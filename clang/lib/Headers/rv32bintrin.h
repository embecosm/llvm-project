/* ===-------- rv32bintrin.h -----------------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RV32BINTRIN_H
#define __RV32BINTRIN_H

#ifndef __RVINTRIN_H
#error "Never use <rv32bintrin.h> directly; include <rvintrin.h> instead."
#endif

#include "rv32bintrin-builtins.h"

#if defined(__riscv_bitmanip)

#include "rvbintrin-asm.h"

#else // Bitmanip extension is disabled.

#include "rv32bintrin-emulation.h"

#endif // defined(__riscv_bitmanip)

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_andn(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_andn(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_fsl(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return _rv_fsl(rs1, rs2, rs3);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_fsr(const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return _rv_fsr(rs1, rs2, rs3);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_max(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_max(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_maxu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_maxu(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_min(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_min(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_minu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_minu(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orn(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_orn(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rol(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_rol(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_ror(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_ror(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_bdep(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_bdep(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_bext(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_bext(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_bfp(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_bfp(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_clmul(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_clmul(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_clmulh(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_clmulh(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_clmulr(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_clmulr(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS _rv32_cmix(
    const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return _rv_cmix(rs1, rs2, rs3);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS _rv32_cmov(
    const uint_xlen_t rs1, const uint_xlen_t rs2, const uint_xlen_t rs3) {
  return _rv_cmov(rs1, rs2, rs3);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_crc32b(const uint_xlen_t rs1) {
  return _rv_crc32b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_crc32h(const uint_xlen_t rs1) {
  return _rv_crc32h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_crc32w(const uint_xlen_t rs1) {
  return _rv_crc32w(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_crc32cb(const uint_xlen_t rs1) {
  return _rv_crc32cb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_crc32ch(const uint_xlen_t rs1) {
  return _rv_crc32cb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_crc32cw(const uint_xlen_t rs1) {
  return _rv_crc32cb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_gorc(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_gorc(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_grev(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_grev(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_pack(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_pack(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_packu(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_packu(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_packh(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_packh(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_sextb(const uint_xlen_t rs1) {
  return _rv_sextb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_sexth(const uint_xlen_t rs1) {
  return _rv_sexth(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_sbclr(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sbclr(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_sbext(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sbext(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_sbinv(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sbinv(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_sbset(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sbset(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_shfl(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_shfl(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_slo(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_slo(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_sro(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_sro(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unshfl(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_unshfl(rs1, rs2);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_xnor(const uint_xlen_t rs1, const uint_xlen_t rs2) {
  return _rv_xnor(rs1, rs2);
}

// Pseudo Instructions

// REV (GREVI) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_revp(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b00001);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev2n(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b00010);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_revn(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b00011);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev4b(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b00100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev2b(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b00110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_revb(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b00111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev8h(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b01000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev4h(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b01100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev2h(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b01110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_revh(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b01111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev16(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b10000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev8(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b11000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev4(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b11100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev2(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b11110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_rev(const uint_xlen_t rs1) {
  return _rv32_grev(rs1, 0b11111);
}

// ORC (GORCI) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orcp(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b00001);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc2n(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b00010);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orcn(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b00011);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc4b(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b00100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc2b(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b00110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orcb(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b00111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc8h(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b01000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc4h(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b01100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc2h(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b01110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orch(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b01111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc16(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b10000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc8(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b11000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc4(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b11100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc2(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b11110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_orc(const uint_xlen_t rs1) {
  return _rv32_gorc(rs1, 0b11111);
}

// ZIP (SHFLI) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_zipn(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b0001);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_zip2b(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b0010);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_zipb(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b0011);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_zip4h(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b0100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_zip2h(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b0110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_ziph(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b0111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_zip8(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b1000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_zip4(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b1100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_zip2(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b1110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_zip(const uint_xlen_t rs1) {
  return _rv32_shfl(rs1, 0b1111);
}

// UNZIP (UNSHFL) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unzipn(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b0001);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unzip2b(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b0010);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unzipb(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b0011);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unzip4h(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b0100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unzip2h(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b0110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unziph(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b0111);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unzip8(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b1000);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unzip4(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b1100);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unzip2(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b1110);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv32_unzip(const uint_xlen_t rs1) {
  return _rv32_unshfl(rs1, 0b1111);
}

// Genric aliases for 32 bit pseudo instructions
// e.g. _rv_* is an alias of _rv32_*

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_revp(const uint_xlen_t rs1) {
  return _rv32_revp(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev2n(const uint_xlen_t rs1) {
  return _rv32_rev2n(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_revn(const uint_xlen_t rs1) {
  return _rv32_revn(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev4b(const uint_xlen_t rs1) {
  return _rv32_rev4b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev2b(const uint_xlen_t rs1) {
  return _rv32_rev2b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_revb(const uint_xlen_t rs1) {
  return _rv32_revb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev8h(const uint_xlen_t rs1) {
  return _rv32_rev8h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev4h(const uint_xlen_t rs1) {
  return _rv32_rev4h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev2h(const uint_xlen_t rs1) {
  return _rv32_rev2h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_revh(const uint_xlen_t rs1) {
  return _rv32_revh(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev16(const uint_xlen_t rs1) {
  return _rv32_rev16(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev8(const uint_xlen_t rs1) {
  return _rv32_rev8(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev4(const uint_xlen_t rs1) {
  return _rv32_rev4(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev2(const uint_xlen_t rs1) {
  return _rv32_rev2(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_rev(const uint_xlen_t rs1) {
  return _rv32_rev(rs1);
}

// ORC (GORCI) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orcp(const uint_xlen_t rs1) {
  return _rv32_orcp(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc2n(const uint_xlen_t rs1) {
  return _rv32_orc2n(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orcn(const uint_xlen_t rs1) {
  return _rv32_orcn(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc4b(const uint_xlen_t rs1) {
  return _rv32_orc4b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc2b(const uint_xlen_t rs1) {
  return _rv32_orc2b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orcb(const uint_xlen_t rs1) {
  return _rv32_orcb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc8h(const uint_xlen_t rs1) {
  return _rv32_orc8h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc4h(const uint_xlen_t rs1) {
  return _rv32_orc4h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc2h(const uint_xlen_t rs1) {
  return _rv32_orc2h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orch(const uint_xlen_t rs1) {
  return _rv32_orch(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc16(const uint_xlen_t rs1) {
  return _rv32_orc16(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc8(const uint_xlen_t rs1) {
  return _rv32_orc8(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc4(const uint_xlen_t rs1) {
  return _rv32_orc4(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc2(const uint_xlen_t rs1) {
  return _rv32_orc2(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_orc(const uint_xlen_t rs1) {
  return _rv32_orc(rs1);
}

// ZIP (SHFLI) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zipn(const uint_xlen_t rs1) {
  return _rv32_zipn(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip2b(const uint_xlen_t rs1) {
  return _rv32_zip2b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zipb(const uint_xlen_t rs1) {
  return _rv32_zipb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip4h(const uint_xlen_t rs1) {
  return _rv32_zip4h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip2h(const uint_xlen_t rs1) {
  return _rv32_zip2h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_ziph(const uint_xlen_t rs1) {
  return _rv32_ziph(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip8(const uint_xlen_t rs1) {
  return _rv32_zip8(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip4(const uint_xlen_t rs1) {
  return _rv32_zip4(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip2(const uint_xlen_t rs1) {
  return _rv32_zip2(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_zip(const uint_xlen_t rs1) {
  return _rv32_zip(rs1);
}

// UNZIP (UNSHFL) pseudo instructions

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzipn(const uint_xlen_t rs1) {
  return _rv32_unzipn(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip2b(const uint_xlen_t rs1) {
  return _rv32_unzip2b(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzipb(const uint_xlen_t rs1) {
  return _rv32_unzipb(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip4h(const uint_xlen_t rs1) {
  return _rv32_unzip4h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip2h(const uint_xlen_t rs1) {
  return _rv32_unzip2h(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unziph(const uint_xlen_t rs1) {
  return _rv32_unziph(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip8(const uint_xlen_t rs1) {
  return _rv32_unzip8(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip4(const uint_xlen_t rs1) {
  return _rv32_unzip4(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip2(const uint_xlen_t rs1) {
  return _rv32_unzip2(rs1);
}

static __inline__ uint_xlen_t __DEFAULT_FN_ATTRS
_rv_unzip(const uint_xlen_t rs1) {
  return _rv32_unzip(rs1);
}

#endif // __RV32BINTRIN_H
