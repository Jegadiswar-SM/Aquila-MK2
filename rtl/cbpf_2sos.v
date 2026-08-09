// =============================================================================
// Module      : cbpf_2sos
// Description : Cascaded Biquad Bandpass Pre-Filter, 300-800 Hz @ Fs=8 kHz
//               2 cascaded second-order sections, DFII-T topology.
//               Coefficients computed via scipy.signal.butter with Q1.15
//               quantisation. Per-section scaling applied to fit Q1.15 range;
//               section 1 scale≈0.700, section 2 scale=0.500.
//               Latency: 4 clock cycles (2 stages per section x 2 sections).
// Author      : GLI / tapeitout.com
// Revision    : 1.0
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module cbpf_2sos (
    input  wire        clk,
    input  wire        rst_n,

    input  wire [15:0] x_in,         // raw input Q1.15
    input  wire        x_valid,

    // AXI4-Lite bypass
    input  wire [3:0]  s_axi_awaddr,
    input  wire        s_axi_awvalid,
    input  wire [31:0] s_axi_wdata,
    input  wire        s_axi_wvalid,
    output reg         s_axi_awready,
    output reg         s_axi_wready,

    output reg  [15:0] y_out,        // filtered output Q1.15
    output reg         y_valid,
    output reg         clip_s1,
    output reg         clip_s2
);

    // =========================================================================
    // Coefficients — computed offline with scipy.signal.butter:
    // python3 -c "from scipy.signal import butter; import numpy as np
    // sos = butter(2, [300, 800], btype='bandpass', fs=8000, output='sos')
    // for row in sos: b=row[:3]; a1=-row[4]; a2=-row[5]; ..."
    //
    // Section 1 coefficients (scaled by 0.70009):
    //   b = [0.029955, 0.059909, 0.029955]
    //   a = [1.0, -1.428387, 0.688400]  (negated for DFII-T adds)
    // Section 2 coefficients (scaled by 0.50000):
    //   b = [1.0, -2.0, 1.0]
    //   a = [1.0, -1.770017, 0.833907]  (negated for DFII-T adds)
    //
    // Combined gain compensation: 1/(0.70009 * 0.50000) = 2.8568x
    // Filter output is scaled accordingly; RLS adaptive filter compensates.
    // =========================================================================

    // Section 1
    localparam signed [15:0] B0_S1 = 16'sd687;
    localparam signed [15:0] B1_S1 = 16'sd1374;
    localparam signed [15:0] B2_S1 = 16'sd687;
    localparam signed [15:0] A1_S1 = 16'sd32767;
    localparam signed [15:0] A2_S1 = -16'sd15792;

    // Section 2
    localparam signed [15:0] B0_S2 = 16'sd16384;
    localparam signed [15:0] B1_S2 = -16'sd32768;
    localparam signed [15:0] B2_S2 = 16'sd16384;
    localparam signed [15:0] A1_S2 = 16'sd29000;
    localparam signed [15:0] A2_S2 = -16'sd13663;

    // -------------------------------------------------------------------------
    // AXI4-Lite bypass register
    // -------------------------------------------------------------------------
    reg bypass_reg;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            bypass_reg    <= 1'b0;
        end else begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            if (s_axi_awvalid && s_axi_wvalid && (s_axi_awaddr[3:0] == 4'h0)) begin
                s_axi_awready <= 1'b1;
                s_axi_wready  <= 1'b1;
                bypass_reg    <= s_axi_wdata[0];
            end
        end
    end

    // -------------------------------------------------------------------------
    // Section 1 — DFII-T
    // -------------------------------------------------------------------------
    reg signed [31:0] w1_s1;   // w[n-1] Q2.30
    reg signed [31:0] w2_s1;   // w[n-2] Q2.30
    reg signed [31:0] w0_s1;   // w[n]   Q2.30
    reg signed [31:0] y_s1;    // output Q2.30

    (* use_dsp = "yes" *) reg signed [31:0] mul_a1_s1;
    (* use_dsp = "yes" *) reg signed [31:0] mul_a2_s1;
    (* use_dsp = "yes" *) reg signed [31:0] mul_b0_s1;
    (* use_dsp = "yes" *) reg signed [31:0] mul_b1_s1;
    (* use_dsp = "yes" *) reg signed [31:0] mul_b2_s1;

    reg [15:0] y_s1_trunc;
    reg        s1_valid_stg1;
    reg        s1_valid_stg2;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            w1_s1        <= 32'sd0;
            w2_s1        <= 32'sd0;
            w0_s1        <= 32'sd0;
            y_s1         <= 32'sd0;
            y_s1_trunc   <= 16'sd0;
            s1_valid_stg1 <= 1'b0;
            s1_valid_stg2 <= 1'b0;
            clip_s1      <= 1'b0;
        end else begin
            s1_valid_stg1 <= x_valid;

            if (x_valid) begin
                // Stage 1: w0 = x_ext + A1*w1 + A2*w2
                mul_a1_s1 <= $signed(A1_S1) * $signed(w1_s1);
                mul_a2_s1 <= $signed(A2_S1) * $signed(w2_s1);
                w0_s1     <= {{16{x_in[15]}}, x_in, 14'b0}
                           + (mul_a1_s1 >>> 15) + (mul_a2_s1 >>> 15);
            end

            s1_valid_stg2 <= s1_valid_stg1;

            if (s1_valid_stg1) begin
                // Stage 2: y = B0*w0 + B1*w1 + B2*w2, then state update
                mul_b0_s1 <= $signed(B0_S1) * $signed(w0_s1);
                mul_b1_s1 <= $signed(B1_S1) * $signed(w1_s1);
                mul_b2_s1 <= $signed(B2_S1) * $signed(w2_s1);
                y_s1      <= (mul_b0_s1 >>> 15) + (mul_b1_s1 >>> 15) + (mul_b2_s1 >>> 15);
                w2_s1     <= w1_s1;
                w1_s1     <= w0_s1;

                // Overflow detection
                clip_s1   <= (y_s1[31:30] != 2'b00) && (y_s1[31:30] != 2'b11);
            end

            if (s1_valid_stg2) begin
                y_s1_trunc <= y_s1[29:14];  // Q2.30 → Q1.15
            end
        end
    end

    // -------------------------------------------------------------------------
    // Section 2 — DFII-T (identical structure)
    // -------------------------------------------------------------------------
    reg signed [31:0] w1_s2;
    reg signed [31:0] w2_s2;
    reg signed [31:0] w0_s2;
    reg signed [31:0] y_s2;

    (* use_dsp = "yes" *) reg signed [31:0] mul_a1_s2;
    (* use_dsp = "yes" *) reg signed [31:0] mul_a2_s2;
    (* use_dsp = "yes" *) reg signed [31:0] mul_b0_s2;
    (* use_dsp = "yes" *) reg signed [31:0] mul_b1_s2;
    (* use_dsp = "yes" *) reg signed [31:0] mul_b2_s2;

    reg [15:0] y_s2_trunc;
    reg        s2_valid_stg1;
    reg        s2_valid_stg2;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            w1_s2        <= 32'sd0;
            w2_s2        <= 32'sd0;
            w0_s2        <= 32'sd0;
            y_s2         <= 32'sd0;
            y_s2_trunc   <= 16'sd0;
            s2_valid_stg1 <= 1'b0;
            s2_valid_stg2 <= 1'b0;
            clip_s2      <= 1'b0;
        end else begin
            s2_valid_stg1 <= s1_valid_stg2;

            if (s1_valid_stg2) begin
                mul_a1_s2 <= $signed(A1_S2) * $signed(w1_s2);
                mul_a2_s2 <= $signed(A2_S2) * $signed(w2_s2);
                w0_s2     <= {{16{y_s1_trunc[15]}}, y_s1_trunc, 14'b0}
                           + (mul_a1_s2 >>> 15) + (mul_a2_s2 >>> 15);
            end

            s2_valid_stg2 <= s2_valid_stg1;

            if (s2_valid_stg1) begin
                mul_b0_s2 <= $signed(B0_S2) * $signed(w0_s2);
                mul_b1_s2 <= $signed(B1_S2) * $signed(w1_s2);
                mul_b2_s2 <= $signed(B2_S2) * $signed(w2_s2);
                y_s2      <= (mul_b0_s2 >>> 15) + (mul_b1_s2 >>> 15) + (mul_b2_s2 >>> 15);
                w2_s2     <= w1_s2;
                w1_s2     <= w0_s2;

                clip_s2   <= (y_s2[31:30] != 2'b00) && (y_s2[31:30] != 2'b11);
            end

            if (s2_valid_stg2) begin
                y_s2_trunc <= y_s2[29:14];  // Q2.30 → Q1.15
            end
        end
    end

    // -------------------------------------------------------------------------
    // Output mux with bypass
    // -------------------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            y_out   <= 16'sd0;
            y_valid <= 1'b0;
        end else begin
            y_valid <= s2_valid_stg2;
            if (bypass_reg)
                y_out <= x_in;
            else
                y_out <= y_s2_trunc;
        end
    end

endmodule
