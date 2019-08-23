/* ===-------- rv32bintrin-emulation.h -------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RV32BINTRIN_EMULATION_H
#define __RV32BINTRIN_EMULATION_H

#ifndef __RVINTRIN_H
#error                                                                         \
    "Never use <rv32bintrin-emulation.h> directly; include <rvintrin.h> instead."
#endif

#include <stdint.h>

#include "rvbintrin-emulation.h"

// If the builtins are unavailable then these provide the same functionality.

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS _rv_gorc(const uint32_t rs1,
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

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS _rv_grev(const uint32_t rs1,
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

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS _rv_shfl(const uint32_t rs1,
                                                          const uint32_t rs2) {
  uint32_t x = rs1;
  const uint_xlen_t shamt = rs2 & 15;
  if (shamt & 8) {
    x = shuffle_stage(x, 0x00ff0000, 0x0000ff00, 8);
  }
  if (shamt & 4) {
    x = shuffle_stage(x, 0x0f000f00, 0x00f000f0, 4);
  }
  if (shamt & 2) {
    x = shuffle_stage(x, 0x30303030, 0x0c0c0c0c, 2);
  }
  if (shamt & 1) {
    x = shuffle_stage(x, 0x44444444, 0x22222222, 1);
  }
  return x;
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unshfl(const uint32_t rs1, const uint32_t rs2) {
  uint32_t x = rs1;
  const uint_xlen_t shamt = rs2 & 15;
  if (shamt & 1) {
    x = shuffle_stage(x, 0x44444444, 0x22222222, 1);
  }
  if (shamt & 2) {
    x = shuffle_stage(x, 0x30303030, 0x0c0c0c0c, 2);
  }
  if (shamt & 4) {
    x = shuffle_stage(x, 0x0f000f00, 0x00f000f0, 4);
  }
  if (shamt & 8) {
    x = shuffle_stage(x, 0x00ff0000, 0x0000ff00, 8);
  }
  return x;
}

#endif //__RV32BINTRIN_EMULATION_H
