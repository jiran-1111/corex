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

void VCoreTop_IMemTop___configure_coverage(VCoreTop_IMemTop* vlSelf, bool first);

void VCoreTop_IMemTop::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    VCoreTop_IMemTop___configure_coverage(this, first);
}

VCoreTop_IMemTop::~VCoreTop_IMemTop() {
}

// Coverage
void VCoreTop_IMemTop::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
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
