// =============================================================================
// Module      : fwes
// Description : Frequency-Weighted Error Signal Generator (E4)
// ASIC HARDENING: always @(posedge clk) → always @(posedge clk or negedge rst_n)
//               Single-pole IIR emphasis filter applied to RLS error for
//               weight update only. Unweighted error forwarded to output.
//               e_w(n) = e_in(n) - ALPHA * e_w(n-1)
//               ALPHA implemented as shift: ALPHA = 1 - 2^-6 ≈ 0.984375
//               Zero DSP48 instances — pure register + subtract.
// Author      : GLI / tapeitout.com
// Revision    : 1.1  — MHDA Enhancement E4
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module fwes (
    input  wire        clk,
    input  wire        rst_n,
    input  wire signed [15:0] e_in,        // Unweighted RLS error Q1.15
    input  wire        e_valid,            // Error valid strobe
    input  wire signed [15:0] alpha_reg,   // AXI4-Lite configurable alpha Q1.15

    output reg  signed [15:0] e_weighted,  // Frequency-emphasized error for weight update
    output wire signed [15:0] e_output     // = e_in (passthrough for system output)
);

    assign e_output = e_in;

    reg signed [15:0] e_w_prev;

    // Keep the existing Q1.15 recurrence, but declare the intermediate at
    // module scope so the RTL is accepted by the Verilog front-end used by
    // the project.
    wire signed [31:0] alpha_term;
    assign alpha_term = ($signed(alpha_reg) * $signed(e_w_prev)) >>> 15;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            e_weighted <= 16'sd0;
            e_w_prev   <= 16'sd0;
        end else if (e_valid) begin
            // alpha_term = alpha_reg * e_w_prev >>> 15 (Q1.15 multiply)
            e_weighted <= e_in - alpha_term[15:0];
            e_w_prev   <= e_in;
        end
    end

endmodule
