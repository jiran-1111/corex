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
    if ((vlSelfRef.PC_reg ^ vlSelfRef.__Vtogcov__PC_reg)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5736, vlSelfRef.PC_reg, vlSelfRef.__Vtogcov__PC_reg);
        vlSelfRef.__Vtogcov__PC_reg = vlSelfRef.PC_reg;
    }
    if ((vlSelfRef.inst_PC_reg ^ vlSelfRef.__Vtogcov__inst_PC_reg)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5864, vlSelfRef.inst_PC_reg, vlSelfRef.__Vtogcov__inst_PC_reg);
        vlSelfRef.__Vtogcov__inst_PC_reg = vlSelfRef.inst_PC_reg;
    }
    if (((IData)(vlSelfRef.fetch) ^ (IData)(vlSelfRef.__Vtogcov__fetch))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5996, vlSelfRef.fetch, vlSelfRef.__Vtogcov__fetch);
        vlSelfRef.__Vtogcov__fetch = vlSelfRef.fetch;
    }
    vlSelfRef.stall = vlSymsp->TOP__CoreTop.stall;
    vlSelfRef.PC_plus4 = ((IData)(4U) + vlSelfRef.PC_reg);
    vlSelfRef.inst_PC = vlSelfRef.inst_PC_reg;
    vlSelfRef.program_address = vlSymsp->TOP__CoreTop.program_address;
    vlSelfRef.start = vlSymsp->TOP__CoreTop.start;
    vlSelfRef.clk = vlSymsp->TOP__CoreTop.clk;
    vlSelfRef.rst = vlSymsp->TOP__CoreTop.rst;
    vlSelfRef.JAL_target = vlSymsp->TOP__CoreTop.id_jal_target;
    vlSelfRef.pc_sel_execute = vlSymsp->TOP__CoreTop.id_pc_sel;
    vlSelfRef.branch_target = vlSymsp->TOP__CoreTop.id_branch_target;
    if (((IData)(vlSelfRef.stall) ^ (IData)(vlSelfRef.__Vtogcov__stall))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5342, vlSelfRef.stall, vlSelfRef.__Vtogcov__stall);
        vlSelfRef.__Vtogcov__stall = vlSelfRef.stall;
    }
    if ((vlSelfRef.PC_plus4 ^ vlSelfRef.__Vtogcov__PC_plus4)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5800, vlSelfRef.PC_plus4, vlSelfRef.__Vtogcov__PC_plus4);
        vlSelfRef.__Vtogcov__PC_plus4 = vlSelfRef.PC_plus4;
    }
    if ((vlSelfRef.inst_PC ^ vlSelfRef.__Vtogcov__inst_PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5670, vlSelfRef.inst_PC, vlSelfRef.__Vtogcov__inst_PC);
        vlSelfRef.__Vtogcov__inst_PC = vlSelfRef.inst_PC;
    }
    if ((vlSelfRef.program_address ^ vlSelfRef.__Vtogcov__program_address)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5344, vlSelfRef.program_address, vlSelfRef.__Vtogcov__program_address);
        vlSelfRef.__Vtogcov__program_address = vlSelfRef.program_address;
    }
    if (((IData)(vlSelfRef.start) ^ (IData)(vlSelfRef.__Vtogcov__start))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5340, vlSelfRef.start, vlSelfRef.__Vtogcov__start);
        vlSelfRef.__Vtogcov__start = vlSelfRef.start;
    }
    if (((IData)(vlSelfRef.clk) ^ (IData)(vlSelfRef.__Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5336, vlSelfRef.clk, vlSelfRef.__Vtogcov__clk);
        vlSelfRef.__Vtogcov__clk = vlSelfRef.clk;
    }
    if (((IData)(vlSelfRef.rst) ^ (IData)(vlSelfRef.__Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5338, vlSelfRef.rst, vlSelfRef.__Vtogcov__rst);
        vlSelfRef.__Vtogcov__rst = vlSelfRef.rst;
    }
    if ((vlSelfRef.JAL_target ^ vlSelfRef.__Vtogcov__JAL_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5408, vlSelfRef.JAL_target, vlSelfRef.__Vtogcov__JAL_target);
        vlSelfRef.__Vtogcov__JAL_target = vlSelfRef.JAL_target;
    }
    if (((IData)(vlSelfRef.pc_sel_execute) ^ (IData)(vlSelfRef.__Vtogcov__pc_sel_execute))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 5600, vlSelfRef.pc_sel_execute, vlSelfRef.__Vtogcov__pc_sel_execute);
        vlSelfRef.__Vtogcov__pc_sel_execute = vlSelfRef.pc_sel_execute;
    }
    if ((vlSelfRef.branch_target ^ vlSelfRef.__Vtogcov__branch_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5536, vlSelfRef.branch_target, vlSelfRef.__Vtogcov__branch_target);
        vlSelfRef.__Vtogcov__branch_target = vlSelfRef.branch_target;
    }
}

