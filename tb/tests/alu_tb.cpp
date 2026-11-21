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
static uint32_t arith_ref(AluCtrl op, uint32_t a, uint32_t b)
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

static const uint32_t EDGE_VALUES[] = {
    0x00000000, 0x00000001, 0x00000002, 0x00000003,
    0x0000001F, 0x00000020, 0x00000021,
    0x7FFFFFFF, 0x80000000, 0x80000001,
    0xFFFFFFFE, 0xFFFFFFFF,
    0x12345678, 0xDEADBEEF, 0x0000FFFF, 0xFFFF0000};

static std::vector<std::pair<uint32_t, uint32_t>> operandPairs()
{
    std::vector<std::pair<uint32_t, uint32_t>> pairs;
    //32-bit random number generator
    std::mt19937 rng(SEED);

    for (uint32_t a : EDGE_VALUES)
        for (uint32_t b : EDGE_VALUES)
            pairs.push_back({a, b});

    for (int i = 0; i < RANDOM_PER_OP; i++)
        pairs.push_back({rng(), rng()});

    // small divisors
    const uint32_t small[] = {1, 2, 3, 0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFE};
    for (int i = 0; i < 50; i++)
        pairs.push_back({rng(), small[rng() % 6]});

    return pairs;
}

//ALU has no clock, so derive from BaseTestbench
class AluTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->ALUctrl = 0;
        top->ALUOp1 = 0;
        top->ALUOp2 = 0;
        top->eval();
    }

    //ALU is combinational: apply inputs, evaluate, dump one time step
    void apply(AluCtrl op, uint32_t a, uint32_t b)
    {
        top->ALUctrl = op;
        top->ALUOp1 = a;
        top->ALUOp2 = b;
        top->eval();
        tfp->dump(ticks++);
    }

    // Run every operand pair through one instruction and compare ALUout
    void runOp(AluCtrl op, const char *name)
    {
        int failures = 0;

        for (const auto &p : operandPairs()){
            const int a = p.first;
            const int b = p.second;

            apply(op, a, b);
            const uint32_t expected = arith_ref(op, a, b);

            if (top->ALUout != expected){
                failures++;
                if (failures <= MAX_REPORTED)
                    FAIL() << name << " " << a << ", " << b
                                   << ": expected " << expected
                                   << ", got " << top->ALUout;
            }
        }
    }
};

// RV32I operations
TEST_F(AluTestbench, Add) { runOp(ADD, "ADD"); }
TEST_F(AluTestbench, Sub) { runOp(SUB, "SUB"); }
TEST_F(AluTestbench, Sll) { runOp(SLL, "SLL"); }
TEST_F(AluTestbench, Slt) { runOp(SLT, "SLT"); }
TEST_F(AluTestbench, Sltu) { runOp(SLTU, "SLTU"); }
TEST_F(AluTestbench, Xor) { runOp(XOR, "XOR"); }
TEST_F(AluTestbench, Srl) { runOp(SRL, "SRL"); }
TEST_F(AluTestbench, Sra) { runOp(SRA, "SRA"); }
TEST_F(AluTestbench, Or) { runOp(OR, "OR"); }
TEST_F(AluTestbench, And) { runOp(AND, "AND"); }

// M extension
TEST_F(AluTestbench, Mul) { runOp(MUL, "MUL"); }
TEST_F(AluTestbench, Mulh) { runOp(MULH, "MULH"); }
TEST_F(AluTestbench, Mulhsu) { runOp(MULHSU, "MULHSU"); }
TEST_F(AluTestbench, Mulhu) { runOp(MULHU, "MULHU"); }
TEST_F(AluTestbench, Div) { runOp(DIV, "DIV"); }
TEST_F(AluTestbench, Divu) { runOp(DIVU, "DIVU"); }
TEST_F(AluTestbench, Rem) { runOp(REM, "REM"); }
TEST_F(AluTestbench, Remu) { runOp(REMU, "REMU"); }

// Branch flags test
TEST_F(AluTestbench, BranchFlags)
{
    int failures = 0;

    for (const auto &p : operandPairs()){
        const int a = p.first;
        const int b = p.second;

        //ADD here does not matter since the branch flag only depends on the oprands
        apply(ADD, a, b);
        const uint32_t expected = branch_ref(a, b);

        if (top->branch_ctrl != expected){
            failures++;
            if (failures <= MAX_REPORTED)
                FAIL() << "branch_ctrl " << a << ", " << b
                                         << ": expected  " << expected
                                         << ", got " << top->branch_ctrl;
        }
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}