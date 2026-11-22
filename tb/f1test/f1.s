.text
.globl main

# a0: output, a1: delay count
# t0: lights remaining, t1: light pattern

main:
    addi    a0, zero, 0x0        # All lights off

mloop:
    addi    a1, zero, 0x100      # Wait before starting
    jal     ra, delay
    addi    t0, zero, 0x8        # Eight lights
    addi    t1, zero, 0x0

iloop:
    slli    t1, t1, 1           # Add the next light
    ori     t1, t1, 0x1
    addi    a0, t1, 0           # Update output
    addi    t0, t0, -1
    beq     t0, zero, all_on

    addi    a1, zero, 0x100      # Wait between lights
    jal     ra, delay
    jal     zero, iloop

all_on:
    addi    a1, zero, 0x200      # Hold all lights on
    jal     ra, delay
    addi    a0, zero, 0x0        # Lights out
    jal     zero, mloop

delay:
    addi    a1, a1, -1
    bne     a1, zero, delay
    jalr    zero, 0(ra)         # Return