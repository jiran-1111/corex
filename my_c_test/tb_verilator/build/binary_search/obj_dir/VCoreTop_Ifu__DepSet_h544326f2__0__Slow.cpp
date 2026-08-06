// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_Ifu.h"

VL_ATTR_COLD void VCoreTop_Ifu___ctor_var_reset(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___ctor_var_reset\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7179230919112499263ull);
    vlSelf->program_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14572411656227091738ull);
    vlSelf->JAL_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13762997767199921771ull);
    vlSelf->JALR_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8830659708808977088ull);
    vlSelf->branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3479053110442652010ull);
    vlSelf->pc_sel_execute = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11434460803577170541ull);
    vlSelf->branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9741308562845961313ull);
    vlSelf->instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8876431511369994264ull);
    vlSelf->inst_PC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13666971760089573322ull);
    vlSelf->valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4944192500720994163ull);
    vlSelf->PC_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3068564523303934272ull);
    vlSelf->PC_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15616808196035973470ull);
    vlSelf->inst_PC_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16951096912792847615ull);
    vlSelf->next_PC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5538379456580407318ull);
    vlSelf->imem_gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16196448357957803538ull);
    vlSelf->imem_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 418908598611598165ull);
    vlSelf->fetch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14022223855178902746ull);
    vlSelf->jump_or_branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10257882756567247808ull);
}
