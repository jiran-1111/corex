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

void VCoreTop_IBusIf___configure_coverage(VCoreTop_IBusIf* vlSelf, bool first);

void VCoreTop_IBusIf::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    VCoreTop_IBusIf___configure_coverage(this, first);
}

VCoreTop_IBusIf::~VCoreTop_IBusIf() {
}

// Coverage
void VCoreTop_IBusIf::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
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
