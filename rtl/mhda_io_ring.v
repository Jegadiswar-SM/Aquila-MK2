// =============================================================================
// Module      : mhda_io_ring
// Description : Pad ring for the MHDA ASIC using sky130 fd_io cells.
//               This module wraps the core rls_dnn_top module and routes
//               all I/Os through physical sky130 pad cells.
//
//               Sky130 Pad Cells used:
//                 - Input pads: sky130_fd_io__gpiobuf_1to16 (configured for input)
//                 - Output pads: sky130_fd_io__gpiobuf_1to16 (configured for output)
//                 - Analog/Power pads: sky130_fd_io__vccd_h, sky130_fd_io__vssd_h,
//                   sky130_fd_io__vcca_h, sky130_fd_io__vssa_h.
//
// Author      : MHDA RTL Hardening (ASIC prep)
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module mhda_io_ring (
    // External Chip Pins (Pads)
    input  wire        pad_clk,
    input  wire        pad_rst_n,
    input  wire        pad_sample_enable,

    // Weight Programming Interface Pins
    input  wire        pad_wload_en,
    input  wire [16:0] pad_wload_addr,
    input  wire [15:0] pad_wload_data,

    // AXI4-Stream Slave (Input)
    input  wire [31:0] pad_s_axis_tdata,
    input  wire        pad_s_axis_tvalid,
    output wire        pad_s_axis_tready,

    // AXI4-Stream Master (Output)
    output wire [15:0] pad_m_axis_tdata,
    output wire        pad_m_axis_tvalid,
    input  wire        pad_m_axis_tready,

    // AXI4-Lite Slave (Config)
    input  wire [7:0]  pad_s_axi_awaddr,
    input  wire        pad_s_axi_awvalid,
    output wire        pad_s_axi_awready,
    input  wire [31:0] pad_s_axi_wdata,
    input  wire        pad_s_axi_wvalid,
    output wire        pad_s_axi_wready,
    output wire [1:0]  pad_s_axi_bresp,
    output wire        pad_s_axi_bvalid,
    input  wire        pad_s_axi_bready,
    input  wire [7:0]  pad_s_axi_araddr,
    input  wire        pad_s_axi_arvalid,
    output wire        pad_s_axi_arready,
    output wire [31:0] pad_s_axi_rdata,
    output wire [1:0]  pad_s_axi_rresp,
    output wire        pad_s_axi_rvalid,
    input  wire        pad_s_axi_rready,

    output wire        pad_clk_gate_en,
    output wire        pad_irq_fault,

    // Power Supplies
    inout  wire        vccd,    // 1.8V digital core power
    inout  wire        vssd,    // Digital ground
    inout  wire        vddio,   // 3.3V IO power
    inout  wire        vssio    // IO ground
);

    // =========================================================================
    // Core Wires
    // =========================================================================
    wire        core_clk;
    wire        core_rst_n;
    wire        core_sample_enable;
    wire        core_wload_en;
    wire [16:0] core_wload_addr;
    wire [15:0] core_wload_data;
    wire [31:0] core_s_axis_tdata;
    wire        core_s_axis_tvalid;
    wire        core_s_axis_tready;
    wire [15:0] core_m_axis_tdata;
    wire        core_m_axis_tvalid;
    wire        core_m_axis_tready;
    wire [7:0]  core_s_axi_awaddr;
    wire        core_s_axi_awvalid;
    wire        core_s_axi_awready;
    wire [31:0] core_s_axi_wdata;
    wire        core_s_axi_wvalid;
    wire        core_s_axi_wready;
    wire [1:0]  core_s_axi_bresp;
    wire        core_s_axi_bvalid;
    wire        core_s_axi_bready;
    wire [7:0]  core_s_axi_araddr;
    wire        core_s_axi_arvalid;
    wire        core_s_axi_arready;
    wire [31:0] core_s_axi_rdata;
    wire [1:0]  core_s_axi_rresp;
    wire        core_s_axi_rvalid;
    wire        core_s_axi_rready;
    wire        core_clk_gate_en;
    wire        core_irq_fault;

    // =========================================================================
    // Core Instance
    // =========================================================================
    rls_dnn_top u_core (
        .clk             (core_clk),
        .rst_n           (core_rst_n),
        .sample_enable   (core_sample_enable),
        .wload_en        (core_wload_en),
        .wload_addr      (core_wload_addr),
        .wload_data      (core_wload_data),
        .s_axis_tdata    (core_s_axis_tdata),
        .s_axis_tvalid   (core_s_axis_tvalid),
        .s_axis_tready   (core_s_axis_tready),
        .m_axis_tdata    (core_m_axis_tdata),
        .m_axis_tvalid   (core_m_axis_tvalid),
        .m_axis_tready   (core_m_axis_tready),
        .s_axi_awaddr    (core_s_axi_awaddr),
        .s_axi_awvalid   (core_s_axi_awvalid),
        .s_axi_awready   (core_s_axi_awready),
        .s_axi_wdata     (core_s_axi_wdata),
        .s_axi_wvalid    (core_s_axi_wvalid),
        .s_axi_wready    (core_s_axi_wready),
        .s_axi_bresp     (core_s_axi_bresp),
        .s_axi_bvalid    (core_s_axi_bvalid),
        .s_axi_bready    (core_s_axi_bready),
        .s_axi_araddr    (core_s_axi_araddr),
        .s_axi_arvalid   (core_s_axi_arvalid),
        .s_axi_arready   (core_s_axi_arready),
        .s_axi_rdata     (core_s_axi_rdata),
        .s_axi_rresp     (core_s_axi_rresp),
        .s_axi_rvalid    (core_s_axi_rvalid),
        .s_axi_rready    (core_s_axi_rready),
        .clk_gate_en     (core_clk_gate_en),
        .irq_fault       (core_irq_fault)
    );

    // =========================================================================
    // sky130 fd_io Pad Instantiations
    //
    // Each pad instance routes one external pad (e.g. pad_clk) to the core (core_clk).
    // The control signals configures the bidirectional buffers:
    //   - oe_n = 1'b1 (Output Enable Active Low -> Input mode)
    //   - oe_n = 1'b0 (Output Enable Active Low -> Output mode)
    // =========================================================================

    // Clock & Reset (Inputs)
    sky130_fd_io__gpiobuf_1to16 u_pad_clk (
        .PAD(pad_clk), .OUT(core_clk), .IN(1'b0), .OE_N(1'b1)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_rst_n (
        .PAD(pad_rst_n), .OUT(core_rst_n), .IN(1'b0), .OE_N(1'b1)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_sample_enable (
        .PAD(pad_sample_enable), .OUT(core_sample_enable), .IN(1'b0), .OE_N(1'b1)
    );

    // Weight Load (Inputs)
    sky130_fd_io__gpiobuf_1to16 u_pad_wload_en (
        .PAD(pad_wload_en), .OUT(core_wload_en), .IN(1'b0), .OE_N(1'b1)
    );
    
    genvar i_wa;
    generate
        for (i_wa = 0; i_wa < 17; i_wa = i_wa + 1) begin : PAD_WLOAD_ADDR
            sky130_fd_io__gpiobuf_1to16 u_pad_wa (
                .PAD(pad_wload_addr[i_wa]), .OUT(core_wload_addr[i_wa]), .IN(1'b0), .OE_N(1'b1)
            );
        end
    endgenerate

    genvar i_wd;
    generate
        for (i_wd = 0; i_wd < 16; i_wd = i_wd + 1) begin : PAD_WLOAD_DATA
            sky130_fd_io__gpiobuf_1to16 u_pad_wd (
                .PAD(pad_wload_data[i_wd]), .OUT(core_wload_data[i_wd]), .IN(1'b0), .OE_N(1'b1)
            );
        end
    endgenerate

    // AXI-Stream In (Inputs & Outputs)
    genvar i_axin;
    generate
        for (i_axin = 0; i_axin < 32; i_axin = i_axin + 1) begin : PAD_S_AXIS_TDATA
            sky130_fd_io__gpiobuf_1to16 u_pad_saxistdata (
                .PAD(pad_s_axis_tdata[i_axin]), .OUT(core_s_axis_tdata[i_axin]), .IN(1'b0), .OE_N(1'b1)
            );
        end
    endgenerate

    sky130_fd_io__gpiobuf_1to16 u_pad_saxisvalid (
        .PAD(pad_s_axis_tvalid), .OUT(core_s_axis_tvalid), .IN(1'b0), .OE_N(1'b1)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_saxisready (
        .PAD(pad_s_axis_tready), .OUT(), .IN(core_s_axis_tready), .OE_N(1'b0)
    );

    // AXI-Stream Out (Inputs & Outputs)
    genvar i_axout;
    generate
        for (i_axout = 0; i_axout < 16; i_axout = i_axout + 1) begin : PAD_M_AXIS_TDATA
            sky130_fd_io__gpiobuf_1to16 u_pad_maxistdata (
                .PAD(pad_m_axis_tdata[i_axout]), .OUT(), .IN(core_m_axis_tdata[i_axout]), .OE_N(1'b0)
            );
        end
    endgenerate

    sky130_fd_io__gpiobuf_1to16 u_pad_maxisvalid (
        .PAD(pad_m_axis_tvalid), .OUT(), .IN(core_m_axis_tvalid), .OE_N(1'b0)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_maxisready (
        .PAD(pad_m_axis_tready), .OUT(core_m_axis_tready), .IN(1'b0), .OE_N(1'b1)
    );

    // AXI4-Lite Address/Data/Control
    genvar i_aw;
    generate
        for (i_aw = 0; i_aw < 8; i_aw = i_aw + 1) begin : PAD_S_AXI_AWADDR
            sky130_fd_io__gpiobuf_1to16 u_pad_sawaddr (
                .PAD(pad_s_axi_awaddr[i_aw]), .OUT(core_s_axi_awaddr[i_aw]), .IN(1'b0), .OE_N(1'b1)
            );
        end
    endgenerate

    sky130_fd_io__gpiobuf_1to16 u_pad_sawvalid (
        .PAD(pad_s_axi_awvalid), .OUT(core_s_axi_awvalid), .IN(1'b0), .OE_N(1'b1)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_sawready (
        .PAD(pad_s_axi_awready), .OUT(), .IN(core_s_axi_awready), .OE_N(1'b0)
    );

    genvar i_wd_lite;
    generate
        for (i_wd_lite = 0; i_wd_lite < 32; i_wd_lite = i_wd_lite + 1) begin : PAD_S_AXI_WDATA
            sky130_fd_io__gpiobuf_1to16 u_pad_saxiwdata (
                .PAD(pad_s_axi_wdata[i_wd_lite]), .OUT(core_s_axi_wdata[i_wd_lite]), .IN(1'b0), .OE_N(1'b1)
            );
        end
    endgenerate

    sky130_fd_io__gpiobuf_1to16 u_pad_sawwvalid (
        .PAD(pad_s_axi_wvalid), .OUT(core_s_axi_wvalid), .IN(1'b0), .OE_N(1'b1)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_sawwready (
        .PAD(pad_s_axi_wready), .OUT(), .IN(core_s_axi_wready), .OE_N(1'b0)
    );

    sky130_fd_io__gpiobuf_1to16 u_pad_saxibresp0 (
        .PAD(pad_s_axi_bresp[0]), .OUT(), .IN(core_s_axi_bresp[0]), .OE_N(1'b0)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_saxibresp1 (
        .PAD(pad_s_axi_bresp[1]), .OUT(), .IN(core_s_axi_bresp[1]), .OE_N(1'b0)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_saxibvalid (
        .PAD(pad_s_axi_bvalid), .OUT(), .IN(core_s_axi_bvalid), .OE_N(1'b0)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_saxibready (
        .PAD(pad_s_axi_bready), .OUT(core_s_axi_bready), .IN(1'b0), .OE_N(1'b1)
    );

    genvar i_ar;
    generate
        for (i_ar = 0; i_ar < 8; i_ar = i_ar + 1) begin : PAD_S_AXI_ARADDR
            sky130_fd_io__gpiobuf_1to16 u_pad_saxiaraddr (
                .PAD(pad_s_axi_araddr[i_ar]), .OUT(core_s_axi_araddr[i_ar]), .IN(1'b0), .OE_N(1'b1)
            );
        end
    endgenerate

    sky130_fd_io__gpiobuf_1to16 u_pad_saxiarvalid (
        .PAD(pad_s_axi_arvalid), .OUT(core_s_axi_arvalid), .IN(1'b0), .OE_N(1'b1)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_saxiarready (
        .PAD(pad_s_axi_arready), .OUT(), .IN(core_s_axi_arready), .OE_N(1'b0)
    );

    genvar i_rd_lite;
    generate
        for (i_rd_lite = 0; i_rd_lite < 32; i_rd_lite = i_rd_lite + 1) begin : PAD_S_AXI_RDATA
            sky130_fd_io__gpiobuf_1to16 u_pad_saxirdata (
                .PAD(pad_s_axi_rdata[i_rd_lite]), .OUT(), .IN(core_s_axi_rdata[i_rd_lite]), .OE_N(1'b0)
            );
        end
    endgenerate

    sky130_fd_io__gpiobuf_1to16 u_pad_saxirresp0 (
        .PAD(pad_s_axi_rresp[0]), .OUT(), .IN(core_s_axi_rresp[0]), .OE_N(1'b0)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_saxirresp1 (
        .PAD(pad_s_axi_rresp[1]), .OUT(), .IN(core_s_axi_rresp[1]), .OE_N(1'b0)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_saxirvalid (
        .PAD(pad_s_axi_rvalid), .OUT(), .IN(core_s_axi_rvalid), .OE_N(1'b0)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_saxirready (
        .PAD(pad_s_axi_rready), .OUT(core_s_axi_rready), .IN(1'b0), .OE_N(1'b1)
    );

    // Gating & Fault Outputs
    sky130_fd_io__gpiobuf_1to16 u_pad_clk_gate_en (
        .PAD(pad_clk_gate_en), .OUT(), .IN(core_clk_gate_en), .OE_N(1'b0)
    );
    sky130_fd_io__gpiobuf_1to16 u_pad_irq_fault (
        .PAD(pad_irq_fault), .OUT(), .IN(core_irq_fault), .OE_N(1'b0)
    );

endmodule

// =============================================================================
// Mock sky130 fd_io buffer model (For simulation/linting without cell library)
// =============================================================================
`ifdef SIMULATION
module sky130_fd_io__gpiobuf_1to16 (
    inout  wire PAD,
    output wire OUT,
    input  wire IN,
    input  wire OE_N
);
    assign PAD = (!OE_N) ? IN : 1'bz;
    assign OUT = PAD;
endmodule
`endif
