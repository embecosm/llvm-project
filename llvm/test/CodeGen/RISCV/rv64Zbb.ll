; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64I
; RUN: llc -mtriple=riscv64 -mattr=+experimental-b -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IB
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbb -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IB

define i64 @slo(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    slo a0, a0, a1
;
; RV64IB-LABEL: slo:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    slo a0, a0, a1
; RV64IB-NEXT:    ret
  %neg = xor i64 %a, -1
  %shl = shl i64 %neg, %b
  %neg1 = xor i64 %shl, -1
  ret i64 %neg1
}

define i64 @sro(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    sro a0, a0, a1
;
; RV64IB-LABEL: sro:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    sro a0, a0, a1
; RV64IB-NEXT:    ret
  %neg = xor i64 %a, -1
  %shr = lshr i64 %neg, %b
  %neg1 = xor i64 %shr, -1
  ret i64 %neg1
}

declare i64 @llvm.ctlz.i64(i64, i1)

define i64 @ctlz_i64(i64 %a) nounwind {
; RV64I-NOT:    clz a0, a0
;
; RV64IB-LABEL: ctlz_i64:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    beqz a0, .LBB2_2
; RV64IB-NEXT:  # %bb.1: # %cond.false
; RV64IB-NEXT:    clz a0, a0
; RV64IB-NEXT:    ret
; RV64IB-NEXT:  .LBB2_2:
; RV64IB-NEXT:    addi a0, zero, 64
; RV64IB-NEXT:    ret
  %1 = call i64 @llvm.ctlz.i64(i64 %a, i1 false)
  ret i64 %1
}

declare i64 @llvm.cttz.i64(i64, i1)

define i64 @cttz_i64(i64 %a) nounwind {
; RV64I-NOT:    ctz a0, a0
;
; RV64IB-LABEL: cttz_i64:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    beqz a0, .LBB3_2
; RV64IB-NEXT:  # %bb.1: # %cond.false
; RV64IB-NEXT:    ctz a0, a0
; RV64IB-NEXT:    ret
; RV64IB-NEXT:  .LBB3_2:
; RV64IB-NEXT:    addi a0, zero, 64
; RV64IB-NEXT:    ret
  %1 = call i64 @llvm.cttz.i64(i64 %a, i1 false)
  ret i64 %1
}

declare i64 @llvm.ctpop.i64(i64)

define i64 @ctpop_i64(i64 %a) nounwind {
; RV64I-NOT:    pcnt a0, a0
;
; RV64IB-LABEL: ctpop_i64:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    pcnt a0, a0
; RV64IB-NEXT:    ret
  %1 = call i64 @llvm.ctpop.i64(i64 %a)
  ret i64 %1
}

define i64 @sextb(i64 %a) nounwind {
; RV64I-NOT:    sext.b a0, a0
;
; RV64IB-LABEL: sextb:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    sext.b a0, a0
; RV64IB-NEXT:    ret
  %shl = shl i64 %a, 56
  %shr = ashr exact i64 %shl, 56
  ret i64 %shr
}

define i64 @sexth(i64 %a) nounwind {
; RV64I-NOT:    sext.h a0, a0
;
; RV64IB-LABEL: sexth:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    sext.h a0, a0
; RV64IB-NEXT:    ret
  %shl = shl i64 %a, 48
  %shr = ashr exact i64 %shl, 48
  ret i64 %shr
}

define i64 @min(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    min a0, a0, a1
;
; RV64IB-LABEL: min:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    min a0, a0, a1
; RV64IB-NEXT:    ret
  %cmp = icmp slt i64 %a, %b
  %cond = select i1 %cmp, i64 %a, i64 %b
  ret i64 %cond
}

define i64 @max(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    max a0, a0, a1
;
; RV64IB-LABEL: max:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    max a0, a0, a1
; RV64IB-NEXT:    ret
  %cmp = icmp sgt i64 %a, %b
  %cond = select i1 %cmp, i64 %a, i64 %b
  ret i64 %cond
}

define i64 @minu(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    minu a0, a0, a1
;
; RV64IB-LABEL: minu:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    minu a0, a0, a1
; RV64IB-NEXT:    ret
  %cmp = icmp ult i64 %a, %b
  %cond = select i1 %cmp, i64 %a, i64 %b
  ret i64 %cond
}

define i64 @maxu(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    maxu a0, a0, a1
;
; RV64IB-LABEL: maxu:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    maxu a0, a0, a1
; RV64IB-NEXT:    ret
  %cmp = icmp ugt i64 %a, %b
  %cond = select i1 %cmp, i64 %a, i64 %b
  ret i64 %cond
}

define i64 @addiwu(i64 %a) nounwind {
; RV64I-NOT:    addiwu a0, a0, 1
;
; RV64IB-LABEL: addiwu:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    addiwu a0, a0, 1
; RV64IB-NEXT:    ret
  %conv = add i64 %a, 1
  %conv1 = and i64 %conv, 4294967295
  ret i64 %conv1
}

define i64 @addwu(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    addwu a0, a1, a0
;
; RV64IB-LABEL: addwu:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    addwu a0, a1, a0
; RV64IB-NEXT:    ret
  %add = add i64 %b, %a
  %conv1 = and i64 %add, 4294967295
  ret i64 %conv1
}

define i64 @subwu(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    subwu a0, a0, a1
;
; RV64IB-LABEL: subwu:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    subwu a0, a0, a1
; RV64IB-NEXT:    ret
  %sub = sub i64 %a, %b
  %conv1 = and i64 %sub, 4294967295
  ret i64 %conv1
}

define i64 @adduw(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    addu.w a0, a0, a1
;
; RV64IB-LABEL: adduw:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    addu.w a0, a0, a1
; RV64IB-NEXT:    ret
  %and = and i64 %b, 4294967295
  %add = add i64 %and, %a
  ret i64 %add
}

define i64 @subuw(i64 %a, i64 %b) nounwind {
; RV64I-NOT:    subu.w a0, a0, a1
;
; RV64IB-LABEL: subuw:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    subu.w a0, a0, a1
; RV64IB-NEXT:    ret
  %and = and i64 %b, 4294967295
  %sub = sub i64 %a, %and
  ret i64 %sub
}
