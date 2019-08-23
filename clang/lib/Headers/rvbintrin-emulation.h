/* ===-------- rvbintrin-emulation.h ---------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RVBINTRIN_EMULATION_H
#define __RVBINTRIN_EMULATION_H

#ifndef __RVINTRIN_H
#error                                                                         \
    "Never use <rvbintrin-emulation.h> directly; include <rvintrin.h> instead."
#endif

#include <stdint.h>

// If the builtins are unavailable then these provide the same functionality.

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_slo(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return ~(~rs1 << (rs2 & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_andn(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 & ~rs2;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_fsl(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  uint_xlen_t shamt = rs2 & (2 * XLEN - 1);
  uint_xlen_t A = rs1;
  uint_xlen_t B = rs3;
  if (shamt >= XLEN) {
    shamt -= XLEN;
    A = rs3;
    B = rs1;
  }
  return shamt ? (A << shamt) | (B >> (XLEN - shamt)) : A;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_fsr(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  uint_xlen_t shamt = rs2 & (2 * XLEN - 1);
  uint_xlen_t A = rs1;
  uint_xlen_t B = rs3;
  if (shamt >= XLEN) {
    shamt -= XLEN;
    A = rs3;
    B = rs1;
  }
  return shamt ? (A >> shamt) | (B << (XLEN - shamt)) : A;
}

static __inline__ int_xlen_t _rv_max(const int_xlen_t rs1,
                                     const int_xlen_t rs2) {
  return rs1 > rs2 ? rs1 : rs2;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_maxu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 > rs2 ? rs1 : rs2;
}

static __inline__ int_xlen_t _rv_min(const int_xlen_t rs1,
                                     const int_xlen_t rs2) {
  return rs1 < rs2 ? rs1 : rs2;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_minu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 < rs2 ? rs1 : rs2;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orn(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 | ~rs2;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rol(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  const uint_xlen_t shamt = rs2 & (XLEN - 1);
  return (rs1 << shamt) | (rs1 >> ((XLEN - shamt) & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_ror(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  const uint_xlen_t shamt = rs2 & (XLEN - 1);
  return (rs1 >> shamt) | (rs1 << ((XLEN - shamt) & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_bdep(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t r = 0;
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

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_bext(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t r = 0;
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

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_bfp(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t len = (rs2 >> 24) & 15;
  const uint_xlen_t off = (rs2 >> 16) & (XLEN - 1);
  len = len ? len : 16;
  const uint_xlen_t mask = _rv_rol(_rv_slo(0, len), off);
  const uint_xlen_t data = _rv_rol(rs2, off);
  return (data & mask) | (rs1 & ~mask);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_clmul(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t x = 0;
  for (uint_xlen_t i = 0; i < XLEN; i++) {
    if ((rs2 >> i) & 1) {
      x ^= rs1 << i;
    }
  }
  return x;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_clmulh(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t x = 0;
  for (uint_xlen_t i = 1; i < XLEN; i++) {
    if ((rs2 >> i) & 1) {
      x ^= rs1 >> (XLEN - i);
    }
  }
  return x;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_clmulr(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  uint_xlen_t x = 0;
  for (uint_xlen_t i = 0; i < XLEN; i++) {
    if ((rs2 >> i) & 1) {
      x ^= rs1 >> (XLEN - i - 1);
    }
  }
  return x;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_cmix(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return (rs1 & rs2) | (rs3 & ~rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_cmov(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return rs2 ? rs1 : rs3;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
crc32(uint_xlen_t x, const uint_xlen_t nbits) {
  for (uint_xlen_t i = 0; i < nbits; i++) {
    x = (x >> 1) ^ (0xEDB88320 & ~((x & 1) - 1));
  }
  return x;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
crc32c(uint_xlen_t x, const uint_xlen_t nbits) {
  for (uint_xlen_t i = 0; i < nbits; i++) {
    x = (x >> 1) ^ (0x82F63B78 & ~((x & 1) - 1));
  }
  return x;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32b(const uint_xlen_t rs1) {
  return crc32(rs1, 8);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32h(const uint_xlen_t rs1) {
  return crc32(rs1, 16);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32w(const uint_xlen_t rs1) {
  return crc32(rs1, 32);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32cb(const uint_xlen_t rs1) {
  return crc32c(rs1, 8);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32ch(const uint_xlen_t rs1) {
  return crc32c(rs1, 16);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_crc32cw(const uint_xlen_t rs1) {
  return crc32c(rs1, 32);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_pack(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return (rs2 << XLEN / 2) | ((rs1 << XLEN / 2) >> XLEN / 2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_packu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return (rs1 >> XLEN / 2) | ((rs2 >> XLEN / 2) << XLEN / 2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_packh(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return (rs1 & 255) | ((rs2 & 255) << 8);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sextb(const uint_xlen_t rs1) {
  return int_xlen_t(x << (XLEN - 8)) >> (XLEN - 8);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sexth(const uint_xlen_t rs1) {
  return int_xlen_t(x << (XLEN - 16)) >> (XLEN - 16);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sbclr(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 & ~(1 << (rs2 & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sbext(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return 1 & (rs1 >> (rs2 & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sbinv(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 ^ (1 << (rs2 & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sbset(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 | (1 << (rs2 & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
shuffle_stage(const uint_xlen_t src, const uint_xlen_t maskL,
              const uint_xlen_t maskR, const uint_xlen_t N) {
  uint_xlen_t x = src & ~(maskL | maskR);
  x |= ((src << N) & maskL) | ((src >> N) & maskR);
  return x;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_sro(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return ~(~rs1 >> (rs2 & (XLEN - 1)));
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_xnor(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return rs1 ^ ~rs2;
}

#endif //__RVBINTRIN_EMULATION_H
