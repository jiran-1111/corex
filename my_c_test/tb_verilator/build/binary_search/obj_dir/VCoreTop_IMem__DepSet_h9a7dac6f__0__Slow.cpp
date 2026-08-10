// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IMem.h"

VL_ATTR_COLD void VCoreTop_IMem___eval_initial__TOP__CoreTop__u_ifu__IMem__imem(VCoreTop_IMem* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_IMem___eval_initial__TOP__CoreTop__u_ifu__IMem__imem\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gnt = 1U;
    vlSelfRef.err = 0U;
}

VL_ATTR_COLD void VCoreTop_IMem___ctor_var_reset(VCoreTop_IMem* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_IMem___ctor_var_reset\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4032165174000709208ull);
    }
    vlSelf->gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12311452861025780666ull);
    vlSelf->err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10541192957841604819ull);
    vlSelf->mem_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 326597072690670135ull);
    vlSelf->rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3450541952785548621ull);
    vlSelf->__Vtogcov__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8977754005702907422ull);
    vlSelf->__Vtogcov__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6831442562242317817ull);
    vlSelf->__Vtogcov__gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16808793585744629073ull);
    vlSelf->__Vtogcov__err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 347842528286250480ull);
    vlSelf->__Vtogcov__mem_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 3220044741057482468ull);
    vlSelf->__Vtogcov__rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16387982742311532879ull);
}
