// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_DBusIf.h"
#include "VCoreTop__Syms.h"

// Parameter definitions for VCoreTop_DBusIf
constexpr IData/*31:0*/ VCoreTop_DBusIf::ADDR_WIDTH;
constexpr IData/*31:0*/ VCoreTop_DBusIf::DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_DBusIf::BYTES_PER_WORD;


void VCoreTop_DBusIf___ctor_var_reset(VCoreTop_DBusIf* vlSelf);

VCoreTop_DBusIf::VCoreTop_DBusIf(VCoreTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCoreTop_DBusIf___ctor_var_reset(this);
}

void VCoreTop_DBusIf::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VCoreTop_DBusIf::~VCoreTop_DBusIf() {
}
