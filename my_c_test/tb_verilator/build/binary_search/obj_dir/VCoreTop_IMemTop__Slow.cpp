// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IMemTop.h"
#include "VCoreTop__Syms.h"

// Parameter definitions for VCoreTop_IMemTop
constexpr IData/*31:0*/ VCoreTop_IMemTop::ADDR_WIDTH;
constexpr IData/*31:0*/ VCoreTop_IMemTop::DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_IMemTop::SIZE_BYTES;


void VCoreTop_IMemTop___ctor_var_reset(VCoreTop_IMemTop* vlSelf);

VCoreTop_IMemTop::VCoreTop_IMemTop(VCoreTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCoreTop_IMemTop___ctor_var_reset(this);
}

void VCoreTop_IMemTop::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VCoreTop_IMemTop::~VCoreTop_IMemTop() {
}
