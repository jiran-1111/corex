// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IBusIf.h"
#include "VCoreTop__Syms.h"

// Parameter definitions for VCoreTop_IBusIf
constexpr IData/*31:0*/ VCoreTop_IBusIf::ADDR_WIDTH;
constexpr IData/*31:0*/ VCoreTop_IBusIf::DATA_WIDTH;


void VCoreTop_IBusIf___ctor_var_reset(VCoreTop_IBusIf* vlSelf);

VCoreTop_IBusIf::VCoreTop_IBusIf(VCoreTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCoreTop_IBusIf___ctor_var_reset(this);
}

void VCoreTop_IBusIf::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VCoreTop_IBusIf::~VCoreTop_IBusIf() {
}
