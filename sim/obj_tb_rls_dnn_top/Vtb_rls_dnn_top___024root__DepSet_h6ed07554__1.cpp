// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rls_dnn_top.h for the primary calling header

#include "Vtb_rls_dnn_top__pch.h"
#include "Vtb_rls_dnn_top___024root.h"

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_sequent__TOP__2(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*1:0*/ __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state = 0;
    CData/*2:0*/ __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up = 0;
    CData/*3:0*/ __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down = 0;
    SData/*15:0*/ __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt = 0;
    CData/*4:0*/ __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt = 0;
    // Body
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state;
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg;
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt;
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state;
    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault;
    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt 
        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt;
    if (vlSelf->tb_rls_dnn_top__DOT__rst_n) {
        if (vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid) {
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt 
                = ((IData)(1U) + vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt);
            __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt = 0x200U;
            __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt 
                = (((IData)(vlSelf->tb_rls_dnn_top__DOT__m_axis_tdata) 
                    == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__last_sample))
                    ? (0x1fU & ((0x1fU == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt))
                                 ? (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt)
                                 : ((IData)(1U) + (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt))))
                    : 0U);
            if ((0xfU <= (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt))) {
                vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault = 1U;
            }
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__last_sample 
                = vlSelf->tb_rls_dnn_top__DOT__m_axis_tdata;
        } else if ((0U != (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt))) {
            __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt 
                = (0xffffU & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt) 
                              - (IData)(1U)));
        }
        if ((0U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt))) {
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault = 1U;
        } else if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst) {
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault = 0U;
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst) {
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault = 0U;
            __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt = 0U;
        }
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rvalid = 0U;
        if (((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_arvalid) 
             & (0U == (0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))))) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_irq_fault = 0U;
        }
        if (((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_bvalid) 
             & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_bready))) {
            vlSelf->tb_rls_dnn_top__DOT__s_axi_bvalid = 0U;
        } else if ((((((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_awready) 
                       | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_awready) 
                          | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_awready) 
                             | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_awready) 
                                | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_awready) 
                                   | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____VdfgRegularize_h739c3624_2_0)))))) 
                      & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid)) 
                     & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_wready) 
                        | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_wready) 
                           | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_wready) 
                              | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_wready) 
                                 | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_wready) 
                                    | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____VdfgRegularize_h739c3624_2_0))))))) 
                    & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid))) {
            vlSelf->tb_rls_dnn_top__DOT__s_axi_bvalid = 1U;
            vlSelf->tb_rls_dnn_top__DOT__s_axi_bresp 
                = ((6U <= (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                 >> 4U))) ? 2U : 0U);
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active) {
            if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_valid_out) {
                if ((0U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt))) {
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active = 0U;
                    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state 
                        = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__next_state;
                } else {
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt 
                        = (0x3fU & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt) 
                                    - (IData)(1U)));
                }
            }
        } else if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_valid_out) {
            if ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__delta_e 
                 > (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_up_reg))) {
                __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up 
                    = (7U & ((7U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up))
                              ? (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up)
                              : ((IData)(1U) + (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up))));
                __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down = 0U;
            } else if ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__delta_e 
                        < (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_down_reg))) {
                __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down)));
                __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up = 0U;
            } else {
                __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up = 0U;
                __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down = 0U;
            }
            if ((0U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state))) {
                if ((3U <= (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up))) {
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active = 1U;
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt = 0x20U;
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__next_state = 1U;
                    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state = 3U;
                }
            } else if ((1U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state))) {
                if ((3U <= (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up))) {
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active = 1U;
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt = 0x20U;
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__next_state = 2U;
                    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state = 3U;
                } else if ((8U <= (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down))) {
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active = 1U;
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt = 0x20U;
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__next_state = 0U;
                    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state = 3U;
                }
            } else if ((2U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state))) {
                if ((8U <= (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down))) {
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active = 1U;
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt = 0x20U;
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__next_state = 1U;
                    __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state = 3U;
                }
            }
        }
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out 
            = ((0U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state))
                ? (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_slow)
                : ((1U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state))
                    ? (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_mid)
                    : ((2U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state))
                        ? (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_fast)
                        : (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_fsm_state_dbg 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state;
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_valid_out) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error;
        }
        if (((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_rvalid) 
             & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_rready))) {
            vlSelf->tb_rls_dnn_top__DOT__s_axi_rvalid = 0U;
        } else if (vlSelf->tb_rls_dnn_top__DOT__s_axi_arvalid) {
            vlSelf->tb_rls_dnn_top__DOT__s_axi_rvalid = 1U;
            vlSelf->tb_rls_dnn_top__DOT__s_axi_rresp = 0U;
            vlSelf->tb_rls_dnn_top__DOT__s_axi_rdata 
                = ((3U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr) 
                                 >> 4U))) ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rdata
                    : ((6U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr) 
                                     >> 4U))) ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__latprof_rdata
                        : 0U));
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_arvalid) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rvalid = 1U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rdata 
                = ((0U == (0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr)))
                    ? (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_type_reg)
                    : ((4U == (0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr)))
                        ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_sample_cnt
                        : ((8U == (0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr)))
                            ? (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg)
                            : 0U)));
        }
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_wready = 0U;
        if (((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_awvalid) 
             & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_wvalid))) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_awready = 1U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_wready = 1U;
            if ((0U != (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr)))) {
                if ((4U != (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr)))) {
                    if ((8U != (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr)))) {
                        if ((0xcU == (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr)))) {
                            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_up_reg 
                                = (0xffffU & vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata);
                        }
                        if ((0xcU != (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr)))) {
                            if ((0x10U == (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr)))) {
                                vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_down_reg 
                                    = (0xffffU & vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata);
                            }
                        }
                    }
                    if ((8U == (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr)))) {
                        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_fast 
                            = (0xffffU & vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata);
                    }
                }
                if ((4U == (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr)))) {
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_mid 
                        = (0xffffU & vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata);
                }
            }
            if ((0U == (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr)))) {
                vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_slow 
                    = (0xffffU & vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata);
            }
        }
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_wready = 0U;
        if ((((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_awvalid) 
              & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_wvalid)) 
             & (0xcU == (0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))))) {
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg = 0U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_awready = 1U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_wready = 1U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_type_reg = 0U;
        }
    } else {
        vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt = 0U;
        __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt = 0x200U;
        vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault = 0U;
        __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt = 0U;
        vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rvalid = 0U;
        vlSelf->tb_rls_dnn_top__DOT__s_axi_bvalid = 0U;
        vlSelf->tb_rls_dnn_top__DOT__s_axi_bresp = 0U;
        __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up = 0U;
        __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__next_state = 0U;
        __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out = 0x7f00U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_fsm_state_dbg = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev = 0U;
        vlSelf->tb_rls_dnn_top__DOT__s_axi_rdata = 0U;
        vlSelf->tb_rls_dnn_top__DOT__s_axi_rvalid = 0U;
        vlSelf->tb_rls_dnn_top__DOT__s_axi_rresp = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__last_sample = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_wready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_wready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_up_reg = 0x200U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_down_reg = 0x80U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_slow = 0x7f00U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_mid = 0x7e00U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_fast = 0x7800U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rdata = 0U;
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt 
        = __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt 
        = __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state 
        = __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up 
        = __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down 
        = __Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down;
}

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_comb__TOP__0(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____VdfgRegularize_h739c3624_2_0 
        = ((5U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                         >> 4U))) | (6U <= (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                                  >> 4U))));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_awvalid 
        = (IData)(((0U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_wvalid 
        = (IData)(((0U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_arvalid 
        = (IData)(((0x30U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_arvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_awvalid 
        = (IData)(((0x30U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_wvalid 
        = (IData)(((0x30U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid)));
}

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_sequent__TOP__3(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_sequent__TOP__3\n"); );
    // Body
    if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_wready = 0U;
        if ((((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_awvalid) 
              & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_wvalid)) 
             & (0U == (0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))))) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_awready = 1U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_wready = 1U;
        }
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_wready = 0U;
        if ((((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_awvalid) 
              & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_wvalid)) 
             & (0U == (0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))))) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_awready = 1U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_wready = 1U;
        }
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_wready = 0U;
        if ((((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_awvalid) 
              & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_wvalid)) 
             & (0U == (0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))))) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_awready = 1U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_wready = 1U;
        }
    } else {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_awready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_wready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_wready = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_wready = 0U;
    }
}

extern const VlUnpacked<CData/*2:0*/, 256> Vtb_rls_dnn_top__ConstPool__TABLE_hb1da3477_0;
extern const VlUnpacked<CData/*2:0*/, 256> Vtb_rls_dnn_top__ConstPool__TABLE_h316d2865_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_rls_dnn_top__ConstPool__TABLE_h3d26ba60_0;
extern const VlUnpacked<CData/*2:0*/, 256> Vtb_rls_dnn_top__ConstPool__TABLE_h1b3639e7_0;

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_sequent__TOP__4(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_sequent__TOP__4\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*15:0*/ __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v8;
    __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v8 = 0;
    SData/*15:0*/ __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v9;
    __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v9 = 0;
    SData/*15:0*/ __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v10;
    __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v10 = 0;
    SData/*15:0*/ __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v11;
    __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v11 = 0;
    SData/*15:0*/ __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v12;
    __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v12 = 0;
    SData/*15:0*/ __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v13;
    __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v13 = 0;
    SData/*15:0*/ __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v14;
    __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v14 = 0;
    SData/*15:0*/ __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v15;
    __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v15 = 0;
    // Body
    if (vlSelf->tb_rls_dnn_top__DOT__rst_n) {
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error = 0U;
        } else if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p2_valid) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error 
                = (0xffffU & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe_p1) 
                              - (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_y_hat)));
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_latprof__s_axi_arvalid) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__latprof_rdata 
                = ((0x20U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                    ? ((0x10U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                        ? 0U : ((8U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                                 ? ((4U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                                     ? 0U : vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt)
                                 : ((4U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                                     ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_total
                                     : vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_mlp_to_out)))
                    : ((0x10U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                        ? ((8U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                            ? ((4U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                                ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_ptdl_to_mlp
                                : vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_rls_to_ptdl)
                            : ((4U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                                ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_cbpf_to_rls
                                : vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_output))
                        : ((8U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                            ? ((4U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                                ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_mlp
                                : vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_ptdl)
                            : ((4U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))
                                ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_rls
                                : vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_cbpf))));
        }
        if ((1U & (~ (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst)))) {
            if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_valid_out) {
                vlSelf->tb_rls_dnn_top__DOT__m_axis_tdata 
                    = (0xffffU & (((1U & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full 
                                          >> 0x10U)) 
                                   == (1U & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full 
                                             >> 0xfU)))
                                   ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full
                                   : ((0x10000U & vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full)
                                       ? 0x8000U : 0x7fffU)));
            }
        }
    } else {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__latprof_rdata = 0U;
        vlSelf->tb_rls_dnn_top__DOT__m_axis_tdata = 0U;
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full 
        = (0x1ffffU & (((0x10000U & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe
                                     [2U] << 1U)) | 
                        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe
                        [2U]) - VL_SHIFTR_III(17,17,32, 
                                              ((0x10000U 
                                                & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est) 
                                                   << 1U)) 
                                               | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est)), 4U)));
    if ((1U & (~ ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n)) 
                  | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst))))) {
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__s1_valid) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_y_hat 
                = ((0U != (0x3ffU & (IData)((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__y_acc 
                                             >> 0x1eU))))
                    ? 0x7fffU : (0xffffU & (IData)(
                                                   (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__y_acc 
                                                    >> 0xfU))));
        }
    }
    if ((1U & ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n)) 
               | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst)))) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe_p1 = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe = 0U;
    } else {
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__s1_valid) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe_p1 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe;
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_en) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly
                [5U];
        }
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[0U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[1U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[2U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[3U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[4U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[5U] = 0U;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v6) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[0U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v6;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v7) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[1U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v7;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v8) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[2U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v8;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v9) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[3U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v9;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v10) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[4U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v10;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v11) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[5U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__d_dly__v11;
    }
    if ((1U & ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n)) 
               | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst)))) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__y_acc = 0ULL;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__xTx_acc = 0ULL;
        vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v0 = 1U;
    } else if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_en) {
        __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v8 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
            [6U];
        vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v8 = 1U;
        __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v9 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
            [5U];
        __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v10 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
            [4U];
        __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v11 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
            [3U];
        __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v12 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
            [2U];
        __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v13 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
            [1U];
        __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v14 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
            [0U];
        __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v15 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_x_out_muxed;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
            = (0xffffffffffULL & VL_MULS_QQQ(40, (0xffffffffffULL 
                                                  & VL_EXTENDS_QI(40,16, 
                                                                  vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w
                                                                  [0U])), 
                                             (0xffffffffffULL 
                                              & VL_EXTENDS_QI(40,16, 
                                                              vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                              [0U]))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
            = (0xffffffffffULL & VL_MULS_QQQ(40, (0xffffffffffULL 
                                                  & VL_EXTENDS_QI(40,16, 
                                                                  vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                  [0U])), 
                                             (0xffffffffffULL 
                                              & VL_EXTENDS_QI(40,16, 
                                                              vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                              [0U]))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w
                                                                 [1U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [1U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [1U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [1U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w
                                                                 [2U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [2U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [2U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [2U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w
                                                                 [3U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [3U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [3U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [3U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w
                                                                 [4U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [4U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [4U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [4U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w
                                                                 [5U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [5U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [5U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [5U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w
                                                                 [6U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [6U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [6U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [6U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w
                                                                 [7U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [7U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
            = (0xffffffffffULL & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx 
                                  + VL_MULS_QQQ(40, 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [7U])), 
                                                (0xffffffffffULL 
                                                 & VL_EXTENDS_QI(40,16, 
                                                                 vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly
                                                                 [7U])))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__y_acc 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__xTx_acc 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[0U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[1U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[2U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[3U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[4U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[5U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[6U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[7U] = 0U;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v8) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[7U] 
            = __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v8;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[6U] 
            = __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v9;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[5U] 
            = __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v10;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[4U] 
            = __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v11;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[3U] 
            = __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v12;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[2U] 
            = __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v13;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[1U] 
            = __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v14;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[0U] 
            = __VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly__v15;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v0) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[0U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v0;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v1) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[1U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v1;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v2) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[2U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v2;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v3) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[3U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v3;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v4) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[4U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v4;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v5) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[5U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v5;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v6) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[6U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v6;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v7) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[7U] 
            = vlSelf->__VdlyVal__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v7;
    }
    if (vlSelf->__VdlySet__tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w__v8) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[0U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[1U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[2U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[3U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[4U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[5U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[6U] = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[7U] = 0U;
    }
    if (vlSelf->tb_rls_dnn_top__DOT__rst_n) {
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_valid_out) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_cbpf_to_rls 
                = (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_rls 
                   - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_cbpf);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_total 
                = (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_output 
                   - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_cbpf);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_rls_to_ptdl 
                = (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_ptdl 
                   - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_rls);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_ptdl_to_mlp 
                = (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_mlp 
                   - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_ptdl);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_mlp_to_out 
                = (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_output 
                   - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_mlp);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_mlp 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt;
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_y_valid) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_cbpf 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt;
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_valid_out) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_rls 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_ptdl 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt;
        }
        if (vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_output 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt;
        }
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt 
            = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt;
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst) {
            vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid = 0U;
        } else if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_valid_out) {
            vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid = 1U;
        } else if (vlSelf->tb_rls_dnn_top__DOT__m_axis_tready) {
            vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid = 0U;
        }
    } else {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_cbpf_to_rls = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_total = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_rls_to_ptdl = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_ptdl_to_mlp = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_mlp_to_out = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_cbpf = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_rls = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_ptdl = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_mlp = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_output = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt 
            = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt;
        vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid = 0U;
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_valid_out 
        = ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n) 
           && (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s1_valid));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s1_valid 
        = ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n) 
           && (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s0_valid));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s0_valid 
        = ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n) 
           && (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_valid_out));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_valid_out 
        = ((IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst))) 
               && (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p2_valid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p2_valid 
        = ((IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n) 
           && ((1U & (~ (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst))) 
               && (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p1_valid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p1_valid 
        = ((1U & (~ ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n)) 
                     | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst)))) 
           && (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__s1_valid));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__s1_valid 
        = ((1U & (~ ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n)) 
                     | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst)))) 
           && (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_en));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_en = 
        ((~ ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n)) 
             | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst))) 
         & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_y_valid) 
            & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_q)));
    if ((1U & ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n)) 
               | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst)))) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_q = 1U;
    } else if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sample_consumed_cbpf) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_q 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__poly_rls_en;
    }
    __Vtableidx1 = (((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_ratio) 
                     << 5U) | (((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_poly__DOT__decim_cnt) 
                                << 2U) | (((IData)(vlSelf->tb_rls_dnn_top__DOT__sample_enable) 
                                           << 1U) | (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n))));
    if (vlSelf->tb_rls_dnn_top__DOT__rst_n) {
        if (((IData)(((0x50U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                      & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid))) 
             & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid))) {
            if ((0U != (3U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                              >> 2U)))) {
                if ((1U != (3U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                  >> 2U)))) {
                    if ((2U == (3U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                      >> 2U)))) {
                        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_ratio 
                            = (7U & vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata);
                    }
                }
            }
        }
    } else {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_ratio = 1U;
    }
    if ((1U & Vtb_rls_dnn_top__ConstPool__TABLE_hb1da3477_0
         [__Vtableidx1])) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_poly__DOT__decim_cnt 
            = Vtb_rls_dnn_top__ConstPool__TABLE_h316d2865_0
            [__Vtableidx1];
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__poly_rls_en 
        = Vtb_rls_dnn_top__ConstPool__TABLE_h3d26ba60_0
        [__Vtableidx1];
    if ((4U & Vtb_rls_dnn_top__ConstPool__TABLE_hb1da3477_0
         [__Vtableidx1])) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__poly_decim_cnt_dbg 
            = Vtb_rls_dnn_top__ConstPool__TABLE_h1b3639e7_0
            [__Vtableidx1];
    }
}

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_comb__TOP__1(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_comb__TOP__1\n"); );
    // Body
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
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_latprof__s_axi_arvalid 
        = (IData)(((0x60U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_arvalid)));
}

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_comb__TOP__2(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_comb__TOP__2\n"); );
    // Body
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__delta_e 
        = (0x1ffffU & (VL_GTS_III(16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error), (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev))
                        ? (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error)) 
                           - VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev)))
                        : (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev)) 
                           - VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error)))));
}

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_sequent__TOP__5(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_sequent__TOP__5\n"); );
    // Body
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_y_valid 
        = ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n) 
           && (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg2));
    if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_x_out_muxed 
            = ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_ref_channel_fault)
                ? 0U : (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__x_cbpf));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__x_cbpf 
            = (0xffffU & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__bypass_reg)
                           ? (vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata 
                              >> 0x10U) : (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2_trunc)));
        if ((((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_awvalid) 
              & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_wvalid)) 
             & (0U == (0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))))) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__bypass_reg 
                = (1U & vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata);
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg2) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a1_s2 
                = VL_MULS_III(32, (IData)(0x7148U), vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s2);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a2_s2 
                = VL_MULS_III(32, (IData)(0xffffcaa1U), vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s2);
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg1) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_clip_s2 
                = ((0U != (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2 
                           >> 0x1eU)) & (3U != (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2 
                                                >> 0x1eU)));
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2 
                = ((VL_SHIFTRS_III(32,32,32, vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b0_s2, 0xfU) 
                    + VL_SHIFTRS_III(32,32,32, vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b1_s2, 0xfU)) 
                   + VL_SHIFTRS_III(32,32,32, vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b2_s2, 0xfU));
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b0_s2 
                = VL_MULS_III(32, (IData)(0x4000U), vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s2);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b1_s2 
                = VL_MULS_III(32, (IData)(0xffff8000U), vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s2);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b2_s2 
                = VL_MULS_III(32, (IData)(0x4000U), vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s2);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s2 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s2;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s2 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s2;
        }
        if (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg2) {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2_trunc 
                = (0xffffU & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2 
                              >> 0xeU));
        }
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg2 
            = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg1;
    } else {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_x_out_muxed = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__x_cbpf = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__bypass_reg = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s2 = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s2 = 0U;
        vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2 = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2_trunc = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg2 = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_clip_s2 = 0U;
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_ref_channel_fault 
        = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__rcim_ref_channel_fault;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s2 
        = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s2;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2 
        = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg1 
        = ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n) 
           && (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg2));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg2 
        = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg2;
}

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_sequent__TOP__6(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_sequent__TOP__6\n"); );
    // Body
    if (vlSelf->tb_rls_dnn_top__DOT__rst_n) {
        if ((2U & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state))) {
            if ((1U & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state))) {
                vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst = 0U;
                vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_irq_fault = 1U;
                vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state = 0U;
            } else {
                vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst = 1U;
                if ((7U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__drain_cnt))) {
                    vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state = 3U;
                } else {
                    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__drain_cnt 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__drain_cnt)));
                }
            }
        } else if ((1U & (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state))) {
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg)));
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__drain_cnt = 0U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_type_reg 
                = ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault)
                    ? 1U : 2U);
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_sample_cnt 
                = vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst = 1U;
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state = 2U;
        } else {
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst = 0U;
            vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_irq_fault = 0U;
            if (((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault) 
                 | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault))) {
                vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state = 1U;
            }
        }
    } else {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__drain_cnt = 0U;
        vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg = 0U;
        vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_irq_fault = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_type_reg = 0U;
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_sample_cnt = 0U;
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault 
        = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault 
        = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state 
        = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt 
        = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg 
        = vlSelf->__Vdly__tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg;
}

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_sequent__TOP__7(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_sequent__TOP__7\n"); );
    // Init
    SData/*15:0*/ __Vfunc_tb_rls_dnn_top__DOT__sin_lut__0__Vfuncout;
    __Vfunc_tb_rls_dnn_top__DOT__sin_lut__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_rls_dnn_top__DOT__sin_lut__0__idx;
    __Vfunc_tb_rls_dnn_top__DOT__sin_lut__0__idx = 0;
    SData/*15:0*/ __Vfunc_tb_rls_dnn_top__DOT__sin_lut__1__Vfuncout;
    __Vfunc_tb_rls_dnn_top__DOT__sin_lut__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_rls_dnn_top__DOT__sin_lut__1__idx;
    __Vfunc_tb_rls_dnn_top__DOT__sin_lut__1__idx = 0;
    // Body
    if (vlSelf->tb_rls_dnn_top__DOT__rst_n) {
        if (((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axis_tvalid) 
             & (~ (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axis_tready)))) {
            vlSelf->tb_rls_dnn_top__DOT__s_axis_tvalid = 1U;
        } else if (vlSelf->tb_rls_dnn_top__DOT__sample_enable) {
            __Vfunc_tb_rls_dnn_top__DOT__sin_lut__0__idx 
                = VL_MULS_III(32, (IData)(0xaU), vlSelf->tb_rls_dnn_top__DOT__sample_idx);
            vlSelf->tb_rls_dnn_top__DOT__sin_lut__Vstatic__angle 
                = ((6.28318530000000042e+00 * VL_ISTOR_D_I(32, 
                                                           (0xffU 
                                                            & __Vfunc_tb_rls_dnn_top__DOT__sin_lut__0__idx))) 
                   / 256.0);
            __Vfunc_tb_rls_dnn_top__DOT__sin_lut__0__Vfuncout 
                = (0xffffU & VL_RTOI_I_D((1.63830000000000000e+04 
                                          * sin(vlSelf->tb_rls_dnn_top__DOT__sin_lut__Vstatic__angle))));
            vlSelf->tb_rls_dnn_top__DOT__s_axis_tvalid = 1U;
            vlSelf->tb_rls_dnn_top__DOT__d_sample = __Vfunc_tb_rls_dnn_top__DOT__sin_lut__0__Vfuncout;
            __Vfunc_tb_rls_dnn_top__DOT__sin_lut__1__idx 
                = ((IData)(0xdU) + VL_MULS_III(32, (IData)(0xaU), vlSelf->tb_rls_dnn_top__DOT__sample_idx));
            vlSelf->tb_rls_dnn_top__DOT__sin_lut__Vstatic__angle 
                = ((6.28318530000000042e+00 * VL_ISTOR_D_I(32, 
                                                           (0xffU 
                                                            & __Vfunc_tb_rls_dnn_top__DOT__sin_lut__1__idx))) 
                   / 256.0);
            __Vfunc_tb_rls_dnn_top__DOT__sin_lut__1__Vfuncout 
                = (0xffffU & VL_RTOI_I_D((1.63830000000000000e+04 
                                          * sin(vlSelf->tb_rls_dnn_top__DOT__sin_lut__Vstatic__angle))));
            vlSelf->tb_rls_dnn_top__DOT__x_sample = __Vfunc_tb_rls_dnn_top__DOT__sin_lut__1__Vfuncout;
            vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata 
                = (VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__d_sample)) 
                   + VL_DIVS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_rls_dnn_top__DOT__x_sample)), (IData)(4U)));
            vlSelf->tb_rls_dnn_top__DOT__sample_idx 
                = ((IData)(1U) + vlSelf->tb_rls_dnn_top__DOT__sample_idx);
        } else {
            vlSelf->tb_rls_dnn_top__DOT__s_axis_tvalid = 0U;
        }
        if ((0x13U == vlSelf->tb_rls_dnn_top__DOT__clk_cnt)) {
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__clk_cnt = 0U;
            vlSelf->tb_rls_dnn_top__DOT__sample_enable = 1U;
        } else {
            vlSelf->__Vdly__tb_rls_dnn_top__DOT__clk_cnt 
                = ((IData)(1U) + vlSelf->tb_rls_dnn_top__DOT__clk_cnt);
            vlSelf->tb_rls_dnn_top__DOT__sample_enable = 0U;
        }
    } else {
        vlSelf->tb_rls_dnn_top__DOT__sample_idx = 0U;
        vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata = 0U;
        vlSelf->tb_rls_dnn_top__DOT__s_axis_tvalid = 0U;
        vlSelf->__Vdly__tb_rls_dnn_top__DOT__clk_cnt = 0U;
        vlSelf->tb_rls_dnn_top__DOT__sample_enable = 0U;
    }
    vlSelf->tb_rls_dnn_top__DOT__clk_cnt = vlSelf->__Vdly__tb_rls_dnn_top__DOT__clk_cnt;
}

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_comb__TOP__3(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_comb__TOP__3\n"); );
    // Body
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_awvalid 
        = (IData)(((0x20U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid)));
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_wvalid 
        = (IData)(((0x20U == (0x70U & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))) 
                   & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid)));
}

