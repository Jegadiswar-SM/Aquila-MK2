// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_plwd.h for the primary calling header

#include "Vtb_plwd__pch.h"
#include "Vtb_plwd__Syms.h"
#include "Vtb_plwd___024root.h"

VL_ATTR_COLD void Vtb_plwd___024root___eval_initial__TOP(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    vlSelf->tb_plwd__DOT__clk = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x706c7764U;
    __Vtemp_1[2U] = 0x74625fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
}
