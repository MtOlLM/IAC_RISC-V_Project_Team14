#!/bin/bash
set -e
cd "$(dirname "$0")"
RTL=../../rtl

# cleanup
rm -rf obj_dir
rm -f *.vcd

# Translate Verilog -> C++ including testbench
verilator -Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL --trace \
          -cc $RTL/top.sv $RTL/ROM.sv $RTL/control_unit.sv \
              $RTL/sign_ext.sv $RTL/regfile.sv $RTL/mux.sv \
              $RTL/mux4.sv $RTL/alu.sv $RTL/program_counter.sv \
              $RTL/mcu.sv $RTL/RAM.sv \
          --top-module top \
          --exe verify.cpp \
          --prefix "Vdut" \
          -o Vdut \
          -CFLAGS "-std=c++17" \
          -LDFLAGS "-lgtest -lgtest_main -lpthread"

# Build C++ project with automatically generated Makefile
make -j -C obj_dir/ -f Vdut.mk

# Run executable simulation file
./obj_dir/Vdut