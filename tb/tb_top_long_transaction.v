`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// Full top-level long-transaction check using the behavioral memory model.
// The memory contents are intentionally unspecified; this test verifies that
// the deterministic MLP schedule completes before the qualified watchdog
// expires.
module tb_top_long_transaction;
    reg clk, rst_n, sample_enable;
    reg wload_en;
    reg [16:0] wload_addr;
    reg [15:0] wload_data;
    reg [31:0] s_axis_tdata;
    reg s_axis_tvalid;
    wire s_axis_tready;
    wire [15:0] m_axis_tdata;
    wire m_axis_tvalid;
    reg m_axis_tready;
    reg [7:0] s_axi_awaddr, s_axi_araddr;
    reg s_axi_awvalid, s_axi_wvalid, s_axi_arvalid;
    reg [31:0] s_axi_wdata;
    wire s_axi_awready, s_axi_wready;
    wire [1:0] s_axi_bresp, s_axi_rresp;
    wire s_axi_bvalid, s_axi_rvalid, s_axi_arready;
    reg s_axi_bready, s_axi_rready;
    wire [31:0] s_axi_rdata;
    wire clk_gate_en, irq_fault;
    integer failures;
    integer cycles;
    reg done;

    rls_dnn_top dut (.*);

    initial clk = 1'b0;
    always #5 clk = ~clk;

    initial begin
        failures = 0;
        cycles = 0;
        done = 1'b0;
        rst_n = 1'b0;
        sample_enable = 1'b0;
        wload_en = 1'b0; wload_addr = 0; wload_data = 0;
        s_axis_tdata = 32'h00010002; s_axis_tvalid = 1'b0;
        m_axis_tready = 1'b1;
        s_axi_awaddr = 0; s_axi_awvalid = 0;
        s_axi_wdata = 0; s_axi_wvalid = 0;
        s_axi_bready = 1'b1;
        s_axi_araddr = 0; s_axi_arvalid = 0;
        s_axi_rready = 1'b1;

        repeat (5) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;
        sample_enable = 1'b1;
        s_axis_tvalid = 1'b1;
        wait (s_axis_tready);
        @(posedge clk);
        @(negedge clk);
        s_axis_tvalid = 1'b0;
        sample_enable = 1'b0;

        for (cycles = 0; cycles < 20000 && !done; cycles = cycles + 1) begin
            @(posedge clk);
            #1;
            if (irq_fault) begin
                $display("FAIL watchdog fault during long transaction at cycle=%0d", cycles);
                failures = failures + 1;
                done = 1'b1;
            end
            if (m_axis_tvalid) begin
                $display("PASS long transaction completed at cycle=%0d", cycles);
                done = 1'b1;
            end
        end

        if (!m_axis_tvalid && !irq_fault && !done) begin
            $display("FAIL no output before watchdog budget expired");
            failures = failures + 1;
        end

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        if (failures != 0)
            $fatal(1, "long transaction test failed");
        $finish;
    end
endmodule
