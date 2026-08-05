// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_Ifu.h"

VL_INLINE_OPT void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__0(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__PC_reg;
    __Vdly__PC_reg = 0;
    IData/*31:0*/ __Vdly__inst_PC_reg;
    __Vdly__inst_PC_reg = 0;
    // Body
    __Vdly__inst_PC_reg = vlSelfRef.inst_PC_reg;
    __Vdly__PC_reg = vlSelfRef.PC_reg;
    if (((IData)(vlSelfRef.rst) | (IData)(vlSelfRef.start))) {
        __Vdly__inst_PC_reg = vlSelfRef.program_address;
        __Vdly__PC_reg = vlSelfRef.program_address;
    } else if (vlSelfRef.stall) {
        __Vdly__inst_PC_reg = vlSelfRef.inst_PC_reg;
        __Vdly__PC_reg = vlSelfRef.PC_reg;
    } else {
        if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            __Vdly__inst_PC_reg = vlSelfRef.PC_reg;
        }
        if (vlSelfRef.jump_or_branch_taken) {
            __Vdly__PC_reg = vlSelfRef.next_PC;
        } else if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            __Vdly__PC_reg = vlSelfRef.PC_plus4;
        }
    }
    vlSelfRef.inst_PC_reg = __Vdly__inst_PC_reg;
    vlSelfRef.PC_reg = __Vdly__PC_reg;
    vlSelfRef.inst_PC = vlSelfRef.inst_PC_reg;
    vlSelfRef.PC_plus4 = ((IData)(4U) + vlSelfRef.PC_reg);
    vlSelfRef.fetch = (1U & (~ (IData)(vlSelfRef.rst)));
}

VL_INLINE_OPT void VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.next_PC = ((1U == (IData)(vlSelfRef.pc_sel_execute))
                          ? ((IData)(vlSelfRef.branch_taken)
                              ? vlSelfRef.branch_target
                              : vlSelfRef.PC_plus4)
                          : ((2U == (IData)(vlSelfRef.pc_sel_execute))
                              ? vlSelfRef.JAL_target
                              : ((3U == (IData)(vlSelfRef.pc_sel_execute))
                                  ? vlSelfRef.JALR_target
                                  : vlSelfRef.PC_plus4)));
}
