// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_CoreTop.h"
#include "VCoreTop__Syms.h"

VL_ATTR_COLD void VCoreTop_CoreTop___eval_static__TOP__CoreTop(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___eval_static__TOP__CoreTop\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cycle_cnt = 0U;
    ++(vlSymsp->__Vcoverage[16]);
}

VL_ATTR_COLD void VCoreTop_CoreTop___eval_initial__TOP__CoreTop(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___eval_initial__TOP__CoreTop\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.stall = 0U;
    VL_WRITEF_NX("===============================================================================================================================================\n Time(ns) | Cycle | [IF] pc_sel | [IF] next_PC | [IF] PC_reg | [IF] inst_PC | [IF] Instr | [ID] PC | [ID] Real_Inst | [EX] WB_Data | RegW | Flush\n===============================================================================================================================================\n",0);
    ++(vlSymsp->__Vcoverage[15]);
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x1000U, vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[(0xfffU 
                                               & vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i)] = 0U;
        ++(vlSymsp->__Vcoverage[175]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i);
    }
    ++(vlSymsp->__Vcoverage[177]);
    ++(vlSymsp->__Vcoverage[178]);
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
    vlSelfRef.u_control_unit__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_execute__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_ex_mem_reg__DOT__clk = vlSelfRef.clk;
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
    vlSelfRef.u_ex_mem_reg__DOT__ctrl_in = vlSelfRef.id_valid;
    vlSelfRef.u_decoder__DOT__PC = vlSelfRef.id_pc;
    vlSelfRef.u_execute__DOT__PC = vlSelfRef.id_pc;
    vlSelfRef.id_instruction_real = ((IData)(vlSelfRef.id_valid)
                                      ? ([&]() {
                ++(vlSymsp->__Vcoverage[3]);
            }(), vlSelfRef.id_instruction) : ([&]() {
                ++(vlSymsp->__Vcoverage[4]);
            }(), 0x13U));
    vlSelfRef.u_decoder__DOT__write_reg = vlSelfRef.wb_write_reg;
    vlSelfRef.u_decoder__DOT__reg_write = vlSelfRef.wb_reg_write;
    vlSelfRef.u_decoder__DOT__instruction = vlSelfRef.id_instruction_real;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr 
        = vlSelfRef.u_decoder__DOT__write_reg;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen = vlSelfRef.u_decoder__DOT__reg_write;
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
    vlSelfRef.id_funct3 = vlSelfRef.u_decoder__DOT__funct3;
    vlSelfRef.u_decoder__DOT__u_imm_32 = (vlSelfRef.u_decoder__DOT__u_imm 
                                          << 0xcU);
    vlSelfRef.u_decoder__DOT__i_imm_32 = (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.u_decoder__DOT__i_imm_orig) 
                                                          >> 0xbU)))) 
                                           << 0xcU) 
                                          | (IData)(vlSelfRef.u_decoder__DOT__i_imm_orig));
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
    if ((0x23U == (IData)(vlSelfRef.u_decoder__DOT__opcode))) {
        if ((0U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            vlSelfRef.u_decoder__DOT__mem_wbe = 1U;
            ++(vlSymsp->__Vcoverage[96]);
        } else if ((1U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            ++(vlSymsp->__Vcoverage[97]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 3U;
        } else if ((2U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            ++(vlSymsp->__Vcoverage[98]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 0xfU;
        } else {
            ++(vlSymsp->__Vcoverage[99]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 0U;
        }
        ++(vlSymsp->__Vcoverage[100]);
    } else {
        ++(vlSymsp->__Vcoverage[101]);
        vlSelfRef.u_decoder__DOT__mem_wbe = 0U;
    }
    ++(vlSymsp->__Vcoverage[102]);
    vlSelfRef.id_opcode = vlSelfRef.u_decoder__DOT__opcode;
    vlSelfRef.u_execute__DOT__funct3 = vlSelfRef.id_funct3;
    vlSelfRef.id_jal_target = vlSelfRef.u_decoder__DOT__JAL_target;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[103]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[104]);
            }(), vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
                        [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1]));
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[105]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[106]);
            }(), vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
                        [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2]));
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
                    ++(vlSymsp->__Vcoverage[36]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[37]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memWrite = (1U & 
                                               ((0x23U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[70]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[71]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memRead = (1U & 
                                              ((3U 
                                                == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                ? ([&]() {
                    ++(vlSymsp->__Vcoverage[74]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[75]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memtoReg = (1U & 
                                               ((3U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[76]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[77]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__next_PC_sel = (3U 
                                                  & ((0x63U 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                      ? 
                                                     ([&]() {
                    ++(vlSymsp->__Vcoverage[78]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[83]);
                }(), ((0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[79]);
                        }(), 2U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[82]);
                        }(), ((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[80]);
                                }(), 3U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[81]);
                                }(), 0U)))))));
    vlSelfRef.u_control_unit__DOT__branch_op = (1U 
                                                & ((0x63U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[72]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[73]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__ALUOp = (7U & ((0x33U 
                                                   == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                   ? 
                                                  ([&]() {
                    ++(vlSymsp->__Vcoverage[38]);
                }(), 0U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[51]);
                }(), ((0x13U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[39]);
                        }(), 1U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[50]);
                        }(), ((0x23U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[40]);
                                }(), 5U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[49]);
                                }(), ((3U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                       ? ([&]() {
                                            ++(vlSymsp->__Vcoverage[41]);
                                        }(), 4U) : 
                                      ([&]() {
                                            ++(vlSymsp->__Vcoverage[48]);
                                        }(), ((0x63U 
                                               == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                               ? ([&]() {
                                                    ++(vlSymsp->__Vcoverage[42]);
                                                }(), 2U)
                                               : ([&]() {
                                                    ++(vlSymsp->__Vcoverage[47]);
                                                }(), 
                                                  (((0x67U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                    | (0x6fU 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                    ? 
                                                   ([&]() {
                                                            ++(vlSymsp->__Vcoverage[43]);
                                                        }(), 3U)
                                                    : 
                                                   ([&]() {
                                                            ++(vlSymsp->__Vcoverage[46]);
                                                        }(), 
                                                    (((0x17U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                      | (0x37U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                      ? 
                                                     ([&]() {
                                                                    ++(vlSymsp->__Vcoverage[44]);
                                                                }(), 6U)
                                                      : 
                                                     ([&]() {
                                                                    ++(vlSymsp->__Vcoverage[45]);
                                                                }(), 0U)))))))))))))));
    vlSelfRef.u_control_unit__DOT__operand_A = (3U 
                                                & ((0x17U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[52]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[57]);
                }(), ((0x37U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[53]);
                        }(), 3U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[56]);
                        }(), (((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                               | (0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[54]);
                                }(), 2U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[55]);
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
                    ++(vlSymsp->__Vcoverage[58]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[59]);
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
                ++(vlSymsp->__Vcoverage[60]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[69]);
            }(), ((0x23U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[61]);
                    }(), 1U) : ([&]() {
                        ++(vlSymsp->__Vcoverage[68]);
                    }(), ((0x63U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[62]);
                            }(), 2U) : ([&]() {
                                ++(vlSymsp->__Vcoverage[67]);
                            }(), (((0x17U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                   | (0x37U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[63]);
                                    }(), 3U) : ([&]() {
                                        ++(vlSymsp->__Vcoverage[66]);
                                    }(), ((0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                           ? ([&]() {
                                                ++(vlSymsp->__Vcoverage[64]);
                                            }(), 4U)
                                           : ([&]() {
                                                ++(vlSymsp->__Vcoverage[65]);
                                            }(), 0U))))))))));
    vlSelfRef.u_decoder__DOT__branch_target = (vlSelfRef.u_decoder__DOT__PC 
                                               + vlSelfRef.u_decoder__DOT__sb_imm_32);
    vlSelfRef.id_reg_write = vlSelfRef.u_control_unit__DOT__regWrite;
    vlSelfRef.id_mem_write = vlSelfRef.u_control_unit__DOT__memWrite;
    vlSelfRef.id_mem_read = vlSelfRef.u_control_unit__DOT__memRead;
    vlSelfRef.id_mem_to_reg = vlSelfRef.u_control_unit__DOT__memtoReg;
    vlSelfRef.id_pc_sel = vlSelfRef.u_control_unit__DOT__next_PC_sel;
    vlSelfRef.id_branch_op = vlSelfRef.u_control_unit__DOT__branch_op;
    vlSelfRef.id_alu_op = vlSelfRef.u_control_unit__DOT__ALUOp;
    vlSelfRef.id_operand_a = vlSelfRef.u_control_unit__DOT__operand_A;
    vlSelfRef.id_operand_b = vlSelfRef.u_control_unit__DOT__operand_B;
    vlSelfRef.id_extend_sel = vlSelfRef.u_control_unit__DOT__extend_sel;
    vlSelfRef.id_branch_target = vlSelfRef.u_decoder__DOT__branch_target;
    VL_ASSIGNBIT_WI(0x4cU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[5]);
                }(), (IData)(vlSelfRef.id_reg_write))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[6]);
                }(), 0U)));
    VL_ASSIGNBIT_WI(0x49U, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[7]);
                }(), (IData)(vlSelfRef.id_mem_write))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[8]);
                }(), 0U)));
    VL_ASSIGNBIT_WI(0x4aU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[9]);
                }(), (IData)(vlSelfRef.id_mem_read))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[10]);
                }(), 0U)));
    VL_ASSIGNBIT_WI(0x4bU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[11]);
                }(), (IData)(vlSelfRef.id_mem_to_reg))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[12]);
                }(), 0U)));
    vlSelfRef.u_execute__DOT__branch_op = vlSelfRef.id_branch_op;
    vlSelfRef.u_execute__DOT__ALU_Operation = vlSelfRef.id_alu_op;
    vlSelfRef.u_execute__DOT__ALU_ASrc = vlSelfRef.id_operand_a;
    vlSelfRef.u_execute__DOT__ALU_BSrc = vlSelfRef.id_operand_b;
    vlSelfRef.u_decoder__DOT__extend_sel = vlSelfRef.id_extend_sel;
    if ((0U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                 << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7)))) {
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
        ++(vlSymsp->__Vcoverage[122]);
    } else if ((0x20U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                           << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7)))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlSelfRef.u_execute__DOT__ALU_Control = (8U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((0x680U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                            << 0xaU) | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                         << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7))))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
    } else if ((0x6a0U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                            << 0xaU) | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                         << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7))))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlSelfRef.u_execute__DOT__ALU_Control = (8U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((1U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
    } else if ((2U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlSelfRef.u_execute__DOT__ALU_Control = (0x10U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((3U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlSelfRef.u_execute__DOT__ALU_Control = 0x1fU;
    } else {
        ++(vlSymsp->__Vcoverage[116]);
        vlSelfRef.u_execute__DOT__ALU_Control = 0U;
    }
    ++(vlSymsp->__Vcoverage[123]);
    vlSelfRef.u_decoder__DOT__extend_imm = ((1U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                             ? ([&]() {
                ++(vlSymsp->__Vcoverage[84]);
            }(), vlSelfRef.u_decoder__DOT__s_imm_32)
                                             : ([&]() {
                ++(vlSymsp->__Vcoverage[91]);
            }(), ((2U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[85]);
                    }(), vlSelfRef.u_decoder__DOT__sb_imm_32)
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[90]);
                    }(), ((3U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[86]);
                            }(), vlSelfRef.u_decoder__DOT__u_imm_32)
                           : ([&]() {
                                ++(vlSymsp->__Vcoverage[89]);
                            }(), ((4U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[87]);
                                    }(), vlSelfRef.u_decoder__DOT__uj_imm_32)
                                   : ([&]() {
                                        ++(vlSymsp->__Vcoverage[88]);
                                    }(), vlSelfRef.u_decoder__DOT__i_imm_32))))))));
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control 
        = vlSelfRef.u_execute__DOT__ALU_Control;
    vlSelfRef.id_extend_imm = vlSelfRef.u_decoder__DOT__extend_imm;
    vlSelfRef.u_execute__DOT__extend = vlSelfRef.id_extend_imm;
}

