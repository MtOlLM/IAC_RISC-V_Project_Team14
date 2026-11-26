.text
.globl main

.equ DELAY_TIME, 100
.equ UPPER_SEED, 0x654
.equ LOWER_SEED, 0x321

# a0: output, a1: delay count
# s0: random seed
# t0: lights remaining, t1: light pattern

main: 
    addi a0, zero, 0x0
    lui  s0, UPPER_SEED
    addi s0, s0, LOWER_SEED

mloop:
    addi a1, zero, DELAY_TIME
    jal  ra, delay
    addi t0, zero, 0x8
    addi t1, zero, 0x0

iloop:
    slli t1, t1, 0x1
    ori  t1, t1, 0x1
    addi a0, t1, 0
    addi t0, t0, -1
    beq  t0, zero, all_on

    addi a1, zero, DELAY_TIME
    jal  ra, delay
    jal  zero, iloop

all_on:
    jal  ra, rand
    andi a1, s0, 0x3FF   # keep the lower 10 bits
    addi a1, a1, 0x100  # add a min
    jal  ra, delay
    addi a0, zero, 0x0
    jal  zero, mloop

rand:
    slli a1, s0, 13
    xor  s0, s0, a1
    srli a1, s0, 17
    xor  s0, s0, a1
    slli a1, s0, 5
    xor  s0, s0, a1
    jalr zero, 0(ra)

# delay for a1 countdowns
delay:
    addi    a1, a1, -1
    bne     a1, zero, delay
    jalr    zero, 0(ra)

