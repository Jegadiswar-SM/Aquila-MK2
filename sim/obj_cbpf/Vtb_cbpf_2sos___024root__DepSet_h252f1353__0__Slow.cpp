// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cbpf_2sos.h for the primary calling header

#include "Vtb_cbpf_2sos__pch.h"
#include "Vtb_cbpf_2sos__Syms.h"
#include "Vtb_cbpf_2sos___024root.h"

VL_ATTR_COLD void Vtb_cbpf_2sos___024root___eval_initial__TOP(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    vlSelf->tb_cbpf_2sos__DOT__clk = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x32736f73U;
    __Vtemp_1[2U] = 0x6270665fU;
    __Vtemp_1[3U] = 0x74625f63U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
}