VL_ATTR_COLD void VCoreTop_CoreTop___configure_coverage(VCoreTop_CoreTop* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___configure_coverage\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 105, 9, "", "v_branch/CoreTop", "if", "105-106");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 105, 10, "", "v_branch/CoreTop", "else", "108");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 104, 5, "", "v_line/CoreTop", "block", "104");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 151, 45, "", "v_branch/CoreTop", "cond_then", "151");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 151, 46, "", "v_branch/CoreTop", "cond_else", "151");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 223, 50, "", "v_branch/CoreTop", "cond_then", "223");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 223, 51, "", "v_branch/CoreTop", "cond_else", "223");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 224, 50, "", "v_branch/CoreTop", "cond_then", "224");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 224, 51, "", "v_branch/CoreTop", "cond_else", "224");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 225, 50, "", "v_branch/CoreTop", "cond_then", "225");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 225, 51, "", "v_branch/CoreTop", "cond_else", "225");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 226, 50, "", "v_branch/CoreTop", "cond_then", "226");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 226, 51, "", "v_branch/CoreTop", "cond_else", "226");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 272, 54, "", "v_branch/CoreTop", "cond_then", "272");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 272, 55, "", "v_branch/CoreTop", "cond_else", "272");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 280, 5, "", "v_line/CoreTop", "block", "280-283");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 286, 21, "", "v_line/CoreTop", "block", "286");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 288, 9, "", "v_branch/CoreTop", "if", "288");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 288, 10, "", "v_branch/CoreTop", "else", "289");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 287, 5, "", "v_line/CoreTop", "block", "287");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 308, 9, "", "v_branch/CoreTop", "if", "308-309");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 308, 10, "", "v_branch/CoreTop", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 292, 27, "", "v_branch/CoreTop", "if", "292-305");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 292, 28, "", "v_branch/CoreTop", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 292, 31, "", "v_expr/CoreTop", "(rst==0) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 292, 31, "", "v_expr/CoreTop", "(rst==1) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 292, 5, "", "v_line/CoreTop", "block", "292");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 47, 22, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "if", "47-48");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 47, 23, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 45, 13, ".u_if_id_reg", "v_line/PipelineReg__C1_D40", "elsif", "45-46");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 41, 9, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "if", "41-42");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 41, 10, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "else", "43");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 40, 5, ".u_if_id_reg", "v_line/PipelineReg__C1_D40", "block", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 58, 9, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "if", "58-59");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 58, 10, ".u_if_id_reg", "v_branch/PipelineReg__C1_D40", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 57, 5, ".u_if_id_reg", "v_line/PipelineReg__C1_D40", "block", "57");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 51, 66, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "51");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 51, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "51");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 52, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "52");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 53, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "53");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 54, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "54");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 55, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "55");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 56, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "56");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 57, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "57");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 58, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 58, 68, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 57, 68, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 56, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 55, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 54, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 53, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 52, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 60, 44, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "60");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 61, 44, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "61");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 62, 66, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "62");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 62, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "62");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 61, 45, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 60, 45, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 66, 46, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "66");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 66, 47, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "66");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 67, 87, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "67");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 68, 47, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "68");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 69, 47, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "69");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 70, 66, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "70");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 71, 47, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "71");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[65]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 71, 48, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "71");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[66]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 70, 67, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[67]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 69, 48, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[68]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 68, 48, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[69]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 67, 88, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[70]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 73, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "73");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[71]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 73, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "73");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[72]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 74, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "74");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[73]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 74, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "74");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[74]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 75, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "75");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[75]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 75, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "75");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[76]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 76, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "76");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[77]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 76, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "76");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[78]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 77, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "77");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 78, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "78");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 79, 49, ".u_control_unit", "v_branch/ControlUnit", "cond_then", "79");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 79, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "79");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 78, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/control_unit.sv", 77, 50, ".u_control_unit", "v_branch/ControlUnit", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 89, 50, ".u_decoder", "v_branch/Decoder", "cond_then", "89");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 90, 50, ".u_decoder", "v_branch/Decoder", "cond_then", "90");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 91, 50, ".u_decoder", "v_branch/Decoder", "cond_then", "91");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 92, 50, ".u_decoder", "v_branch/Decoder", "cond_then", "92");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[88]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 92, 51, ".u_decoder", "v_branch/Decoder", "cond_else", "93");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[89]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 91, 51, ".u_decoder", "v_branch/Decoder", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[90]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 90, 51, ".u_decoder", "v_branch/Decoder", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 89, 51, ".u_decoder", "v_branch/Decoder", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 102, 48, ".u_decoder", "v_branch/Decoder", "cond_then", "102");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 102, 49, ".u_decoder", "v_branch/Decoder", "cond_else", "102");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 103, 48, ".u_decoder", "v_branch/Decoder", "cond_then", "103");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 103, 49, ".u_decoder", "v_branch/Decoder", "cond_else", "103");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 108, 27, ".u_decoder", "v_line/Decoder", "case", "108");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 109, 27, ".u_decoder", "v_line/Decoder", "case", "109");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 110, 27, ".u_decoder", "v_line/Decoder", "case", "110");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[99]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 111, 21, ".u_decoder", "v_line/Decoder", "case", "111");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[100]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 106, 9, ".u_decoder", "v_branch/Decoder", "if", "106-107");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[101]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 106, 10, ".u_decoder", "v_branch/Decoder", "else", "113");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[102]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/decoder.sv", 105, 5, ".u_decoder", "v_line/Decoder", "block", "105");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[103]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 39, 46, ".u_decoder.u_regfile", "v_branch/RegFile", "cond_then", "39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[104]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 39, 47, ".u_decoder.u_regfile", "v_branch/RegFile", "cond_else", "39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[105]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 40, 46, ".u_decoder.u_regfile", "v_branch/RegFile", "cond_then", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[106]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 40, 47, ".u_decoder.u_regfile", "v_branch/RegFile", "cond_else", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[107]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 64, 13, ".u_decoder.u_regfile", "v_line/RegFile", "block", "64-65");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[108]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 18, ".u_decoder.u_regfile", "v_branch/RegFile", "if", "67-68");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[109]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 19, ".u_decoder.u_regfile", "v_branch/RegFile", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[110]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 27, ".u_decoder.u_regfile", "v_expr/RegFile", "(rst==0 && wen==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[111]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 27, ".u_decoder.u_regfile", "v_expr/RegFile", "(wen==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[112]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 67, 27, ".u_decoder.u_regfile", "v_expr/RegFile", "(rst==1) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[113]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 63, 9, ".u_decoder.u_regfile", "v_line/RegFile", "elsif", "63-64");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[114]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/reg_file.sv", 62, 5, ".u_decoder.u_regfile", "v_line/RegFile", "block", "62");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[115]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 59, 14, ".u_execute", "v_line/execute", "if", "59,61");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[116]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 59, 15, ".u_execute", "v_line/execute", "else", "63,65");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[117]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 55, 14, ".u_execute", "v_line/execute", "elsif", "55,57");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[118]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 51, 14, ".u_execute", "v_line/execute", "elsif", "51,53");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[119]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 47, 14, ".u_execute", "v_line/execute", "elsif", "47,49");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[120]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 43, 14, ".u_execute", "v_line/execute", "elsif", "43,45");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[121]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 39, 14, ".u_execute", "v_line/execute", "elsif", "39,41");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[122]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 35, 9, ".u_execute", "v_line/execute", "elsif", "35,37");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[123]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 34, 5, ".u_execute", "v_line/execute", "block", "34");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[124]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 75, 46, ".u_execute", "v_branch/execute", "cond_then", "75");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[125]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 76, 50, ".u_execute", "v_branch/execute", "cond_then", "76");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[126]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 77, 46, ".u_execute", "v_branch/execute", "cond_then", "77");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[127]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 77, 47, ".u_execute", "v_branch/execute", "cond_else", "78");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[128]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 76, 51, ".u_execute", "v_branch/execute", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 75, 47, ".u_execute", "v_branch/execute", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[130]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 81, 34, ".u_execute", "v_branch/execute", "cond_then", "81");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[131]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/execute.sv", 81, 35, ".u_execute", "v_branch/execute", "cond_else", "81");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[132]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 39, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[133]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 40, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[134]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 42, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "42");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[135]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 43, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "43");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[136]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 44, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "44");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[137]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 46, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "46");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[138]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 47, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "47");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[139]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 49, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "49");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[140]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 50, 51, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[141]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 51, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "51");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[142]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 53, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "53");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[143]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 54, 63, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "54");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[144]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 55, 63, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "55");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[145]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 56, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "56");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[146]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 57, 42, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "57");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[147]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 58, 63, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[148]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 59, 63, ".u_execute.u_alu", "v_branch/ALU", "cond_then", "59");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[149]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 59, 64, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "60");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[150]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 58, 64, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[151]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 57, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[152]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 56, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[153]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 55, 64, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[154]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 54, 64, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[155]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 53, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[156]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 51, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[157]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 50, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[158]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 49, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[159]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 47, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[160]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 46, 43, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[161]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 44, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[162]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 43, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[163]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 42, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[164]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 40, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[165]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ALU.sv", 39, 52, ".u_execute.u_alu", "v_branch/ALU", "cond_else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[166]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 47, 22, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "if", "47-48");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[167]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 47, 23, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[168]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 45, 13, ".u_ex_mem_reg", "v_line/PipelineReg__C1_D4d", "elsif", "45-46");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[169]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 41, 9, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "if", "41-42");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[170]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 41, 10, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "else", "43");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[171]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 40, 5, ".u_ex_mem_reg", "v_line/PipelineReg__C1_D4d", "block", "40");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[172]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 58, 9, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "if", "58-59");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[173]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 58, 10, ".u_ex_mem_reg", "v_branch/PipelineReg__C1_D4d", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[174]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/pipeline_reg.sv", 57, 5, ".u_ex_mem_reg", "v_line/PipelineReg__C1_D4d", "block", "57");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[175]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 34, 9, ".u_dmem.dmem", "v_line/DMem", "block", "34-35");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[176]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 38, 9, ".u_dmem.dmem", "v_branch/DMem", "if", "38-39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[177]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 38, 10, ".u_dmem.dmem", "v_branch/DMem", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[178]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 33, 5, ".u_dmem.dmem", "v_line/DMem", "block", "33-34");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[179]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 59, 13, ".u_dmem.dmem", "v_branch/DMem", "if", "59-60");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[180]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 59, 14, ".u_dmem.dmem", "v_branch/DMem", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[181]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 58, 9, ".u_dmem.dmem", "v_line/DMem", "block", "58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[182]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 56, 5, ".u_dmem.dmem", "v_line/DMem", "block", "56-58");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[183]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 13, ".u_dmem.dmem", "v_branch/DMem", "if", "73-74");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[184]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 14, ".u_dmem.dmem", "v_branch/DMem", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[185]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 28, ".u_dmem.dmem", "v_expr/DMem", "(dbus.write==1 && gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[186]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 28, ".u_dmem.dmem", "v_expr/DMem", "(gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[187]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 73, 28, ".u_dmem.dmem", "v_expr/DMem", "(dbus.write==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[188]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 77, 37, ".u_dmem.dmem", "v_expr/DMem", "(dbus.write==1 && gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[189]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 77, 37, ".u_dmem.dmem", "v_expr/DMem", "(gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[190]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 77, 37, ".u_dmem.dmem", "v_expr/DMem", "(dbus.write==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[191]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 70, 9, ".u_dmem.dmem", "v_branch/DMem", "if", "70-71");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[192]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 70, 10, ".u_dmem.dmem", "v_branch/DMem", "else", "72,77");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[193]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dmem.sv", 69, 5, ".u_dmem.dmem", "v_line/DMem", "block", "69");
}
