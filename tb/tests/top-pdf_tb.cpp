#include "gtest/gtest.h"
#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"
#include <iostream>
#include <vector>
#include <algorithm>

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;
bool complete = false;

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
        run(2);
        top->rst = 0;
    }

    // Runs the simulation for a clock cycle, evaluates the DUT, dumps waveform.
    void runSimulation()
    {
        for (int clk = 0; clk < 2; clk++)
        {
            top->eval();
            tfp->dump(2 * ticks + clk);
            top->clk = !top->clk;
        }
        ticks++;

        if (Verilated::gotFinish())
        {
            complete = true;
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

// select wave you want from reference folder
// put into tb folder, and rename as data.hex
TEST_F(cpuTest, pdfTest)
{
    const int BUILD_CYCLES = 500'000;
    const int CYCLES = 4; // per sample
    const int NO_SAMPLES = 256 * 4;

    run(BUILD_CYCLES);

    for (int i = 0; i < NO_SAMPLES; i++)
    {
        run(CYCLES);
        uint32_t value = top->a0;
        ASSERT_LE(value, 255u) << "a0 out of range:: " << ticks;
        vbdPlot(int(value), 0, 255);
        vbdCycle(ticks);
    }
}

int main(int argc, char **argv)
{
    top = new Vdut;
    tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    testing::InitGoogleTest(&argc, argv);
    if (vbdOpen() != 1) {
        tfp->close();
        top->final();
        delete tfp;
        delete top;
        return -1;
    }
    vbdHeader("PDF");

    auto res = RUN_ALL_TESTS();

    vbdClose();
    top->final();
    tfp->close();

    delete top;
    delete tfp;

    return res;
}
