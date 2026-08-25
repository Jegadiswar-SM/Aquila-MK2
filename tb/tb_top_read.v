`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

module tb_top_read;
    reg clk, rst_n, sample_enable;
    reg [31:0] s_axis_tdata;
    reg s_axis_tvalid;
    wire s_axis_tready;
    wire [15:0] m_axis_tdata;
    wire m_axis_tvalid;
    reg m_axis_tready;
    reg [7:0] s_axi_awaddr, s_axi_araddr;
    reg s_axi_awvalid, s_axi_wvalid, s_axi_arvalid;
    reg [31:0] s_axi_wdata;
    wire s_axi_awready, s_axi_wready, s_axi_arready;
    wire [1:0] s_axi_bresp, s_axi_rresp;
    wire s_axi_bvalid, s_axi_rvalid;
    reg s_axi_bready, s_axi_rready;
    wire [31:0] s_axi_rdata;
    reg wload_en;
    reg [16:0] wload_addr;
    reg [15:0] wload_data;
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
        rst_n = 1'b0; sample_enable = 1'b0;
        s_axis_tdata = 0; s_axis_tvalid = 0; m_axis_tready = 1'b1;
        s_axi_awaddr = 0; s_axi_awvalid = 0; s_axi_wdata = 0; s_axi_wvalid = 0;
        s_axi_bready = 1'b1; s_axi_araddr = 8'h60; s_axi_arvalid = 0;
        s_axi_rready = 1'b0;
        wload_en = 0; wload_addr = 0; wload_data = 0;

        repeat (5) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;
        force dut.u_plwd.fault_type_reg = 2'b10;
        @(negedge clk);
        s_axi_arvalid = 1'b1;
        wait (s_axi_arready);
        @(posedge clk);
        // Keep VALID asserted through the accepting edge.  Deasserting it
        // from the same posedge creates a TB/DUT scheduling race.
        @(negedge clk);
        s_axi_arvalid = 1'b0;

        wait (s_axi_rvalid);
        #1;
        if (s_axi_rdata[1:0] !== 2'b10) begin
            $display("FAIL read data=%h", s_axi_rdata);
            failures = failures + 1;
        end else begin
            $display("PASS child read data=%h", s_axi_rdata);
        end
        if (s_axi_rdata !== 32'h00000002) begin
            $display("FAIL full read word=%h", s_axi_rdata);
            failures = failures + 1;
        end
        // RDATA must remain stable while the response is stalled.
        repeat (2) begin
            @(posedge clk);
            #1;
            if (!s_axi_rvalid || s_axi_rdata !== 32'h00000002) begin
                $display("FAIL stalled read response valid=%b data=%h",
                         s_axi_rvalid, s_axi_rdata);
                failures = failures + 1;
            end
        end
        s_axi_rready = 1'b1;
        @(posedge clk);
        #1;

        // Issue a second read after the first response handshake.  This
        // checks that the top-level pending state does not retain stale data.
        s_axi_araddr = 8'h68;
        @(negedge clk);
        s_axi_arvalid = 1'b1;
        wait (s_axi_arready);
        @(posedge clk);
        @(negedge clk);
        s_axi_arvalid = 1'b0;
        wait (s_axi_rvalid);
        #1;
        if (s_axi_rdata !== 32'h00000000) begin
            $display("FAIL back-to-back read data=%h", s_axi_rdata);
            failures = failures + 1;
        end
        s_axi_rready = 1'b1;
        @(posedge clk);
        #1;
        release dut.u_plwd.fault_type_reg;

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end
endmodule
