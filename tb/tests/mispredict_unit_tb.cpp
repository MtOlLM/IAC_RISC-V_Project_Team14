#include "base_testbench.h"
#include <cstdint>

const uint32_t mem_base = 0xBFC00000;

unsigned int ticks = 0;

struct Output
{
    bool mispreict;
    bool up_taken;
    uint32_t up_target;
};

enum Funt3EType : uint8_t
{
    BEQ = 0b000,
    BNE = 0b001,
    BLT = 0b100,
    BGE = 0b101,
    BLTU = 0b110,
    BGEU = 0b111
};

const uint8_t all_funct3[] = {BEQ, BNE, BLT, BGE, BLT, BGE, BLTU, BGEU};

static Output refrence(const uint8_t &branch_ctrl, const uint8_t &funct3E,
                       const uint32_t &alu_out, const uint32_t &pred_target,
                       const bool &jumpE, const bool &branchE, const bool &pred_taken)
{
    Output o;
    o.up_taken = false;
    o.up_target = mem_base;

        if (branchE)
    {
        o.up_target = alu_out;

        bool bit0, bit1, bit2;

        bit0 = branch_ctrl & 1;
        bit1 = (branch_ctrl >> 1) & 1;
        bit2 = (branch_ctrl >> 2) & 1;

        switch (funct3E)
        {
        case BEQ:
            o.up_taken = bit2;
            break;
        case BNE:
            o.up_taken = !bit2;
            break;
        case BLT:
            o.up_taken = bit1;
            break;
        case BGE:
            o.up_taken = !bit1;
            break;
        case BLTU:
            o.up_taken = bit0;
            break;
        case BGEU:
            o.up_taken = !bit0;
            break;
        default:
            break;
        }
    }
    else if (jumpE)
    {
        o.up_taken = true;
        o.up_target = alu_out;
    }

    o.mispreict = (o.up_taken != pred_taken) || (o.up_target != pred_target);
    
    return o;
}

//combinational logic, uses basetestbench
class MispredictionTest : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->branch_ctrl = 0;
        top->funct3E = 0;
        top->jumpE = 0;
        top->branchE = 0;
        top->alu_out = mem_base;
        top->pred_targetE = mem_base;
        top->pred_takenE = 0;

        top->eval();
    }

    Output dump_vals(uint8_t branch_ctrl, uint8_t funct3E,
                     uint32_t alu_out, uint32_t pred_target,
                     bool jumpE, bool branchE, bool pred_taken)
    {
        top->branch_ctrl = branch_ctrl;
        top->funct3E = funct3E;
        top->jumpE = jumpE;
        top->branchE = branchE;
        top->alu_out = alu_out;
        top->pred_targetE = pred_target;
        top->pred_takenE = pred_taken;

        top->eval();

        Output o;

        o.mispreict = static_cast<bool>(top->mispredict);
        o.up_taken = static_cast<bool>(top->up_taken);
        o.up_target = static_cast<uint32_t>(top->up_target);

        return o;
    }

    void verify_output(uint8_t branch_ctrl, uint8_t funct3E,
                       bool jumpE, bool branchE, bool pred_taken)
    {
        Output o_ref, o_sv;
        o_sv = dump_vals (branch_ctrl, funct3E, mem_base, mem_base, jumpE, branchE, pred_taken);
        o_ref = refrence(branch_ctrl, funct3E, mem_base, mem_base, jumpE, branchE, pred_taken);
        EXPECT_EQ(o_sv.mispreict, o_ref.mispreict);
        EXPECT_EQ(o_sv.up_taken, o_ref.up_taken);
        EXPECT_EQ(o_sv.up_target, o_ref.up_target);

        o_sv = dump_vals (branch_ctrl, funct3E, mem_base, mem_base+1, jumpE, branchE, pred_taken);
        o_ref = refrence(branch_ctrl, funct3E, mem_base, mem_base+1, jumpE, branchE, pred_taken);
        EXPECT_EQ(o_sv.mispreict, o_ref.mispreict);
        EXPECT_EQ(o_sv.up_taken, o_ref.up_taken);
        EXPECT_EQ(o_sv.up_target, o_ref.up_target);
    }


};

TEST_F(MispredictionTest, AllPossibleControlInputs)
{
    for(uint8_t branch_ctrl = 0; branch_ctrl < 0b1000; branch_ctrl++){
        for(uint8_t funct3E : all_funct3){
            for(uint8_t bools = 0; bools < 0b1000; bools++){
                bool jumpE = bools & 1;
                bool branchE = (bools >> 1) & 1;
                bool pred_taken = (bools >>2) & 1;
                if(jumpE && branchE) break;

                verify_output(branch_ctrl, funct3E, jumpE, branchE, pred_taken);
            }
        }
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}