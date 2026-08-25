`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

module tb_affhc;
    reg        clk;
    reg        rst_n;
    reg [15:0] e_in;
    reg        e_valid;
    reg [4:0]  s_axi_awaddr;
    reg        s_axi_awvalid;
    reg [31:0] s_axi_wdata;
    reg        s_axi_wvalid;
    wire       s_axi_awready;
    wire       s_axi_wready;
    wire [15:0] lambda_out;
    wire [1:0]  fsm_state_dbg;

    affhc dut (
        .clk              (clk),
        .rst_n            (rst_n),
        .e_in             (e_in),
        .e_valid          (e_valid),
        .s_axi_awaddr     (s_axi_awaddr),
        .s_axi_awvalid    (s_axi_awvalid),
        .s_axi_wdata      (s_axi_wdata),
        .s_axi_wvalid     (s_axi_wvalid),
        .s_axi_awready    (s_axi_awready),
        .s_axi_wready     (s_axi_wready),
        .lambda_out       (lambda_out),
        .fsm_state_dbg    (fsm_state_dbg)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    integer pass, fail;

    initial begin
        $display("===== tb_affhc: start =====");
        pass = 0; fail = 0;

        rst_n = 1'b0; e_valid = 1'b0; e_in = 16'sd0;
        s_axi_awaddr = 5'h0; s_axi_awvalid = 1'b0;
        s_axi_wdata = 32'h0; s_axi_wvalid = 1'b0;

        repeat(10) @(posedge clk);
        @(negedge clk); rst_n = 1'b1;
        @(posedge clk);

        // Check initial state = STEADY, lambda_slow = 0x7F00
        if (fsm_state_dbg == 2'b00 && lambda_out == 16'h7F00) begin
            $display("PASS: initial state STEADY, lambda=0x%04h", lambda_out); pass = pass + 1;
        end else begin
            $display("FAIL: initial state=%b lambda=0x%04h", fsm_state_dbg, lambda_out); fail = fail + 1;
        end

        force dut.e_in = 16'sh7fff;
        force dut.e_prev = 16'sh8000;
        #1;
        if (dut.delta_e !== 17'h0ffff) begin
            $display("FAIL: extreme signed delta=%h", dut.delta_e); fail = fail + 1;
        end else begin
            $display("PASS: extreme signed delta"); pass = pass + 1;
        end
        release dut.e_in;
        release dut.e_prev;

        // Inject large delta-e to trigger TRACKING
        // Alternate the error so |e(n)-e(n-1)| remains above the threshold
        // for the configured dwell interval.  Holding 3000 would produce one
        // large delta followed by zero deltas.
        e_valid = 1'b1;
        repeat(8) begin
            @(negedge clk);
            e_in = (e_in == 16'sd3000) ? 16'sd0 : 16'sd3000;
        end
        // Once TRACKING is reached, keep the delta in the hysteresis band so
        // the FSM does not intentionally advance to FAST.
        repeat(40) begin
            @(negedge clk);
            e_in = (e_in == 16'sd256) ? 16'sd0 : 16'sd256;
        end
        if (fsm_state_dbg == 2'b01) begin
            $display("PASS: transition to TRACKING"); pass = pass + 1;
        end else begin
            $display("FAIL: expected TRACKING got %b", fsm_state_dbg); fail = fail + 1;
        end

        // Inject small delta-e to return to STEADY
        repeat(12) begin
            @(negedge clk);
            e_in = (e_in == 16'sd50) ? 16'sd0 : 16'sd50;
        end
        repeat(50) @(posedge clk);
        if (fsm_state_dbg == 2'b00) begin
            $display("PASS: returned to STEADY"); pass = pass + 1;
        end else begin
            $display("FAIL: expected STEADY got %b", fsm_state_dbg); fail = fail + 1;
        end

        e_valid = 1'b0;
        repeat(10) @(posedge clk);

        $display("===== tb_affhc: %0d pass, %0d fail =====", pass, fail);
        if (fail) $display("RESULT: FAIL");
        else      $display("RESULT: PASS");
        $finish;
    end

    initial begin #200_000; $display("TIMEOUT"); $finish; end
    initial begin $dumpfile("tb_affhc.vcd"); $dumpvars(0, tb_affhc); end
endmodule
