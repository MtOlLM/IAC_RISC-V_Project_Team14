#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "gtest/gtest.h"
#include "base_testbench.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <string>
#include <vector>

#define RANDOM_PER_OP 200 // random operand pairs per opcode
#define SEED 1234         // fixed seed
#define MAX_REPORTED 10   // failures printed per test

unsigned int ticks = 0; // declared extern in base_testbench.h

enum AluCtrl : uint8_t
{
    ADD = 0x00,
    SLL = 0x01,
    SLT = 0x02,
    SLTU = 0x03,
    XOR = 0x04,
    SRL = 0x05,
    OR = 0x06,
    AND = 0x07,
    SUB = 0x08,
    SRA = 0x0D,
    MUL = 0x10,
    MULH = 0x11,
    MULHSU = 0x12,
    MULHU = 0x13,
    DIV = 0x14,
    DIVU = 0x15,
    REM = 0x16,
    REMU = 0x17
};

// refrence models
uint32_t arith_ref(AluCtrl op, uint32_t a, uint32_t b)
{
    const int32_t sa = static_cast<int32_t>(a);
    const int32_t sb = static_cast<int32_t>(b);
    const uint32_t shift = b & 31;
    const bool zero = (b == 0);
    const bool overflow = (a == 0x80000000u) && (b == 0xFFFFFFFFu);

    switch (op)
    {
    case ADD:
        return a + b;
    case SUB:
        return a - b;
    case SLL:
        return a << shift;
    case SLT:
        return (sa < sb) ? 1 : 0;
    case SLTU:
        return a < b ? 1 : 0;
    case XOR:
        return a ^ b;
    case SRL:
        return a >> shift;
    case SRA:
        return static_cast<uint32_t>(sa >> shift);
    case OR:
        return a | b;
    case AND:
        return a & b;
    case MUL:
        return static_cast<uint32_t>(static_cast<int64_t>(sa) * sb);
    case MULH:
        return static_cast<uint32_t>(
            static_cast<uint64_t>(static_cast<int64_t>(sa) * sb) >> 32);
    case MULHSU:
        return static_cast<uint32_t>(
            static_cast<uint64_t>(static_cast<int64_t>(sa) * static_cast<int64_t>(b)) >> 32);
    case MULHU:
        return static_cast<uint32_t>(
            (static_cast<uint64_t>(a) * b) >> 32);
    case DIV:
        if (zero)
            return 0xFFFFFFFFu;
        if (overflow)
            return 0x80000000u;
        return static_cast<uint32_t>(sa / sb); // C++ rounds toward zero, like RISC-V
    case DIVU:
        if (zero)
            return 0xFFFFFFFFu;
        return a / b;
    case REM:
        if (zero)
            return a;
        if (overflow)
            return 0;
        return static_cast<uint32_t>(sa % sb);
    case REMU:
        if (zero)
            return a;
        return a % b;
    }
    return 0;
}

static uint32_t branch_ref(uint32_t a, uint32_t b)
{
    const uint32_t eq = (a == b);
    const uint32_t lt = (static_cast<int32_t>(a) < static_cast<int32_t>(b));
    const uint32_t ltu = (a < b);
    return (eq << 3) | (lt << 1) | ltu;
}
