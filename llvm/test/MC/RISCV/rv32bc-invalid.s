# RUN: not llvm-mc -triple riscv32 -mattr=+b,c < %s 2>&1 | FileCheck %s

# Too many operands
c.not s0, s1 # CHECK: :[[@LINE]]:11: error: invalid operand for instruction
