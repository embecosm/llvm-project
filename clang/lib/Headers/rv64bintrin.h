/* ===-------- rv64bintrin.h -----------------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RV64BINTRIN_H
#define __RV64BINTRIN_H

#ifndef __RVINTRIN_H
#error "Never use <rv64bintrin.h> directly; include <rvintrin.h> instead."
#endif

#include <stdint.h>

#include "rv64bintrin-builtins.h"

#if defined(__riscv_bitmanip)

#include "rv64bintrin-asm.h"

#else // Bitmanip extension is disabled.

#include "rv64bintrin-emulation.h"

#endif // defined(__riscv_bitmanip)

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_andn(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_andn(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_fsl(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return _rv_fsl(rs1, rs2, rs3);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_fsr(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return _rv_fsr(rs1, rs2, rs3);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_max(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_max(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_maxu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_maxu(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_min(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_min(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_minu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_minu(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orn(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_orn(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rol(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_rol(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_ror(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_ror(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_bdep(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_bdep(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_bext(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_bext(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_bfp(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_bfp(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_clmul(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_clmul(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_clmulh(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_clmulh(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_clmulr(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_clmulr(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS _rv64_cmix(
    const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return _rv_cmix(rs1, rs2, rs3);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS _rv64_cmov(
    const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return _rv_cmov(rs1, rs2, rs3);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_crc32b(const uint_xlen_t rs1) {
  return _rv_crc32b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_crc32h(const uint_xlen_t rs1) {
  return _rv_crc32h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_crc32w(const uint_xlen_t rs1) {
  return _rv_crc32w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_crc32cb(const uint_xlen_t rs1) {
  return _rv_crc32cb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_crc32ch(const uint_xlen_t rs1) {
  return _rv_crc32cb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_crc32cw(const uint_xlen_t rs1) {
  return _rv_crc32cb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_gorc(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_gorc(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_grev(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_grev(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_pack(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_pack(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_packu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_packu(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_packh(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_packh(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_sextb(const uint_xlen_t rs1) {
  return _rv_sextb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_sexth(const uint_xlen_t rs1) {
  return _rv_sexth(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_sbclr(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sbclr(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_sbext(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sbext(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_sbinv(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sbinv(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_sbset(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sbset(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_shfl(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_shfl(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_slo(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_slo(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_sro(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sro(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unshfl(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_unshfl(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_xnor(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_xnor(rs1, rs2);
}

// 64 bit only

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_fslw(const uint32_t rs1,
                                                         const uint32_t rs2,
                                                         const uint32_t rs3) {
  return _rv_fslw(rs1, rs2, rs3);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_fsrw(const uint32_t rs1,
                                                         const uint32_t rs2,
                                                         const uint32_t rs3) {
  return _rv_fsrw(rs1, rs2, rs3);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_rolw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  return _rv_rolw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_rorw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  return _rv_rorw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_adduw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_adduw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_addwu(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_addwu(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_bdepw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_bdepw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_bfpw(const uint32_t rs1,
                                                         const uint32_t rs2) {
  return _rv_bfpw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_bextw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_bextw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
_rv64_bmatflip(const uint32_t rs1) {
  return _rv_bmatflip(rs1);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_bmator(const uint32_t rs1,
                                                           const uint32_t rs2) {
  return _rv_bmator(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
_rv64_bmatxor(const uint32_t rs1, const uint32_t rs2) {
  return _rv_bmatxor(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
_rv64_clmulhw(const uint32_t rs1, const uint32_t rs2) {
  return _rv_clmulhw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
_rv64_clmulrw(const uint32_t rs1, const uint32_t rs2) {
  return _rv_clmulrw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_clmulw(const uint32_t rs1,
                                                           const uint32_t rs2) {
  return _rv_clmulw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_crc32d(const uint32_t rs1) {
  return _rv_crc32d(rs1);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
_rv64_crc32cd(const uint32_t rs1) {
  return _rv_crc32cd(rs1);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_gorcw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_gorcw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_grevw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_grevw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_packw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_packw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_packuw(const uint32_t rs1,
                                                           const uint32_t rs2) {
  return _rv_packuw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_sbclrw(const uint32_t rs1,
                                                           const uint32_t rs2) {
  return _rv_sbclrw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_sbextw(const uint32_t rs1,
                                                           const uint32_t rs2) {
  return _rv_sbextw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_sbinvw(const uint32_t rs1,
                                                           const uint32_t rs2) {
  return _rv_sbinvw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_sbsetw(const uint32_t rs1,
                                                           const uint32_t rs2) {
  return _rv_sbsetw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_shflw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_shflw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_slow(const uint32_t rs1,
                                                         const uint32_t rs2) {
  return _rv_slow(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_srow(const uint32_t rs1,
                                                         const uint32_t rs2) {
  return _rv_srow(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_subuw(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_subuw(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS _rv64_subwu(const uint32_t rs1,
                                                          const uint32_t rs2) {
  return _rv_subwu(rs1, rs2);
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
_rv64_unshflw(const uint32_t rs1, const uint32_t rs2) {
  return _rv_unshflw(rs1, rs2);
}

// Pseudo Instructions

// REV (GREVI) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_revp(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b000001);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev2n(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b000010);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_revn(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b000011);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev4b(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b000100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev2b(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b000110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_revb(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b000111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev8h(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b001000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev4h(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b001100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev2h(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b001110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_revh(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b001111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev16w(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b010000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev8w(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b011000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev4w(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b011100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev2w(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b011110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_revw(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b011111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev32(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b100000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev16(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b110000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev8(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b111000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev4(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b111100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev2(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b111110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_rev(const uint_xlen_t rs1) {
  return _rv64_grev(rs1, 0b111111);
}

// ORC (GORCI) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orcp(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b000001);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc2n(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b000010);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orcn(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b000011);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc4b(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b000100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc2b(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b000110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orcb(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b000111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc8h(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b001000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc4h(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b001100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc2h(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b001110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orch(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b001111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc16w(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b010000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc8w(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b011000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc4w(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b011100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc2w(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b011110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orcw(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b011111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc32(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b100000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc16(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b110000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc8(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b111000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc4(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b111100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc2(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b111110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_orc(const uint_xlen_t rs1) {
  return _rv64_gorc(rs1, 0b111111);
}

// ZIP (SHFLI) pseudo instructions
static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zipn(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b00001);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip2b(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b00010);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zipb(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b00011);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip4h(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b00100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip2h(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b00110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_ziph(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b00111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip8w(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b01000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip4w(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b01100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip2w(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b01110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zipw(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b01111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip16(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b10000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip8(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b11000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip4(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b11100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip2(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b11110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_zip(const uint_xlen_t rs1) {
  return _rv64_shfl(rs1, 0b11111);
}

// UNZIP (UNSHFL) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzipn(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b00001);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip2b(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b00010);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzipb(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b00011);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip4h(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b00100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip2h(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b00110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unziph(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b00111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip8w(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b01000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip4w(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b01100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip2w(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b01110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzipw(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b01111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip16(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b11000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip8(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b11000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip4(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b11100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip2(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b11110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv64_unzip(const uint_xlen_t rs1) {
  return _rv64_unshfl(rs1, 0b11111);
}

// Genric aliases for 64 bit pseudo instructions
// e.g. _rv_* is an alias of _rv64_*

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_revp(const uint_xlen_t rs1) {
  return _rv64_revp(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev2n(const uint_xlen_t rs1) {
  return _rv64_rev2n(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_revn(const uint_xlen_t rs1) {
  return _rv64_revn(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev4b(const uint_xlen_t rs1) {
  return _rv64_rev4b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev2b(const uint_xlen_t rs1) {
  return _rv64_rev2b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_revb(const uint_xlen_t rs1) {
  return _rv64_revb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev8h(const uint_xlen_t rs1) {
  return _rv64_rev8h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev4h(const uint_xlen_t rs1) {
  return _rv64_rev4h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev2h(const uint_xlen_t rs1) {
  return _rv64_rev2h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_revh(const uint_xlen_t rs1) {
  return _rv64_revh(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev16w(const uint_xlen_t rs1) {
  return _rv64_rev16w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev8w(const uint_xlen_t rs1) {
  return _rv64_rev8w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev4w(const uint_xlen_t rs1) {
  return _rv64_rev4w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev2w(const uint_xlen_t rs1) {
  return _rv64_rev2w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_revw(const uint_xlen_t rs1) {
  return _rv64_revw(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev32(const uint_xlen_t rs1) {
  return _rv64_rev32(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev16(const uint_xlen_t rs1) {
  return _rv64_rev16(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev8(const uint_xlen_t rs1) {
  return _rv64_rev8(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev4(const uint_xlen_t rs1) {
  return _rv64_rev4(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev2(const uint_xlen_t rs1) {
  return _rv64_rev2(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev(const uint_xlen_t rs1) {
  return _rv64_rev(rs1);
}

// ORC (GORCI) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orcp(const uint_xlen_t rs1) {
  return _rv64_orcp(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc2n(const uint_xlen_t rs1) {
  return _rv64_orc2n(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orcn(const uint_xlen_t rs1) {
  return _rv64_orcn(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc4b(const uint_xlen_t rs1) {
  return _rv64_orc4b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc2b(const uint_xlen_t rs1) {
  return _rv64_orc2b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orcb(const uint_xlen_t rs1) {
  return _rv64_orcb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc8h(const uint_xlen_t rs1) {
  return _rv64_orc8h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc4h(const uint_xlen_t rs1) {
  return _rv64_orc4h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc2h(const uint_xlen_t rs1) {
  return _rv64_orc2h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orch(const uint_xlen_t rs1) {
  return _rv64_orch(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc16w(const uint_xlen_t rs1) {
  return _rv64_orc16w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc8w(const uint_xlen_t rs1) {
  return _rv64_orc8w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc4w(const uint_xlen_t rs1) {
  return _rv64_orc4w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc2w(const uint_xlen_t rs1) {
  return _rv64_orc2w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orcw(const uint_xlen_t rs1) {
  return _rv64_orcw(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc32(const uint_xlen_t rs1) {
  return _rv64_orc32(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc16(const uint_xlen_t rs1) {
  return _rv64_orc16(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc8(const uint_xlen_t rs1) {
  return _rv64_orc8(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc4(const uint_xlen_t rs1) {
  return _rv64_orc4(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc2(const uint_xlen_t rs1) {
  return _rv64_orc2(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc(const uint_xlen_t rs1) {
  return _rv64_orc(rs1);
}

// ZIP (SHFLI) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zipn(const uint_xlen_t rs1) {
  return _rv64_zipn(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip2b(const uint_xlen_t rs1) {
  return _rv64_zip2b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zipb(const uint_xlen_t rs1) {
  return _rv64_zipb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip4h(const uint_xlen_t rs1) {
  return _rv64_zip4h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip2h(const uint_xlen_t rs1) {
  return _rv64_zip2h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_ziph(const uint_xlen_t rs1) {
  return _rv64_ziph(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip8w(const uint_xlen_t rs1) {
  return _rv64_zip8w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip4w(const uint_xlen_t rs1) {
  return _rv64_zip4w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip2w(const uint_xlen_t rs1) {
  return _rv64_zip2w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zipw(const uint_xlen_t rs1) {
  return _rv64_zipw(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip16(const uint_xlen_t rs1) {
  return _rv64_zip16(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip8(const uint_xlen_t rs1) {
  return _rv64_zip8(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip4(const uint_xlen_t rs1) {
  return _rv64_zip4(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip2(const uint_xlen_t rs1) {
  return _rv64_zip2(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip(const uint_xlen_t rs1) {
  return _rv64_zip(rs1);
}

// UNZIP (UNSHFL) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzipn(const uint_xlen_t rs1) {
  return _rv64_unzipn(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip2b(const uint_xlen_t rs1) {
  return _rv64_unzip2b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzipb(const uint_xlen_t rs1) {
  return _rv64_unzipb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip4h(const uint_xlen_t rs1) {
  return _rv64_unzip4h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip2h(const uint_xlen_t rs1) {
  return _rv64_unzip2h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unziph(const uint_xlen_t rs1) {
  return _rv64_unziph(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip8w(const uint_xlen_t rs1) {
  return _rv64_unzip8w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip4w(const uint_xlen_t rs1) {
  return _rv64_unzip4w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip2w(const uint_xlen_t rs1) {
  return _rv64_unzip2w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzipw(const uint_xlen_t rs1) {
  return _rv64_unzipw(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip16(const uint_xlen_t rs1) {
  return _rv64_unzip16(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip8(const uint_xlen_t rs1) {
  return _rv64_unzip8(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip4(const uint_xlen_t rs1) {
  return _rv64_unzip4(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip2(const uint_xlen_t rs1) {
  return _rv64_unzip2(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip(const uint_xlen_t rs1) {
  return _rv64_unzip(rs1);
}

#endif // __RV64BINTRIN_H
