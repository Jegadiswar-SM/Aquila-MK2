`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// Directed AXI-Stream output-stability check.  The internal MLP pulse is
// forced only to exercise the top-level output register; no trained weights
// are required for this protocol test.
module tb_top_output_hold;
    reg clk, rst_n, sample_enable;
    reg [31:0] s_axis_tdata;
    reg s_axis_tvalid, m_axis_tready;
    reg [7:0] s_axi_awaddr, s_axi_araddr;
    reg s_axi_awvalid, s_axi_wvalid, s_axi_arvalid;
    reg [31:0] s_axi_wdata;
    reg s_axi_bready, s_axi_rready;
    reg wload_en;
    reg [16:0] wload_addr;
    reg [15:0] wload_data;
    wire s_axis_tready, m_axis_tvalid;
    wire [15:0] m_axis_tdata;
    wire s_axi_awready, s_axi_wready, s_axi_bvalid;
    wire [1:0] s_axi_bresp, s_axi_rresp;
    wire s_axi_arready, s_axi_rvalid;
    wire [31:0] s_axi_rdata;
    wire clk_gate_en, irq_fault;
    integer failures;

    rls_dnn_top dut (
        .clk(clk), .rst_n(rst_n), .sample_enable(sample_enable),
        .wload_en(wload_en), .wload_addr(wload_addr), .wload_data(wload_data),
        .s_axis_tdata(s_axis_tdata), .s_axis_tvalid(s_axis_tvalid),
        .s_axis_tready(s_axis_tready), .m_axis_tdata(m_axis_tdata),
        .m_axis_tvalid(m_axis_tvalid), .m_axis_tready(m_axis_tready),
        .s_axi_awaddr(s_axi_awaddr), .s_axi_awvalid(s_axi_awvalid),
        .s_axi_awready(s_axi_awready), .s_axi_wdata(s_axi_wdata),
        .s_axi_wvalid(s_axi_wvalid), .s_axi_wready(s_axi_wready),
        .s_axi_bresp(s_axi_bresp), .s_axi_bvalid(s_axi_bvalid),
        .s_axi_bready(s_axi_bready), .s_axi_araddr(s_axi_araddr),
        .s_axi_arvalid(s_axi_arvalid), .s_axi_arready(s_axi_arready),
        .s_axi_rdata(s_axi_rdata), .s_axi_rresp(s_axi_rresp),
        .s_axi_rvalid(s_axi_rvalid), .s_axi_rready(s_axi_rready),
        .clk_gate_en(clk_gate_en), .irq_fault(irq_fault)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    initial begin
        failures = 0;
        rst_n = 1'b0;
        sample_enable = 1'b0;
        s_axis_tdata = 32'd0;
        s_axis_tvalid = 1'b0;
        m_axis_tready = 1'b0;
        s_axi_awaddr = 0; s_axi_awvalid = 0;
        s_axi_wdata = 0; s_axi_wvalid = 0;
        s_axi_bready = 1'b1;
        s_axi_araddr = 0; s_axi_arvalid = 0;
        s_axi_rready = 1'b1;
        wload_en = 1'b0; wload_addr = 0; wload_data = 0;

        repeat (5) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;
        wait (dut.rst_n_sync);

        force dut.mlp_valid_out = 1'b1;
        force dut.sub_sat = 16'sh1234;
        @(posedge clk);
        #1;
        if (!m_axis_tvalid || m_axis_tdata !== 16'h1234) begin
            $display("FAIL initial output valid=%b data=%h", m_axis_tvalid, m_axis_tdata);
            failures = failures + 1;
        end

        force dut.sub_sat = 16'sh5678;
        repeat (3) begin
            @(posedge clk);
            #1;
            if (!m_axis_tvalid || m_axis_tdata !== 16'h1234) begin
                $display("FAIL stalled output changed valid=%b data=%h", m_axis_tvalid, m_axis_tdata);
                failures = failures + 1;
            end
        end

        release dut.mlp_valid_out;
        release dut.sub_sat;
        m_axis_tready = 1'b1;
        @(posedge clk);
        #1;
        if (m_axis_tvalid !== 1'b0) begin
            $display("FAIL output did not clear after handshake");
            failures = failures + 1;
        end

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end
endmodule
