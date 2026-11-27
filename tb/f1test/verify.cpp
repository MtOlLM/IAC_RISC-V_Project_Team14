#include "gtest/gtest.h"
#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"  

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class cpuTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        initializeInputs();
        runReset();
    }

    void TearDown() override
    {
    }

    void initializeInputs()
    {
        top->clk = 0;
        top->rst = 0;
    }

    void runReset()
    {
        top->rst = 1;
        runSimulation();
        top->rst = 0;
    }

    // Runs the simulation for a clock cycle, evaluates the DUT, dumps waveform.
    void runSimulation()
    {
        for (int clk = 0; clk < 2; clk++)
        {
            top->eval();
            tfp->dump(2 * ticks + clk);
            vbdBar(top->a0 & 0xFF);
            top->clk = !top->clk;
        }
        ticks++;

        if (Verilated::gotFinish())
        {
            exit(0);
        }
    }

    void run(int cycles)
    {
        for (int i = 0; i < cycles; i++)
            runSimulation();
    }

    void expectValue(uint32_t expected)
    {
        EXPECT_EQ(top->a0, expected);
    }
};

TEST_F(cpuTest, program)
{
    run(15000);
}

int main(int argc, char **argv)
{
    top = new Vdut;
    tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    testing::InitGoogleTest(&argc, argv);
    if (vbdOpen() != 1) return -1;
    auto res = RUN_ALL_TESTS();

    top->final();
    tfp->close();

    delete top;
    delete tfp;

    vbdClose();
    return res;
}
