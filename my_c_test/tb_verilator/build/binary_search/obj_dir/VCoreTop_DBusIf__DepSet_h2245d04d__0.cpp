// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_DBusIf.h"

std::string VL_TO_STRING(const VCoreTop_DBusIf* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_DBusIf::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
