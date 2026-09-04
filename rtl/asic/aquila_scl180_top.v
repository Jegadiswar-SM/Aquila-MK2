// Technology-neutral ASIC binding boundary.
// Replace only aquila_scl180_io_bind's implementation with approved SCL180
// pad cells at C2S. No foundry cell, voltage, or electrical assumption is
// encoded here. The functional core is rls_dnn_top and is unchanged.
`timescale 1ns/1ps

module aquila_scl180_top (
    input wire clk, input wire rst_n, input wire sample_enable,
    input wire wload_en, input wire [16:0] wload_addr, input wire [15:0] wload_data,
    input wire [31:0] s_axis_tdata, input wire s_axis_tvalid, output wire s_axis_tready,
    output wire [15:0] m_axis_tdata, output wire m_axis_tvalid, input wire m_axis_tready,
    input wire [7:0] s_axi_awaddr, input wire s_axi_awvalid, output wire s_axi_awready,
    input wire [31:0] s_axi_wdata, input wire s_axi_wvalid, output wire s_axi_wready,
    output wire [1:0] s_axi_bresp, output wire s_axi_bvalid, input wire s_axi_bready,
    input wire [7:0] s_axi_araddr, input wire s_axi_arvalid, output wire s_axi_arready,
    output wire [31:0] s_axi_rdata, output wire [1:0] s_axi_rresp, output wire s_axi_rvalid,
    input wire s_axi_rready, output wire clk_gate_en, output wire irq_fault,
    inout wire vccd, inout wire vssd, inout wire vddio, inout wire vssio
);
    wire c_clk, c_rst_n, c_sample_enable, c_wload_en;
    wire [16:0] c_wload_addr; wire [15:0] c_wload_data;
    wire [31:0] c_s_axis_tdata; wire c_s_axis_tvalid, c_s_axis_tready;
    wire [15:0] c_m_axis_tdata; wire c_m_axis_tvalid, c_m_axis_tready;
    wire [7:0] c_awaddr, c_araddr; wire c_awvalid, c_awready;
    wire [31:0] c_wdata, c_rdata; wire c_wvalid, c_wready;
    wire [1:0] c_bresp, c_rresp; wire c_bvalid, c_bready;
    wire c_arvalid, c_arready, c_rvalid, c_rready, c_clk_gate_en, c_irq_fault;

    aquila_scl180_io_bind u_io (
        .pad_clk(clk), .pad_rst_n(rst_n), .pad_sample_enable(sample_enable),
        .pad_wload_en(wload_en), .pad_wload_addr(wload_addr), .pad_wload_data(wload_data),
        .pad_s_axis_tdata(s_axis_tdata), .pad_s_axis_tvalid(s_axis_tvalid), .pad_s_axis_tready(s_axis_tready),
        .pad_m_axis_tdata(m_axis_tdata), .pad_m_axis_tvalid(m_axis_tvalid), .pad_m_axis_tready(m_axis_tready),
        .pad_s_axi_awaddr(s_axi_awaddr), .pad_s_axi_awvalid(s_axi_awvalid), .pad_s_axi_awready(s_axi_awready),
        .pad_s_axi_wdata(s_axi_wdata), .pad_s_axi_wvalid(s_axi_wvalid), .pad_s_axi_wready(s_axi_wready),
        .pad_s_axi_bresp(s_axi_bresp), .pad_s_axi_bvalid(s_axi_bvalid), .pad_s_axi_bready(s_axi_bready),
        .pad_s_axi_araddr(s_axi_araddr), .pad_s_axi_arvalid(s_axi_arvalid), .pad_s_axi_arready(s_axi_arready),
        .pad_s_axi_rdata(s_axi_rdata), .pad_s_axi_rresp(s_axi_rresp), .pad_s_axi_rvalid(s_axi_rvalid),
        .pad_s_axi_rready(s_axi_rready), .pad_clk_gate_en(clk_gate_en), .pad_irq_fault(irq_fault),
        .vccd(vccd), .vssd(vssd), .vddio(vddio), .vssio(vssio),
        .core_clk(c_clk), .core_rst_n(c_rst_n), .core_sample_enable(c_sample_enable),
        .core_wload_en(c_wload_en), .core_wload_addr(c_wload_addr), .core_wload_data(c_wload_data),
        .core_s_axis_tdata(c_s_axis_tdata), .core_s_axis_tvalid(c_s_axis_tvalid), .core_s_axis_tready(c_s_axis_tready),
        .core_m_axis_tdata(c_m_axis_tdata), .core_m_axis_tvalid(c_m_axis_tvalid), .core_m_axis_tready(c_m_axis_tready),
        .core_s_axi_awaddr(c_awaddr), .core_s_axi_awvalid(c_awvalid), .core_s_axi_awready(c_awready),
        .core_s_axi_wdata(c_wdata), .core_s_axi_wvalid(c_wvalid), .core_s_axi_wready(c_wready),
        .core_s_axi_bresp(c_bresp), .core_s_axi_bvalid(c_bvalid), .core_s_axi_bready(c_bready),
        .core_s_axi_araddr(c_araddr), .core_s_axi_arvalid(c_arvalid), .core_s_axi_arready(c_arready),
        .core_s_axi_rdata(c_rdata), .core_s_axi_rresp(c_rresp), .core_s_axi_rvalid(c_rvalid),
        .core_s_axi_rready(c_rready), .core_clk_gate_en(c_clk_gate_en), .core_irq_fault(c_irq_fault)
    );

    rls_dnn_top u_core (
        .clk(c_clk), .rst_n(c_rst_n), .sample_enable(c_sample_enable),
        .wload_en(c_wload_en), .wload_addr(c_wload_addr), .wload_data(c_wload_data),
        .s_axis_tdata(c_s_axis_tdata), .s_axis_tvalid(c_s_axis_tvalid), .s_axis_tready(c_s_axis_tready),
        .m_axis_tdata(c_m_axis_tdata), .m_axis_tvalid(c_m_axis_tvalid), .m_axis_tready(c_m_axis_tready),
        .s_axi_awaddr(c_awaddr), .s_axi_awvalid(c_awvalid), .s_axi_awready(c_awready),
        .s_axi_wdata(c_wdata), .s_axi_wvalid(c_wvalid), .s_axi_wready(c_wready),
        .s_axi_bresp(c_bresp), .s_axi_bvalid(c_bvalid), .s_axi_bready(c_bready),
        .s_axi_araddr(c_araddr), .s_axi_arvalid(c_arvalid), .s_axi_arready(c_arready),
        .s_axi_rdata(c_rdata), .s_axi_rresp(c_rresp), .s_axi_rvalid(c_rvalid), .s_axi_rready(c_rready),
        .clk_gate_en(c_clk_gate_en), .irq_fault(c_irq_fault)
    );
endmodule

module aquila_scl180_io_bind (
    input wire pad_clk, pad_rst_n, pad_sample_enable, pad_wload_en,
    input wire [16:0] pad_wload_addr, input wire [15:0] pad_wload_data,
    input wire [31:0] pad_s_axis_tdata, input wire pad_s_axis_tvalid, output wire pad_s_axis_tready,
    output wire [15:0] pad_m_axis_tdata, output wire pad_m_axis_tvalid, input wire pad_m_axis_tready,
    input wire [7:0] pad_s_axi_awaddr, input wire pad_s_axi_awvalid, output wire pad_s_axi_awready,
    input wire [31:0] pad_s_axi_wdata, input wire pad_s_axi_wvalid, output wire pad_s_axi_wready,
    output wire [1:0] pad_s_axi_bresp, output wire pad_s_axi_bvalid, input wire pad_s_axi_bready,
    input wire [7:0] pad_s_axi_araddr, input wire pad_s_axi_arvalid, output wire pad_s_axi_arready,
    output wire [31:0] pad_s_axi_rdata, output wire [1:0] pad_s_axi_rresp, output wire pad_s_axi_rvalid,
    input wire pad_s_axi_rready, output wire pad_clk_gate_en, output wire pad_irq_fault,
    inout wire vccd, vssd, vddio, vssio,
    output wire core_clk, core_rst_n, core_sample_enable, core_wload_en,
    output wire [16:0] core_wload_addr, output wire [15:0] core_wload_data,
    output wire [31:0] core_s_axis_tdata, output wire core_s_axis_tvalid, input wire core_s_axis_tready,
    input wire [15:0] core_m_axis_tdata, input wire core_m_axis_tvalid, output wire core_m_axis_tready,
    output wire [7:0] core_s_axi_awaddr, output wire core_s_axi_awvalid, input wire core_s_axi_awready,
    output wire [31:0] core_s_axi_wdata, output wire core_s_axi_wvalid, input wire core_s_axi_wready,
    input wire [1:0] core_s_axi_bresp, input wire core_s_axi_bvalid, output wire core_s_axi_bready,
    output wire [7:0] core_s_axi_araddr, output wire core_s_axi_arvalid, input wire core_s_axi_arready,
    input wire [31:0] core_s_axi_rdata, input wire [1:0] core_s_axi_rresp, input wire core_s_axi_rvalid,
    output wire core_s_axi_rready, input wire core_clk_gate_en, input wire core_irq_fault
);
    assign core_clk=pad_clk; assign core_rst_n=pad_rst_n; assign core_sample_enable=pad_sample_enable;
    assign core_wload_en=pad_wload_en; assign core_wload_addr=pad_wload_addr; assign core_wload_data=pad_wload_data;
    assign core_s_axis_tdata=pad_s_axis_tdata; assign core_s_axis_tvalid=pad_s_axis_tvalid; assign pad_s_axis_tready=core_s_axis_tready;
    assign pad_m_axis_tdata=core_m_axis_tdata; assign pad_m_axis_tvalid=core_m_axis_tvalid; assign core_m_axis_tready=pad_m_axis_tready;
    assign core_s_axi_awaddr=pad_s_axi_awaddr; assign core_s_axi_awvalid=pad_s_axi_awvalid; assign pad_s_axi_awready=core_s_axi_awready;
    assign core_s_axi_wdata=pad_s_axi_wdata; assign core_s_axi_wvalid=pad_s_axi_wvalid; assign pad_s_axi_wready=core_s_axi_wready;
    assign pad_s_axi_bresp=core_s_axi_bresp; assign pad_s_axi_bvalid=core_s_axi_bvalid; assign core_s_axi_bready=pad_s_axi_bready;
    assign core_s_axi_araddr=pad_s_axi_araddr; assign core_s_axi_arvalid=pad_s_axi_arvalid; assign pad_s_axi_arready=core_s_axi_arready;
    assign pad_s_axi_rdata=core_s_axi_rdata; assign pad_s_axi_rresp=core_s_axi_rresp; assign pad_s_axi_rvalid=core_s_axi_rvalid; assign core_s_axi_rready=pad_s_axi_rready;
    assign pad_clk_gate_en=core_clk_gate_en; assign pad_irq_fault=core_irq_fault;
endmodule
