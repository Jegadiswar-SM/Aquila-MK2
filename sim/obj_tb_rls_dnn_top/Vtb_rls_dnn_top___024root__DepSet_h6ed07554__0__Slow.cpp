// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rls_dnn_top.h for the primary calling header

#include "Vtb_rls_dnn_top__pch.h"
#include "Vtb_rls_dnn_top___024root.h"

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___eval_static(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___eval_final(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rls_dnn_top___024root___dump_triggers__stl(Vtb_rls_dnn_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_rls_dnn_top___024root___eval_phase__stl(Vtb_rls_dnn_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___eval_settle(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_rls_dnn_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_rls_dnn_top.v", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_rls_dnn_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rls_dnn_top___024root___dump_triggers__stl(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___stl_sequent__TOP__0(Vtb_rls_dnn_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___eval_stl(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_rls_dnn_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[0xdU] = 1U;
        vlSelf->__Vm_traceActivity[0xcU] = 1U;
        vlSelf->__Vm_traceActivity[0xbU] = 1U;
        vlSelf->__Vm_traceActivity[0xaU] = 1U;
        vlSelf->__Vm_traceActivity[9U] = 1U;
        vlSelf->__Vm_traceActivity[8U] = 1U;
        vlSelf->__Vm_traceActivity[7U] = 1U;
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___stl_sequent__TOP__0(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____VdfgRegularize_h739c3624_2_0 
        = ((5U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                         >> 4U))) | (6U <= (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                                  >> 4U))));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n 
        = ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst)) 
           & (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_awvalid 
        = (IData)(((0x20U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_wvalid 
        = (IData)(((0x20U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_awvalid 
        = (IData)(((0x10U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_wvalid 
        = (IData)(((0x10U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_awvalid 
        = (IData)(((0x40U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_wvalid 
        = (IData)(((0x40U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_awvalid 
        = (IData)(((0U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_wvalid 
        = (IData)(((0U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_awvalid 
        = (IData)(((0x30U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_wvalid 
        = (IData)(((0x30U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_arvalid 
        = (IData)(((0x30U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_arvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_latprof__s_axi_arvalid 
        = (IData)(((0x60U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_arvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full 
        = (0x1ffffU & (((0x10000U & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe
                                     [2U] << 1U)) | 
                        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe
                        [2U]) - VL_SHIFTR_III(17,17,32, 
                                              ((0x10000U 
                                                & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est) 
                                                   << 1U)) 
                                               | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est)), 4U)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__delta_e 
        = (0x1ffffU & (VL_GTS_III(16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error), (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev))
                        ? (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error)) 
                           - VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev)))
                        : (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev)) 
                           - VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error)))));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__recip_approx 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram
        [(0xfU & (IData)((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ref_power_acc 
                          >> 0x23U)))];
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__activity_cmp 
        = (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_A 
           > (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_B 
                                 >> (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__ratio_shift_reg))));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[0U] 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
        [0U];
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[1U] 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
        [1U];
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[2U] 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
        [2U];
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[3U] 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
        [3U];
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[4U] 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
        [4U];
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[5U] 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
        [5U];
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[6U] 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
        [6U];
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[7U] 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
        [7U];
    vlSelf->tb_rls_dnn_top__DOT__s_axis_tready = ((IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n) 
                                                  & ((IData)(vlSelf->tb_rls_dnn_top__DOT__sample_enable) 
                                                     & ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst)) 
                                                        & ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid)) 
                                                           | (IData)(vlSelf->tb_rls_dnn_top__DOT__m_axis_tready)))));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sample_consumed_cbpf 
        = ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axis_tvalid) 
           & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axis_tready) 
              & (IData)(vlSelf->tb_rls_dnn_top__DOT__sample_enable)));
}

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___eval_triggers__stl(Vtb_rls_dnn_top___024root* vlSelf);

VL_ATTR_COLD bool Vtb_rls_dnn_top___024root___eval_phase__stl(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_rls_dnn_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_rls_dnn_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rls_dnn_top___024root___dump_triggers__act(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_rls_dnn_top.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_rls_dnn_top.clk or negedge tb_rls_dnn_top.rst_n)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge tb_rls_dnn_top.clk or negedge tb_rls_dnn_top.dut.__Vcellinp__u_aad__rst_n)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge tb_rls_dnn_top.clk)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rls_dnn_top___024root___dump_triggers__nba(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_rls_dnn_top.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_rls_dnn_top.clk or negedge tb_rls_dnn_top.rst_n)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge tb_rls_dnn_top.clk or negedge tb_rls_dnn_top.dut.__Vcellinp__u_aad__rst_n)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge tb_rls_dnn_top.clk)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___ctor_var_reset(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_rls_dnn_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__sample_enable = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__s_axis_tvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__s_axis_tready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__m_axis_tdata = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__m_axis_tready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr = VL_RAND_RESET_I(8);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr = VL_RAND_RESET_I(8);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__s_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__clk_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__sample_idx = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__sin_val = 0;
    vlSelf->tb_rls_dnn_top__DOT__noise_val = 0;
    vlSelf->tb_rls_dnn_top__DOT__d_sample = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__x_sample = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__sin_lut__Vstatic__angle = 0;
    vlSelf->tb_rls_dnn_top__DOT__out_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__pass_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__x_cbpf = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_y_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_clip_s1 = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_clip_s2 = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_signal_active = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_clk_gate_en = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_ref_channel_fault = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_x_out_muxed = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_y_hat = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_valid_out = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_fsm_state_dbg = VL_RAND_RESET_I(2);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_valid_out = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_irq_fault = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__poly_rls_en = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__poly_decim_cnt_dbg = VL_RAND_RESET_I(3);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_ratio = VL_RAND_RESET_I(3);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sample_consumed_cbpf = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_en = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__fwes_e_weighted = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_arvalid = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_vld_pipe[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full = VL_RAND_RESET_I(17);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__latprof_rvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__latprof_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_latprof__s_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_leak_factor = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__fwes_alpha_reg = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_awready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_wready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_awready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_wready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_awready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_wready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_awready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_wready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_awready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_wready = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vlvbound_h2eb1b900__1 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vlvbound_h6be89c00__1 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vlvbound_h960a4189__1 = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____VdfgRegularize_h739c3624_2_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_poly__DOT__decim_cnt = VL_RAND_RESET_I(3);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__bypass_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a1_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a2_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b0_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b1_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b2_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s1_trunc = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg1 = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg2 = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a1_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a2_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b0_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b1_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b2_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2_trunc = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg1 = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg2 = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_A_dbg = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_B_dbg = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__ratio_shift_reg = VL_RAND_RESET_I(4);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__x_sq = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__mul_tmp = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_A = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_B = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__activity_cmp = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__assert_cnt = VL_RAND_RESET_I(3);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__deassert_cnt = VL_RAND_RESET_I(7);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_threshold = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ratio_shift = VL_RAND_RESET_I(4);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_acc = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ref_power_acc = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_dx = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_xx = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__recip_approx = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__nr_term = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__nr_prod = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_nr1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_nr2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__norm_corr_prod = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_norm = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__fault_cnt = VL_RAND_RESET_I(8);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__recover_cnt = VL_RAND_RESET_I(8);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_fwes__DOT__e_w_prev = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_fwes__DOT__unnamedblk1__DOT__alpha_term = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__p_scalar = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__y_acc = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__xTx_acc = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__e_reg = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__s1_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__mul_tmp = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_denom_p1 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_x1 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_x2 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p1_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p2_valid = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__e_reg_p1 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe_p1 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__d_norm = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__lut_idx = VL_RAND_RESET_I(3);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__x0 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__Dx0 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__residual1 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__Dx1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__residual2 = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_new = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_slow = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_mid = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_fast = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_up_reg = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_down_reg = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__next_state = VL_RAND_RESET_I(2);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__delta_e = VL_RAND_RESET_I(17);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up = VL_RAND_RESET_I(3);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down = VL_RAND_RESET_I(4);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt = VL_RAND_RESET_I(6);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w1_rom[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w2_rom[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b3_rom[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h1[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s0_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__mul_s0 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s1_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__mul_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__mul_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER1__DOT__L1_COMPUTE__DOT__n = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER1__DOT__L1_COMPUTE__DOT__k = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER1__DOT__L1_COMPUTE__DOT__acc = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER2__DOT__L2_COMPUTE__DOT__n = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER2__DOT__L2_COMPUTE__DOT__k = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER2__DOT__L2_COMPUTE__DOT__acc = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER3__DOT__L3_COMPUTE__DOT__k = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER3__DOT__L3_COMPUTE__DOT__acc = VL_RAND_RESET_Q(40);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__last_sample = VL_RAND_RESET_I(16);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt = VL_RAND_RESET_I(5);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault = VL_RAND_RESET_I(1);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_type_reg = VL_RAND_RESET_I(2);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_sample_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg = VL_RAND_RESET_I(8);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state = VL_RAND_RESET_I(2);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__drain_cnt = VL_RAND_RESET_I(3);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_cbpf = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_rls = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_ptdl = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_mlp = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_output = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_cbpf_to_rls = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_rls_to_ptdl = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_ptdl_to_mlp = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_mlp_to_out = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_total = VL_RAND_RESET_I(32);
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt_snap = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__clk_cnt = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v6 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v7 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v8 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v9 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v10 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v11 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v0 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v1 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v2 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v3 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v4 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v5 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v6 = VL_RAND_RESET_I(16);
    vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v7 = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg2 = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2 = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s2 = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__rcim_ref_channel_fault = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v0 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v6 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v7 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v8 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v9 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v10 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v11 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v0 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v8 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v0 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v1 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v2 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v3 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v4 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v5 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v6 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v7 = 0;
    vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v8 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_rls_dnn_top__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rls_dnn_top__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 14; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
