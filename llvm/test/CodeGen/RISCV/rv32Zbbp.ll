; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32I
; RUN: llc -mtriple=riscv32 -mattr=+experimental-b -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbb -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbp -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB

define i32 @andn(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    andn a0, a0, a1
;
; RV32IB-LABEL: andn:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    andn a0, a0, a1
; RV32IB-NEXT:    ret
  %neg = xor i32 %b, -1
  %and = and i32 %neg, %a
  ret i32 %and
}

define i32 @orn(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    orn a0, a0, a1
;
; RV32IB-LABEL: orn:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    orn a0, a0, a1
; RV32IB-NEXT:    ret
  %neg = xor i32 %b, -1
  %or = or i32 %neg, %a
  ret i32 %or
}

define i32 @xnor(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    xnor a0, a0, a1
;
; RV32IB-LABEL: xnor:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    xnor a0, a0, a1
; RV32IB-NEXT:    ret
  %neg = xor i32 %a, -1
  %xor = xor i32 %neg, %b
  ret i32 %xor
}

declare i32 @llvm.fshl.i32(i32, i32, i32)

define i32 @rol(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    rol a0, a0, a1
;
; RV32IB-LABEL: rol:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    rol a0, a0, a1
; RV32IB-NEXT:    ret
  %or = tail call i32 @llvm.fshl.i32(i32 %a, i32 %a, i32 %b)
  ret i32 %or
}

declare i32 @llvm.fshr.i32(i32, i32, i32)

define i32 @ror(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    ror a0, a0, a1
;
; RV32IB-LABEL: ror:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    ror a0, a0, a1
; RV32IB-NEXT:    ret
  %or = tail call i32 @llvm.fshr.i32(i32 %a, i32 %a, i32 %b)
  ret i32 %or
}

define i32 @pack(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    pack a0, a0, a1
;
; RV32IB-LABEL: pack:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    pack a0, a0, a1
; RV32IB-NEXT:    ret
  %shl = and i32 %a, 65535
  %shl1 = shl i32 %b, 16
  %or = or i32 %shl1, %shl
  ret i32 %or
}

define i32 @packu(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    packu a0, a0, a1
;
; RV32IB-LABEL: packu:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    packu a0, a0, a1
; RV32IB-NEXT:    ret
  %shr = lshr i32 %a, 16
  %shr1 = and i32 %b, -65536
  %or = or i32 %shr1, %shr
  ret i32 %or
}

define i32 @packh(i32 %a, i32 %b) nounwind {
; RV32I-NOT:    packh a0, a0, a1
;
; RV32IB-LABEL: packh:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    packh a0, a0, a1
; RV32IB-NEXT:    ret
  %and = and i32 %a, 255
  %and1 = shl i32 %b, 8
  %shl = and i32 %and1, 65280
  %or = or i32 %shl, %and
  ret i32 %or
}
