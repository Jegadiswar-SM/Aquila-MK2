// =============================================================================
// Module      : ptdl_8stage
// Description : 8-Stage Parallel Tapped Delay Line (PTDL)
// ASIC HARDENING: Changed always @(posedge clk) → always @(posedge clk or negedge rst_n)
//                 for standard async-assert, sync-deassert reset style.
//               Captures RLS error residual e(n) into a shift register and
//               presents all 8 samples simultaneously as a 128-bit parallel
//               vector for single-cycle MLP inference.
//
//               Output packing (MSB-first):
//                 taps_out[127:112] = e(n)   -- most recent
//                 taps_out[111: 96] = e(n-1)
//                 ...
//                 taps_out[ 15:  0] = e(n-7) -- oldest
// Author      : GLI / tapeitout.com
// Revision    : 1.0
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module ptdl_8stage (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        srst,
    input  wire        sample_en,         // Shift enable (from rls_valid_out)

    input  wire signed [15:0] e_in,       // Current error residual Q1.15

    output wire [127:0]       taps_out    // 8 parallel 16-bit taps
);

    // -------------------------------------------------------------------------
    // Shift register bank : sr[0] = e(n), sr[7] = e(n-7)
    // -------------------------------------------------------------------------
    reg signed [15:0] sr [0:7];
    integer i;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (i = 0; i < 8; i = i + 1)
                sr[i] <= 16'sd0;
        end else if (srst) begin
            for (i = 0; i < 8; i = i + 1)
                sr[i] <= 16'sd0;
        end else if (sample_en) begin
            // Shift: oldest sample moves to higher index
            sr[7] <= sr[6];
            sr[6] <= sr[5];
            sr[5] <= sr[4];
            sr[4] <= sr[3];
            sr[3] <= sr[2];
            sr[2] <= sr[1];
            sr[1] <= sr[0];
            sr[0] <= e_in;   // New sample enters at index 0
        end
    end

    // -------------------------------------------------------------------------
    // Combinational parallel output -- available in same cycle as shift
    // (MLP sees the just-updated values because it samples on next edge)
    // -------------------------------------------------------------------------
    assign taps_out[127:112] = sr[0];  // e(n)
    assign taps_out[111: 96] = sr[1];  // e(n-1)
    assign taps_out[ 95: 80] = sr[2];  // e(n-2)
    assign taps_out[ 79: 64] = sr[3];  // e(n-3)
    assign taps_out[ 63: 48] = sr[4];  // e(n-4)
    assign taps_out[ 47: 32] = sr[5];  // e(n-5)
    assign taps_out[ 31: 16] = sr[6];  // e(n-6)
    assign taps_out[ 15:  0] = sr[7];  // e(n-7)

endmodule