VL_INLINE_OPT void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.valid = vlSymsp->TOP__CoreTop__u_ifu__IMem.ack;
    vlSelfRef.imem_err = vlSymsp->TOP__CoreTop__u_ifu__IMem.err;
    vlSelfRef.imem_gnt = vlSymsp->TOP__CoreTop__u_ifu__IMem.gnt;
    vlSelfRef.instruction = vlSymsp->TOP__CoreTop__u_ifu__IMem.rdata;
    if (((IData)(vlSelfRef.valid) ^ (IData)(vlSelfRef.__Vtogcov__valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5734, vlSelfRef.valid, vlSelfRef.__Vtogcov__valid);
        vlSelfRef.__Vtogcov__valid = vlSelfRef.valid;
    }
    if (((IData)(vlSelfRef.imem_err) ^ (IData)(vlSelfRef.__Vtogcov__imem_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5994, vlSelfRef.imem_err, vlSelfRef.__Vtogcov__imem_err);
        vlSelfRef.__Vtogcov__imem_err = vlSelfRef.imem_err;
    }
    if (((IData)(vlSelfRef.imem_gnt) ^ (IData)(vlSelfRef.__Vtogcov__imem_gnt))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5992, vlSelfRef.imem_gnt, vlSelfRef.__Vtogcov__imem_gnt);
        vlSelfRef.__Vtogcov__imem_gnt = vlSelfRef.imem_gnt;
    }
    if ((vlSelfRef.instruction ^ vlSelfRef.__Vtogcov__instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5606, vlSelfRef.instruction, vlSelfRef.__Vtogcov__instruction);
        vlSelfRef.__Vtogcov__instruction = vlSelfRef.instruction;
    }
}

