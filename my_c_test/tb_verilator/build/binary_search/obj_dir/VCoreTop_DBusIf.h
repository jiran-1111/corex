// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCoreTop.h for the primary calling header

#ifndef VERILATED_VCORETOP_DBUSIF_H_
#define VERILATED_VCORETOP_DBUSIF_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"


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
    CData/*0:0*/ __Vtogcov__read;
    CData/*0:0*/ __Vtogcov__write;
    CData/*3:0*/ __Vtogcov__wbe;
    CData/*0:0*/ __Vtogcov__gnt;
    CData/*0:0*/ __Vtogcov__rack;
    CData/*0:0*/ __Vtogcov__wack;
    CData/*0:0*/ __Vtogcov__err;
    IData/*31:0*/ addr;
    IData/*31:0*/ wdata;
    IData/*31:0*/ rdata;
    IData/*31:0*/ __Vtogcov__addr;
    IData/*31:0*/ __Vtogcov__wdata;
    IData/*31:0*/ __Vtogcov__rdata;

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
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};

std::string VL_TO_STRING(const VCoreTop_DBusIf* obj);

#endif  // guard
