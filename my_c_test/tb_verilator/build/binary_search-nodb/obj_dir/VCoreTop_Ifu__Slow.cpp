// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_Ifu.h"
#include "VCoreTop__Syms.h"

// Parameter definitions for VCoreTop_Ifu
constexpr IData/*31:0*/ VCoreTop_Ifu::DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_Ifu::ADDR_WIDTH;


void VCoreTop_Ifu___ctor_var_reset(VCoreTop_Ifu* vlSelf);

VCoreTop_Ifu::VCoreTop_Ifu(VCoreTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCoreTop_Ifu___ctor_var_reset(this);
}

void VCoreTop_Ifu::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VCoreTop_Ifu::~VCoreTop_Ifu() {
}
