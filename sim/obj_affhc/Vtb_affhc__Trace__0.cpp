// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_affhc__Syms.h"


void Vtb_affhc___024root__trace_chg_0_sub_0(Vtb_affhc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_affhc___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root__trace_chg_0\n"); );
    // Init
    Vtb_affhc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_affhc___024root*>(voidSelf);
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_affhc___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_affhc___024root__trace_chg_0_sub_0(Vtb_affhc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb_affhc__DOT__rst_n));
        bufp->chgSData(oldp+1,(vlSelf->tb_affhc__DOT__e_in),16);
        bufp->chgBit(oldp+2,(vlSelf->tb_affhc__DOT__e_valid));
        bufp->chgCData(oldp+3,(vlSelf->tb_affhc__DOT__s_axi_awaddr),5);
        bufp->chgBit(oldp+4,(vlSelf->tb_affhc__DOT__s_axi_awvalid));
        bufp->chgIData(oldp+5,(vlSelf->tb_affhc__DOT__s_axi_wdata),32);
        bufp->chgBit(oldp+6,(vlSelf->tb_affhc__DOT__s_axi_wvalid));
        bufp->chgIData(oldp+7,(vlSelf->tb_affhc__DOT__pass),32);
        bufp->chgIData(oldp+8,(vlSelf->tb_affhc__DOT__fail),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+9,(vlSelf->tb_affhc__DOT__s_axi_awready));
        bufp->chgBit(oldp+10,(vlSelf->tb_affhc__DOT__s_axi_wready));
        bufp->chgSData(oldp+11,(vlSelf->tb_affhc__DOT__lambda_out),16);
        bufp->chgCData(oldp+12,(vlSelf->tb_affhc__DOT__fsm_state_dbg),2);
        bufp->chgSData(oldp+13,(vlSelf->tb_affhc__DOT__dut__DOT__lambda_slow),16);
        bufp->chgSData(oldp+14,(vlSelf->tb_affhc__DOT__dut__DOT__lambda_mid),16);
        bufp->chgSData(oldp+15,(vlSelf->tb_affhc__DOT__dut__DOT__lambda_fast),16);
        bufp->chgSData(oldp+16,(vlSelf->tb_affhc__DOT__dut__DOT__threshold_up_reg),16);
        bufp->chgSData(oldp+17,(vlSelf->tb_affhc__DOT__dut__DOT__threshold_down_reg),16);
        bufp->chgCData(oldp+18,(vlSelf->tb_affhc__DOT__dut__DOT__state),2);
        bufp->chgCData(oldp+19,(vlSelf->tb_affhc__DOT__dut__DOT__next_state),2);
        bufp->chgSData(oldp+20,(vlSelf->tb_affhc__DOT__dut__DOT__e_prev),16);
        bufp->chgCData(oldp+21,(vlSelf->tb_affhc__DOT__dut__DOT__cnt_up),3);
        bufp->chgCData(oldp+22,(vlSelf->tb_affhc__DOT__dut__DOT__cnt_down),4);
        bufp->chgCData(oldp+23,(vlSelf->tb_affhc__DOT__dut__DOT__lockout_cnt),6);
        bufp->chgBit(oldp+24,(vlSelf->tb_affhc__DOT__dut__DOT__lockout_active));
    }
    bufp->chgBit(oldp+25,(vlSelf->tb_affhc__DOT__clk));
    bufp->chgIData(oldp+26,(vlSelf->tb_affhc__DOT__dut__DOT__delta_e),17);
}

void Vtb_affhc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root__trace_cleanup\n"); );
    // Init
    Vtb_affhc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_affhc___024root*>(voidSelf);
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
