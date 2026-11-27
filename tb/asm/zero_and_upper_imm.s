/* tests if the x0 register stays zero
*  checks if lui and auipc puts everything in the right bits
*
*/

.text
.equ base_addr, 0x100

main:                           
    JAL     ra, test_x0 
    JAL     ra, test_lui
    JAL     ra, test_auipc
    ADDI    a0, zero, 1 
forever:
    J       forever 

test_x0: # check that writing to x0 is ignored. 0 stays 0
    ADDI    x0, x0, 123         
    LUI     x0, 0x12345 
    BNE     x0, zero, fail 
    RET

test_lui: # check LUI puts 20-bit value into bits and clears lower 12 bits
    LUI     t0, 0x80000 # load immediate
    LI      t1, 0x80000000
    BNE     t0, t1, fail

    LUI     t2, 0x12345 # add lower bits
    ADDI    t2, t2, 0x678
    LI      t3, 0x12345678
    BNE     t2, t3, fail
    RET

test_auipc: # check AUIPC
    AUIPC   t0, 0
    JAL     t1, _after_auipc
_after_auipc:
    BLTU    t1, t0, fail
    RET

fail:
    ADDI    a0, zero, 0
    J       forever