VL_INLINE_OPT void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__2(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.JALR_target = vlSymsp->TOP__CoreTop.ex_jalr_target;
    vlSelfRef.branch_taken = vlSymsp->TOP__CoreTop.ex_branch_taken;
    if ((vlSelfRef.JALR_target ^ vlSelfRef.__Vtogcov__JALR_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5472, vlSelfRef.JALR_target, vlSelfRef.__Vtogcov__JALR_target);
        vlSelfRef.__Vtogcov__JALR_target = vlSelfRef.JALR_target;
    }
    if (((IData)(vlSelfRef.branch_taken) ^ (IData)(vlSelfRef.__Vtogcov__branch_taken))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5604, vlSelfRef.branch_taken, vlSelfRef.__Vtogcov__branch_taken);
        vlSelfRef.__Vtogcov__branch_taken = vlSelfRef.branch_taken;
    }
    vlSelfRef.jump_or_branch_taken = (((1U == (IData)(vlSelfRef.pc_sel_execute)) 
                                       & (IData)(vlSelfRef.branch_taken)) 
                                      | ((2U == (IData)(vlSelfRef.pc_sel_execute)) 
                                         | (3U == (IData)(vlSelfRef.pc_sel_execute))));
    if ((1U == (IData)(vlSelfRef.pc_sel_execute))) {
        vlSelfRef.next_PC = ((IData)(vlSelfRef.branch_taken)
                              ? ([&]() {
                    ++(vlSymsp->__Vcoverage[6002]);
                }(), vlSelfRef.branch_target) : ([&]() {
                    ++(vlSymsp->__Vcoverage[6003]);
                }(), vlSelfRef.PC_plus4));
        ++(vlSymsp->__Vcoverage[6004]);
    } else if ((2U == (IData)(vlSelfRef.pc_sel_execute))) {
        ++(vlSymsp->__Vcoverage[6005]);
        vlSelfRef.next_PC = vlSelfRef.JAL_target;
    } else if ((3U == (IData)(vlSelfRef.pc_sel_execute))) {
        ++(vlSymsp->__Vcoverage[6006]);
        vlSelfRef.next_PC = vlSelfRef.JALR_target;
    } else {
        ++(vlSymsp->__Vcoverage[6007]);
        vlSelfRef.next_PC = vlSelfRef.PC_plus4;
    }
    if (vlSelfRef.branch_taken) {
        ++(vlSymsp->__Vcoverage[6000]);
    }
    if ((1U & (~ (IData)(vlSelfRef.branch_taken)))) {
        ++(vlSymsp->__Vcoverage[6001]);
    }
    ++(vlSymsp->__Vcoverage[6008]);
    if (((IData)(vlSelfRef.jump_or_branch_taken) ^ (IData)(vlSelfRef.__Vtogcov__jump_or_branch_taken))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5998, vlSelfRef.jump_or_branch_taken, vlSelfRef.__Vtogcov__jump_or_branch_taken);
        vlSelfRef.__Vtogcov__jump_or_branch_taken = vlSelfRef.jump_or_branch_taken;
    }
    if ((vlSelfRef.next_PC ^ vlSelfRef.__Vtogcov__next_PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5928, vlSelfRef.next_PC, vlSelfRef.__Vtogcov__next_PC);
        vlSelfRef.__Vtogcov__next_PC = vlSelfRef.next_PC;
    }
}

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
        ++(vlSymsp->__Vcoverage[6034]);
        __Vdly__inst_PC_reg = vlSelfRef.program_address;
    } else if (vlSelfRef.stall) {
        __Vdly__inst_PC_reg = vlSelfRef.inst_PC_reg;
        ++(vlSymsp->__Vcoverage[6033]);
    } else {
        if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            ++(vlSymsp->__Vcoverage[6028]);
            __Vdly__inst_PC_reg = vlSelfRef.PC_reg;
        } else {
            ++(vlSymsp->__Vcoverage[6029]);
        }
        if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            ++(vlSymsp->__Vcoverage[6030]);
        }
        if ((1U & (~ (IData)(vlSelfRef.imem_gnt)))) {
            ++(vlSymsp->__Vcoverage[6031]);
        }
        if ((1U & (~ (IData)(vlSelfRef.fetch)))) {
            ++(vlSymsp->__Vcoverage[6032]);
        }
    }
    if (vlSelfRef.start) {
        ++(vlSymsp->__Vcoverage[6035]);
    }
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[6036]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rst)) & (~ (IData)(vlSelfRef.start))))) {
        ++(vlSymsp->__Vcoverage[6037]);
    }
    ++(vlSymsp->__Vcoverage[6038]);
    if (((IData)(vlSelfRef.rst) | (IData)(vlSelfRef.start))) {
        ++(vlSymsp->__Vcoverage[6023]);
        __Vdly__PC_reg = vlSelfRef.program_address;
    } else if (vlSelfRef.stall) {
        __Vdly__PC_reg = vlSelfRef.PC_reg;
        ++(vlSymsp->__Vcoverage[6022]);
    } else if (vlSelfRef.jump_or_branch_taken) {
        ++(vlSymsp->__Vcoverage[6021]);
        __Vdly__PC_reg = vlSelfRef.next_PC;
    } else {
        if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            ++(vlSymsp->__Vcoverage[6016]);
            __Vdly__PC_reg = vlSelfRef.PC_plus4;
        } else {
            ++(vlSymsp->__Vcoverage[6017]);
        }
        if (((IData)(vlSelfRef.fetch) & (IData)(vlSelfRef.imem_gnt))) {
            ++(vlSymsp->__Vcoverage[6018]);
        }
        if ((1U & (~ (IData)(vlSelfRef.imem_gnt)))) {
            ++(vlSymsp->__Vcoverage[6019]);
        }
        if ((1U & (~ (IData)(vlSelfRef.fetch)))) {
            ++(vlSymsp->__Vcoverage[6020]);
        }
    }
    if (vlSelfRef.start) {
        ++(vlSymsp->__Vcoverage[6024]);
    }
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[6025]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rst)) & (~ (IData)(vlSelfRef.start))))) {
        ++(vlSymsp->__Vcoverage[6026]);
    }
    ++(vlSymsp->__Vcoverage[6027]);
    vlSelfRef.inst_PC_reg = __Vdly__inst_PC_reg;
    vlSelfRef.PC_reg = __Vdly__PC_reg;
    if ((vlSelfRef.inst_PC_reg ^ vlSelfRef.__Vtogcov__inst_PC_reg)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5864, vlSelfRef.inst_PC_reg, vlSelfRef.__Vtogcov__inst_PC_reg);
        vlSelfRef.__Vtogcov__inst_PC_reg = vlSelfRef.inst_PC_reg;
    }
    vlSelfRef.inst_PC = vlSelfRef.inst_PC_reg;
    if ((vlSelfRef.PC_reg ^ vlSelfRef.__Vtogcov__PC_reg)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5736, vlSelfRef.PC_reg, vlSelfRef.__Vtogcov__PC_reg);
        vlSelfRef.__Vtogcov__PC_reg = vlSelfRef.PC_reg;
    }
    vlSelfRef.PC_plus4 = ((IData)(4U) + vlSelfRef.PC_reg);
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[6014]);
        vlSelfRef.fetch = 0U;
    } else {
        if (((IData)(vlSelfRef.start) | (IData)(vlSelfRef.stall))) {
            ++(vlSymsp->__Vcoverage[6009]);
            vlSelfRef.fetch = 1U;
        } else {
            ++(vlSymsp->__Vcoverage[6010]);
            vlSelfRef.fetch = 1U;
        }
        if (vlSelfRef.stall) {
            ++(vlSymsp->__Vcoverage[6011]);
        }
        if (vlSelfRef.start) {
            ++(vlSymsp->__Vcoverage[6012]);
        }
        if ((1U & ((~ (IData)(vlSelfRef.start)) & (~ (IData)(vlSelfRef.stall))))) {
            ++(vlSymsp->__Vcoverage[6013]);
        }
    }
    ++(vlSymsp->__Vcoverage[6015]);
    if ((vlSelfRef.inst_PC ^ vlSelfRef.__Vtogcov__inst_PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5670, vlSelfRef.inst_PC, vlSelfRef.__Vtogcov__inst_PC);
        vlSelfRef.__Vtogcov__inst_PC = vlSelfRef.inst_PC;
    }
    if ((vlSelfRef.PC_plus4 ^ vlSelfRef.__Vtogcov__PC_plus4)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5800, vlSelfRef.PC_plus4, vlSelfRef.__Vtogcov__PC_plus4);
        vlSelfRef.__Vtogcov__PC_plus4 = vlSelfRef.PC_plus4;
    }
    if (((IData)(vlSelfRef.fetch) ^ (IData)(vlSelfRef.__Vtogcov__fetch))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5996, vlSelfRef.fetch, vlSelfRef.__Vtogcov__fetch);
        vlSelfRef.__Vtogcov__fetch = vlSelfRef.fetch;
    }
}

