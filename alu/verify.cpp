#include "gtest/gtest.h"
#include "Vdut.h"
#include "verilated.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class aluTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        initializeInputs();
    }

    void TearDown() override
    {
    }

    void initializeInputs()
    {
        top->ALUctrl = 0;
        top->ALUOp1 = 0;
        top->ALUOp2 = 0;
    }

    int run(int ctrl, int op1, int op2)
    {
        top->ALUctrl = ctrl;
        top->ALUOp1 = op1;
        top->ALUOp2 = op2;
        top->eval();
        return top->ALUout;
    }
};

TEST_F(aluTest, addTwo)
{
    EXPECT_EQ(run(0b000, 1, 3), 4u);
}

TEST_F(aluTest, subTwo)
{
    EXPECT_EQ(run(0b001, 5, 3), 2u);
}

TEST_F(aluTest, subTwoGoesNeg)
{
    EXPECT_EQ(run(0b001, 7, 9), 0xFFFFFFFEu);
}

TEST_F(aluTest, subTwoGiveZero)
{
    EXPECT_EQ(run(0b001, 2, 2), 0u);
}

TEST_F(aluTest, wrap32Bit)
{
    EXPECT_EQ(run(0b000, 0xFFFFFFFF, 1), 0u);
}

TEST_F(aluTest, bitwiseAnd)
{
    EXPECT_EQ(run(0b010, 0xF0F0, 0xFF00), 0xF000u);
}

TEST_F(aluTest, bitwiseOr)
{
    EXPECT_EQ(run(0b011, 0xF0F0, 0xFF00), 0xFFF0u);
}

TEST_F(aluTest, equalYes)
{
    run(0b000, 123, 123);
    EXPECT_EQ(top->eq, 1);
}

TEST_F(aluTest, equalNo)
{
    run(0b000, 123, 12313);
    EXPECT_EQ(top->eq, 0);
}

TEST_F(aluTest, sltTrue)
{
    EXPECT_EQ(run(0b101, 3, 5), 1u);
}

TEST_F(aluTest, sltFalse)
{
    EXPECT_EQ(run(0b101, 5, 3), 0u);
}

TEST_F(aluTest, sltEqual)
{
    EXPECT_EQ(run(0b101, 4, 4), 0u);
}

TEST_F(aluTest, sltMostNegVSMostPos)
{
    EXPECT_EQ(run(0b101, 0x80000000, 0x7FFFFFFF), 1u);
}

int main(int argc, char **argv)
{
    top = new Vdut;

    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    top->final();
    delete top;

    return res;
}
