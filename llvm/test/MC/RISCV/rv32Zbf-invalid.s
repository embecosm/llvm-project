# RUN: not llvm-mc -triple riscv32 -mattr=+b,bf < %s 2>&1 | FileCheck %s

# Too few operands
bfp s0, s1 # CHECK: :[[@LINE]]:1: error: too few operands for instruction
