// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_Ifu.h"
#include "VCoreTop__Syms.h"

VL_INLINE_OPT void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__0(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.stall = vlSymsp->TOP__CoreTop.stall;
    vlSelfRef.inst_PC = vlSelfRef.inst_PC_reg;
    vlSelfRef.PC_plus4 = ((IData)(4U) + vlSelfRef.PC_reg);
    vlSelfRef.program_address = vlSymsp->TOP__CoreTop.program_address;
    vlSelfRef.start = vlSymsp->TOP__CoreTop.start;
    vlSelfRef.clk = vlSymsp->TOP__CoreTop.clk;
    vlSelfRef.rst = vlSymsp->TOP__CoreTop.rst;
    vlSelfRef.JAL_target = vlSymsp->TOP__CoreTop.id_jal_target;
    vlSelfRef.branch_target = vlSymsp->TOP__CoreTop.id_branch_target;
    vlSelfRef.pc_sel_execute = vlSymsp->TOP__CoreTop.id_pc_sel;
}

VL_INLINE_OPT void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.valid = vlSymsp->TOP__CoreTop__u_ifu__IMem.ack;
}

VL_INLINE_OPT void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__2(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.imem_err = vlSymsp->TOP__CoreTop__u_ifu__IMem.err;
    vlSelfRef.imem_gnt = vlSymsp->TOP__CoreTop__u_ifu__IMem.gnt;
    vlSelfRef.instruction = vlSymsp->TOP__CoreTop__u_ifu__IMem.rdata;
    vlSelfRef.JALR_target = vlSymsp->TOP__CoreTop.ex_jalr_target;
    vlSelfRef.branch_taken = vlSymsp->TOP__CoreTop.ex_branch_taken;
    vlSelfRef.jump_or_branch_taken = (((1U == (IData)(vlSelfRef.pc_sel_execute)) 
                                       & (IData)(vlSelfRef.branch_taken)) 
                                      | ((2U == (IData)(vlSelfRef.pc_sel_execute)) 
                                         | (3U == (IData)(vlSelfRef.pc_sel_execute))));
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

VL_INLINE_OPT void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.valid = vlSymsp->TOP__CoreTop__u_ifu__IMem.ack;
    vlSelfRef.instruction = vlSymsp->TOP__CoreTop__u_ifu__IMem.rdata;
}

VL_INLINE_OPT void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__2(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.JAL_target = vlSymsp->TOP__CoreTop.id_jal_target;
    vlSelfRef.branch_target = vlSymsp->TOP__CoreTop.id_branch_target;
    vlSelfRef.pc_sel_execute = vlSymsp->TOP__CoreTop.id_pc_sel;
}

VL_INLINE_OPT void VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__0(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.JALR_target = vlSymsp->TOP__CoreTop.ex_jalr_target;
    vlSelfRef.branch_taken = vlSymsp->TOP__CoreTop.ex_branch_taken;
    vlSelfRef.jump_or_branch_taken = (((1U == (IData)(vlSelfRef.pc_sel_execute)) 
                                       & (IData)(vlSelfRef.branch_taken)) 
                                      | ((2U == (IData)(vlSelfRef.pc_sel_execute)) 
                                         | (3U == (IData)(vlSelfRef.pc_sel_execute))));
}
