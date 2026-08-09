`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

module tb_aad;
    reg        clk;
    reg        rst_n;
    reg [15:0] x_in;
    reg        x_valid;
    reg [3:0]  s_axi_awaddr;
    reg        s_axi_awvalid;
    reg [31:0] s_axi_wdata;
    reg        s_axi_wvalid;
    wire       s_axi_awready;
    wire       s_axi_wready;
    wire       signal_active;
    wire       clk_gate_en;
    wire [39:0] acc_A_dbg;
    wire [39:0] acc_B_dbg;

    aad dut (
        .clk            (clk),
        .rst_n          (rst_n),
        .x_in           (x_in),
        .x_valid        (x_valid),
        .s_axi_awaddr   (s_axi_awaddr),
        .s_axi_awvalid  (s_axi_awvalid),
        .s_axi_wdata    (s_axi_wdata),
        .s_axi_wvalid   (s_axi_wvalid),
        .s_axi_awready  (s_axi_awready),
        .s_axi_wready   (s_axi_wready),
        .signal_active  (signal_active),
        .clk_gate_en    (clk_gate_en),
        .acc_A_dbg      (acc_A_dbg),
        .acc_B_dbg      (acc_B_dbg)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    integer pass, fail;

    initial begin
        $display("===== tb_aad: start =====");
        pass = 0; fail = 0;

        rst_n = 1'b0; x_valid = 1'b0; x_in = 16'sd0;
        s_axi_awaddr = 4'h0; s_axi_awvalid = 1'b0;
        s_axi_wdata = 32'h0; s_axi_wvalid = 1'b0;

        repeat(10) @(posedge clk);
        @(negedge clk); rst_n = 1'b1;
        @(posedge clk);

        // Start with silence — signal should stay inactive
        x_in = 16'sd0; x_valid = 1'b1;
        repeat(20) @(posedge clk);
        if (!signal_active) begin
            $display("PASS: silence -> signal inactive"); pass = pass + 1;
        end else begin
            $display("FAIL: expected inactive"); fail = fail + 1;
        end

        // Large signal should assert activity
        x_in = 16'sh6000; x_valid = 1'b1;
        repeat(20) @(posedge clk);
        if (signal_active) begin
            $display("PASS: loud -> signal active"); pass = pass + 1;
        end else begin
            $display("FAIL: expected active"); fail = fail + 1;
        end

        // Return to silence — should deassert
        x_in = 16'sd0; x_valid = 1'b1;
        repeat(100) @(posedge clk);
        if (!signal_active) begin
            $display("PASS: returned to inactive"); pass = pass + 1;
        end else begin
            $display("FAIL: expected inactive after silence"); fail = fail + 1;
        end

        x_valid = 1'b0;
        repeat(10) @(posedge clk);

        $display("===== tb_aad: %0d pass, %0d fail =====", pass, fail);
        if (fail) $display("RESULT: FAIL");
        else      $display("RESULT: PASS");
        $finish;
    end

    initial begin #300_000; $display("TIMEOUT"); $finish; end
    initial begin $dumpfile("tb_aad.vcd"); $dumpvars(0, tb_aad); end
endmodule
