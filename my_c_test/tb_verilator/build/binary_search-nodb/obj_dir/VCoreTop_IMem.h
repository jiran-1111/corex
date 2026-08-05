// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCoreTop.h for the primary calling header

#ifndef VERILATED_VCORETOP_IMEM_H_
#define VERILATED_VCORETOP_IMEM_H_  // guard

#include "verilated.h"


class VCoreTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCoreTop_IMem final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ gnt;
    CData/*0:0*/ err;
    SData/*11:0*/ mem_addr;
    IData/*31:0*/ rdata_q;
    VlUnpacked<IData/*31:0*/, 4096> mem;

    // INTERNAL VARIABLES
    VCoreTop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ SIZE_BYTES = 0x00004000U;
    static constexpr IData/*31:0*/ BYTES_PER_WORD = 4U;
    static constexpr IData/*31:0*/ MEM_DEPTH = 0x00001000U;
    static constexpr IData/*31:0*/ MEM_ADDR_WIDTH = 0x0000000cU;
    static constexpr IData/*31:0*/ BYTE_OFFSET = 2U;

    // CONSTRUCTORS
    VCoreTop_IMem(VCoreTop__Syms* symsp, const char* v__name);
    ~VCoreTop_IMem();
    VL_UNCOPYABLE(VCoreTop_IMem);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
