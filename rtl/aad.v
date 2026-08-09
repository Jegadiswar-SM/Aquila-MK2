// =============================================================================
// Module      : aad
// Description : Dual-Rate Acoustic Activity Detector
//               Compares short-term and long-term energy estimates to detect
//               acoustic activity. Short-term weight approx 255/256, long-term
//               weight approx 4095/4096. Ratio threshold at 6 dB (x4).
// Author      : GLI / tapeitout.com
// Revision    : 1.0
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module aad #(
    parameter SHORT_SHIFT  = 8,
    parameter LONG_SHIFT   = 12,
    parameter RATIO_SHIFT  = 2,
    parameter ASSERT_CNT   = 4,
    parameter DEASSERT_CNT = 64
)(
    input  wire        clk,
    input  wire        rst_n,

    input  wire [15:0] x_in,
    input  wire        x_valid,

    // AXI4-Lite (ratio_shift override)
    input  wire [3:0]  s_axi_awaddr,
    input  wire        s_axi_awvalid,
    input  wire [31:0] s_axi_wdata,
    input  wire        s_axi_wvalid,
    output reg         s_axi_awready,
    output reg         s_axi_wready,

    output reg         signal_active,
    output reg         clk_gate_en,
    output reg [39:0]  acc_A_dbg,
    output reg [39:0]  acc_B_dbg
);

    // -------------------------------------------------------------------------
    // AXI4-Lite writable register
    // -------------------------------------------------------------------------
    reg [3:0] ratio_shift_reg;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_awready   <= 1'b0;
            s_axi_wready    <= 1'b0;
            ratio_shift_reg <= RATIO_SHIFT;
        end else begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            if (s_axi_awvalid && s_axi_wvalid && (s_axi_awaddr[3:0] == 4'h0)) begin
                s_axi_awready   <= 1'b1;
                s_axi_wready    <= 1'b1;
                ratio_shift_reg <= s_axi_wdata[3:0];
            end
        end
    end

    // -------------------------------------------------------------------------
    // x_sq with DSP48 inference
    // -------------------------------------------------------------------------
    reg signed [31:0] x_sq;
    (* use_dsp = "yes" *) reg signed [31:0] mul_tmp;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            x_sq <= 32'sd0;
        end else if (x_valid) begin
            mul_tmp <= $signed(x_in) * $signed(x_in);
            x_sq    <= mul_tmp;
        end
    end

    // -------------------------------------------------------------------------
    // Energy accumulators (40-bit, one-pole IIR approximation of sliding window)
    //   acc = acc - (acc >> shift) + x_sq
    // -------------------------------------------------------------------------
    reg [39:0] acc_A;
    reg [39:0] acc_B;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            acc_A <= 40'd0;
            acc_B <= 40'd0;
        end else if (x_valid) begin
            acc_A <= acc_A - (acc_A >>> SHORT_SHIFT) + $signed({8'b0, x_sq});
            acc_B <= acc_B - (acc_B >>> LONG_SHIFT)  + $signed({8'b0, x_sq});
        end
    end

    // -------------------------------------------------------------------------
    // Comparator: activity when acc_A > acc_B / 2^ratio_shift
    // -------------------------------------------------------------------------
    wire activity_cmp;
    assign activity_cmp = (acc_A > (acc_B >>> ratio_shift_reg));

    // -------------------------------------------------------------------------
    // Assert counter (3-bit)
    // -------------------------------------------------------------------------
    reg [2:0] assert_cnt;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            assert_cnt <= 3'd0;
        end else if (x_valid) begin
            if (activity_cmp)
                assert_cnt <= (assert_cnt == 3'd7) ? assert_cnt : assert_cnt + 3'd1;
            else
                assert_cnt <= 3'd0;
        end
    end

    // -------------------------------------------------------------------------
    // Deassert counter (7-bit)
    // -------------------------------------------------------------------------
    reg [6:0] deassert_cnt;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            deassert_cnt <= 7'd0;
        end else if (x_valid && signal_active) begin
            if (~activity_cmp)
                deassert_cnt <= (deassert_cnt == 7'd127) ? deassert_cnt : deassert_cnt + 7'd1;
            else
                deassert_cnt <= 7'd0;
        end
    end

    // -------------------------------------------------------------------------
    // Output registers
    // -------------------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            signal_active <= 1'b0;
            clk_gate_en   <= 1'b1;
            acc_A_dbg     <= 40'd0;
            acc_B_dbg     <= 40'd0;
        end else begin
            // Signal active on assert threshold
            if (assert_cnt >= (ASSERT_CNT - 1))
                signal_active <= 1'b1;
            else if (deassert_cnt >= (DEASSERT_CNT - 1))
                signal_active <= 1'b0;

            // clk_gate_en follows signal_active (registered to avoid glitches)
            clk_gate_en <= signal_active;

            acc_A_dbg <= acc_A;
            acc_B_dbg <= acc_B;
        end
    end

endmodule
