// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_CoreTop.h"
#include "VCoreTop__Syms.h"

// Parameter definitions for VCoreTop_CoreTop
constexpr CData/*0:0*/ VCoreTop_CoreTop::u_if_id_reg__DOT__RESET_VALUE;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__R_TYPE;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__I_TYPE;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__AUIPC;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__LUI;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__STORE;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__LOAD;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__BRANCH;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__JALR;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__JAL;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__FENCES;
constexpr CData/*6:0*/ VCoreTop_CoreTop::u_control_unit__DOT__SYSCALL;
constexpr CData/*0:0*/ VCoreTop_CoreTop::u_decoder__DOT__u_regfile__DOT__ZERO_X0;
constexpr CData/*0:0*/ VCoreTop_CoreTop::u_ex_mem_reg__DOT__RESET_VALUE;
constexpr IData/*31:0*/ VCoreTop_CoreTop::DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::ADDR_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::NOP;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_if_id_reg__DOT__CTRL_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_if_id_reg__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_control_unit__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_decoder__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_decoder__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_decoder__DOT__u_regfile__DOT__REG_DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_decoder__DOT__u_regfile__DOT__REG_SEL_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_decoder__DOT__u_regfile__DOT__REG_COUNT;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_execute__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_execute__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_execute__DOT__u_alu__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_execute__DOT__u_alu__DOT__SHIFT_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_ex_mem_reg__DOT__CTRL_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_ex_mem_reg__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__SIZE_BYTES;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__BYTES_PER_WORD;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__dmem__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__dmem__DOT__SIZE_BYTES;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__dmem__DOT__BYTES_PER_WORD;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__dmem__DOT__MEM_DEPTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__dmem__DOT__MEM_ADDR_WIDTH;
constexpr IData/*31:0*/ VCoreTop_CoreTop::u_dmem__DOT__dmem__DOT__BYTE_OFFSET;
const std::string VCoreTop_CoreTop::IMEM_INIT_FILE = "";
const std::string VCoreTop_CoreTop::DMEM_INIT_FILE = "";
const std::string VCoreTop_CoreTop::u_dmem__DOT__INIT_FILE = "";
const std::string VCoreTop_CoreTop::u_dmem__DOT__dmem__DOT__INIT_FILE = "";


void VCoreTop_CoreTop___ctor_var_reset(VCoreTop_CoreTop* vlSelf);

VCoreTop_CoreTop::VCoreTop_CoreTop(VCoreTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCoreTop_CoreTop___ctor_var_reset(this);
}

void VCoreTop_CoreTop::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VCoreTop_CoreTop::~VCoreTop_CoreTop() {
}
