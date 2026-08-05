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
    vlSelfRef.pc_sel_execute = vlSymsp->TOP__CoreTop.id_pc_sel;
    vlSelfRef.branch_target = vlSymsp->TOP__CoreTop.id_branch_target;
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
    if ((1U == (IData)(vlSelfRef.pc_sel_execute))) {
        vlSelfRef.next_PC = ((IData)(vlSelfRef.branch_taken)
                              ? ([&]() {
                    ++(vlSymsp->__Vcoverage[196]);
                }(), vlSelfRef.branch_target) : ([&]() {
                    ++(vlSymsp->__Vcoverage[197]);
                }(), vlSelfRef.PC_plus4));
        ++(vlSymsp->__Vcoverage[198]);
    } else if ((2U == (IData)(vlSelfRef.pc_sel_execute))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlSelfRef.next_PC = vlSelfRef.JAL_target;
    } else if ((3U == (IData)(vlSelfRef.pc_sel_execute))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlSelfRef.next_PC = vlSelfRef.JALR_target;
    } else {
        ++(vlSymsp->__Vcoverage[201]);
        vlSelfRef.next_PC = vlSelfRef.PC_plus4;
    }
    if (vlSelfRef.branch_taken) {
        ++(vlSymsp->__Vcoverage[194]);
    }
    if ((1U & (~ (IData)(vlSelfRef.branch_taken)))) {
        ++(vlSymsp->__Vcoverage[195]);
    }
    ++(vlSymsp->__Vcoverage[202]);
}

VL_INLINE_OPT void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__0(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__inst_PC_reg;
    __Vdly__inst_PC_reg = 0;
    // Body
    __Vdly__inst_PC_reg = vlSelfRef.inst_PC_reg;
    vlSelfRef.__Vdly__PC_reg = vlSelfRef.PC_reg;
    if (((IData)(vlSelfRef.rst) | (IData)(vlSelfRef.start))) {
        ++(vlSymsp->__Vcoverage[228]);
        __Vdly__inst_PC_reg = vlSelfRef.program_address;
    } else if (vlSelfRef.stall) {
        __Vdly__inst_PC_reg = vlSelfRef.inst_PC_reg;
        ++(vlSymsp->__Vcoverage[227]);
    } else {
        if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            ++(vlSymsp->__Vcoverage[222]);
            __Vdly__inst_PC_reg = vlSelfRef.PC_reg;
        } else {
            ++(vlSymsp->__Vcoverage[223]);
        }
        if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            ++(vlSymsp->__Vcoverage[224]);
        }
        if ((1U & (~ (IData)(vlSelfRef.imem_gnt)))) {
            ++(vlSymsp->__Vcoverage[225]);
        }
        if ((1U & (~ (IData)(vlSelfRef.fetch)))) {
            ++(vlSymsp->__Vcoverage[226]);
        }
    }
    if (vlSelfRef.start) {
        ++(vlSymsp->__Vcoverage[229]);
    }
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[230]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rst)) & (~ (IData)(vlSelfRef.start))))) {
        ++(vlSymsp->__Vcoverage[231]);
    }
    ++(vlSymsp->__Vcoverage[232]);
    if (((IData)(vlSelfRef.rst) | (IData)(vlSelfRef.start))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlSelfRef.__Vdly__PC_reg = vlSelfRef.program_address;
    } else if (vlSelfRef.stall) {
        vlSelfRef.__Vdly__PC_reg = vlSelfRef.PC_reg;
        ++(vlSymsp->__Vcoverage[216]);
    } else if (vlSelfRef.jump_or_branch_taken) {
        ++(vlSymsp->__Vcoverage[215]);
        vlSelfRef.__Vdly__PC_reg = vlSelfRef.next_PC;
    } else {
        if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            ++(vlSymsp->__Vcoverage[210]);
            vlSelfRef.__Vdly__PC_reg = vlSelfRef.PC_plus4;
        } else {
            ++(vlSymsp->__Vcoverage[211]);
        }
        if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            ++(vlSymsp->__Vcoverage[212]);
        }
        if ((1U & (~ (IData)(vlSelfRef.imem_gnt)))) {
            ++(vlSymsp->__Vcoverage[213]);
        }
        if ((1U & (~ (IData)(vlSelfRef.fetch)))) {
            ++(vlSymsp->__Vcoverage[214]);
        }
    }
    if (vlSelfRef.start) {
        ++(vlSymsp->__Vcoverage[218]);
    }
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[219]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rst)) & (~ (IData)(vlSelfRef.start))))) {
        ++(vlSymsp->__Vcoverage[220]);
    }
    ++(vlSymsp->__Vcoverage[221]);
    vlSelfRef.inst_PC_reg = __Vdly__inst_PC_reg;
    vlSelfRef.inst_PC = vlSelfRef.inst_PC_reg;
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[208]);
        vlSelfRef.fetch = 0U;
    } else {
        if (((IData)(vlSelfRef.start) | (IData)(vlSelfRef.stall))) {
            ++(vlSymsp->__Vcoverage[203]);
            vlSelfRef.fetch = 1U;
        } else {
            ++(vlSymsp->__Vcoverage[204]);
            vlSelfRef.fetch = 1U;
        }
        if (vlSelfRef.stall) {
            ++(vlSymsp->__Vcoverage[205]);
        }
        if (vlSelfRef.start) {
            ++(vlSymsp->__Vcoverage[206]);
        }
        if ((1U & ((~ (IData)(vlSelfRef.start)) & (~ (IData)(vlSelfRef.stall))))) {
            ++(vlSymsp->__Vcoverage[207]);
        }
    }
    ++(vlSymsp->__Vcoverage[209]);
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
    vlSelfRef.pc_sel_execute = vlSymsp->TOP__CoreTop.id_pc_sel;
    vlSelfRef.branch_target = vlSymsp->TOP__CoreTop.id_branch_target;
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

VL_INLINE_OPT void VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U == (IData)(vlSelfRef.pc_sel_execute))) {
        vlSelfRef.next_PC = ((IData)(vlSelfRef.branch_taken)
                              ? ([&]() {
                    ++(vlSymsp->__Vcoverage[196]);
                }(), vlSelfRef.branch_target) : ([&]() {
                    ++(vlSymsp->__Vcoverage[197]);
                }(), vlSelfRef.PC_plus4));
        ++(vlSymsp->__Vcoverage[198]);
    } else if ((2U == (IData)(vlSelfRef.pc_sel_execute))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlSelfRef.next_PC = vlSelfRef.JAL_target;
    } else if ((3U == (IData)(vlSelfRef.pc_sel_execute))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlSelfRef.next_PC = vlSelfRef.JALR_target;
    } else {
        ++(vlSymsp->__Vcoverage[201]);
        vlSelfRef.next_PC = vlSelfRef.PC_plus4;
    }
    if (vlSelfRef.branch_taken) {
        ++(vlSymsp->__Vcoverage[194]);
    }
    if ((1U & (~ (IData)(vlSelfRef.branch_taken)))) {
        ++(vlSymsp->__Vcoverage[195]);
    }
    ++(vlSymsp->__Vcoverage[202]);
}
