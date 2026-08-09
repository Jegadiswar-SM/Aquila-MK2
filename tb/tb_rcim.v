`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

module tb_rcim;
    reg        clk;
    reg        rst_n;
    reg [15:0] d_in;
    reg [15:0] x_in;
    reg        samples_valid;
    reg [4:0]  s_axi_awaddr;
    reg        s_axi_awvalid;
    reg [31:0] s_axi_wdata;
    reg        s_axi_wvalid;
    wire       s_axi_awready;
    wire       s_axi_wready;
    wire       ref_channel_fault;
    wire [15:0] x_out_muxed;

    rcim dut (
        .clk               (clk),
        .rst_n             (rst_n),
        .d_in              (d_in),
        .x_in              (x_in),
        .samples_valid     (samples_valid),
        .s_axi_awaddr      (s_axi_awaddr),
        .s_axi_awvalid     (s_axi_awvalid),
        .s_axi_wdata       (s_axi_wdata),
        .s_axi_wvalid      (s_axi_wvalid),
        .s_axi_awready     (s_axi_awready),
        .s_axi_wready      (s_axi_wready),
        .ref_channel_fault (ref_channel_fault),
        .x_out_muxed       (x_out_muxed)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    integer pass, fail;

    initial begin
        $display("===== tb_rcim: start =====");
        pass = 0; fail = 0;

        rst_n = 1'b0; samples_valid = 1'b0;
        d_in = 16'sd0; x_in = 16'sd0;
        s_axi_awaddr = 5'h0; s_axi_awvalid = 1'b0;
        s_axi_wdata = 32'h0; s_axi_wvalid = 1'b0;

        repeat(10) @(posedge clk);
        @(negedge clk); rst_n = 1'b1;
        @(posedge clk);

        // Correlated d and x — no fault expected
        d_in = 16'sh4000; x_in = 16'sh4000; samples_valid = 1'b1;
        repeat(40) @(posedge clk);
        if (!ref_channel_fault) begin
            $display("PASS: no fault with correlated channels"); pass = pass + 1;
        end else begin
            $display("FAIL: unexpected fault"); fail = fail + 1;
        end

        // Uncorrelated — x should look like noise vs d
        d_in = 16'sh4000; x_in = 16'sd0; samples_valid = 1'b1;
        repeat(200) @(posedge clk);
        if (ref_channel_fault) begin
            $display("PASS: fault detected with uncorrelated reference"); pass = pass + 1;
        end else begin
            $display("FAIL: expected fault not detected"); fail = fail + 1;
        end

        // x_out_muxed should be 0 during fault
        if (x_out_muxed == 16'sd0) begin
            $display("PASS: x_out_muxed = 0 during fault"); pass = pass + 1;
        end else begin
            $display("FAIL: x_out_muxed != 0 during fault (0x%04h)", x_out_muxed); fail = fail + 1;
        end

        samples_valid = 1'b0;
        repeat(10) @(posedge clk);

        $display("===== tb_rcim: %0d pass, %0d fail =====", pass, fail);
        if (fail) $display("RESULT: FAIL");
        else      $display("RESULT: PASS");
        $finish;
    end

    initial begin #500_000; $display("TIMEOUT"); $finish; end
    initial begin $dumpfile("tb_rcim.vcd"); $dumpvars(0, tb_rcim); end
endmodule
