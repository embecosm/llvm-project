; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32I
; RUN: llc -mtriple=riscv32 -mattr=+experimental-b -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbp -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB

define i32 @gorc1(i32 %a) nounwind {
; RV32I-NOT:    orc.p a0, a0
;
; RV32IB-LABEL: gorc1:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    orc.p a0, a0
; RV32IB-NEXT:    ret
  %and = shl i32 %a, 1
  %shl = and i32 %and, -1431655766
  %and1 = lshr i32 %a, 1
  %shr = and i32 %and1, 1431655765
  %or = or i32 %shr, %a
  %or2 = or i32 %or, %shl
  ret i32 %or2
}

define i32 @gorc2(i32 %a) nounwind {
; RV32I-NOT:    orc2.n a0, a0
;
; RV32IB-LABEL: gorc2:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    orc2.n a0, a0
; RV32IB-NEXT:    ret
  %and = shl i32 %a, 2
  %shl = and i32 %and, -858993460
  %and1 = lshr i32 %a, 2
  %shr = and i32 %and1, 858993459
  %or = or i32 %shr, %a
  %or2 = or i32 %or, %shl
  ret i32 %or2
}

define i32 @gorc4(i32 %a) nounwind {
; RV32I-NOT:    orc4.b a0, a0
;
; RV32IB-LABEL: gorc4:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    orc4.b a0, a0
; RV32IB-NEXT:    ret
  %and = shl i32 %a, 4
  %shl = and i32 %and, -252645136
  %and1 = lshr i32 %a, 4
  %shr = and i32 %and1, 252645135
  %or = or i32 %shr, %a
  %or2 = or i32 %or, %shl
  ret i32 %or2
}

define i32 @gorc8(i32 %a) nounwind {
; RV32I-NOT:    orc8.h a0, a0
;
; RV32IB-LABEL: gorc8:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    orc8.h a0, a0
; RV32IB-NEXT:    ret
  %and = shl i32 %a, 8
  %shl = and i32 %and, -16711936
  %and1 = lshr i32 %a, 8
  %shr = and i32 %and1, 16711935
  %or = or i32 %shr, %a
  %or2 = or i32 %or, %shl
  ret i32 %or2
}

define i32 @gorc16(i32 %a) nounwind {
; RV32I-NOT:    orc16 a0, a0
;
; RV32IB-LABEL: gorc16:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    orc16 a0, a0
; RV32IB-NEXT:    ret
  %shl = shl i32 %a, 16
  %shr = lshr i32 %a, 16
  %or = or i32 %shr, %a
  %or2 = or i32 %or, %shl
  ret i32 %or2
}

define i32 @grev1(i32 %a) nounwind {
; RV32I-NOT:    rev.p a0, a0
;
; RV32IB-LABEL: grev1:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    rev.p a0, a0
; RV32IB-NEXT:    ret
  %and = shl i32 %a, 1
  %shl = and i32 %and, -1431655766
  %and1 = lshr i32 %a, 1
  %shr = and i32 %and1, 1431655765
  %or = or i32 %shl, %shr
  ret i32 %or
}

define i32 @grev2(i32 %a) nounwind {
; RV32I-NOT:    rev2.n a0, a0
;
; RV32IB-LABEL: grev2:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    rev2.n a0, a0
; RV32IB-NEXT:    ret
  %and = shl i32 %a, 2
  %shl = and i32 %and, -858993460
  %and1 = lshr i32 %a, 2
  %shr = and i32 %and1, 858993459
  %or = or i32 %shl, %shr
  ret i32 %or
}

define i32 @grev4(i32 %a) nounwind {
; RV32I-NOT:    rev4.b a0, a0
;
; RV32IB-LABEL: grev4:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    rev4.b a0, a0
; RV32IB-NEXT:    ret
  %and = shl i32 %a, 4
  %shl = and i32 %and, -252645136
  %and1 = lshr i32 %a, 4
  %shr = and i32 %and1, 252645135
  %or = or i32 %shl, %shr
  ret i32 %or
}

define i32 @grev8(i32 %a) nounwind {
; RV32I-NOT:    rev8.h a0, a0
;
; RV32IB-LABEL: grev8:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    rev8.h a0, a0
; RV32IB-NEXT:    ret
  %and = shl i32 %a, 8
  %shl = and i32 %and, -16711936
  %and1 = lshr i32 %a, 8
  %shr = and i32 %and1, 16711935
  %or = or i32 %shl, %shr
  ret i32 %or
}

define i32 @grev16(i32 %a) nounwind {
; RV32I-NOT:    rev16 a0, a0
;
; RV32IB-LABEL: grev16:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    rev16 a0, a0
; RV32IB-NEXT:    ret
  %shl = shl i32 %a, 16
  %shr = lshr i32 %a, 16
  %or = or i32 %shl, %shr
  ret i32 %or
}

declare i32 @llvm.bswap.i32(i32)

define i32 @bswap_i32(i32 %a) nounwind {
; RV32I-NOT:    rev8 a0, a0
;
; RV32IB-LABEL: bswap_i32:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    rev8 a0, a0
; RV32IB-NEXT:    ret
  %1 = tail call i32 @llvm.bswap.i32(i32 %a)
  ret i32 %1
}

declare i32 @llvm.bitreverse.i32(i32)

define i32 @bitreverse_i32(i32 %a) nounwind {
; RV32I-NOT:    rev a0, a0
;
; RV32IB-LABEL: bitreverse_i32:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    rev a0, a0
; RV32IB-NEXT:    ret
  %1 = tail call i32 @llvm.bitreverse.i32(i32 %a)
  ret i32 %1
}

define i32 @shfl1(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    zip.n a0, a0
;
; RV32IB-LABEL: shfl1:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    zip.n a0, a0
; RV32IB-NEXT:    ret
  %and = and i32 %a, -1717986919
  %shl = shl i32 %a, 1
  %and1 = and i32 %shl, 1145324612
  %or = or i32 %and1, %and
  %shr = lshr i32 %a, 1
  %and2 = and i32 %shr, 572662306
  %or3 = or i32 %or, %and2
  ret i32 %or3
}

define i32 @shfl2(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    zip2.b a0, a0
;
; RV32IB-LABEL: shfl2:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    zip2.b a0, a0
; RV32IB-NEXT:    ret
  %and = and i32 %a, -1010580541
  %shl = shl i32 %a, 2
  %and1 = and i32 %shl, 808464432
  %or = or i32 %and1, %and
  %shr = lshr i32 %a, 2
  %and2 = and i32 %shr, 202116108
  %or3 = or i32 %or, %and2
  ret i32 %or3
}

define i32 @shfl4(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    zip4.h a0, a0
;
; RV32IB-LABEL: shfl4:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    zip4.h a0, a0
; RV32IB-NEXT:    ret
  %and = and i32 %a, -267390961
  %shl = shl i32 %a, 4
  %and1 = and i32 %shl, 251662080
  %or = or i32 %and1, %and
  %shr = lshr i32 %a, 4
  %and2 = and i32 %shr, 15728880
  %or3 = or i32 %or, %and2
  ret i32 %or3
}

define i32 @shfl8(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    zip8 a0, a0
;
; RV32IB-LABEL: shfl8:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    zip8 a0, a0
; RV32IB-NEXT:    ret
  %and = and i32 %a, -16776961
  %shl = shl i32 %a, 8
  %and1 = and i32 %shl, 16711680
  %or = or i32 %and1, %and
  %shr = lshr i32 %a, 8
  %and2 = and i32 %shr, 65280
  %or3 = or i32 %or, %and2
  ret i32 %or3
}
