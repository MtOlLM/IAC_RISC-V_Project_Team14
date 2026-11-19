/*
 *  Verifies the register file (clocked write, async read).
 *  Exits with 0 on success.
 *
 *  Ports: AD1, AD2, AD3, clk, WE3, WD3 -> RD1, RD2, a0 (= x10)
 */

#include "testbench.h"
#include <cstdint>
#include <random>

unsigned int ticks = 0;

class RegfileTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        // Start low so each runSimulation() cycle contains a full rising edge
        top->clk = 0;
        top->AD1 = 0;
        top->AD2 = 0;
        top->AD3 = 0;
        top->WE3 = 0;
        top->WD3 = 0;
    }

    // Write one register over one clock cycle, then disable writes
    void write(uint8_t addr, uint32_t data)
    {
        top->AD3 = addr;
        top->WD3 = data;
        top->WE3 = 1;
        runSimulation(1);
        top->WE3 = 0;
    }

    uint32_t read1(uint8_t addr)
    {
        top->AD1 = addr;
        top->eval();
        return top->RD1;
    }

    uint32_t read2(uint8_t addr)
    {
        top->AD2 = addr;
        top->eval();
        return top->RD2;
    }
};

TEST_F(RegfileTestbench, WriteThenReadTest)
{
    write(5, 0xDEADBEEF);
    EXPECT_EQ(read1(5), 0xDEADBEEFu);
    EXPECT_EQ(read2(5), 0xDEADBEEFu);
}

TEST_F(RegfileTestbench, X0IsAlwaysZeroTest)
{
    write(0, 0xFFFFFFFF);
    EXPECT_EQ(read1(0), 0u);
    EXPECT_EQ(read2(0), 0u);
}

TEST_F(RegfileTestbench, NoWriteWhenWEIsLowTest)
{
    write(7, 111);
    top->AD3 = 7;
    top->WD3 = 222;
    top->WE3 = 0;
    runSimulation(1);
    EXPECT_EQ(read1(7), 111u);
}

TEST_F(RegfileTestbench, WriteOnlyOnClockEdgeTest)
{
    write(3, 1);
    // Change data with WE high but no clock edge -> must not update yet
    top->AD3 = 3;
    top->WD3 = 99;
    top->WE3 = 1;
    top->eval();
    EXPECT_EQ(read1(3), 1u);
    runSimulation(1);
    EXPECT_EQ(read1(3), 99u);
}

TEST_F(RegfileTestbench, TwoReadPortsIndependentTest)
{
    write(1, 10);
    write(2, 20);
    top->AD1 = 1;
    top->AD2 = 2;
    top->eval();
    EXPECT_EQ(top->RD1, 10u);
    EXPECT_EQ(top->RD2, 20u);
}

TEST_F(RegfileTestbench, A0MirrorsX10Test)
{
    write(10, 254);
    EXPECT_EQ(top->a0, 254u);
}

TEST_F(RegfileTestbench, RandomVsModelTest)
{
    std::mt19937 rng(14);
    uint32_t model[32] = {0};

    for (int i = 0; i < 1000; i++)
    {
        uint8_t addr = rng() % 32;
        uint32_t data = rng();
        write(addr, data);
        if (addr != 0)
            model[addr] = data;

        uint8_t r = rng() % 32;
        ASSERT_EQ(read1(r), model[r]) << "reg x" << (int)r;
        ASSERT_EQ(read2(addr), model[addr]) << "reg x" << (int)addr;
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
