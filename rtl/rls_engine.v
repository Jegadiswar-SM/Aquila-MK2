`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0
//
// ASIC HARDENING CHANGES (vs. original):
//   1. Removed `initial begin` LUT ROM → replaced with nr_lut_read() function
//      (synthesises as combinational mux-tree or block ROM — ASIC-safe).
//   2. STAGE0 and STAGE3: changed always @(posedge clk) to
//      always @(posedge clk or negedge rst_n) for async-assert reset.
//   3. STAGE2: changed always @(posedge clk) to
//      always @(posedge clk or negedge rst_n) for async-assert reset.
//      Weight registers (w[]) still excluded from srst (intentional).
//   4. (* rom_style = "distributed" *) attribute removed; synthesis tool
//      will infer ROM style from the function case statement.

module rls_engine #(
    parameter N          = 8,
    parameter W          = 16,
    parameter LAMBDA_Q15 = 16'h7F00
)(
    input  wire              clk,
    input  wire              rst_n,
    input  wire              srst,         // Pipeline soft reset (excludes weight/p_scalar)
    input  wire              sample_en,
    input  wire signed [15:0] d_in,
    input  wire signed [15:0] x_in,
    input  wire signed [15:0] lambda_in,   // External override (0 = use LAMBDA_Q15)
    input  wire signed [15:0] leak_factor, // Leakage factor Q1.15 (E2 default 16'h7FE0)
    input  wire signed [15:0] e_weighted,  // Frequency-weighted error for update (E4)

    output reg  signed [15:0] error_out,
    output reg                valid_out,
    output reg  signed [15:0] y_hat,       // RLS estimate for FWES/top-level
    output wire signed [15:0] nr_x2_debug  // NR reciprocal (Q2.14), for test observation
);

    // Declare before the continuous assignment for compatibility with older
    // Incisive ncvlog parsers.
    reg signed [15:0] nr_x2;
    assign nr_x2_debug = nr_x2;

    localparam ACC_W = 40;
    localparam FRAC  = 15;
    localparam signed [15:0] TWO_Q214 = 16'sh7FFF; // +1.99994: saturated "2.0" in signed Q2.14
    // y_acc is Q?.15 and y_hat takes the signed Q1.15 slice [30:15].
    // These are the exact accumulator limits corresponding to 0x7fff and
    // 0x8000 in that output format.
    localparam signed [ACC_W-1:0] Y_HAT_MAX_ACC = 40'sh003FFF8000;
    localparam signed [ACC_W-1:0] Y_HAT_MIN_ACC = 40'shFFC0000000;

    wire [15:0] lambda_used = (lambda_in == 16'd0) ? LAMBDA_Q15[15:0] : lambda_in;

    reg signed [W-1:0] w [0:N-1];
    reg signed [W-1:0] x_dly [0:N-1];
    reg signed [W-1:0] p_scalar;

    /* verilator lint_off UNUSEDSIGNAL */
    reg signed [ACC_W-1:0] y_acc;
    reg signed [ACC_W-1:0] xTx_acc;
    /* verilator lint_on UNUSEDSIGNAL */
    reg signed [W-1:0]     e_reg;
    reg signed [W-1:0]     d_pipe;
    reg                    s1_valid;

    // =========================================================================
    // E1: 2nd-Order Newton-Raphson — 32-entry combinational ROM function
    //
    // ASIC FIX: Replaced `initial begin` / reg-array LUT with a pure
    // combinational function. Synthesis tools infer this as a mux tree or
    // embedded ROM block — fully synthesizable and DRC-safe.
    //
    // 32 segments over [0,1): each entry = 2.0 - D_mid in Q2.14.
    // =========================================================================
    function automatic [15:0] nr_lut_read;
        input [4:0] addr;
        case (addr)
            5'd0:  nr_lut_read = 16'h7F00;
            5'd1:  nr_lut_read = 16'h7D00;
            5'd2:  nr_lut_read = 16'h7B00;
            5'd3:  nr_lut_read = 16'h7900;
            5'd4:  nr_lut_read = 16'h7700;
            5'd5:  nr_lut_read = 16'h7500;
            5'd6:  nr_lut_read = 16'h7300;
            5'd7:  nr_lut_read = 16'h7100;
            5'd8:  nr_lut_read = 16'h6F00;
            5'd9:  nr_lut_read = 16'h6D00;
            5'd10: nr_lut_read = 16'h6B00;
            5'd11: nr_lut_read = 16'h6900;
            5'd12: nr_lut_read = 16'h6700;
            5'd13: nr_lut_read = 16'h6500;
            5'd14: nr_lut_read = 16'h6300;
            5'd15: nr_lut_read = 16'h6100;
            5'd16: nr_lut_read = 16'h5F00;
            5'd17: nr_lut_read = 16'h5D00;
            5'd18: nr_lut_read = 16'h5B00;
            5'd19: nr_lut_read = 16'h5900;
            5'd20: nr_lut_read = 16'h5700;
            5'd21: nr_lut_read = 16'h5500;
            5'd22: nr_lut_read = 16'h5300;
            5'd23: nr_lut_read = 16'h5100;
            5'd24: nr_lut_read = 16'h4F00;
            5'd25: nr_lut_read = 16'h4D00;
            5'd26: nr_lut_read = 16'h4B00;
            5'd27: nr_lut_read = 16'h4900;
            5'd28: nr_lut_read = 16'h4700;
            5'd29: nr_lut_read = 16'h4500;
            5'd30: nr_lut_read = 16'h4300;
            5'd31: nr_lut_read = 16'h4100;
            default: nr_lut_read = 16'h7F00;
        endcase
    endfunction

    // NR pipeline registers
    reg signed [15:0] nr_denom_p1;    // Q1.15 denom delayed to NR stage 1
    reg signed [15:0] nr_x1;          // Q2.14 format, range [-2.0,+1.99994)
    reg               nr_p1_valid;
    reg               nr_p2_valid;

    reg signed [W-1:0] x_dly_p1 [0:N-1]; // Delayed x_dly for weight update
    reg signed [W-1:0] e_reg_p1;          // Delayed e_reg for weight update
    reg signed [W-1:0] d_pipe_p1;         // Delayed d_pipe

    // The original implementation updated all eight taps in parallel.  That
    // created eight leakage multipliers and sixteen gain/error multipliers in
    // one synthesis cone.  Keep one scheduled tap datapath instead.  The
    // scalar NR and dot-product semantics remain unchanged; only the
    // independent per-tap updates are serialized.
    reg                    rls_busy;
    reg                    update_busy;
    reg             [2:0]  update_idx;
    reg signed      [31:0] update_p_over_denom;
    reg signed      [15:0] update_err;
    // Keep the estimate/error pipeline's original sample cadence.  At the
    // intended 8 kHz service interval the serialized update lane is idle
    // before the next sample; short-cadence diagnostic pulses may still
    // update y_hat without corrupting the protected tap-update schedule.
    wire                   sample_accept = sample_en;
    wire                   update_done = update_busy && (update_idx == 3'd7);
    wire signed     [31:0] update_w_leaked = $signed(leak_factor) * $signed(w[update_idx]);
    wire signed     [31:0] update_ke1 =
        ($signed(update_p_over_denom[15:0]) * $signed(x_dly_p1[update_idx])) >>> FRAC;
    wire signed     [31:0] update_ke = (update_ke1 * $signed(update_err)) >>> FRAC;
    wire signed     [31:0] update_w_sum =
        $signed({{16{update_w_leaked[30]}}, update_w_leaked[30:15]}) +
        $signed({{16{update_ke[15]}}, update_ke[15:0]});

    // =========================================================================
    // STAGE0: Dot product + error computation
    // ASIC FIX: Changed to always @(posedge clk or negedge rst_n) for async reset.
    // =========================================================================
    always @(posedge clk or negedge rst_n) begin : STAGE0
        if (!rst_n) begin
            y_acc    <= {ACC_W{1'b0}};
            xTx_acc  <= {ACC_W{1'b0}};
            e_reg    <= 16'sd0;
            d_pipe   <= 16'sd0;
            s1_valid <= 1'b0;
            rls_busy <= 1'b0;
            for (integer i_s0_reset = 0; i_s0_reset < N; i_s0_reset = i_s0_reset + 1)
                x_dly[i_s0_reset] <= 16'sd0;
        end else if (srst) begin
            y_acc    <= {ACC_W{1'b0}};
            xTx_acc  <= {ACC_W{1'b0}};
            e_reg    <= 16'sd0;
            d_pipe   <= 16'sd0;
            s1_valid <= 1'b0;
            rls_busy <= 1'b0;
            for (integer i_s0_srst = 0; i_s0_srst < N; i_s0_srst = i_s0_srst + 1)
                x_dly[i_s0_srst] <= 16'sd0;
        end else begin
            if (update_done)
                rls_busy <= 1'b0;
            s1_valid <= sample_accept;
            if (sample_accept) begin
                rls_busy <= 1'b1;
                for (integer i_s0_shift = N-1; i_s0_shift > 0; i_s0_shift = i_s0_shift - 1)
                    x_dly[i_s0_shift] <= x_dly[i_s0_shift-1];
                x_dly[0] <= x_in;
                d_pipe <= d_in;

                begin : DOT_PRODUCT
                    reg signed [ACC_W-1:0] acc_y;
                    reg signed [ACC_W-1:0] acc_xx;
                    integer j;
                    acc_y  = {ACC_W{1'b0}};
                    acc_xx = {ACC_W{1'b0}};
                    for (j = 0; j < N; j = j + 1) begin
                        acc_y  = acc_y  + $signed(w[j])     * $signed(x_dly[j]);
                        acc_xx = acc_xx + $signed(x_dly[j]) * $signed(x_dly[j]);
                    end
                    y_acc   <= acc_y;
                    xTx_acc <= acc_xx;
                end

                e_reg <= d_in - $signed(y_acc[30:15]);
            end
        end
    end

    // =========================================================================
    // STAGE1: Denominator computation + 2nd-order Newton-Raphson Stage 1
    // Already had negedge rst_n — no change needed for reset style.
    // ASIC FIX: LUT read via nr_lut_read() function (not reg array).
    // =========================================================================
    always @(posedge clk or negedge rst_n) begin : STAGE1_NR1
        if (!rst_n) begin
            nr_denom_p1 <= 16'sd0;
            nr_x1       <= 16'sd0;
            nr_p1_valid <= 1'b0;
            for (integer i_s1_reset = 0; i_s1_reset < N; i_s1_reset = i_s1_reset + 1)
                x_dly_p1[i_s1_reset] <= 16'sd0;
            e_reg_p1    <= 16'sd0;
            d_pipe_p1   <= 16'sd0;
        end else if (srst) begin
            nr_p1_valid <= 1'b0;
            for (integer i_s1_srst = 0; i_s1_srst < N; i_s1_srst = i_s1_srst + 1)
                x_dly_p1[i_s1_srst] <= 16'sd0;
            e_reg_p1    <= 16'sd0;
            d_pipe_p1   <= 16'sd0;
        end else begin
            nr_p1_valid <= s1_valid;
            if (s1_valid) begin
                // Pipeline x_dly, e_reg, d_pipe for weight update in STAGE2
                for (integer i_s1_pipe = 0; i_s1_pipe < N; i_s1_pipe = i_s1_pipe + 1)
                    x_dly_p1[i_s1_pipe] <= x_dly[i_s1_pipe];
                e_reg_p1  <= e_reg;
                d_pipe_p1 <= d_pipe;

                if (y_acc > Y_HAT_MAX_ACC)
                    y_hat <= 16'sh7FFF;
                else if (y_acc < Y_HAT_MIN_ACC)
                    y_hat <= 16'sh8000;
                else
                    y_hat <= y_acc[30:15];

                begin : NR_STAGE1
                    reg signed [31:0] denom;
                    reg signed [15:0] d_norm;
                    reg [4:0]         lut_idx;
                    reg signed [15:0] x0;
                    reg signed [31:0] lambda_ext;
                    reg signed [31:0] p_scalar_ext;
                    reg signed [31:0] xTx_q15;
                    /* verilator lint_off UNUSEDSIGNAL */
                    reg signed [31:0] Dx0;
                    /* verilator lint_on UNUSEDSIGNAL */
                    reg signed [31:0] x1_product;
                    /* verilator lint_off UNUSEDSIGNAL */
                    reg signed [31:0] x1_shift;
                    /* verilator lint_on UNUSEDSIGNAL */
                    reg signed [63:0] denom_prod;
                    /* verilator lint_off UNUSEDSIGNAL */
                    reg signed [63:0] denom_prod_shift;
                    /* verilator lint_on UNUSEDSIGNAL */
                    reg signed [31:0] denom_prod_q15;
                    reg signed [15:0] Dx0_q214;
                    reg signed [15:0] residual1;

                    lambda_ext = $signed({16'd0, lambda_used});
                    p_scalar_ext = $signed({{16{p_scalar[15]}}, p_scalar});
                    xTx_q15 = $signed({{16{xTx_acc[30]}}, xTx_acc[30:15]});
                    denom_prod = $signed(p_scalar_ext) * $signed(xTx_q15);
                    denom_prod_shift = denom_prod >>> FRAC;
                    denom_prod_q15 = denom_prod_shift[31:0];
                    denom = lambda_ext + denom_prod_q15;

                    if (denom[31] || (denom == 0))
                        d_norm = 16'sh4000;
                    else
                        d_norm = denom[15:0];

                    nr_denom_p1 <= d_norm;

                    // ASIC FIX: read LUT via function (was reg-array initial block)
                    lut_idx = d_norm[14:10];
                    x0 = nr_lut_read(lut_idx);

                    // NR stage 1: x1 = x0 * (2 - D*x0)
                    Dx0 = $signed({1'b0, d_norm}) * $signed(x0);  // Q1.15 * Q2.14 = Q3.29
                    Dx0_q214 = Dx0[30:15];                         // Q3.29 -> Q2.14
                    residual1 = TWO_Q214 - Dx0_q214;               // 2.0 - D*x0 in Q2.14
                    x1_product = $signed(x0) * $signed(residual1);  // Q2.14 * Q2.14 = Q4.28
                    x1_shift = x1_product >>> 14;
                    nr_x1 <= x1_shift[15:0];
                end
            end
        end
    end

    // =========================================================================
    // STAGE2: 2nd-order Newton-Raphson Stage 2 + Weight Update
    // ASIC FIX: Changed to always @(posedge clk or negedge rst_n) for async reset.
    // NOTE: Weight registers w[] and p_scalar are NOT reset by srst (intentional:
    //       PLWD pipeline soft-reset preserves adaptive filter state).
    // =========================================================================
    always @(posedge clk or negedge rst_n) begin : STAGE2_NR2
        if (!rst_n) begin
            p_scalar    <= 16'sh0800;
            nr_x2       <= 16'sd0;
            nr_p2_valid <= 1'b0;
            update_busy <= 1'b0;
            update_idx  <= 3'd0;
            update_p_over_denom <= 32'sd0;
            update_err  <= 16'sd0;
            for (integer i_s2_reset = 0; i_s2_reset < N; i_s2_reset = i_s2_reset + 1)
                w[i_s2_reset] <= 16'sd0;
        end else if (srst) begin
            nr_p2_valid <= 1'b0;
            update_busy <= 1'b0;
            update_idx  <= 3'd0;
            update_p_over_denom <= 32'sd0;
            update_err  <= 16'sd0;
            // w[] and p_scalar preserved intentionally
        end else begin
            nr_p2_valid <= 1'b0;
            if (update_busy) begin
                // One physical tap-update lane is reused for all eight taps.
                if (update_w_sum > 32'sh00007FFF)
                    w[update_idx] <= 16'sh7FFF;
                else if (update_w_sum < -32'sh00008000)
                    w[update_idx] <= 16'sh8000;
                else
                    w[update_idx] <= update_w_sum[15:0];

                if (update_idx == 3'd7) begin
                    update_busy <= 1'b0;
                    nr_p2_valid <= 1'b1;
                end else begin
                    update_idx <= update_idx + 3'd1;
                end
            end else if (nr_p1_valid) begin : NR_STAGE2
                /* verilator lint_off UNUSEDSIGNAL */
                reg signed [31:0] Dx1;
                /* verilator lint_on UNUSEDSIGNAL */
                reg signed [31:0] p_over_denom;
                reg signed [15:0] Dx1_q214;
                reg signed [15:0] residual2;
                reg signed [31:0] x2_product;
                /* verilator lint_off UNUSEDSIGNAL */
                reg signed [31:0] x2_shift;
                /* verilator lint_on UNUSEDSIGNAL */

                // NR stage 2: x2 = x1 * (2 - D*x1), all x/residual terms Q2.14.
                Dx1 = $signed({1'b0, nr_denom_p1}) * $signed(nr_x1);
                Dx1_q214 = Dx1[30:15];
                residual2 = TWO_Q214 - Dx1_q214;
                x2_product = $signed(nr_x1) * $signed(residual2);  // Q2.14 * Q2.14 = Q4.28
                x2_shift = x2_product >>> 14;
                nr_x2 <= x2_shift[15:0];

                // Kalman gain scalar: p_scalar(Q1.15) * reciprocal(Q2.14)
                p_over_denom = $signed(p_scalar) * $signed(nr_x2);
                p_over_denom = p_over_denom >>> 14;

                // E2: Capture the common terms and serialize the exact same
                // per-tap update over the following eight cycles.
                update_p_over_denom <= p_over_denom;
                update_err <= (e_weighted != 16'd0) ? e_weighted : e_reg_p1;
                update_idx <= 3'd0;
                update_busy <= 1'b1;

                begin : P_UPDATE
                    reg signed [31:0] p_new;
                    reg signed [31:0] p_scalar_ext;
                    p_scalar_ext = $signed({{16{p_scalar[15]}}, p_scalar});
                    p_new = p_scalar_ext + (p_scalar_ext >>> 7);
                    if (p_new > 32'sh00007FFF)
                        p_scalar <= 16'sh7FFF;
                    else if (p_new < 32'sd1)
                        p_scalar <= 16'sh0001;
                    else
                        p_scalar <= p_new[15:0];
                end
            end
        end
    end

    // =========================================================================
    // STAGE3: Output error computation
    // ASIC FIX: Changed to always @(posedge clk or negedge rst_n) for async reset.
    // =========================================================================
    always @(posedge clk or negedge rst_n) begin : STAGE3_OUT
        if (!rst_n) begin
            error_out <= 16'sd0;
            valid_out <= 1'b0;
        end else if (srst) begin
            error_out <= 16'sd0;
            valid_out <= 1'b0;
        end else begin
            valid_out <= nr_p2_valid;
            if (nr_p2_valid) begin
                error_out <= d_pipe_p1 - y_hat;
            end
        end
    end

endmodule
