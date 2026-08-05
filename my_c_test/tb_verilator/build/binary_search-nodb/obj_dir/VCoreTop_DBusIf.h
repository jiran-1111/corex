// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCoreTop.h for the primary calling header

#ifndef VERILATED_VCORETOP_DBUSIF_H_
#define VERILATED_VCORETOP_DBUSIF_H_  // guard

#include "verilated.h"


class VCoreTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCoreTop_DBusIf final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ read;
    CData/*0:0*/ write;
    CData/*3:0*/ wbe;
    CData/*0:0*/ gnt;
    CData/*0:0*/ rack;
    CData/*0:0*/ wack;
    CData/*0:0*/ err;
    IData/*31:0*/ addr;
    IData/*31:0*/ wdata;
    IData/*31:0*/ rdata;

    // INTERNAL VARIABLES
    VCoreTop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ BYTES_PER_WORD = 4U;

    // CONSTRUCTORS
    VCoreTop_DBusIf(VCoreTop__Syms* symsp, const char* v__name);
    ~VCoreTop_DBusIf();
    VL_UNCOPYABLE(VCoreTop_DBusIf);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VCoreTop_DBusIf* obj);

#endif  // guard
