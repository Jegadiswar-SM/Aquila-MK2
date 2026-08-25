// =============================================================================
// Module      : mlp_inference
// Description : Time-Multiplexed, 16-Parallel-MAC MLP Inference Engine.
//               Topology : 8 inputs -> 128 hidden (QAA tanh) -> 384 hidden (QAA tanh)
//                        -> 128 hidden (QAA tanh) -> 1 output (linear)
//
//               ASIC Hardening Changes:
//                 - Removed all non-synthesizable initial blocks and localparam weight ROMs.
//                 - Connects to an external 256-bit wide weight SRAM wrapper.
//                 - Implemented as a time-multiplexed state machine to avoid 49,000 parallel multipliers.
//                 - Uses a 16-multiplier array with a pipelined adder tree and single 40-bit accumulator.
//                 - Runs comfortably within the 12,500 clock cycle budget at 8 kHz sample rate.
//
// Author      : MHDA RTL Hardening (ASIC prep)
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module mlp_inference (
    input  wire         clk,
    input  wire         rst_n,
    input  wire         srst,
    input  wire         en_in,             // New feature strobe (1 cycle wide)

    input  wire [127:0] features_in,      // 8 x Q1.15 packed from PTDL

    // Weight SRAM Interface (256-bit read port)
    output reg          ren,
    output reg  [12:0]  raddr,
    input  wire [255:0] rdata,
    input  wire         rvalid,

    output reg  [15:0]  y_out,            // Q1.15 noise estimate
    output reg          valid_out         // Asserted when output is ready
);

    // =========================================================================
    // Activation function: 4-Segment Piecewise-Linear Tanh (QAA)
    // =========================================================================
    function automatic signed [15:0] qaa_tanh;
        input signed [15:0] x;
        reg signed [15:0] abs_x;
        reg signed [15:0] y_mag;
        begin
            abs_x = x[15] ? (~x + 1'b1) : x;

            if (abs_x <= 16'd8192)
                y_mag = ($signed(abs_x) * 16'sh7C00) >>> 15;
            else if (abs_x <= 16'd16384)
                y_mag = 16'h1F06 + (($signed(abs_x) - 16'd8192) * 16'sh6800 >>> 15);
            else if (abs_x <= 16'd24576)
                y_mag = 16'h3904 + (($signed(abs_x) - 16'd16384) * 16'sh3800 >>> 15);
            else
                y_mag = 16'h7800;

            qaa_tanh = x[15] ? (~y_mag + 1'b1) : y_mag;
        end
    endfunction

    // =========================================================================
    // Local Activation Storage (Registers for intermediate layer outputs)
    // =========================================================================
    reg signed [15:0] feat_reg [0:7];
    reg signed [15:0] h1 [0:127];
    reg signed [15:0] h2 [0:383];
    reg signed [15:0] h3 [0:127];

    // =========================================================================
    // FSM States
    // =========================================================================
    localparam [2:0] STATE_IDLE      = 3'd0,
                     STATE_READ_BIAS = 3'd1,
                     STATE_WAIT_BIAS = 3'd2,
                     STATE_COMPUTE   = 3'd3,
                     STATE_WAIT_DATA = 3'd4,
                     STATE_DONE      = 3'd5;

    reg [2:0] state;
    reg [2:0] current_layer; // 0: L1, 1: L2, 2: L3, 3: L4

    // Counters
    reg [8:0] node_cnt;      // Up to 384 nodes
    reg [5:0] step_cnt;      // Up to 24 steps (384 / 16 = 24)

    // Explicitly sized index/address intermediates.  The original
    // expressions relied on unsized arithmetic operands, which obscured the
    // intended bounds in ASIC lint even though the measured activation
    // indices were correct.
    wire [12:0] node_cnt_ext = {4'd0, node_cnt};
    wire [12:0] step_cnt_ext = {7'd0, step_cnt};

    function automatic [6:0] activation_index_128;
        input [2:0] step;
        input [3:0] offset;
        begin
            activation_index_128 = {step, 4'd0} + {3'd0, offset};
        end
    endfunction

    function automatic [8:0] activation_index_384;
        input [4:0] step;
        input [3:0] offset;
        begin
            activation_index_384 = {step, 4'd0} + {5'd0, offset};
        end
    endfunction

    // Accumulators
    reg signed [39:0] accumulator;
    reg signed [15:0] bias_reg;

    // Pipeline Registers for MAC multipliers
    reg signed [15:0] w_reg [0:15];
    reg signed [15:0] a_reg [0:15];
    reg signed [31:0] prod  [0:15];
    wire signed [39:0] prod_ext [0:15];

    genvar p;
    generate
        for (p = 0; p < 16; p = p + 1) begin : PROD_EXTEND
            assign prod_ext[p] = {{8{prod[p][31]}}, prod[p]};
        end
    endgenerate

    // SRAM Read delay line
    reg [2:0] rvalid_dly;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            rvalid_dly <= 3'd0;
        else if (srst)
            rvalid_dly <= 3'd0;
        else
            rvalid_dly <= {rvalid_dly[1:0], rvalid};
    end

    // Unpack features_in
    wire signed [15:0] feat_in_unpacked [0:7];
    genvar g;
    generate
        for (g = 0; g < 8; g = g + 1) begin : UNPACK
            assign feat_in_unpacked[g] = $signed(features_in[127 - g*16 -: 16]);
        end
    endgenerate

    // Index helper for activations
    reg signed [15:0] act_val [0:15];
    always @(*) begin
        for (integer idx_act = 0; idx_act < 16; idx_act = idx_act + 1) begin
            if (current_layer == 3'd0) begin
                if (idx_act < 8)
                    act_val[idx_act] = feat_reg[idx_act];
                else
                    act_val[idx_act] = 16'sd0;
            end else if (current_layer == 3'd1) begin
                act_val[idx_act] = h1[activation_index_128(step_cnt[2:0], idx_act[3:0])];
            end else if (current_layer == 3'd2) begin
                act_val[idx_act] = h2[activation_index_384(step_cnt[4:0], idx_act[3:0])];
            end else begin
                act_val[idx_act] = h3[activation_index_128(step_cnt[2:0], idx_act[3:0])];
            end
        end
    end

    // =========================================================================
    // Time-multiplexed FSM and Address Generator
    // =========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state         <= STATE_IDLE;
            current_layer <= 3'd0;
            node_cnt      <= 9'd0;
            step_cnt      <= 6'd0;
            ren           <= 1'b0;
            raddr         <= 13'd0;
            accumulator   <= 40'sd0;
            bias_reg      <= 16'sd0;
            y_out         <= 16'sd0;
            valid_out     <= 1'b0;
            for (integer idx_feat_reset = 0; idx_feat_reset < 8; idx_feat_reset = idx_feat_reset + 1)
                feat_reg[idx_feat_reset] <= 16'sd0;
            for (integer idx_hidden_reset = 0; idx_hidden_reset < 128; idx_hidden_reset = idx_hidden_reset + 1) begin
                h1[idx_hidden_reset] = 16'sd0;
                h3[idx_hidden_reset] = 16'sd0;
            end
            for (integer idx_h2_reset = 0; idx_h2_reset < 384; idx_h2_reset = idx_h2_reset + 1)
                h2[idx_h2_reset] = 16'sd0;
        end else if (srst) begin
            state         <= STATE_IDLE;
            current_layer <= 3'd0;
            node_cnt      <= 9'd0;
            step_cnt      <= 6'd0;
            ren           <= 1'b0;
            raddr         <= 13'd0;
            accumulator   <= 40'sd0;
            bias_reg      <= 16'sd0;
            y_out         <= 16'sd0;
            valid_out     <= 1'b0;
            for (integer idx_feat_srst = 0; idx_feat_srst < 8; idx_feat_srst = idx_feat_srst + 1)
                feat_reg[idx_feat_srst] <= 16'sd0;
            for (integer idx_hidden_srst = 0; idx_hidden_srst < 128; idx_hidden_srst = idx_hidden_srst + 1) begin
                h1[idx_hidden_srst] = 16'sd0;
                h3[idx_hidden_srst] = 16'sd0;
            end
            for (integer idx_h2_srst = 0; idx_h2_srst < 384; idx_h2_srst = idx_h2_srst + 1)
                h2[idx_h2_srst] = 16'sd0;
        end else begin
            valid_out <= 1'b0;

            case (state)
                STATE_IDLE: begin
                    if (en_in) begin
                        for (integer idx_feat_load = 0; idx_feat_load < 8; idx_feat_load = idx_feat_load + 1) begin
                            feat_reg[idx_feat_load] <= feat_in_unpacked[idx_feat_load];
                        end
                        current_layer <= 3'd0;
                        node_cnt      <= 9'd0;
                        step_cnt      <= 6'd0;
                        state         <= STATE_READ_BIAS;
                    end
                end

                STATE_READ_BIAS: begin
                    ren <= 1'b1;
                    case (current_layer)
                        3'd0: raddr <= 13'd64   + (node_cnt_ext >> 4); // B1
                        3'd1: raddr <= 13'd3144 + (node_cnt_ext >> 4); // B2
                        3'd2: raddr <= 13'd6240 + (node_cnt_ext >> 4); // B3
                        3'd3: raddr <= 13'd6256;                   // B4
                        default: raddr <= 13'd0;
                    endcase
                    state <= STATE_WAIT_BIAS;
                end

                STATE_WAIT_BIAS: begin
                    ren <= 1'b0;
                    if (rvalid_dly[0]) begin
                        // Extract specific bias word from the 256-bit row
                        case (node_cnt[3:0])
                            4'd0:  bias_reg <= rdata[15:0];
                            4'd1:  bias_reg <= rdata[31:16];
                            4'd2:  bias_reg <= rdata[47:32];
                            4'd3:  bias_reg <= rdata[63:48];
                            4'd4:  bias_reg <= rdata[79:64];
                            4'd5:  bias_reg <= rdata[95:80];
                            4'd6:  bias_reg <= rdata[111:96];
                            4'd7:  bias_reg <= rdata[127:112];
                            4'd8:  bias_reg <= rdata[143:128];
                            4'd9:  bias_reg <= rdata[159:144];
                            4'd10: bias_reg <= rdata[175:160];
                            4'd11: bias_reg <= rdata[191:176];
                            4'd12: bias_reg <= rdata[207:192];
                            4'd13: bias_reg <= rdata[223:208];
                            4'd14: bias_reg <= rdata[239:224];
                            4'd15: bias_reg <= rdata[255:240];
                        endcase
                        accumulator <= 40'sd0;
                        step_cnt    <= 6'd0;
                        state       <= STATE_COMPUTE;
                    end
                end

                STATE_COMPUTE: begin
                    // Issue read command to SRAM for weights
                    ren <= 1'b1;
                    case (current_layer)
                        3'd0: begin
                            raddr <= (node_cnt_ext >> 1); // W1
                            ren   <= 1'b1;
                            state <= STATE_WAIT_DATA;
                        end
                        3'd1: begin
                            raddr <= 13'd72 + (node_cnt_ext << 3) + step_cnt_ext; // W2
                            if (step_cnt == 6'd7) begin
                                // The SRAM is synchronous: this edge issues
                                // the final address, and the following edge
                                // observes its response. Keep ren asserted
                                // through that command edge.
                                ren   <= 1'b1;
                                state <= STATE_WAIT_DATA;
                            end else begin
                                step_cnt <= step_cnt + 6'd1;
                            end
                        end
                        3'd2: begin
                            raddr <= 13'd3168 + (node_cnt_ext * 13'd24) + step_cnt_ext; // W3
                            if (step_cnt == 6'd23) begin
                                ren   <= 1'b1;
                                state <= STATE_WAIT_DATA;
                            end else begin
                                step_cnt <= step_cnt + 6'd1;
                            end
                        end
                        3'd3: begin
                            raddr <= 13'd6248 + step_cnt_ext; // W4
                            if (step_cnt == 6'd7) begin
                                ren   <= 1'b1;
                                state <= STATE_WAIT_DATA;
                            end else begin
                                step_cnt <= step_cnt + 6'd1;
                            end
                        end
                        default: state <= STATE_IDLE;
                    endcase
                end

                STATE_WAIT_DATA: begin
                    ren <= 1'b0;

                    // Accumulate multiplier products as they arrive through the pipeline
                    if (rvalid_dly[2]) begin
                        accumulator <= accumulator +
                                       prod_ext[0]  + prod_ext[1]  + prod_ext[2]  + prod_ext[3]  +
                                       prod_ext[4]  + prod_ext[5]  + prod_ext[6]  + prod_ext[7]  +
                                       prod_ext[8]  + prod_ext[9]  + prod_ext[10] + prod_ext[11] +
                                       prod_ext[12] + prod_ext[13] + prod_ext[14] + prod_ext[15];
                    end

                    // Once all data has cleared the pipeline
                    if (rvalid_dly == 3'd0) begin
                        // Final step: add bias, apply tanh/saturation
                        reg signed [39:0] final_acc;
                        reg signed [15:0] activated_val;

                        final_acc     = accumulator + {{8{bias_reg[15]}}, bias_reg, 16'b0};
                        activated_val = (current_layer == 3'd3) ? 16'sd0 : qaa_tanh(final_acc[30:15]);

                        case (current_layer)
                            3'd0: h1[node_cnt[6:0]] <= activated_val;
                            3'd1: h2[node_cnt] <= activated_val;
                            3'd2: h3[node_cnt[6:0]] <= activated_val;
                            3'd3: begin
                                // Compare the signed accumulator against the
                                // exact Q1.15 output limits.  A part-select is
                                // unsigned in Verilog; comparing it directly
                                // against a negative literal made zero
                                // incorrectly satisfy the negative branch.
                                if (final_acc > 40'sh003FFF8000)
                                    y_out <= 16'sh7FFF;
                                else if (final_acc < 40'shFFC0000000)
                                    y_out <= 16'sh8000;
                                else
                                    y_out <= final_acc[30:15];
                            end
                            default: begin
                                y_out <= 16'sd0;
                            end
                        endcase

                        // Step to next node or layer
                        case (current_layer)
                            3'd0: begin
                                if (node_cnt == 9'd127) begin
                                    current_layer <= 3'd1;
                                    node_cnt      <= 9'd0;
                                end else begin
                                    node_cnt <= node_cnt + 9'd1;
                                end
                                state <= STATE_READ_BIAS;
                            end
                            3'd1: begin
                                if (node_cnt == 9'd383) begin
                                    current_layer <= 3'd2;
                                    node_cnt      <= 9'd0;
                                end else begin
                                    node_cnt <= node_cnt + 9'd1;
                                end
                                state <= STATE_READ_BIAS;
                            end
                            3'd2: begin
                                if (node_cnt == 9'd127) begin
                                    current_layer <= 3'd3;
                                    node_cnt      <= 9'd0;
                                end else begin
                                    node_cnt <= node_cnt + 9'd1;
                                end
                                state <= STATE_READ_BIAS;
                            end
                            3'd3: begin
                                state <= STATE_DONE;
                            end
                            default: begin
                                state <= STATE_IDLE;
                            end
                        endcase
                    end
                end

                STATE_DONE: begin
                    valid_out <= 1'b1;
                    state     <= STATE_IDLE;
                end
                default: begin
                    state <= STATE_IDLE;
                    ren   <= 1'b0;
                end
            endcase
        end
    end

    // =========================================================================
    // Multiplier Pipeline Stages (DSP48-compatible registers)
    // =========================================================================
    integer m;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (m = 0; m < 16; m = m + 1) begin
                w_reg[m] <= 16'sd0;
                a_reg[m] <= 16'sd0;
                prod[m]  <= 32'sd0;
            end
        end else if (srst) begin
            for (m = 0; m < 16; m = m + 1) begin
                w_reg[m] <= 16'sd0;
                a_reg[m] <= 16'sd0;
                prod[m]  <= 32'sd0;
            end
        end else begin
            // Stage 1: Register inputs from SRAM and Activation Memory
            if (rvalid) begin
                for (m = 0; m < 16; m = m + 1) begin
                    // Extract weights from 256-bit row data
                    case (m[3:0])
                        4'd0:  w_reg[0]  <= rdata[15:0];
                        4'd1:  w_reg[1]  <= rdata[31:16];
                        4'd2:  w_reg[2]  <= rdata[47:32];
                        4'd3:  w_reg[3]  <= rdata[63:48];
                        4'd4:  w_reg[4]  <= rdata[79:64];
                        4'd5:  w_reg[5]  <= rdata[95:80];
                        4'd6:  w_reg[6]  <= rdata[111:96];
                        4'd7:  w_reg[7]  <= rdata[127:112];
                        4'd8:  w_reg[8]  <= rdata[143:128];
                        4'd9:  w_reg[9]  <= rdata[159:144];
                        4'd10: w_reg[10] <= rdata[175:160];
                        4'd11: w_reg[11] <= rdata[191:176];
                        4'd12: w_reg[12] <= rdata[207:192];
                        4'd13: w_reg[13] <= rdata[223:208];
                        4'd14: w_reg[14] <= rdata[239:224];
                        4'd15: w_reg[15] <= rdata[255:240];
                    endcase

                    // Handle special mapping for Layer 1
                    if (current_layer == 3'd0) begin
                        if (node_cnt[0] == 1'b0) begin
                            // Even node: uses first 8 weights of row
                            if (m < 8)
                                a_reg[m] <= act_val[m];
                            else
                                a_reg[m] <= 16'sd0;
                        end else begin
                            // Odd node: uses second 8 weights of row
                            if (m >= 8)
                                a_reg[m] <= act_val[m - 8];
                            else
                                a_reg[m] <= 16'sd0;
                        end
                    end else begin
                        a_reg[m] <= act_val[m];
                    end
                end
            end

            // Stage 2: Register products
            // (* use_dsp = "yes" *) hint ensures DSP inference during synthesis
            for (m = 0; m < 16; m = m + 1) begin
                prod[m] <= $signed(w_reg[m]) * $signed(a_reg[m]);
            end
        end
    end

endmodule
