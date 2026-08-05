// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_CoreTop.h"
#include "VCoreTop__Syms.h"

VL_INLINE_OPT void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ u_control_unit__DOT____VdfgRegularize_h767aeadd_0_6;
    u_control_unit__DOT____VdfgRegularize_h767aeadd_0_6 = 0;
    CData/*0:0*/ u_control_unit__DOT____VdfgRegularize_h767aeadd_0_7;
    u_control_unit__DOT____VdfgRegularize_h767aeadd_0_7 = 0;
    // Body
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
    vlSelfRef.u_if_id_reg__DOT__en = vlSelfRef.u_ex_mem_reg__DOT__en;
    vlSelfRef.dmem_wack = vlSelfRef.u_dmem__DOT__wack;
    vlSelfRef.u_if_id_reg__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_ex_mem_reg__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_control_unit__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_execute__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_decoder__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_dmem__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_if_id_reg__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_control_unit__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_execute__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_ex_mem_reg__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_decoder__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_dmem__DOT__rst = vlSelfRef.rst;
    vlSelfRef.mem_ctrl_out = vlSelfRef.u_ex_mem_reg__DOT__ctrl_out;
    vlSelfRef.mem_data_out[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[0U];
    vlSelfRef.mem_data_out[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[1U];
    vlSelfRef.mem_data_out[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[2U];
    vlSelfRef.id_valid = vlSelfRef.u_if_id_reg__DOT__ctrl_out;
    vlSelfRef.id_pc = (IData)((vlSelfRef.u_if_id_reg__DOT__data_out 
                               >> 0x20U));
    vlSelfRef.id_instruction = (IData)(vlSelfRef.u_if_id_reg__DOT__data_out);
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__clk = vlSelfRef.u_decoder__DOT__clk;
    vlSelfRef.u_dmem__DOT__dmem__DOT__clk = vlSelfRef.u_dmem__DOT__clk;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst = vlSelfRef.u_decoder__DOT__rst;
    vlSelfRef.u_dmem__DOT__dmem__DOT__rst = vlSelfRef.u_dmem__DOT__rst;
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
    vlSelfRef.u_decoder__DOT__write_reg = vlSelfRef.wb_write_reg;
    vlSelfRef.u_decoder__DOT__reg_write = vlSelfRef.wb_reg_write;
    vlSelfRef.u_decoder__DOT__instruction = vlSelfRef.id_instruction_real;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr 
        = vlSelfRef.u_decoder__DOT__write_reg;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen = vlSelfRef.u_decoder__DOT__reg_write;
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
    vlSelfRef.u_decoder__DOT__rs1_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs1) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((0U 
                                                     != (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                    & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.u_decoder__DOT__rs1)))));
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1 
        = vlSelfRef.u_decoder__DOT__rs1;
    vlSelfRef.id_rs2 = vlSelfRef.u_decoder__DOT__rs2;
    vlSelfRef.u_decoder__DOT__rs2_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs2) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                    & (0U 
                                                       != (IData)(vlSelfRef.u_decoder__DOT__rs2))));
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
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1))
            ? 0U : vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
           [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1]);
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2))
            ? 0U : vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
           [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2]);
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
    vlSelfRef.u_decoder__DOT__rs1_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1;
    vlSelfRef.u_decoder__DOT__rs2_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2;
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

