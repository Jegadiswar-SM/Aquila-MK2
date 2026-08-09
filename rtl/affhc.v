// =============================================================================
// Module      : affhc
// Description : Adaptive Forgetting Factor Hardware Controller
//               Dynamically selects RLS forgetting factor lambda based on
//               the rate of change in the error residual e(n).
//               FSM: STEADY → TRACKING → FAST (and reverse) with hysteresis
//               and lockout counters on transitions.
// Author      : GLI / tapeitout.com
// Revision    : 1.0
// SPDX-License-Identifier: Apache-2.0
// =============================================================================

`timescale 1ns / 1ps

module affhc #(
    parameter THRESHOLD_UP   = 16'd512,
    parameter THRESHOLD_DOWN = 16'd128,
    parameter DWELL_UP       = 3,
    parameter DWELL_DOWN     = 8,
    parameter LOCKOUT_CYCLES = 32
)(
    input  wire        clk,
    input  wire        rst_n,

    input  wire [15:0] e_in,
    input  wire        e_valid,

    // AXI4-Lite slave (write-only)
    input  wire [4:0]  s_axi_awaddr,
    input  wire        s_axi_awvalid,
    input  wire [31:0] s_axi_wdata,
    input  wire        s_axi_wvalid,
    output reg         s_axi_awready,
    output reg         s_axi_wready,

    output reg  [15:0] lambda_out,
    output reg  [1:0]  fsm_state_dbg
);

    // -------------------------------------------------------------------------
    // AXI4-Lite writable config registers
    // -------------------------------------------------------------------------
    reg [15:0] lambda_slow;
    reg [15:0] lambda_mid;
    reg [15:0] lambda_fast;
    reg [15:0] threshold_up_reg;
    reg [15:0] threshold_down_reg;

    // -------------------------------------------------------------------------
    // FSM state encoding
    // -------------------------------------------------------------------------
    localparam [1:0] STEADY   = 2'b00;
    localparam [1:0] TRACKING = 2'b01;
    localparam [1:0] FAST     = 2'b10;
    localparam [1:0] LOCKOUT  = 2'b11;

    reg [1:0] state;
    reg [1:0] next_state;     // target state after lockout expires

    // -------------------------------------------------------------------------
    // Internal registers
    // -------------------------------------------------------------------------
    reg [15:0] e_prev;
    wire [16:0] delta_e;
    reg [2:0]  cnt_up;        // 3-bit hysteresis counter for upward transition
    reg [3:0]  cnt_down;      // 4-bit hysteresis counter for downward transition
    reg [5:0]  lockout_cnt;   // 6-bit lockout counter
    reg        lockout_active;

    // -------------------------------------------------------------------------
    // AXI4-Lite write handling
    // -------------------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            lambda_slow   <= 16'h7F00;
            lambda_mid    <= 16'h7E00;
            lambda_fast   <= 16'h7800;
            threshold_up_reg   <= THRESHOLD_UP;
            threshold_down_reg <= THRESHOLD_DOWN;
        end else begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            if (s_axi_awvalid && s_axi_wvalid) begin
                s_axi_awready <= 1'b1;
                s_axi_wready  <= 1'b1;
                case (s_axi_awaddr[4:0])
                    5'h00: lambda_slow   <= s_axi_wdata[15:0];
                    5'h04: lambda_mid    <= s_axi_wdata[15:0];
                    5'h08: lambda_fast   <= s_axi_wdata[15:0];
                    5'h0C: threshold_up_reg   <= s_axi_wdata[15:0];
                    5'h10: threshold_down_reg <= s_axi_wdata[15:0];
                endcase
            end
        end
    end

    // -------------------------------------------------------------------------
    // Delta-e computation
    // -------------------------------------------------------------------------
    assign delta_e = ($signed(e_in) > $signed(e_prev))
        ? ($signed(e_in) - $signed(e_prev))
        : ($signed(e_prev) - $signed(e_in));

    // -------------------------------------------------------------------------
    // FSM and counters (all clocked on posedge clk)
    // -------------------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state          <= STEADY;
            next_state     <= STEADY;
            e_prev         <= 16'sd0;
            cnt_up         <= 3'd0;
            cnt_down       <= 4'd0;
            lockout_cnt    <= 6'd0;
            lockout_active <= 1'b0;
            lambda_out     <= 16'h7F00;
            fsm_state_dbg  <= STEADY;
        end else begin
            // Preserve previous error sample
            if (e_valid) begin
                e_prev <= e_in;
            end

            // Lockout counter
            if (lockout_active) begin
                if (e_valid) begin
                    if (lockout_cnt == 6'd0) begin
                        lockout_active <= 1'b0;
                        state          <= next_state;
                    end else begin
                        lockout_cnt <= lockout_cnt - 6'd1;
                    end
                end
            end else if (e_valid) begin
                // --- Hysteresis counters ---
                if (delta_e > {1'b0, threshold_up_reg}) begin
                    cnt_up   <= (cnt_up == {DWELL_UP{1'b1}}) ? cnt_up : cnt_up + 3'd1;
                    cnt_down <= 4'd0;
                end else if (delta_e < {1'b0, threshold_down_reg}) begin
                    cnt_down <= (cnt_down == {DWELL_DOWN{1'b1}}) ? cnt_down : cnt_down + 4'd1;
                    cnt_up   <= 3'd0;
                end else begin
                    cnt_up   <= 3'd0;
                    cnt_down <= 4'd0;
                end

                // --- State transitions ---
                case (state)
                    STEADY: begin
                        if (cnt_up >= DWELL_UP) begin
                            lockout_active <= 1'b1;
                            lockout_cnt    <= LOCKOUT_CYCLES;
                            next_state     <= TRACKING;
                            state          <= LOCKOUT;
                        end
                    end
                    TRACKING: begin
                        if (cnt_up >= DWELL_UP) begin
                            lockout_active <= 1'b1;
                            lockout_cnt    <= LOCKOUT_CYCLES;
                            next_state     <= FAST;
                            state          <= LOCKOUT;
                        end else if (cnt_down >= DWELL_DOWN) begin
                            lockout_active <= 1'b1;
                            lockout_cnt    <= LOCKOUT_CYCLES;
                            next_state     <= STEADY;
                            state          <= LOCKOUT;
                        end
                    end
                    FAST: begin
                        if (cnt_down >= DWELL_DOWN) begin
                            lockout_active <= 1'b1;
                            lockout_cnt    <= LOCKOUT_CYCLES;
                            next_state     <= TRACKING;
                            state          <= LOCKOUT;
                        end
                    end
                endcase
            end

            // Lambda output mux
            case (state)
                STEADY:   lambda_out <= lambda_slow;
                TRACKING: lambda_out <= lambda_mid;
                FAST:     lambda_out <= lambda_fast;
                default:  lambda_out <= lambda_out;  // hold during LOCKOUT
            endcase

            fsm_state_dbg <= state;
        end
    end

endmodule
