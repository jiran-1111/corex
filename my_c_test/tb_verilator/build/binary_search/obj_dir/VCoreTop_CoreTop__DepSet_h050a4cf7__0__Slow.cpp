// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_CoreTop.h"
#include "VCoreTop__Syms.h"

VL_ATTR_COLD void VCoreTop_CoreTop___eval_initial__TOP__CoreTop(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___eval_initial__TOP__CoreTop\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.stall = 0U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x1000U, vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[(0xfffU 
                                               & vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i)] = 0U;
        ++(vlSymsp->__Vcoverage[5225]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i);
    }
    ++(vlSymsp->__Vcoverage[5227]);
    ++(vlSymsp->__Vcoverage[5228]);
    vlSelfRef.u_dmem__DOT__dmem__DOT__gnt = 1U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__err = 0U;
    vlSelfRef.u_ex_mem_reg__DOT__flush = 0U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 0U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 1U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 2U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 3U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 4U;
}

VL_ATTR_COLD void VCoreTop_CoreTop___stl_sequent__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___stl_sequent__TOP__CoreTop__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    if (((IData)(vlSelfRef.stall) ^ (IData)(vlSelfRef.__Vtogcov__stall))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 70, vlSelfRef.stall, vlSelfRef.__Vtogcov__stall);
        vlSelfRef.__Vtogcov__stall = vlSelfRef.stall;
    }
    if (((IData)(vlSelfRef.flush_d) ^ (IData)(vlSelfRef.__Vtogcov__flush_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1410, vlSelfRef.flush_d, vlSelfRef.__Vtogcov__flush_d);
        vlSelfRef.__Vtogcov__flush_d = vlSelfRef.flush_d;
    }
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__ctrl_q) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1697, vlSelfRef.u_if_id_reg__DOT__ctrl_q, vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_q);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_q 
            = vlSelfRef.u_if_id_reg__DOT__ctrl_q;
    }
    if ((vlSelfRef.u_if_id_reg__DOT__data_q ^ vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_q)) {
        VL_COV_TOGGLE_CHG_ST_Q(64, vlSymsp->__Vcoverage + 1699, vlSelfRef.u_if_id_reg__DOT__data_q, vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_q);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_q 
            = vlSelfRef.u_if_id_reg__DOT__data_q;
    }
    if ((vlSelfRef.u_decoder__DOT__uj_imm ^ vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(20, vlSymsp->__Vcoverage + 2934, vlSelfRef.u_decoder__DOT__uj_imm, vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm);
        vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm 
            = vlSelfRef.u_decoder__DOT__uj_imm;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__flush) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__flush))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4524, vlSelfRef.u_ex_mem_reg__DOT__flush, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__flush);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__flush 
            = vlSelfRef.u_ex_mem_reg__DOT__flush;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__ctrl_q) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4840, vlSelfRef.u_ex_mem_reg__DOT__ctrl_q, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_q);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_q 
            = vlSelfRef.u_ex_mem_reg__DOT__ctrl_q;
    }
    __Vtemp_1[0U] = (vlSelfRef.u_ex_mem_reg__DOT__data_q[0U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[0U]);
    __Vtemp_1[1U] = (vlSelfRef.u_ex_mem_reg__DOT__data_q[1U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[1U]);
    __Vtemp_1[2U] = (vlSelfRef.u_ex_mem_reg__DOT__data_q[2U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[2U]);
    if (__Vtemp_1) {
        VL_COV_TOGGLE_CHG_ST_W(77, vlSymsp->__Vcoverage + 4842, vlSelfRef.u_ex_mem_reg__DOT__data_q, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[0U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_q[0U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[1U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_q[1U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[2U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_q[2U];
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__gnt))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5229, vlSelfRef.u_dmem__DOT__dmem__DOT__gnt, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__gnt);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__gnt 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__gnt;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__err) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5231, vlSelfRef.u_dmem__DOT__dmem__DOT__err, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__err);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__err 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__err;
    }
    vlSelfRef.u_execute__DOT__stall = vlSelfRef.stall;
    vlSelfRef.program_address = vlSymsp->TOP.program_address;
    vlSelfRef.start = vlSymsp->TOP.start;
    vlSelfRef.u_ex_mem_reg__DOT__en = (1U & (~ (IData)(vlSelfRef.stall)));
    vlSelfRef.u_dmem__DOT__wack = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack;
    vlSelfRef.clk = vlSymsp->TOP.clk;
    vlSelfRef.rst = vlSymsp->TOP.rst;
    vlSelfRef.u_ex_mem_reg__DOT__ctrl_out = vlSelfRef.u_ex_mem_reg__DOT__ctrl_q;
    vlSelfRef.u_ex_mem_reg__DOT__data_out[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[0U];
    vlSelfRef.u_ex_mem_reg__DOT__data_out[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[1U];
    vlSelfRef.u_ex_mem_reg__DOT__data_out[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[2U];
    vlSelfRef.u_if_id_reg__DOT__ctrl_out = vlSelfRef.u_if_id_reg__DOT__ctrl_q;
    vlSelfRef.u_if_id_reg__DOT__data_out = vlSelfRef.u_if_id_reg__DOT__data_q;
    if (((IData)(vlSelfRef.u_execute__DOT__stall) ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__stall))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3433, vlSelfRef.u_execute__DOT__stall, vlSelfRef.u_execute__DOT____Vtogcov__stall);
        vlSelfRef.u_execute__DOT____Vtogcov__stall 
            = vlSelfRef.u_execute__DOT__stall;
    }
    if ((vlSelfRef.program_address ^ vlSelfRef.__Vtogcov__program_address)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6, vlSelfRef.program_address, vlSelfRef.__Vtogcov__program_address);
        vlSelfRef.__Vtogcov__program_address = vlSelfRef.program_address;
    }
    if (((IData)(vlSelfRef.start) ^ (IData)(vlSelfRef.__Vtogcov__start))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4, vlSelfRef.start, vlSelfRef.__Vtogcov__start);
        vlSelfRef.__Vtogcov__start = vlSelfRef.start;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__en) ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4526, vlSelfRef.u_ex_mem_reg__DOT__en, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__en);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__en 
            = vlSelfRef.u_ex_mem_reg__DOT__en;
    }
    vlSelfRef.u_if_id_reg__DOT__en = vlSelfRef.u_ex_mem_reg__DOT__en;
    if (((IData)(vlSelfRef.u_dmem__DOT__wack) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__wack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5153, vlSelfRef.u_dmem__DOT__wack, vlSelfRef.u_dmem__DOT____Vtogcov__wack);
        vlSelfRef.u_dmem__DOT____Vtogcov__wack = vlSelfRef.u_dmem__DOT__wack;
    }
    vlSelfRef.dmem_wack = vlSelfRef.u_dmem__DOT__wack;
    if (((IData)(vlSelfRef.clk) ^ (IData)(vlSelfRef.__Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 0, vlSelfRef.clk, vlSelfRef.__Vtogcov__clk);
        vlSelfRef.__Vtogcov__clk = vlSelfRef.clk;
    }
    vlSelfRef.u_if_id_reg__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_control_unit__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_execute__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_ex_mem_reg__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_decoder__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_dmem__DOT__clk = vlSelfRef.clk;
    if (((IData)(vlSelfRef.rst) ^ (IData)(vlSelfRef.__Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 2, vlSelfRef.rst, vlSelfRef.__Vtogcov__rst);
        vlSelfRef.__Vtogcov__rst = vlSelfRef.rst;
    }
    vlSelfRef.u_if_id_reg__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_control_unit__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_execute__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_ex_mem_reg__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_decoder__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_dmem__DOT__rst = vlSelfRef.rst;
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__ctrl_out) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4530, vlSelfRef.u_ex_mem_reg__DOT__ctrl_out, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_out);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_out 
            = vlSelfRef.u_ex_mem_reg__DOT__ctrl_out;
    }
    vlSelfRef.mem_ctrl_out = vlSelfRef.u_ex_mem_reg__DOT__ctrl_out;
    __Vtemp_2[0U] = (vlSelfRef.u_ex_mem_reg__DOT__data_out[0U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[0U]);
    __Vtemp_2[1U] = (vlSelfRef.u_ex_mem_reg__DOT__data_out[1U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[1U]);
    __Vtemp_2[2U] = (vlSelfRef.u_ex_mem_reg__DOT__data_out[2U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[2U]);
    if (__Vtemp_2) {
        VL_COV_TOGGLE_CHG_ST_W(77, vlSymsp->__Vcoverage + 4686, vlSelfRef.u_ex_mem_reg__DOT__data_out, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[0U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_out[0U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[1U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_out[1U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[2U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_out[2U];
    }
    vlSelfRef.mem_data_out[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[0U];
    vlSelfRef.mem_data_out[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[1U];
    vlSelfRef.mem_data_out[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[2U];
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__ctrl_out) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1439, vlSelfRef.u_if_id_reg__DOT__ctrl_out, vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_out);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_out 
            = vlSelfRef.u_if_id_reg__DOT__ctrl_out;
    }
    vlSelfRef.id_valid = vlSelfRef.u_if_id_reg__DOT__ctrl_out;
    if ((vlSelfRef.u_if_id_reg__DOT__data_out ^ vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_out)) {
        VL_COV_TOGGLE_CHG_ST_Q(64, vlSymsp->__Vcoverage + 1569, vlSelfRef.u_if_id_reg__DOT__data_out, vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_out);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_out 
            = vlSelfRef.u_if_id_reg__DOT__data_out;
    }
    vlSelfRef.id_pc = (IData)((vlSelfRef.u_if_id_reg__DOT__data_out 
                               >> 0x20U));
    vlSelfRef.id_instruction = (IData)(vlSelfRef.u_if_id_reg__DOT__data_out);
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__en) ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1435, vlSelfRef.u_if_id_reg__DOT__en, vlSelfRef.u_if_id_reg__DOT____Vtogcov__en);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__en = vlSelfRef.u_if_id_reg__DOT__en;
    }
    if (((IData)(vlSelfRef.dmem_wack) ^ (IData)(vlSelfRef.__Vtogcov__dmem_wack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1406, vlSelfRef.dmem_wack, vlSelfRef.__Vtogcov__dmem_wack);
        vlSelfRef.__Vtogcov__dmem_wack = vlSelfRef.dmem_wack;
    }
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__clk) ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1429, vlSelfRef.u_if_id_reg__DOT__clk, vlSelfRef.u_if_id_reg__DOT____Vtogcov__clk);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__clk 
            = vlSelfRef.u_if_id_reg__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_control_unit__DOT__clk) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1836, vlSelfRef.u_control_unit__DOT__clk, vlSelfRef.u_control_unit__DOT____Vtogcov__clk);
        vlSelfRef.u_control_unit__DOT____Vtogcov__clk 
            = vlSelfRef.u_control_unit__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__clk) ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3429, vlSelfRef.u_execute__DOT__clk, vlSelfRef.u_execute__DOT____Vtogcov__clk);
        vlSelfRef.u_execute__DOT____Vtogcov__clk = vlSelfRef.u_execute__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__clk) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4520, vlSelfRef.u_ex_mem_reg__DOT__clk, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__clk);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__clk 
            = vlSelfRef.u_ex_mem_reg__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__clk) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1934, vlSelfRef.u_decoder__DOT__clk, vlSelfRef.u_decoder__DOT____Vtogcov__clk);
        vlSelfRef.u_decoder__DOT____Vtogcov__clk = vlSelfRef.u_decoder__DOT__clk;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__clk = vlSelfRef.u_decoder__DOT__clk;
    if (((IData)(vlSelfRef.u_dmem__DOT__clk) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5005, vlSelfRef.u_dmem__DOT__clk, vlSelfRef.u_dmem__DOT____Vtogcov__clk);
        vlSelfRef.u_dmem__DOT____Vtogcov__clk = vlSelfRef.u_dmem__DOT__clk;
    }
    vlSelfRef.u_dmem__DOT__dmem__DOT__clk = vlSelfRef.u_dmem__DOT__clk;
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__rst) ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1431, vlSelfRef.u_if_id_reg__DOT__rst, vlSelfRef.u_if_id_reg__DOT____Vtogcov__rst);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__rst 
            = vlSelfRef.u_if_id_reg__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_control_unit__DOT__rst) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1838, vlSelfRef.u_control_unit__DOT__rst, vlSelfRef.u_control_unit__DOT____Vtogcov__rst);
        vlSelfRef.u_control_unit__DOT____Vtogcov__rst 
            = vlSelfRef.u_control_unit__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__rst) ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3431, vlSelfRef.u_execute__DOT__rst, vlSelfRef.u_execute__DOT____Vtogcov__rst);
        vlSelfRef.u_execute__DOT____Vtogcov__rst = vlSelfRef.u_execute__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__rst) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4522, vlSelfRef.u_ex_mem_reg__DOT__rst, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__rst);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__rst 
            = vlSelfRef.u_ex_mem_reg__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__rst) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1936, vlSelfRef.u_decoder__DOT__rst, vlSelfRef.u_decoder__DOT____Vtogcov__rst);
        vlSelfRef.u_decoder__DOT____Vtogcov__rst = vlSelfRef.u_decoder__DOT__rst;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst = vlSelfRef.u_decoder__DOT__rst;
    if (((IData)(vlSelfRef.u_dmem__DOT__rst) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5007, vlSelfRef.u_dmem__DOT__rst, vlSelfRef.u_dmem__DOT____Vtogcov__rst);
        vlSelfRef.u_dmem__DOT____Vtogcov__rst = vlSelfRef.u_dmem__DOT__rst;
    }
    vlSelfRef.u_dmem__DOT__dmem__DOT__rst = vlSelfRef.u_dmem__DOT__rst;
    if (((IData)(vlSelfRef.mem_ctrl_out) ^ (IData)(vlSelfRef.__Vtogcov__mem_ctrl_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1028, vlSelfRef.mem_ctrl_out, vlSelfRef.__Vtogcov__mem_ctrl_out);
        vlSelfRef.__Vtogcov__mem_ctrl_out = vlSelfRef.mem_ctrl_out;
    }
    if ((0x1000U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1184, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 0xcU), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                           >> 0xcU));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0xfffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x1000U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x800U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1186, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 0xbU), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                           >> 0xbU));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x17ffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x800U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x400U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1188, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 0xaU), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                           >> 0xaU));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1bffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x400U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x200U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1190, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 9U), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                         >> 9U));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1dffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x200U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0xfU & (((vlSelfRef.mem_data_out[2U] << 0x1bU) 
                  | (vlSelfRef.mem_data_out[2U] >> 5U)) 
                 ^ ((vlSelfRef.__Vtogcov__mem_data_out[2U] 
                     << 0x1bU) | (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                  >> 5U))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 1192, 
                               ((vlSelfRef.mem_data_out[2U] 
                                 << 0x1bU) | (vlSelfRef.mem_data_out[2U] 
                                              >> 5U)), 
                               ((vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                 << 0x1bU) | (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                              >> 5U)));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1e1fU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x1e0U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x1fU & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 1200, 
                               vlSelfRef.mem_data_out[2U], 
                               vlSelfRef.__Vtogcov__mem_data_out[2U]);
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1fe0U 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x1fU 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((vlSelfRef.mem_data_out[1U] ^ vlSelfRef.__Vtogcov__mem_data_out[1U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1210, 
                               vlSelfRef.mem_data_out[1U], 
                               vlSelfRef.__Vtogcov__mem_data_out[1U]);
        vlSelfRef.__Vtogcov__mem_data_out[1U] = vlSelfRef.mem_data_out[1U];
    }
    if ((vlSelfRef.mem_data_out[0U] ^ vlSelfRef.__Vtogcov__mem_data_out[0U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1274, 
                               vlSelfRef.mem_data_out[0U], 
                               vlSelfRef.__Vtogcov__mem_data_out[0U]);
        vlSelfRef.__Vtogcov__mem_data_out[0U] = vlSelfRef.mem_data_out[0U];
    }
    vlSelfRef.u_dmem__DOT__write = (1U & (vlSelfRef.mem_data_out[2U] 
                                          >> 9U));
    vlSelfRef.u_dmem__DOT__wdata = vlSelfRef.mem_data_out[0U];
    vlSelfRef.u_dmem__DOT__wbe = (0xfU & (vlSelfRef.mem_data_out[2U] 
                                          >> 5U));
    vlSelfRef.u_dmem__DOT__read = (1U & (vlSelfRef.mem_data_out[2U] 
                                         >> 0xaU));
    vlSelfRef.wb_write_reg = (0x1fU & vlSelfRef.mem_data_out[2U]);
    vlSelfRef.wb_reg_write = ((vlSelfRef.mem_data_out[2U] 
                               >> 0xcU) & (IData)(vlSelfRef.mem_ctrl_out));
    vlSelfRef.u_dmem__DOT__addr = vlSelfRef.mem_data_out[1U];
    if (((IData)(vlSelfRef.id_valid) ^ (IData)(vlSelfRef.__Vtogcov__id_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 530, vlSelfRef.id_valid, vlSelfRef.__Vtogcov__id_valid);
        vlSelfRef.__Vtogcov__id_valid = vlSelfRef.id_valid;
    }
    vlSelfRef.u_ex_mem_reg__DOT__ctrl_in = vlSelfRef.id_valid;
    if ((vlSelfRef.id_pc ^ vlSelfRef.__Vtogcov__id_pc)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 466, vlSelfRef.id_pc, vlSelfRef.__Vtogcov__id_pc);
        vlSelfRef.__Vtogcov__id_pc = vlSelfRef.id_pc;
    }
    vlSelfRef.u_decoder__DOT__PC = vlSelfRef.id_pc;
    vlSelfRef.u_execute__DOT__PC = vlSelfRef.id_pc;
    if ((vlSelfRef.id_instruction ^ vlSelfRef.__Vtogcov__id_instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 402, vlSelfRef.id_instruction, vlSelfRef.__Vtogcov__id_instruction);
        vlSelfRef.__Vtogcov__id_instruction = vlSelfRef.id_instruction;
    }
    vlSelfRef.id_instruction_real = ((IData)(vlSelfRef.id_valid)
                                      ? ([&]() {
                ++(vlSymsp->__Vcoverage[1417]);
            }(), vlSelfRef.id_instruction) : ([&]() {
                ++(vlSymsp->__Vcoverage[1418]);
            }(), 0x13U));
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__clk) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3189, vlSelfRef.u_decoder__DOT__u_regfile__DOT__clk, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__clk);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__clk 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__clk) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5221, vlSelfRef.u_dmem__DOT__dmem__DOT__clk, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__clk);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__clk 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3191, vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rst);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rst 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__rst) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5223, vlSelfRef.u_dmem__DOT__dmem__DOT__rst, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__rst);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__rst 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__write) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5011, vlSelfRef.u_dmem__DOT__write, vlSelfRef.u_dmem__DOT____Vtogcov__write);
        vlSelfRef.u_dmem__DOT____Vtogcov__write = vlSelfRef.u_dmem__DOT__write;
    }
    if ((vlSelfRef.u_dmem__DOT__wdata ^ vlSelfRef.u_dmem__DOT____Vtogcov__wdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5077, vlSelfRef.u_dmem__DOT__wdata, vlSelfRef.u_dmem__DOT____Vtogcov__wdata);
        vlSelfRef.u_dmem__DOT____Vtogcov__wdata = vlSelfRef.u_dmem__DOT__wdata;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__wbe) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 5141, vlSelfRef.u_dmem__DOT__wbe, vlSelfRef.u_dmem__DOT____Vtogcov__wbe);
        vlSelfRef.u_dmem__DOT____Vtogcov__wbe = vlSelfRef.u_dmem__DOT__wbe;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__read) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__read))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5009, vlSelfRef.u_dmem__DOT__read, vlSelfRef.u_dmem__DOT____Vtogcov__read);
        vlSelfRef.u_dmem__DOT____Vtogcov__read = vlSelfRef.u_dmem__DOT__read;
    }
    if (((IData)(vlSelfRef.wb_write_reg) ^ (IData)(vlSelfRef.__Vtogcov__wb_write_reg))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 954, vlSelfRef.wb_write_reg, vlSelfRef.__Vtogcov__wb_write_reg);
        vlSelfRef.__Vtogcov__wb_write_reg = vlSelfRef.wb_write_reg;
    }
    vlSelfRef.u_decoder__DOT__write_reg = vlSelfRef.wb_write_reg;
    if (((IData)(vlSelfRef.wb_reg_write) ^ (IData)(vlSelfRef.__Vtogcov__wb_reg_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 952, vlSelfRef.wb_reg_write, vlSelfRef.__Vtogcov__wb_reg_write);
        vlSelfRef.__Vtogcov__wb_reg_write = vlSelfRef.wb_reg_write;
    }
    vlSelfRef.u_decoder__DOT__reg_write = vlSelfRef.wb_reg_write;
    if ((vlSelfRef.u_dmem__DOT__addr ^ vlSelfRef.u_dmem__DOT____Vtogcov__addr)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5013, vlSelfRef.u_dmem__DOT__addr, vlSelfRef.u_dmem__DOT____Vtogcov__addr);
        vlSelfRef.u_dmem__DOT____Vtogcov__addr = vlSelfRef.u_dmem__DOT__addr;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__ctrl_in) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_in))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4528, vlSelfRef.u_ex_mem_reg__DOT__ctrl_in, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_in);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_in 
            = vlSelfRef.u_ex_mem_reg__DOT__ctrl_in;
    }
    if ((vlSelfRef.u_decoder__DOT__PC ^ vlSelfRef.u_decoder__DOT____Vtogcov__PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2002, vlSelfRef.u_decoder__DOT__PC, vlSelfRef.u_decoder__DOT____Vtogcov__PC);
        vlSelfRef.u_decoder__DOT____Vtogcov__PC = vlSelfRef.u_decoder__DOT__PC;
    }
    if ((vlSelfRef.u_execute__DOT__PC ^ vlSelfRef.u_execute__DOT____Vtogcov__PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3467, vlSelfRef.u_execute__DOT__PC, vlSelfRef.u_execute__DOT____Vtogcov__PC);
        vlSelfRef.u_execute__DOT____Vtogcov__PC = vlSelfRef.u_execute__DOT__PC;
    }
    if ((vlSelfRef.id_instruction_real ^ vlSelfRef.__Vtogcov__id_instruction_real)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 532, vlSelfRef.id_instruction_real, vlSelfRef.__Vtogcov__id_instruction_real);
        vlSelfRef.__Vtogcov__id_instruction_real = vlSelfRef.id_instruction_real;
    }
    vlSelfRef.u_decoder__DOT__instruction = vlSelfRef.id_instruction_real;
    if (((IData)(vlSelfRef.u_decoder__DOT__write_reg) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__write_reg))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2074, vlSelfRef.u_decoder__DOT__write_reg, vlSelfRef.u_decoder__DOT____Vtogcov__write_reg);
        vlSelfRef.u_decoder__DOT____Vtogcov__write_reg 
            = vlSelfRef.u_decoder__DOT__write_reg;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr 
        = vlSelfRef.u_decoder__DOT__write_reg;
    if (((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__reg_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 2072, vlSelfRef.u_decoder__DOT__reg_write, vlSelfRef.u_decoder__DOT____Vtogcov__reg_write);
        vlSelfRef.u_decoder__DOT____Vtogcov__reg_write 
            = vlSelfRef.u_decoder__DOT__reg_write;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen = vlSelfRef.u_decoder__DOT__reg_write;
    if ((vlSelfRef.u_decoder__DOT__instruction ^ vlSelfRef.u_decoder__DOT____Vtogcov__instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1938, vlSelfRef.u_decoder__DOT__instruction, vlSelfRef.u_decoder__DOT____Vtogcov__instruction);
        vlSelfRef.u_decoder__DOT____Vtogcov__instruction 
            = vlSelfRef.u_decoder__DOT__instruction;
    }
    vlSelfRef.u_decoder__DOT__funct3 = (7U & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0xcU));
    vlSelfRef.u_decoder__DOT__u_imm = (vlSelfRef.u_decoder__DOT__instruction 
                                       >> 0xcU);
    vlSelfRef.u_decoder__DOT__i_imm_orig = (vlSelfRef.u_decoder__DOT__instruction 
                                            >> 0x14U);
    vlSelfRef.u_decoder__DOT__uj_imm_32 = (((- (IData)(
                                                       (vlSelfRef.u_decoder__DOT__instruction 
                                                        >> 0x1fU))) 
                                            << 0x14U) 
                                           | (((0xff000U 
                                                & vlSelfRef.u_decoder__DOT__instruction) 
                                               | (0x800U 
                                                  & (vlSelfRef.u_decoder__DOT__instruction 
                                                     >> 9U))) 
                                              | (0x7feU 
                                                 & (vlSelfRef.u_decoder__DOT__instruction 
                                                    >> 0x14U))));
    vlSelfRef.u_decoder__DOT__rs1 = (0x1fU & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0xfU));
    vlSelfRef.u_decoder__DOT__rs2 = (0x1fU & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0x14U));
    vlSelfRef.u_decoder__DOT__rd = (0x1fU & (vlSelfRef.u_decoder__DOT__instruction 
                                             >> 7U));
    vlSelfRef.u_decoder__DOT__funct7 = (vlSelfRef.u_decoder__DOT__instruction 
                                        >> 0x19U);
    vlSelfRef.u_decoder__DOT__opcode = (0x7fU & vlSelfRef.u_decoder__DOT__instruction);
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__waddr))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 3195, vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__waddr);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__waddr 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wen))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3193, vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wen);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wen 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__funct3) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__funct3))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 2176, vlSelfRef.u_decoder__DOT__funct3, vlSelfRef.u_decoder__DOT____Vtogcov__funct3);
        vlSelfRef.u_decoder__DOT____Vtogcov__funct3 
            = vlSelfRef.u_decoder__DOT__funct3;
    }
    vlSelfRef.id_funct3 = vlSelfRef.u_decoder__DOT__funct3;
    if ((vlSelfRef.u_decoder__DOT__u_imm ^ vlSelfRef.u_decoder__DOT____Vtogcov__u_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(20, vlSymsp->__Vcoverage + 2564, vlSelfRef.u_decoder__DOT__u_imm, vlSelfRef.u_decoder__DOT____Vtogcov__u_imm);
        vlSelfRef.u_decoder__DOT____Vtogcov__u_imm 
            = vlSelfRef.u_decoder__DOT__u_imm;
    }
    vlSelfRef.u_decoder__DOT__u_imm_32 = (vlSelfRef.u_decoder__DOT__u_imm 
                                          << 0xcU);
    if (((IData)(vlSelfRef.u_decoder__DOT__i_imm_orig) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_orig))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 2540, vlSelfRef.u_decoder__DOT__i_imm_orig, vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_orig);
        vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_orig 
            = vlSelfRef.u_decoder__DOT__i_imm_orig;
    }
    vlSelfRef.u_decoder__DOT__i_imm_32 = (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.u_decoder__DOT__i_imm_orig) 
                                                          >> 0xbU)))) 
                                           << 0xcU) 
                                          | (IData)(vlSelfRef.u_decoder__DOT__i_imm_orig));
    if ((vlSelfRef.u_decoder__DOT__uj_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2974, vlSelfRef.u_decoder__DOT__uj_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm_32 
            = vlSelfRef.u_decoder__DOT__uj_imm_32;
    }
    vlSelfRef.u_decoder__DOT__JAL_target = (vlSelfRef.u_decoder__DOT__PC 
                                            + vlSelfRef.u_decoder__DOT__uj_imm_32);
    if (((IData)(vlSelfRef.u_decoder__DOT__rs1) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs1))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2182, vlSelfRef.u_decoder__DOT__rs1, vlSelfRef.u_decoder__DOT____Vtogcov__rs1);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1 = vlSelfRef.u_decoder__DOT__rs1;
    }
    vlSelfRef.id_rs1 = vlSelfRef.u_decoder__DOT__rs1;
    vlSelfRef.u_decoder__DOT__rs1_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs1) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((0U 
                                                     != (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                    & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.u_decoder__DOT__rs1)))));
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1 
        = vlSelfRef.u_decoder__DOT__rs1;
    if (((IData)(vlSelfRef.u_decoder__DOT__rs2) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs2))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2192, vlSelfRef.u_decoder__DOT__rs2, vlSelfRef.u_decoder__DOT____Vtogcov__rs2);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2 = vlSelfRef.u_decoder__DOT__rs2;
    }
    vlSelfRef.id_rs2 = vlSelfRef.u_decoder__DOT__rs2;
    vlSelfRef.u_decoder__DOT__rs2_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs2) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                    & (0U 
                                                       != (IData)(vlSelfRef.u_decoder__DOT__rs2))));
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2 
        = vlSelfRef.u_decoder__DOT__rs2;
    if (((IData)(vlSelfRef.u_decoder__DOT__rd) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rd))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2202, vlSelfRef.u_decoder__DOT__rd, vlSelfRef.u_decoder__DOT____Vtogcov__rd);
        vlSelfRef.u_decoder__DOT____Vtogcov__rd = vlSelfRef.u_decoder__DOT__rd;
    }
    vlSelfRef.id_rd = vlSelfRef.u_decoder__DOT__rd;
    vlSelfRef.u_decoder__DOT__s_imm_lsb = vlSelfRef.u_decoder__DOT__rd;
    if (((IData)(vlSelfRef.u_decoder__DOT__funct7) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__funct7))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 2162, vlSelfRef.u_decoder__DOT__funct7, vlSelfRef.u_decoder__DOT____Vtogcov__funct7);
        vlSelfRef.u_decoder__DOT____Vtogcov__funct7 
            = vlSelfRef.u_decoder__DOT__funct7;
    }
    vlSelfRef.id_funct7 = vlSelfRef.u_decoder__DOT__funct7;
    vlSelfRef.u_decoder__DOT__s_imm_msb = vlSelfRef.u_decoder__DOT__funct7;
    if (((IData)(vlSelfRef.u_decoder__DOT__opcode) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__opcode))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 2148, vlSelfRef.u_decoder__DOT__opcode, vlSelfRef.u_decoder__DOT____Vtogcov__opcode);
        vlSelfRef.u_decoder__DOT____Vtogcov__opcode 
            = vlSelfRef.u_decoder__DOT__opcode;
    }
    if ((0x23U == (IData)(vlSelfRef.u_decoder__DOT__opcode))) {
        if ((0U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            vlSelfRef.u_decoder__DOT__mem_wbe = 1U;
            ++(vlSymsp->__Vcoverage[3182]);
        } else if ((1U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            ++(vlSymsp->__Vcoverage[3183]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 3U;
        } else if ((2U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            ++(vlSymsp->__Vcoverage[3184]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 0xfU;
        } else {
            ++(vlSymsp->__Vcoverage[3185]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 0U;
        }
        ++(vlSymsp->__Vcoverage[3186]);
    } else {
        ++(vlSymsp->__Vcoverage[3187]);
        vlSelfRef.u_decoder__DOT__mem_wbe = 0U;
    }
    ++(vlSymsp->__Vcoverage[3188]);
    vlSelfRef.id_opcode = vlSelfRef.u_decoder__DOT__opcode;
    if (((IData)(vlSelfRef.id_funct3) ^ (IData)(vlSelfRef.__Vtogcov__id_funct3))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 652, vlSelfRef.id_funct3, vlSelfRef.__Vtogcov__id_funct3);
        vlSelfRef.__Vtogcov__id_funct3 = vlSelfRef.id_funct3;
    }
    vlSelfRef.u_execute__DOT__funct3 = vlSelfRef.id_funct3;
    if ((vlSelfRef.u_decoder__DOT__u_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__u_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2668, vlSelfRef.u_decoder__DOT__u_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__u_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__u_imm_32 
            = vlSelfRef.u_decoder__DOT__u_imm_32;
    }
    if ((vlSelfRef.u_decoder__DOT__i_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2604, vlSelfRef.u_decoder__DOT__i_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_32 
            = vlSelfRef.u_decoder__DOT__i_imm_32;
    }
    if ((vlSelfRef.u_decoder__DOT__JAL_target ^ vlSelfRef.u_decoder__DOT____Vtogcov__JAL_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2468, vlSelfRef.u_decoder__DOT__JAL_target, vlSelfRef.u_decoder__DOT____Vtogcov__JAL_target);
        vlSelfRef.u_decoder__DOT____Vtogcov__JAL_target 
            = vlSelfRef.u_decoder__DOT__JAL_target;
    }
    vlSelfRef.id_jal_target = vlSelfRef.u_decoder__DOT__JAL_target;
    if (((IData)(vlSelfRef.id_rs1) ^ (IData)(vlSelfRef.__Vtogcov__id_rs1))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 658, vlSelfRef.id_rs1, vlSelfRef.__Vtogcov__id_rs1);
        vlSelfRef.__Vtogcov__id_rs1 = vlSelfRef.id_rs1;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__rs1_data_bypass) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_bypass))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3038, vlSelfRef.u_decoder__DOT__rs1_data_bypass, vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_bypass);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_bypass 
            = vlSelfRef.u_decoder__DOT__rs1_data_bypass;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr1))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 3269, vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr1);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr1 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[3417]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[3418]);
            }(), vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
                        [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1]));
    if (((IData)(vlSelfRef.id_rs2) ^ (IData)(vlSelfRef.__Vtogcov__id_rs2))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 668, vlSelfRef.id_rs2, vlSelfRef.__Vtogcov__id_rs2);
        vlSelfRef.__Vtogcov__id_rs2 = vlSelfRef.id_rs2;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__rs2_data_bypass) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_bypass))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3040, vlSelfRef.u_decoder__DOT__rs2_data_bypass, vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_bypass);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_bypass 
            = vlSelfRef.u_decoder__DOT__rs2_data_bypass;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr2))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 3279, vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr2);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr2 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[3419]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[3420]);
            }(), vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
                        [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2]));
    if (((IData)(vlSelfRef.id_rd) ^ (IData)(vlSelfRef.__Vtogcov__id_rd))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 678, vlSelfRef.id_rd, vlSelfRef.__Vtogcov__id_rd);
        vlSelfRef.__Vtogcov__id_rd = vlSelfRef.id_rd;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_lsb))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2746, vlSelfRef.u_decoder__DOT__s_imm_lsb, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_lsb);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_lsb 
            = vlSelfRef.u_decoder__DOT__s_imm_lsb;
    }
    if (((IData)(vlSelfRef.id_funct7) ^ (IData)(vlSelfRef.__Vtogcov__id_funct7))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 638, vlSelfRef.id_funct7, vlSelfRef.__Vtogcov__id_funct7);
        vlSelfRef.__Vtogcov__id_funct7 = vlSelfRef.id_funct7;
    }
    vlSelfRef.u_execute__DOT__funct7 = vlSelfRef.id_funct7;
    if (((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 2732, vlSelfRef.u_decoder__DOT__s_imm_msb, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_msb);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_msb 
            = vlSelfRef.u_decoder__DOT__s_imm_msb;
    }
    vlSelfRef.u_decoder__DOT__s_imm_orig = (((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
                                             << 5U) 
                                            | (IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb));
    vlSelfRef.u_decoder__DOT__sb_imm_orig = (((0x1000U 
                                               & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
                                                  << 6U)) 
                                              | (0x800U 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb) 
                                                    << 0xbU))) 
                                             | ((0x7e0U 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
                                                    << 5U)) 
                                                | (0x1eU 
                                                   & (IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb))));
    if (((IData)(vlSelfRef.u_decoder__DOT__mem_wbe) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__mem_wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 2532, vlSelfRef.u_decoder__DOT__mem_wbe, vlSelfRef.u_decoder__DOT____Vtogcov__mem_wbe);
        vlSelfRef.u_decoder__DOT____Vtogcov__mem_wbe 
            = vlSelfRef.u_decoder__DOT__mem_wbe;
    }
    vlSelfRef.id_mem_wbe = vlSelfRef.u_decoder__DOT__mem_wbe;
    if (((IData)(vlSelfRef.id_opcode) ^ (IData)(vlSelfRef.__Vtogcov__id_opcode))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 624, vlSelfRef.id_opcode, vlSelfRef.__Vtogcov__id_opcode);
        vlSelfRef.__Vtogcov__id_opcode = vlSelfRef.id_opcode;
    }
    vlSelfRef.u_control_unit__DOT__opcode = vlSelfRef.id_opcode;
    if (((IData)(vlSelfRef.u_execute__DOT__funct3) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__funct3))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 3455, vlSelfRef.u_execute__DOT__funct3, vlSelfRef.u_execute__DOT____Vtogcov__funct3);
        vlSelfRef.u_execute__DOT____Vtogcov__funct3 
            = vlSelfRef.u_execute__DOT__funct3;
    }
    if ((vlSelfRef.id_jal_target ^ vlSelfRef.__Vtogcov__id_jal_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 274, vlSelfRef.id_jal_target, vlSelfRef.__Vtogcov__id_jal_target);
        vlSelfRef.__Vtogcov__id_jal_target = vlSelfRef.id_jal_target;
    }
    if ((vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1 
         ^ vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata1)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3289, vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata1);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata1 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1;
    }
    vlSelfRef.u_decoder__DOT__rs1_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1;
    if ((vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2 
         ^ vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata2)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3353, vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata2);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata2 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2;
    }
    vlSelfRef.u_decoder__DOT__rs2_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2;
    if (((IData)(vlSelfRef.u_execute__DOT__funct7) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__funct7))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 3441, vlSelfRef.u_execute__DOT__funct7, vlSelfRef.u_execute__DOT____Vtogcov__funct7);
        vlSelfRef.u_execute__DOT____Vtogcov__funct7 
            = vlSelfRef.u_execute__DOT__funct7;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__s_imm_orig) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_orig))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 2756, vlSelfRef.u_decoder__DOT__s_imm_orig, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_orig);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_orig 
            = vlSelfRef.u_decoder__DOT__s_imm_orig;
    }
    vlSelfRef.u_decoder__DOT__s_imm_32 = (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_orig) 
                                                          >> 0xbU)))) 
                                           << 0xcU) 
                                          | (IData)(vlSelfRef.u_decoder__DOT__s_imm_orig));
    if (((IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_orig))) {
        VL_COV_TOGGLE_CHG_ST_I(13, vlSymsp->__Vcoverage + 2844, vlSelfRef.u_decoder__DOT__sb_imm_orig, vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_orig);
        vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_orig 
            = vlSelfRef.u_decoder__DOT__sb_imm_orig;
    }
    vlSelfRef.u_decoder__DOT__sb_imm_32 = (((- (IData)(
                                                       (1U 
                                                        & ((IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig) 
                                                           >> 0xcU)))) 
                                            << 0xdU) 
                                           | (IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig));
    if (((IData)(vlSelfRef.id_mem_wbe) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 880, vlSelfRef.id_mem_wbe, vlSelfRef.__Vtogcov__id_mem_wbe);
        vlSelfRef.__Vtogcov__id_mem_wbe = vlSelfRef.id_mem_wbe;
    }
    if (((IData)(vlSelfRef.u_control_unit__DOT__opcode) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__opcode))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 1840, vlSelfRef.u_control_unit__DOT__opcode, vlSelfRef.u_control_unit__DOT____Vtogcov__opcode);
        vlSelfRef.u_control_unit__DOT____Vtogcov__opcode 
            = vlSelfRef.u_control_unit__DOT__opcode;
    }
    vlSelfRef.u_control_unit__DOT__next_PC_sel = (3U 
                                                  & ((0x63U 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                      ? 
                                                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1928]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1933]);
                }(), ((0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[1929]);
                        }(), 2U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[1932]);
                        }(), ((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[1930]);
                                }(), 3U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[1931]);
                                }(), 0U)))))));
    vlSelfRef.u_control_unit__DOT__branch_op = (1U 
                                                & ((0x63U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[1922]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1923]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__regWrite = (1U & 
                                               ((((((((0x33U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                      | (0x13U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                     | (3U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                    | (0x67U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                   | (0x6fU 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                  | (0x17U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                 | (0x37U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[1886]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1887]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memWrite = (1U & 
                                               ((0x23U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[1920]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1921]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memRead = (1U & 
                                              ((3U 
                                                == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                ? ([&]() {
                    ++(vlSymsp->__Vcoverage[1924]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1925]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memtoReg = (1U & 
                                               ((3U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[1926]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1927]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__ALUOp = (7U & ((0x33U 
                                                   == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                   ? 
                                                  ([&]() {
                    ++(vlSymsp->__Vcoverage[1888]);
                }(), 0U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1901]);
                }(), ((0x13U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[1889]);
                        }(), 1U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[1900]);
                        }(), ((0x23U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[1890]);
                                }(), 5U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[1899]);
                                }(), ((3U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                       ? ([&]() {
                                            ++(vlSymsp->__Vcoverage[1891]);
                                        }(), 4U) : 
                                      ([&]() {
                                            ++(vlSymsp->__Vcoverage[1898]);
                                        }(), ((0x63U 
                                               == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                               ? ([&]() {
                                                    ++(vlSymsp->__Vcoverage[1892]);
                                                }(), 2U)
                                               : ([&]() {
                                                    ++(vlSymsp->__Vcoverage[1897]);
                                                }(), 
                                                  (((0x67U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                    | (0x6fU 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                    ? 
                                                   ([&]() {
                                                            ++(vlSymsp->__Vcoverage[1893]);
                                                        }(), 3U)
                                                    : 
                                                   ([&]() {
                                                            ++(vlSymsp->__Vcoverage[1896]);
                                                        }(), 
                                                    (((0x17U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                      | (0x37U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                      ? 
                                                     ([&]() {
                                                                    ++(vlSymsp->__Vcoverage[1894]);
                                                                }(), 6U)
                                                      : 
                                                     ([&]() {
                                                                    ++(vlSymsp->__Vcoverage[1895]);
                                                                }(), 0U)))))))))))))));
    vlSelfRef.u_control_unit__DOT__operand_A = (3U 
                                                & ((0x17U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[1902]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1907]);
                }(), ((0x37U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[1903]);
                        }(), 3U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[1906]);
                        }(), (((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                               | (0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[1904]);
                                }(), 2U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[1905]);
                                }(), 0U)))))));
    vlSelfRef.u_control_unit__DOT__operand_B = (1U 
                                                & ((((((0x13U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                       | (0x23U 
                                                          == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                      | (3U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                     | (0x17U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                    | (0x37U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[1908]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1909]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__extend_sel = (((
                                                   (0x13U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                   | (3U 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                  | (0x67U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                  ? 
                                                 ([&]() {
                ++(vlSymsp->__Vcoverage[1910]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[1919]);
            }(), ((0x23U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[1911]);
                    }(), 1U) : ([&]() {
                        ++(vlSymsp->__Vcoverage[1918]);
                    }(), ((0x63U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[1912]);
                            }(), 2U) : ([&]() {
                                ++(vlSymsp->__Vcoverage[1917]);
                            }(), (((0x17U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                   | (0x37U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[1913]);
                                    }(), 3U) : ([&]() {
                                        ++(vlSymsp->__Vcoverage[1916]);
                                    }(), ((0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                           ? ([&]() {
                                                ++(vlSymsp->__Vcoverage[1914]);
                                            }(), 4U)
                                           : ([&]() {
                                                ++(vlSymsp->__Vcoverage[1915]);
                                            }(), 0U))))))))));
    if ((vlSelfRef.u_decoder__DOT__rs1_data_decode 
         ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_decode)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3042, vlSelfRef.u_decoder__DOT__rs1_data_decode, vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_decode);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_decode 
            = vlSelfRef.u_decoder__DOT__rs1_data_decode;
    }
    if ((vlSelfRef.u_decoder__DOT__rs2_data_decode 
         ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_decode)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3106, vlSelfRef.u_decoder__DOT__rs2_data_decode, vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_decode);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_decode 
            = vlSelfRef.u_decoder__DOT__rs2_data_decode;
    }
    if ((vlSelfRef.u_decoder__DOT__s_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2780, vlSelfRef.u_decoder__DOT__s_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_32 
            = vlSelfRef.u_decoder__DOT__s_imm_32;
    }
    if ((vlSelfRef.u_decoder__DOT__sb_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2870, vlSelfRef.u_decoder__DOT__sb_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_32 
            = vlSelfRef.u_decoder__DOT__sb_imm_32;
    }
    vlSelfRef.u_decoder__DOT__branch_target = (vlSelfRef.u_decoder__DOT__PC 
                                               + vlSelfRef.u_decoder__DOT__sb_imm_32);
    if (((IData)(vlSelfRef.u_control_unit__DOT__next_PC_sel) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__next_PC_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 1882, vlSelfRef.u_control_unit__DOT__next_PC_sel, vlSelfRef.u_control_unit__DOT____Vtogcov__next_PC_sel);
        vlSelfRef.u_control_unit__DOT____Vtogcov__next_PC_sel 
            = vlSelfRef.u_control_unit__DOT__next_PC_sel;
    }
    vlSelfRef.id_pc_sel = vlSelfRef.u_control_unit__DOT__next_PC_sel;
    if (((IData)(vlSelfRef.u_control_unit__DOT__branch_op) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__branch_op))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1874, vlSelfRef.u_control_unit__DOT__branch_op, vlSelfRef.u_control_unit__DOT____Vtogcov__branch_op);
        vlSelfRef.u_control_unit__DOT____Vtogcov__branch_op 
            = vlSelfRef.u_control_unit__DOT__branch_op;
    }
    vlSelfRef.id_branch_op = vlSelfRef.u_control_unit__DOT__branch_op;
    if (((IData)(vlSelfRef.u_control_unit__DOT__regWrite) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__regWrite))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1872, vlSelfRef.u_control_unit__DOT__regWrite, vlSelfRef.u_control_unit__DOT____Vtogcov__regWrite);
        vlSelfRef.u_control_unit__DOT____Vtogcov__regWrite 
            = vlSelfRef.u_control_unit__DOT__regWrite;
    }
    vlSelfRef.id_reg_write = vlSelfRef.u_control_unit__DOT__regWrite;
    if (((IData)(vlSelfRef.u_control_unit__DOT__memWrite) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__memWrite))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1878, vlSelfRef.u_control_unit__DOT__memWrite, vlSelfRef.u_control_unit__DOT____Vtogcov__memWrite);
        vlSelfRef.u_control_unit__DOT____Vtogcov__memWrite 
            = vlSelfRef.u_control_unit__DOT__memWrite;
    }
    vlSelfRef.id_mem_write = vlSelfRef.u_control_unit__DOT__memWrite;
    if (((IData)(vlSelfRef.u_control_unit__DOT__memRead) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__memRead))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1876, vlSelfRef.u_control_unit__DOT__memRead, vlSelfRef.u_control_unit__DOT____Vtogcov__memRead);
        vlSelfRef.u_control_unit__DOT____Vtogcov__memRead 
            = vlSelfRef.u_control_unit__DOT__memRead;
    }
    vlSelfRef.id_mem_read = vlSelfRef.u_control_unit__DOT__memRead;
    if (((IData)(vlSelfRef.u_control_unit__DOT__memtoReg) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__memtoReg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1880, vlSelfRef.u_control_unit__DOT__memtoReg, vlSelfRef.u_control_unit__DOT____Vtogcov__memtoReg);
        vlSelfRef.u_control_unit__DOT____Vtogcov__memtoReg 
            = vlSelfRef.u_control_unit__DOT__memtoReg;
    }
    vlSelfRef.id_mem_to_reg = vlSelfRef.u_control_unit__DOT__memtoReg;
    if (((IData)(vlSelfRef.u_control_unit__DOT__ALUOp) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__ALUOp))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 1854, vlSelfRef.u_control_unit__DOT__ALUOp, vlSelfRef.u_control_unit__DOT____Vtogcov__ALUOp);
        vlSelfRef.u_control_unit__DOT____Vtogcov__ALUOp 
            = vlSelfRef.u_control_unit__DOT__ALUOp;
    }
    vlSelfRef.id_alu_op = vlSelfRef.u_control_unit__DOT__ALUOp;
    if (((IData)(vlSelfRef.u_control_unit__DOT__operand_A) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__operand_A))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 1860, vlSelfRef.u_control_unit__DOT__operand_A, vlSelfRef.u_control_unit__DOT____Vtogcov__operand_A);
        vlSelfRef.u_control_unit__DOT____Vtogcov__operand_A 
            = vlSelfRef.u_control_unit__DOT__operand_A;
    }
    vlSelfRef.id_operand_a = vlSelfRef.u_control_unit__DOT__operand_A;
    if (((IData)(vlSelfRef.u_control_unit__DOT__operand_B) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__operand_B))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1864, vlSelfRef.u_control_unit__DOT__operand_B, vlSelfRef.u_control_unit__DOT____Vtogcov__operand_B);
        vlSelfRef.u_control_unit__DOT____Vtogcov__operand_B 
            = vlSelfRef.u_control_unit__DOT__operand_B;
    }
    vlSelfRef.id_operand_b = vlSelfRef.u_control_unit__DOT__operand_B;
    if (((IData)(vlSelfRef.u_control_unit__DOT__extend_sel) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__extend_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 1866, vlSelfRef.u_control_unit__DOT__extend_sel, vlSelfRef.u_control_unit__DOT____Vtogcov__extend_sel);
        vlSelfRef.u_control_unit__DOT____Vtogcov__extend_sel 
            = vlSelfRef.u_control_unit__DOT__extend_sel;
    }
    vlSelfRef.id_extend_sel = vlSelfRef.u_control_unit__DOT__extend_sel;
    if ((vlSelfRef.u_decoder__DOT__branch_target ^ vlSelfRef.u_decoder__DOT____Vtogcov__branch_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2404, vlSelfRef.u_decoder__DOT__branch_target, vlSelfRef.u_decoder__DOT____Vtogcov__branch_target);
        vlSelfRef.u_decoder__DOT____Vtogcov__branch_target 
            = vlSelfRef.u_decoder__DOT__branch_target;
    }
    vlSelfRef.id_branch_target = vlSelfRef.u_decoder__DOT__branch_target;
    if (((IData)(vlSelfRef.id_pc_sel) ^ (IData)(vlSelfRef.__Vtogcov__id_pc_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 204, vlSelfRef.id_pc_sel, vlSelfRef.__Vtogcov__id_pc_sel);
        vlSelfRef.__Vtogcov__id_pc_sel = vlSelfRef.id_pc_sel;
    }
    if (((IData)(vlSelfRef.id_branch_op) ^ (IData)(vlSelfRef.__Vtogcov__id_branch_op))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 616, vlSelfRef.id_branch_op, vlSelfRef.__Vtogcov__id_branch_op);
        vlSelfRef.__Vtogcov__id_branch_op = vlSelfRef.id_branch_op;
    }
    vlSelfRef.u_execute__DOT__branch_op = vlSelfRef.id_branch_op;
    if (((IData)(vlSelfRef.id_reg_write) ^ (IData)(vlSelfRef.__Vtogcov__id_reg_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 614, vlSelfRef.id_reg_write, vlSelfRef.__Vtogcov__id_reg_write);
        vlSelfRef.__Vtogcov__id_reg_write = vlSelfRef.id_reg_write;
    }
    VL_ASSIGNBIT_WI(0x4cU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1419]);
                }(), (IData)(vlSelfRef.id_reg_write))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1420]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_mem_write) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 620, vlSelfRef.id_mem_write, vlSelfRef.__Vtogcov__id_mem_write);
        vlSelfRef.__Vtogcov__id_mem_write = vlSelfRef.id_mem_write;
    }
    VL_ASSIGNBIT_WI(0x49U, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1421]);
                }(), (IData)(vlSelfRef.id_mem_write))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1422]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_mem_read) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_read))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 618, vlSelfRef.id_mem_read, vlSelfRef.__Vtogcov__id_mem_read);
        vlSelfRef.__Vtogcov__id_mem_read = vlSelfRef.id_mem_read;
    }
    VL_ASSIGNBIT_WI(0x4aU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1423]);
                }(), (IData)(vlSelfRef.id_mem_read))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1424]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_mem_to_reg) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_to_reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 622, vlSelfRef.id_mem_to_reg, vlSelfRef.__Vtogcov__id_mem_to_reg);
        vlSelfRef.__Vtogcov__id_mem_to_reg = vlSelfRef.id_mem_to_reg;
    }
    VL_ASSIGNBIT_WI(0x4bU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1425]);
                }(), (IData)(vlSelfRef.id_mem_to_reg))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1426]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_alu_op) ^ (IData)(vlSelfRef.__Vtogcov__id_alu_op))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 596, vlSelfRef.id_alu_op, vlSelfRef.__Vtogcov__id_alu_op);
        vlSelfRef.__Vtogcov__id_alu_op = vlSelfRef.id_alu_op;
    }
    vlSelfRef.u_execute__DOT__ALU_Operation = vlSelfRef.id_alu_op;
    if (((IData)(vlSelfRef.id_operand_a) ^ (IData)(vlSelfRef.__Vtogcov__id_operand_a))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 602, vlSelfRef.id_operand_a, vlSelfRef.__Vtogcov__id_operand_a);
        vlSelfRef.__Vtogcov__id_operand_a = vlSelfRef.id_operand_a;
    }
    vlSelfRef.u_execute__DOT__ALU_ASrc = vlSelfRef.id_operand_a;
    if (((IData)(vlSelfRef.id_operand_b) ^ (IData)(vlSelfRef.__Vtogcov__id_operand_b))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 606, vlSelfRef.id_operand_b, vlSelfRef.__Vtogcov__id_operand_b);
        vlSelfRef.__Vtogcov__id_operand_b = vlSelfRef.id_operand_b;
    }
    vlSelfRef.u_execute__DOT__ALU_BSrc = vlSelfRef.id_operand_b;
    if (((IData)(vlSelfRef.id_extend_sel) ^ (IData)(vlSelfRef.__Vtogcov__id_extend_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 608, vlSelfRef.id_extend_sel, vlSelfRef.__Vtogcov__id_extend_sel);
        vlSelfRef.__Vtogcov__id_extend_sel = vlSelfRef.id_extend_sel;
    }
    vlSelfRef.u_decoder__DOT__extend_sel = vlSelfRef.id_extend_sel;
    if ((vlSelfRef.id_branch_target ^ vlSelfRef.__Vtogcov__id_branch_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 210, vlSelfRef.id_branch_target, vlSelfRef.__Vtogcov__id_branch_target);
        vlSelfRef.__Vtogcov__id_branch_target = vlSelfRef.id_branch_target;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__branch_op) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__branch_op))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3723, vlSelfRef.u_execute__DOT__branch_op, vlSelfRef.u_execute__DOT____Vtogcov__branch_op);
        vlSelfRef.u_execute__DOT____Vtogcov__branch_op 
            = vlSelfRef.u_execute__DOT__branch_op;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_Operation))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 3435, vlSelfRef.u_execute__DOT__ALU_Operation, vlSelfRef.u_execute__DOT____Vtogcov__ALU_Operation);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_Operation 
            = vlSelfRef.u_execute__DOT__ALU_Operation;
    }
    if ((0U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                 << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7)))) {
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
        ++(vlSymsp->__Vcoverage[3876]);
    } else if ((0x20U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                           << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7)))) {
        ++(vlSymsp->__Vcoverage[3875]);
        vlSelfRef.u_execute__DOT__ALU_Control = (8U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((0x680U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                            << 0xaU) | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                         << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7))))) {
        ++(vlSymsp->__Vcoverage[3874]);
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
    } else if ((0x6a0U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                            << 0xaU) | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                         << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7))))) {
        ++(vlSymsp->__Vcoverage[3873]);
        vlSelfRef.u_execute__DOT__ALU_Control = (8U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((1U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[3872]);
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
    } else if ((2U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[3871]);
        vlSelfRef.u_execute__DOT__ALU_Control = (0x10U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((3U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[3869]);
        vlSelfRef.u_execute__DOT__ALU_Control = 0x1fU;
    } else {
        ++(vlSymsp->__Vcoverage[3870]);
        vlSelfRef.u_execute__DOT__ALU_Control = 0U;
    }
    ++(vlSymsp->__Vcoverage[3877]);
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_ASrc) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_ASrc))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 3461, vlSelfRef.u_execute__DOT__ALU_ASrc, vlSelfRef.u_execute__DOT____Vtogcov__ALU_ASrc);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_ASrc 
            = vlSelfRef.u_execute__DOT__ALU_ASrc;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_BSrc) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_BSrc))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3465, vlSelfRef.u_execute__DOT__ALU_BSrc, vlSelfRef.u_execute__DOT____Vtogcov__ALU_BSrc);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_BSrc 
            = vlSelfRef.u_execute__DOT__ALU_BSrc;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__extend_sel) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__extend_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 2066, vlSelfRef.u_decoder__DOT__extend_sel, vlSelfRef.u_decoder__DOT____Vtogcov__extend_sel);
        vlSelfRef.u_decoder__DOT____Vtogcov__extend_sel 
            = vlSelfRef.u_decoder__DOT__extend_sel;
    }
    vlSelfRef.u_decoder__DOT__extend_imm = ((1U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                             ? ([&]() {
                ++(vlSymsp->__Vcoverage[3170]);
            }(), vlSelfRef.u_decoder__DOT__s_imm_32)
                                             : ([&]() {
                ++(vlSymsp->__Vcoverage[3177]);
            }(), ((2U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[3171]);
                    }(), vlSelfRef.u_decoder__DOT__sb_imm_32)
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[3176]);
                    }(), ((3U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[3172]);
                            }(), vlSelfRef.u_decoder__DOT__u_imm_32)
                           : ([&]() {
                                ++(vlSymsp->__Vcoverage[3175]);
                            }(), ((4U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[3173]);
                                    }(), vlSelfRef.u_decoder__DOT__uj_imm_32)
                                   : ([&]() {
                                        ++(vlSymsp->__Vcoverage[3174]);
                                    }(), vlSelfRef.u_decoder__DOT__i_imm_32))))))));
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_Control) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_Control))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSymsp->__Vcoverage + 3855, vlSelfRef.u_execute__DOT__ALU_Control, vlSelfRef.u_execute__DOT____Vtogcov__ALU_Control);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_Control 
            = vlSelfRef.u_execute__DOT__ALU_Control;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control 
        = vlSelfRef.u_execute__DOT__ALU_Control;
    if ((vlSelfRef.u_decoder__DOT__extend_imm ^ vlSelfRef.u_decoder__DOT____Vtogcov__extend_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2212, vlSelfRef.u_decoder__DOT__extend_imm, vlSelfRef.u_decoder__DOT____Vtogcov__extend_imm);
        vlSelfRef.u_decoder__DOT____Vtogcov__extend_imm 
            = vlSelfRef.u_decoder__DOT__extend_imm;
    }
    vlSelfRef.id_extend_imm = vlSelfRef.u_decoder__DOT__extend_imm;
    if (((IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control) 
         ^ (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_Control))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSymsp->__Vcoverage + 4014, vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_Control);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_Control 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control;
    }
    if ((vlSelfRef.id_extend_imm ^ vlSelfRef.__Vtogcov__id_extend_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 688, vlSelfRef.id_extend_imm, vlSelfRef.__Vtogcov__id_extend_imm);
        vlSelfRef.__Vtogcov__id_extend_imm = vlSelfRef.id_extend_imm;
    }
    vlSelfRef.u_execute__DOT__extend = vlSelfRef.id_extend_imm;
    if ((vlSelfRef.u_execute__DOT__extend ^ vlSelfRef.u_execute__DOT____Vtogcov__extend)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3659, vlSelfRef.u_execute__DOT__extend, vlSelfRef.u_execute__DOT____Vtogcov__extend);
        vlSelfRef.u_execute__DOT____Vtogcov__extend 
            = vlSelfRef.u_execute__DOT__extend;
    }
}

