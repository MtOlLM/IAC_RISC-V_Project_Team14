/*
 *  Verifies the ALU (combinational) against a C++ reference model.
 *  Exits with 0 on success.
 *
 *  ALUctrl encoding (from alu.sv):
 *    000 add | 001 sub | 010 and | 011 or | 101 slt | others -> 0
 */

#include "base_testbench.h"
#include <cstdint>
#include <random>

unsigned int ticks = 0;

class AluTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->ALUOp1 = 0;
        top->ALUOp2 = 0;
        top->ALUctrl = 0;
        // outputs: ALUout, eq
    }

    // Drive inputs and settle the combinational logic
    void apply(uint32_t a, uint32_t b, uint8_t ctrl)
    {
        top->ALUOp1 = a;
        top->ALUOp2 = b;
        top->ALUctrl = ctrl;
        top->eval();
    }

    // Golden reference model
    static uint32_t model(uint32_t a, uint32_t b, uint8_t ctrl)
    {
        switch (ctrl)
        {
        case 0b000: return a + b;
        case 0b001: return a - b;
        case 0b010: return a & b;
        case 0b011: return a | b;
        case 0b101: return (int32_t)a < (int32_t)b; // RISC-V slt is signed
        default:    return 0;
        }
    }
};

// ---------- Directed tests ----------

TEST_F(AluTestbench, AddTest)
{
    apply(5, 7, 0b000);
    EXPECT_EQ(top->ALUout, 12u);
}

TEST_F(AluTestbench, AddOverflowWrapsTest)
{
    apply(0xFFFFFFFF, 1, 0b000);
    EXPECT_EQ(top->ALUout, 0u);
}

TEST_F(AluTestbench, SubTest)
{
    apply(10, 3, 0b001);
    EXPECT_EQ(top->ALUout, 7u);
}

TEST_F(AluTestbench, SubNegativeTest)
{
    apply(3, 10, 0b001);
    EXPECT_EQ(top->ALUout, (uint32_t)-7);
}

TEST_F(AluTestbench, AndTest)
{
    apply(0xF0F0F0F0, 0xFF00FF00, 0b010);
    EXPECT_EQ(top->ALUout, 0xF000F000u);
}

TEST_F(AluTestbench, OrTest)
{
    apply(0xF0F0F0F0, 0x0F0F0000, 0b011);
    EXPECT_EQ(top->ALUout, 0xFFFFF0F0u);
}

TEST_F(AluTestbench, SltTrueTest)
{
    apply(2, 9, 0b101);
    EXPECT_EQ(top->ALUout, 1u);
}

TEST_F(AluTestbench, SltFalseTest)
{
    apply(9, 2, 0b101);
    EXPECT_EQ(top->ALUout, 0u);
}

TEST_F(AluTestbench, SltSignedTest)
{
    // -1 < 1 must be true for signed slt
    apply(0xFFFFFFFF, 1, 0b101);
    EXPECT_EQ(top->ALUout, 1u);
}

TEST_F(AluTestbench, UnusedCtrlGivesZeroTest)
{
    for (uint8_t c : {0b100, 0b110, 0b111})
    {
        apply(0x12345678, 0x9ABCDEF0, c);
        EXPECT_EQ(top->ALUout, 0u) << "ALUctrl=" << (int)c;
    }
}

// eq drives the branch decision (bne in program.S)
TEST_F(AluTestbench, EqFlagTest)
{
    apply(42, 42, 0b001);
    EXPECT_EQ(top->eq, 1);
    apply(42, 43, 0b001);
    EXPECT_EQ(top->eq, 0);
}

// ---------- Randomised test vs golden model ----------

TEST_F(AluTestbench, RandomVsModelTest)
{
    std::mt19937 rng(14); // fixed seed -> reproducible failures
    const uint8_t ops[] = {0b000, 0b001, 0b010, 0b011, 0b101};

    for (int i = 0; i < 2000; i++)
    {
        uint32_t a = rng(), b = rng();
        uint8_t ctrl = ops[i % 5];
        apply(a, b, ctrl);
        ASSERT_EQ(top->ALUout, model(a, b, ctrl))
            << "a=0x" << std::hex << a << " b=0x" << b << " ctrl=" << (int)ctrl;
        ASSERT_EQ(top->eq, a == b);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
