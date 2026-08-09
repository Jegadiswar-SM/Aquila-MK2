// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_plwd__Syms.h"


void Vtb_plwd___024root__trace_chg_0_sub_0(Vtb_plwd___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_plwd___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root__trace_chg_0\n"); );
    // Init
    Vtb_plwd___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_plwd___024root*>(voidSelf);
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_plwd___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_plwd___024root__trace_chg_0_sub_0(Vtb_plwd___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb_plwd__DOT__rst_n));
        bufp->chgBit(oldp+1,(vlSelf->tb_plwd__DOT__m_axis_tvalid));
        bufp->chgSData(oldp+2,(vlSelf->tb_plwd__DOT__m_axis_tdata),16);
        bufp->chgCData(oldp+3,(vlSelf->tb_plwd__DOT__s_axi_araddr),4);
        bufp->chgBit(oldp+4,(vlSelf->tb_plwd__DOT__s_axi_arvalid));
        bufp->chgCData(oldp+5,(vlSelf->tb_plwd__DOT__s_axi_awaddr),4);
        bufp->chgBit(oldp+6,(vlSelf->tb_plwd__DOT__s_axi_awvalid));
        bufp->chgIData(oldp+7,(vlSelf->tb_plwd__DOT__s_axi_wdata),32);
        bufp->chgBit(oldp+8,(vlSelf->tb_plwd__DOT__s_axi_wvalid));
        bufp->chgIData(oldp+9,(vlSelf->tb_plwd__DOT__pass),32);
        bufp->chgIData(oldp+10,(vlSelf->tb_plwd__DOT__fail),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+11,(vlSelf->tb_plwd__DOT__s_axi_rdata),32);
        bufp->chgBit(oldp+12,(vlSelf->tb_plwd__DOT__s_axi_rvalid));
        bufp->chgBit(oldp+13,(vlSelf->tb_plwd__DOT__s_axi_awready));
        bufp->chgBit(oldp+14,(vlSelf->tb_plwd__DOT__s_axi_wready));
        bufp->chgBit(oldp+15,(vlSelf->tb_plwd__DOT__pipeline_srst));
        bufp->chgBit(oldp+16,(vlSelf->tb_plwd__DOT__irq_fault));
        bufp->chgSData(oldp+17,(vlSelf->tb_plwd__DOT__dut__DOT__timeout_cnt),16);
        bufp->chgBit(oldp+18,(vlSelf->tb_plwd__DOT__dut__DOT__pipeline_stall_fault));
        bufp->chgSData(oldp+19,(vlSelf->tb_plwd__DOT__dut__DOT__last_sample),16);
        bufp->chgCData(oldp+20,(vlSelf->tb_plwd__DOT__dut__DOT__stuck_cnt),5);
        bufp->chgBit(oldp+21,(vlSelf->tb_plwd__DOT__dut__DOT__output_stuck_fault));
        bufp->chgIData(oldp+22,(vlSelf->tb_plwd__DOT__dut__DOT__global_sample_cnt),32);
        bufp->chgCData(oldp+23,(vlSelf->tb_plwd__DOT__dut__DOT__fault_type_reg),2);
        bufp->chgIData(oldp+24,(vlSelf->tb_plwd__DOT__dut__DOT__fault_sample_cnt),32);
        bufp->chgCData(oldp+25,(vlSelf->tb_plwd__DOT__dut__DOT__fault_count_reg),8);
        bufp->chgCData(oldp+26,(vlSelf->tb_plwd__DOT__dut__DOT__rcv_state),2);
        bufp->chgCData(oldp+27,(vlSelf->tb_plwd__DOT__dut__DOT__drain_cnt),3);
    }
    bufp->chgBit(oldp+28,(vlSelf->tb_plwd__DOT__clk));
}

void Vtb_plwd___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root__trace_cleanup\n"); );
    // Init
    Vtb_plwd___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_plwd___024root*>(voidSelf);
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
