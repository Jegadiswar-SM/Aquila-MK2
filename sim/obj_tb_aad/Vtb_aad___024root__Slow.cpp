// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_aad.h for the primary calling header

#include "Vtb_aad__pch.h"
#include "Vtb_aad__Syms.h"
#include "Vtb_aad___024root.h"

void Vtb_aad___024root___ctor_var_reset(Vtb_aad___024root* vlSelf);

Vtb_aad___024root::Vtb_aad___024root(Vtb_aad__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_aad___024root___ctor_var_reset(this);
}

void Vtb_aad___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_aad___024root::~Vtb_aad___024root() {
}
