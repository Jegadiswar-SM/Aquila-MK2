`timescale 1ns/1ps
// Language-semantics oracle for the qaa_tanh function as compiled from the
// actual mlp_inference module. This test is intentionally separate from model
// verification and exposes no new RTL behavior.
module tb_mlp_qaa_oracle;
    reg clk = 1'b0;
    reg rst_n = 1'b0;
    reg srst = 1'b0;
    reg en_in = 1'b0;
    reg [127:0] features_in = 128'd0;
    reg [255:0] rdata = 256'd0;
    reg rvalid = 1'b0;
    wire ren;
    wire [12:0] raddr;
    wire [15:0] y_out;
    wire valid_out;

    mlp_inference dut (.clk(clk), .rst_n(rst_n), .srst(srst), .en_in(en_in),
        .features_in(features_in), .ren(ren), .raddr(raddr), .rdata(rdata),
        .rvalid(rvalid), .y_out(y_out), .valid_out(valid_out));

    always #5 clk = ~clk;

    initial begin
        #1;
        $display("qaa(0)=%h qaa(2)=%h qaa(8192)=%h qaa(8193)=%h qaa(16384)=%h qaa(16385)=%h qaa(24576)=%h qaa(24577)=%h neg8192=%h neg16384=%h neg32768=%h", 
            dut.qaa_tanh(16'sd0), dut.qaa_tanh(16'sd2), dut.qaa_tanh(16'sd8192),
            dut.qaa_tanh(16'sd8193), dut.qaa_tanh(16'sd16384), dut.qaa_tanh(16'sd16385),
            dut.qaa_tanh(16'sd24576), dut.qaa_tanh(16'sd24577), dut.qaa_tanh(-16'sd8192),
            dut.qaa_tanh(-16'sd16384), dut.qaa_tanh(-16'sd32768));
        $display("QAA RTL ORACLE: compiled-expression results captured");
        $finish;
    end
endmodule
