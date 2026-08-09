// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_affhc.h for the primary calling header

#include "Vtb_affhc__pch.h"
#include "Vtb_affhc__Syms.h"
#include "Vtb_affhc___024root.h"

VL_ATTR_COLD void Vtb_affhc___024root___eval_initial__TOP(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    vlSelf->tb_affhc__DOT__clk = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x66666863U;
    __Vtemp_1[2U] = 0x74625f61U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_affhc___024root___dump_triggers__stl(Vtb_affhc___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_affhc___024root___eval_triggers__stl(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_affhc___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
