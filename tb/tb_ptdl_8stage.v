`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

module tb_ptdl_8stage;
    reg clk;
    reg rst_n;
    reg srst;
    reg sample_en;
    reg signed [15:0] e_in;
    wire [127:0] taps_out;
    integer failures;
    integer sample;

    ptdl_8stage dut (
        .clk       (clk),
        .rst_n     (rst_n),
        .srst      (srst),
        .sample_en (sample_en),
        .e_in      (e_in),
        .taps_out  (taps_out)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    initial begin
        failures = 0;
        rst_n = 1'b0;
        srst = 1'b0;
        sample_en = 1'b0;
        e_in = 16'sd0;
        repeat (3) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;

        for (sample = 1; sample <= 8; sample = sample + 1) begin
            @(negedge clk);
            e_in = sample;
            sample_en = 1'b1;
            @(posedge clk);
            #1;
            sample_en = 1'b0;
            if (taps_out[127:112] !== sample[15:0]) begin
                $display("FAIL newest sample=%0d got=%0d", sample,
                         $signed(taps_out[127:112]));
                failures = failures + 1;
            end
        end

        #1;
        if (taps_out !== {16'd8, 16'd7, 16'd6, 16'd5,
                          16'd4, 16'd3, 16'd2, 16'd1}) begin
            $display("FAIL packed taps=%h", taps_out);
            failures = failures + 1;
        end else begin
            $display("PASS packed taps=%h", taps_out);
        end

        srst = 1'b1;
        @(posedge clk);
        #1;
        srst = 1'b0;
        if (taps_out !== 128'd0) begin
            $display("FAIL soft reset taps=%h", taps_out);
            failures = failures + 1;
        end else begin
            $display("PASS soft reset clears tap history");
        end

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end
endmodule
