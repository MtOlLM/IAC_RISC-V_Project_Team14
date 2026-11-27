// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__regfile__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+1,(((vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                                 [(0xfffU & ((IData)(3U) 
                                             + vlSelfRef.top__DOT__pc))] 
                                 << 0x18U) | vlSelfRef.__VdfgRegularize_hd87f99a1_0_1)),32);
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__pc),32);
        bufp->chgIData(oldp+3,(vlSelfRef.top__DOT__inc_pc),32);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__imm_op),32);
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__ALU_out),32);
        bufp->chgIData(oldp+6,(((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                 ? ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                     ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                                     : ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                         ? (0xffffU 
                                            & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)
                                         : (0xffU & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))
                                 : ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                     ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                                     : ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                            >> 0xfU)))) 
                                             << 0x10U) 
                                            | (0xffffU 
                                               & vlSelfRef.top__DOT__MCU__DOT__ram_data_out))
                                         : (((- (IData)(
                                                        (1U 
                                                         & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                            >> 7U)))) 
                                             << 8U) 
                                            | (0xffU 
                                               & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))))),32);
        bufp->chgIData(oldp+7,(((2U & (IData)(vlSelfRef.top__DOT__result_src))
                                 ? ((1U & (IData)(vlSelfRef.top__DOT__result_src))
                                     ? vlSelfRef.top__DOT__inc_pc
                                     : vlSelfRef.top__DOT__imm_op)
                                 : ((1U & (IData)(vlSelfRef.top__DOT__result_src))
                                     ? ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                         ? ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                             ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                                             : ((1U 
                                                 & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                                 ? 
                                                (0xffffU 
                                                 & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)
                                                 : 
                                                (0xffU 
                                                 & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))
                                         : ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                             ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                                             : ((1U 
                                                 & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                                 ? 
                                                (((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                                 >> 0xfU)))) 
                                                  << 0x10U) 
                                                 | (0xffffU 
                                                    & vlSelfRef.top__DOT__MCU__DOT__ram_data_out))
                                                 : 
                                                (((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                                 >> 7U)))) 
                                                  << 8U) 
                                                 | (0xffU 
                                                    & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))))
                                     : vlSelfRef.top__DOT__ALU_out))),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__alu_op1),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__alu_op2),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__rs1),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__rs2),32);
        bufp->chgCData(oldp+12,(vlSelfRef.top__DOT__branch_ctrl),4);
        bufp->chgBit(oldp+13,(vlSelfRef.top__DOT__reg_write));
        bufp->chgCData(oldp+14,(vlSelfRef.top__DOT__pc_src),2);
        bufp->chgCData(oldp+15,(vlSelfRef.top__DOT__imm_src),3);
        bufp->chgCData(oldp+16,(vlSelfRef.top__DOT__ALU_control),4);
        bufp->chgCData(oldp+17,(vlSelfRef.top__DOT__ALU_src),2);
        bufp->chgCData(oldp+18,(vlSelfRef.top__DOT__mem_write),4);
        bufp->chgCData(oldp+19,(vlSelfRef.top__DOT__result_src),2);
        bufp->chgBit(oldp+20,((1U & (IData)(vlSelfRef.top__DOT__ALU_src))));
        bufp->chgBit(oldp+21,((1U & ((IData)(vlSelfRef.top__DOT__ALU_src) 
                                     >> 1U))));
        bufp->chgCData(oldp+22,(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3),3);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__MCU__DOT__ram_data_out),32);
        bufp->chgIData(oldp+24,((0x1ffffU & vlSelfRef.top__DOT__ALU_out)),17);
        bufp->chgCData(oldp+25,(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode),7);
        bufp->chgBit(oldp+26,(vlSelfRef.top__DOT____Vcellinp__control_unit__funct7_5));
        bufp->chgSData(oldp+27,((0xfffU & vlSelfRef.top__DOT__pc)),12);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__program_counter__DOT__relative_pc),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__program_counter__DOT__absolute_pc),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__program_counter__DOT__next_pc),32);
        bufp->chgCData(oldp+31,((0x1fU & (vlSelfRef.__VdfgRegularize_hd87f99a1_0_1 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+32,(((0x10U & (vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                                           [(0xfffU 
                                             & ((IData)(3U) 
                                                + vlSelfRef.top__DOT__pc))] 
                                           << 4U)) 
                                 | (0xfU & (vlSelfRef.__VdfgRegularize_hd87f99a1_0_1 
                                            >> 0x14U)))),5);
        bufp->chgCData(oldp+33,((0x1fU & ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
                                          >> 7U))),5);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__regfile__DOT__register_file[0]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__regfile__DOT__register_file[1]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__regfile__DOT__register_file[2]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__regfile__DOT__register_file[3]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__regfile__DOT__register_file[4]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__regfile__DOT__register_file[5]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__regfile__DOT__register_file[6]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__regfile__DOT__register_file[7]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__regfile__DOT__register_file[8]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.top__DOT__regfile__DOT__register_file[9]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.top__DOT__regfile__DOT__register_file[10]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__regfile__DOT__register_file[11]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.top__DOT__regfile__DOT__register_file[12]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.top__DOT__regfile__DOT__register_file[13]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.top__DOT__regfile__DOT__register_file[14]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__regfile__DOT__register_file[15]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.top__DOT__regfile__DOT__register_file[16]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__regfile__DOT__register_file[17]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__regfile__DOT__register_file[18]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__regfile__DOT__register_file[19]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__regfile__DOT__register_file[20]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__regfile__DOT__register_file[21]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.top__DOT__regfile__DOT__register_file[22]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.top__DOT__regfile__DOT__register_file[23]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__regfile__DOT__register_file[24]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.top__DOT__regfile__DOT__register_file[25]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__regfile__DOT__register_file[26]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.top__DOT__regfile__DOT__register_file[27]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.top__DOT__regfile__DOT__register_file[28]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.top__DOT__regfile__DOT__register_file[29]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__regfile__DOT__register_file[30]),32);
        bufp->chgIData(oldp+65,(vlSelfRef.top__DOT__regfile__DOT__register_file[31]),32);
        bufp->chgIData(oldp+66,(vlSelfRef.top__DOT____Vcellinp__sign_ext__in),25);
    }
    bufp->chgBit(oldp+67,(vlSelfRef.clk));
    bufp->chgBit(oldp+68,(vlSelfRef.rst));
    bufp->chgIData(oldp+69,(vlSelfRef.a0),32);
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