VL_INLINE_OPT void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.if_pc = vlSymsp->TOP__CoreTop__u_ifu.inst_PC;
    vlSelfRef.u_dmem__DOT__gnt = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.gnt;
    vlSelfRef.u_dmem__DOT__err = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.err;
    vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr = (0xfffU 
                                                  & (vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.addr 
                                                     >> 2U));
    vlSelfRef.u_dmem__DOT__rack = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.rack;
    vlSelfRef.dmem_gnt = vlSelfRef.u_dmem__DOT__gnt;
    vlSelfRef.dmem_err = vlSelfRef.u_dmem__DOT__err;
    vlSelfRef.u_dmem__DOT__dmem__DOT__write_data = 
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr];
    if ((1U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffff00U & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xffU & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    }
    if ((2U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffff00ffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff00U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    }
    if ((4U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xff00ffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff0000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    }
    if ((8U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff000000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    }
    vlSelfRef.dmem_rack = vlSelfRef.u_dmem__DOT__rack;
}

VL_INLINE_OPT void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.if_valid = vlSymsp->TOP__CoreTop__u_ifu.valid;
    vlSelfRef.u_dmem__DOT__rdata = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.rdata;
    vlSelfRef.u_if_id_reg__DOT__ctrl_in = vlSelfRef.if_valid;
    vlSelfRef.mem_rdata = vlSelfRef.u_dmem__DOT__rdata;
    vlSelfRef.wb_write_data = ((0x800U & vlSelfRef.mem_data_out[2U])
                                ? vlSelfRef.mem_rdata
                                : vlSelfRef.u_dmem__DOT__addr);
    vlSelfRef.u_decoder__DOT__write_data = vlSelfRef.wb_write_data;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata 
        = vlSelfRef.u_decoder__DOT__write_data;
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
    vlSelfRef.real_if_id_flush = ((IData)(vlSelfRef.flush) 
                                  | (IData)(vlSelfRef.flush_d));
    vlSelfRef.u_if_id_reg__DOT__flush = vlSelfRef.real_if_id_flush;
}

VL_INLINE_OPT void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__3\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.if_instruction = vlSymsp->TOP__CoreTop__u_ifu.instruction;
    vlSelfRef.u_if_id_reg__DOT__data_in = (((QData)((IData)(vlSelfRef.if_pc)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.if_instruction)));
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0;
    __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0;
    __VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__u_dmem__DOT__dmem__DOT__mem__v0;
    __VdlySet__u_dmem__DOT__dmem__DOT__mem__v0 = 0;
    // Body
    __VdlySet__u_dmem__DOT__dmem__DOT__mem__v0 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__rst)))) {
        if (((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
             & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt))) {
            __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0 
                = vlSelfRef.u_dmem__DOT__dmem__DOT__write_data;
            __VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0 
                = vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr;
            __VdlySet__u_dmem__DOT__dmem__DOT__mem__v0 = 1U;
        }
    }
    if (__VdlySet__u_dmem__DOT__dmem__DOT__mem__v0) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[__VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0] 
            = __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__3\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack = 
        ((1U & (~ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__rst))) 
         && ((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
             & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt)));
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__4(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__4\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__wack = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack;
    vlSelfRef.dmem_wack = vlSelfRef.u_dmem__DOT__wack;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__5(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__5\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.rst)))))) {
        VL_WRITEF_NX("%8t | %5d |      2'b%b |   %x |   %x |   %x |  %x | %x |   %x   |   %x   |  %b   |   %b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,32,
                     vlSelfRef.cycle_cnt,2,(IData)(vlSelfRef.id_pc_sel),
                     32,vlSymsp->TOP__CoreTop__u_ifu.next_PC,
                     32,vlSymsp->TOP__CoreTop__u_ifu.PC_reg,
                     32,vlSelfRef.if_pc,32,vlSelfRef.if_instruction,
                     32,vlSelfRef.id_pc,32,vlSelfRef.id_instruction_real,
                     32,vlSelfRef.wb_write_data,1,(IData)(vlSelfRef.wb_reg_write),
                     1,vlSelfRef.real_if_id_flush);
        if (VL_UNLIKELY((vlSelfRef.flush))) {
            VL_WRITEF_NX("          >>> [FLUSH DETECTED] Branch/Jump Taken at Time %0t ns | Target PC: %x <<<\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         32,vlSymsp->TOP__CoreTop__u_ifu.next_PC);
        }
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__6(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__6\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.if_valid = vlSymsp->TOP__CoreTop__u_ifu.valid;
    vlSelfRef.if_instruction = vlSymsp->TOP__CoreTop__u_ifu.instruction;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__8(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__8\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr = (0xfffU 
                                                  & (vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.addr 
                                                     >> 2U));
    vlSelfRef.u_dmem__DOT__rack = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.rack;
    vlSelfRef.dmem_rack = vlSelfRef.u_dmem__DOT__rack;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__10(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__10\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.if_pc = vlSymsp->TOP__CoreTop__u_ifu.inst_PC;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__dmem__DOT__write_data = 
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr];
    if ((1U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffff00U & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xffU & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    }
    if ((2U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffff00ffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff00U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    }
    if ((4U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xff00ffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff0000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    }
    if ((8U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff000000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__rdata = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.rdata;
    vlSelfRef.mem_rdata = vlSelfRef.u_dmem__DOT__rdata;
    vlSelfRef.wb_write_data = ((0x800U & vlSelfRef.mem_data_out[2U])
                                ? vlSelfRef.mem_rdata
                                : vlSelfRef.u_dmem__DOT__addr);
    vlSelfRef.u_decoder__DOT__write_data = vlSelfRef.wb_write_data;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata 
        = vlSelfRef.u_decoder__DOT__write_data;
}
