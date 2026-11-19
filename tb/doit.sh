#!/bin/bash

# This script runs the testbench
# Usage: ./doit.sh <file1.cpp> <file2.cpp>

# Constants
SCRIPT_DIR=$(dirname "$(realpath "$0")")
OBJ_DIR="obj_dir"

# GNU Make cannot handle paths containing spaces, so if the project lives in
# one, access it through a space-free symlink and build in /tmp instead
if [[ "$SCRIPT_DIR" == *" "* ]]; then
    LINK="/tmp/iac_project_$(id -u)"
    ln -sfn "$(dirname "$SCRIPT_DIR")" "$LINK"
    OBJ_DIR="/tmp/iac_obj_dir_$(id -u)"
    args=()
    for f in "$@"; do args+=("$LINK/tb/tests/$(basename "$f")"); done
    set -- "${args[@]}"
    SCRIPT_DIR="$LINK/tb"
fi

TEST_FOLDER="$SCRIPT_DIR/tests"
RTL_FOLDER="$SCRIPT_DIR/../rtl"
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)

# Homebrew (Apple Silicon) installs gtest outside the default search paths
EXTRA_CFLAGS=""
EXTRA_LDFLAGS=""
if [ -d /opt/homebrew/include/gtest ]; then
    EXTRA_CFLAGS="-I/opt/homebrew/include -std=c++17"
    EXTRA_LDFLAGS="-L/opt/homebrew/lib"
fi

# Variables
passes=0
fails=0

# Handle terminal arguments
if [[ $# -eq 0 ]]; then
    # If no arguments provided, run all tests
    files=("${TEST_FOLDER}"/*.cpp)
else
    # If arguments provided, use them as input files
    files=("$@")
fi

# Cleanup
rm -rf "$OBJ_DIR"

cd "$SCRIPT_DIR"

# Iterate through files
for file in "${files[@]}"; do
    name=$(basename "$file" _tb.cpp | cut -f1 -d\-)
    
    # If verify.cpp -> we are testing the top module
    if [ "$name" == "verify.cpp" ] || [ "$name" == "sine_verify.cpp" ]; then
        name="top"
    fi

    # Translate Verilog -> C++ including testbench
    verilator   -Wall --trace \
                -cc "${RTL_FOLDER}/${name}.sv" \
                --exe "${file}" \
                -y "${RTL_FOLDER}" \
                --prefix "Vdut" --Mdir "$OBJ_DIR" \
                -o Vdut \
                -CFLAGS "${EXTRA_CFLAGS}" \
                -LDFLAGS "${EXTRA_LDFLAGS} -lgtest -lgtest_main -lpthread" \

    # Build C++ project with automatically generated Makefile
    make -j -C "$OBJ_DIR" -f Vdut.mk
    
    # Run executable simulation file
    "$OBJ_DIR/Vdut"
    
    # Check if the test succeeded or not
    if [ $? -eq 0 ]; then
        ((passes++))
    else
        ((fails++))
    fi
    
done

# Exit as a pass or fail (for CI purposes)
if [ $fails -eq 0 ]; then
    echo "${GREEN}Success! All ${passes} test(s) passed!"
    exit 0
else
    total=$((passes + fails))
    echo "${RED}Failure! Only ${passes} test(s) passed out of ${total}."
    exit 1
fi