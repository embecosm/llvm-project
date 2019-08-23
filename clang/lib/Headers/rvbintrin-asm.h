/* ===-------- rvbintrin-asm.h ---------------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RVBINTRIN_ASM_H
#define __RVBINTRIN_ASM_H

#ifndef __RVINTRIN_H
#error "Never use <rvbintrin-asm.h> directly; include <rvintrin.h> instead."
#endif

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_andn(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("andn  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_fsl(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  uint_xlen_t rd;
  __asm__("fsl  %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "r"(rs3));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_fsr(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("fsri  %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "i"(rs3));
  } else {
    __asm__("fsr  %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "r"(rs3));
  }
  return rd;
}

static __inline__ int_xlen_t _rv_max(const int_xlen_t rs1,
                                     const int_xlen_t rs2) {
  int_xlen_t rd;
  __asm__("max  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_maxu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("maxu  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ int_xlen_t _rv_min(const int_xlen_t rs1,
                                     const int_xlen_t rs2) {
  int_xlen_t rd;
  __asm__("min  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_minu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("minu  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orn(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("orn  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rol(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("rol  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_ror(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("rori  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("ror  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_bdep(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("bdep  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_bext(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("bext  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_bfp(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("bfp  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_clmul(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("clmul  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_clmulh(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("clmulh  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_clmulr(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("clmulr  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_cmix(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  uint_xlen_t rd;
  __asm__("cmix  %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "r"(rs3));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_cmov(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  uint_xlen_t rd;
  __asm__("cmov  %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "r"(rs3));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32b(const uint_xlen_t rs1) {
  uint_xlen_t rd;
  __asm__("crc32.b  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32h(const uint_xlen_t rs1) {
  uint_xlen_t rd;
  __asm__("crc32.h  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32w(const uint_xlen_t rs1) {
  uint_xlen_t rd;
  __asm__("crc32.w  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32cb(const uint_xlen_t rs1) {
  uint_xlen_t rd;
  __asm__("crc32c.b  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32ch(const uint_xlen_t rs1) {
  uint_xlen_t rd;
  __asm__("crc32c.h  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32cw(const uint_xlen_t rs1) {
  uint_xlen_t rd;
  __asm__("crc32c.w  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_gorc(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("gorci  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("gorc  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_grev(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("grevi  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("grev  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_pack(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("pack  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_packu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("packu  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_packh(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  __asm__("packh  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sextb(const uint_xlen_t rs1) {
  uint_xlen_t rd;
  __asm__("sext.b  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sexth(const uint_xlen_t rs1) {
  uint_xlen_t rd;
  __asm__("sext.h  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sbclr(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sbclri  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("sbclr  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sbext(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sbexti  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("sbext  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sbinv(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sbinvi  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("sbinv  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sbset(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sbseti  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("sbset  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_shfl(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("shfli  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("shfl  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_slo(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sloi  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("slo  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sro(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sroi  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("sro  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unshfl(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("unshfli  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("unshfl  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_xnor(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 ^ ~rs2;
}

#endif // __RVBINTRIN_ASM_H
