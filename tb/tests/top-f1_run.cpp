#include "gtest/gtest.h"
#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"  

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class f1Test : public ::testing::Test
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

TEST_F(f1Test, TwoSequences)
{
    // Check two complete rounds.
    const std::array<unsigned int, 19> expected = {
        0,
        1, 3, 7, 15, 31, 63, 127, 255, 0,
        1, 3, 7, 15, 31, 63, 127, 255, 0
    };

    const unsigned int MAX_CYCLES = 30000;  // raise if your delays are longer

    unsigned int previous = 0;
    unsigned int last_change = 0;
    std::size_t next = 1;

    vbdBar(0);

    for (unsigned int cycle = 1; cycle <= MAX_CYCLES; cycle++)
    {
        run(1);
        const unsigned int output = top->a0;

        if (output == previous)
            continue;

        // Check each new light pattern.
        ASSERT_EQ(output, expected[next])
            << "Wrong pattern at cycle " << cycle;

        // Check that each pattern was held long enough.
        const unsigned int held = cycle - last_change;
        if (next > 1)
        {
            const unsigned int minimum = (previous == 255) ? 400 : 200;
            ASSERT_GE(held, minimum)
                << "Delay too short at cycle " << cycle;
        }

        std::cout << "Cycle " << cycle
                  << ": a0 = " << output
                  << " (previous held for " << held << " cycles)";
        if (previous == 255)
            std::cout << "  <-- lights-out delay";
        std::cout << '\n';

        vbdBar(output & 0xFF);
        vbdCycle(cycle);

        previous = output;
        last_change = cycle;
        next++;

        if (next == expected.size())
            return;
    }

    FAIL() << "Two F1 sequences did not finish within " << MAX_CYCLES << " cycles";
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