VL_INLINE_OPT void Vtb_rls_dnn_top___024root___nba_comb__TOP__4(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___nba_comb__TOP__4\n"); );
    // Body
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n 
        = ((~ (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst)) 
           & (IData)(vlSelf->tb_rls_dnn_top__DOT__rst_n));
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

void Vtb_rls_dnn_top___024root___timing_resume(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h65953776__0.resume("@(posedge tb_rls_dnn_top.clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h65953737__0.resume("@(negedge tb_rls_dnn_top.clk)");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_rls_dnn_top___024root___timing_commit(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h65953776__0.commit("@(posedge tb_rls_dnn_top.clk)");
    }
    if ((! (8ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h65953737__0.commit("@(negedge tb_rls_dnn_top.clk)");
    }
}

void Vtb_rls_dnn_top___024root___eval_triggers__act(Vtb_rls_dnn_top___024root* vlSelf);
void Vtb_rls_dnn_top___024root___eval_act(Vtb_rls_dnn_top___024root* vlSelf);

bool Vtb_rls_dnn_top___024root___eval_phase__act(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<5> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_rls_dnn_top___024root___eval_triggers__act(vlSelf);
    Vtb_rls_dnn_top___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_rls_dnn_top___024root___timing_resume(vlSelf);
        Vtb_rls_dnn_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_rls_dnn_top___024root___eval_nba(Vtb_rls_dnn_top___024root* vlSelf);

bool Vtb_rls_dnn_top___024root___eval_phase__nba(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_rls_dnn_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rls_dnn_top___024root___dump_triggers__nba(Vtb_rls_dnn_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rls_dnn_top___024root___dump_triggers__act(Vtb_rls_dnn_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_rls_dnn_top___024root___eval(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_rls_dnn_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_rls_dnn_top.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_rls_dnn_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_rls_dnn_top.v", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_rls_dnn_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_rls_dnn_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_rls_dnn_top___024root___eval_debug_assertions(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
