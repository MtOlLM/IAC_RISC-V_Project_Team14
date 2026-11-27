// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

void Vdut___024root___eval_act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf);

void Vdut___024root___eval_nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__top__DOT__regfile__DOT__register_file__v0;
    __VdlyVal__top__DOT__regfile__DOT__register_file__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regfile__DOT__register_file__v0;
    __VdlyDim0__top__DOT__regfile__DOT__register_file__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regfile__DOT__register_file__v0;
    __VdlySet__top__DOT__regfile__DOT__register_file__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0;
    __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0;
    __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0;
    __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1;
    __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1;
    __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1;
    __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2;
    __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2;
    __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2;
    __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3;
    __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3;
    __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3;
    __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3 = 0;
    // Body
    __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0 = 0U;
    __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1 = 0U;
    __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2 = 0U;
    __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3 = 0U;
    __VdlySet__top__DOT__regfile__DOT__register_file__v0 = 0U;
    if ((1U & (IData)(vlSelfRef.top__DOT__mem_write))) {
        __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0 
            = (0xffU & vlSelfRef.top__DOT__rs2);
        __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0 
            = (0x1ffffU & vlSelfRef.top__DOT__ALU_out);
        __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0 = 1U;
    }
    if ((2U & (IData)(vlSelfRef.top__DOT__mem_write))) {
        __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1 
            = (0xffU & (vlSelfRef.top__DOT__rs2 >> 8U));
        __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1 
            = (0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALU_out));
        __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1 = 1U;
    }
    if ((4U & (IData)(vlSelfRef.top__DOT__mem_write))) {
        __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2 
            = (0xffU & (vlSelfRef.top__DOT__rs2 >> 0x10U));
        __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2 
            = (0x1ffffU & ((IData)(2U) + vlSelfRef.top__DOT__ALU_out));
        __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2 = 1U;
    }
    if ((8U & (IData)(vlSelfRef.top__DOT__mem_write))) {
        __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3 
            = (vlSelfRef.top__DOT__rs2 >> 0x18U);
        __VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3 
            = (0x1ffffU & ((IData)(3U) + vlSelfRef.top__DOT__ALU_out));
        __VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3 = 1U;
    }
    if (((IData)(vlSelfRef.top__DOT__reg_write) & (0U 
                                                   != 
                                                   (0x1fU 
                                                    & ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
                                                       >> 7U))))) {
        __VdlyVal__top__DOT__regfile__DOT__register_file__v0 
            = ((2U & (IData)(vlSelfRef.top__DOT__result_src))
                ? ((1U & (IData)(vlSelfRef.top__DOT__result_src))
                    ? vlSelfRef.top__DOT__inc_pc : vlSelfRef.top__DOT__imm_op)
                : ((1U & (IData)(vlSelfRef.top__DOT__result_src))
                    ? ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                        ? ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                            ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                            : ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                ? (0xffffU & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)
                                : (0xffU & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))
                        : ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                            ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                            : ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                ? (((- (IData)((1U 
                                                & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                   >> 0xfU)))) 
                                    << 0x10U) | (0xffffU 
                                                 & vlSelfRef.top__DOT__MCU__DOT__ram_data_out))
                                : (((- (IData)((1U 
                                                & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                   >> 7U)))) 
                                    << 8U) | (0xffU 
                                              & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))))
                    : vlSelfRef.top__DOT__ALU_out));
        __VdlyDim0__top__DOT__regfile__DOT__register_file__v0 
            = (0x1fU & ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
                        >> 7U));
        __VdlySet__top__DOT__regfile__DOT__register_file__v0 = 1U;
    }
    vlSelfRef.top__DOT__pc = ((IData)(vlSelfRef.rst)
                               ? 0U : vlSelfRef.top__DOT__program_counter__DOT__next_pc);
    if (__VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0) {
        vlSelfRef.top__DOT__MCU__DOT__data_RAM__DOT__ram_array[__VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0] 
            = __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v0;
    }
    if (__VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1) {
        vlSelfRef.top__DOT__MCU__DOT__data_RAM__DOT__ram_array[__VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1] 
            = __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v1;
    }
    if (__VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2) {
        vlSelfRef.top__DOT__MCU__DOT__data_RAM__DOT__ram_array[__VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2] 
            = __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v2;
    }
    if (__VdlySet__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3) {
        vlSelfRef.top__DOT__MCU__DOT__data_RAM__DOT__ram_array[__VdlyDim0__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3] 
            = __VdlyVal__top__DOT__MCU__DOT__data_RAM__DOT__ram_array__v3;
    }
    if (__VdlySet__top__DOT__regfile__DOT__register_file__v0) {
        vlSelfRef.top__DOT__regfile__DOT__register_file[__VdlyDim0__top__DOT__regfile__DOT__register_file__v0] 
            = __VdlyVal__top__DOT__regfile__DOT__register_file__v0;
    }
    vlSelfRef.a0 = vlSelfRef.top__DOT__regfile__DOT__register_file
        [0xaU];
    vlSelfRef.top__DOT____Vcellinp__control_unit__funct7_5 
        = (1U & (vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                 [(0xfffU & ((IData)(3U) + vlSelfRef.top__DOT__pc))] 
                 >> 6U));
    vlSelfRef.top__DOT____Vcellinp__control_unit__funct3 
        = (7U & (vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                 [(0xfffU & ((IData)(1U) + vlSelfRef.top__DOT__pc))] 
                 >> 4U));
    vlSelfRef.top__DOT____Vcellinp__sign_ext__in = 
        ((vlSelfRef.top__DOT__instr_mem__DOT__rom_array
          [(0xfffU & ((IData)(3U) + vlSelfRef.top__DOT__pc))] 
          << 0x11U) | ((vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                        [(0xfffU & ((IData)(2U) + vlSelfRef.top__DOT__pc))] 
                        << 9U) | ((vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                                   [(0xfffU & ((IData)(1U) 
                                               + vlSelfRef.top__DOT__pc))] 
                                   << 1U) | (1U & (
                                                   vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                                                   [
                                                   (0xfffU 
                                                    & vlSelfRef.top__DOT__pc)] 
                                                   >> 7U)))));
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_0 = ((vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                                                 [(0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__pc))] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                                                [(0xfffU 
                                                  & vlSelfRef.top__DOT__pc)]);
    vlSelfRef.top__DOT____Vcellinp__control_unit__opcode 
        = (0x7fU & vlSelfRef.top__DOT__instr_mem__DOT__rom_array
           [(0xfffU & vlSelfRef.top__DOT__pc)]);
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_1 = ((vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                                                 [(0xfffU 
                                                   & ((IData)(2U) 
                                                      + vlSelfRef.top__DOT__pc))] 
                                                 << 0x10U) 
                                                | (IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0));
    vlSelfRef.top__DOT__reg_write = 0U;
    vlSelfRef.top__DOT__result_src = 0U;
    vlSelfRef.top__DOT__mem_write = 0U;
    vlSelfRef.top__DOT__ALU_control = 0U;
    vlSelfRef.top__DOT__imm_src = 0U;
    vlSelfRef.top__DOT__ALU_src = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                  >> 6U)))) {
        if ((0x20U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                                vlSelfRef.top__DOT__mem_write 
                                    = ((0U == (3U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3)))
                                        ? 1U : ((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3)))
                                                 ? 3U
                                                 : 
                                                ((2U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3)))
                                                  ? 0xfU
                                                  : 0U)));
                                vlSelfRef.top__DOT__ALU_src 
                                    = (2U | (IData)(vlSelfRef.top__DOT__ALU_src));
                            }
                        }
                    }
                }
            }
            if ((0x10U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                                vlSelfRef.top__DOT__ALU_control 
                                    = (((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct7_5) 
                                        << 3U) | (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3));
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                                 >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            vlSelfRef.top__DOT__ALU_control = 0U;
                        }
                    }
                }
            }
        } else if ((0x10U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            vlSelfRef.top__DOT__ALU_control = 0U;
                            vlSelfRef.top__DOT__ALU_src = 3U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        vlSelfRef.top__DOT__ALU_control 
                            = ((((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct7_5) 
                                 & (5U == (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))) 
                                << 3U) | (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3));
                        if ((5U == (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))) {
                            vlSelfRef.top__DOT__ALU_control 
                                = ((7U & (IData)(vlSelfRef.top__DOT__ALU_control)) 
                                   | ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct7_5) 
                                      << 3U));
                        }
                        vlSelfRef.top__DOT__ALU_src 
                            = (2U | (IData)(vlSelfRef.top__DOT__ALU_src));
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        vlSelfRef.top__DOT__ALU_control = 0U;
                        vlSelfRef.top__DOT__ALU_src 
                            = (2U | (IData)(vlSelfRef.top__DOT__ALU_src));
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__rs2 = vlSelfRef.top__DOT__regfile__DOT__register_file
        [((0x10U & (vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                    [(0xfffU & ((IData)(3U) + vlSelfRef.top__DOT__pc))] 
                    << 4U)) | (0xfU & (vlSelfRef.__VdfgRegularize_hd87f99a1_0_1 
                                       >> 0x14U)))];
    vlSelfRef.top__DOT__rs1 = vlSelfRef.top__DOT__regfile__DOT__register_file
        [(0x1fU & (vlSelfRef.__VdfgRegularize_hd87f99a1_0_1 
                   >> 0xfU))];
    if ((0x40U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
        if ((0x20U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                                vlSelfRef.top__DOT__reg_write = 1U;
                                vlSelfRef.top__DOT__result_src = 3U;
                                vlSelfRef.top__DOT__imm_src = 4U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            vlSelfRef.top__DOT__reg_write = 1U;
                            vlSelfRef.top__DOT__result_src = 3U;
                            vlSelfRef.top__DOT__imm_src = 0U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        vlSelfRef.top__DOT__imm_src = 2U;
                    }
                }
            }
        }
    } else if ((0x20U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
        if ((0x10U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            vlSelfRef.top__DOT__reg_write = 1U;
                            vlSelfRef.top__DOT__result_src = 2U;
                            vlSelfRef.top__DOT__imm_src = 3U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        vlSelfRef.top__DOT__reg_write = 1U;
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        vlSelfRef.top__DOT__imm_src = 1U;
                    }
                }
            }
        }
    } else {
        if ((0x10U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            vlSelfRef.top__DOT__reg_write = 1U;
                            vlSelfRef.top__DOT__imm_src = 3U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        vlSelfRef.top__DOT__reg_write = 1U;
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        vlSelfRef.top__DOT__reg_write = 1U;
                    }
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            vlSelfRef.top__DOT__result_src = 1U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__imm_op = ((4U & (IData)(vlSelfRef.top__DOT__imm_src))
                                   ? ((2U & (IData)(vlSelfRef.top__DOT__imm_src))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelfRef.top__DOT__imm_src))
                                                ? 0U
                                                : (
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                                    >> 0x18U)))) 
                                                     << 0x15U) 
                                                    | (0x100000U 
                                                       & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                          >> 4U))) 
                                                   | (((0xff000U 
                                                        & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                           << 7U)) 
                                                       | (0x800U 
                                                          & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                             >> 2U))) 
                                                      | (0x7feU 
                                                         & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                            >> 0xdU))))))
                                   : ((2U & (IData)(vlSelfRef.top__DOT__imm_src))
                                       ? ((1U & (IData)(vlSelfRef.top__DOT__imm_src))
                                           ? (0xfffff000U 
                                              & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                 << 7U))
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                              >> 0x18U)))) 
                                               << 0xdU) 
                                              | (((0x1000U 
                                                   & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                      >> 0xcU)) 
                                                  | (0x800U 
                                                     & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                        << 0xbU))) 
                                                 | ((0x7e0U 
                                                     & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                        >> 0xdU)) 
                                                    | (0x1eU 
                                                       & vlSelfRef.top__DOT____Vcellinp__sign_ext__in)))))
                                       : ((1U & (IData)(vlSelfRef.top__DOT__imm_src))
                                           ? (((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                              >> 0x18U)))) 
                                               << 0xcU) 
                                              | ((0xfe0U 
                                                  & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                     >> 0xdU)) 
                                                 | (0x1fU 
                                                    & vlSelfRef.top__DOT____Vcellinp__sign_ext__in)))
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                              >> 0x18U)))) 
                                               << 0xcU) 
                                              | (0xfffU 
                                                 & (vlSelfRef.top__DOT____Vcellinp__sign_ext__in 
                                                    >> 0xdU))))));
    vlSelfRef.top__DOT__alu_op1 = ((1U & (IData)(vlSelfRef.top__DOT__ALU_src))
                                    ? vlSelfRef.top__DOT__pc
                                    : vlSelfRef.top__DOT__rs1);
    vlSelfRef.top__DOT__alu_op2 = ((2U & (IData)(vlSelfRef.top__DOT__ALU_src))
                                    ? vlSelfRef.top__DOT__imm_op
                                    : vlSelfRef.top__DOT__rs2);
    vlSelfRef.top__DOT__ALU_out = ((8U & (IData)(vlSelfRef.top__DOT__ALU_control))
                                    ? ((4U & (IData)(vlSelfRef.top__DOT__ALU_control))
                                        ? ((2U & (IData)(vlSelfRef.top__DOT__ALU_control))
                                            ? 0U : 
                                           ((1U & (IData)(vlSelfRef.top__DOT__ALU_control))
                                             ? VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__alu_op1, 
                                                              (0x1fU 
                                                               & vlSelfRef.top__DOT__alu_op2))
                                             : 0U))
                                        : ((2U & (IData)(vlSelfRef.top__DOT__ALU_control))
                                            ? 0U : 
                                           ((1U & (IData)(vlSelfRef.top__DOT__ALU_control))
                                             ? 0U : 
                                            (vlSelfRef.top__DOT__alu_op1 
                                             - vlSelfRef.top__DOT__alu_op2))))
                                    : ((4U & (IData)(vlSelfRef.top__DOT__ALU_control))
                                        ? ((2U & (IData)(vlSelfRef.top__DOT__ALU_control))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.top__DOT__ALU_control))
                                                ? (vlSelfRef.top__DOT__alu_op1 
                                                   & vlSelfRef.top__DOT__alu_op2)
                                                : (vlSelfRef.top__DOT__alu_op1 
                                                   | vlSelfRef.top__DOT__alu_op2))
                                            : ((1U 
                                                & (IData)(vlSelfRef.top__DOT__ALU_control))
                                                ? (vlSelfRef.top__DOT__alu_op1 
                                                   >> 
                                                   (0x1fU 
                                                    & vlSelfRef.top__DOT__alu_op2))
                                                : (vlSelfRef.top__DOT__alu_op1 
                                                   ^ vlSelfRef.top__DOT__alu_op2)))
                                        : ((2U & (IData)(vlSelfRef.top__DOT__ALU_control))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.top__DOT__ALU_control))
                                                ? (vlSelfRef.top__DOT__alu_op1 
                                                   < vlSelfRef.top__DOT__alu_op2)
                                                : VL_LTS_III(32, vlSelfRef.top__DOT__alu_op1, vlSelfRef.top__DOT__alu_op2))
                                            : ((1U 
                                                & (IData)(vlSelfRef.top__DOT__ALU_control))
                                                ? (vlSelfRef.top__DOT__alu_op1 
                                                   << 
                                                   (0x1fU 
                                                    & vlSelfRef.top__DOT__alu_op2))
                                                : (vlSelfRef.top__DOT__alu_op1 
                                                   + vlSelfRef.top__DOT__alu_op2)))));
    vlSelfRef.top__DOT__branch_ctrl = (((vlSelfRef.top__DOT__alu_op1 
                                         == vlSelfRef.top__DOT__alu_op2) 
                                        << 3U) | ((
                                                   VL_LTS_III(32, vlSelfRef.top__DOT__alu_op1, vlSelfRef.top__DOT__alu_op2) 
                                                   << 1U) 
                                                  | (vlSelfRef.top__DOT__alu_op1 
                                                     < vlSelfRef.top__DOT__alu_op2)));
    vlSelfRef.top__DOT__MCU__DOT__ram_data_out = ((
                                                   (vlSelfRef.top__DOT__MCU__DOT__data_RAM__DOT__ram_array
                                                    [
                                                    (0x1ffffU 
                                                     & ((IData)(3U) 
                                                        + vlSelfRef.top__DOT__ALU_out))] 
                                                    << 0x18U) 
                                                   | (vlSelfRef.top__DOT__MCU__DOT__data_RAM__DOT__ram_array
                                                      [
                                                      (0x1ffffU 
                                                       & ((IData)(2U) 
                                                          + vlSelfRef.top__DOT__ALU_out))] 
                                                      << 0x10U)) 
                                                  | ((vlSelfRef.top__DOT__MCU__DOT__data_RAM__DOT__ram_array
                                                      [
                                                      (0x1ffffU 
                                                       & ((IData)(1U) 
                                                          + vlSelfRef.top__DOT__ALU_out))] 
                                                      << 8U) 
                                                     | vlSelfRef.top__DOT__MCU__DOT__data_RAM__DOT__ram_array
                                                     [
                                                     (0x1ffffU 
                                                      & vlSelfRef.top__DOT__ALU_out)]));
    vlSelfRef.top__DOT__pc_src = 0U;
    if ((0x40U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
        if ((0x20U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                                vlSelfRef.top__DOT__pc_src = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                            vlSelfRef.top__DOT__pc_src = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode))) {
                        vlSelfRef.top__DOT__pc_src 
                            = ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                ? ((2U & (IData)(vlSelfRef.top__DOT__pc_src)) 
                                   | (1U & ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                                 ? 
                                                (~ (IData)(vlSelfRef.top__DOT__branch_ctrl))
                                                 : (IData)(vlSelfRef.top__DOT__branch_ctrl))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelfRef.top__DOT__branch_ctrl) 
                                                  >> 1U))
                                                 : 
                                                ((IData)(vlSelfRef.top__DOT__branch_ctrl) 
                                                 >> 1U)))))
                                : ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                    ? 0U : ((2U & (IData)(vlSelfRef.top__DOT__pc_src)) 
                                            | (1U & 
                                               ((1U 
                                                 & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                                 ? 
                                                (~ 
                                                 ((IData)(vlSelfRef.top__DOT__branch_ctrl) 
                                                  >> 3U))
                                                 : 
                                                ((IData)(vlSelfRef.top__DOT__branch_ctrl) 
                                                 >> 3U))))));
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__inc_pc = ((IData)(4U) + vlSelfRef.top__DOT__pc);
    vlSelfRef.top__DOT__program_counter__DOT__relative_pc 
        = (vlSelfRef.top__DOT__pc + vlSelfRef.top__DOT__imm_op);
    vlSelfRef.top__DOT__program_counter__DOT__absolute_pc 
        = (0xfffffffeU & (vlSelfRef.top__DOT__rs1 + vlSelfRef.top__DOT__imm_op));
    vlSelfRef.top__DOT__program_counter__DOT__next_pc 
        = ((0U == (IData)(vlSelfRef.top__DOT__pc_src))
            ? vlSelfRef.top__DOT__inc_pc : ((1U == (IData)(vlSelfRef.top__DOT__pc_src))
                                             ? vlSelfRef.top__DOT__program_counter__DOT__relative_pc
                                             : ((2U 
                                                 == (IData)(vlSelfRef.top__DOT__pc_src))
                                                 ? vlSelfRef.top__DOT__program_counter__DOT__absolute_pc
                                                 : vlSelfRef.top__DOT__inc_pc)));
}

void Vdut___024root___eval_triggers__act(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdut___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdut___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdut___024root___eval_phase__nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdut___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vdut___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../rtl/top.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdut___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdut___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
