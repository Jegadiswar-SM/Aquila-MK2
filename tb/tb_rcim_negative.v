`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// The monitor uses correlation magnitude, so an inverted but otherwise
// coherent reference must not be classified as a reference fault.
module tb_rcim_negative;
    reg clk;
    reg rst_n;
    reg srst;
    reg [15:0] d_in;
    reg [15:0] x_in;
    reg samples_valid;
    wire ref_channel_fault;
    wire [15:0] x_out_muxed;
    wire s_axi_awready;
    wire s_axi_wready;

    rcim #(.FAULT_PERSIST(32)) dut (
        .clk               (clk),
        .rst_n             (rst_n),
        .srst              (srst),
        .d_in              (d_in),
        .x_in              (x_in),
        .samples_valid     (samples_valid),
        .s_axi_awaddr      (5'd0),
        .s_axi_awvalid     (1'b0),
        .s_axi_wdata      (32'd0),
        .s_axi_wvalid     (1'b0),
        .s_axi_awready     (s_axi_awready),
        .s_axi_wready      (s_axi_wready),
        .ref_channel_fault (ref_channel_fault),
        .x_out_muxed       (x_out_muxed)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    integer failures;
    integer sample;

    initial begin
        failures = 0;
        rst_n = 1'b0;
        srst = 1'b0;
        d_in = 16'sd0;
        x_in = 16'sd0;
        samples_valid = 1'b0;
        repeat (10) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;
        @(negedge clk);
        d_in = 16'shC000;
        x_in = 16'sh4000;
        samples_valid = 1'b1;
        for (sample = 0; sample < 300; sample = sample + 1)
            @(posedge clk);

        #1;
        if (ref_channel_fault) begin
            $display("FAIL: inverted coherent reference flagged as fault");
            failures = failures + 1;
        end else begin
            $display("PASS: inverted coherent reference accepted");
        end

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end
endmodule
