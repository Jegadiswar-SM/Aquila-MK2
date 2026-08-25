`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// Verifies that the MLP receives the PTDL vector produced by the current RLS
// event and that the residual held for the long MLP transaction is the same
// event's residual.
module tb_top_alignment;
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
        s_axis_tdata = 0; s_axis_tvalid = 0; m_axis_tready = 1'b1;
        s_axi_awaddr = 0; s_axi_awvalid = 0; s_axi_wdata = 0; s_axi_wvalid = 0;
        s_axi_bready = 1'b1; s_axi_araddr = 0; s_axi_arvalid = 0;
        s_axi_rready = 1'b1;
        wload_en = 1'b0; wload_addr = 0; wload_data = 0;

        repeat (5) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;
        wait (dut.rst_n_sync);

        // A single current residual enters PTDL.  The MLP must not capture
        // the pre-shift all-zero tap vector on this same edge.
        force dut.rls_valid_out = 1'b1;
        force dut.rls_error = 16'sh0123;
        @(posedge clk);
        @(negedge clk);
        release dut.rls_valid_out;
        release dut.rls_error;

        if (dut.ptdl_taps[127:112] !== 16'h0123) begin
            $display("FAIL PTDL current tap=%h", dut.ptdl_taps[127:112]);
            failures = failures + 1;
        end

        @(posedge clk);
        #1;
        if (dut.u_mlp.feat_reg[0] !== 16'h0123) begin
            $display("FAIL MLP captured stale feature=%h", dut.u_mlp.feat_reg[0]);
            failures = failures + 1;
        end
        if (dut.mlp_error_hold !== 16'sh0123) begin
            $display("FAIL held residual=%h", dut.mlp_error_hold);
            failures = failures + 1;
        end

        // Exercise output subtraction independently of the long MLP run.
        force dut.mlp_valid_out = 1'b1;
        force dut.mlp_noise_est = 16'sh0100; // scaled by 16 -> 0x0010
        @(posedge clk);
        #1;
        if (!m_axis_tvalid || m_axis_tdata !== 16'h0113) begin
            $display("FAIL aligned output valid=%b data=%h", m_axis_tvalid, m_axis_tdata);
            failures = failures + 1;
        end
        release dut.mlp_valid_out;
        release dut.mlp_noise_est;

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        $finish;
    end
endmodule
