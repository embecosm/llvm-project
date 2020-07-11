; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32I
; RUN: llc -mtriple=riscv32 -mattr=+experimental-b -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbt -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB

define i32 @cmix(i32 %a, i32 %b, i32 %c) nounwind {
; RV32I-NOT:    cmix a0, a1, a0, a2
;
; RV32IB-LABEL: cmix:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    cmix a0, a1, a0, a2
; RV32IB-NEXT:    ret
  %and = and i32 %b, %a
  %neg = xor i32 %b, -1
  %and1 = and i32 %neg, %c
  %or = or i32 %and1, %and
  ret i32 %or
}

define i32 @cmov(i32 %a, i32 %b, i32 %c) nounwind {
; RV32I-NOT:    cmov a0, a1, a0, a2
;
; RV32IB-LABEL: cmov:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    cmov a0, a1, a0, a2
; RV32IB-NEXT:    ret
  %tobool = icmp eq i32 %b, 0
  %cond = select i1 %tobool, i32 %c, i32 %a
  ret i32 %cond
}

declare i32 @llvm.fshl.i32(i32, i32, i32)

define i32 @fshl(i32 %a, i32 %b, i32 %c) nounwind {
; RV32I-NOT:    fsl a0, a0, a2, a1
;
; RV32IB-LABEL: fshl:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    fsl a0, a0, a2, a1
; RV32IB-NEXT:    ret
  %1 = tail call i32 @llvm.fshl.i32(i32 %a, i32 %b, i32 %c)
  ret i32 %1
}

declare i32 @llvm.fshr.i32(i32, i32, i32)

define i32 @fshr(i32 %a, i32 %b, i32 %c) nounwind {
; RV32I-NOT:    fsr a0, a0, a2, a1
;
; RV32IB-LABEL: fshr:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    fsr a0, a0, a2, a1
; RV32IB-NEXT:    ret
  %1 = tail call i32 @llvm.fshr.i32(i32 %a, i32 %b, i32 %c)
  ret i32 %1
}
