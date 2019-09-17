# RUN: not llvm-mc -triple riscv64 -mattr=+b,c < %s 2>&1 | FileCheck %s

# Too many operands
c.not t0, t1 # CHECK: :[[@LINE]]:11: error: invalid operand for instruction
# Too many operands
c.zest.w t0, t1 # CHECK: :[[@LINE]]:14: error: invalid operand for instruction