VL_INLINE_OPT void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.valid = vlSymsp->TOP__CoreTop__u_ifu__IMem.ack;
    vlSelfRef.instruction = vlSymsp->TOP__CoreTop__u_ifu__IMem.rdata;
    if (((IData)(vlSelfRef.valid) ^ (IData)(vlSelfRef.__Vtogcov__valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5734, vlSelfRef.valid, vlSelfRef.__Vtogcov__valid);
        vlSelfRef.__Vtogcov__valid = vlSelfRef.valid;
    }
    if ((vlSelfRef.instruction ^ vlSelfRef.__Vtogcov__instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5606, vlSelfRef.instruction, vlSelfRef.__Vtogcov__instruction);
        vlSelfRef.__Vtogcov__instruction = vlSelfRef.instruction;
    }
}

VL_INLINE_OPT void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__2(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.JAL_target = vlSymsp->TOP__CoreTop.id_jal_target;
    vlSelfRef.pc_sel_execute = vlSymsp->TOP__CoreTop.id_pc_sel;
    vlSelfRef.branch_target = vlSymsp->TOP__CoreTop.id_branch_target;
    if ((vlSelfRef.JAL_target ^ vlSelfRef.__Vtogcov__JAL_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5408, vlSelfRef.JAL_target, vlSelfRef.__Vtogcov__JAL_target);
        vlSelfRef.__Vtogcov__JAL_target = vlSelfRef.JAL_target;
    }
    if (((IData)(vlSelfRef.pc_sel_execute) ^ (IData)(vlSelfRef.__Vtogcov__pc_sel_execute))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 5600, vlSelfRef.pc_sel_execute, vlSelfRef.__Vtogcov__pc_sel_execute);
        vlSelfRef.__Vtogcov__pc_sel_execute = vlSelfRef.pc_sel_execute;
    }
    if ((vlSelfRef.branch_target ^ vlSelfRef.__Vtogcov__branch_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5536, vlSelfRef.branch_target, vlSelfRef.__Vtogcov__branch_target);
        vlSelfRef.__Vtogcov__branch_target = vlSelfRef.branch_target;
    }
}

