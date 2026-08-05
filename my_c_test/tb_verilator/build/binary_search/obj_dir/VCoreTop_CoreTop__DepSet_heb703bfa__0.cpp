// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_CoreTop.h"

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__cycle_cnt = vlSelfRef.cycle_cnt;
    vlSelfRef.__Vdly__cycle_cnt = ((IData)(vlSelfRef.rst)
                                    ? 0U : ((IData)(1U) 
                                            + vlSelfRef.cycle_cnt));
    vlSelfRef.flush_d = ((~ (IData)(vlSelfRef.rst)) 
                         & (IData)(vlSelfRef.flush));
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0 = 0;
    IData/*31:0*/ __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32;
    __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0;
    CData/*4:0*/ __VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32;
    __VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0;
    // Body
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0U;
    if (vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 2U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 3U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 4U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 5U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 6U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 7U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 8U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 9U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xaU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xbU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xcU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xdU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xeU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xfU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x10U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x11U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x12U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x13U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x14U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x15U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x16U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x17U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x18U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x19U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1aU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1bU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1cU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1dU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1eU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1fU;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x20U;
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0 = 1U;
    } else if (((~ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst)) 
                & (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen))) {
        __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata;
        __VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr;
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32 = 1U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[1U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[2U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[3U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[4U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[5U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[6U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[7U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[8U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[9U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xaU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xbU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xcU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xdU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xeU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xfU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x10U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x11U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x12U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x13U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x14U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x15U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x16U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x17U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x18U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x19U] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1aU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1bU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1cU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1dU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1eU] = 0U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1fU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[__VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32] 
            = __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__7(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__7\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.u_ex_mem_reg__DOT__rst) {
        vlSelfRef.u_ex_mem_reg__DOT__ctrl_q = 0U;
    } else if (vlSelfRef.u_ex_mem_reg__DOT__flush) {
        vlSelfRef.u_ex_mem_reg__DOT__ctrl_q = 0U;
    } else if (vlSelfRef.u_ex_mem_reg__DOT__en) {
        vlSelfRef.u_ex_mem_reg__DOT__ctrl_q = vlSelfRef.u_ex_mem_reg__DOT__ctrl_in;
    }
    if (vlSelfRef.u_ex_mem_reg__DOT__en) {
        vlSelfRef.u_ex_mem_reg__DOT__data_q[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_in[0U];
        vlSelfRef.u_ex_mem_reg__DOT__data_q[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_in[1U];
        vlSelfRef.u_ex_mem_reg__DOT__data_q[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_in[2U];
    }
    vlSelfRef.u_ex_mem_reg__DOT__ctrl_out = vlSelfRef.u_ex_mem_reg__DOT__ctrl_q;
    vlSelfRef.u_ex_mem_reg__DOT__data_out[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[0U];
    vlSelfRef.u_ex_mem_reg__DOT__data_out[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[1U];
    vlSelfRef.u_ex_mem_reg__DOT__data_out[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[2U];
    vlSelfRef.mem_ctrl_out = vlSelfRef.u_ex_mem_reg__DOT__ctrl_out;
    vlSelfRef.mem_data_out[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[0U];
    vlSelfRef.mem_data_out[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[1U];
    vlSelfRef.mem_data_out[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[2U];
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
    vlSelfRef.u_decoder__DOT__write_reg = vlSelfRef.wb_write_reg;
    vlSelfRef.u_decoder__DOT__reg_write = vlSelfRef.wb_reg_write;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr 
        = vlSelfRef.u_decoder__DOT__write_reg;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen = vlSelfRef.u_decoder__DOT__reg_write;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__9(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__9\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ u_control_unit__DOT____VdfgRegularize_h767aeadd_0_6;
    u_control_unit__DOT____VdfgRegularize_h767aeadd_0_6 = 0;
    CData/*0:0*/ u_control_unit__DOT____VdfgRegularize_h767aeadd_0_7;
    u_control_unit__DOT____VdfgRegularize_h767aeadd_0_7 = 0;
    // Body
    if (vlSelfRef.u_if_id_reg__DOT__rst) {
        vlSelfRef.u_if_id_reg__DOT__ctrl_q = 0U;
    } else if (vlSelfRef.u_if_id_reg__DOT__flush) {
        vlSelfRef.u_if_id_reg__DOT__ctrl_q = 0U;
    } else if (vlSelfRef.u_if_id_reg__DOT__en) {
        vlSelfRef.u_if_id_reg__DOT__ctrl_q = vlSelfRef.u_if_id_reg__DOT__ctrl_in;
    }
    if (vlSelfRef.u_if_id_reg__DOT__en) {
        vlSelfRef.u_if_id_reg__DOT__data_q = vlSelfRef.u_if_id_reg__DOT__data_in;
    }
    vlSelfRef.u_if_id_reg__DOT__ctrl_out = vlSelfRef.u_if_id_reg__DOT__ctrl_q;
    vlSelfRef.u_if_id_reg__DOT__data_out = vlSelfRef.u_if_id_reg__DOT__data_q;
    vlSelfRef.id_valid = vlSelfRef.u_if_id_reg__DOT__ctrl_out;
    vlSelfRef.id_pc = (IData)((vlSelfRef.u_if_id_reg__DOT__data_out 
                               >> 0x20U));
    vlSelfRef.id_instruction = (IData)(vlSelfRef.u_if_id_reg__DOT__data_out);
    if (vlSelfRef.id_valid) {
        vlSelfRef.u_ex_mem_reg__DOT__ctrl_in = 1U;
        vlSelfRef.u_decoder__DOT__PC = vlSelfRef.id_pc;
        vlSelfRef.u_execute__DOT__PC = vlSelfRef.id_pc;
        vlSelfRef.id_instruction_real = vlSelfRef.id_instruction;
    } else {
        vlSelfRef.u_ex_mem_reg__DOT__ctrl_in = 0U;
        vlSelfRef.u_decoder__DOT__PC = vlSelfRef.id_pc;
        vlSelfRef.u_execute__DOT__PC = vlSelfRef.id_pc;
        vlSelfRef.id_instruction_real = 0x13U;
    }
    vlSelfRef.u_decoder__DOT__instruction = vlSelfRef.id_instruction_real;
    vlSelfRef.u_decoder__DOT__funct3 = (7U & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0xcU));
    vlSelfRef.u_decoder__DOT__i_imm_orig = (vlSelfRef.u_decoder__DOT__instruction 
                                            >> 0x14U);
    vlSelfRef.u_decoder__DOT__u_imm = (vlSelfRef.u_decoder__DOT__instruction 
                                       >> 0xcU);
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
    vlSelfRef.id_funct3 = vlSelfRef.u_decoder__DOT__funct3;
    vlSelfRef.u_decoder__DOT__i_imm_32 = (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.u_decoder__DOT__i_imm_orig) 
                                                          >> 0xbU)))) 
                                           << 0xcU) 
                                          | (IData)(vlSelfRef.u_decoder__DOT__i_imm_orig));
    vlSelfRef.u_decoder__DOT__u_imm_32 = (vlSelfRef.u_decoder__DOT__u_imm 
                                          << 0xcU);
    vlSelfRef.u_decoder__DOT__JAL_target = (vlSelfRef.u_decoder__DOT__PC 
                                            + vlSelfRef.u_decoder__DOT__uj_imm_32);
    vlSelfRef.id_rs1 = vlSelfRef.u_decoder__DOT__rs1;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1 
        = vlSelfRef.u_decoder__DOT__rs1;
    vlSelfRef.id_rs2 = vlSelfRef.u_decoder__DOT__rs2;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2 
        = vlSelfRef.u_decoder__DOT__rs2;
    vlSelfRef.id_rd = vlSelfRef.u_decoder__DOT__rd;
    vlSelfRef.u_decoder__DOT__s_imm_lsb = vlSelfRef.u_decoder__DOT__rd;
    vlSelfRef.id_funct7 = vlSelfRef.u_decoder__DOT__funct7;
    vlSelfRef.u_decoder__DOT__s_imm_msb = vlSelfRef.u_decoder__DOT__funct7;
    vlSelfRef.u_decoder__DOT__mem_wbe = ((0x23U == (IData)(vlSelfRef.u_decoder__DOT__opcode))
                                          ? ((0U == (IData)(vlSelfRef.u_decoder__DOT__funct3))
                                              ? 1U : 
                                             ((1U == (IData)(vlSelfRef.u_decoder__DOT__funct3))
                                               ? 3U
                                               : ((2U 
                                                   == (IData)(vlSelfRef.u_decoder__DOT__funct3))
                                                   ? 0xfU
                                                   : 0U)))
                                          : 0U);
    vlSelfRef.id_opcode = vlSelfRef.u_decoder__DOT__opcode;
    vlSelfRef.u_execute__DOT__funct3 = vlSelfRef.id_funct3;
    vlSelfRef.id_jal_target = vlSelfRef.u_decoder__DOT__JAL_target;
    vlSelfRef.u_execute__DOT__funct7 = vlSelfRef.id_funct7;
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
    vlSelfRef.id_mem_wbe = vlSelfRef.u_decoder__DOT__mem_wbe;
    vlSelfRef.u_control_unit__DOT__opcode = vlSelfRef.id_opcode;
    vlSelfRef.u_decoder__DOT__s_imm_32 = (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_orig) 
                                                          >> 0xbU)))) 
                                           << 0xcU) 
                                          | (IData)(vlSelfRef.u_decoder__DOT__s_imm_orig));
    vlSelfRef.u_decoder__DOT__sb_imm_32 = (((- (IData)(
                                                       (1U 
                                                        & ((IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig) 
                                                           >> 0xcU)))) 
                                            << 0xdU) 
                                           | (IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig));
    u_control_unit__DOT____VdfgRegularize_h767aeadd_0_6 
        = ((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
           | (0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode)));
    vlSelfRef.u_control_unit__DOT__branch_op = (0x63U 
                                                == (IData)(vlSelfRef.u_control_unit__DOT__opcode));
    vlSelfRef.u_control_unit__DOT__memWrite = (0x23U 
                                               == (IData)(vlSelfRef.u_control_unit__DOT__opcode));
    u_control_unit__DOT____VdfgRegularize_h767aeadd_0_7 
        = ((0x17U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
           | (0x37U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)));
    vlSelfRef.u_control_unit__DOT__memRead = (3U == (IData)(vlSelfRef.u_control_unit__DOT__opcode));
    vlSelfRef.u_decoder__DOT__branch_target = (vlSelfRef.u_decoder__DOT__PC 
                                               + vlSelfRef.u_decoder__DOT__sb_imm_32);
    vlSelfRef.u_control_unit__DOT__operand_A = ((0x17U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                 ? 1U
                                                 : 
                                                ((0x37U 
                                                  == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                  ? 3U
                                                  : 
                                                 ((IData)(u_control_unit__DOT____VdfgRegularize_h767aeadd_0_6)
                                                   ? 2U
                                                   : 0U)));
    if (vlSelfRef.u_control_unit__DOT__branch_op) {
        vlSelfRef.u_control_unit__DOT__next_PC_sel = 1U;
        vlSelfRef.id_branch_op = 1U;
    } else {
        vlSelfRef.u_control_unit__DOT__next_PC_sel 
            = ((0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                ? 2U : ((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                         ? 3U : 0U));
        vlSelfRef.id_branch_op = 0U;
    }
    vlSelfRef.id_mem_write = vlSelfRef.u_control_unit__DOT__memWrite;
    vlSelfRef.id_mem_read = vlSelfRef.u_control_unit__DOT__memRead;
    vlSelfRef.u_control_unit__DOT__memtoReg = vlSelfRef.u_control_unit__DOT__memRead;
    vlSelfRef.u_control_unit__DOT__regWrite = ((0x33U 
                                                == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                               | ((0x13U 
                                                   == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                  | ((IData)(vlSelfRef.u_control_unit__DOT__memRead) 
                                                     | ((IData)(u_control_unit__DOT____VdfgRegularize_h767aeadd_0_6) 
                                                        | (IData)(u_control_unit__DOT____VdfgRegularize_h767aeadd_0_7)))));
    vlSelfRef.u_control_unit__DOT__ALUOp = ((0x33U 
                                             == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                             ? 0U : 
                                            ((0x13U 
                                              == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                              ? 1U : 
                                             ((IData)(vlSelfRef.u_control_unit__DOT__memWrite)
                                               ? 5U
                                               : ((IData)(vlSelfRef.u_control_unit__DOT__memRead)
                                                   ? 4U
                                                   : 
                                                  ((IData)(vlSelfRef.u_control_unit__DOT__branch_op)
                                                    ? 2U
                                                    : 
                                                   ((IData)(u_control_unit__DOT____VdfgRegularize_h767aeadd_0_6)
                                                     ? 3U
                                                     : 
                                                    ((IData)(u_control_unit__DOT____VdfgRegularize_h767aeadd_0_7)
                                                      ? 6U
                                                      : 0U)))))));
    vlSelfRef.u_control_unit__DOT__operand_B = ((0x13U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                | ((IData)(vlSelfRef.u_control_unit__DOT__memWrite) 
                                                   | ((IData)(vlSelfRef.u_control_unit__DOT__memRead) 
                                                      | (IData)(u_control_unit__DOT____VdfgRegularize_h767aeadd_0_7))));
    vlSelfRef.u_control_unit__DOT__extend_sel = (((0x13U 
                                                   == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                  | ((IData)(vlSelfRef.u_control_unit__DOT__memRead) 
                                                     | (0x67U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode))))
                                                  ? 0U
                                                  : 
                                                 ((IData)(vlSelfRef.u_control_unit__DOT__memWrite)
                                                   ? 1U
                                                   : 
                                                  ((IData)(vlSelfRef.u_control_unit__DOT__branch_op)
                                                    ? 2U
                                                    : 
                                                   ((IData)(u_control_unit__DOT____VdfgRegularize_h767aeadd_0_7)
                                                     ? 3U
                                                     : 
                                                    ((0x6fU 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                      ? 4U
                                                      : 0U)))));
    vlSelfRef.id_branch_target = vlSelfRef.u_decoder__DOT__branch_target;
    vlSelfRef.id_operand_a = vlSelfRef.u_control_unit__DOT__operand_A;
    vlSelfRef.id_pc_sel = vlSelfRef.u_control_unit__DOT__next_PC_sel;
    vlSelfRef.u_execute__DOT__branch_op = vlSelfRef.id_branch_op;
    vlSelfRef.id_mem_to_reg = vlSelfRef.u_control_unit__DOT__memtoReg;
    vlSelfRef.id_reg_write = vlSelfRef.u_control_unit__DOT__regWrite;
    vlSelfRef.id_alu_op = vlSelfRef.u_control_unit__DOT__ALUOp;
    vlSelfRef.id_operand_b = vlSelfRef.u_control_unit__DOT__operand_B;
    vlSelfRef.id_extend_sel = vlSelfRef.u_control_unit__DOT__extend_sel;
    vlSelfRef.u_execute__DOT__ALU_ASrc = vlSelfRef.id_operand_a;
    vlSelfRef.u_execute__DOT__ALU_Operation = vlSelfRef.id_alu_op;
    vlSelfRef.u_execute__DOT__ALU_BSrc = vlSelfRef.id_operand_b;
    vlSelfRef.u_decoder__DOT__extend_sel = vlSelfRef.id_extend_sel;
    vlSelfRef.u_execute__DOT__ALU_Control = ((0U == 
                                              (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                                                << 7U) 
                                               | (IData)(vlSelfRef.u_execute__DOT__funct7)))
                                              ? (IData)(vlSelfRef.u_execute__DOT__funct3)
                                              : ((0x20U 
                                                  == 
                                                  (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                                                    << 7U) 
                                                   | (IData)(vlSelfRef.u_execute__DOT__funct7)))
                                                  ? 
                                                 (8U 
                                                  | (IData)(vlSelfRef.u_execute__DOT__funct3))
                                                  : 
                                                 ((0x680U 
                                                   == 
                                                   (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                                                     << 0xaU) 
                                                    | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                                        << 7U) 
                                                       | (IData)(vlSelfRef.u_execute__DOT__funct7))))
                                                   ? (IData)(vlSelfRef.u_execute__DOT__funct3)
                                                   : 
                                                  ((0x6a0U 
                                                    == 
                                                    (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                                                      << 0xaU) 
                                                     | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                                         << 7U) 
                                                        | (IData)(vlSelfRef.u_execute__DOT__funct7))))
                                                    ? 
                                                   (8U 
                                                    | (IData)(vlSelfRef.u_execute__DOT__funct3))
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))
                                                     ? (IData)(vlSelfRef.u_execute__DOT__funct3)
                                                     : 
                                                    ((2U 
                                                      == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))
                                                      ? 
                                                     (0x10U 
                                                      | (IData)(vlSelfRef.u_execute__DOT__funct3))
                                                      : 
                                                     ((3U 
                                                       == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))
                                                       ? 0x1fU
                                                       : 0U)))))));
    vlSelfRef.u_decoder__DOT__extend_imm = ((1U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                             ? vlSelfRef.u_decoder__DOT__s_imm_32
                                             : ((2U 
                                                 == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                                 ? vlSelfRef.u_decoder__DOT__sb_imm_32
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                                  ? vlSelfRef.u_decoder__DOT__u_imm_32
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                                   ? vlSelfRef.u_decoder__DOT__uj_imm_32
                                                   : vlSelfRef.u_decoder__DOT__i_imm_32))));
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control 
        = vlSelfRef.u_execute__DOT__ALU_Control;
    vlSelfRef.id_extend_imm = vlSelfRef.u_decoder__DOT__extend_imm;
    vlSelfRef.u_execute__DOT__extend = vlSelfRef.id_extend_imm;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__11(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__11\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cycle_cnt = vlSelfRef.__Vdly__cycle_cnt;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__12(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__12\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_if_id_reg__DOT__ctrl_in = vlSelfRef.if_valid;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_decoder__DOT__rs1_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs1) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((0U 
                                                     != (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                    & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.u_decoder__DOT__rs1)))));
    vlSelfRef.u_decoder__DOT__rs2_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs2) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                    & (0U 
                                                       != (IData)(vlSelfRef.u_decoder__DOT__rs2))));
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__3\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1))
            ? 0U : vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
           [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1]);
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2))
            ? 0U : vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
           [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2]);
    vlSelfRef.u_decoder__DOT__rs1_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1;
    vlSelfRef.u_decoder__DOT__rs2_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__4(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__4\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_if_id_reg__DOT__data_in = (((QData)((IData)(vlSelfRef.if_pc)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.if_instruction)));
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__5(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__5\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_decoder__DOT__rs1_data = ((IData)(vlSelfRef.u_decoder__DOT__rs1_data_bypass)
                                           ? vlSelfRef.u_decoder__DOT__write_data
                                           : vlSelfRef.u_decoder__DOT__rs1_data_decode);
    vlSelfRef.u_decoder__DOT__rs2_data = ((IData)(vlSelfRef.u_decoder__DOT__rs2_data_bypass)
                                           ? vlSelfRef.u_decoder__DOT__write_data
                                           : vlSelfRef.u_decoder__DOT__rs2_data_decode);
    vlSelfRef.id_rs1_data = vlSelfRef.u_decoder__DOT__rs1_data;
    vlSelfRef.id_rs2_data = vlSelfRef.u_decoder__DOT__rs2_data;
    vlSelfRef.u_execute__DOT__regRead_1 = vlSelfRef.id_rs1_data;
    vlSelfRef.u_execute__DOT__regRead_2 = vlSelfRef.id_rs2_data;
    vlSelfRef.u_execute__DOT__alu_in_a = ((1U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                                           ? vlSelfRef.u_execute__DOT__PC
                                           : ((2U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                                               ? ((IData)(4U) 
                                                  + vlSelfRef.u_execute__DOT__PC)
                                               : ((3U 
                                                   == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                                                   ? 0U
                                                   : vlSelfRef.u_execute__DOT__regRead_1)));
    vlSelfRef.u_execute__DOT__JALR_target = (0xfffffffeU 
                                             & (vlSelfRef.u_execute__DOT__extend 
                                                + vlSelfRef.u_execute__DOT__regRead_1));
    vlSelfRef.u_execute__DOT__alu_in_b = ((IData)(vlSelfRef.u_execute__DOT__ALU_BSrc)
                                           ? vlSelfRef.u_execute__DOT__extend
                                           : vlSelfRef.u_execute__DOT__regRead_2);
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
        = vlSelfRef.u_execute__DOT__alu_in_a;
    vlSelfRef.ex_jalr_target = vlSelfRef.u_execute__DOT__JALR_target;
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b 
        = vlSelfRef.u_execute__DOT__alu_in_b;
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than 
        = VL_LTS_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than 
        = (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
           < vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal 
        = VL_GTES_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__shamt = (0x1fU 
                                                   & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift 
        = VL_SHIFTRS_III(32,32,5, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt));
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result 
        = ((0U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
            ? (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
               + vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b)
            : ((8U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                ? (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                   - vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b)
                : ((4U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                    ? (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                       ^ vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b)
                    : ((6U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                        ? (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                           | vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b)
                        : ((7U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                            ? (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                               & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b)
                            : ((2U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                ? vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than
                                : ((3U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                    ? vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than
                                    : ((1U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                        ? (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                           << (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt))
                                        : ((5U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                            ? (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                               >> (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt))
                                            : ((0xdU 
                                                == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                ? vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift
                                                : (
                                                   (0x1fU 
                                                    == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                    ? vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a
                                                    : 
                                                   ((0x10U 
                                                     == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                     ? 
                                                    (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                     == vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b)
                                                     : 
                                                    ((0x11U 
                                                      == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                      ? 
                                                     (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                      != vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b)
                                                      : 
                                                     ((0x14U 
                                                       == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                       ? vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than
                                                       : 
                                                      ((0x15U 
                                                        == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                        ? vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal
                                                        : 
                                                       ((0x16U 
                                                         == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                         ? vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                          ? 
                                                         (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                          >= vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b)
                                                          : 0U)))))))))))))))));
    vlSelfRef.u_execute__DOT__ALU_result = vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result;
    vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out = 
        (1U & vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result);
    vlSelfRef.ex_alu_result = vlSelfRef.u_execute__DOT__ALU_result;
    vlSelfRef.u_execute__DOT__alu_cmp_out = vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out;
    vlSelfRef.id_ex_data_in[0U] = (IData)((((QData)((IData)(vlSelfRef.ex_alu_result)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.id_rs2_data))));
    vlSelfRef.id_ex_data_in[1U] = (IData)(((((QData)((IData)(vlSelfRef.ex_alu_result)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelfRef.id_rs2_data))) 
                                           >> 0x20U));
    vlSelfRef.id_ex_data_in[2U] = (0x1fffU & ((((((IData)(vlSelfRef.id_reg_write) 
                                                  & (IData)(vlSelfRef.id_valid)) 
                                                 << 0xcU) 
                                                | (((IData)(vlSelfRef.id_mem_to_reg) 
                                                    & (IData)(vlSelfRef.id_valid)) 
                                                   << 0xbU)) 
                                               | ((((IData)(vlSelfRef.id_mem_read) 
                                                    & (IData)(vlSelfRef.id_valid)) 
                                                   << 0xaU) 
                                                  | (((IData)(vlSelfRef.id_mem_write) 
                                                      & (IData)(vlSelfRef.id_valid)) 
                                                     << 9U))) 
                                              | (((IData)(vlSelfRef.id_mem_wbe) 
                                                  << 5U) 
                                                 | (IData)(vlSelfRef.id_rd))));
    vlSelfRef.u_execute__DOT__branch_taken = ((IData)(vlSelfRef.u_execute__DOT__alu_cmp_out) 
                                              & (IData)(vlSelfRef.u_execute__DOT__branch_op));
    vlSelfRef.u_ex_mem_reg__DOT__data_in[0U] = vlSelfRef.id_ex_data_in[0U];
    vlSelfRef.u_ex_mem_reg__DOT__data_in[1U] = vlSelfRef.id_ex_data_in[1U];
    vlSelfRef.u_ex_mem_reg__DOT__data_in[2U] = vlSelfRef.id_ex_data_in[2U];
    vlSelfRef.ex_branch_taken = vlSelfRef.u_execute__DOT__branch_taken;
    vlSelfRef.flush = (((1U == (IData)(vlSelfRef.id_pc_sel)) 
                        & (IData)(vlSelfRef.ex_branch_taken)) 
                       | ((2U == (IData)(vlSelfRef.id_pc_sel)) 
                          | (3U == (IData)(vlSelfRef.id_pc_sel))));
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__6(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__6\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.real_if_id_flush = ((IData)(vlSelfRef.flush) 
                                  | (IData)(vlSelfRef.flush_d));
    vlSelfRef.u_if_id_reg__DOT__flush = vlSelfRef.real_if_id_flush;
}
