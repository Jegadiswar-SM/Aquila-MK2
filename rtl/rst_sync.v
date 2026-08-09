// =============================================================================
// Module      : rst_sync
// Description : 2-Flop Reset Synchronizer
//               Async-assert (immediately propagates negedge rst_n_i),
//               sync-deassert (deasserts only on posedge clk after two
//               clean clock edges). This is the ASIC-standard approach to
//               prevent reset metastability on the deassertion edge.
//
//               Usage: Instantiate once in the top level. Drive all
//               internal flip-flops from rst_n_o, NOT from rst_n_i.
//               The pad-ring rst_n input connects only to rst_n_i.
//
//               (* dont_touch = "true" *) prevents synthesis from
//               merging or removing the two synchronizer FFs. The
//               attribute is recognized by Genus, DC, and Vivado.
//
// Author      : MHDA RTL Hardening (ASIC prep)
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module rst_sync (
    input  wire clk,        // Core clock (100 MHz)
    input  wire rst_n_i,    // Asynchronous reset from IO pad (active-low)
    output wire rst_n_o     // Synchronous-deassert reset to logic (active-low)
);

    // Two cascaded FFs, placed in the same clock domain.
    // (* dont_touch = "true" *) prevents synthesis optimization.
    (* dont_touch = "true" *) reg ff1;
    (* dont_touch = "true" *) reg ff2;

    always @(posedge clk or negedge rst_n_i) begin
        if (!rst_n_i) begin
            ff1 <= 1'b0;
            ff2 <= 1'b0;
        end else begin
            ff1 <= 1'b1;
            ff2 <= ff1;
        end
    end

    assign rst_n_o = ff2;

endmodule
