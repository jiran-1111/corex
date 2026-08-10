// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCoreTop.h for the primary calling header

#ifndef VERILATED_VCORETOP___024ROOT_H_
#define VERILATED_VCORETOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
class VCoreTop_CoreTop;


class VCoreTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCoreTop___024root final : public VerilatedModule {
  public:
    // CELLS
    VCoreTop_CoreTop* CoreTop;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(start,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CoreTop__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CoreTop__rst__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CoreTop__u_if_id_reg__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CoreTop__u_decoder__DOT__u_regfile__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CoreTop__u_ex_mem_reg__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CoreTop__u_dmem__DOT__dmem__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CoreTop__u_ifu__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CoreTop__u_ifu__IMem__imem__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(program_address,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<8> __VactTriggered;
    VlTriggerVec<8> __VnbaTriggered;

    // INTERNAL VARIABLES
    VCoreTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCoreTop___024root(VCoreTop__Syms* symsp, const char* v__name);
    ~VCoreTop___024root();
    VL_UNCOPYABLE(VCoreTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
