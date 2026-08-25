`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// This regression records the executable FWES recurrence.  The RTL stores
// e_in in e_w_prev, so the second sample below is expected to use the prior
// unweighted input; this test does not silently reinterpret the comment.
module tb_fwes;
    reg clk, rst_n, e_valid;
    reg signed [15:0] e_in, alpha_reg;
    wire signed [15:0] e_weighted, e_output;
    integer failures;

    fwes dut (
        .clk(clk), .rst_n(rst_n), .e_in(e_in), .e_valid(e_valid),
        .alpha_reg(alpha_reg), .e_weighted(e_weighted), .e_output(e_output)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    initial begin
        failures = 0;
        rst_n = 1'b0;
        e_valid = 1'b0;
        e_in = 16'sd0;
        alpha_reg = 16'sh4000; // 0.5 in Q1.15

        repeat (3) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;

        e_valid = 1'b1;
        e_in = 16'sh2000;
        @(posedge clk);
        #1;
        if (e_weighted !== 16'sh2000) begin
            $display("FAIL first FWES result=%h", e_weighted);
            failures = failures + 1;
        end

        e_in = 16'sh2000;
        @(posedge clk);
        #1;
        if (e_weighted !== 16'sh1000) begin
            $display("FAIL executable recurrence result=%h", e_weighted);
            failures = failures + 1;
        end
        if (e_output !== e_in) begin
            $display("FAIL passthrough output=%h", e_output);
            failures = failures + 1;
        end

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end
endmodule
