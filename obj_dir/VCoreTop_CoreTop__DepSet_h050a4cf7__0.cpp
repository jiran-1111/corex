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
        ++(vlSymsp->__Vcoverage[179]);
    } else {
        ++(vlSymsp->__Vcoverage[180]);
    }
    ++(vlSymsp->__Vcoverage[181]);
    if ((2U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffff00ffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff00U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[180]);
    }
    ++(vlSymsp->__Vcoverage[181]);
    if ((4U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xff00ffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff0000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[180]);
    }
    ++(vlSymsp->__Vcoverage[181]);
    if ((8U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff000000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[180]);
    }
    ++(vlSymsp->__Vcoverage[181]);
    ++(vlSymsp->__Vcoverage[182]);
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
                                ? ([&]() {
                ++(vlSymsp->__Vcoverage[13]);
            }(), vlSelfRef.mem_rdata) : ([&]() {
                ++(vlSymsp->__Vcoverage[14]);
            }(), vlSelfRef.mem_data_out[1U]));
    vlSelfRef.u_decoder__DOT__write_data = vlSelfRef.wb_write_data;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata 
        = vlSelfRef.u_decoder__DOT__write_data;
    vlSelfRef.u_decoder__DOT__rs1_data = ((IData)(vlSelfRef.u_decoder__DOT__rs1_data_bypass)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[93]);
            }(), vlSelfRef.u_decoder__DOT__write_data)
                                           : ([&]() {
                ++(vlSymsp->__Vcoverage[92]);
            }(), vlSelfRef.u_decoder__DOT__rs1_data_decode));
    vlSelfRef.u_decoder__DOT__rs2_data = ((IData)(vlSelfRef.u_decoder__DOT__rs2_data_bypass)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[95]);
            }(), vlSelfRef.u_decoder__DOT__write_data)
                                           : ([&]() {
                ++(vlSymsp->__Vcoverage[94]);
            }(), vlSelfRef.u_decoder__DOT__rs2_data_decode));
    vlSelfRef.id_rs1_data = vlSelfRef.u_decoder__DOT__rs1_data;
    vlSelfRef.id_rs2_data = vlSelfRef.u_decoder__DOT__rs2_data;
    vlSelfRef.u_execute__DOT__regRead_1 = vlSelfRef.id_rs1_data;
    vlSelfRef.u_execute__DOT__regRead_2 = vlSelfRef.id_rs2_data;
    vlSelfRef.u_execute__DOT__JALR_target = (0xfffffffeU 
                                             & (vlSelfRef.u_execute__DOT__extend 
                                                + vlSelfRef.u_execute__DOT__regRead_1));
    vlSelfRef.u_execute__DOT__alu_in_a = ((1U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[124]);
            }(), vlSelfRef.u_execute__DOT__PC) : ([&]() {
                ++(vlSymsp->__Vcoverage[129]);
            }(), ((2U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[125]);
                    }(), ((IData)(4U) + vlSelfRef.u_execute__DOT__PC))
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[128]);
                    }(), ((3U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[126]);
                            }(), 0U) : ([&]() {
                                ++(vlSymsp->__Vcoverage[127]);
                            }(), vlSelfRef.u_execute__DOT__regRead_1))))));
    vlSelfRef.u_execute__DOT__alu_in_b = ((IData)(vlSelfRef.u_execute__DOT__ALU_BSrc)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[130]);
            }(), vlSelfRef.u_execute__DOT__extend) : 
                                          ([&]() {
                ++(vlSymsp->__Vcoverage[131]);
            }(), vlSelfRef.u_execute__DOT__regRead_2));
    vlSelfRef.ex_jalr_target = vlSelfRef.u_execute__DOT__JALR_target;
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
        = vlSelfRef.u_execute__DOT__alu_in_a;
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b 
        = vlSelfRef.u_execute__DOT__alu_in_b;
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal 
        = VL_GTES_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than 
        = VL_LTS_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than 
        = (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
           < vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__shamt = (0x1fU 
                                                   & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift 
        = VL_SHIFTRS_III(32,32,5, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt));
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result 
        = ((0U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[132]);
            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                  + vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
            : ([&]() {
                ++(vlSymsp->__Vcoverage[165]);
            }(), ((8U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[133]);
                    }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                          - vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[164]);
                    }(), ((4U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[134]);
                            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                  ^ vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                           : ([&]() {
                                ++(vlSymsp->__Vcoverage[163]);
                            }(), ((6U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[135]);
                                    }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                          | vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                   : ([&]() {
                                        ++(vlSymsp->__Vcoverage[162]);
                                    }(), ((7U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                           ? ([&]() {
                                                ++(vlSymsp->__Vcoverage[136]);
                                            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                  & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                           : ([&]() {
                                                ++(vlSymsp->__Vcoverage[161]);
                                            }(), ((2U 
                                                   == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                   ? 
                                                  ([&]() {
                                                        ++(vlSymsp->__Vcoverage[137]);
                                                    }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than)
                                                   : 
                                                  ([&]() {
                                                        ++(vlSymsp->__Vcoverage[160]);
                                                    }(), 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                     ? 
                                                    ([&]() {
                                                                ++(vlSymsp->__Vcoverage[138]);
                                                            }(), vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than)
                                                     : 
                                                    ([&]() {
                                                                ++(vlSymsp->__Vcoverage[159]);
                                                            }(), 
                                                     ((1U 
                                                       == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                       ? 
                                                      ([&]() {
                                                                        ++(vlSymsp->__Vcoverage[139]);
                                                                    }(), 
                                                       (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                        << (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt)))
                                                       : 
                                                      ([&]() {
                                                                        ++(vlSymsp->__Vcoverage[158]);
                                                                    }(), 
                                                       ((5U 
                                                         == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                         ? 
                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[140]);
                                                                            }(), 
                                                         (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                          >> (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt)))
                                                         : 
                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[157]);
                                                                            }(), 
                                                         ((0xdU 
                                                           == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                           ? 
                                                          ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[141]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift)
                                                           : 
                                                          ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[156]);
                                                                                }(), 
                                                           ((0x1fU 
                                                             == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                             ? 
                                                            ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[142]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a)
                                                             : 
                                                            ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[155]);
                                                                                }(), 
                                                             ((0x10U 
                                                               == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                               ? 
                                                              ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[143]);
                                                                                }(), 
                                                               (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                == vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                               : 
                                                              ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[154]);
                                                                                }(), 
                                                               ((0x11U 
                                                                 == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                 ? 
                                                                ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[144]);
                                                                                }(), 
                                                                 (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                  != vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                 : 
                                                                ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[153]);
                                                                                }(), 
                                                                 ((0x14U 
                                                                   == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                   ? 
                                                                  ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[145]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than)
                                                                   : 
                                                                  ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[152]);
                                                                                }(), 
                                                                   ((0x15U 
                                                                     == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                     ? 
                                                                    ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[146]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal)
                                                                     : 
                                                                    ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[151]);
                                                                                }(), 
                                                                     ((0x16U 
                                                                       == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                       ? 
                                                                      ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[147]);
                                                                                }(), 
                                                                       (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                        < vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                       : 
                                                                      ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[150]);
                                                                                }(), 
                                                                       ((0x17U 
                                                                         == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                         ? 
                                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[148]);
                                                                                }(), 
                                                                         (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                          >= vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                         : 
                                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[149]);
                                                                                }(), 0U))))))))))))))))))))))))))))))))));
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
    vlSelfRef.id_ex_data_in[2U] = ((0x1e00U & vlSelfRef.id_ex_data_in[2U]) 
                                   | (0x1fffU & (((IData)(vlSelfRef.id_mem_wbe) 
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

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__cycle_cnt = vlSelfRef.cycle_cnt;
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[17]);
        vlSelfRef.__Vdly__cycle_cnt = 0U;
    } else {
        vlSelfRef.__Vdly__cycle_cnt = ((IData)(1U) 
                                       + vlSelfRef.cycle_cnt);
        ++(vlSymsp->__Vcoverage[18]);
    }
    ++(vlSymsp->__Vcoverage[19]);
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[0]);
        vlSelfRef.flush_d = 0U;
    } else {
        ++(vlSymsp->__Vcoverage[1]);
        vlSelfRef.flush_d = vlSelfRef.flush;
    }
    ++(vlSymsp->__Vcoverage[2]);
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
    // Body
    if (vlSelfRef.u_dmem__DOT__dmem__DOT__rst) {
        ++(vlSymsp->__Vcoverage[191]);
        vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack = 0U;
    } else {
        if (((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
             & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt))) {
            ++(vlSymsp->__Vcoverage[183]);
            __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0 
                = vlSelfRef.u_dmem__DOT__dmem__DOT__write_data;
            __VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0 
                = vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr;
            vlSelfRef.__VdlySet__u_dmem__DOT__dmem__DOT__mem__v0 = 1U;
        } else {
            ++(vlSymsp->__Vcoverage[184]);
        }
        vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack 
            = ((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
               & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt));
        if (((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
             & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt))) {
            ++(vlSymsp->__Vcoverage[185]);
        }
        if ((1U & (~ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt)))) {
            ++(vlSymsp->__Vcoverage[186]);
        }
        if ((1U & (~ (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write)))) {
            ++(vlSymsp->__Vcoverage[187]);
        }
        if (((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
             & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt))) {
            ++(vlSymsp->__Vcoverage[188]);
        }
        if ((1U & (~ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt)))) {
            ++(vlSymsp->__Vcoverage[189]);
        }
        if ((1U & (~ (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write)))) {
            ++(vlSymsp->__Vcoverage[190]);
        }
        ++(vlSymsp->__Vcoverage[192]);
    }
    ++(vlSymsp->__Vcoverage[193]);
    if (vlSelfRef.__VdlySet__u_dmem__DOT__dmem__DOT__mem__v0) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[__VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0] 
            = __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__3\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__wack = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack;
    vlSelfRef.dmem_wack = vlSelfRef.u_dmem__DOT__wack;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__4(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__4\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_LIKELY((vlSelfRef.rst))) {
        ++(vlSymsp->__Vcoverage[23]);
    } else {
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
            ++(vlSymsp->__Vcoverage[20]);
        } else {
            ++(vlSymsp->__Vcoverage[21]);
        }
        ++(vlSymsp->__Vcoverage[22]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rst)))) {
        ++(vlSymsp->__Vcoverage[24]);
    }
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[25]);
    }
    ++(vlSymsp->__Vcoverage[26]);
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__5(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__5\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31 = 0;
    IData/*31:0*/ __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32;
    __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0;
    CData/*4:0*/ __VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32;
    __VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0;
    // Body
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0U;
    if (vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst) {
        ++(vlSymsp->__Vcoverage[107]);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0U;
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 1U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 2U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 3U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 4U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 5U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 6U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 7U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 8U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 9U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xaU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xbU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xcU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xdU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xeU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xfU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x10U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x11U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x12U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x13U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x14U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x15U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x16U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x17U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x18U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x19U;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1aU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1bU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1cU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1dU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1eU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1fU;
        ++(vlSymsp->__Vcoverage[107]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x20U;
        ++(vlSymsp->__Vcoverage[113]);
    } else {
        if (((~ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst)) 
             & (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen))) {
            ++(vlSymsp->__Vcoverage[108]);
            __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32 
                = vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata;
            __VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32 
                = vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr;
            __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32 = 1U;
        } else {
            ++(vlSymsp->__Vcoverage[109]);
        }
        if (((~ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst)) 
             & (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen))) {
            ++(vlSymsp->__Vcoverage[110]);
        }
        if ((1U & (~ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen)))) {
            ++(vlSymsp->__Vcoverage[111]);
        }
        if (vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst) {
            ++(vlSymsp->__Vcoverage[112]);
        }
    }
    ++(vlSymsp->__Vcoverage[114]);
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[1U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[2U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[3U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[4U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[5U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[6U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[7U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[8U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[9U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xaU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xbU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xcU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xdU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xeU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xfU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x10U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x11U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x12U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x13U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x14U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x15U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x16U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x17U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x18U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x19U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1aU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1bU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1cU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1dU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1eU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1fU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[__VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32] 
            = __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32;
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

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__7(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__7\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.u_ex_mem_reg__DOT__rst) {
        ++(vlSymsp->__Vcoverage[169]);
        vlSelfRef.u_ex_mem_reg__DOT__ctrl_q = 0U;
    } else {
        if (vlSelfRef.u_ex_mem_reg__DOT__flush) {
            ++(vlSymsp->__Vcoverage[168]);
            vlSelfRef.u_ex_mem_reg__DOT__ctrl_q = 0U;
        } else if (vlSelfRef.u_ex_mem_reg__DOT__en) {
            ++(vlSymsp->__Vcoverage[166]);
            vlSelfRef.u_ex_mem_reg__DOT__ctrl_q = vlSelfRef.u_ex_mem_reg__DOT__ctrl_in;
        } else {
            ++(vlSymsp->__Vcoverage[167]);
        }
        ++(vlSymsp->__Vcoverage[170]);
    }
    ++(vlSymsp->__Vcoverage[171]);
    if (vlSelfRef.u_ex_mem_reg__DOT__en) {
        ++(vlSymsp->__Vcoverage[172]);
        vlSelfRef.u_ex_mem_reg__DOT__data_q[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_in[0U];
        vlSelfRef.u_ex_mem_reg__DOT__data_q[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_in[1U];
        vlSelfRef.u_ex_mem_reg__DOT__data_q[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_in[2U];
    } else {
        ++(vlSymsp->__Vcoverage[173]);
    }
    ++(vlSymsp->__Vcoverage[174]);
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

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__9(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__9\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.u_if_id_reg__DOT__rst) {
        ++(vlSymsp->__Vcoverage[30]);
        vlSelfRef.u_if_id_reg__DOT__ctrl_q = 0U;
    } else {
        if (vlSelfRef.u_if_id_reg__DOT__flush) {
            ++(vlSymsp->__Vcoverage[29]);
            vlSelfRef.u_if_id_reg__DOT__ctrl_q = 0U;
        } else if (vlSelfRef.u_if_id_reg__DOT__en) {
            ++(vlSymsp->__Vcoverage[27]);
            vlSelfRef.u_if_id_reg__DOT__ctrl_q = vlSelfRef.u_if_id_reg__DOT__ctrl_in;
        } else {
            ++(vlSymsp->__Vcoverage[28]);
        }
        ++(vlSymsp->__Vcoverage[31]);
    }
    ++(vlSymsp->__Vcoverage[32]);
    if (vlSelfRef.u_if_id_reg__DOT__en) {
        ++(vlSymsp->__Vcoverage[33]);
        vlSelfRef.u_if_id_reg__DOT__data_q = vlSelfRef.u_if_id_reg__DOT__data_in;
    } else {
        ++(vlSymsp->__Vcoverage[34]);
    }
    ++(vlSymsp->__Vcoverage[35]);
    vlSelfRef.u_if_id_reg__DOT__ctrl_out = vlSelfRef.u_if_id_reg__DOT__ctrl_q;
    vlSelfRef.u_if_id_reg__DOT__data_out = vlSelfRef.u_if_id_reg__DOT__data_q;
    vlSelfRef.id_valid = vlSelfRef.u_if_id_reg__DOT__ctrl_out;
    vlSelfRef.id_pc = (IData)((vlSelfRef.u_if_id_reg__DOT__data_out 
                               >> 0x20U));
    vlSelfRef.id_instruction = (IData)(vlSelfRef.u_if_id_reg__DOT__data_out);
    vlSelfRef.u_ex_mem_reg__DOT__ctrl_in = vlSelfRef.id_valid;
    vlSelfRef.u_decoder__DOT__PC = vlSelfRef.id_pc;
    vlSelfRef.u_execute__DOT__PC = vlSelfRef.id_pc;
    vlSelfRef.id_instruction_real = ((IData)(vlSelfRef.id_valid)
                                      ? ([&]() {
                ++(vlSymsp->__Vcoverage[3]);
            }(), vlSelfRef.id_instruction) : ([&]() {
                ++(vlSymsp->__Vcoverage[4]);
            }(), 0x13U));
    vlSelfRef.u_decoder__DOT__instruction = vlSelfRef.id_instruction_real;
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
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1 
        = vlSelfRef.u_decoder__DOT__rs1;
    vlSelfRef.id_rs2 = vlSelfRef.u_decoder__DOT__rs2;
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
        ++(vlSymsp->__Vcoverage[179]);
    } else {
        ++(vlSymsp->__Vcoverage[180]);
    }
    ++(vlSymsp->__Vcoverage[181]);
    if ((2U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffff00ffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff00U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[180]);
    }
    ++(vlSymsp->__Vcoverage[181]);
    if ((4U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xff00ffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff0000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[180]);
    }
    ++(vlSymsp->__Vcoverage[181]);
    if ((8U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff000000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[180]);
    }
    ++(vlSymsp->__Vcoverage[181]);
    ++(vlSymsp->__Vcoverage[182]);
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__rdata = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.rdata;
    vlSelfRef.mem_rdata = vlSelfRef.u_dmem__DOT__rdata;
    vlSelfRef.wb_write_data = ((0x800U & vlSelfRef.mem_data_out[2U])
                                ? ([&]() {
                ++(vlSymsp->__Vcoverage[13]);
            }(), vlSelfRef.mem_rdata) : ([&]() {
                ++(vlSymsp->__Vcoverage[14]);
            }(), vlSelfRef.mem_data_out[1U]));
    vlSelfRef.u_decoder__DOT__write_data = vlSelfRef.wb_write_data;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata 
        = vlSelfRef.u_decoder__DOT__write_data;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__3\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.u_decoder__DOT__rs1_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1;
    vlSelfRef.u_decoder__DOT__rs2_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__5(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__5\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_decoder__DOT__rs1_data = ((IData)(vlSelfRef.u_decoder__DOT__rs1_data_bypass)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[93]);
            }(), vlSelfRef.u_decoder__DOT__write_data)
                                           : ([&]() {
                ++(vlSymsp->__Vcoverage[92]);
            }(), vlSelfRef.u_decoder__DOT__rs1_data_decode));
    vlSelfRef.u_decoder__DOT__rs2_data = ((IData)(vlSelfRef.u_decoder__DOT__rs2_data_bypass)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[95]);
            }(), vlSelfRef.u_decoder__DOT__write_data)
                                           : ([&]() {
                ++(vlSymsp->__Vcoverage[94]);
            }(), vlSelfRef.u_decoder__DOT__rs2_data_decode));
    vlSelfRef.id_rs1_data = vlSelfRef.u_decoder__DOT__rs1_data;
    vlSelfRef.id_rs2_data = vlSelfRef.u_decoder__DOT__rs2_data;
    vlSelfRef.u_execute__DOT__regRead_1 = vlSelfRef.id_rs1_data;
    vlSelfRef.u_execute__DOT__regRead_2 = vlSelfRef.id_rs2_data;
    vlSelfRef.u_execute__DOT__JALR_target = (0xfffffffeU 
                                             & (vlSelfRef.u_execute__DOT__extend 
                                                + vlSelfRef.u_execute__DOT__regRead_1));
    vlSelfRef.u_execute__DOT__alu_in_a = ((1U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[124]);
            }(), vlSelfRef.u_execute__DOT__PC) : ([&]() {
                ++(vlSymsp->__Vcoverage[129]);
            }(), ((2U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[125]);
                    }(), ((IData)(4U) + vlSelfRef.u_execute__DOT__PC))
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[128]);
                    }(), ((3U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[126]);
                            }(), 0U) : ([&]() {
                                ++(vlSymsp->__Vcoverage[127]);
                            }(), vlSelfRef.u_execute__DOT__regRead_1))))));
    vlSelfRef.u_execute__DOT__alu_in_b = ((IData)(vlSelfRef.u_execute__DOT__ALU_BSrc)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[130]);
            }(), vlSelfRef.u_execute__DOT__extend) : 
                                          ([&]() {
                ++(vlSymsp->__Vcoverage[131]);
            }(), vlSelfRef.u_execute__DOT__regRead_2));
    vlSelfRef.ex_jalr_target = vlSelfRef.u_execute__DOT__JALR_target;
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
        = vlSelfRef.u_execute__DOT__alu_in_a;
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b 
        = vlSelfRef.u_execute__DOT__alu_in_b;
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal 
        = VL_GTES_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than 
        = VL_LTS_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than 
        = (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
           < vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__shamt = (0x1fU 
                                                   & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift 
        = VL_SHIFTRS_III(32,32,5, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt));
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result 
        = ((0U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[132]);
            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                  + vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
            : ([&]() {
                ++(vlSymsp->__Vcoverage[165]);
            }(), ((8U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[133]);
                    }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                          - vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[164]);
                    }(), ((4U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[134]);
                            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                  ^ vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                           : ([&]() {
                                ++(vlSymsp->__Vcoverage[163]);
                            }(), ((6U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[135]);
                                    }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                          | vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                   : ([&]() {
                                        ++(vlSymsp->__Vcoverage[162]);
                                    }(), ((7U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                           ? ([&]() {
                                                ++(vlSymsp->__Vcoverage[136]);
                                            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                  & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                           : ([&]() {
                                                ++(vlSymsp->__Vcoverage[161]);
                                            }(), ((2U 
                                                   == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                   ? 
                                                  ([&]() {
                                                        ++(vlSymsp->__Vcoverage[137]);
                                                    }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than)
                                                   : 
                                                  ([&]() {
                                                        ++(vlSymsp->__Vcoverage[160]);
                                                    }(), 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                     ? 
                                                    ([&]() {
                                                                ++(vlSymsp->__Vcoverage[138]);
                                                            }(), vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than)
                                                     : 
                                                    ([&]() {
                                                                ++(vlSymsp->__Vcoverage[159]);
                                                            }(), 
                                                     ((1U 
                                                       == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                       ? 
                                                      ([&]() {
                                                                        ++(vlSymsp->__Vcoverage[139]);
                                                                    }(), 
                                                       (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                        << (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt)))
                                                       : 
                                                      ([&]() {
                                                                        ++(vlSymsp->__Vcoverage[158]);
                                                                    }(), 
                                                       ((5U 
                                                         == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                         ? 
                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[140]);
                                                                            }(), 
                                                         (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                          >> (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt)))
                                                         : 
                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[157]);
                                                                            }(), 
                                                         ((0xdU 
                                                           == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                           ? 
                                                          ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[141]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift)
                                                           : 
                                                          ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[156]);
                                                                                }(), 
                                                           ((0x1fU 
                                                             == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                             ? 
                                                            ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[142]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a)
                                                             : 
                                                            ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[155]);
                                                                                }(), 
                                                             ((0x10U 
                                                               == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                               ? 
                                                              ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[143]);
                                                                                }(), 
                                                               (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                == vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                               : 
                                                              ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[154]);
                                                                                }(), 
                                                               ((0x11U 
                                                                 == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                 ? 
                                                                ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[144]);
                                                                                }(), 
                                                                 (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                  != vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                 : 
                                                                ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[153]);
                                                                                }(), 
                                                                 ((0x14U 
                                                                   == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                   ? 
                                                                  ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[145]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than)
                                                                   : 
                                                                  ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[152]);
                                                                                }(), 
                                                                   ((0x15U 
                                                                     == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                     ? 
                                                                    ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[146]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal)
                                                                     : 
                                                                    ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[151]);
                                                                                }(), 
                                                                     ((0x16U 
                                                                       == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                       ? 
                                                                      ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[147]);
                                                                                }(), 
                                                                       (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                        < vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                       : 
                                                                      ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[150]);
                                                                                }(), 
                                                                       ((0x17U 
                                                                         == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                         ? 
                                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[148]);
                                                                                }(), 
                                                                         (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                          >= vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                         : 
                                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[149]);
                                                                                }(), 0U))))))))))))))))))))))))))))))))));
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
    vlSelfRef.id_ex_data_in[2U] = ((0x1e00U & vlSelfRef.id_ex_data_in[2U]) 
                                   | (0x1fffU & (((IData)(vlSelfRef.id_mem_wbe) 
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
