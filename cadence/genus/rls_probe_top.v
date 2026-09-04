`timescale 1ns/1ps
module rls_probe_top (
    input wire clk,
    input wire rst_n,
    input wire srst,
    input wire sample_en,
    input wire signed [15:0] d_in,
    input wire signed [15:0] x_in,
    input wire signed [15:0] lambda_in,
    input wire signed [15:0] leak_factor,
    input wire signed [15:0] e_weighted,
    output wire signed [15:0] error_out,
    output wire valid_out,
    output wire signed [15:0] y_hat,
    output wire signed [15:0] nr_x2_debug
);
    rls_engine u_rls (
        .clk(clk), .rst_n(rst_n), .srst(srst), .sample_en(sample_en),
        .d_in(d_in), .x_in(x_in), .lambda_in(lambda_in),
        .leak_factor(leak_factor), .e_weighted(e_weighted),
        .error_out(error_out), .valid_out(valid_out), .y_hat(y_hat),
        .nr_x2_debug(nr_x2_debug)
    );
endmodule
