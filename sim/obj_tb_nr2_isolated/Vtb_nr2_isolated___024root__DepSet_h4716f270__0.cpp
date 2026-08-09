// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_nr2_isolated.h for the primary calling header

#include "Vtb_nr2_isolated__pch.h"
#include "Vtb_nr2_isolated___024root.h"

VL_ATTR_COLD void Vtb_nr2_isolated___024root___eval_initial__TOP(Vtb_nr2_isolated___024root* vlSelf);
VlCoroutine Vtb_nr2_isolated___024root___eval_initial__TOP__Vtiming__0(Vtb_nr2_isolated___024root* vlSelf);
VlCoroutine Vtb_nr2_isolated___024root___eval_initial__TOP__Vtiming__1(Vtb_nr2_isolated___024root* vlSelf);

void Vtb_nr2_isolated___024root___eval_initial(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___eval_initial\n"); );
    // Body
    Vtb_nr2_isolated___024root___eval_initial__TOP(vlSelf);
    Vtb_nr2_isolated___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_nr2_isolated___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_nr2_isolated__DOT__clk__0 
        = vlSelf->tb_nr2_isolated__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vtb_nr2_isolated___024root___eval_initial__TOP__Vtiming__0(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ tb_nr2_isolated__DOT__idx;
    tb_nr2_isolated__DOT__idx = 0;
    double tb_nr2_isolated__DOT__max_err;
    tb_nr2_isolated__DOT__max_err = 0;
    double tb_nr2_isolated__DOT__worst_d;
    tb_nr2_isolated__DOT__worst_d = 0;
    double tb_nr2_isolated__DOT__worst_hw;
    tb_nr2_isolated__DOT__worst_hw = 0;
    double tb_nr2_isolated__DOT__worst_true;
    tb_nr2_isolated__DOT__worst_true = 0;
    IData/*31:0*/ __Vtask_tb_nr2_isolated__DOT__run_vector__0__d_q_in;
    __Vtask_tb_nr2_isolated__DOT__run_vector__0__d_q_in = 0;
    IData/*31:0*/ __Vtask_tb_nr2_isolated__DOT__run_vector__1__d_q_in;
    __Vtask_tb_nr2_isolated__DOT__run_vector__1__d_q_in = 0;
    // Body
    VL_WRITEF_NX("==========================================\nNR2 Isolated Sweep Testbench\n==========================================\n",0);
    vlSelf->tb_nr2_isolated__DOT__rst_n = 0U;
    vlSelf->tb_nr2_isolated__DOT__srst = 0U;
    vlSelf->tb_nr2_isolated__DOT__sample_en = 0U;
    vlSelf->tb_nr2_isolated__DOT__d_in = 0U;
    vlSelf->tb_nr2_isolated__DOT__x_in = 0U;
    vlSelf->tb_nr2_isolated__DOT__lambda_in = 0U;
    vlSelf->tb_nr2_isolated__DOT__leak_factor = 0x7fe0U;
    vlSelf->tb_nr2_isolated__DOT__e_weighted = 0U;
    tb_nr2_isolated__DOT__max_err = 0.0;
    tb_nr2_isolated__DOT__worst_d = 0.0;
    tb_nr2_isolated__DOT__worst_hw = 0.0;
    tb_nr2_isolated__DOT__worst_true = 0.0;
    co_await vlSelf->__VtrigSched_h4dfc4760__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_nr2_isolated.clk)", 
                                                       "tb/tb_nr2_isolated.v", 
                                                       114);
    co_await vlSelf->__VtrigSched_h4dfc4760__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_nr2_isolated.clk)", 
                                                       "tb/tb_nr2_isolated.v", 
                                                       114);
    vlSelf->tb_nr2_isolated__DOT__rst_n = 1U;
    VL_WRITEF_NX("t=%0t: Reset released\n",0,64,VL_TIME_UNITED_Q(1000),
                 -9);
    tb_nr2_isolated__DOT__idx = 0U;
    while (VL_GTS_III(32, 0x50U, tb_nr2_isolated__DOT__idx)) {
        vlSelf->tb_nr2_isolated__DOT__d_q = ((IData)(0x4000U) 
                                             + VL_DIVS_III(32, 
                                                           VL_MULS_III(32, (IData)(0x3fffU), tb_nr2_isolated__DOT__idx), (IData)(0x4fU)));
        __Vtask_tb_nr2_isolated__DOT__run_vector__0__d_q_in 
            = vlSelf->tb_nr2_isolated__DOT__d_q;
        co_await vlSelf->__VtrigSched_h4dfc4760__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_nr2_isolated.clk)", 
                                                           "tb/tb_nr2_isolated.v", 
                                                           61);
        vlSelf->tb_nr2_isolated__DOT__lambda_in = (0xffffU 
                                                   & __Vtask_tb_nr2_isolated__DOT__run_vector__0__d_q_in);
        vlSelf->tb_nr2_isolated__DOT__x_in = 0U;
        vlSelf->tb_nr2_isolated__DOT__d_in = 0U;
        vlSelf->tb_nr2_isolated__DOT__sample_en = 1U;
        co_await vlSelf->__VtrigSched_h4dfc46b1__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_nr2_isolated.clk)", 
                                                           "tb/tb_nr2_isolated.v", 
                                                           67);
        co_await vlSelf->__VtrigSched_h4dfc4760__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_nr2_isolated.clk)", 
                                                           "tb/tb_nr2_isolated.v", 
                                                           68);
        vlSelf->tb_nr2_isolated__DOT__sample_en = 0U;
        co_await vlSelf->__VtrigSched_h4dfc46b1__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_nr2_isolated.clk)", 
                                                           "tb/tb_nr2_isolated.v", 
                                                           71);
        co_await vlSelf->__VtrigSched_h4dfc46b1__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_nr2_isolated.clk)", 
                                                           "tb/tb_nr2_isolated.v", 
                                                           72);
        co_await vlSelf->__VtrigSched_h4dfc46b1__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_nr2_isolated.clk)", 
                                                           "tb/tb_nr2_isolated.v", 
                                                           73);
        co_await vlSelf->__VdlySched.delay(0x3e8ULL, 
                                           nullptr, 
                                           "tb/tb_nr2_isolated.v", 
                                           74);
        vlSelf->tb_nr2_isolated__DOT__x2_signed = (
                                                   ((- (IData)(
                                                               (1U 
                                                                & ((IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x2) 
                                                                   >> 0xfU)))) 
                                                    << 0x10U) 
                                                   | (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x2));
        vlSelf->tb_nr2_isolated__DOT__d_float = (VL_ISTOR_D_I(32, __Vtask_tb_nr2_isolated__DOT__run_vector__0__d_q_in) 
                                                 / 3.27680000000000000e+04);
        vlSelf->tb_nr2_isolated__DOT__true_inv = (1.0 
                                                  / vlSelf->tb_nr2_isolated__DOT__d_float);
        vlSelf->tb_nr2_isolated__DOT__hw_inv = (VL_ISTOR_D_I(32, vlSelf->tb_nr2_isolated__DOT__x2_signed) 
                                                / 1.63840000000000000e+04);
        vlSelf->tb_nr2_isolated__DOT__err = (vlSelf->tb_nr2_isolated__DOT__true_inv 
                                             - vlSelf->tb_nr2_isolated__DOT__hw_inv);
        if ((vlSelf->tb_nr2_isolated__DOT__err < 0.0)) {
            vlSelf->tb_nr2_isolated__DOT__err = (- vlSelf->tb_nr2_isolated__DOT__err);
        }
        if ((vlSelf->tb_nr2_isolated__DOT__err > tb_nr2_isolated__DOT__max_err)) {
            tb_nr2_isolated__DOT__max_err = vlSelf->tb_nr2_isolated__DOT__err;
            tb_nr2_isolated__DOT__worst_d = vlSelf->tb_nr2_isolated__DOT__d_float;
            tb_nr2_isolated__DOT__worst_hw = vlSelf->tb_nr2_isolated__DOT__hw_inv;
            tb_nr2_isolated__DOT__worst_true = vlSelf->tb_nr2_isolated__DOT__true_inv;
        }
        VL_WRITEF_NX("D=0x%04x D=%0.6f true_inv=%0.6f hw_inv=%0.6f error=%0.6f\n",0,
                     16,(0xffffU & __Vtask_tb_nr2_isolated__DOT__run_vector__0__d_q_in),
                     64,vlSelf->tb_nr2_isolated__DOT__d_float,
                     64,vlSelf->tb_nr2_isolated__DOT__true_inv,
                     64,vlSelf->tb_nr2_isolated__DOT__hw_inv,
                     64,vlSelf->tb_nr2_isolated__DOT__err);
        tb_nr2_isolated__DOT__idx = ((IData)(1U) + tb_nr2_isolated__DOT__idx);
    }
    __Vtask_tb_nr2_isolated__DOT__run_vector__1__d_q_in = 0x7fffU;
    co_await vlSelf->__VtrigSched_h4dfc4760__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_nr2_isolated.clk)", 
                                                       "tb/tb_nr2_isolated.v", 
                                                       61);
    vlSelf->tb_nr2_isolated__DOT__lambda_in = (0xffffU 
                                               & __Vtask_tb_nr2_isolated__DOT__run_vector__1__d_q_in);
    vlSelf->tb_nr2_isolated__DOT__x_in = 0U;
    vlSelf->tb_nr2_isolated__DOT__d_in = 0U;
    vlSelf->tb_nr2_isolated__DOT__sample_en = 1U;
    co_await vlSelf->__VtrigSched_h4dfc46b1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_nr2_isolated.clk)", 
                                                       "tb/tb_nr2_isolated.v", 
                                                       67);
    co_await vlSelf->__VtrigSched_h4dfc4760__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_nr2_isolated.clk)", 
                                                       "tb/tb_nr2_isolated.v", 
                                                       68);
    vlSelf->tb_nr2_isolated__DOT__sample_en = 0U;
    co_await vlSelf->__VtrigSched_h4dfc46b1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_nr2_isolated.clk)", 
                                                       "tb/tb_nr2_isolated.v", 
                                                       71);
    co_await vlSelf->__VtrigSched_h4dfc46b1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_nr2_isolated.clk)", 
                                                       "tb/tb_nr2_isolated.v", 
                                                       72);
    co_await vlSelf->__VtrigSched_h4dfc46b1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_nr2_isolated.clk)", 
                                                       "tb/tb_nr2_isolated.v", 
                                                       73);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_nr2_isolated.v", 
                                       74);
    vlSelf->tb_nr2_isolated__DOT__x2_signed = (((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x2) 
                                                               >> 0xfU)))) 
                                                << 0x10U) 
                                               | (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x2));
    vlSelf->tb_nr2_isolated__DOT__d_float = (VL_ISTOR_D_I(32, __Vtask_tb_nr2_isolated__DOT__run_vector__1__d_q_in) 
                                             / 3.27680000000000000e+04);
    vlSelf->tb_nr2_isolated__DOT__true_inv = (1.0 / vlSelf->tb_nr2_isolated__DOT__d_float);
    vlSelf->tb_nr2_isolated__DOT__hw_inv = (VL_ISTOR_D_I(32, vlSelf->tb_nr2_isolated__DOT__x2_signed) 
                                            / 1.63840000000000000e+04);
    vlSelf->tb_nr2_isolated__DOT__err = (vlSelf->tb_nr2_isolated__DOT__true_inv 
                                         - vlSelf->tb_nr2_isolated__DOT__hw_inv);
    if ((vlSelf->tb_nr2_isolated__DOT__err < 0.0)) {
        vlSelf->tb_nr2_isolated__DOT__err = (- vlSelf->tb_nr2_isolated__DOT__err);
    }
    if ((vlSelf->tb_nr2_isolated__DOT__err > tb_nr2_isolated__DOT__max_err)) {
        tb_nr2_isolated__DOT__max_err = vlSelf->tb_nr2_isolated__DOT__err;
        tb_nr2_isolated__DOT__worst_d = vlSelf->tb_nr2_isolated__DOT__d_float;
        tb_nr2_isolated__DOT__worst_hw = vlSelf->tb_nr2_isolated__DOT__hw_inv;
        tb_nr2_isolated__DOT__worst_true = vlSelf->tb_nr2_isolated__DOT__true_inv;
    }
    VL_WRITEF_NX("D=0x%04x D=%0.6f true_inv=%0.6f hw_inv=%0.6f error=%0.6f\n\nMAX_ERR=%0.6f worst_D=%0.6f true_inv=%0.6f hw_inv=%0.6f\n",0,
                 16,(0xffffU & __Vtask_tb_nr2_isolated__DOT__run_vector__1__d_q_in),
                 64,vlSelf->tb_nr2_isolated__DOT__d_float,
                 64,vlSelf->tb_nr2_isolated__DOT__true_inv,
                 64,vlSelf->tb_nr2_isolated__DOT__hw_inv,
                 64,vlSelf->tb_nr2_isolated__DOT__err,
                 64,tb_nr2_isolated__DOT__max_err,64,
                 tb_nr2_isolated__DOT__worst_d,64,tb_nr2_isolated__DOT__worst_true,
                 64,tb_nr2_isolated__DOT__worst_hw);
    if (VL_LIKELY((tb_nr2_isolated__DOT__max_err < 1.00000000000000002e-02))) {
        VL_WRITEF_NX("NR2_SWEEP_PASS\n",0);
    } else {
        VL_WRITEF_NX("NR2_SWEEP_FAIL\n",0);
        VL_FINISH_MT("tb/tb_nr2_isolated.v", 131, "");
    }
    VL_FINISH_MT("tb/tb_nr2_isolated.v", 134, "");
}

