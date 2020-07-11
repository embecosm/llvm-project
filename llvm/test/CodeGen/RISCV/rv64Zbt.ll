; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64I
; RUN: llc -mtriple=riscv64 -mattr=+experimental-b -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IB
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbt -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IB

define i64 @cmix(i64 %a, i64 %b, i64 %c) nounwind {
; RV64I-NOT:    cmix a0, a1, a0, a2
;
; RV64IB-LABEL: cmix:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    cmix a0, a1, a0, a2
; RV64IB-NEXT:    ret
  %and = and i64 %b, %a
  %neg = xor i64 %b, -1
  %and1 = and i64 %neg, %c
  %or = or i64 %and1, %and
  ret i64 %or
}

define i64 @cmov(i64 %a, i64 %b, i64 %c) nounwind {
; RV64I-NOT:    cmov a0, a1, a0, a2
;
; RV64IB-LABEL: cmov:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    cmov a0, a1, a0, a2
; RV64IB-NEXT:    ret
  %tobool = icmp eq i64 %b, 0
  %cond = select i1 %tobool, i64 %c, i64 %a
  ret i64 %cond
}

declare i64 @llvm.fshl.i64(i64, i64, i64)

define i64 @fshl(i64 %a, i64 %b, i64 %c) nounwind {
; RV64I-NOT:    fsl a0, a0, a2, a1
;
; RV64IB-LABEL: fshl:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    fsl a0, a0, a2, a1
; RV64IB-NEXT:    ret
  %1 = tail call i64 @llvm.fshl.i64(i64 %a, i64 %b, i64 %c)
  ret i64 %1
}

declare i64 @llvm.fshr.i64(i64, i64, i64)

define i64 @fshr(i64 %a, i64 %b, i64 %c) nounwind {
; RV64I-NOT:    fsr a0, a0, a2, a1
;
; RV64IB-LABEL: fshr:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    fsr a0, a0, a2, a1
; RV64IB-NEXT:    ret
  %1 = tail call i64 @llvm.fshr.i64(i64 %a, i64 %b, i64 %c)
  ret i64 %1
}
