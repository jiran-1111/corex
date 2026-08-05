// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IMem.h"
#include "VCoreTop__Syms.h"

// Parameter definitions for VCoreTop_IMem
constexpr IData/*31:0*/ VCoreTop_IMem::DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_IMem::SIZE_BYTES;
constexpr IData/*31:0*/ VCoreTop_IMem::BYTES_PER_WORD;
constexpr IData/*31:0*/ VCoreTop_IMem::MEM_DEPTH;
constexpr IData/*31:0*/ VCoreTop_IMem::MEM_ADDR_WIDTH;
constexpr IData/*31:0*/ VCoreTop_IMem::BYTE_OFFSET;


void VCoreTop_IMem___ctor_var_reset(VCoreTop_IMem* vlSelf);

VCoreTop_IMem::VCoreTop_IMem(VCoreTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCoreTop_IMem___ctor_var_reset(this);
}

void VCoreTop_IMem::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VCoreTop_IMem::~VCoreTop_IMem() {
}
