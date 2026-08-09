`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

module tb_plwd;
    reg        clk;
    reg        rst_n;
    reg        m_axis_tvalid;
    reg [15:0] m_axis_tdata;
    reg [3:0]  s_axi_araddr;
    reg        s_axi_arvalid;
    wire [31:0] s_axi_rdata;
    wire        s_axi_rvalid;
    reg [3:0]  s_axi_awaddr;
    reg        s_axi_awvalid;
    reg [31:0] s_axi_wdata;
    reg        s_axi_wvalid;
    wire       s_axi_awready;
    wire       s_axi_wready;
    wire       pipeline_srst;
    wire       irq_fault;

    plwd #(
        .VALID_TIMEOUT   (8),
        .STUCK_THRESHOLD (4)
    ) dut (
        .clk             (clk),
        .rst_n           (rst_n),
        .m_axis_tvalid   (m_axis_tvalid),
        .m_axis_tdata    (m_axis_tdata),
        .s_axi_araddr    (s_axi_araddr),
        .s_axi_arvalid   (s_axi_arvalid),
        .s_axi_rdata     (s_axi_rdata),
        .s_axi_rvalid    (s_axi_rvalid),
        .s_axi_awaddr    (s_axi_awaddr),
        .s_axi_awvalid   (s_axi_awvalid),
        .s_axi_wdata     (s_axi_wdata),
        .s_axi_wvalid    (s_axi_wvalid),
        .s_axi_awready   (s_axi_awready),
        .s_axi_wready    (s_axi_wready),
        .pipeline_srst   (pipeline_srst),
        .irq_fault       (irq_fault)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    integer pass, fail;

    initial begin
        $display("===== tb_plwd: start =====");
        pass = 0; fail = 0;

        rst_n = 1'b1; // start high briefly
        m_axis_tvalid = 1'b0; m_axis_tdata = 16'sd0;
        s_axi_araddr = 4'h0; s_axi_arvalid = 1'b0;
        s_axi_awaddr = 4'h0; s_axi_awvalid = 1'b0;
        s_axi_wdata = 32'h0; s_axi_wvalid = 1'b0;

        @(posedge clk);
        rst_n = 1'b0;
        repeat(5) @(posedge clk);
        @(negedge clk); rst_n = 1'b1;
        @(posedge clk);

        // Feed valid outputs — no fault expected
        m_axis_tvalid = 1'b1; m_axis_tdata = 16'sh1000;
        repeat(10) @(posedge clk);
        // Change data
        m_axis_tdata = 16'sh2000;
        repeat(10) @(posedge clk);
        if (!pipeline_srst && !irq_fault) begin
            $display("PASS: no false fault with valid stream"); pass = pass + 1;
        end else begin
            $display("FAIL: spurious fault"); fail = fail + 1;
        end

        // Stop valid — stall should trigger after VALID_TIMEOUT=8 cycles
        m_axis_tvalid = 1'b0;
        repeat(20) @(posedge clk);
        if (pipeline_srst) begin
            $display("PASS: stall detected, pipeline_srst asserted"); pass = pass + 1;
        end else begin
            $display("FAIL: stall not detected"); fail = fail + 1;
        end

        // Wait for recovery to complete
        repeat(20) @(posedge clk);
        if (!pipeline_srst) begin
            $display("PASS: pipeline_srst deasserted after recovery"); pass = pass + 1;
        end else begin
            $display("FAIL: pipeline_srst stuck high"); fail = fail + 1;
        end

        // Read fault_type_reg via AXI-Lite
        @(negedge clk);
        s_axi_araddr = 4'h0; s_axi_arvalid = 1'b1;
        @(posedge clk);
        s_axi_arvalid = 1'b0;
        @(posedge clk);
        if (s_axi_rdata[1:0] == 2'b01) begin
            $display("PASS: fault_type_reg = %b (stall)", s_axi_rdata[1:0]); pass = pass + 1;
        end else begin
            $display("FAIL: expected fault_type=01 got %b", s_axi_rdata[1:0]); fail = fail + 1;
        end

        $display("===== tb_plwd: %0d pass, %0d fail =====", pass, fail);
        if (fail) $display("RESULT: FAIL");
        else      $display("RESULT: PASS");
        $finish;
    end

    initial begin #200_000; $display("TIMEOUT"); $finish; end
    initial begin $dumpfile("tb_plwd.vcd"); $dumpvars(0, tb_plwd); end
endmodule
