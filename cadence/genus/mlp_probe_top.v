`timescale 1ns/1ps
module mlp_probe_top (
    input wire clk, input wire rst_n, input wire srst, input wire en_in,
    input wire [127:0] features_in,
    output wire ren, output wire [12:0] raddr,
    input wire [255:0] rdata, input wire rvalid,
    output wire [15:0] y_out, output wire valid_out
);
    mlp_inference u_mlp (
        .clk(clk), .rst_n(rst_n), .srst(srst), .en_in(en_in),
        .features_in(features_in), .ren(ren), .raddr(raddr),
        .rdata(rdata), .rvalid(rvalid), .y_out(y_out), .valid_out(valid_out)
    );
endmodule
