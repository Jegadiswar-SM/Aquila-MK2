// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_affhc.h for the primary calling header

#include "Vtb_affhc__pch.h"
#include "Vtb_affhc__Syms.h"
#include "Vtb_affhc___024root.h"

void Vtb_affhc___024root___ctor_var_reset(Vtb_affhc___024root* vlSelf);

Vtb_affhc___024root::Vtb_affhc___024root(Vtb_affhc__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_affhc___024root___ctor_var_reset(this);
}

void Vtb_affhc___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_affhc___024root::~Vtb_affhc___024root() {
}