VL_ATTR_COLD void VCoreTop_CoreTop___configure_coverage(VCoreTop_CoreTop* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___configure_coverage\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[0]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 16, 34, "", "v_toggle/CoreTop", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[2]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 17, 34, "", "v_toggle/CoreTop", "rst");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[4]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 18, 34, "", "v_toggle/CoreTop", "start");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[6]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 19, 34, "", "v_toggle/CoreTop", "program_address");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[70]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 25, 11, "", "v_toggle/CoreTop", "stall");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[72]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 26, 11, "", "v_toggle/CoreTop", "flush");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[74]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 34, 28, "", "v_toggle/CoreTop", "if_instruction");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[138]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 35, 28, "", "v_toggle/CoreTop", "if_pc");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[202]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 36, 28, "", "v_toggle/CoreTop", "if_valid");
    vlSelf->__vlCoverToggleInsert(0, 1, 1, &(vlSymsp->__Vcoverage[204]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 39, 28, "", "v_toggle/CoreTop", "id_pc_sel");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[208]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 40, 28, "", "v_toggle/CoreTop", "ex_branch_taken");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[210]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 41, 28, "", "v_toggle/CoreTop", "id_branch_target");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[274]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 42, 28, "", "v_toggle/CoreTop", "id_jal_target");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[338]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 43, 28, "", "v_toggle/CoreTop", "ex_jalr_target");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[402]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 46, 28, "", "v_toggle/CoreTop", "id_instruction");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[466]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 47, 28, "", "v_toggle/CoreTop", "id_pc");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[530]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 48, 28, "", "v_toggle/CoreTop", "id_valid");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[532]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 49, 28, "", "v_toggle/CoreTop", "id_instruction_real");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, &(vlSymsp->__Vcoverage[596]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 52, 30, "", "v_toggle/CoreTop", "id_alu_op");
    vlSelf->__vlCoverToggleInsert(0, 1, 1, &(vlSymsp->__Vcoverage[602]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 53, 30, "", "v_toggle/CoreTop", "id_operand_a");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[606]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 54, 30, "", "v_toggle/CoreTop", "id_operand_b");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, &(vlSymsp->__Vcoverage[608]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 55, 30, "", "v_toggle/CoreTop", "id_extend_sel");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[614]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 56, 30, "", "v_toggle/CoreTop", "id_reg_write");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[616]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 57, 30, "", "v_toggle/CoreTop", "id_branch_op");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[618]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 58, 30, "", "v_toggle/CoreTop", "id_mem_read");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[620]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 59, 30, "", "v_toggle/CoreTop", "id_mem_write");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[622]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 60, 30, "", "v_toggle/CoreTop", "id_mem_to_reg");
    vlSelf->__vlCoverToggleInsert(0, 6, 1, &(vlSymsp->__Vcoverage[624]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 62, 30, "", "v_toggle/CoreTop", "id_opcode");
    vlSelf->__vlCoverToggleInsert(0, 6, 1, &(vlSymsp->__Vcoverage[638]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 63, 30, "", "v_toggle/CoreTop", "id_funct7");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, &(vlSymsp->__Vcoverage[652]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 64, 30, "", "v_toggle/CoreTop", "id_funct3");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[658]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 65, 30, "", "v_toggle/CoreTop", "id_rs1");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[668]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 66, 30, "", "v_toggle/CoreTop", "id_rs2");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[678]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 67, 30, "", "v_toggle/CoreTop", "id_rd");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[688]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 68, 30, "", "v_toggle/CoreTop", "id_extend_imm");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[752]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 69, 30, "", "v_toggle/CoreTop", "id_rs1_data");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[816]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 70, 30, "", "v_toggle/CoreTop", "id_rs2_data");
    vlSelf->__vlCoverToggleInsert(0, 3, 1, &(vlSymsp->__Vcoverage[880]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 71, 30, "", "v_toggle/CoreTop", "id_mem_wbe");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[888]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 74, 28, "", "v_toggle/CoreTop", "ex_alu_result");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[952]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 77, 28, "", "v_toggle/CoreTop", "wb_reg_write");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[954]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 78, 28, "", "v_toggle/CoreTop", "wb_write_reg");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[964]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 79, 28, "", "v_toggle/CoreTop", "wb_write_data");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1028]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 93, 19, "", "v_toggle/CoreTop", "mem_ctrl_out");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1030]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 19, "", "v_toggle/CoreTop", "id_ex_data_in.reg_write");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1032]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 19, "", "v_toggle/CoreTop", "id_ex_data_in.mem_to_reg");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1034]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 19, "", "v_toggle/CoreTop", "id_ex_data_in.mem_read");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1036]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 19, "", "v_toggle/CoreTop", "id_ex_data_in.mem_write");
    vlSelf->__vlCoverToggleInsert(0, 3, 1, &(vlSymsp->__Vcoverage[1038]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 19, "", "v_toggle/CoreTop", "id_ex_data_in.mem_wbe");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[1046]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 19, "", "v_toggle/CoreTop", "id_ex_data_in.rd");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[1056]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 19, "", "v_toggle/CoreTop", "id_ex_data_in.alu_result");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[1120]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 19, "", "v_toggle/CoreTop", "id_ex_data_in.rs2_data");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1184]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 34, "", "v_toggle/CoreTop", "mem_data_out.reg_write");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1186]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 34, "", "v_toggle/CoreTop", "mem_data_out.mem_to_reg");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1188]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 34, "", "v_toggle/CoreTop", "mem_data_out.mem_read");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1190]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 34, "", "v_toggle/CoreTop", "mem_data_out.mem_write");
    vlSelf->__vlCoverToggleInsert(0, 3, 1, &(vlSymsp->__Vcoverage[1192]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 34, "", "v_toggle/CoreTop", "mem_data_out.mem_wbe");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[1200]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 34, "", "v_toggle/CoreTop", "mem_data_out.rd");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[1210]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 34, "", "v_toggle/CoreTop", "mem_data_out.alu_result");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[1274]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 94, 34, "", "v_toggle/CoreTop", "mem_data_out.rs2_data");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[1338]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 97, 28, "", "v_toggle/CoreTop", "mem_rdata");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1402]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 98, 28, "", "v_toggle/CoreTop", "dmem_gnt");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1404]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 98, 38, "", "v_toggle/CoreTop", "dmem_rack");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1406]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 98, 49, "", "v_toggle/CoreTop", "dmem_wack");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1408]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 98, 60, "", "v_toggle/CoreTop", "dmem_err");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1410]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 101, 11, "", "v_toggle/CoreTop", "flush_d");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1412]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 102, 11, "", "v_toggle/CoreTop", "real_if_id_flush");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1414]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 105, 9, "", "v_branch/CoreTop", "if", "105-106");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1415]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 105, 10, "", "v_branch/CoreTop", "else", "108");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1416]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 104, 5, "", "v_line/CoreTop", "block", "104");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1417]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 151, 45, "", "v_branch/CoreTop", "cond_then", "151");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1418]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 151, 46, "", "v_branch/CoreTop", "cond_else", "151");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1419]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 223, 50, "", "v_branch/CoreTop", "cond_then", "223");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1420]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 223, 51, "", "v_branch/CoreTop", "cond_else", "223");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1421]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 224, 50, "", "v_branch/CoreTop", "cond_then", "224");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1422]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 224, 51, "", "v_branch/CoreTop", "cond_else", "224");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1423]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 225, 50, "", "v_branch/CoreTop", "cond_then", "225");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1424]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 225, 51, "", "v_branch/CoreTop", "cond_else", "225");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1425]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 226, 50, "", "v_branch/CoreTop", "cond_then", "226");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1426]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 226, 51, "", "v_branch/CoreTop", "cond_else", "226");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1427]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 272, 54, "", "v_branch/CoreTop", "cond_then", "272");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1428]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 272, 55, "", "v_branch/CoreTop", "cond_else", "272");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1429]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 20, 17, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1431]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 21, 17, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "rst");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1433]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 22, 17, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "flush");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1435]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 23, 17, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "en");
    vlSelf->__vlCoverToggleInsert(0, 0, 1, &(vlSymsp->__Vcoverage[1437]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 25, 34, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "ctrl_in");
    vlSelf->__vlCoverToggleInsert(0, 0, 1, &(vlSymsp->__Vcoverage[1439]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 26, 35, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "ctrl_out");
    vlSelf->__vlCoverToggleInsert(0, 63, 1, &(vlSymsp->__Vcoverage[1441]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 28, 34, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "data_in");
    vlSelf->__vlCoverToggleInsert(0, 63, 1, &(vlSymsp->__Vcoverage[1569]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 29, 35, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "data_out");
    vlSelf->__vlCoverToggleInsert(0, 0, 1, &(vlSymsp->__Vcoverage[1697]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 33, 28, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "ctrl_q");
    vlSelf->__vlCoverToggleInsert(0, 63, 1, &(vlSymsp->__Vcoverage[1699]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 34, 28, ".u_if_id_reg", "v_toggle/PipelineReg__C1_D40", "data_q");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1827]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 47, 22, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "if", "47-48");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1828]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 47, 23, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1829]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 45, 13, ".u_if_id_reg", "v_line/PipelineReg__C1_D40", "elsif", "45-46");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1830]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 41, 9, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "if", "41-42");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1831]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 41, 10, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "else", "43");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1832]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 40, 5, ".u_if_id_reg", "v_line/PipelineReg__C1_D40", "block", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1833]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 58, 9, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "if", "58-59");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1834]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 58, 10, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1835]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 57, 5, ".u_if_id_reg", "v_line/PipelineReg__C1_D40", "block", "57");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1836]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 16, 24, ".u_control_unit", "v_toggle/ControlUnit", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1838]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 17, 24, ".u_control_unit", "v_toggle/ControlUnit", "rst");
    vlSelf->__vlCoverToggleInsert(0, 6, 1, &(vlSymsp->__Vcoverage[1840]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 18, 24, ".u_control_unit", "v_toggle/ControlUnit", "opcode");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, &(vlSymsp->__Vcoverage[1854]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 20, 24, ".u_control_unit", "v_toggle/ControlUnit", "ALUOp");
    vlSelf->__vlCoverToggleInsert(0, 1, 1, &(vlSymsp->__Vcoverage[1860]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 21, 24, ".u_control_unit", "v_toggle/ControlUnit", "operand_A");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1864]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 22, 24, ".u_control_unit", "v_toggle/ControlUnit", "operand_B");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, &(vlSymsp->__Vcoverage[1866]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 23, 24, ".u_control_unit", "v_toggle/ControlUnit", "extend_sel");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1872]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 24, 24, ".u_control_unit", "v_toggle/ControlUnit", "regWrite");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1874]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 26, 18, ".u_control_unit", "v_toggle/ControlUnit", "branch_op");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1876]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 27, 18, ".u_control_unit", "v_toggle/ControlUnit", "memRead");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1878]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 28, 18, ".u_control_unit", "v_toggle/ControlUnit", "memWrite");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1880]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 29, 18, ".u_control_unit", "v_toggle/ControlUnit", "memtoReg");
    vlSelf->__vlCoverToggleInsert(0, 1, 1, &(vlSymsp->__Vcoverage[1882]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 30, 24, ".u_control_unit", "v_toggle/ControlUnit", "next_PC_sel");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1886]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 51, 66, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "51");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1887]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 51, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "51");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1888]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 52, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "52");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1889]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 53, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "53");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1890]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 54, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "54");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1891]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 55, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "55");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1892]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 56, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "56");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1893]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 57, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "57");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1894]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 58, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1895]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 58, 68, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1896]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 57, 68, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1897]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 56, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1898]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 55, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1899]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 54, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1900]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 53, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1901]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 52, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1902]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 60, 44, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "60");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1903]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 61, 44, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "61");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1904]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 62, 66, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "62");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1905]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 62, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "62");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1906]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 61, 45, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1907]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 60, 45, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1908]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 66, 46, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "66");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1909]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 66, 47, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "66");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1910]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 67, 87, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "67");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1911]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 68, 47, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "68");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1912]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 69, 47, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "69");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1913]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 70, 66, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "70");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1914]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 71, 47, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "71");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1915]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 71, 48, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "71");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1916]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 70, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1917]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 69, 48, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1918]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 68, 48, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1919]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 67, 88, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1920]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 73, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "73");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1921]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 73, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "73");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1922]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 74, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "74");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1923]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 74, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "74");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1924]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 75, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "75");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1925]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 75, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "75");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1926]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 76, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "76");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1927]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 76, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "76");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1928]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 77, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "77");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1929]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 78, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "78");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1930]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 79, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "79");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1931]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 79, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "79");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1932]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 78, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1933]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 77, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1934]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 14, 36, ".u_decoder", "v_toggle/Decoder", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[1936]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 15, 36, ".u_decoder", "v_toggle/Decoder", "rst");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[1938]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 16, 36, ".u_decoder", "v_toggle/Decoder", "instruction");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2002]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 18, 36, ".u_decoder", "v_toggle/Decoder", "PC");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, &(vlSymsp->__Vcoverage[2066]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 20, 36, ".u_decoder", "v_toggle/Decoder", "extend_sel");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[2072]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 21, 36, ".u_decoder", "v_toggle/Decoder", "reg_write");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[2074]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 22, 36, ".u_decoder", "v_toggle/Decoder", "write_reg");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2084]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 23, 36, ".u_decoder", "v_toggle/Decoder", "write_data");
    vlSelf->__vlCoverToggleInsert(0, 6, 1, &(vlSymsp->__Vcoverage[2148]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 25, 36, ".u_decoder", "v_toggle/Decoder", "opcode");
    vlSelf->__vlCoverToggleInsert(0, 6, 1, &(vlSymsp->__Vcoverage[2162]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 26, 36, ".u_decoder", "v_toggle/Decoder", "funct7");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, &(vlSymsp->__Vcoverage[2176]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 27, 36, ".u_decoder", "v_toggle/Decoder", "funct3");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[2182]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 28, 36, ".u_decoder", "v_toggle/Decoder", "rs1");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[2192]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 29, 36, ".u_decoder", "v_toggle/Decoder", "rs2");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[2202]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 30, 36, ".u_decoder", "v_toggle/Decoder", "rd");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2212]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 31, 36, ".u_decoder", "v_toggle/Decoder", "extend_imm");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2276]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 32, 36, ".u_decoder", "v_toggle/Decoder", "rs1_data");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2340]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 33, 36, ".u_decoder", "v_toggle/Decoder", "rs2_data");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2404]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 35, 35, ".u_decoder", "v_toggle/Decoder", "branch_target");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2468]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 36, 35, ".u_decoder", "v_toggle/Decoder", "JAL_target");
    vlSelf->__vlCoverToggleInsert(0, 3, 1, &(vlSymsp->__Vcoverage[2532]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 38, 37, ".u_decoder", "v_toggle/Decoder", "mem_wbe");
    vlSelf->__vlCoverToggleInsert(0, 11, 1, &(vlSymsp->__Vcoverage[2540]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 44, 18, ".u_decoder", "v_toggle/Decoder", "i_imm_orig");
    vlSelf->__vlCoverToggleInsert(0, 19, 1, &(vlSymsp->__Vcoverage[2564]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 45, 18, ".u_decoder", "v_toggle/Decoder", "u_imm");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2604]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 46, 18, ".u_decoder", "v_toggle/Decoder", "i_imm_32");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2668]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 47, 18, ".u_decoder", "v_toggle/Decoder", "u_imm_32");
    vlSelf->__vlCoverToggleInsert(0, 6, 1, &(vlSymsp->__Vcoverage[2732]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 49, 18, ".u_decoder", "v_toggle/Decoder", "s_imm_msb");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[2746]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 50, 18, ".u_decoder", "v_toggle/Decoder", "s_imm_lsb");
    vlSelf->__vlCoverToggleInsert(0, 11, 1, &(vlSymsp->__Vcoverage[2756]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 51, 18, ".u_decoder", "v_toggle/Decoder", "s_imm_orig");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2780]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 52, 18, ".u_decoder", "v_toggle/Decoder", "s_imm_32");
    vlSelf->__vlCoverToggleInsert(0, 12, 1, &(vlSymsp->__Vcoverage[2844]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 53, 18, ".u_decoder", "v_toggle/Decoder", "sb_imm_orig");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2870]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 54, 18, ".u_decoder", "v_toggle/Decoder", "sb_imm_32");
    vlSelf->__vlCoverToggleInsert(0, 19, 1, &(vlSymsp->__Vcoverage[2934]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 55, 18, ".u_decoder", "v_toggle/Decoder", "uj_imm");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[2974]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 56, 18, ".u_decoder", "v_toggle/Decoder", "uj_imm_32");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3038]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 57, 11, ".u_decoder", "v_toggle/Decoder", "rs1_data_bypass");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3040]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 58, 11, ".u_decoder", "v_toggle/Decoder", "rs2_data_bypass");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3042]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 59, 28, ".u_decoder", "v_toggle/Decoder", "rs1_data_decode");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3106]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 60, 28, ".u_decoder", "v_toggle/Decoder", "rs2_data_decode");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3170]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 89, 50, ".u_decoder", "v_branch/Decoder", "cond_then", "89");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3171]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 90, 50, ".u_decoder", "v_branch/Decoder", "cond_then", "90");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3172]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 91, 50, ".u_decoder", "v_branch/Decoder", "cond_then", "91");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3173]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 92, 50, ".u_decoder", "v_branch/Decoder", "cond_then", "92");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3174]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 92, 51, ".u_decoder", "v_branch/Decoder", "cond_else", "93");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3175]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 91, 51, ".u_decoder", "v_branch/Decoder", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3176]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 90, 51, ".u_decoder", "v_branch/Decoder", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3177]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 89, 51, ".u_decoder", "v_branch/Decoder", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3178]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 102, 48, ".u_decoder", "v_branch/Decoder", "cond_then", "102");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3179]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 102, 49, ".u_decoder", "v_branch/Decoder", "cond_else", "102");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3180]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 103, 48, ".u_decoder", "v_branch/Decoder", "cond_then", "103");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3181]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 103, 49, ".u_decoder", "v_branch/Decoder", "cond_else", "103");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3182]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 108, 27, ".u_decoder", "v_line/Decoder", "case", "108");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3183]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 109, 27, ".u_decoder", "v_line/Decoder", "case", "109");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3184]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 110, 27, ".u_decoder", "v_line/Decoder", "case", "110");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3185]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 111, 21, ".u_decoder", "v_line/Decoder", "case", "111");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3186]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 106, 9, ".u_decoder", "v_branch/Decoder", "if", "106-107");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3187]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 106, 10, ".u_decoder", "v_branch/Decoder", "else", "113");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3188]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 105, 5, ".u_decoder", "v_line/Decoder", "block", "105");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3189]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 19, 17, ".u_decoder.u_regfile", "v_toggle/RegFile", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3191]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 20, 17, ".u_decoder.u_regfile", "v_toggle/RegFile", "rst");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3193]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 22, 17, ".u_decoder.u_regfile", "v_toggle/RegFile", "wen");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[3195]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 23, 37, ".u_decoder.u_regfile", "v_toggle/RegFile", "waddr");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3205]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 24, 38, ".u_decoder.u_regfile", "v_toggle/RegFile", "wdata");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[3269]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 26, 37, ".u_decoder.u_regfile", "v_toggle/RegFile", "raddr1");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[3279]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 27, 37, ".u_decoder.u_regfile", "v_toggle/RegFile", "raddr2");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3289]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 28, 39, ".u_decoder.u_regfile", "v_toggle/RegFile", "rdata1");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3353]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 29, 39, ".u_decoder.u_regfile", "v_toggle/RegFile", "rdata2");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3417]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 39, 46, ".u_decoder.u_regfile", "v_branch/RegFile", "cond_then", "39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3418]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 39, 47, ".u_decoder.u_regfile", "v_branch/RegFile", "cond_else", "39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3419]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 40, 46, ".u_decoder.u_regfile", "v_branch/RegFile", "cond_then", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3420]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 40, 47, ".u_decoder.u_regfile", "v_branch/RegFile", "cond_else", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3421]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 64, 13, ".u_decoder.u_regfile", "v_line/RegFile", "block", "64-65");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3422]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 18, ".u_decoder.u_regfile", "v_branch/RegFile", "if", "67-68");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3423]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 19, ".u_decoder.u_regfile", "v_branch/RegFile", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3424]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 27, ".u_decoder.u_regfile", "v_expr/RegFile", "(rst==0 && wen==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3425]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 27, ".u_decoder.u_regfile", "v_expr/RegFile", "(wen==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3426]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 27, ".u_decoder.u_regfile", "v_expr/RegFile", "(rst==1) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3427]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 63, 9, ".u_decoder.u_regfile", "v_line/RegFile", "elsif", "63-64");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3428]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 62, 5, ".u_decoder.u_regfile", "v_line/RegFile", "block", "62");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3429]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 13, 17, ".u_execute", "v_toggle/execute", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3431]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 14, 17, ".u_execute", "v_toggle/execute", "rst");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3433]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 15, 17, ".u_execute", "v_toggle/execute", "stall");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, &(vlSymsp->__Vcoverage[3435]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 16, 23, ".u_execute", "v_toggle/execute", "ALU_Operation");
    vlSelf->__vlCoverToggleInsert(0, 6, 1, &(vlSymsp->__Vcoverage[3441]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 17, 23, ".u_execute", "v_toggle/execute", "funct7");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, &(vlSymsp->__Vcoverage[3455]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 18, 23, ".u_execute", "v_toggle/execute", "funct3");
    vlSelf->__vlCoverToggleInsert(0, 1, 1, &(vlSymsp->__Vcoverage[3461]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 19, 23, ".u_execute", "v_toggle/execute", "ALU_ASrc");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3465]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 20, 17, ".u_execute", "v_toggle/execute", "ALU_BSrc");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3467]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 22, 34, ".u_execute", "v_toggle/execute", "PC");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3531]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 23, 34, ".u_execute", "v_toggle/execute", "regRead_1");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3595]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 24, 34, ".u_execute", "v_toggle/execute", "regRead_2");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3659]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 25, 34, ".u_execute", "v_toggle/execute", "extend");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3723]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 26, 17, ".u_execute", "v_toggle/execute", "branch_op");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3725]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 28, 35, ".u_execute", "v_toggle/execute", "ALU_result");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3789]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 29, 18, ".u_execute", "v_toggle/execute", "branch_taken");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3791]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 30, 35, ".u_execute", "v_toggle/execute", "JALR_target");
    vlSelf->__vlCoverToggleInsert(0, 5, 1, &(vlSymsp->__Vcoverage[3855]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 32, 17, ".u_execute", "v_toggle/execute", "ALU_Control");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[3867]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 33, 11, ".u_execute", "v_toggle/execute", "alu_cmp_out");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3869]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 59, 14, ".u_execute", "v_line/execute", "if", "59,61");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3870]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 59, 15, ".u_execute", "v_line/execute", "else", "63,65");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3871]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 55, 14, ".u_execute", "v_line/execute", "elsif", "55,57");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3872]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 51, 14, ".u_execute", "v_line/execute", "elsif", "51,53");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3873]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 47, 14, ".u_execute", "v_line/execute", "elsif", "47,49");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3874]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 43, 14, ".u_execute", "v_line/execute", "elsif", "43,45");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3875]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 39, 14, ".u_execute", "v_line/execute", "elsif", "39,41");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3876]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 35, 9, ".u_execute", "v_line/execute", "elsif", "35,37");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3877]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 34, 5, ".u_execute", "v_line/execute", "block", "34");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3878]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 70, 28, ".u_execute", "v_toggle/execute", "alu_in_a");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[3942]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 71, 28, ".u_execute", "v_toggle/execute", "alu_in_b");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4006]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 75, 46, ".u_execute", "v_branch/execute", "cond_then", "75");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4007]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 76, 50, ".u_execute", "v_branch/execute", "cond_then", "76");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4008]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 77, 46, ".u_execute", "v_branch/execute", "cond_then", "77");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4009]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 77, 47, ".u_execute", "v_branch/execute", "cond_else", "78");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4010]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 76, 51, ".u_execute", "v_branch/execute", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4011]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 75, 47, ".u_execute", "v_branch/execute", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4012]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 81, 34, ".u_execute", "v_branch/execute", "cond_then", "81");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4013]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 81, 35, ".u_execute", "v_branch/execute", "cond_else", "81");
    vlSelf->__vlCoverToggleInsert(0, 5, 1, &(vlSymsp->__Vcoverage[4014]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 12, 35, ".u_execute.u_alu", "v_toggle/ALU", "ALU_Control");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[4026]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 13, 35, ".u_execute.u_alu", "v_toggle/ALU", "alu_in_a");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[4090]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 14, 35, ".u_execute.u_alu", "v_toggle/ALU", "alu_in_b");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[4154]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 15, 35, ".u_execute.u_alu", "v_toggle/ALU", "ALU_result");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[4218]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 16, 18, ".u_execute.u_alu", "v_toggle/ALU", "cmp_out");
    vlSelf->__vlCoverToggleInsert(0, 4, 1, &(vlSymsp->__Vcoverage[4220]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 22, 29, ".u_execute.u_alu", "v_toggle/ALU", "shamt");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[4230]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 23, 28, ".u_execute.u_alu", "v_toggle/ALU", "arithmetic_right_shift");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[4294]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 24, 28, ".u_execute.u_alu", "v_toggle/ALU", "signed_less_than");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[4358]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 25, 28, ".u_execute.u_alu", "v_toggle/ALU", "unsigned_less_than");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[4422]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 26, 28, ".u_execute.u_alu", "v_toggle/ALU", "signed_greater_than_equal");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4486]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 39, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4487]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 40, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4488]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 42, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "42");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4489]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 43, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "43");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4490]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 44, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "44");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4491]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 46, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "46");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4492]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 47, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "47");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4493]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 49, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "49");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4494]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 50, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4495]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 51, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "51");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4496]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 53, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "53");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4497]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 54, 63, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "54");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4498]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 55, 63, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "55");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4499]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 56, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "56");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4500]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 57, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "57");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4501]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 58, 63, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4502]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 59, 63, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "59");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4503]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 59, 64, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "60");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4504]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 58, 64, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4505]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 57, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4506]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 56, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4507]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 55, 64, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4508]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 54, 64, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4509]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 53, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4510]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 51, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4511]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 50, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4512]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 49, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4513]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 47, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4514]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 46, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4515]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 44, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4516]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 43, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4517]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 42, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4518]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 40, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4519]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 39, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[4520]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 20, 17, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[4522]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 21, 17, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "rst");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[4524]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 22, 17, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "flush");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[4526]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 23, 17, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "en");
    vlSelf->__vlCoverToggleInsert(0, 0, 1, &(vlSymsp->__Vcoverage[4528]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 25, 34, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "ctrl_in");
    vlSelf->__vlCoverToggleInsert(0, 0, 1, &(vlSymsp->__Vcoverage[4530]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 26, 35, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "ctrl_out");
    vlSelf->__vlCoverToggleInsert(0, 76, 1, &(vlSymsp->__Vcoverage[4532]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 28, 34, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "data_in");
    vlSelf->__vlCoverToggleInsert(0, 76, 1, &(vlSymsp->__Vcoverage[4686]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 29, 35, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "data_out");
    vlSelf->__vlCoverToggleInsert(0, 0, 1, &(vlSymsp->__Vcoverage[4840]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 33, 28, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "ctrl_q");
    vlSelf->__vlCoverToggleInsert(0, 76, 1, &(vlSymsp->__Vcoverage[4842]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 34, 28, ".u_ex_mem_reg", "v_toggle/PipelineReg__C1_D4d", "data_q");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4996]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 47, 22, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "if", "47-48");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4997]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 47, 23, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4998]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 45, 13, ".u_ex_mem_reg", "v_line/PipelineReg__C1_D4d", "elsif", "45-46");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4999]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 41, 9, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "if", "41-42");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5000]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 41, 10, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "else", "43");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5001]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 40, 5, ".u_ex_mem_reg", "v_line/PipelineReg__C1_D4d", "block", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5002]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 58, 9, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "if", "58-59");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5003]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 58, 10, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5004]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 57, 5, ".u_ex_mem_reg", "v_line/PipelineReg__C1_D4d", "block", "57");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5005]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 98, 17, ".u_dmem", "v_toggle/DMemTop", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5007]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 99, 17, ".u_dmem", "v_toggle/DMemTop", "rst");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5009]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 102, 17, ".u_dmem", "v_toggle/DMemTop", "read");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5011]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 103, 17, ".u_dmem", "v_toggle/DMemTop", "write");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5013]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 104, 34, ".u_dmem", "v_toggle/DMemTop", "addr");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5077]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 105, 34, ".u_dmem", "v_toggle/DMemTop", "wdata");
    vlSelf->__vlCoverToggleInsert(0, 3, 1, &(vlSymsp->__Vcoverage[5141]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 106, 38, ".u_dmem", "v_toggle/DMemTop", "wbe");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5149]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 109, 18, ".u_dmem", "v_toggle/DMemTop", "gnt");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5151]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 110, 18, ".u_dmem", "v_toggle/DMemTop", "rack");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5153]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 111, 18, ".u_dmem", "v_toggle/DMemTop", "wack");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5155]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 112, 18, ".u_dmem", "v_toggle/DMemTop", "err");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5157]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 113, 35, ".u_dmem", "v_toggle/DMemTop", "rdata");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5221]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 20, 17, ".u_dmem.dmem", "v_toggle/DMem", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5223]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 21, 17, ".u_dmem.dmem", "v_toggle/DMem", "rst");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5225]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 34, 9, ".u_dmem.dmem", "v_line/DMem", "block", "34-35");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5226]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 38, 9, ".u_dmem.dmem", "v_branch/DMem", "if", "38-39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5227]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 38, 10, ".u_dmem.dmem", "v_branch/DMem", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5228]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 33, 5, ".u_dmem.dmem", "v_line/DMem", "block", "33-34");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5229]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 44, 11, ".u_dmem.dmem", "v_toggle/DMem", "gnt");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5231]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 45, 11, ".u_dmem.dmem", "v_toggle/DMem", "err");
    vlSelf->__vlCoverToggleInsert(0, 11, 1, &(vlSymsp->__Vcoverage[5233]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 50, 32, ".u_dmem.dmem", "v_toggle/DMem", "mem_addr");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5257]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 53, 28, ".u_dmem.dmem", "v_toggle/DMem", "write_data");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5321]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 59, 13, ".u_dmem.dmem", "v_branch/DMem", "if", "59-60");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5322]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 59, 14, ".u_dmem.dmem", "v_branch/DMem", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5323]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 58, 9, ".u_dmem.dmem", "v_line/DMem", "block", "58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5324]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 56, 5, ".u_dmem.dmem", "v_line/DMem", "block", "56-58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5325]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 13, ".u_dmem.dmem", "v_branch/DMem", "if", "73-74");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5326]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 14, ".u_dmem.dmem", "v_branch/DMem", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5327]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 28, ".u_dmem.dmem", "v_expr/DMem", "(dbus.write==1 && gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5328]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 28, ".u_dmem.dmem", "v_expr/DMem", "(gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5329]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 28, ".u_dmem.dmem", "v_expr/DMem", "(dbus.write==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5330]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 77, 37, ".u_dmem.dmem", "v_expr/DMem", "(dbus.write==1 && gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5331]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 77, 37, ".u_dmem.dmem", "v_expr/DMem", "(gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5332]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 77, 37, ".u_dmem.dmem", "v_expr/DMem", "(dbus.write==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5333]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 70, 9, ".u_dmem.dmem", "v_branch/DMem", "if", "70-71");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5334]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 70, 10, ".u_dmem.dmem", "v_branch/DMem", "else", "72,77");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5335]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 69, 5, ".u_dmem.dmem", "v_line/DMem", "block", "69");
}
