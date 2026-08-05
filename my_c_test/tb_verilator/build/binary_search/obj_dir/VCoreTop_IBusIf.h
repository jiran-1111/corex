// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCoreTop.h for the primary calling header

#ifndef VERILATED_VCORETOP_IBUSIF_H_
#define VERILATED_VCORETOP_IBUSIF_H_  // guard

#include "verilated.h"


class VCoreTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCoreTop_IBusIf final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ req;
    CData/*0:0*/ gnt;
    CData/*0:0*/ ack;
    CData/*0:0*/ err;
    IData/*31:0*/ addr;
    IData/*31:0*/ rdata;

    // INTERNAL VARIABLES
    VCoreTop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000020U;

    // CONSTRUCTORS
    VCoreTop_IBusIf(VCoreTop__Syms* symsp, const char* v__name);
    ~VCoreTop_IBusIf();
    VL_UNCOPYABLE(VCoreTop_IBusIf);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VCoreTop_IBusIf* obj);

#endif  // guard
