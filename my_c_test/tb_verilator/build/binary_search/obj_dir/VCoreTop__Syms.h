// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCORETOP__SYMS_H_
#define VERILATED_VCORETOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VCoreTop.h"

// INCLUDE MODULE CLASSES
#include "VCoreTop___024root.h"
#include "VCoreTop_CoreTop.h"
#include "VCoreTop_Ifu.h"
#include "VCoreTop_IMemTop.h"
#include "VCoreTop_DBusIf.h"
#include "VCoreTop_IMem.h"
#include "VCoreTop_IBusIf.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VCoreTop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VCoreTop* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VCoreTop___024root             TOP;
    VCoreTop_CoreTop               TOP__CoreTop;
    VCoreTop_DBusIf                TOP__CoreTop__u_dmem__DOT__dbus;
    VCoreTop_Ifu                   TOP__CoreTop__u_ifu;
    VCoreTop_IMemTop               TOP__CoreTop__u_ifu__IMem;
    VCoreTop_IBusIf                TOP__CoreTop__u_ifu__IMem__ibus;
    VCoreTop_IMem                  TOP__CoreTop__u_ifu__IMem__imem;

    // COVERAGE
    uint32_t __Vcoverage[6635];

    // SCOPE NAMES
    VerilatedScope __Vscope_CoreTop;
    VerilatedScope __Vscope_CoreTop__u_control_unit;
    VerilatedScope __Vscope_CoreTop__u_decoder;
    VerilatedScope __Vscope_CoreTop__u_decoder__u_regfile;
    VerilatedScope __Vscope_CoreTop__u_decoder__u_regfile__unnamedblk1;
    VerilatedScope __Vscope_CoreTop__u_dmem;
    VerilatedScope __Vscope_CoreTop__u_dmem__dbus;
    VerilatedScope __Vscope_CoreTop__u_dmem__dmem;
    VerilatedScope __Vscope_CoreTop__u_dmem__dmem__unnamedblk1;
    VerilatedScope __Vscope_CoreTop__u_dmem__dmem__unnamedblk2;
    VerilatedScope __Vscope_CoreTop__u_ex_mem_reg;
    VerilatedScope __Vscope_CoreTop__u_execute;
    VerilatedScope __Vscope_CoreTop__u_execute__u_alu;
    VerilatedScope __Vscope_CoreTop__u_if_id_reg;
    VerilatedScope __Vscope_CoreTop__u_ifu;
    VerilatedScope __Vscope_CoreTop__u_ifu__IMem;
    VerilatedScope __Vscope_CoreTop__u_ifu__IMem__ibus;
    VerilatedScope __Vscope_CoreTop__u_ifu__IMem__imem;
    VerilatedScope __Vscope_TOP;

    // CONSTRUCTORS
    VCoreTop__Syms(VerilatedContext* contextp, const char* namep, VCoreTop* modelp);
    ~VCoreTop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
