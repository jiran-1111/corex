// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_CoreTop.h"

VL_ATTR_COLD void VCoreTop_CoreTop___eval_initial__TOP__CoreTop(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___eval_initial__TOP__CoreTop\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.stall = 0U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x1000U, vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[(0xfffU 
                                               & vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i)] = 0U;
        vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i);
    }
    vlSelfRef.u_dmem__DOT__dmem__DOT__gnt = 1U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__err = 0U;
    vlSelfRef.u_ex_mem_reg__DOT__flush = 0U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 0U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 1U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 2U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 3U;
    vlSelfRef.u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 4U;
}

VL_ATTR_COLD void VCoreTop_CoreTop___ctor_var_reset(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___ctor_var_reset\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->program_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14572411656227091738ull);
    vlSelf->stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7179230919112499263ull);
    vlSelf->flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8361382489806169962ull);
    vlSelf->if_instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1785401360507248117ull);
    vlSelf->if_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12943109772521745060ull);
    vlSelf->if_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2083161230122339260ull);
    vlSelf->id_pc_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1770549076600472687ull);
    vlSelf->ex_branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11784697329827887643ull);
    vlSelf->id_branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15713471709109013470ull);
    vlSelf->id_jal_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7591635487237645296ull);
    vlSelf->ex_jalr_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8344553311671846689ull);
    vlSelf->id_instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10362910217659916677ull);
    vlSelf->id_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11514240163166444805ull);
    vlSelf->id_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17315639441857410375ull);
    vlSelf->id_instruction_real = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12763774888924935376ull);
    vlSelf->id_alu_op = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14030447827651045958ull);
    vlSelf->id_operand_a = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8724320425095447716ull);
    vlSelf->id_operand_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6890357128456835748ull);
    vlSelf->id_extend_sel = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13378691501719885035ull);
    vlSelf->id_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3218916237426022453ull);
    vlSelf->id_branch_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16908684734640788268ull);
    vlSelf->id_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9079389628330843447ull);
    vlSelf->id_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13868669800259891711ull);
    vlSelf->id_mem_to_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13602901500501082841ull);
    vlSelf->id_opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 14889594337889393726ull);
    vlSelf->id_funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 12409692206607371714ull);
    vlSelf->id_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7586384359710784381ull);
    vlSelf->id_rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11161051184236966554ull);
    vlSelf->id_rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1234937432380737747ull);
    vlSelf->id_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7361846893978282369ull);
    vlSelf->id_extend_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12380508103811053400ull);
    vlSelf->id_rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11937095040506201589ull);
    vlSelf->id_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9943837479444938783ull);
    vlSelf->id_mem_wbe = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18074569360065463756ull);
    vlSelf->ex_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7529293660166449691ull);
    vlSelf->wb_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6949882575047384243ull);
    vlSelf->wb_write_reg = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14037247198851692032ull);
    vlSelf->wb_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065751511148788534ull);
    vlSelf->mem_ctrl_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3535103708679641892ull);
    VL_SCOPED_RAND_RESET_W(77, vlSelf->id_ex_data_in, __VscopeHash, 13639186828917221268ull);
    VL_SCOPED_RAND_RESET_W(77, vlSelf->mem_data_out, __VscopeHash, 1804579628565772488ull);
    vlSelf->mem_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9659133473039683418ull);
    vlSelf->dmem_gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5675421106615776949ull);
    vlSelf->dmem_rack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2356652016391147746ull);
    vlSelf->dmem_wack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5658779703905607447ull);
    vlSelf->dmem_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15879450885275558624ull);
    vlSelf->flush_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12157993274752035746ull);
    vlSelf->real_if_id_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11032393963725397829ull);
    vlSelf->u_if_id_reg__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1155571005677575077ull);
    vlSelf->u_if_id_reg__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13919705248861663337ull);
    vlSelf->u_if_id_reg__DOT__flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1987213197145316253ull);
    vlSelf->u_if_id_reg__DOT__en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14195815090917557042ull);
    vlSelf->u_if_id_reg__DOT__ctrl_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6890071486616404725ull);
    vlSelf->u_if_id_reg__DOT__ctrl_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11151738440818573606ull);
    vlSelf->u_if_id_reg__DOT__data_in = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7721426973535263860ull);
    vlSelf->u_if_id_reg__DOT__data_out = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7149527387851276335ull);
    vlSelf->u_if_id_reg__DOT__ctrl_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15292175394100885978ull);
    vlSelf->u_if_id_reg__DOT__data_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13386535548375072175ull);
    vlSelf->u_control_unit__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9872984416739401310ull);
    vlSelf->u_control_unit__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12868710118312138450ull);
    vlSelf->u_control_unit__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 5082194453523058710ull);
    vlSelf->u_control_unit__DOT__ALUOp = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6924129591912330418ull);
    vlSelf->u_control_unit__DOT__operand_A = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1663838690473360560ull);
    vlSelf->u_control_unit__DOT__operand_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8713649498882090234ull);
    vlSelf->u_control_unit__DOT__extend_sel = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12404069950447542243ull);
    vlSelf->u_control_unit__DOT__regWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17104842014159851685ull);
    vlSelf->u_control_unit__DOT__branch_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3452900315385071226ull);
    vlSelf->u_control_unit__DOT__memRead = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13160673569503451385ull);
    vlSelf->u_control_unit__DOT__memWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7953743618332185546ull);
    vlSelf->u_control_unit__DOT__memtoReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12485591018189657390ull);
    vlSelf->u_control_unit__DOT__next_PC_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17293939418343531835ull);
    vlSelf->u_decoder__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7795748119747393850ull);
    vlSelf->u_decoder__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17441828221221765321ull);
    vlSelf->u_decoder__DOT__instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5431800950866659893ull);
    vlSelf->u_decoder__DOT__PC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8677410841713619377ull);
    vlSelf->u_decoder__DOT__extend_sel = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9441846960067322096ull);
    vlSelf->u_decoder__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6864049506970573985ull);
    vlSelf->u_decoder__DOT__write_reg = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8092894239192403997ull);
    vlSelf->u_decoder__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2709537931480312686ull);
    vlSelf->u_decoder__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 2031622673326582230ull);
    vlSelf->u_decoder__DOT__funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 9032870259074702633ull);
    vlSelf->u_decoder__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17698854720085792058ull);
    vlSelf->u_decoder__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16874439924953298278ull);
    vlSelf->u_decoder__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5235337499964906097ull);
    vlSelf->u_decoder__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9393117620240018463ull);
    vlSelf->u_decoder__DOT__extend_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17345153074129954032ull);
    vlSelf->u_decoder__DOT__rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9286865785817165606ull);
    vlSelf->u_decoder__DOT__rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4776537356252232253ull);
    vlSelf->u_decoder__DOT__branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13809287372607889554ull);
    vlSelf->u_decoder__DOT__JAL_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2114648629429608922ull);
    vlSelf->u_decoder__DOT__mem_wbe = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 361729231427458625ull);
    vlSelf->u_decoder__DOT__i_imm_orig = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8657849181407809633ull);
    vlSelf->u_decoder__DOT__u_imm = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 5193073846459508174ull);
    vlSelf->u_decoder__DOT__i_imm_32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 593655167491423467ull);
    vlSelf->u_decoder__DOT__u_imm_32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8992769026815218421ull);
    vlSelf->u_decoder__DOT__s_imm_msb = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 8949867745983376486ull);
    vlSelf->u_decoder__DOT__s_imm_lsb = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13684020650657826263ull);
    vlSelf->u_decoder__DOT__s_imm_orig = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 6742957031350262533ull);
    vlSelf->u_decoder__DOT__s_imm_32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13835551085499774537ull);
    vlSelf->u_decoder__DOT__sb_imm_orig = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 1704998078598209450ull);
    vlSelf->u_decoder__DOT__sb_imm_32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11299557195017506895ull);
    vlSelf->u_decoder__DOT__uj_imm = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 12538686362812205992ull);
    vlSelf->u_decoder__DOT__uj_imm_32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6457402260020297945ull);
    vlSelf->u_decoder__DOT__rs1_data_bypass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1882429135155877718ull);
    vlSelf->u_decoder__DOT__rs2_data_bypass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14255393694921429779ull);
    vlSelf->u_decoder__DOT__rs1_data_decode = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18435415842043513934ull);
    vlSelf->u_decoder__DOT__rs2_data_decode = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5276669813664588554ull);
    vlSelf->u_decoder__DOT__u_regfile__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3283857792891764313ull);
    vlSelf->u_decoder__DOT__u_regfile__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14507195830635523899ull);
    vlSelf->u_decoder__DOT__u_regfile__DOT__wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6891950423863011748ull);
    vlSelf->u_decoder__DOT__u_regfile__DOT__waddr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6098455453857950445ull);
    vlSelf->u_decoder__DOT__u_regfile__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1164764020323611418ull);
    vlSelf->u_decoder__DOT__u_regfile__DOT__raddr1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12120018696891794378ull);
    vlSelf->u_decoder__DOT__u_regfile__DOT__raddr2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 335063665354033216ull);
    vlSelf->u_decoder__DOT__u_regfile__DOT__rdata1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8778235277880623509ull);
    vlSelf->u_decoder__DOT__u_regfile__DOT__rdata2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1142029249802757816ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->u_decoder__DOT__u_regfile__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1944767502560049610ull);
    }
    vlSelf->u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->u_execute__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1491221565103144541ull);
    vlSelf->u_execute__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1382386290054051211ull);
    vlSelf->u_execute__DOT__stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7121992824651064076ull);
    vlSelf->u_execute__DOT__ALU_Operation = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 175432822999735412ull);
    vlSelf->u_execute__DOT__funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 18442043083582500464ull);
    vlSelf->u_execute__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10325198000398095775ull);
    vlSelf->u_execute__DOT__ALU_ASrc = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10522318828000627225ull);
    vlSelf->u_execute__DOT__ALU_BSrc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16485596798418327568ull);
    vlSelf->u_execute__DOT__PC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10547509379014822386ull);
    vlSelf->u_execute__DOT__regRead_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16257024394812062605ull);
    vlSelf->u_execute__DOT__regRead_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9711164236745732104ull);
    vlSelf->u_execute__DOT__extend = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17239113949736933262ull);
    vlSelf->u_execute__DOT__branch_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 375473081787352411ull);
    vlSelf->u_execute__DOT__ALU_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17860254833223545677ull);
    vlSelf->u_execute__DOT__branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10207469093053846036ull);
    vlSelf->u_execute__DOT__JALR_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8737584517947122942ull);
    vlSelf->u_execute__DOT__ALU_Control = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 15753314155670724354ull);
    vlSelf->u_execute__DOT__alu_cmp_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8472009539510057004ull);
    vlSelf->u_execute__DOT__alu_in_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9081884316279829895ull);
    vlSelf->u_execute__DOT__alu_in_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 496641676383767916ull);
    vlSelf->u_execute__DOT__u_alu__DOT__ALU_Control = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14933528075750528508ull);
    vlSelf->u_execute__DOT__u_alu__DOT__alu_in_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12298399488818851102ull);
    vlSelf->u_execute__DOT__u_alu__DOT__alu_in_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13897721139670364221ull);
    vlSelf->u_execute__DOT__u_alu__DOT__ALU_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10351379529272935709ull);
    vlSelf->u_execute__DOT__u_alu__DOT__cmp_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4162289501869679009ull);
    vlSelf->u_execute__DOT__u_alu__DOT__shamt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17752339177277972562ull);
    vlSelf->u_execute__DOT__u_alu__DOT__arithmetic_right_shift = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12498236633007371910ull);
    vlSelf->u_execute__DOT__u_alu__DOT__signed_less_than = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13054483848884272619ull);
    vlSelf->u_execute__DOT__u_alu__DOT__unsigned_less_than = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12601967346367452934ull);
    vlSelf->u_execute__DOT__u_alu__DOT__signed_greater_than_equal = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7404243079520635910ull);
    vlSelf->u_ex_mem_reg__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12975184531207760308ull);
    vlSelf->u_ex_mem_reg__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10717174899317132141ull);
    vlSelf->u_ex_mem_reg__DOT__flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18036004337477874137ull);
    vlSelf->u_ex_mem_reg__DOT__en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14783544261852051420ull);
    vlSelf->u_ex_mem_reg__DOT__ctrl_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1184137880215188226ull);
    vlSelf->u_ex_mem_reg__DOT__ctrl_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12444314015802881571ull);
    VL_SCOPED_RAND_RESET_W(77, vlSelf->u_ex_mem_reg__DOT__data_in, __VscopeHash, 2175162721052072578ull);
    VL_SCOPED_RAND_RESET_W(77, vlSelf->u_ex_mem_reg__DOT__data_out, __VscopeHash, 16422235460594266017ull);
    vlSelf->u_ex_mem_reg__DOT__ctrl_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6371981148914445696ull);
    VL_SCOPED_RAND_RESET_W(77, vlSelf->u_ex_mem_reg__DOT__data_q, __VscopeHash, 16396943999590747274ull);
    vlSelf->u_dmem__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12329336250093376887ull);
    vlSelf->u_dmem__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18206975686160195940ull);
    vlSelf->u_dmem__DOT__read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8017893634888316744ull);
    vlSelf->u_dmem__DOT__write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8397930487338204600ull);
    vlSelf->u_dmem__DOT__addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14817536800159254541ull);
    vlSelf->u_dmem__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11517912151316882407ull);
    vlSelf->u_dmem__DOT__wbe = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 810168130280126564ull);
    vlSelf->u_dmem__DOT__gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8377215587958389638ull);
    vlSelf->u_dmem__DOT__rack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3779422730600866016ull);
    vlSelf->u_dmem__DOT__wack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13861965162875902866ull);
    vlSelf->u_dmem__DOT__err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16070427094810294205ull);
    vlSelf->u_dmem__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 558255189880995795ull);
    vlSelf->u_dmem__DOT__dmem__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14550631533422428336ull);
    vlSelf->u_dmem__DOT__dmem__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8949784695392930639ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->u_dmem__DOT__dmem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5821277782427560095ull);
    }
    vlSelf->u_dmem__DOT__dmem__DOT__gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1203314705998261517ull);
    vlSelf->u_dmem__DOT__dmem__DOT__err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9166230113504448793ull);
    vlSelf->u_dmem__DOT__dmem__DOT__mem_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 11117023264649158801ull);
    vlSelf->u_dmem__DOT__dmem__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8949063453499613835ull);
    vlSelf->u_dmem__DOT__dmem__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->u_dmem__DOT__dmem__DOT__unnamedblk2__DOT__i = 0;
}
