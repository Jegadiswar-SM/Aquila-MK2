`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// Checks the top-level transaction contract without depending on trained
// weights or waiting for the full MLP schedule.
module tb_top_admission;
    reg clk;
    reg rst_n;
    reg sample_enable;
    reg [31:0] s_axis_tdata;
    reg s_axis_tvalid;
    wire s_axis_tready;
    wire [15:0] m_axis_tdata;
    wire m_axis_tvalid;
    reg m_axis_tready;
    reg [7:0] s_axi_awaddr;
    reg s_axi_awvalid;
    wire s_axi_awready;
    reg [31:0] s_axi_wdata;
    reg s_axi_wvalid;
    wire s_axi_wready;
    wire [1:0] s_axi_bresp;
    wire s_axi_bvalid;
    reg s_axi_bready;
    reg [7:0] s_axi_araddr;
    reg s_axi_arvalid;
    wire s_axi_arready;
    wire [31:0] s_axi_rdata;
    wire [1:0] s_axi_rresp;
    wire s_axi_rvalid;
    reg s_axi_rready;
    reg wload_en;
    reg [16:0] wload_addr;
    reg [15:0] wload_data;
    wire clk_gate_en;
    wire irq_fault;
    integer handshakes;
    integer failures;
    integer cycle;

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

    always @(posedge clk) begin
        if (s_axis_tvalid && s_axis_tready)
            handshakes = handshakes + 1;
        cycle = cycle + 1;
    end

    initial begin
        handshakes = 0;
        failures = 0;
        cycle = 0;
        rst_n = 1'b0;
        sample_enable = 1'b0;
        s_axis_tdata = 32'h12345678;
        s_axis_tvalid = 1'b0;
        m_axis_tready = 1'b1;
        s_axi_awaddr = 0; s_axi_awvalid = 0; s_axi_wdata = 0; s_axi_wvalid = 0;
        s_axi_bready = 1'b1; s_axi_araddr = 0; s_axi_arvalid = 0;
        s_axi_rready = 1'b1;
        wload_en = 1'b0; wload_addr = 0; wload_data = 0;

        repeat (5) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;
        sample_enable = 1'b1;
        s_axis_tvalid = 1'b1;

        wait (s_axis_tready);
        @(posedge clk);
        #1;
        if (handshakes !== 1) begin
            $display("FAIL first transfer count=%0d", handshakes);
            failures = failures + 1;
        end
        if (s_axis_tready !== 1'b0) begin
            $display("FAIL input remained ready while transaction active");
            failures = failures + 1;
        end

        repeat (20) begin
            @(posedge clk);
            #1;
            if (handshakes !== 1) begin
                $display("FAIL second transfer accepted at cycle=%0d", cycle);
                failures = failures + 1;
            end
        end

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end
endmodule
