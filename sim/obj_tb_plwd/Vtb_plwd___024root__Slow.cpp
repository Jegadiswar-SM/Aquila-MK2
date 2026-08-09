// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_plwd.h for the primary calling header

#include "Vtb_plwd__pch.h"
#include "Vtb_plwd__Syms.h"
#include "Vtb_plwd___024root.h"

void Vtb_plwd___024root___ctor_var_reset(Vtb_plwd___024root* vlSelf);

Vtb_plwd___024root::Vtb_plwd___024root(Vtb_plwd__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_plwd___024root___ctor_var_reset(this);
}

void Vtb_plwd___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_plwd___024root::~Vtb_plwd___024root() {
}
