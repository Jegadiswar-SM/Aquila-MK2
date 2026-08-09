`timescale 1ns / 1ps

module tb_nr2_isolated;

    reg         clk;
    reg         rst_n;
    reg         srst;
    reg         sample_en;
    reg  signed [15:0] d_in;
    reg  signed [15:0] x_in;
    reg  signed [15:0] lambda_in;
    reg  signed [15:0] leak_factor;
    reg  signed [15:0] e_weighted;
    /* verilator lint_off UNUSEDSIGNAL */
    wire signed [15:0] error_out;
    wire               valid_out;
    wire signed [15:0] y_hat;
    /* verilator lint_on UNUSEDSIGNAL */
    wire signed [15:0] nr_x2_debug;

    integer idx;
    integer d_q;
    integer signed x2_signed;
    real d_float;
    real true_inv;
    real hw_inv;
    real err;
    real max_err;
    real worst_d;
    real worst_hw;
    real worst_true;

    rls_engine #(
        .N(8),
        .W(16),
        .LAMBDA_Q15(16'h7F00)
    ) dut (
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
    /* verilator lint_off BLKSEQ */
    always #5 clk = ~clk;
    /* verilator lint_on BLKSEQ */

    task run_vector;
        input integer d_q_in;
        begin
            @(negedge clk);
            lambda_in = d_q_in[15:0];
            x_in      = 16'sd0;
            d_in      = 16'sd0;
            sample_en = 1'b1;

            @(posedge clk);
            @(negedge clk);
            sample_en = 1'b0;

            @(posedge clk);
            @(posedge clk);
            @(posedge clk);
            #1;

            x2_signed = $signed({{16{nr_x2_debug[15]}}, nr_x2_debug});
            d_float = $itor(d_q_in) / 32768.0;
            true_inv = 1.0 / d_float;
            hw_inv = $itor(x2_signed) / 16384.0;
            err = true_inv - hw_inv;
            if (err < 0.0)
                err = -err;

            if (err > max_err) begin
                max_err = err;
                worst_d = d_float;
                worst_hw = hw_inv;
                worst_true = true_inv;
            end

            $display("D=0x%04X D=%0.6f true_inv=%0.6f hw_inv=%0.6f error=%0.6f",
                     d_q_in[15:0], d_float, true_inv, hw_inv, err);
        end
    endtask

    initial begin
        $display("==========================================");
        $display("NR2 Isolated Sweep Testbench");
        $display("==========================================");

        rst_n       = 1'b0;
        srst        = 1'b0;
        sample_en   = 1'b0;
        d_in        = 16'sd0;
        x_in        = 16'sd0;
        lambda_in   = 16'sd0;
        leak_factor = 16'h7FE0;
        e_weighted  = 16'sd0;
        max_err     = 0.0;
        worst_d     = 0.0;
        worst_hw    = 0.0;
        worst_true  = 0.0;

        repeat (2) @(negedge clk);
        rst_n = 1'b1;
        $display("t=%0t: Reset released", $time);

        for (idx = 0; idx < 80; idx = idx + 1) begin
            d_q = 32'sh00004000 + ((32'sh00007FFF - 32'sh00004000) * idx) / 79;
            run_vector(d_q);
        end
        run_vector(32'sh00007FFF);

        $display("");
        $display("MAX_ERR=%0.6f worst_D=%0.6f true_inv=%0.6f hw_inv=%0.6f",
                 max_err, worst_d, worst_true, worst_hw);
        if (max_err < 0.01)
            $display("NR2_SWEEP_PASS");
        else begin
            $display("NR2_SWEEP_FAIL");
            $finish;
        end

        $finish;
    end

endmodule
