// =============================================================================
// Module      : rcim
// Description : Reference Channel Integrity Monitor
//               Estimates cross-correlation between primary (d) and reference
//               (x) channels using one-pole IIR approximation of a 32-sample
//               sliding window. Normalised correlation via Newton-Raphson
//               reciprocal function ROM. Fault asserted when correlation persists
//               below threshold — zeroes the reference channel output.
//
// ASIC HARDENING CHANGES (vs. original):
//   1. Replaced `always @(posedge clk or negedge rst_n)` LUTRAM reset block
//      with a pure combinational function `rcim_lut_read()`. The 16 values
//      are constants; storing them in flip-flops (reset-initialized) wastes
//      256 bits of flop area and ties the read latency to reset sequencing.
//      A function case-ROM synthesises as a mux tree — ASIC-clean.
//   2. `reg [15:0] lutram [0:LUTRAM_DEPTH-1]` declaration removed.
//   3. `lut_idx` is now a wire (combinational from ref_power_acc[38:35]).
//   4. NR refinement path and fault logic unchanged.
//
// Author      : GLI / tapeitout.com  (ASIC hardening: MHDA RTL team)
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module rcim #(
    parameter WINDOW        = 32,
    parameter FAULT_PERSIST = 128,
    parameter LUTRAM_DEPTH  = 16
)(
    input  wire        clk,
    input  wire        rst_n,
    input  wire        srst,

    input  wire [15:0] d_in,
    input  wire [15:0] x_in,
    input  wire        samples_valid,

    // AXI4-Lite
    input  wire [4:0]  s_axi_awaddr,
    input  wire        s_axi_awvalid,
    input  wire [31:0] s_axi_wdata,
    input  wire        s_axi_wvalid,
    output reg         s_axi_awready,
    output reg         s_axi_wready,

    output reg         ref_channel_fault,
    output reg  [15:0] x_out_muxed
);

    // -------------------------------------------------------------------------
    // AXI4-Lite config: corr_threshold
    // -------------------------------------------------------------------------
    reg [15:0] corr_threshold;
    reg [3:0]  ratio_shift;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_awready  <= 1'b0;
            s_axi_wready   <= 1'b0;
            corr_threshold <= 16'h1999;
            ratio_shift    <= 4'd5;  // 1/32 sliding window
        end else if (srst) begin
            s_axi_awready  <= 1'b0;
            s_axi_wready   <= 1'b0;
            corr_threshold <= 16'h1999;
            ratio_shift    <= 4'd5;
        end else begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            if (s_axi_awvalid && s_axi_wvalid && (s_axi_awaddr[4:0] == 5'h00)) begin
                s_axi_awready  <= 1'b1;
                s_axi_wready   <= 1'b1;
                corr_threshold <= s_axi_wdata[15:0];
            end
        end
    end

    // -------------------------------------------------------------------------
    // Correlation accumulator  corr = sum(d * x) over sliding window
    //   corr_acc = corr_acc - (corr_acc >>> 5) + d * x
    // -------------------------------------------------------------------------
    reg signed [39:0] corr_acc;
    reg signed [39:0] ref_power_acc;

    (* use_dsp = "yes" *) reg signed [31:0] mul_dx;
    (* use_dsp = "yes" *) reg signed [31:0] mul_xx;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            corr_acc      <= 40'sd0;
            ref_power_acc <= 40'sd0;
            mul_dx        <= 32'sd0;
            mul_xx        <= 32'sd0;
        end else if (srst) begin
            corr_acc      <= 40'sd0;
            ref_power_acc <= 40'sd0;
            mul_dx        <= 32'sd0;
            mul_xx        <= 32'sd0;
        end else if (samples_valid) begin
            mul_dx <= $signed(d_in) * $signed(x_in);
            mul_xx <= $signed(x_in) * $signed(x_in);
            corr_acc      <= corr_acc      - (corr_acc      >>> ratio_shift) +
                             $signed({{8{mul_dx[31]}}, mul_dx});
            ref_power_acc <= ref_power_acc - (ref_power_acc >>> ratio_shift) +
                             $signed({{8{mul_xx[31]}}, mul_xx});
        end
    end

    // -------------------------------------------------------------------------
    // ASIC FIX: Reciprocal LUT — pure combinational ROM function
    //
    // Original used a `reg [15:0] lutram [0:15]` array reset-initialized
    // from an `always @(posedge clk or negedge rst_n)` block. Since this
    // array is never written after reset, it is a ROM. Converting to a
    // function case-statement eliminates 16 × 16 = 256 flip-flops and
    // removes the reset dependency from the read path.
    //
    // 16 entries, Q0.16 format:
    //   entry[i] = round(65536 / (i * 4096 + 2048)) for i=1..15
    //   entry[0] = 16'hFFFF  (no-signal fallback)
    // -------------------------------------------------------------------------
    function automatic [15:0] rcim_lut_read;
        input [3:0] addr;
        case (addr)
            4'd0:  rcim_lut_read = 16'hFFFF;
            4'd1:  rcim_lut_read = 16'h7FFF;
            4'd2:  rcim_lut_read = 16'h3FFF;
            4'd3:  rcim_lut_read = 16'h2AAA;
            4'd4:  rcim_lut_read = 16'h2000;
            4'd5:  rcim_lut_read = 16'h1999;
            4'd6:  rcim_lut_read = 16'h1555;
            4'd7:  rcim_lut_read = 16'h1249;
            4'd8:  rcim_lut_read = 16'h1000;
            4'd9:  rcim_lut_read = 16'h0E38;
            4'd10: rcim_lut_read = 16'h0CCC;
            4'd11: rcim_lut_read = 16'h0BA2;
            4'd12: rcim_lut_read = 16'h0AAA;
            4'd13: rcim_lut_read = 16'h09D8;
            4'd14: rcim_lut_read = 16'h0924;
            4'd15: rcim_lut_read = 16'h0888;
            default: rcim_lut_read = 16'hFFFF;
        endcase
    endfunction

    wire [3:0]  lut_idx        = ref_power_acc[38:35];
    wire [15:0] recip_approx   = rcim_lut_read(lut_idx);

    // -------------------------------------------------------------------------
    // Newton-Raphson refinement: refined = recip * (2 - norm * recip) >> 15
    //   ref_power_acc_norm = ref_power_acc[30:15]  (Q1.15 normalised slice)
    // -------------------------------------------------------------------------
    wire [15:0] ref_power_norm;
    wire [15:0] refined_recip;

    assign ref_power_norm = ref_power_acc[30:15];

    (* use_dsp = "yes" *) reg signed [31:0] mul_nr1;
    (* use_dsp = "yes" *) reg signed [31:0] mul_nr2;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mul_nr1 <= 32'sd0;
            mul_nr2 <= 32'sd0;
        end else if (srst) begin
            mul_nr1 <= 32'sd0;
            mul_nr2 <= 32'sd0;
        end else begin
            // NR: norm * recip → Q2.30, then 2 - result → Q1.15
            mul_nr1 <= $signed(recip_approx) * $signed(ref_power_norm);
            // refined = recip * (2 - mul_nr1[30:15]) >> 15
            mul_nr2 <= $signed(recip_approx) *
                       $signed({1'b0, 16'hFFFF} - mul_nr1[30:15]);
        end
    end

    assign refined_recip = mul_nr2[30:15];

    // -------------------------------------------------------------------------
    // Normalised correlation: |corr| * refined >> 15
    // -------------------------------------------------------------------------
    wire [15:0] corr_mag;
    wire [15:0] norm_corr;

    assign corr_mag = corr_acc[39] ? (~corr_acc[30:15] + 16'd1) : corr_acc[30:15];

    (* use_dsp = "yes" *) reg signed [31:0] mul_norm;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mul_norm <= 32'sd0;
        end else if (srst) begin
            mul_norm <= 32'sd0;
        end else begin
            mul_norm <= {16'd0, corr_mag} * {16'd0, refined_recip};
        end
    end

    assign norm_corr = mul_norm[30:15];

    // -------------------------------------------------------------------------
    // Fault logic with hysteresis
    // -------------------------------------------------------------------------
    reg [7:0] fault_cnt;
    reg [7:0] recover_cnt;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            fault_cnt         <= 8'd0;
            recover_cnt       <= 8'd0;
            ref_channel_fault <= 1'b0;
        end else if (srst) begin
            fault_cnt         <= 8'd0;
            recover_cnt       <= 8'd0;
            ref_channel_fault <= 1'b0;
        end else if (samples_valid) begin
            if (norm_corr < corr_threshold) begin
                fault_cnt   <= (fault_cnt == 8'd255) ? fault_cnt : fault_cnt + 8'd1;
                recover_cnt <= 8'd0;
                if (fault_cnt >= (FAULT_PERSIST - 1))
                    ref_channel_fault <= 1'b1;
            end else begin
                fault_cnt <= 8'd0;
                if (ref_channel_fault) begin
                    recover_cnt <= (recover_cnt == 8'd255) ? recover_cnt : recover_cnt + 8'd1;
                    if (recover_cnt >= 8'd15)   // 16-sample hysteresis on recovery
                        ref_channel_fault <= 1'b0;
                end
            end
        end
    end

    // -------------------------------------------------------------------------
    // Output mux (registered, 1-cycle latency)
    // -------------------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            x_out_muxed <= 16'sd0;
        end else if (srst) begin
            x_out_muxed <= 16'sd0;
        end else begin
            x_out_muxed <= ref_channel_fault ? 16'sd0 : x_in;
        end
    end

endmodule
