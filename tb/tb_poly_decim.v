`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

module tb_poly_decim;
    reg       clk;
    reg       rst_n;
    reg       srst;
    reg       sample_enable_in;
    reg [2:0] decim_ratio;
    wire      sample_enable_rls;
    wire      sample_enable_cbpf;
    wire [2:0] decim_cnt_dbg;

    poly_decim dut (
        .clk                 (clk),
        .rst_n               (rst_n),
        .srst                (srst),
        .sample_enable_in    (sample_enable_in),
        .decim_ratio         (decim_ratio),
        .sample_enable_rls   (sample_enable_rls),
        .sample_enable_cbpf  (sample_enable_cbpf),
        .decim_cnt_dbg       (decim_cnt_dbg)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    integer failures;
    integer sample;

    task run_ratio;
        input [2:0] ratio;
        input integer count;
        begin
            decim_ratio = ratio;
            for (sample = 0; sample < count; sample = sample + 1) begin
                @(negedge clk);
                sample_enable_in = 1'b1;
                @(posedge clk);
                #1;
                if (ratio == 3'b001) begin
                    if (!sample_enable_rls) begin
                        $display("FAIL ratio=1:1 sample=%0d", sample);
                        failures = failures + 1;
                    end
                end else if (ratio == 3'b010) begin
                    if (sample_enable_rls !== (sample[0] == 1'b0)) begin
                        $display("FAIL ratio=1:2 sample=%0d enable=%b", sample, sample_enable_rls);
                        failures = failures + 1;
                    end
                end else if (ratio == 3'b100) begin
                    if (sample_enable_rls !== (sample[1:0] == 2'b00)) begin
                        $display("FAIL ratio=1:4 sample=%0d enable=%b", sample, sample_enable_rls);
                        failures = failures + 1;
                    end
                end
                if (sample_enable_cbpf !== 1'b1) begin
                    $display("FAIL CBPF strobe sample=%0d", sample);
                    failures = failures + 1;
                end
            end
            @(negedge clk);
            sample_enable_in = 1'b0;
            @(posedge clk);
            #1;
            if (sample_enable_rls !== 1'b0) begin
                $display("FAIL ratio=%b bubble did not clear output", ratio);
                failures = failures + 1;
            end
        end
    endtask

    initial begin
        failures = 0;
        rst_n = 1'b0;
        srst = 1'b0;
        sample_enable_in = 1'b0;
        decim_ratio = 3'b001;
        repeat (2) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;

        run_ratio(3'b001, 8);
        run_ratio(3'b010, 12);
        run_ratio(3'b100, 16);

        srst = 1'b1;
        @(posedge clk);
        #1;
        srst = 1'b0;
        if (sample_enable_rls !== 1'b0 || decim_cnt_dbg !== 3'd0) begin
            $display("FAIL soft reset output=%b phase=%b",
                     sample_enable_rls, decim_cnt_dbg);
            failures = failures + 1;
        end

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end
endmodule
