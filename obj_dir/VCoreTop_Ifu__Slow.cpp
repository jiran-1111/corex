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

void VCoreTop_Ifu___configure_coverage(VCoreTop_Ifu* vlSelf, bool first);

void VCoreTop_Ifu::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    VCoreTop_Ifu___configure_coverage(this, first);
}

VCoreTop_Ifu::~VCoreTop_Ifu() {
}

// Coverage
void VCoreTop_Ifu::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    std::string fullhier = std::string{VerilatedModule::name()} + hierp;
    if (!fullhier.empty() && fullhier[0] == '.') fullhier = fullhier.substr(1);
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(vlSymsp->_vm_contextp__->coveragep(), VerilatedModule::name(), count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",fullhier,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}
