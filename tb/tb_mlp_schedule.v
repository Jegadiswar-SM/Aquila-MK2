`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// Schedule-only MLP regression.  A zero-valued synchronous memory model makes
// this independent of the unavailable trained weight artifact while checking
// the complete address/valid handshake and terminal rows.
module tb_mlp_schedule;
    reg clk;
    reg rst_n;
    reg srst;
    reg en_in;
    reg [127:0] features_in;
    wire ren;
    wire [12:0] raddr;
    reg [255:0] rdata;
    reg rvalid;
    wire [15:0] y_out;
    wire valid_out;

    reg seen [0:8191];
    integer i;
    integer cycles;
    integer read_count;
    integer failures;

    mlp_inference dut (
        .clk         (clk),
        .rst_n       (rst_n),
        .srst        (srst),
        .en_in       (en_in),
        .features_in (features_in),
        .ren         (ren),
        .raddr       (raddr),
        .rdata       (rdata),
        .rvalid      (rvalid),
        .y_out       (y_out),
        .valid_out   (valid_out)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    // One-cycle synchronous read model.  The command visible before each
    // active edge is the command accepted by the memory on that edge.
    always @(posedge clk) begin
        rvalid <= ren;
        if (ren) begin
            rdata <= 256'd0;
            seen[raddr] = 1'b1;
            read_count = read_count + 1;
        end
        cycles = cycles + 1;
    end

    initial begin
        failures = 0;
        cycles = 0;
        read_count = 0;
        rdata = 256'd0;
        rvalid = 1'b0;
        rst_n = 1'b0;
        srst = 1'b0;
        en_in = 1'b0;
        features_in = 128'd0;
        for (i = 0; i < 8192; i = i + 1)
            seen[i] = 1'b0;

        repeat (5) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;
        @(negedge clk);
        en_in = 1'b1;
        @(posedge clk);
        #1 en_in = 1'b0;

        wait (valid_out);
        #1;
        if (y_out !== 16'd0) begin
            $display("FAIL zero-memory output y=%h", y_out);
            failures = failures + 1;
        end
        if (!seen[79]) begin
            $display("FAIL missing final layer-1 W2 row 79");
            failures = failures + 1;
        end
        if (!seen[6239]) begin
            $display("FAIL missing final layer-3 W3 row 6239");
            failures = failures + 1;
        end
        if (!seen[6255]) begin
            $display("FAIL missing final layer-4 W4 row 6255");
            failures = failures + 1;
        end

        if (failures == 0)
            $display("RESULT: PASS cycles=%0d reads=%0d", cycles, read_count);
        else
            $display("RESULT: FAIL failures=%0d cycles=%0d reads=%0d",
                     failures, cycles, read_count);
        $finish;
    end

    initial begin
        #2000000;
        $display("TIMEOUT cycles=%0d reads=%0d state=%0d",
                 cycles, read_count, dut.state);
        $finish;
    end
endmodule
