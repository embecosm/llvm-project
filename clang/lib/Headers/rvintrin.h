/* ===-------- rvintrin.h --------------------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RVINTRIN_H
#define __RVINTRIN_H

// Long is 32 bit on riscv32 and 64 bit on riscv64
#define int_xlen_t long
#define uint_xlen_t unsigned int_xlen_t
#define XLEN __riscv_xlen

_Static_assert(__riscv_xlen == sizeof(uint_xlen_t) * 8,
               "uint_xlen_t is not __riscv_xlen bits long");

#define __DEFAULT_FN_ATTRS                                                     \
  __attribute__((__always_inline__, __artificial__, __nodebug__))

#if defined(__riscv32__)

#include "rv32bintrin.h"

#elif defined(__riscv64__)

#include "rv64bintrin.h"

#endif // defined(__riscv64__)

#undef __DEFAULT_FN_ATTRS

#undef XLEN
#undef uint_xlen_t
#undef int_xlen_t
#endif // __RVINTRIN_H
