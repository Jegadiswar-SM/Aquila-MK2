// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_aad.h for the primary calling header

#include "Vtb_aad__pch.h"
#include "Vtb_aad__Syms.h"
#include "Vtb_aad___024root.h"

VL_ATTR_COLD void Vtb_aad___024root___eval_initial__TOP(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    vlSelf->tb_aad__DOT__clk = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x5f616164U;
    __Vtemp_1[2U] = 0x7462U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_aad___024root___dump_triggers__stl(Vtb_aad___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_aad___024root___eval_triggers__stl(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_aad___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
