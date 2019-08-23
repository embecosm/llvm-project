/* ===-------- rv64bintrin-emulation.h -------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RV64INTRIN_EMULATION_H
#define __RV64INTRIN_EMULATION_H

#ifndef __RVINTRIN_H
#error                                                                         \
    "Never use <rv64bintrin-emulation.h> directly; include <rvintrin.h> instead."
#endif

#include <stdint.h>

#include "rvbintrin-emulation.h"

static __inline__ uint32_t shuffle32_stage(const uint32_t src,
                                           const uint32_t maskL,
                                           const uint32_t maskR,
                                           const uint_xlen_t N) {
  uint32_t x = src & ~(maskL | maskR);
  x |= ((src << N) & maskL) | ((src >> N) & maskR);
  return x;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS _rv_shfl(const uint64_t rs1,
                                                       const uint64_t rs2) {
  uint64_t x = rs1;
  const uint_xlen_t shamt = rs2 & 31;
  if (shamt & 16) {
    x = shuffle_stage(x, 0x0000ffff00000000LL, 0x00000000ffff0000LL, 16);
  }
  if (shamt & 8) {
    x = shuffle_stage(x, 0x00ff000000ff0000LL, 0x0000ff000000ff00LL, 8);
  }
  if (shamt & 4) {
    x = shuffle_stage(x, 0x0f000f000f000f00LL, 0x00f000f000f000f0LL, 4);
  }
  if (shamt & 2) {
    x = shuffle_stage(x, 0x3030303030303030LL, 0x0c0c0c0c0c0c0c0cLL, 2);
  }
  if (shamt & 1) {
    x = shuffle_stage(x, 0x4444444444444444LL, 0x2222222222222222LL, 1);
  }

  return x;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_shflw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint32_t x = rs1;
  const uint_xlen_t shamt = rs2 & 15;
  if (shamt & 8) {
    x = shuffle32_stage(x, 0x00ff0000, 0x0000ff00, 8);
  }
  if (shamt & 4) {
    x = shuffle32_stage(x, 0x0f000f00, 0x00f000f0, 4);
  }
  if (shamt & 2) {
    x = shuffle32_stage(x, 0x30303030, 0x0c0c0c0c, 2);
  }
  if (shamt & 1) {
    x = shuffle32_stage(x, 0x44444444, 0x22222222, 1);
  }
  return x;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS _rv_bmatflip(const uint64_t rs1) {
  uint64_t x = rs1;
  x = _rv_shfl(x, 31);
  x = _rv_shfl(x, 31);
  x = _rv_shfl(x, 31);
  return x;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS _rv_bmator(const uint64_t rs1,
                                                         const uint64_t rs2) {
  // transpose of rs2
  const uint64_t rs2t = _rv_bmatflip(rs2);
  uint8_t u[8]; // rows of rs1
  uint8_t v[8]; // cols of rs2
  for (uint_xlen_t i = 0; i < 8; i++) {
    u[i] = rs1 >> (i * 8);
    v[i] = rs2t >> (i * 8);
  }
  uint64_t x = 0;
  for (uint_xlen_t i = 0; i < 8; i++) {
    if ((u[i / 8] & v[i % 8]) != 0) {
      x |= 1LL << i;
    }
  }
  return x;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS _rv_bmatxor(const uint64_t rs1,
                                                          const uint64_t rs2) {
  // transpose of rs2
  const uint64_t rs2t = _rv_bmatflip(rs2);
  uint8_t u[8]; // rows of rs1
  uint8_t v[8]; // cols of rs2
  for (uint_xlen_t i = 0; i < 8; i++) {
    u[i] = rs1 >> (i * 8);
    v[i] = rs2t >> (i * 8);
  }
  uint64_t x = 0;
  for (uint_xlen_t i = 0; i < 64; i++) {
    if (_rv_pcnt(u[i / 8] & v[i % 8]) & 1) {
      x |= 1LL << i;
    }
  }
  return x;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_fslw(const uint32_t rs1,
                                                       const uint32_t rs2,
                                                       const uint32_t rs3) {
  uint32_t shamt = rs2 & (2 * XLEN - 1);
  uint32_t A = rs1;
  uint32_t B = rs3;
  if (shamt >= XLEN) {
    shamt -= XLEN;
    A = rs3;
    B = rs1;
  }
  return shamt ? (A << shamt) | (B >> (XLEN - shamt)) : A;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_fsrw(const uint32_t rs1,
                                                       const uint32_t rs2,
                                                       const uint32_t rs3) {
  uint32_t shamt = rs2 & (2 * XLEN - 1);
  uint32_t A = rs1;
  uint32_t B = rs3;
  if (shamt >= XLEN) {
    shamt -= XLEN;
    A = rs3;
    B = rs1;
  }
  return shamt ? (A >> shamt) | (B << (XLEN - shamt)) : A;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_rolw(const uint32_t rs1,
                                                       const uint32_t rs2) {
  const uint32_t shamt = rs2 & (XLEN - 1);
  return (rs1 << shamt) | (rs1 >> ((XLEN - shamt) & (XLEN - 1)));
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_rorw(const uint32_t rs1,
                                                       const uint32_t rs2) {
  const uint32_t shamt = rs2 & (XLEN - 1);
  return (rs1 >> shamt) | (rs1 << ((XLEN - shamt) & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_adduw(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 + (rs2 & 0xFFFFFFFF);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_addwu(const uint32_t rs1,
                                                        const uint32_t rs2) {
  return (rs1 + rs2) & 0xFFFFFFFF;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_bdepw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint32_t r = 0;
  for (uint_xlen_t i = 0, j = 0; i < XLEN; i++) {
    if ((rs2 >> i) & 1) {
      if ((rs1 >> j) & 1) {
        r |= 1 << i;
      }
      j++;
    }
  }
  return r;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_bextw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint32_t r = 0;
  for (uint_xlen_t i = 0, j = 0; i < XLEN; i++) {
    if ((rs2 >> i) & 1) {
      if ((rs1 >> i) & 1) {
        r |= 1 << j;
      }
      j++;
    }
  }
  return r;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_bfpw(const uint32_t rs1,
                                                       const uint32_t rs2) {
  uint_xlen_t len = (rs2 >> 24) & 15;
  const uint32_t off = (rs2 >> 16) & (XLEN - 1);
  len = len ? len : 16;
  const uint32_t mask = _rv_rol(_rv_slo(0, len), off);
  const uint32_t data = _rv_rol(rs2, off);
  return (data & mask) | (rs1 & ~mask);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_clmulhw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  uint32_t x = 0;
  for (uint_xlen_t i = 1; i < XLEN; i++) {
    if ((rs2 >> i) & 1) {
      x ^= rs1 >> (XLEN - i);
    }
  }
  return x;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_clmulrw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  uint32_t x = 0;
  for (uint_xlen_t i = 0; i < XLEN; i++) {
    if ((rs2 >> i) & 1) {
      x ^= rs1 >> (XLEN - i - 1);
    }
  }
  return x;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_clmulw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  uint32_t x = 0;
  for (uint_xlen_t i = 0; i < XLEN; i++) {
    if ((rs2 >> i) & 1) {
      x ^= rs1 << i;
    }
  }
  return x;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32d(const uint_xlen_t rs1) {
  return crc32(rs1, 64);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32cd(const uint_xlen_t rs1) {
  return crc32c(rs1, 64);
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS _rv_gorc(const uint64_t rs1,
                                                       const uint64_t rs2) {
  uint64_t x = rs1;
  const uint_xlen_t shamt = rs2 & 63;
  if (shamt & 1)
    x |= ((x & 0x5555555555555555LL) << 1) | ((x & 0xAAAAAAAAAAAAAAAALL) >> 1);
  if (shamt & 2)
    x |= ((x & 0x3333333333333333LL) << 2) | ((x & 0xCCCCCCCCCCCCCCCCLL) >> 2);
  if (shamt & 4)
    x |= ((x & 0x0F0F0F0F0F0F0F0FLL) << 4) | ((x & 0xF0F0F0F0F0F0F0F0LL) >> 4);
  if (shamt & 8)
    x |= ((x & 0x00FF00FF00FF00FFLL) << 8) | ((x & 0xFF00FF00FF00FF00LL) >> 8);
  if (shamt & 16)
    x |=
        ((x & 0x0000FFFF0000FFFFLL) << 16) | ((x & 0xFFFF0000FFFF0000LL) >> 16);
  if (shamt & 32)
    x |=
        ((x & 0x00000000FFFFFFFFLL) << 32) | ((x & 0xFFFFFFFF00000000LL) >> 32);
  return x;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_gorcw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint32_t x = rs1;
  const uint_xlen_t shamt = rs2 & 31;
  if (shamt & 1) {
    x |= ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
  }
  if (shamt & 2) {
    x |= ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
  }
  if (shamt & 4) {
    x |= ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
  }
  if (shamt & 8) {
    x |= ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
  }
  if (shamt & 16) {
    x |= ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
  }
  return x;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS _rv_grev(const uint64_t rs1,
                                                       const uint64_t rs2) {
  uint64_t x = rs1;
  const uint_xlen_t shamt = rs2 & 63;
  if (shamt & 1) {
    x = ((x & 0x5555555555555555LL) << 1) | ((x & 0xAAAAAAAAAAAAAAAALL) >> 1);
  }
  if (shamt & 2) {
    x = ((x & 0x3333333333333333LL) << 2) | ((x & 0xCCCCCCCCCCCCCCCCLL) >> 2);
  }
  if (shamt & 4) {
    x = ((x & 0x0F0F0F0F0F0F0F0FLL) << 4) | ((x & 0xF0F0F0F0F0F0F0F0LL) >> 4);
  }
  if (shamt & 8) {
    x = ((x & 0x00FF00FF00FF00FFLL) << 8) | ((x & 0xFF00FF00FF00FF00LL) >> 8);
  }
  if (shamt & 16) {
    x = ((x & 0x0000FFFF0000FFFFLL) << 16) | ((x & 0xFFFF0000FFFF0000LL) >> 16);
  }
  if (shamt & 32) {
    x = ((x & 0x00000000FFFFFFFFLL) << 32) | ((x & 0xFFFFFFFF00000000LL) >> 32);
  }
  return x;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_grevw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  uint32_t x = rs1;
  const uint_xlen_t shamt = rs2 & 31;
  if (shamt & 1) {
    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
  }
  if (shamt & 2) {
    x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
  }
  if (shamt & 4) {
    x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
  }
  if (shamt & 8) {
    x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
  }
  if (shamt & 16) {
    x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
  }
  return x;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_packw(const uint32_t rs1,
                                                        const uint32_t rs2) {
  // XLEN / 4 to get half of a 32 bit value on riscv64
  return (rs2 << XLEN / 4) | ((rs1 << XLEN / 4) >> XLEN / 4);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_packuw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  // XLEN / 4 to get half of a 32 bit value on riscv64
  return (rs1 >> XLEN / 4) | ((rs2 >> XLEN / 4) << XLEN / 4)
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_sbclrw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  return rs1 & ~(1 << (rs2 & (XLEN - 1)));
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_sbextw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  return 1 & (rs1 >> (rs2 & (XLEN - 1)));
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_sbinvw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  return rs1 ^ (1 << (rs2 & (XLEN - 1)));
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_sbsetw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  return rs1 | (1 << (rs2 & (XLEN - 1)));
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_slow(const uint32_t rs1,
                                                       const uint32_t rs2) {
  return ~(~rs1 << (rs2 & (XLEN - 1)));
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_srow(const uint32_t rs1,
                                                       const uint32_t rs2) {
  return ~(~rs1 >> (rs2 & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_subuw(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 - (rs2 & 0xFFFFFFFF);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_subwu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return (rs1 - rs2) & 0xFFFFFFFF;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS _rv_unshfl(const uint64_t rs1,
                                                         const uint64_t rs2) {
  uint64_t x = rs1;
  const uint_xlen_t shamt = rs2 & 31;
  if (shamt & 1) {
    x = shuffle_stage(x, 0x4444444444444444LL, 0x2222222222222222LL, 1);
  }
  if (shamt & 2) {
    x = shuffle_stage(x, 0x3030303030303030LL, 0x0c0c0c0c0c0c0c0cLL, 2);
  }
  if (shamt & 4) {
    x = shuffle_stage(x, 0x0f000f000f000f00LL, 0x00f000f000f000f0LL, 4);
  }
  if (shamt & 8) {
    x = shuffle_stage(x, 0x00ff000000ff0000LL, 0x0000ff000000ff00LL, 8);
  }
  if (shamt & 16) {
    x = shuffle_stage(x, 0x0000ffff00000000LL, 0x00000000ffff0000LL, 16);
  }
  return x;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv_unshflw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  uint32_t x = rs1;
  const uint_xlen_t shamt = rs2 & 15;
  if (shamt & 1) {
    x = shuffle32_stage(x, 0x44444444, 0x22222222, 1);
  }
  if (shamt & 2) {
    x = shuffle32_stage(x, 0x30303030, 0x0c0c0c0c, 2);
  }
  if (shamt & 4) {
    x = shuffle32_stage(x, 0x0f000f00, 0x00f000f0, 4);
  }
  if (shamt & 8) {
    x = shuffle32_stage(x, 0x00ff0000, 0x0000ff00, 8);
  }
  return x;
}

#endif //__RV64INTRIN_EMULATION_H