VL_INLINE_OPT VlCoroutine Vtb_nr2_isolated___024root___eval_initial__TOP__Vtiming__1(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb/tb_nr2_isolated.v", 
                                           55);
        vlSelf->tb_nr2_isolated__DOT__clk = (1U & (~ (IData)(vlSelf->tb_nr2_isolated__DOT__clk)));
    }
}

void Vtb_nr2_isolated___024root___eval_act(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___eval_act\n"); );
}

void Vtb_nr2_isolated___024root___nba_sequent__TOP__0(Vtb_nr2_isolated___024root* vlSelf);

void Vtb_nr2_isolated___024root___eval_nba(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_nr2_isolated___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_nr2_isolated___024root___nba_sequent__TOP__0(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v8;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v8 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v9;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v9 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v10;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v10 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v11;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v11 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v12;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v12 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v13;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v13 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v14;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v14 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v15;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v15 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v8;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v8 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v9;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v9 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v10;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v10 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v11;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v11 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v12;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v12 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v13;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v13 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v14;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v14 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v15;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v15 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v0;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v0 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v1;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v1 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v2;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v2 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v3;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v3 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v4;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v4 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v5;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v5 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v6;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v6 = 0;
    SData/*15:0*/ __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v7;
    __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v7 = 0;
    SData/*15:0*/ __Vdly__tb_nr2_isolated__DOT__dut__DOT__p_scalar;
    __Vdly__tb_nr2_isolated__DOT__dut__DOT__p_scalar = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v0;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v8;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v8 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v0;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v8;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v8 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v0;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v1;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v2;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v3;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v4;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v5;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v6;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v7;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v8;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v8 = 0;
    // Body
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v0 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v8 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v0 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v8 = 0U;
    __Vdly__tb_nr2_isolated__DOT__dut__DOT__p_scalar 
        = vlSelf->tb_nr2_isolated__DOT__dut__DOT__p_scalar;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v0 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v1 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v2 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v3 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v4 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v5 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v6 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v7 = 0U;
    __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v8 = 0U;
    if (vlSelf->tb_nr2_isolated__DOT__rst_n) {
        if ((1U & (~ (IData)(vlSelf->tb_nr2_isolated__DOT__srst)))) {
            if (vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_p1_valid) {
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__p_scalar)), 
                                  VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x2)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom 
                    = VL_SHIFTRS_III(32,32,32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom, 0xeU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__leak_factor)), 
                                  VL_EXTENDS_II(32,16, 
                                                vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                [0U]));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                           VL_EXTENDS_II(32,16, 
                                                                         (0xffffU 
                                                                          & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom)), 
                                                           VL_EXTENDS_II(32,16, 
                                                                         vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1
                                                                         [0U])), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err 
                    = ((0U != (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted))
                        ? (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted)
                        : (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke, 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err))), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum 
                    = ((((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                           >> 0x1eU)))) 
                         << 0x10U) | (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                                 >> 0xfU))) 
                       + (((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                                             >> 0xfU)))) 
                           << 0x10U) | (0xffffU & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke)));
                __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v0 = 1U;
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__leak_factor)), 
                                  VL_EXTENDS_II(32,16, 
                                                vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                [1U]));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                           VL_EXTENDS_II(32,16, 
                                                                         (0xffffU 
                                                                          & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom)), 
                                                           VL_EXTENDS_II(32,16, 
                                                                         vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1
                                                                         [1U])), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err 
                    = ((0U != (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted))
                        ? (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted)
                        : (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke, 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err))), 0xfU);
                __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v0 
                    = (VL_LTS_III(32, 0x7fffU, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                        ? 0x7fffU : (VL_GTS_III(32, 0xffff8000U, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                                      ? 0x8000U : (0xffffU 
                                                   & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum 
                    = ((((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                           >> 0x1eU)))) 
                         << 0x10U) | (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                                 >> 0xfU))) 
                       + (((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                                             >> 0xfU)))) 
                           << 0x10U) | (0xffffU & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke)));
                __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v1 = 1U;
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__leak_factor)), 
                                  VL_EXTENDS_II(32,16, 
                                                vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                [2U]));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                           VL_EXTENDS_II(32,16, 
                                                                         (0xffffU 
                                                                          & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom)), 
                                                           VL_EXTENDS_II(32,16, 
                                                                         vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1
                                                                         [2U])), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err 
                    = ((0U != (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted))
                        ? (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted)
                        : (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke, 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err))), 0xfU);
                __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v1 
                    = (VL_LTS_III(32, 0x7fffU, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                        ? 0x7fffU : (VL_GTS_III(32, 0xffff8000U, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                                      ? 0x8000U : (0xffffU 
                                                   & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum 
                    = ((((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                           >> 0x1eU)))) 
                         << 0x10U) | (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                                 >> 0xfU))) 
                       + (((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                                             >> 0xfU)))) 
                           << 0x10U) | (0xffffU & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke)));
                __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v2 = 1U;
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__leak_factor)), 
                                  VL_EXTENDS_II(32,16, 
                                                vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                [3U]));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                           VL_EXTENDS_II(32,16, 
                                                                         (0xffffU 
                                                                          & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom)), 
                                                           VL_EXTENDS_II(32,16, 
                                                                         vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1
                                                                         [3U])), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err 
                    = ((0U != (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted))
                        ? (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted)
                        : (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke, 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err))), 0xfU);
                __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v2 
                    = (VL_LTS_III(32, 0x7fffU, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                        ? 0x7fffU : (VL_GTS_III(32, 0xffff8000U, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                                      ? 0x8000U : (0xffffU 
                                                   & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum 
                    = ((((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                           >> 0x1eU)))) 
                         << 0x10U) | (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                                 >> 0xfU))) 
                       + (((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                                             >> 0xfU)))) 
                           << 0x10U) | (0xffffU & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke)));
                __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v3 = 1U;
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__leak_factor)), 
                                  VL_EXTENDS_II(32,16, 
                                                vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                [4U]));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                           VL_EXTENDS_II(32,16, 
                                                                         (0xffffU 
                                                                          & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom)), 
                                                           VL_EXTENDS_II(32,16, 
                                                                         vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1
                                                                         [4U])), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err 
                    = ((0U != (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted))
                        ? (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted)
                        : (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke, 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err))), 0xfU);
                __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v3 
                    = (VL_LTS_III(32, 0x7fffU, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                        ? 0x7fffU : (VL_GTS_III(32, 0xffff8000U, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                                      ? 0x8000U : (0xffffU 
                                                   & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum 
                    = ((((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                           >> 0x1eU)))) 
                         << 0x10U) | (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                                 >> 0xfU))) 
                       + (((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                                             >> 0xfU)))) 
                           << 0x10U) | (0xffffU & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke)));
                __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v4 = 1U;
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__leak_factor)), 
                                  VL_EXTENDS_II(32,16, 
                                                vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                [5U]));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                           VL_EXTENDS_II(32,16, 
                                                                         (0xffffU 
                                                                          & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom)), 
                                                           VL_EXTENDS_II(32,16, 
                                                                         vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1
                                                                         [5U])), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err 
                    = ((0U != (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted))
                        ? (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted)
                        : (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke, 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err))), 0xfU);
                __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v4 
                    = (VL_LTS_III(32, 0x7fffU, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                        ? 0x7fffU : (VL_GTS_III(32, 0xffff8000U, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                                      ? 0x8000U : (0xffffU 
                                                   & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum 
                    = ((((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                           >> 0x1eU)))) 
                         << 0x10U) | (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                                 >> 0xfU))) 
                       + (((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                                             >> 0xfU)))) 
                           << 0x10U) | (0xffffU & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke)));
                __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v5 = 1U;
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__leak_factor)), 
                                  VL_EXTENDS_II(32,16, 
                                                vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                [6U]));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                           VL_EXTENDS_II(32,16, 
                                                                         (0xffffU 
                                                                          & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom)), 
                                                           VL_EXTENDS_II(32,16, 
                                                                         vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1
                                                                         [6U])), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err 
                    = ((0U != (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted))
                        ? (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted)
                        : (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke, 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err))), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err 
                    = ((0U != (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted))
                        ? (IData)(vlSelf->tb_nr2_isolated__DOT__e_weighted)
                        : (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1));
                __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v5 
                    = (VL_LTS_III(32, 0x7fffU, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                        ? 0x7fffU : (VL_GTS_III(32, 0xffff8000U, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                                      ? 0x8000U : (0xffffU 
                                                   & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum 
                    = ((((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                           >> 0x1eU)))) 
                         << 0x10U) | (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                                 >> 0xfU))) 
                       + (((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                                             >> 0xfU)))) 
                           << 0x10U) | (0xffffU & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke)));
                __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v6 = 1U;
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__leak_factor)), 
                                  VL_EXTENDS_II(32,16, 
                                                vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                [7U]));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                           VL_EXTENDS_II(32,16, 
                                                                         (0xffffU 
                                                                          & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom)), 
                                                           VL_EXTENDS_II(32,16, 
                                                                         vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1
                                                                         [7U])), 0xfU);
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                    = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke, 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err))), 0xfU);
                __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v6 
                    = (VL_LTS_III(32, 0x7fffU, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                        ? 0x7fffU : (VL_GTS_III(32, 0xffff8000U, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                                      ? 0x8000U : (0xffffU 
                                                   & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum 
                    = ((((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                           >> 0x1eU)))) 
                         << 0x10U) | (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked 
                                                 >> 0xfU))) 
                       + (((- (IData)((1U & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke 
                                             >> 0xfU)))) 
                           << 0x10U) | (0xffffU & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke)));
                __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v7 
                    = (VL_LTS_III(32, 0x7fffU, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                        ? 0x7fffU : (VL_GTS_III(32, 0xffff8000U, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)
                                      ? 0x8000U : (0xffffU 
                                                   & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum)));
                __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v7 = 1U;
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_scalar_ext 
                    = (((- (IData)((1U & ((IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__p_scalar) 
                                          >> 0xfU)))) 
                        << 0x10U) | (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__p_scalar));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_new 
                    = (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_scalar_ext 
                       + VL_SHIFTRS_III(32,32,32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_scalar_ext, 7U));
                __Vdly__tb_nr2_isolated__DOT__dut__DOT__p_scalar 
                    = (VL_LTS_III(32, 0x7fffU, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_new)
                        ? 0x7fffU : (VL_GTS_III(32, 1U, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_new)
                                      ? 1U : (0xffffU 
                                              & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_new)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__Dx1 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,17, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_denom_p1)), 
                                  VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x1)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__Dx1_q214 
                    = (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__Dx1 
                                  >> 0xfU));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__residual2 
                    = (0xffffU & ((IData)(0x7fffU) 
                                  - (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__Dx1_q214)));
                vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x2 
                    = (0xffffU & VL_SHIFTRS_III(16,16,32, 
                                                (0xffffU 
                                                 & VL_MULS_III(16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x1), (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__residual2))), 0xeU));
            }
        }
    } else {
        __Vdly__tb_nr2_isolated__DOT__dut__DOT__p_scalar = 0x800U;
        __VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v8 = 1U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x2 = 0U;
    }
    if ((1U & ((~ (IData)(vlSelf->tb_nr2_isolated__DOT__rst_n)) 
               | (IData)(vlSelf->tb_nr2_isolated__DOT__srst)))) {
        __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v0 = 1U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1 = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_denom_p1 = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x1 = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__y_acc = 0ULL;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__xTx_acc = 0ULL;
        __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v0 = 1U;
    } else {
        if (vlSelf->tb_nr2_isolated__DOT__dut__DOT__s1_valid) {
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v8 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [0U];
            __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v8 = 1U;
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v9 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [1U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v10 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [2U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v11 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [3U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v12 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [4U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v13 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [5U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v14 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [6U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v15 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [7U];
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg_p1 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg;
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__lambda_ext 
                = ((0U == (IData)(vlSelf->tb_nr2_isolated__DOT__lambda_in))
                    ? 0x7f00U : (IData)(vlSelf->tb_nr2_isolated__DOT__lambda_in));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__p_scalar_ext 
                = (((- (IData)((1U & ((IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__p_scalar) 
                                      >> 0xfU)))) << 0x10U) 
                   | (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__p_scalar));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__xTx_q15 
                = (((- (IData)((1U & (IData)((vlSelf->tb_nr2_isolated__DOT__dut__DOT__xTx_acc 
                                              >> 0x1eU))))) 
                    << 0x10U) | (0xffffU & (IData)(
                                                   (vlSelf->tb_nr2_isolated__DOT__dut__DOT__xTx_acc 
                                                    >> 0xfU))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom_prod 
                = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__p_scalar_ext), 
                              VL_EXTENDS_QI(64,32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__xTx_q15));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom_prod_shift 
                = VL_SHIFTRS_QQI(64,64,32, vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom_prod, 0xfU);
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom_prod_q15 
                = (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom_prod_shift);
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom 
                = (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__lambda_ext 
                   + vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom_prod_q15);
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__d_norm 
                = (((vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom 
                     >> 0x1fU) | (0U == vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom))
                    ? 0x4000U : (0xffffU & vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_denom_p1 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__d_norm;
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__lut_idx 
                = (0x1fU & ((IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__d_norm) 
                            >> 0xaU));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__x0 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_lut
                [vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__lut_idx];
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__Dx0 
                = VL_MULS_III(32, VL_EXTENDS_II(32,17, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__d_norm)), 
                              VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__x0)));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__Dx0_q214 
                = (0xffffU & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__Dx0 
                              >> 0xfU));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__residual1 
                = (0xffffU & ((IData)(0x7fffU) - (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__Dx0_q214)));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_x1 
                = (0xffffU & VL_SHIFTRS_III(16,16,32, 
                                            (0xffffU 
                                             & VL_MULS_III(16, (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__x0), (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__residual1))), 0xeU));
        }
        if (vlSelf->tb_nr2_isolated__DOT__sample_en) {
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__e_reg 
                = (0xffffU & ((IData)(vlSelf->tb_nr2_isolated__DOT__d_in) 
                              - (IData)((vlSelf->tb_nr2_isolated__DOT__dut__DOT__y_acc 
                                         >> 0xfU))));
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v8 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [6U];
            __VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v8 = 1U;
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v9 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [5U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v10 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [4U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v11 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [3U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v12 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [2U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v13 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [1U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v14 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                [0U];
            __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v15 
                = vlSelf->tb_nr2_isolated__DOT__x_in;
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                = (0xffffffffffULL & VL_MULS_QQQ(40, 
                                                 (0xffffffffffULL 
                                                  & VL_EXTENDS_QI(40,16, 
                                                                  vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                                  [0U])), 
                                                 (0xffffffffffULL 
                                                  & VL_EXTENDS_QI(40,16, 
                                                                  vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                  [0U]))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                = (0xffffffffffULL & VL_MULS_QQQ(40, 
                                                 (0xffffffffffULL 
                                                  & VL_EXTENDS_QI(40,16, 
                                                                  vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                  [0U])), 
                                                 (0xffffffffffULL 
                                                  & VL_EXTENDS_QI(40,16, 
                                                                  vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                  [0U]))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                                     [1U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [1U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [1U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [1U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                                     [2U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [2U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [2U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [2U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                                     [3U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [3U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [3U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [3U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                                     [4U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [4U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [4U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [4U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                                     [5U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [5U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [5U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [5U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                                     [6U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [6U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [6U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [6U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__w
                                                                     [7U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [7U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                = (0xffffffffffULL & (vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                      + VL_MULS_QQQ(40, 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [7U])), 
                                                    (0xffffffffffULL 
                                                     & VL_EXTENDS_QI(40,16, 
                                                                     vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly
                                                                     [7U])))));
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__y_acc 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y;
            vlSelf->tb_nr2_isolated__DOT__dut__DOT__xTx_acc 
                = vlSelf->tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx;
        }
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v0) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[0U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[1U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[2U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[3U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[4U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[5U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[6U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[7U] = 0U;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v8) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[0U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v8;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[1U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v9;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[2U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v10;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[3U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v11;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[4U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v12;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[5U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v13;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[6U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v14;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly_p1[7U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly_p1__v15;
    }
    vlSelf->tb_nr2_isolated__DOT__dut__DOT__nr_p1_valid 
        = ((1U & (~ ((~ (IData)(vlSelf->tb_nr2_isolated__DOT__rst_n)) 
                     | (IData)(vlSelf->tb_nr2_isolated__DOT__srst)))) 
           && (IData)(vlSelf->tb_nr2_isolated__DOT__dut__DOT__s1_valid));
    vlSelf->tb_nr2_isolated__DOT__dut__DOT__p_scalar 
        = __Vdly__tb_nr2_isolated__DOT__dut__DOT__p_scalar;
    vlSelf->tb_nr2_isolated__DOT__dut__DOT__s1_valid 
        = ((1U & (~ ((~ (IData)(vlSelf->tb_nr2_isolated__DOT__rst_n)) 
                     | (IData)(vlSelf->tb_nr2_isolated__DOT__srst)))) 
           && (IData)(vlSelf->tb_nr2_isolated__DOT__sample_en));
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v0) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[0U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[1U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[2U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[3U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[4U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[5U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[6U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[7U] = 0U;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__x_dly__v8) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[7U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v8;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[6U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v9;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[5U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v10;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[4U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v11;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[3U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v12;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[2U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v13;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[1U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v14;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__x_dly[0U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__x_dly__v15;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v0) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[0U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v0;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v1) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[1U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v1;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v2) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[2U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v2;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v3) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[3U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v3;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v4) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[4U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v4;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v5) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[5U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v5;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v6) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[6U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v6;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v7) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[7U] 
            = __VdlyVal__tb_nr2_isolated__DOT__dut__DOT__w__v7;
    }
    if (__VdlySet__tb_nr2_isolated__DOT__dut__DOT__w__v8) {
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[0U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[1U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[2U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[3U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[4U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[5U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[6U] = 0U;
        vlSelf->tb_nr2_isolated__DOT__dut__DOT__w[7U] = 0U;
    }
}

void Vtb_nr2_isolated___024root___timing_resume(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h4dfc4760__0.resume("@(negedge tb_nr2_isolated.clk)");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h4dfc46b1__0.resume("@(posedge tb_nr2_isolated.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_nr2_isolated___024root___timing_commit(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h4dfc4760__0.commit("@(negedge tb_nr2_isolated.clk)");
    }
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h4dfc46b1__0.commit("@(posedge tb_nr2_isolated.clk)");
    }
}

void Vtb_nr2_isolated___024root___eval_triggers__act(Vtb_nr2_isolated___024root* vlSelf);

bool Vtb_nr2_isolated___024root___eval_phase__act(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_nr2_isolated___024root___eval_triggers__act(vlSelf);
    Vtb_nr2_isolated___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_nr2_isolated___024root___timing_resume(vlSelf);
        Vtb_nr2_isolated___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_nr2_isolated___024root___eval_phase__nba(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_nr2_isolated___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_nr2_isolated___024root___dump_triggers__nba(Vtb_nr2_isolated___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_nr2_isolated___024root___dump_triggers__act(Vtb_nr2_isolated___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_nr2_isolated___024root___eval(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_nr2_isolated___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_nr2_isolated.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_nr2_isolated___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_nr2_isolated.v", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_nr2_isolated___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_nr2_isolated___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_nr2_isolated___024root___eval_debug_assertions(Vtb_nr2_isolated___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_nr2_isolated__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_nr2_isolated___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
