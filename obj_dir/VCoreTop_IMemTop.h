// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCoreTop.h for the primary calling header

#ifndef VERILATED_VCORETOP_IMEMTOP_H_
#define VERILATED_VCORETOP_IMEMTOP_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
class VCoreTop_IBusIf;
class VCoreTop_IMem;


class VCoreTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCoreTop_IMemTop final : public VerilatedModule {
  public:
    // CELLS
    VCoreTop_IBusIf* __PVT__ibus;
    VCoreTop_IMem* imem;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(req,0,0);
    VL_OUT8(gnt,0,0);
    VL_OUT8(ack,0,0);
    VL_OUT8(err,0,0);
    VL_IN(addr,31,0);
    VL_OUT(rdata,31,0);

    // INTERNAL VARIABLES
    VCoreTop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ SIZE_BYTES = 0x00004000U;

    // CONSTRUCTORS
    VCoreTop_IMemTop(VCoreTop__Syms* symsp, const char* v__name);
    ~VCoreTop_IMemTop();
    VL_UNCOPYABLE(VCoreTop_IMemTop);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
};


#endif  // guard
