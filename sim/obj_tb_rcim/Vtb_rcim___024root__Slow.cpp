// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rcim.h for the primary calling header

#include "Vtb_rcim__pch.h"
#include "Vtb_rcim__Syms.h"
#include "Vtb_rcim___024root.h"

void Vtb_rcim___024root___ctor_var_reset(Vtb_rcim___024root* vlSelf);

Vtb_rcim___024root::Vtb_rcim___024root(Vtb_rcim__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_rcim___024root___ctor_var_reset(this);
}

void Vtb_rcim___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_rcim___024root::~Vtb_rcim___024root() {
}
