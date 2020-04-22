; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64I
; RUN: llc -mtriple=riscv64 -mattr=+experimental-b -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IB
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbs -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IB

define i64 @sbclr(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    sbclr a0, a0, a1
;
; RV64IB-LABEL: sbclr:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    sbclr a0, a0, a1
; RV64IB-NEXT:    ret
  %sh_prom = trunc i64 %b to i32
  %shl = shl i32 1, %sh_prom
  %neg = xor i32 %shl, -1
  %conv = sext i32 %neg to i64
  %and = and i64 %conv, %a
  ret i64 %and
}

define i64 @sbset(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    sbset a0, a0, a1
;
; RV64IB-LABEL: sbset:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    sbset a0, a0, a1
; RV64IB-NEXT:    ret
  %sh_prom = trunc i64 %b to i32
  %shl = shl i32 1, %sh_prom
  %conv = sext i32 %shl to i64
  %or = or i64 %conv, %a
  ret i64 %or
}

define i64 @sbinv(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    sbinv a0, a0, a1
;
; RV64IB-LABEL: sbinv:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    sbinv a0, a0, a1
; RV64IB-NEXT:    ret
  %sh_prom = trunc i64 %b to i32
  %shl = shl i32 1, %sh_prom
  %conv = sext i32 %shl to i64
  %xor = xor i64 %conv, %a
  ret i64 %xor
}

define i64 @sbext(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    sbext a0, a0, a1
;
; RV64IB-LABEL: sbext:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    sbext a0, a0, a1
; RV64IB-NEXT:    ret
  %shr = lshr i64 %a, %b
  %and = and i64 %shr, 1
  ret i64 %and
}
