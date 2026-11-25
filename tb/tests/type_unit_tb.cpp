#include "base_testbench.h"
#include <cstdint>

const uint8_t ra = 1;
const uint8_t t0 = 5;

unsigned int ticks = 0;

enum BranchType : uint8_t
{
    BR_COND = 0b000,
    BR_JUMP = 0b001,
    BR_CALL = 0b010,
    BR_RET = 0b011,
    BR_CORO = 0b100
};

static uint8_t refrence(const uint8_t &rs1E, const uint8_t &rdE,
                       const bool &jalrE, const bool &branchE)
{
    bool link_rs1, link_rd;

    link_rs1 = (rs1E == ra) || (rs1E == t0);
    link_rd = (rdE == ra) || (rdE == t0);

    //the logic here is not simplified so it is more likely to be correct
    //a proper testbench should probably do something like this
    //instead of just wrting the same code again in C++
    if(branchE) return BR_COND;
    if(jalrE){
        if(!link_rd && link_rs1){
            return BR_RET;
        }
        if(link_rd && !link_rs1){
            return BR_CALL;
        }
        if(link_rd && link_rs1){
            if(rs1E == rdE) return BR_CALL;
            else return BR_CORO;
        }
    }

    if(link_rd) return BR_CALL;
    
    return BR_JUMP;
}

// combinational logic, uses basetestbench
class TypeTest : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->rs1E = 0;
        top->rdE = 0;
        top->jalrE = 0;
        top->branchE = 0;

        top->eval();
    }

    uint8_t dump_vals(const uint8_t &rs1E, const uint8_t &rdE,
                       const bool &jalrE, const bool &branchE)
    {
        top->rs1E = rs1E;
        top->rdE = rdE;
        top->jalrE = jalrE;
        top->branchE = branchE;

        top->eval();

        return static_cast<uint8_t>(top->up_type);
    }

    void verify_output(const uint8_t &rs1E, const uint8_t &rdE,
                       const bool &jalrE, const bool &branchE)
    {
        uint8_t o_ref, o_sv;
        o_ref = refrence(rs1E, rdE, jalrE, branchE);
        o_sv = dump_vals(rs1E, rdE, jalrE, branchE);
        EXPECT_EQ(o_sv, o_ref);

    }
};

TEST_F(TypeTest, AllPossibleInputs)
{
    for (uint8_t rs1E = 0; rs1E < 32; rs1E++)
    {
        for (uint8_t rdE = 0; rdE < 32; rdE++)
        {
            verify_output(rs1E, rdE, false, false);
            verify_output(rs1E, rdE, false, true);
            verify_output(rs1E, rdE, true, false);
        }
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}