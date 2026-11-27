// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___eval_static(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vdut___024root___eval_initial__TOP(Vdut___024root* vlSelf);
VL_ATTR_COLD void Vdut___024root____Vm_traceActivitySetAll(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdut___024root___eval_initial__TOP(vlSelf);
    Vdut___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vdut___024root___eval_initial__TOP(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x6772616dU;
    __Vtemp_1[2U] = 0x70726fU;
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_1)
                 ,  &(vlSelfRef.top__DOT__instr_mem__DOT__rom_array)
                 , 0, ~0ULL);
    vlSelfRef.top__DOT__regfile__DOT__register_file[0U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[1U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[2U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[3U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[4U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[5U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[6U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[7U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[8U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[9U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0xaU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0xbU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0xcU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0xdU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0xeU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0xfU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x10U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x11U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x12U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x13U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x14U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x15U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x16U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x17U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x18U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x19U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x1aU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x1bU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x1cU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x1dU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x1eU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__register_file[0x1fU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__unnamedblk1__DOT__i = 0x20U;
    VL_READMEM_N(true, 8, 131072, 0, std::string{"sine.mem"}
                 ,  &(vlSelfRef.top__DOT__MCU__DOT__data_RAM__DOT__ram_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vdut___024root___eval_final(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__stl(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdut___024root___eval_phase__stl(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/top.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdut___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__stl(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_stl(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vdut___024root___stl_sequent__TOP__0(vlSelf);
        Vdut___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

VL_ATTR_COLD void Vdut___024root___eval_triggers__stl(Vdut___024root* vlSelf);

VL_ATTR_COLD bool Vdut___024root___eval_phase__stl(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdut___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vdut___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root____Vm_traceActivitySetAll(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root____Vm_traceActivitySetAll\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__inc_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__imm_op = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_op1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_op2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rs1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rs2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__branch_ctrl = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__reg_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__pc_src = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__imm_src = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ALU_control = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ALU_src = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__mem_write = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__result_src = VL_RAND_RESET_I(2);
    vlSelf->top__DOT____Vcellinp__control_unit__funct7_5 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____Vcellinp__control_unit__funct3 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT____Vcellinp__control_unit__opcode = VL_RAND_RESET_I(7);
    vlSelf->top__DOT____Vcellinp__sign_ext__in = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->top__DOT__instr_mem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__register_file[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__regfile__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->top__DOT__program_counter__DOT__relative_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__program_counter__DOT__absolute_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__program_counter__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MCU__DOT__ram_data_out = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 131072; ++__Vi0) {
        vlSelf->top__DOT__MCU__DOT__data_RAM__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__VdfgRegularize_hd87f99a1_0_0 = VL_RAND_RESET_I(16);
    vlSelf->__VdfgRegularize_hd87f99a1_0_1 = VL_RAND_RESET_I(24);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
