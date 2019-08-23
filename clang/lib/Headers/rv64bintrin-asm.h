/* ===-------- rv64bintrin-asm.h -------------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RV64BINTRIN_ASM_H
#define __RV64BINTRIN_ASM_H

#ifndef __RVINTRIN_H
#error "Never use <rv64bintrin-asm.h> directly; include <rvintrin.h> instead."
#endif

#include <stdint.h>

#include "rvbintrin-asm.h"

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_fslw(const uint32_t rs1,
                                                       const uint32_t rs2,
                                                       const uint32_t rs3) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("fsriw  %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "i"(rs3));
  } else {
    __asm__("fslw  %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "r"(rs3));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_fsrw(const uint32_t rs1,
                                                       const uint32_t rs2,
                                                       const uint32_t rs3) {
  uint_xlen_t rd;
  __asm__("fsrw  %0, %1, %2, %3" : "=r"(rd) : "r"(rs1), "r"(rs2), "r"(rs3));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_rolw(const uint32_t rs1,
                                                       const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("rolw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_rorw(const uint32_t rs1,
                                                       const uint32_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("roriw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("rorw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_addwu(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("addiwu  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("addwu  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_adduw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("addu.w  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_bdepw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("bdepw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_bfpw(const uint32_t rs1,
                                                       const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("bfpw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_bextw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("bextw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_bmatflip(const uint32_t rs1) {
  uint_xlen_t rd;
  __asm__("bmatflip  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_bmator(const uint32_t rs1,
                                                         const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("bmator  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_bmatxor(const uint32_t rs1,
                                                          const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("bmatxor  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_clmulhw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("clmulhw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_clmulrw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("clmulrw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_clmulw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("clmulw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_crc32d(const uint32_t rs1) {
  uint_xlen_t rd;
  __asm__("crc32.d  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_crc32cd(const uint32_t rs1) {
  uint_xlen_t rd;
  __asm__("crc32c.d  %0, %1" : "=r"(rd) : "r"(rs1));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_gorcw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("gorciw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("gorcw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_grevw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("greviw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("grevw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_packw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("packw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_packuw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("packuw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_sbclrw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sbclriw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("sbclrw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_sbextw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("sbextw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_sbinvw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sbinviw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("sbinvw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_sbsetw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sbsetiw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("sbsetw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_shflw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("shflw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_slow(const uint32_t rs1,
                                                       const uint32_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sloiw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("slow  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_srow(const uint32_t rs1,
                                                       const uint32_t rs2) {
  uint_xlen_t rd;
  if (__builtin_constant_p(rs2)) {
    __asm__("sroiw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "i"(rs2));
  } else {
    __asm__("srow  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  }
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_subuw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("subu.w  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_subwu(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("subwu  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_unshflw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  uint_xlen_t rd;
  __asm__("unshflw  %0, %1, %2" : "=r"(rd) : "r"(rs1), "r"(rs2));
  return rd;
}

#endif //__RV64BINTRIN_ASM_H
