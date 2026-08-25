// =============================================================================
// Module      : lat_prof
// Description : Hardware Pipeline Latency Profiler (E6)
//               Free-running 32-bit cycle counter; timestamp capture on each
//               pipeline stage valid signal. All timestamps + computed
//               intervals readable via AXI4-Lite slave. Cycle-accurate
//               end-to-end and stage-to-stage latency measurement.
// Author      : GLI / tapeitout.com
// Revision    : 1.1  — MHDA Enhancement E6
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module lat_prof (
    input  wire        clk,
    input  wire        rst_n,

    // Stage valid signals from pipeline
    input  wire        cbpf_y_valid,
    input  wire        rls_out_valid,
    input  wire        ptdl_out_valid,
    input  wire        mlp_out_valid,
    input  wire        m_axis_tvalid,

    // AXI4-Lite read slave (sub-address decoded externally)
    input  wire [7:0]  s_axi_araddr,
    input  wire        s_axi_arvalid,
    output reg  [31:0] s_axi_rdata,
    output reg         s_axi_rvalid
);

    // Free-running 32-bit cycle counter (wraps at 2^32)
    reg [31:0] free_cnt;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            free_cnt <= 32'd0;
        else
            free_cnt <= free_cnt + 1'b1;
    end

    // Timestamp capture registers
    reg [31:0] ts_cbpf;
    reg [31:0] ts_rls;
    reg [31:0] ts_ptdl;
    reg [31:0] ts_mlp;
    reg [31:0] ts_output;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ts_cbpf   <= 32'd0;
            ts_rls    <= 32'd0;
            ts_ptdl   <= 32'd0;
            ts_mlp    <= 32'd0;
            ts_output <= 32'd0;
        end else begin
            if (cbpf_y_valid)   ts_cbpf   <= free_cnt;
            if (rls_out_valid)  ts_rls    <= free_cnt;
            if (ptdl_out_valid) ts_ptdl   <= free_cnt;
            if (mlp_out_valid)  ts_mlp    <= free_cnt;
            if (m_axis_tvalid)  ts_output <= free_cnt;
        end
    end

    // Interval registers (computed combinationally, registered on read)
    reg [31:0] lat_cbpf_to_rls;
    reg [31:0] lat_rls_to_ptdl;
    reg [31:0] lat_ptdl_to_mlp;
    reg [31:0] lat_mlp_to_out;
    reg [31:0] lat_total;
    reg [31:0] free_cnt_snap;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            lat_cbpf_to_rls <= 32'd0;
            lat_rls_to_ptdl <= 32'd0;
            lat_ptdl_to_mlp <= 32'd0;
            lat_mlp_to_out  <= 32'd0;
            lat_total       <= 32'd0;
        end else begin
            if (mlp_out_valid) begin
                // Snapshot intervals on output valid
                lat_cbpf_to_rls <= ts_rls - ts_cbpf;
                lat_rls_to_ptdl <= ts_ptdl - ts_rls;
                lat_ptdl_to_mlp <= ts_mlp - ts_ptdl;
                lat_mlp_to_out  <= ts_output - ts_mlp;
                lat_total       <= ts_output - ts_cbpf;
            end
        end
    end

    // AXI4-Lite read decode (external address decode selects this module)
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_rdata  <= 32'd0;
            s_axi_rvalid <= 1'b0;
            free_cnt_snap <= 32'd0;
        end else begin
            if (s_axi_arvalid) begin
                s_axi_rvalid <= 1'b1;
                case (s_axi_araddr[5:2])
                    4'd0:  s_axi_rdata <= ts_cbpf;
                    4'd1:  s_axi_rdata <= ts_rls;
                    4'd2:  s_axi_rdata <= ts_ptdl;
                    4'd3:  s_axi_rdata <= ts_mlp;
                    4'd4:  s_axi_rdata <= ts_output;
                    4'd5:  s_axi_rdata <= lat_cbpf_to_rls;
                    4'd6:  s_axi_rdata <= lat_rls_to_ptdl;
                    4'd7:  s_axi_rdata <= lat_ptdl_to_mlp;
                    4'd8:  s_axi_rdata <= lat_mlp_to_out;
                    4'd9:  s_axi_rdata <= lat_total;
                    4'd10: begin
                        s_axi_rdata   <= free_cnt;
                        free_cnt_snap <= free_cnt;
                    end
                    default: s_axi_rdata <= 32'd0;
                endcase
            end else begin
                s_axi_rvalid <= 1'b0;
            end
        end
    end

endmodule
