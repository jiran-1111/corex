// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCoreTop.h for the primary calling header

#ifndef VERILATED_VCORETOP_IFU_H_
#define VERILATED_VCORETOP_IFU_H_  // guard

#include "verilated.h"
class VCoreTop_IMemTop;


class VCoreTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCoreTop_Ifu final : public VerilatedModule {
  public:
    // CELLS
    VCoreTop_IMemTop* IMem;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(start,0,0);
    VL_IN8(stall,0,0);
    VL_IN8(pc_sel_execute,1,0);
    VL_IN8(branch_taken,0,0);
    VL_OUT8(valid,0,0);
    CData/*0:0*/ imem_gnt;
    CData/*0:0*/ imem_err;
    CData/*0:0*/ fetch;
    CData/*0:0*/ jump_or_branch_taken;
    VL_IN(program_address,31,0);
    VL_IN(JAL_target,31,0);
    VL_IN(JALR_target,31,0);
    VL_IN(branch_target,31,0);
    VL_OUT(instruction,31,0);
    VL_OUT(inst_PC,31,0);
    IData/*31:0*/ PC_reg;
    IData/*31:0*/ PC_plus4;
    IData/*31:0*/ inst_PC_reg;
    IData/*31:0*/ next_PC;

    // INTERNAL VARIABLES
    VCoreTop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ ADDR_WIDTH = 0x00000020U;

    // CONSTRUCTORS
    VCoreTop_Ifu(VCoreTop__Syms* symsp, const char* v__name);
    ~VCoreTop_Ifu();
    VL_UNCOPYABLE(VCoreTop_Ifu);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
