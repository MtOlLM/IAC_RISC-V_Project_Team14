#include "testbench.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

#define CYCLES 10000

unsigned int ticks = 0;

static std::vector<uint8_t> loadMem(const std::string &path)
{
    std::ifstream f(path);
    std::vector<uint8_t> v;
    std::string tok;
    while (f >> tok)
        v.push_back(static_cast<uint8_t>(std::stoul(tok, nullptr, 16)));
    return v;
}

class SineTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 1;
        top->rst = 1;
        runSimulation(2);
        top->rst = 0;
    }
};

TEST_F(SineTestbench, OutputsEverySampleInOrder)
{
    system("./compile.sh asm/program.S");
    std::vector<uint8_t> expected = loadMem("sine.mem");
    int idx = 0;

    for (int i = 0; i < CYCLES; i++)
    {
        runSimulation(1);
        //printf("output value: %d\n", top->a0);
        uint8_t output = (top->a0 & 0xFF);
        if (output == expected[idx])
        {
            idx++;
        }
        else if(output != expected[idx-1] && idx != 0){
            break;
        }
        if(idx >=256) break;
    }
    if (idx == 256)
    {
        SUCCEED();
        
    }else{
        printf("%d\n",idx);
        FAIL() << "Not all points are correct";
    }
}

// Note this is how we are going to test your CPU. Do not worry about this for
// now, as it requires a lot more instructions to function
// TEST_F(CpuTestbench, Return5Test)
// {
//     system("./compile.sh c/return_5.c");
//     runSimulation(100);
//     EXPECT_EQ(top->a0, 5);
// }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
