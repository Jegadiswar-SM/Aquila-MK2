`timescale 1ns/1ps
// Direct MLP transaction/schedule test with an explicitly zero-valued
// behavioral memory response.  This is a structural/transaction fixture only;
// it is not a trained-weight or model-equivalence test.
module tb_mlp_transaction;
    reg clk, rst_n, srst, en_in;
    reg [127:0] features_in;
    wire ren;
    wire [12:0] raddr;
    reg [255:0] rdata;
    reg rvalid;
    wire [15:0] y_out;
    wire valid_out;

    integer cycles;
    integer failures;
    integer guard;
    integer start_cycle;
    reg [127:0] first_features;

    mlp_inference dut (
        .clk(clk), .rst_n(rst_n), .srst(srst), .en_in(en_in),
        .features_in(features_in), .ren(ren), .raddr(raddr),
        .rdata(rdata), .rvalid(rvalid), .y_out(y_out),
        .valid_out(valid_out)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    // One-cycle synchronous zero-memory response.
    always @(posedge clk) begin
        rvalid <= ren;
        if (ren)
            rdata <= 256'd0;
        cycles = cycles + 1;
    end

    task start_inference;
        input [127:0] value;
        begin
            @(negedge clk);
            features_in = value;
            en_in = 1'b1;
            @(negedge clk);
            en_in = 1'b0;
        end
    endtask

    task wait_for_result;
        begin
            guard = 0;
            while (!valid_out && guard < 200000) begin
                @(posedge clk);
                guard = guard + 1;
            end
            if (!valid_out) begin
                $display("FAIL timeout state=%0d cycles=%0d", dut.state, cycles);
                failures = failures + 1;
            end else if (y_out !== 16'h0000) begin
                $display("FAIL zero-memory output=%h", y_out);
                failures = failures + 1;
            end
        end
    endtask

    initial begin
        cycles = 0;
        failures = 0;
        guard = 0;
        start_cycle = 0;
        first_features = 128'h0001_8000_7fff_ffff_0000_1234_8001;
        rst_n = 1'b0;
        srst = 1'b0;
        en_in = 1'b0;
        features_in = 128'd0;
        rdata = 256'd0;
        rvalid = 1'b0;

        repeat (4) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;

        // First transaction and a deliberately attempted busy-time input.
        start_inference(first_features);
        start_cycle = cycles;
        repeat (40) @(posedge clk);
        @(negedge clk);
        features_in = 128'hdead_beef_dead_beef_dead_beef_dead_beef;
        en_in = 1'b1;
        @(negedge clk);
        en_in = 1'b0;
        if (dut.feat_reg[0] !== $signed(first_features[127:112])) begin
            $display("FAIL busy-time input changed accepted feature: %h", dut.feat_reg[0]);
            failures = failures + 1;
        end
        wait_for_result();
        $display("INFO first zero-memory inference latency=%0d cycles", cycles-start_cycle);

        // Back-to-back transaction after completion.
        start_inference(128'h7fff_7fff_7fff_7fff_8000_8000_8000_8000);
        wait_for_result();

        // Soft reset during an active transaction must cancel it cleanly.
        start_inference(128'h1111_2222_3333_4444_5555_6666_7777_8888);
        repeat (40) @(posedge clk);
        @(negedge clk);
        srst = 1'b1;
        @(negedge clk);
        srst = 1'b0;
        repeat (100) @(posedge clk);
        if (valid_out) begin
            $display("FAIL result escaped soft reset");
            failures = failures + 1;
        end

        start_inference(128'h0000_0001_0002_0003_0004_0005_0006_0007);
        wait_for_result();

        if (failures == 0)
            $display("RESULT: PASS direct MLP transaction/zero-memory checks");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end

    initial begin
        #8000000;
        $display("TIMEOUT testbench");
        $finish;
    end
endmodule
