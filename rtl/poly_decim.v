// =============================================================================
// Module      : poly_decim
// Description : Polyphase Decimation Controller (E5)
// ASIC HARDENING: always @(posedge clk) → always @(posedge clk or negedge rst_n)
//               Runtime-configurable (AXI4-Lite) sample-rate decimation for
//               RLS/MLP pipeline. Only power-of-2 ratios: 1:1, 1:2, 1:4.
//               CBPF/AAD continue at full rate. DSP switching activity
//               reduces proportionally to decimation ratio.
// Author      : GLI / tapeitout.com
// Revision    : 1.1  — MHDA Enhancement E5
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module poly_decim (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        sample_enable_in,    // 8 kHz strobe from top-level
    input  wire [2:0]  decim_ratio,         // AXI4-Lite: 001=1:1, 010=1:2, 100=1:4

    output reg         sample_enable_rls,   // Decimated strobe to RLS+MLP
    output wire        sample_enable_cbpf,  // Full-rate strobe to CBPF+AAD
    output reg  [2:0]  decim_cnt_dbg        // Debug tap
);

    assign sample_enable_cbpf = sample_enable_in;

    reg [2:0] decim_cnt;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            decim_cnt        <= 3'b000;
            sample_enable_rls <= 1'b0;
            decim_cnt_dbg    <= 3'b000;
        end else begin
            if (sample_enable_in) begin
                decim_cnt <= decim_cnt + 3'b001;
                if (decim_ratio == 3'b001)
                    sample_enable_rls <= 1'b1;           // 1:1 — every sample
                else if (decim_ratio == 3'b010)
                    sample_enable_rls <= (decim_cnt == 3'b000);  // 1:2 — every other
                else if (decim_ratio == 3'b100)
                    sample_enable_rls <= (decim_cnt[1:0] == 2'b00); // 1:4 — every 4th
                else
                    sample_enable_rls <= 1'b1;           // default: passthrough

                decim_cnt_dbg <= decim_cnt;
            end else begin
                sample_enable_rls <= 1'b0;
            end
        end
    end

endmodule
