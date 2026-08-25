`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// Boundary regression for the signed y_hat conversion.  The force is
// intentional: this test isolates the output conversion from the adaptive
// convergence loop so the accumulator limits can be checked exactly.
module tb_rls_engine_sat;
    reg clk;
    reg rst_n;
    reg srst;
    reg sample_en;
    reg signed [15:0] d_in;
    reg signed [15:0] x_in;
    reg signed [15:0] lambda_in;
    reg signed [15:0] leak_factor;
    reg signed [15:0] e_weighted;
    wire signed [15:0] error_out;
    wire                valid_out;
    wire signed [15:0] y_hat;
    wire signed [15:0] nr_x2_debug;

    rls_engine dut (
        .clk          (clk),
        .rst_n        (rst_n),
        .srst         (srst),
        .sample_en    (sample_en),
        .d_in         (d_in),
        .x_in         (x_in),
        .lambda_in    (lambda_in),
        .leak_factor  (leak_factor),
        .e_weighted   (e_weighted),
        .error_out    (error_out),
        .valid_out    (valid_out),
        .y_hat        (y_hat),
        .nr_x2_debug  (nr_x2_debug)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    integer failures;

    task check_y_hat;
        input signed [39:0] acc_value;
        input signed [15:0] expected;
        begin
            force dut.y_acc = acc_value;
            @(negedge clk);
            sample_en = 1'b1;
            @(posedge clk);
            #1 sample_en = 1'b0;
            @(posedge clk);
            #1;
            if (y_hat !== expected) begin
                $display("FAIL y_acc=%0d expected y_hat=%0d got %0d",
                         acc_value, expected, y_hat);
                failures = failures + 1;
            end
            release dut.y_acc;
        end
    endtask

    initial begin
        failures  = 0;
        rst_n     = 1'b0;
        srst      = 1'b0;
        sample_en = 1'b0;
        d_in      = 16'sd0;
        x_in      = 16'sd0;
        lambda_in = 16'sd0;
        leak_factor = 16'sh7FE0;
        e_weighted = 16'sd0;

        repeat (3) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;

        check_y_hat(-40'sd536870912,  16'shC000); // -0.5 in Q1.15
        check_y_hat( 40'sd536870912,  16'sh4000); // +0.5 in Q1.15
        check_y_hat(-40'sd1310720000, 16'sh8000); // negative saturation
        check_y_hat( 40'sd1310720000, 16'sh7FFF); // positive saturation

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end
endmodule
