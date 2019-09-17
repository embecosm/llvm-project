# RUN: not llvm-mc -triple riscv64 -mattr=+b,bf < %s 2>&1 | FileCheck %s

# Too few operands
bfpw s0, s1 # CHECK: :[[@LINE]]:1: error: too few operands for instruction
