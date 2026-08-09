// =============================================================================
// Module      : plwd
// Description : Pipeline Integrity Watchdog with Auto-Recovery FSM
//               Monitors the output AXI4-Stream for stall (no tvalid) and
//               stuck (consecutive identical tdata) faults. Issues a soft
//               pipeline reset (excluding weight registers) and interrupt.
//
// CRITICAL: pipeline_srst MUST NOT reset adaptive weight/coefficient
// registers. In the top-level, pipeline_srst is ANDed with rst_n for
// datapath flops only; weight register resets use only rst_n.
// Author      : GLI / tapeitout.com
// Revision    : 1.0
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module plwd #(
    parameter VALID_TIMEOUT   = 512,
    parameter STUCK_THRESHOLD = 16
)(
    input  wire        clk,
    input  wire        rst_n,

    input  wire        m_axis_tvalid,
    input  wire [15:0] m_axis_tdata,

    // AXI4-Lite read interface
    input  wire [3:0]  s_axi_araddr,
    input  wire        s_axi_arvalid,
    output reg  [31:0] s_axi_rdata,
    output reg         s_axi_rvalid,

    // AXI4-Lite write interface
    input  wire [3:0]  s_axi_awaddr,
    input  wire        s_axi_awvalid,
    input  wire [31:0] s_axi_wdata,
    input  wire        s_axi_wvalid,
    output reg         s_axi_awready,
    output reg         s_axi_wready,

    // Outputs
    output reg         pipeline_srst,
    output reg         irq_fault
);

    // -------------------------------------------------------------------------
    // Monitor 1 — Stall detector
    // -------------------------------------------------------------------------
    reg [15:0] timeout_cnt;
    reg        pipeline_stall_fault;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            timeout_cnt           <= VALID_TIMEOUT;
            pipeline_stall_fault  <= 1'b0;
        end else begin
            if (m_axis_tvalid) begin
                timeout_cnt <= VALID_TIMEOUT;
            end else if (timeout_cnt != 16'd0) begin
                timeout_cnt <= timeout_cnt - 16'd1;
            end

            if (timeout_cnt == 16'd0)
                pipeline_stall_fault <= 1'b1;
            else if (pipeline_srst)
                pipeline_stall_fault <= 1'b0;
        end
    end

    // -------------------------------------------------------------------------
    // Monitor 2 — Stuck output detector
    // -------------------------------------------------------------------------
    reg [15:0] last_sample;
    reg [4:0]  stuck_cnt;
    reg        output_stuck_fault;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            last_sample        <= 16'sd0;
            stuck_cnt          <= 5'd0;
            output_stuck_fault <= 1'b0;
        end else begin
            if (m_axis_tvalid) begin
                if (m_axis_tdata == last_sample) begin
                    stuck_cnt <= (stuck_cnt == 5'd31) ? stuck_cnt : stuck_cnt + 5'd1;
                end else begin
                    stuck_cnt <= 5'd0;
                end
                last_sample <= m_axis_tdata;

                if (stuck_cnt >= (STUCK_THRESHOLD - 1))
                    output_stuck_fault <= 1'b1;
            end

            if (pipeline_srst) begin
                output_stuck_fault <= 1'b0;
                stuck_cnt          <= 5'd0;
            end
        end
    end

    // -------------------------------------------------------------------------
    // Global sample counter
    // -------------------------------------------------------------------------
    reg [31:0] global_sample_cnt;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            global_sample_cnt <= 32'd0;
        end else if (m_axis_tvalid) begin
            global_sample_cnt <= global_sample_cnt + 32'd1;
        end
    end

    // -------------------------------------------------------------------------
    // Fault log registers
    // -------------------------------------------------------------------------
    reg [1:0]  fault_type_reg;
    reg [31:0] fault_sample_cnt;
    reg [7:0]  fault_count_reg;

    // -------------------------------------------------------------------------
    // Recovery FSM
    // -------------------------------------------------------------------------
    localparam [1:0] IDLE           = 2'b00;
    localparam [1:0] FAULT_DETECT   = 2'b01;
    localparam [1:0] PIPELINE_DRAIN = 2'b10;
    localparam [1:0] FORCE_RESET    = 2'b11;

    reg [1:0] rcv_state;
    reg [2:0] drain_cnt;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rcv_state        <= IDLE;
            drain_cnt        <= 3'd0;
            pipeline_srst    <= 1'b0;
            irq_fault        <= 1'b0;
            fault_type_reg   <= 2'b00;
            fault_sample_cnt <= 32'd0;
            fault_count_reg  <= 8'd0;
        end else begin
            case (rcv_state)
                IDLE: begin
                    pipeline_srst <= 1'b0;
                    irq_fault     <= 1'b0;
                    if (pipeline_stall_fault || output_stuck_fault) begin
                        rcv_state <= FAULT_DETECT;
                    end
                end

                FAULT_DETECT: begin
                    // Capture fault info
                    if (pipeline_stall_fault)
                        fault_type_reg <= 2'b01;
                    else
                        fault_type_reg <= 2'b10;

                    fault_sample_cnt <= global_sample_cnt;
                    fault_count_reg  <= fault_count_reg + 8'd1;
                    pipeline_srst    <= 1'b1;
                    drain_cnt        <= 3'd0;
                    rcv_state        <= PIPELINE_DRAIN;
                end

                PIPELINE_DRAIN: begin
                    pipeline_srst <= 1'b1;
                    if (drain_cnt == 3'd7) begin
                        rcv_state <= FORCE_RESET;
                    end else begin
                        drain_cnt <= drain_cnt + 3'd1;
                    end
                end

                FORCE_RESET: begin
                    pipeline_srst <= 1'b0;
                    irq_fault     <= 1'b1;
                    rcv_state     <= IDLE;
                end
            endcase
        end
    end

    // -------------------------------------------------------------------------
    // AXI4-Lite read
    // -------------------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_rdata  <= 32'd0;
            s_axi_rvalid <= 1'b0;
        end else begin
            s_axi_rvalid <= 1'b0;
            if (s_axi_arvalid) begin
                s_axi_rvalid <= 1'b1;
                case (s_axi_araddr[3:0])
                    4'h0: s_axi_rdata <= {30'd0, fault_type_reg};
                    4'h4: s_axi_rdata <= fault_sample_cnt;
                    4'h8: s_axi_rdata <= {24'd0, fault_count_reg};
                    default: s_axi_rdata <= 32'd0;
                endcase
            end
            // Clear irq_fault on read of fault_type_reg
            if (s_axi_arvalid && (s_axi_araddr[3:0] == 4'h0))
                irq_fault <= 1'b0;
        end
    end

    // -------------------------------------------------------------------------
    // AXI4-Lite write (fault_clear)
    // -------------------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
        end else begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            if (s_axi_awvalid && s_axi_wvalid && (s_axi_awaddr[3:0] == 4'hC)) begin
                s_axi_awready   <= 1'b1;
                s_axi_wready    <= 1'b1;
                fault_count_reg <= 8'd0;
                fault_type_reg  <= 2'b00;
            end
        end
    end

endmodule