VL_INLINE_OPT void VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__0(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.JALR_target = vlSymsp->TOP__CoreTop.ex_jalr_target;
    vlSelfRef.branch_taken = vlSymsp->TOP__CoreTop.ex_branch_taken;
    if ((vlSelfRef.JALR_target ^ vlSelfRef.__Vtogcov__JALR_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5472, vlSelfRef.JALR_target, vlSelfRef.__Vtogcov__JALR_target);
        vlSelfRef.__Vtogcov__JALR_target = vlSelfRef.JALR_target;
    }
    if (((IData)(vlSelfRef.branch_taken) ^ (IData)(vlSelfRef.__Vtogcov__branch_taken))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5604, vlSelfRef.branch_taken, vlSelfRef.__Vtogcov__branch_taken);
        vlSelfRef.__Vtogcov__branch_taken = vlSelfRef.branch_taken;
    }
    vlSelfRef.jump_or_branch_taken = (((1U == (IData)(vlSelfRef.pc_sel_execute)) 
                                       & (IData)(vlSelfRef.branch_taken)) 
                                      | ((2U == (IData)(vlSelfRef.pc_sel_execute)) 
                                         | (3U == (IData)(vlSelfRef.pc_sel_execute))));
    if (((IData)(vlSelfRef.jump_or_branch_taken) ^ (IData)(vlSelfRef.__Vtogcov__jump_or_branch_taken))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5998, vlSelfRef.jump_or_branch_taken, vlSelfRef.__Vtogcov__jump_or_branch_taken);
        vlSelfRef.__Vtogcov__jump_or_branch_taken = vlSelfRef.jump_or_branch_taken;
    }
}

VL_INLINE_OPT void VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U == (IData)(vlSelfRef.pc_sel_execute))) {
        vlSelfRef.next_PC = ((IData)(vlSelfRef.branch_taken)
                              ? ([&]() {
                    ++(vlSymsp->__Vcoverage[6002]);
                }(), vlSelfRef.branch_target) : ([&]() {
                    ++(vlSymsp->__Vcoverage[6003]);
                }(), vlSelfRef.PC_plus4));
        ++(vlSymsp->__Vcoverage[6004]);
    } else if ((2U == (IData)(vlSelfRef.pc_sel_execute))) {
        ++(vlSymsp->__Vcoverage[6005]);
        vlSelfRef.next_PC = vlSelfRef.JAL_target;
    } else if ((3U == (IData)(vlSelfRef.pc_sel_execute))) {
        ++(vlSymsp->__Vcoverage[6006]);
        vlSelfRef.next_PC = vlSelfRef.JALR_target;
    } else {
        ++(vlSymsp->__Vcoverage[6007]);
        vlSelfRef.next_PC = vlSelfRef.PC_plus4;
    }
    if (vlSelfRef.branch_taken) {
        ++(vlSymsp->__Vcoverage[6000]);
    }
    if ((1U & (~ (IData)(vlSelfRef.branch_taken)))) {
        ++(vlSymsp->__Vcoverage[6001]);
    }
    ++(vlSymsp->__Vcoverage[6008]);
    if ((vlSelfRef.next_PC ^ vlSelfRef.__Vtogcov__next_PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5928, vlSelfRef.next_PC, vlSelfRef.__Vtogcov__next_PC);
        vlSelfRef.__Vtogcov__next_PC = vlSelfRef.next_PC;
    }
}
