// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCoreTop.h for the primary calling header

#ifndef VERILATED_VCORETOP_CORETOP_H_
#define VERILATED_VCORETOP_CORETOP_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
class VCoreTop_DBusIf;
class VCoreTop_Ifu;


class VCoreTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCoreTop_CoreTop final : public VerilatedModule {
  public:
    // CELLS
    VCoreTop_Ifu* u_ifu;
    VCoreTop_DBusIf* __PVT__u_dmem__DOT__dbus;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*0:0*/ u_if_id_reg__DOT__clk;
        CData/*0:0*/ u_decoder__DOT__u_regfile__DOT__clk;
        CData/*0:0*/ u_ex_mem_reg__DOT__clk;
        CData/*0:0*/ u_dmem__DOT__dmem__DOT__clk;
        VL_IN8(start,0,0);
        CData/*0:0*/ stall;
        CData/*0:0*/ flush;
        CData/*0:0*/ if_valid;
        CData/*1:0*/ id_pc_sel;
        CData/*0:0*/ ex_branch_taken;
        CData/*0:0*/ id_valid;
        CData/*2:0*/ id_alu_op;
        CData/*1:0*/ id_operand_a;
        CData/*0:0*/ id_operand_b;
        CData/*2:0*/ id_extend_sel;
        CData/*0:0*/ id_reg_write;
        CData/*0:0*/ id_branch_op;
        CData/*0:0*/ id_mem_read;
        CData/*0:0*/ id_mem_write;
        CData/*0:0*/ id_mem_to_reg;
        CData/*6:0*/ id_opcode;
        CData/*6:0*/ id_funct7;
        CData/*2:0*/ id_funct3;
        CData/*4:0*/ id_rs1;
        CData/*4:0*/ id_rs2;
        CData/*4:0*/ id_rd;
        CData/*3:0*/ id_mem_wbe;
        CData/*0:0*/ wb_reg_write;
        CData/*4:0*/ wb_write_reg;
        CData/*0:0*/ mem_ctrl_out;
        CData/*0:0*/ dmem_gnt;
        CData/*0:0*/ dmem_rack;
        CData/*0:0*/ dmem_wack;
        CData/*0:0*/ dmem_err;
        CData/*0:0*/ flush_d;
        CData/*0:0*/ real_if_id_flush;
        CData/*0:0*/ u_if_id_reg__DOT__rst;
        CData/*0:0*/ u_if_id_reg__DOT__flush;
        CData/*0:0*/ u_if_id_reg__DOT__en;
        CData/*0:0*/ u_if_id_reg__DOT__ctrl_in;
        CData/*0:0*/ u_if_id_reg__DOT__ctrl_out;
        CData/*0:0*/ u_if_id_reg__DOT__ctrl_q;
        CData/*0:0*/ u_control_unit__DOT__clk;
        CData/*0:0*/ u_control_unit__DOT__rst;
        CData/*6:0*/ u_control_unit__DOT__opcode;
        CData/*2:0*/ u_control_unit__DOT__ALUOp;
        CData/*1:0*/ u_control_unit__DOT__operand_A;
        CData/*0:0*/ u_control_unit__DOT__operand_B;
        CData/*2:0*/ u_control_unit__DOT__extend_sel;
        CData/*0:0*/ u_control_unit__DOT__regWrite;
        CData/*0:0*/ u_control_unit__DOT__branch_op;
        CData/*0:0*/ u_control_unit__DOT__memRead;
        CData/*0:0*/ u_control_unit__DOT__memWrite;
        CData/*0:0*/ u_control_unit__DOT__memtoReg;
        CData/*1:0*/ u_control_unit__DOT__next_PC_sel;
        CData/*0:0*/ u_decoder__DOT__clk;
        CData/*0:0*/ u_decoder__DOT__rst;
        CData/*2:0*/ u_decoder__DOT__extend_sel;
        CData/*0:0*/ u_decoder__DOT__reg_write;
        CData/*4:0*/ u_decoder__DOT__write_reg;
        CData/*6:0*/ u_decoder__DOT__opcode;
        CData/*6:0*/ u_decoder__DOT__funct7;
    };
    struct {
        CData/*2:0*/ u_decoder__DOT__funct3;
        CData/*4:0*/ u_decoder__DOT__rs1;
        CData/*4:0*/ u_decoder__DOT__rs2;
        CData/*4:0*/ u_decoder__DOT__rd;
        CData/*3:0*/ u_decoder__DOT__mem_wbe;
        CData/*6:0*/ u_decoder__DOT__s_imm_msb;
        CData/*4:0*/ u_decoder__DOT__s_imm_lsb;
        CData/*0:0*/ u_decoder__DOT__rs1_data_bypass;
        CData/*0:0*/ u_decoder__DOT__rs2_data_bypass;
        CData/*0:0*/ u_decoder__DOT__u_regfile__DOT__rst;
        CData/*0:0*/ u_decoder__DOT__u_regfile__DOT__wen;
        CData/*4:0*/ u_decoder__DOT__u_regfile__DOT__waddr;
        CData/*4:0*/ u_decoder__DOT__u_regfile__DOT__raddr1;
        CData/*4:0*/ u_decoder__DOT__u_regfile__DOT__raddr2;
        CData/*0:0*/ u_execute__DOT__clk;
        CData/*0:0*/ u_execute__DOT__rst;
        CData/*0:0*/ u_execute__DOT__stall;
        CData/*2:0*/ u_execute__DOT__ALU_Operation;
        CData/*6:0*/ u_execute__DOT__funct7;
        CData/*2:0*/ u_execute__DOT__funct3;
        CData/*1:0*/ u_execute__DOT__ALU_ASrc;
        CData/*0:0*/ u_execute__DOT__ALU_BSrc;
        CData/*0:0*/ u_execute__DOT__branch_op;
        CData/*0:0*/ u_execute__DOT__branch_taken;
        CData/*5:0*/ u_execute__DOT__ALU_Control;
        CData/*0:0*/ u_execute__DOT__alu_cmp_out;
        CData/*5:0*/ u_execute__DOT__u_alu__DOT__ALU_Control;
        CData/*0:0*/ u_execute__DOT__u_alu__DOT__cmp_out;
        CData/*4:0*/ u_execute__DOT__u_alu__DOT__shamt;
        CData/*0:0*/ u_ex_mem_reg__DOT__rst;
        CData/*0:0*/ u_ex_mem_reg__DOT__flush;
        CData/*0:0*/ u_ex_mem_reg__DOT__en;
        CData/*0:0*/ u_ex_mem_reg__DOT__ctrl_in;
        CData/*0:0*/ u_ex_mem_reg__DOT__ctrl_out;
        CData/*0:0*/ u_ex_mem_reg__DOT__ctrl_q;
        CData/*0:0*/ u_dmem__DOT__clk;
        CData/*0:0*/ u_dmem__DOT__rst;
        CData/*0:0*/ u_dmem__DOT__read;
        CData/*0:0*/ u_dmem__DOT__write;
        CData/*3:0*/ u_dmem__DOT__wbe;
        CData/*0:0*/ u_dmem__DOT__gnt;
        CData/*0:0*/ u_dmem__DOT__rack;
        CData/*0:0*/ u_dmem__DOT__wack;
        CData/*0:0*/ u_dmem__DOT__err;
        CData/*0:0*/ u_dmem__DOT__dmem__DOT__rst;
        CData/*0:0*/ u_dmem__DOT__dmem__DOT__gnt;
        CData/*0:0*/ u_dmem__DOT__dmem__DOT__err;
        CData/*0:0*/ __VdlySet__u_dmem__DOT__dmem__DOT__mem__v0;
        SData/*11:0*/ u_decoder__DOT__i_imm_orig;
        SData/*11:0*/ u_decoder__DOT__s_imm_orig;
        SData/*12:0*/ u_decoder__DOT__sb_imm_orig;
        SData/*11:0*/ u_dmem__DOT__dmem__DOT__mem_addr;
        VL_IN(program_address,31,0);
        IData/*31:0*/ if_instruction;
        IData/*31:0*/ if_pc;
        IData/*31:0*/ id_branch_target;
        IData/*31:0*/ id_jal_target;
        IData/*31:0*/ ex_jalr_target;
        IData/*31:0*/ id_instruction;
        IData/*31:0*/ id_pc;
        IData/*31:0*/ id_instruction_real;
        IData/*31:0*/ id_extend_imm;
        IData/*31:0*/ id_rs1_data;
        IData/*31:0*/ id_rs2_data;
    };
    struct {
        IData/*31:0*/ ex_alu_result;
        IData/*31:0*/ wb_write_data;
        IData/*31:0*/ mem_rdata;
        IData/*31:0*/ cycle_cnt;
        IData/*31:0*/ u_decoder__DOT__instruction;
        IData/*31:0*/ u_decoder__DOT__PC;
        IData/*31:0*/ u_decoder__DOT__write_data;
        IData/*31:0*/ u_decoder__DOT__extend_imm;
        IData/*31:0*/ u_decoder__DOT__rs1_data;
        IData/*31:0*/ u_decoder__DOT__rs2_data;
        IData/*31:0*/ u_decoder__DOT__branch_target;
        IData/*31:0*/ u_decoder__DOT__JAL_target;
        IData/*19:0*/ u_decoder__DOT__u_imm;
        IData/*31:0*/ u_decoder__DOT__i_imm_32;
        IData/*31:0*/ u_decoder__DOT__u_imm_32;
        IData/*31:0*/ u_decoder__DOT__s_imm_32;
        IData/*31:0*/ u_decoder__DOT__sb_imm_32;
        IData/*19:0*/ u_decoder__DOT__uj_imm;
        IData/*31:0*/ u_decoder__DOT__uj_imm_32;
        IData/*31:0*/ u_decoder__DOT__rs1_data_decode;
        IData/*31:0*/ u_decoder__DOT__rs2_data_decode;
        IData/*31:0*/ u_decoder__DOT__u_regfile__DOT__wdata;
        IData/*31:0*/ u_decoder__DOT__u_regfile__DOT__rdata1;
        IData/*31:0*/ u_decoder__DOT__u_regfile__DOT__rdata2;
        IData/*31:0*/ u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ u_execute__DOT__PC;
        IData/*31:0*/ u_execute__DOT__regRead_1;
        IData/*31:0*/ u_execute__DOT__regRead_2;
        IData/*31:0*/ u_execute__DOT__extend;
        IData/*31:0*/ u_execute__DOT__ALU_result;
        IData/*31:0*/ u_execute__DOT__JALR_target;
        IData/*31:0*/ u_execute__DOT__alu_in_a;
        IData/*31:0*/ u_execute__DOT__alu_in_b;
        IData/*31:0*/ u_execute__DOT__u_alu__DOT__alu_in_a;
        IData/*31:0*/ u_execute__DOT__u_alu__DOT__alu_in_b;
        IData/*31:0*/ u_execute__DOT__u_alu__DOT__ALU_result;
        IData/*31:0*/ u_execute__DOT__u_alu__DOT__arithmetic_right_shift;
        IData/*31:0*/ u_execute__DOT__u_alu__DOT__signed_less_than;
        IData/*31:0*/ u_execute__DOT__u_alu__DOT__unsigned_less_than;
        IData/*31:0*/ u_execute__DOT__u_alu__DOT__signed_greater_than_equal;
        VlWide<3>/*76:0*/ u_ex_mem_reg__DOT__data_in;
        VlWide<3>/*76:0*/ u_ex_mem_reg__DOT__data_out;
        VlWide<3>/*76:0*/ u_ex_mem_reg__DOT__data_q;
        IData/*31:0*/ u_dmem__DOT__addr;
        IData/*31:0*/ u_dmem__DOT__wdata;
        IData/*31:0*/ u_dmem__DOT__rdata;
        IData/*31:0*/ u_dmem__DOT__dmem__DOT__write_data;
        IData/*31:0*/ u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ __Vdly__cycle_cnt;
        VlWide<3>/*76:0*/ id_ex_data_in;
        VlWide<3>/*76:0*/ mem_data_out;
        QData/*63:0*/ u_if_id_reg__DOT__data_in;
        QData/*63:0*/ u_if_id_reg__DOT__data_out;
        QData/*63:0*/ u_if_id_reg__DOT__data_q;
        VlUnpacked<IData/*31:0*/, 32> u_decoder__DOT__u_regfile__DOT__regs;
        VlUnpacked<IData/*31:0*/, 4096> u_dmem__DOT__dmem__DOT__mem;
    };

    // INTERNAL VARIABLES
    VCoreTop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*0:0*/ u_if_id_reg__DOT__RESET_VALUE = 0U;
    static constexpr CData/*6:0*/ u_control_unit__DOT__R_TYPE = 0x33U;
    static constexpr CData/*6:0*/ u_control_unit__DOT__I_TYPE = 0x13U;
    static constexpr CData/*6:0*/ u_control_unit__DOT__AUIPC = 0x17U;
    static constexpr CData/*6:0*/ u_control_unit__DOT__LUI = 0x37U;
    static constexpr CData/*6:0*/ u_control_unit__DOT__STORE = 0x23U;
    static constexpr CData/*6:0*/ u_control_unit__DOT__LOAD = 3U;
    static constexpr CData/*6:0*/ u_control_unit__DOT__BRANCH = 0x63U;
    static constexpr CData/*6:0*/ u_control_unit__DOT__JALR = 0x67U;
    static constexpr CData/*6:0*/ u_control_unit__DOT__JAL = 0x6fU;
    static constexpr CData/*6:0*/ u_control_unit__DOT__FENCES = 0x0fU;
    static constexpr CData/*6:0*/ u_control_unit__DOT__SYSCALL = 0x73U;
    static constexpr CData/*0:0*/ u_decoder__DOT__u_regfile__DOT__ZERO_X0 = 1U;
    static constexpr CData/*0:0*/ u_ex_mem_reg__DOT__RESET_VALUE = 0U;
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ NOP = 0x00000013U;
    static constexpr IData/*31:0*/ u_if_id_reg__DOT__CTRL_WIDTH = 1U;
    static constexpr IData/*31:0*/ u_if_id_reg__DOT__DATA_WIDTH = 0x00000040U;
    static constexpr IData/*31:0*/ u_control_unit__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_decoder__DOT__ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_decoder__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_decoder__DOT__u_regfile__DOT__REG_DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_decoder__DOT__u_regfile__DOT__REG_SEL_WIDTH = 5U;
    static constexpr IData/*31:0*/ u_decoder__DOT__u_regfile__DOT__REG_COUNT = 0x00000020U;
    static constexpr IData/*31:0*/ u_execute__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_execute__DOT__ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_execute__DOT__u_alu__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_execute__DOT__u_alu__DOT__SHIFT_WIDTH = 5U;
    static constexpr IData/*31:0*/ u_ex_mem_reg__DOT__CTRL_WIDTH = 1U;
    static constexpr IData/*31:0*/ u_ex_mem_reg__DOT__DATA_WIDTH = 0x0000004dU;
    static constexpr IData/*31:0*/ u_dmem__DOT__ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_dmem__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_dmem__DOT__SIZE_BYTES = 0x00004000U;
    static constexpr IData/*31:0*/ u_dmem__DOT__BYTES_PER_WORD = 4U;
    static constexpr IData/*31:0*/ u_dmem__DOT__dmem__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ u_dmem__DOT__dmem__DOT__SIZE_BYTES = 0x00004000U;
    static constexpr IData/*31:0*/ u_dmem__DOT__dmem__DOT__BYTES_PER_WORD = 4U;
    static constexpr IData/*31:0*/ u_dmem__DOT__dmem__DOT__MEM_DEPTH = 0x00001000U;
    static constexpr IData/*31:0*/ u_dmem__DOT__dmem__DOT__MEM_ADDR_WIDTH = 0x0000000cU;
    static constexpr IData/*31:0*/ u_dmem__DOT__dmem__DOT__BYTE_OFFSET = 2U;
    static const std::string IMEM_INIT_FILE;
    static const std::string DMEM_INIT_FILE;
    static const std::string u_dmem__DOT__INIT_FILE;
    static const std::string u_dmem__DOT__dmem__DOT__INIT_FILE;

    // CONSTRUCTORS
    VCoreTop_CoreTop(VCoreTop__Syms* symsp, const char* v__name);
    ~VCoreTop_CoreTop();
    VL_UNCOPYABLE(VCoreTop_CoreTop);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
};


#endif  // guard
