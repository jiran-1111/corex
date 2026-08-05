// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VCoreTop__pch.h"
#include "VCoreTop.h"
#include "VCoreTop___024root.h"
#include "VCoreTop_CoreTop.h"
#include "VCoreTop_Ifu.h"
#include "VCoreTop_IMemTop.h"
#include "VCoreTop_DBusIf.h"
#include "VCoreTop_IMem.h"
#include "VCoreTop_IBusIf.h"

// FUNCTIONS
VCoreTop__Syms::~VCoreTop__Syms()
{
}

VCoreTop__Syms::VCoreTop__Syms(VerilatedContext* contextp, const char* namep, VCoreTop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__CoreTop{this, Verilated::catName(namep, "CoreTop")}
    , TOP__CoreTop__u_dmem__DOT__dbus{this, Verilated::catName(namep, "CoreTop.u_dmem.dbus")}
    , TOP__CoreTop__u_ifu{this, Verilated::catName(namep, "CoreTop.u_ifu")}
    , TOP__CoreTop__u_ifu__IMem{this, Verilated::catName(namep, "CoreTop.u_ifu.IMem")}
    , TOP__CoreTop__u_ifu__IMem__ibus{this, Verilated::catName(namep, "CoreTop.u_ifu.IMem.ibus")}
    , TOP__CoreTop__u_ifu__IMem__imem{this, Verilated::catName(namep, "CoreTop.u_ifu.IMem.imem")}
{
        // Check resources
        Verilated::stackCheck(73);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.CoreTop = &TOP__CoreTop;
    TOP__CoreTop.__PVT__u_dmem__DOT__dbus = &TOP__CoreTop__u_dmem__DOT__dbus;
    TOP__CoreTop.u_ifu = &TOP__CoreTop__u_ifu;
    TOP__CoreTop__u_ifu.IMem = &TOP__CoreTop__u_ifu__IMem;
    TOP__CoreTop__u_ifu__IMem.__PVT__ibus = &TOP__CoreTop__u_ifu__IMem__ibus;
    TOP__CoreTop__u_ifu__IMem.imem = &TOP__CoreTop__u_ifu__IMem__imem;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__CoreTop.__Vconfigure(true);
    TOP__CoreTop__u_dmem__DOT__dbus.__Vconfigure(true);
    TOP__CoreTop__u_ifu.__Vconfigure(true);
    TOP__CoreTop__u_ifu__IMem.__Vconfigure(true);
    TOP__CoreTop__u_ifu__IMem__ibus.__Vconfigure(true);
    TOP__CoreTop__u_ifu__IMem__imem.__Vconfigure(true);
    // Setup scopes
    __Vscope_CoreTop.configure(this, name(), "CoreTop", "CoreTop", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_control_unit.configure(this, name(), "CoreTop.u_control_unit", "u_control_unit", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_decoder.configure(this, name(), "CoreTop.u_decoder", "u_decoder", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_decoder__u_regfile.configure(this, name(), "CoreTop.u_decoder.u_regfile", "u_regfile", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_decoder__u_regfile__unnamedblk1.configure(this, name(), "CoreTop.u_decoder.u_regfile.unnamedblk1", "unnamedblk1", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_dmem.configure(this, name(), "CoreTop.u_dmem", "u_dmem", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_dmem__dbus.configure(this, name(), "CoreTop.u_dmem.dbus", "dbus", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_dmem__dmem.configure(this, name(), "CoreTop.u_dmem.dmem", "dmem", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_dmem__dmem__unnamedblk1.configure(this, name(), "CoreTop.u_dmem.dmem.unnamedblk1", "unnamedblk1", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_dmem__dmem__unnamedblk2.configure(this, name(), "CoreTop.u_dmem.dmem.unnamedblk2", "unnamedblk2", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_ex_mem_reg.configure(this, name(), "CoreTop.u_ex_mem_reg", "u_ex_mem_reg", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_execute.configure(this, name(), "CoreTop.u_execute", "u_execute", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_execute__u_alu.configure(this, name(), "CoreTop.u_execute.u_alu", "u_alu", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_if_id_reg.configure(this, name(), "CoreTop.u_if_id_reg", "u_if_id_reg", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_ifu.configure(this, name(), "CoreTop.u_ifu", "u_ifu", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_ifu__IMem.configure(this, name(), "CoreTop.u_ifu.IMem", "IMem", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_ifu__IMem__ibus.configure(this, name(), "CoreTop.u_ifu.IMem.ibus", "ibus", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_CoreTop__u_ifu__IMem__imem.configure(this, name(), "CoreTop.u_ifu.IMem.imem", "imem", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_CoreTop.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"DMEM_INIT_FILE", const_cast<void*>(static_cast<const void*>(TOP__CoreTop.DMEM_INIT_FILE.c_str())), true, VLVT_STRING,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"IMEM_INIT_FILE", const_cast<void*>(static_cast<const void*>(TOP__CoreTop.IMEM_INIT_FILE.c_str())), true, VLVT_STRING,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"NOP", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.NOP))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"clk", &(TOP__CoreTop.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"cycle_cnt", &(TOP__CoreTop.cycle_cnt), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"dmem_err", &(TOP__CoreTop.dmem_err), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"dmem_gnt", &(TOP__CoreTop.dmem_gnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"dmem_rack", &(TOP__CoreTop.dmem_rack), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"dmem_wack", &(TOP__CoreTop.dmem_wack), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"ex_alu_result", &(TOP__CoreTop.ex_alu_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"ex_branch_taken", &(TOP__CoreTop.ex_branch_taken), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"ex_jalr_target", &(TOP__CoreTop.ex_jalr_target), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"flush", &(TOP__CoreTop.flush), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"flush_d", &(TOP__CoreTop.flush_d), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_alu_op", &(TOP__CoreTop.id_alu_op), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_branch_op", &(TOP__CoreTop.id_branch_op), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_branch_target", &(TOP__CoreTop.id_branch_target), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_ex_data_in", &(TOP__CoreTop.id_ex_data_in), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,76,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_extend_imm", &(TOP__CoreTop.id_extend_imm), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_extend_sel", &(TOP__CoreTop.id_extend_sel), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_funct3", &(TOP__CoreTop.id_funct3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_funct7", &(TOP__CoreTop.id_funct7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_instruction", &(TOP__CoreTop.id_instruction), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_instruction_real", &(TOP__CoreTop.id_instruction_real), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_jal_target", &(TOP__CoreTop.id_jal_target), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_mem_read", &(TOP__CoreTop.id_mem_read), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_mem_to_reg", &(TOP__CoreTop.id_mem_to_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_mem_wbe", &(TOP__CoreTop.id_mem_wbe), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_mem_write", &(TOP__CoreTop.id_mem_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_opcode", &(TOP__CoreTop.id_opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_operand_a", &(TOP__CoreTop.id_operand_a), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_operand_b", &(TOP__CoreTop.id_operand_b), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_pc", &(TOP__CoreTop.id_pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_pc_sel", &(TOP__CoreTop.id_pc_sel), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_rd", &(TOP__CoreTop.id_rd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_reg_write", &(TOP__CoreTop.id_reg_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_rs1", &(TOP__CoreTop.id_rs1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_rs1_data", &(TOP__CoreTop.id_rs1_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_rs2", &(TOP__CoreTop.id_rs2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_rs2_data", &(TOP__CoreTop.id_rs2_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"id_valid", &(TOP__CoreTop.id_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"if_instruction", &(TOP__CoreTop.if_instruction), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"if_pc", &(TOP__CoreTop.if_pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"if_valid", &(TOP__CoreTop.if_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"mem_ctrl_out", &(TOP__CoreTop.mem_ctrl_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"mem_data_out", &(TOP__CoreTop.mem_data_out), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,76,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"mem_rdata", &(TOP__CoreTop.mem_rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"program_address", &(TOP__CoreTop.program_address), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"real_if_id_flush", &(TOP__CoreTop.real_if_id_flush), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"rst", &(TOP__CoreTop.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"stall", &(TOP__CoreTop.stall), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"start", &(TOP__CoreTop.start), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"wb_reg_write", &(TOP__CoreTop.wb_reg_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"wb_write_data", &(TOP__CoreTop.wb_write_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop.varInsert(__Vfinal,"wb_write_reg", &(TOP__CoreTop.wb_write_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"ALUOp", &(TOP__CoreTop.u_control_unit__DOT__ALUOp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"AUIPC", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__AUIPC))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"BRANCH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__BRANCH))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"FENCES", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__FENCES))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"I_TYPE", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__I_TYPE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"JAL", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__JAL))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"JALR", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__JALR))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"LOAD", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__LOAD))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"LUI", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__LUI))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"R_TYPE", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__R_TYPE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"STORE", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__STORE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"SYSCALL", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_control_unit__DOT__SYSCALL))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"branch_op", &(TOP__CoreTop.u_control_unit__DOT__branch_op), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"clk", &(TOP__CoreTop.u_control_unit__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"extend_sel", &(TOP__CoreTop.u_control_unit__DOT__extend_sel), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"memRead", &(TOP__CoreTop.u_control_unit__DOT__memRead), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"memWrite", &(TOP__CoreTop.u_control_unit__DOT__memWrite), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"memtoReg", &(TOP__CoreTop.u_control_unit__DOT__memtoReg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"next_PC_sel", &(TOP__CoreTop.u_control_unit__DOT__next_PC_sel), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"opcode", &(TOP__CoreTop.u_control_unit__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"operand_A", &(TOP__CoreTop.u_control_unit__DOT__operand_A), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"operand_B", &(TOP__CoreTop.u_control_unit__DOT__operand_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"regWrite", &(TOP__CoreTop.u_control_unit__DOT__regWrite), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_control_unit.varInsert(__Vfinal,"rst", &(TOP__CoreTop.u_control_unit__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_decoder__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_decoder__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"JAL_target", &(TOP__CoreTop.u_decoder__DOT__JAL_target), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"PC", &(TOP__CoreTop.u_decoder__DOT__PC), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"branch_target", &(TOP__CoreTop.u_decoder__DOT__branch_target), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"clk", &(TOP__CoreTop.u_decoder__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"extend_imm", &(TOP__CoreTop.u_decoder__DOT__extend_imm), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"extend_sel", &(TOP__CoreTop.u_decoder__DOT__extend_sel), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"funct3", &(TOP__CoreTop.u_decoder__DOT__funct3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"funct7", &(TOP__CoreTop.u_decoder__DOT__funct7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"i_imm_32", &(TOP__CoreTop.u_decoder__DOT__i_imm_32), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"i_imm_orig", &(TOP__CoreTop.u_decoder__DOT__i_imm_orig), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,11,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"instruction", &(TOP__CoreTop.u_decoder__DOT__instruction), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"mem_wbe", &(TOP__CoreTop.u_decoder__DOT__mem_wbe), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"opcode", &(TOP__CoreTop.u_decoder__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rd", &(TOP__CoreTop.u_decoder__DOT__rd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"reg_write", &(TOP__CoreTop.u_decoder__DOT__reg_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rs1", &(TOP__CoreTop.u_decoder__DOT__rs1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rs1_data", &(TOP__CoreTop.u_decoder__DOT__rs1_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rs1_data_bypass", &(TOP__CoreTop.u_decoder__DOT__rs1_data_bypass), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rs1_data_decode", &(TOP__CoreTop.u_decoder__DOT__rs1_data_decode), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rs2", &(TOP__CoreTop.u_decoder__DOT__rs2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rs2_data", &(TOP__CoreTop.u_decoder__DOT__rs2_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rs2_data_bypass", &(TOP__CoreTop.u_decoder__DOT__rs2_data_bypass), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rs2_data_decode", &(TOP__CoreTop.u_decoder__DOT__rs2_data_decode), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"rst", &(TOP__CoreTop.u_decoder__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"s_imm_32", &(TOP__CoreTop.u_decoder__DOT__s_imm_32), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"s_imm_lsb", &(TOP__CoreTop.u_decoder__DOT__s_imm_lsb), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"s_imm_msb", &(TOP__CoreTop.u_decoder__DOT__s_imm_msb), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"s_imm_orig", &(TOP__CoreTop.u_decoder__DOT__s_imm_orig), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,11,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"sb_imm_32", &(TOP__CoreTop.u_decoder__DOT__sb_imm_32), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"sb_imm_orig", &(TOP__CoreTop.u_decoder__DOT__sb_imm_orig), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,12,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"u_imm", &(TOP__CoreTop.u_decoder__DOT__u_imm), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,19,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"u_imm_32", &(TOP__CoreTop.u_decoder__DOT__u_imm_32), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"uj_imm", &(TOP__CoreTop.u_decoder__DOT__uj_imm), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,19,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"uj_imm_32", &(TOP__CoreTop.u_decoder__DOT__uj_imm_32), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"write_data", &(TOP__CoreTop.u_decoder__DOT__write_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder.varInsert(__Vfinal,"write_reg", &(TOP__CoreTop.u_decoder__DOT__write_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"REG_COUNT", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__REG_COUNT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"REG_DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__REG_DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"REG_SEL_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__REG_SEL_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"ZERO_X0", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__ZERO_X0))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"clk", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"raddr1", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__raddr1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"raddr2", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__raddr2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"rdata1", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__rdata1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"rdata2", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__rdata2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"regs", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__regs), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,31 ,31,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"rst", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"waddr", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__waddr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"wdata", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_decoder__u_regfile.varInsert(__Vfinal,"wen", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__wen), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_decoder__u_regfile__unnamedblk1.varInsert(__Vfinal,"i", &(TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"BYTES_PER_WORD", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__BYTES_PER_WORD))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"INIT_FILE", const_cast<void*>(static_cast<const void*>(TOP__CoreTop.u_dmem__DOT__INIT_FILE.c_str())), true, VLVT_STRING,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__SIZE_BYTES))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"addr", &(TOP__CoreTop.u_dmem__DOT__addr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"clk", &(TOP__CoreTop.u_dmem__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"err", &(TOP__CoreTop.u_dmem__DOT__err), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"gnt", &(TOP__CoreTop.u_dmem__DOT__gnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"rack", &(TOP__CoreTop.u_dmem__DOT__rack), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"rdata", &(TOP__CoreTop.u_dmem__DOT__rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"read", &(TOP__CoreTop.u_dmem__DOT__read), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"rst", &(TOP__CoreTop.u_dmem__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"wack", &(TOP__CoreTop.u_dmem__DOT__wack), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"wbe", &(TOP__CoreTop.u_dmem__DOT__wbe), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"wdata", &(TOP__CoreTop.u_dmem__DOT__wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem.varInsert(__Vfinal,"write", &(TOP__CoreTop.u_dmem__DOT__write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_dmem__DOT__dbus.ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"BYTES_PER_WORD", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_dmem__DOT__dbus.BYTES_PER_WORD))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_dmem__DOT__dbus.DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"addr", &(TOP__CoreTop__u_dmem__DOT__dbus.addr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"err", &(TOP__CoreTop__u_dmem__DOT__dbus.err), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"gnt", &(TOP__CoreTop__u_dmem__DOT__dbus.gnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"rack", &(TOP__CoreTop__u_dmem__DOT__dbus.rack), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"rdata", &(TOP__CoreTop__u_dmem__DOT__dbus.rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"read", &(TOP__CoreTop__u_dmem__DOT__dbus.read), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"wack", &(TOP__CoreTop__u_dmem__DOT__dbus.wack), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"wbe", &(TOP__CoreTop__u_dmem__DOT__dbus.wbe), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"wdata", &(TOP__CoreTop__u_dmem__DOT__dbus.wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dbus.varInsert(__Vfinal,"write", &(TOP__CoreTop__u_dmem__DOT__dbus.write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"BYTES_PER_WORD", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__dmem__DOT__BYTES_PER_WORD))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"BYTE_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__dmem__DOT__BYTE_OFFSET))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__dmem__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"INIT_FILE", const_cast<void*>(static_cast<const void*>(TOP__CoreTop.u_dmem__DOT__dmem__DOT__INIT_FILE.c_str())), true, VLVT_STRING,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"MEM_ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__dmem__DOT__MEM_ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"MEM_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__dmem__DOT__MEM_DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_dmem__DOT__dmem__DOT__SIZE_BYTES))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"clk", &(TOP__CoreTop.u_dmem__DOT__dmem__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"err", &(TOP__CoreTop.u_dmem__DOT__dmem__DOT__err), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"gnt", &(TOP__CoreTop.u_dmem__DOT__dmem__DOT__gnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"mem", &(TOP__CoreTop.u_dmem__DOT__dmem__DOT__mem), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,4095 ,31,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"mem_addr", &(TOP__CoreTop.u_dmem__DOT__dmem__DOT__mem_addr), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,11,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"rst", &(TOP__CoreTop.u_dmem__DOT__dmem__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_dmem__dmem.varInsert(__Vfinal,"write_data", &(TOP__CoreTop.u_dmem__DOT__dmem__DOT__write_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dmem__unnamedblk1.varInsert(__Vfinal,"i", &(TOP__CoreTop.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_dmem__dmem__unnamedblk2.varInsert(__Vfinal,"i", &(TOP__CoreTop.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"CTRL_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_ex_mem_reg__DOT__CTRL_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_ex_mem_reg__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"RESET_VALUE", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_ex_mem_reg__DOT__RESET_VALUE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"clk", &(TOP__CoreTop.u_ex_mem_reg__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"ctrl_in", &(TOP__CoreTop.u_ex_mem_reg__DOT__ctrl_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"ctrl_out", &(TOP__CoreTop.u_ex_mem_reg__DOT__ctrl_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"ctrl_q", &(TOP__CoreTop.u_ex_mem_reg__DOT__ctrl_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"data_in", &(TOP__CoreTop.u_ex_mem_reg__DOT__data_in), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,76,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"data_out", &(TOP__CoreTop.u_ex_mem_reg__DOT__data_out), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,76,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"data_q", &(TOP__CoreTop.u_ex_mem_reg__DOT__data_q), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,76,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"en", &(TOP__CoreTop.u_ex_mem_reg__DOT__en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"flush", &(TOP__CoreTop.u_ex_mem_reg__DOT__flush), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ex_mem_reg.varInsert(__Vfinal,"rst", &(TOP__CoreTop.u_ex_mem_reg__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_execute__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"ALU_ASrc", &(TOP__CoreTop.u_execute__DOT__ALU_ASrc), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"ALU_BSrc", &(TOP__CoreTop.u_execute__DOT__ALU_BSrc), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"ALU_Control", &(TOP__CoreTop.u_execute__DOT__ALU_Control), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,5,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"ALU_Operation", &(TOP__CoreTop.u_execute__DOT__ALU_Operation), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"ALU_result", &(TOP__CoreTop.u_execute__DOT__ALU_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_execute__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"JALR_target", &(TOP__CoreTop.u_execute__DOT__JALR_target), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"PC", &(TOP__CoreTop.u_execute__DOT__PC), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"alu_cmp_out", &(TOP__CoreTop.u_execute__DOT__alu_cmp_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"alu_in_a", &(TOP__CoreTop.u_execute__DOT__alu_in_a), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"alu_in_b", &(TOP__CoreTop.u_execute__DOT__alu_in_b), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"branch_op", &(TOP__CoreTop.u_execute__DOT__branch_op), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"branch_taken", &(TOP__CoreTop.u_execute__DOT__branch_taken), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"clk", &(TOP__CoreTop.u_execute__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"extend", &(TOP__CoreTop.u_execute__DOT__extend), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"funct3", &(TOP__CoreTop.u_execute__DOT__funct3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"funct7", &(TOP__CoreTop.u_execute__DOT__funct7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"regRead_1", &(TOP__CoreTop.u_execute__DOT__regRead_1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"regRead_2", &(TOP__CoreTop.u_execute__DOT__regRead_2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"rst", &(TOP__CoreTop.u_execute__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_execute.varInsert(__Vfinal,"stall", &(TOP__CoreTop.u_execute__DOT__stall), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"ALU_Control", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__ALU_Control), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,5,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"ALU_result", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__ALU_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_execute__DOT__u_alu__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"SHIFT_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_execute__DOT__u_alu__DOT__SHIFT_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"alu_in_a", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__alu_in_a), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"alu_in_b", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__alu_in_b), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"arithmetic_right_shift", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__arithmetic_right_shift), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"cmp_out", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__cmp_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"shamt", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__shamt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"signed_greater_than_equal", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__signed_greater_than_equal), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"signed_less_than", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__signed_less_than), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_execute__u_alu.varInsert(__Vfinal,"unsigned_less_than", &(TOP__CoreTop.u_execute__DOT__u_alu__DOT__unsigned_less_than), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"CTRL_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_if_id_reg__DOT__CTRL_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_if_id_reg__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"RESET_VALUE", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop.u_if_id_reg__DOT__RESET_VALUE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"clk", &(TOP__CoreTop.u_if_id_reg__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"ctrl_in", &(TOP__CoreTop.u_if_id_reg__DOT__ctrl_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"ctrl_out", &(TOP__CoreTop.u_if_id_reg__DOT__ctrl_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"ctrl_q", &(TOP__CoreTop.u_if_id_reg__DOT__ctrl_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"data_in", &(TOP__CoreTop.u_if_id_reg__DOT__data_in), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"data_out", &(TOP__CoreTop.u_if_id_reg__DOT__data_out), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"data_q", &(TOP__CoreTop.u_if_id_reg__DOT__data_q), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"en", &(TOP__CoreTop.u_if_id_reg__DOT__en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"flush", &(TOP__CoreTop.u_if_id_reg__DOT__flush), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_if_id_reg.varInsert(__Vfinal,"rst", &(TOP__CoreTop.u_if_id_reg__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu.ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu.DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"JALR_target", &(TOP__CoreTop__u_ifu.JALR_target), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"JAL_target", &(TOP__CoreTop__u_ifu.JAL_target), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"PC_plus4", &(TOP__CoreTop__u_ifu.PC_plus4), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"PC_reg", &(TOP__CoreTop__u_ifu.PC_reg), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"branch_taken", &(TOP__CoreTop__u_ifu.branch_taken), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"branch_target", &(TOP__CoreTop__u_ifu.branch_target), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"clk", &(TOP__CoreTop__u_ifu.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"fetch", &(TOP__CoreTop__u_ifu.fetch), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"imem_err", &(TOP__CoreTop__u_ifu.imem_err), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"imem_gnt", &(TOP__CoreTop__u_ifu.imem_gnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"inst_PC", &(TOP__CoreTop__u_ifu.inst_PC), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"inst_PC_reg", &(TOP__CoreTop__u_ifu.inst_PC_reg), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"instruction", &(TOP__CoreTop__u_ifu.instruction), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"jump_or_branch_taken", &(TOP__CoreTop__u_ifu.jump_or_branch_taken), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"next_PC", &(TOP__CoreTop__u_ifu.next_PC), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"pc_sel_execute", &(TOP__CoreTop__u_ifu.pc_sel_execute), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"program_address", &(TOP__CoreTop__u_ifu.program_address), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"rst", &(TOP__CoreTop__u_ifu.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"stall", &(TOP__CoreTop__u_ifu.stall), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"start", &(TOP__CoreTop__u_ifu.start), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu.varInsert(__Vfinal,"valid", &(TOP__CoreTop__u_ifu.valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem.ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem.DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem.SIZE_BYTES))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"ack", &(TOP__CoreTop__u_ifu__IMem.ack), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"addr", &(TOP__CoreTop__u_ifu__IMem.addr), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"clk", &(TOP__CoreTop__u_ifu__IMem.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"err", &(TOP__CoreTop__u_ifu__IMem.err), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"gnt", &(TOP__CoreTop__u_ifu__IMem.gnt), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"rdata", &(TOP__CoreTop__u_ifu__IMem.rdata), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"req", &(TOP__CoreTop__u_ifu__IMem.req), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem.varInsert(__Vfinal,"rst", &(TOP__CoreTop__u_ifu__IMem.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem__ibus.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem__ibus.ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__ibus.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem__ibus.DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__ibus.varInsert(__Vfinal,"ack", &(TOP__CoreTop__u_ifu__IMem__ibus.ack), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem__ibus.varInsert(__Vfinal,"addr", &(TOP__CoreTop__u_ifu__IMem__ibus.addr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__ibus.varInsert(__Vfinal,"err", &(TOP__CoreTop__u_ifu__IMem__ibus.err), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem__ibus.varInsert(__Vfinal,"gnt", &(TOP__CoreTop__u_ifu__IMem__ibus.gnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem__ibus.varInsert(__Vfinal,"rdata", &(TOP__CoreTop__u_ifu__IMem__ibus.rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__ibus.varInsert(__Vfinal,"req", &(TOP__CoreTop__u_ifu__IMem__ibus.req), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"BYTES_PER_WORD", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem__imem.BYTES_PER_WORD))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"BYTE_OFFSET", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem__imem.BYTE_OFFSET))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem__imem.DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"MEM_ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem__imem.MEM_ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"MEM_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem__imem.MEM_DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__CoreTop__u_ifu__IMem__imem.SIZE_BYTES))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"clk", &(TOP__CoreTop__u_ifu__IMem__imem.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"err", &(TOP__CoreTop__u_ifu__IMem__imem.err), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"gnt", &(TOP__CoreTop__u_ifu__IMem__imem.gnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"mem", &(TOP__CoreTop__u_ifu__IMem__imem.mem), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,4095 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"mem_addr", &(TOP__CoreTop__u_ifu__IMem__imem.mem_addr), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,11,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"rdata_q", &(TOP__CoreTop__u_ifu__IMem__imem.rdata_q), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_CoreTop__u_ifu__IMem__imem.varInsert(__Vfinal,"rst", &(TOP__CoreTop__u_ifu__IMem__imem.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"program_address", &(TOP.program_address), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOP.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"start", &(TOP.start), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
    }
}
