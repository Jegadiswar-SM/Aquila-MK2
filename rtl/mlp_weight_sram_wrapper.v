// =============================================================================
// Module      : mlp_weight_sram_wrapper
// Description : Behavioral wrapper for sky130 OpenRAM SRAM.
//               Configured with a 16-bit write port (for easy sequential loading)
//               and a 256-bit read port (delivering 16 weights in parallel per cycle
//               to the time-multiplexed MLP engine).
//
//               Total capacity: 8192 rows x 256 bits = 2.097 Megabits (~262 KB).
//               We use 6257 rows for the 8->128->384->128->1 network.
//
// Author      : MHDA RTL Hardening (ASIC prep)
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module mlp_weight_sram_wrapper (
    input  wire         clk,
    input  wire         rst_n,

    // Write Port (16-bit wide for sequential programming)
    input  wire         wload_en,
    input  wire [16:0]  wload_addr, // 0 to 131071 (17-bit for word address)
    input  wire [15:0]  wload_data,

    // Read Port (255-bit wide for parallel execution)
    input  wire         ren,
    input  wire [12:0]  raddr,      // 0 to 8191 (13-bit for row address)
    output reg  [255:0] rdata,
    output reg          rvalid
);

    // 8192 rows of 256 bits (each row is 16 words of 16-bit)
    reg [255:0] mem [0:8191];

    // Write port: address map is word-addressable
    // wload_addr[16:4] selects the row (0 to 8191)
    // wload_addr[3:0] selects the 16-bit word offset within the row (0 to 15)
    wire [12:0] wrow = wload_addr[16:4];
    wire [3:0]  woff = wload_addr[3:0];

    always @(posedge clk) begin
        if (wload_en) begin
            case (woff)
                4'd0:  mem[wrow][15:0]    <= wload_data;
                4'd1:  mem[wrow][31:16]   <= wload_data;
                4'd2:  mem[wrow][47:32]   <= wload_data;
                4'd3:  mem[wrow][63:48]   <= wload_data;
                4'd4:  mem[wrow][79:64]   <= wload_data;
                4'd5:  mem[wrow][95:80]   <= wload_data;
                4'd6:  mem[wrow][111:96]  <= wload_data;
                4'd7:  mem[wrow][127:112] <= wload_data;
                4'd8:  mem[wrow][143:128] <= wload_data;
                4'd9:  mem[wrow][159:144] <= wload_data;
                4'd10: mem[wrow][175:160] <= wload_data;
                4'd11: mem[wrow][191:176] <= wload_data;
                4'd12: mem[wrow][207:192] <= wload_data;
                4'd13: mem[wrow][223:208] <= wload_data;
                4'd14: mem[wrow][239:224] <= wload_data;
                4'd15: mem[wrow][255:240] <= wload_data;
            endcase
        end
    end

    // Read port: 1-cycle latency
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rdata  <= 256'd0;
            rvalid <= 1'b0;
        end else begin
            rvalid <= ren;
            if (ren) begin
                rdata <= mem[raddr];
            end
        end
    end

endmodule
