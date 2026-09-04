`timescale 1ns/1ps

module tb_mlp_weight_sram_wrapper;
    reg clk = 0;
    reg rst_n = 0;
    reg wload_en = 0;
    reg [16:0] wload_addr = 0;
    reg [15:0] wload_data = 0;
    reg ren = 0;
    reg [12:0] raddr = 0;
    wire [255:0] rdata;
    wire rvalid;
    reg [255:0] expected;
    integer i;

    always #5 clk = ~clk;

    mlp_weight_sram_wrapper dut (.*);

    task write_word;
        input [16:0] addr;
        input [15:0] data;
        begin
            @(negedge clk); wload_addr = addr; wload_data = data; wload_en = 1;
            @(negedge clk); wload_en = 0;
        end
    endtask

    task read_row;
        input [12:0] addr;
        begin
            @(negedge clk); raddr = addr; ren = 1;
            @(posedge clk); #1;
            if (!rvalid || rdata !== expected) begin
                $display("FAIL read row %0d valid=%b data=%h expected=%h", addr, rvalid, rdata, expected);
                $finish;
            end
            @(negedge clk); ren = 0;
        end
    endtask

    initial begin
        repeat (2) @(posedge clk);
        rst_n = 1;
        // One word and a full row; little word offset is [3:0].
        expected = 256'd0;
        write_word(17'h00000, 16'h1234); expected[15:0] = 16'h1234;
        read_row(13'd0);
        for (i = 0; i < 16; i = i + 1) begin
            write_word({13'd1, i[3:0]}, 16'h5000 + i);
            expected[i*16 +: 16] = 16'h5000 + i;
        end
        read_row(13'd1);
        // Row isolation and repeated overwrite.
        write_word({13'd2, 4'd3}, 16'hCAFE);
        expected = 256'd0; expected[3*16 +: 16] = 16'hCAFE;
        read_row(13'd2);
        expected = 256'd0; expected[15:0] = 16'h1234;
        read_row(13'd0);
        write_word({13'd2, 4'd3}, 16'hBEEF);
        expected[3*16 +: 16] = 16'hBEEF;
        read_row(13'd2);
        // Highest representable row and word address.
        write_word(17'h1ffff, 16'hFACE);
        expected = 256'd0; expected[15*16 +: 16] = 16'hFACE;
        read_row(13'd8191);
        // Same-edge read/write has old-data semantics in this behavioral model.
        expected[15*16 +: 16] = 16'hFACE;
        @(negedge clk); raddr = 13'd8191; ren = 1; wload_addr = 17'h1ffff;
        wload_data = 16'h0BAD; wload_en = 1;
        @(posedge clk); #1;
        if (!rvalid || rdata !== expected) begin $display("FAIL collision"); $finish; end
        @(negedge clk); ren = 0; wload_en = 0;
        expected[15*16 +: 16] = 16'h0BAD; read_row(13'd8191);
        // Reset clears read response state, not weight contents.
        rst_n = 0; @(posedge clk); #1;
        if (rvalid !== 1'b0 || rdata !== 256'd0) begin $display("FAIL reset response"); $finish; end
        rst_n = 1;
        $display("RESULT: PASS memory adapter contract");
        $finish;
    end
endmodule
