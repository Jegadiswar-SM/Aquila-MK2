`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0
//
// ASIC HARDENING CHANGES (vs. original):
//   1. Instantiated `rst_sync` to generate a 2FF synchronized reset `rst_n_sync`.
//   2. Submodules receive synchronized reset release; top-level sequential
//      blocks retain raw `rst_n` for asynchronous assertion and qualify reset
//      release with `rst_n_sync`.
//   3. Watchdog recovery is distributed as synchronous `srst` to datapath
//      blocks; it is not used as a generated clock.
//   4. Added weight programming ports (`wload_en`, `wload_addr`, `wload_data`)
//      and integrated the `mlp_weight_sram_wrapper` to feed the time-multiplexed MLP.
//   5. Connected SRAM read interface ports to `mlp_inference`.
//   6. Cleaned up global `integer i` declarations to avoid multiple driver / scoping issues.

module rls_dnn_top (
    input  wire        clk,
    input  wire        rst_n,           // Raw asynchronous reset input (from IO pad)
    input  wire        sample_enable,

    // Weight Programming Interface
    input  wire         wload_en,
    input  wire [16:0]  wload_addr,
    input  wire [15:0]  wload_data,

    input  wire [31:0] s_axis_tdata,
    input  wire        s_axis_tvalid,
    output wire        s_axis_tready,

    output reg  [15:0] m_axis_tdata,
    output reg         m_axis_tvalid,
    input  wire        m_axis_tready,

    input  wire [7:0]  s_axi_awaddr,
    input  wire        s_axi_awvalid,
    output wire        s_axi_awready,
    input  wire [31:0] s_axi_wdata,
    input  wire        s_axi_wvalid,
    output wire        s_axi_wready,
    output reg  [1:0]  s_axi_bresp,
    output reg         s_axi_bvalid,
    input  wire        s_axi_bready,
    input  wire [7:0]  s_axi_araddr,
    input  wire        s_axi_arvalid,
    output wire        s_axi_arready,
    output reg  [31:0] s_axi_rdata,
    output reg  [1:0]  s_axi_rresp,
    output reg         s_axi_rvalid,
    input  wire        s_axi_rready,

    output wire        clk_gate_en,
    output wire        irq_fault
);

    // =========================================================================
    // Reset Synchronizer (2FF)
    // =========================================================================
    wire rst_n_sync;
    rst_sync u_rst_sync (
        .clk    (clk),
        .rst_n_i(rst_n),
        .rst_n_o(rst_n_sync)
    );

    // =========================================================================
    // Unpack AXI-S input
    // =========================================================================
    wire signed [15:0] d_in = s_axis_tdata[15:0];
    wire signed [15:0] x_in = s_axis_tdata[31:16];

    // =========================================================================
    // AXI-S input gating
    // =========================================================================
    wire sample_consumed;
    // The existing datapath has no storage for a second feature vector while
    // the time-multiplexed MLP is active.  Serialize admission explicitly so
    // every accepted AXI-Stream transfer has exactly one eventual result.
    reg  transaction_active;
    assign s_axis_tready = rst_n_sync && sample_enable && !plwd_pipeline_srst
        && !transaction_active
        && (m_axis_tready || !m_axis_tvalid);
    assign sample_consumed = s_axis_tvalid && s_axis_tready && sample_enable;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            transaction_active <= 1'b0;
        end else if (!rst_n_sync || plwd_pipeline_srst) begin
            transaction_active <= 1'b0;
        end else if (m_axis_tvalid && m_axis_tready) begin
            transaction_active <= 1'b0;
        end else if (sample_consumed) begin
            transaction_active <= 1'b1;
        end
    end

    // =========================================================================
    // Internal wires
    // =========================================================================
    // --- CBPF ---
    wire signed [15:0] x_cbpf;
    wire               cbpf_y_valid;
    wire               cbpf_clip_s1;
    wire               cbpf_clip_s2;

    // --- AAD ---
    wire               aad_signal_active;
    wire               aad_clk_gate_en;

    // --- RCIM ---
    wire               rcim_ref_channel_fault;
    wire signed [15:0] rcim_x_out_muxed;

    // --- RLS ---
    wire signed [15:0] rls_error;
    wire signed [15:0] rls_y_hat;
    wire               rls_valid_out;

    // --- AFFHC ---
    wire signed [15:0] affhc_lambda_out;
    wire [1:0]         affhc_fsm_state_dbg;

    // --- PTDL ---
    wire [127:0]       ptdl_taps;

    // --- MLP ---
    wire signed [15:0] mlp_noise_est;
    wire               mlp_valid_out;
    reg                ptdl_valid_d;
    reg signed [15:0]  mlp_error_hold;

    // --- PLWD ---
    wire               plwd_pipeline_srst;
    wire               plwd_irq_fault;

    // --- Control/status registers and decode ---
    reg signed [15:0] rls_leak_factor;
    reg signed [15:0] fwes_alpha_reg;

    wire [2:0] aw_sel;
    wire       affhc_aw_sel;
    wire       aad_aw_sel;
    wire       cbpf_aw_sel;
    wire       plwd_aw_sel;
    wire       rcim_aw_sel;
    wire       rlsctl_aw_sel;
    wire       other_aw_sel;
    wire       write_accept;

    wire [2:0] ar_sel;
    wire       plwd_ar_sel;
    wire       latprof_ar_sel;

    wire affhc_awready;
    wire affhc_wready;
    wire aad_awready;
    wire aad_wready;
    wire cbpf_awready;
    wire cbpf_wready;
    wire plwd_awready;
    wire plwd_wready;
    wire rcim_awready;
    wire rcim_wready;

    wire [31:0] plwd_rdata;
    wire        plwd_rvalid;
    wire [31:0] latprof_rdata;
    wire        latprof_rvalid;
    wire        read_accept;
    reg         read_pending;
    reg         read_pending_plwd;
    reg         read_pending_latprof;

    // Aquila Custom Control Interface: 32-byte byte-addressed windows.
    // Bits [7:5] select the destination block.
    assign aw_sel         = s_axi_awaddr[7:5];
    assign affhc_aw_sel   = (aw_sel == 3'd0);
    assign aad_aw_sel     = (aw_sel == 3'd1);
    assign cbpf_aw_sel    = (aw_sel == 3'd2);
    assign plwd_aw_sel    = (aw_sel == 3'd3);
    assign rcim_aw_sel    = (aw_sel == 3'd4);
    assign rlsctl_aw_sel  = (aw_sel == 3'd5);
    assign other_aw_sel   = (aw_sel >= 3'd6);

    assign ar_sel         = s_axi_araddr[7:5];
    assign plwd_ar_sel    = (ar_sel == 3'd3);
    // LATPROF exposes eleven 32-bit words, so its read-only region extends
    // from 0xC0 through 0xEB. Functional write windows remain 32-byte
    // [7:5]-selected regions; the extension is read-only and unambiguous.
    assign latprof_ar_sel = (s_axi_araddr >= 8'hC0) &&
                            (s_axi_araddr <= 8'hEB);
    assign read_accept    = s_axi_arvalid && s_axi_arready;
    // Coupled custom write: one request may be outstanding and both valid
    // signals must be asserted together. This is intentionally not AXI4-Lite.
    assign write_accept   = rst_n_sync && !s_axi_bvalid &&
                            s_axi_awvalid && s_axi_wvalid;

    // =========================================================================
    // E5: Polyphase Decimation
    // =========================================================================
    wire               poly_rls_en;
    wire               poly_cbpf_en;
    wire [2:0]         poly_decim_cnt_dbg;
    reg [2:0]          decim_ratio;   // AXI4-Lite writable: 001=1:1, 010=1:2, 100=1:4

    poly_decim u_poly (
        .clk               (clk),
        .rst_n             (rst_n_sync),
        .srst              (plwd_pipeline_srst),
        // Decimation advances only for an accepted AXI-stream sample.
        // Using the raw external strobe here would advance the phase while
        // the input is stalled or while no transfer is occurring.
        .sample_enable_in  (sample_consumed),
        .decim_ratio       (decim_ratio),
        .sample_enable_rls (poly_rls_en),
        .sample_enable_cbpf(poly_cbpf_en),
        .decim_cnt_dbg     (poly_decim_cnt_dbg)
    );

    // Sample consumed with decimation gating: CBPF/AAD run at full rate
    wire sample_consumed_cbpf = sample_consumed; // poly_cbpf_en is sample_enable passthrough

    // =========================================================================
    // Pipeline alignment delays
    // =========================================================================
    reg signed [15:0] d_dly [0:5];

    // Use the raw reset for asynchronous assertion.  Keep rst_n_sync in the
    // reset condition so release remains synchronized to clk.
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            d_dly[0] <= 16'sd0;
            d_dly[1] <= 16'sd0;
            d_dly[2] <= 16'sd0;
            d_dly[3] <= 16'sd0;
            d_dly[4] <= 16'sd0;
            d_dly[5] <= 16'sd0;
        end else if (!rst_n_sync || plwd_pipeline_srst) begin
            d_dly[0] <= 16'sd0;
            d_dly[1] <= 16'sd0;
            d_dly[2] <= 16'sd0;
            d_dly[3] <= 16'sd0;
            d_dly[4] <= 16'sd0;
            d_dly[5] <= 16'sd0;
        end else if (sample_consumed_cbpf) begin
            d_dly[0] <= d_in;
            d_dly[1] <= d_dly[0];
            d_dly[2] <= d_dly[1];
            d_dly[3] <= d_dly[2];
            d_dly[4] <= d_dly[3];
            d_dly[5] <= d_dly[4];
        end
    end

    // RLS enable: gate cbpf_y_valid with decimation decision
    reg decim_q;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            decim_q <= 1'b1;
        else if (!rst_n_sync || plwd_pipeline_srst)
            decim_q <= 1'b1;
        else if (sample_consumed_cbpf) begin
            // poly_decim's enable is registered.  At the acceptance edge its
            // output still describes the previous sample, so derive the
            // decision from the pre-update phase and configured ratio and
            // hold it until CBPF produces the corresponding valid pulse.
            case (decim_ratio)
                3'b001: decim_q <= 1'b1;
                3'b010: decim_q <= (poly_decim_cnt_dbg == 3'd0);
                3'b100: decim_q <= (poly_decim_cnt_dbg == 3'd0);
                default: decim_q <= 1'b1;
            endcase
        end
    end

    reg rls_en;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            rls_en <= 1'b0;
        else if (!rst_n_sync || plwd_pipeline_srst)
            rls_en <= 1'b0;
        else
            rls_en <= cbpf_y_valid && decim_q;
    end

    // =========================================================================
    // Module Instantiations
    // =========================================================================

    // --- CBPF: Bandpass pre-filter on reference channel x ---
    cbpf_2sos u_cbpf (
        .clk             (clk),
        .rst_n           (rst_n_sync),
        .srst            (plwd_pipeline_srst),
        .x_in            (x_in),
        .x_valid         (sample_consumed_cbpf),
        .s_axi_awaddr    (s_axi_awaddr[3:0]),
        .s_axi_awvalid   (cbpf_aw_sel && write_accept),
        .s_axi_wdata     (s_axi_wdata),
        .s_axi_wvalid    (cbpf_aw_sel && write_accept),
        .s_axi_awready   (cbpf_awready),
        .s_axi_wready    (cbpf_wready),
        .y_out           (x_cbpf),
        .y_valid         (cbpf_y_valid),
        .clip_s1         (cbpf_clip_s1),
        .clip_s2         (cbpf_clip_s2)
    );

    // --- AAD: Acoustic Activity Detector on filtered x ---
    aad u_aad (
        .clk             (clk),
        .rst_n           (rst_n_sync),
        .srst            (plwd_pipeline_srst),
        .x_in            (x_cbpf),
        .x_valid         (cbpf_y_valid),
        .s_axi_awaddr    (s_axi_awaddr[3:0]),
        .s_axi_awvalid   (aad_aw_sel && write_accept),
        .s_axi_wdata     (s_axi_wdata),
        .s_axi_wvalid    (aad_aw_sel && write_accept),
        .s_axi_awready   (aad_awready),
        .s_axi_wready    (aad_wready),
        .signal_active   (aad_signal_active),
        .clk_gate_en     (aad_clk_gate_en),
        .acc_A_dbg       (),
        .acc_B_dbg       ()
    );

    // --- RCIM: Reference Channel Integrity Monitor ---
    rcim u_rcim (
        .clk               (clk),
        .rst_n             (rst_n_sync),
        .srst              (plwd_pipeline_srst),
        .d_in              (d_dly[4]),
        .x_in              (x_cbpf),
        .samples_valid     (cbpf_y_valid),
        .s_axi_awaddr      (s_axi_awaddr[4:0]),
        .s_axi_awvalid     (rcim_aw_sel && write_accept),
        .s_axi_wdata       (s_axi_wdata),
        .s_axi_wvalid      (rcim_aw_sel && write_accept),
        .s_axi_awready     (rcim_awready),
        .s_axi_wready      (rcim_wready),
        .ref_channel_fault (rcim_ref_channel_fault),
        .x_out_muxed       (rcim_x_out_muxed)
    );

    // --- E4: FWES — Frequency-Weighted Error Signal ---
    wire signed [15:0] fwes_e_weighted;

    fwes u_fwes (
        .clk        (clk),
        .rst_n      (rst_n_sync),
        .e_in       (rls_error),
        .e_valid    (rls_valid_out),
        .alpha_reg  (fwes_alpha_reg),
        .e_weighted (fwes_e_weighted),
        .e_output   ()
    );

    // --- RLS Adaptive Engine ---
    wire signed [15:0] rls_nr_x2_debug;

    rls_engine u_rls (
        .clk          (clk),
        .rst_n        (rst_n_sync),
        .srst         (plwd_pipeline_srst),
        .sample_en    (rls_en),
        .d_in         (d_dly[5]),
        .x_in         (rcim_x_out_muxed),
        .lambda_in    (affhc_lambda_out),
        .leak_factor  (rls_leak_factor),
        .e_weighted   (fwes_e_weighted),
        .error_out    (rls_error),
        .valid_out    (rls_valid_out),
        .y_hat        (rls_y_hat),
        .nr_x2_debug  (rls_nr_x2_debug)
    );

    // --- AFFHC: Adaptive Forgetting Factor Controller ---
    affhc u_affhc (
        .clk              (clk),
        .rst_n            (rst_n_sync),
        .e_in             (rls_error),
        .e_valid          (rls_valid_out),
        .s_axi_awaddr     (s_axi_awaddr[4:0]),
        .s_axi_awvalid    (affhc_aw_sel && write_accept),
        .s_axi_wdata      (s_axi_wdata),
        .s_axi_wvalid     (affhc_aw_sel && write_accept),
        .s_axi_awready    (affhc_awready),
        .s_axi_wready     (affhc_wready),
        .lambda_out       (affhc_lambda_out),
        .fsm_state_dbg    (affhc_fsm_state_dbg)
    );

    // --- PTDL: Tapped Delay Line ---
    ptdl_8stage u_ptdl (
        .clk          (clk),
        .rst_n        (rst_n_sync),
        .srst         (plwd_pipeline_srst),
        .sample_en    (rls_valid_out),
        .e_in         (rls_error),
        .taps_out     (ptdl_taps)
    );

    // --- Weight SRAM Wrapper ---
    wire          sram_ren;
    wire [12:0]   sram_raddr;
    wire [255:0]  sram_rdata;
    wire          sram_rvalid;

    mlp_weight_sram_wrapper u_sram (
        .clk        (clk),
        .rst_n      (rst_n_sync),
        .wload_en   (wload_en),
        .wload_addr (wload_addr),
        .wload_data (wload_data),
        .ren        (sram_ren),
        .raddr      (sram_raddr),
        .rdata      (sram_rdata),
        .rvalid     (sram_rvalid)
    );

    // --- MLP Inference Engine ---
    mlp_inference u_mlp (
        .clk          (clk),
        .rst_n        (rst_n_sync),
        .srst         (plwd_pipeline_srst),
        .en_in        (ptdl_valid_d),
        .features_in  (ptdl_taps),
        .ren          (sram_ren),
        .raddr        (sram_raddr),
        .rdata        (sram_rdata),
        .rvalid       (sram_rvalid),
        .y_out        (mlp_noise_est),
        .valid_out    (mlp_valid_out)
    );

    // --- PLWD: Pipeline Watchdog ---
    // The measured zero-weight MLP schedule is 12,186 cycles.  This
    // top-level timeout leaves margin for the surrounding pipeline while
    // retaining a finite watchdog for a genuinely active transaction.
    plwd #(.VALID_TIMEOUT(16'd16384)) u_plwd (
        .clk             (clk),
        .rst_n           (rst_n_sync),
        .m_axis_tvalid   (m_axis_tvalid),
        .m_axis_tdata    (m_axis_tdata),
        .m_axis_tready   (m_axis_tready),
        .pipeline_active (transaction_active),
        .s_axi_araddr    (s_axi_araddr[3:0]),
        .s_axi_arvalid   (plwd_ar_sel && read_accept),
        .s_axi_rdata     (plwd_rdata),
        .s_axi_rvalid    (plwd_rvalid),
        .s_axi_awaddr    (s_axi_awaddr[3:0]),
        .s_axi_awvalid   (plwd_aw_sel && write_accept),
        .s_axi_wdata     (s_axi_wdata),
        .s_axi_wvalid    (plwd_aw_sel && write_accept),
        .s_axi_awready   (plwd_awready),
        .s_axi_wready    (plwd_wready),
        .pipeline_srst   (plwd_pipeline_srst),
        .irq_fault       (plwd_irq_fault)
    );

    // =========================================================================
    // PTDL/MLP transaction alignment
    // =========================================================================
    // PTDL shifts its taps on the edge carrying rls_valid_out.  Delay only
    // the MLP start strobe so the MLP samples the updated tap vector on the
    // following edge.  Hold the corresponding residual for the complete
    // time-multiplexed MLP transaction; a fixed short pipeline cannot remain
    // aligned across the measured 12,186-cycle MLP schedule.
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ptdl_valid_d   <= 1'b0;
            mlp_error_hold <= 16'sd0;
        end else if (!rst_n_sync || plwd_pipeline_srst) begin
            ptdl_valid_d   <= 1'b0;
            mlp_error_hold <= 16'sd0;
        end else begin
            ptdl_valid_d <= rls_valid_out;
            if (rls_valid_out)
                mlp_error_hold <= rls_error;
        end
    end

    // =========================================================================
    // Final Subtraction: y(n) = e_aligned - mlp_estimate
    // =========================================================================
    wire signed [16:0] mlp_scaled = {mlp_noise_est[15], mlp_noise_est} >>> 4;
    wire signed [16:0] sub_full = {mlp_error_hold[15], mlp_error_hold}
                                - mlp_scaled;
    wire signed [15:0] sub_sat;
    assign sub_sat = (sub_full[16] != sub_full[15])
                        ? (sub_full[16] ? 16'sh8000 : 16'sh7FFF)
                        : sub_full[15:0];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            m_axis_tdata  <= 16'sd0;
            m_axis_tvalid <= 1'b0;
        end else if (!rst_n_sync) begin
            m_axis_tdata  <= 16'sd0;
            m_axis_tvalid <= 1'b0;
        end else begin
            if (plwd_pipeline_srst) begin
                m_axis_tvalid <= 1'b0;
            end else if (m_axis_tvalid && !m_axis_tready) begin
                // AXI4-Stream rule: a presented, stalled result owns the
                // output until it is transferred.  A later internal pulse
                // must not overwrite the held data.
                m_axis_tvalid <= 1'b1;
            end else if (mlp_valid_out) begin
                m_axis_tdata  <= sub_sat;
                m_axis_tvalid <= 1'b1;
            end else if (m_axis_tready) begin
                m_axis_tvalid <= 1'b0;
            end
        end
    end

    // =========================================================================
    // E6: Latency Profiler
    // =========================================================================
    lat_prof u_latprof (
        .clk            (clk),
        .rst_n          (rst_n_sync),
        .cbpf_y_valid   (cbpf_y_valid),
        .rls_out_valid  (rls_valid_out),
        .ptdl_out_valid (rls_valid_out),
        .mlp_out_valid  (mlp_valid_out),
        .m_axis_tvalid  (m_axis_tvalid),
        .s_axi_araddr   (s_axi_araddr),
        .s_axi_arvalid  (latprof_ar_sel && read_accept),
        .s_axi_rdata    (latprof_rdata),
        .s_axi_rvalid   (latprof_rvalid)
    );

    // =========================================================================
    // Custom-control registers: leak_factor, fwes_alpha, decim_ratio
    // =========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rls_leak_factor  <= 16'sh7FE0;
            fwes_alpha_reg   <= 16'sh7E00;
            decim_ratio      <= 3'b001;
        end else if (!rst_n_sync) begin
            rls_leak_factor  <= 16'sh7FE0;
            fwes_alpha_reg   <= 16'sh7E00;
            decim_ratio      <= 3'b001;
        end else begin
            if (rlsctl_aw_sel && write_accept) begin
                case (s_axi_awaddr[3:2])
                    2'd0: rls_leak_factor <= s_axi_wdata[15:0];  // 0xA0
                    2'd1: fwes_alpha_reg  <= s_axi_wdata[15:0];  // 0xA4
                    2'd2: decim_ratio     <= s_axi_wdata[2:0];   // 0xA8
                    default: ;
                endcase
            end
        end
    end

    // =========================================================================
    // AXI Module Select Decode
    // =========================================================================
    // Address[7:5] selects module:
    //   0 = AFFHC, 1 = AAD, 2 = CBPF, 3 = PLWD, 4 = RCIM
    //   5 = RLSCTL (leak_factor, fwes_alpha, decim_ratio)
    //   6 = LATPROF (read-only)
    // Ready is an idle indication for the coupled custom write request.
    assign s_axi_awready = rst_n_sync && !s_axi_bvalid;
    assign s_axi_wready  = rst_n_sync && !s_axi_bvalid;

    // Do not advertise a read transfer while the synchronized reset is
    // active.  Otherwise an external master can observe ARREADY during the
    // reset-release pipeline and believe that a request was accepted even
    // though the read process is still resetting.
    assign s_axi_arready = rst_n_sync && !s_axi_rvalid && !read_pending;

    // =========================================================================
    // AXI write response (B channel)
    // =========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_bvalid <= 1'b0;
            s_axi_bresp  <= 2'b00;
        end else if (!rst_n_sync) begin
            s_axi_bvalid <= 1'b0;
            s_axi_bresp  <= 2'b00;
        end else begin
            if (s_axi_bvalid && s_axi_bready)
                s_axi_bvalid <= 1'b0;
            else if (write_accept) begin
                s_axi_bvalid <= 1'b1;
                s_axi_bresp  <= other_aw_sel ? 2'b10 : 2'b00;
            end
        end
    end

    // =========================================================================
    // AXI read response (R channel) — includes lat_prof routing
    // =========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_rdata  <= 32'd0;
            s_axi_rvalid <= 1'b0;
            s_axi_rresp  <= 2'b00;
            read_pending <= 1'b0;
            read_pending_plwd <= 1'b0;
            read_pending_latprof <= 1'b0;
        end else if (!rst_n_sync) begin
            s_axi_rdata  <= 32'd0;
            s_axi_rvalid <= 1'b0;
            s_axi_rresp  <= 2'b00;
            read_pending <= 1'b0;
            read_pending_plwd <= 1'b0;
            read_pending_latprof <= 1'b0;
        end else begin
            if (s_axi_rvalid && s_axi_rready)
                s_axi_rvalid <= 1'b0;

            // Child register blocks return data one cycle after their read
            // request. Capture the response rather than the old rdata value.
            if (read_pending) begin
                if ((read_pending_plwd && plwd_rvalid) ||
                    (read_pending_latprof && latprof_rvalid)) begin
                    s_axi_rvalid <= 1'b1;
                    if (read_pending_plwd)
                        s_axi_rdata <= plwd_rdata;
                    else
                        s_axi_rdata <= latprof_rdata;
                    read_pending <= 1'b0;
                    read_pending_plwd <= 1'b0;
                    read_pending_latprof <= 1'b0;
                end
            end else if (read_accept) begin
                s_axi_rresp <= 2'b00;
                if (plwd_ar_sel || latprof_ar_sel) begin
                    read_pending <= 1'b1;
                    read_pending_plwd <= plwd_ar_sel;
                    read_pending_latprof <= latprof_ar_sel;
                end else begin
                    s_axi_rvalid <= 1'b1;
                    s_axi_rdata <= 32'd0;
                end
            end
        end
    end

    // =========================================================================
    // Output assignments
    // =========================================================================
    assign clk_gate_en = aad_clk_gate_en;
    assign irq_fault   = plwd_irq_fault;

endmodule
