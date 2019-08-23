/* ===-------- rv32bintrin-builtins.h --------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RV32BINTRIN_BUILTINS_H
#define __RV32BINTRIN_BUILTINS_H

#ifndef __RVINTRIN_H
#error                                                                         \
    "Never use <rv32bintrin-builtins.h> directly; include <rvintrin.h> instead."
#endif

// These are available regardless of whether or not the Bitmanip extension is
// enabled or not.

// Our approach to these functions is to use inline asm when the Bitmanip
// extension is enabled and use replacment C code when it's disabled. However,
// where LLVM builtins are already avaiable we are making use of them.

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_clz(const uint_xlen_t rs1) {
  // Calling these builtins with 0 results in undefined behaviour.
  if (rs1 == 0) {
    return XLEN;
  }
  return __builtin_clz(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_ctz(const uint_xlen_t rs1) {
  if (rs1 == 0) {
    return XLEN;
  }
  return __builtin_ctz(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_pcnt(const uint_xlen_t rs1) {
  return __builtin_popcount(rs1);
}

// Genric aliases
// e.g. _rv_* is an alias of _rv64_*

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_clz(const uint_xlen_t rs1) {
  return _rv32_clz(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_ctz(const uint_xlen_t rs1) {
  return _rv32_ctz(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_pcnt(const uint_xlen_t rs1) {
  return _rv32_pcnt(rs1);
}

#endif //__RV32BINTRIN_BUILTINS_H
