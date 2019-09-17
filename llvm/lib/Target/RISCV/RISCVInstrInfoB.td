//===-- RISCVInstrFormatsB.td - RISCV B Instruction Formats --*- tablegen -*-=//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
//  This file describes the RISC-V B extension instruction formats.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

def uimm6 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<6>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<6>;
  let DecoderMethod = "decodeUImmOperand<6>";
}

def uimm7 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<7>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<7>;
  let DecoderMethod = "decodeUImmOperand<7>";
}

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

// These templates should be moved to RISCVInstrFormats.td once the B extension has
// been ratified.

class RVBInstShift<bits<5> funct5, bits<3> funct3, RISCVOpcode opcode,
                   string opcodestr>
    : RVInst<(outs GPR:$rd), (ins GPR:$rs1, uimm6:$imm6),
             opcodestr, "$rd, $rs1, $imm6", [], InstFormatI> {
  bits<5> rs1;
  bits<6> imm6;
  bits<5> rd;

  let Inst{31-27} = funct5;
  // NOTE: the shamt bit-field should be 7-bits long, but since that would cause
  // decoding conflicts all the shift operations are encoded with op(26) = 0
  // apart from funnel shifts FSL, FSR and FSRI that have op(26) = 1
  let Inst{26} = 0;
  let Inst{25-20} = imm6;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = opcode.Value;
}

class RVBInstImm7<bits<5> funct5, bits<3> funct3, RISCVOpcode opcode,
                    string opcodestr>
    : RVInst<(outs GPR:$rd), (ins GPR:$rs1, uimm7:$imm7),
             opcodestr, "$rd, $rs1, $imm7", [], InstFormatI> {
  bits<5> rs1;
  bits<7> imm7;
  bits<5> rd;

  let Inst{31-27} = funct5;
  let Inst{26-20} = imm7;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = opcode.Value;
}

class RVBInstImm6<bits<6> funct6, bits<3> funct3, RISCVOpcode opcode,
                    string opcodestr>
    : RVInst<(outs GPR:$rd), (ins GPR:$rs1, uimm6:$imm6),
              opcodestr, "$rd, $rs1, $imm6", [], InstFormatI> {
  bits<5> rs1;
  bits<6> imm6;
  bits<5> rd;

  let Inst{31-26} = funct6;
  let Inst{25-20} = imm6;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = opcode.Value;
}

class RVBInstImm5<bits<7> funct7, bits<3> funct3, RISCVOpcode opcode,
                    string opcodestr>
    : RVInst<(outs GPR:$rd), (ins GPR:$rs1, uimm5:$imm5),
              opcodestr, "$rd, $rs1, $imm5", [], InstFormatI> {
  bits<5> rs1;
  bits<5> imm5;
  bits<5> rd;

  let Inst{31-25} = funct7;
  let Inst{24-20} = imm5;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = opcode.Value;
}

class RVBInstFunct12<bits<12> funct12, bits<3> funct3, RISCVOpcode opcode,
                     string opcodestr>
    : RVInst<(outs GPR:$rd), (ins GPR:$rs1),
             opcodestr, "$rd, $rs1", [], InstFormatI> {
  bits<5> rs1;
  bits<5> rd;

  let Inst{31-20} = funct12;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = opcode.Value;
}

class RVBInstR<bits<7> funct7, bits<3> funct3, string opcodestr>
    : RVInstR<funct7, funct3, OPC_OP_32, (outs GPR:$rd),
              (ins GPR:$rs1, GPR:$rs2), opcodestr, "$rd, $rs1, $rs2"> {}

class RVBInstR4Reg<bits<2> funct2, bits<3> funct3, RISCVOpcode opcode,
                   string opcodestr, string argstr>
    : RVInst<(outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2, GPR:$rs3), opcodestr,
             argstr, [], InstFormatR4> {
  bits<5> rs3;
  bits<5> rs2;
  bits<5> rs1;
  bits<5> rd;

  let Inst{31-27} = rs3;
  let Inst{26-25} = funct2;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = opcode.Value;
}

// Currently implemented only for one instruction FSRIW
class RVBInstR4Imm<bits<2> funct2, bits<3> funct3, RISCVOpcode opcode,
                   string opcodestr>
    : RVInst<(outs GPR:$rd), (ins GPR:$rs1, GPR:$rs3, uimm5:$imm),
             opcodestr, "$rd, $rs1, $rs3, $imm", [], InstFormatR4> {
  bits<5> rs3;
  bits<5> imm;
  bits<5> rs1;
  bits<5> rd;

  let Inst{31-27} = rs3;
  let Inst{26-25} = funct2;
  let Inst{24-20} = imm;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = opcode.Value;
}

// Currently implemented only for one instruction FSRI
class RVBInstR4Imm6<bit funct1, bits<3> funct3, RISCVOpcode opcode,
                    string opcodestr>
    : RVInst<(outs GPR:$rd), (ins GPR:$rs1, GPR:$rs3, uimm5:$imm),
             opcodestr, "$rd, $rs1, $rs3, $imm", [], InstFormatR4> {
  bits<5> rs3;
  bits<6> imm;
  bits<5> rs1;
  bits<5> rd;

  let Inst{31-27} = rs3;
  let Inst{26} = funct1;
  let Inst{25-20} = imm;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Opcode = opcode.Value;
}

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

// Base instructions

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in {
let Predicates = [HasStdExtZbb] in {
  def CLZ  : RVBInstFunct12<0b011000000000, 0b001, OPC_OP_IMM, "clz">;
  def CTZ  : RVBInstFunct12<0b011000000001, 0b001, OPC_OP_IMM, "ctz">;
  def PCNT : RVBInstFunct12<0b011000000010, 0b001, OPC_OP_IMM, "pcnt">;

  def SLO  : ALU_rr<0b0010000, 0b001, "slo">;
  def SRO  : ALU_rr<0b0010000, 0b101, "sro">;
  def SLOI : RVBInstShift<0b00100, 0b001, OPC_OP_IMM, "sloi">;
  def SROI : RVBInstShift<0b00100, 0b101, OPC_OP_IMM, "sroi">;

  def MIN  : ALU_rr<0b0000101, 0b100, "min">;
  def MAX  : ALU_rr<0b0000101, 0b101, "max">;
  def MINU : ALU_rr<0b0000101, 0b110, "minu">;
  def MAXU : ALU_rr<0b0000101, 0b111, "maxu">;

  def SEXTB : RVBInstFunct12<0b011000000100, 0b001, OPC_OP_IMM, "sext.b">;
  def SEXTH : RVBInstFunct12<0b011000000101, 0b001, OPC_OP_IMM, "sext.h">;
}

let Predicates = [HasStdExtZbb, IsRV64] in {
  def CLZW   : RVBInstFunct12<0b011000000000, 0b001, OPC_OP_IMM_32, "clzw">;
  def CTZW   : RVBInstFunct12<0b011000000001, 0b001, OPC_OP_IMM_32, "ctzw">;
  def PCNTW  : RVBInstFunct12<0b011000000010, 0b001, OPC_OP_IMM_32, "pcntw">;
  def SLOW   : RVBInstR<0b0010000, 0b001, "slow">;
  def SROW   : RVBInstR<0b0010000, 0b101, "srow">;
  def SLOIW  : RVBInstImm5<0b0010000, 0b001, OPC_OP_IMM_32, "sloiw">;
  def SROIW  : RVBInstImm5<0b0010000, 0b101, OPC_OP_IMM_32, "sroiw">;
  def ADDIWU : RVInstI<0b100, OPC_OP_IMM_32, (outs GPR:$rd),
                       (ins GPR:$rs1, simm12:$imm12),
                       "addiwu", "$rd, $rs1, $imm12">;

  def SLLIUW : RVBInstShift<0b00001, 0b001, OPC_OP_IMM_32, "slliu.w">;

  def ADDWU : RVBInstR<0b0000101, 0b000, "addwu">;
  def SUBWU : RVBInstR<0b0100101, 0b000, "subwu">;
  def ADDUW : RVBInstR<0b0000100, 0b000, "addu.w">;
  def SUBUW : RVBInstR<0b0100100, 0b000, "subu.w">;
}

// Carry-less instructions

let Predicates = [HasStdExtZbc] in {
  def CLMUL  : ALU_rr<0b0000101, 0b001, "clmul">;
  def CLMULR : ALU_rr<0b0000101, 0b010, "clmulr">;
  def CLMULH : ALU_rr<0b0000101, 0b011, "clmulh">;
}

let Predicates = [HasStdExtZbc, IsRV64] in {
  def CLMULW  : RVBInstR<0b0000101, 0b001, "clmulw">;
  def CLMULRW : RVBInstR<0b0000101, 0b010, "clmulrw">;
  def CLMULHW : RVBInstR<0b0000101, 0b011, "clmulhw">;
}

// Extract-bit/Deposit-bit instructions

let Predicates = [HasStdExtZbe] in {
  def BDEP : ALU_rr<0b0100100, 0b110, "bdep">;
  def BEXT : ALU_rr<0b0000100, 0b110, "bext">;
}

let Predicates = [HasStdExtZbe, IsRV64] in {
  def BDEPW : RVBInstR<0b0100100, 0b110, "bdepw">;
  def BEXTW : RVBInstR<0b0000100, 0b110, "bextw">;
}

// Bit-Field instructions

let Predicates = [HasStdExtZbf] in {
  def BFP : ALU_rr<0b0100100, 0b111, "bfp">;
}

let Predicates = [HasStdExtZbf, IsRV64] in {
  def BFPW : RVBInstR<0b0100100, 0b111, "bfpw">;
}

// Matrix Instructions

let Predicates = [HasStdExtZbm, IsRV64] in {
  def BMATOR   : ALU_rr<0b0000100, 0b011, "bmator">;
  def BMATXOR  : ALU_rr<0b0100100, 0b011, "bmatxor">;
  def BMATFLIP : RVBInstFunct12<0b011000000011, 0b001, OPC_OP_IMM, "bmatflip">;
}

// Bit Permutations Instructions

let Predicates = [HasStdExtZbbOrZbp] in {
  def ANDN  : ALU_rr<0b0100000, 0b111, "andn">;
  def ORN   : ALU_rr<0b0100000, 0b110, "orn">;
  def XNOR  : ALU_rr<0b0100000, 0b100, "xnor">;
  def PACK  : ALU_rr<0b0000100, 0b100, "pack">;
  def PACKU : ALU_rr<0b0100100, 0b100, "packu">;
  def PACKH : ALU_rr<0b0000100, 0b111, "packh">;
  def ROL   : ALU_rr<0b0110000, 0b001, "rol">;
  def ROR   : ALU_rr<0b0110000, 0b101, "ror">;
  def RORI  : RVBInstImm7<0b01100, 0b101, OPC_OP_IMM, "rori">;
}

let Predicates = [HasStdExtZbp] in {
  def GREV   : ALU_rr<0b0110100, 0b101, "grev">;
  def GORC   : ALU_rr<0b0010100, 0b101, "gorc">;
  def SHFL   : ALU_rr<0b0000100, 0b001, "shfl">;
  def UNSHFL : ALU_rr<0b0000100, 0b101, "unshfl">;

  // RVBInstShift sets inst[26] to 0. We use it here to avoid a decoding conflict with FSRI
  def GREVI   : RVBInstShift<0b01101, 0b101, OPC_OP_IMM, "grevi">;
  def GORCI   : RVBInstShift<0b00101, 0b101, OPC_OP_IMM, "gorci">;

  def SHFLI   : RVBInstImm6<0b000010, 0b001, OPC_OP_IMM, "shfli">;
  def UNSHFLI : RVBInstImm6<0b000010, 0b101, OPC_OP_IMM, "unshfli">;
}

let Predicates = [HasStdExtZbbOrZbp, IsRV64] in {
  def ROLW  : RVBInstR<0b0110000, 0b001, "rolw">;
  def RORW  : RVBInstR<0b0110000, 0b101, "rorw">;
  def RORIW : RVBInstImm5<0b0110000, 0b101, OPC_OP_IMM_32, "roriw">;

  def PACKW  : RVBInstR<0b0000100, 0b100, "packw">;
  def PACKUW : RVBInstR<0b0100100, 0b100, "packuw">;
}

let Predicates = [HasStdExtZbp, IsRV64] in {
  def GREVW  : RVBInstR<0b0110100, 0b101, "grevw">;
  def GORCW  : RVBInstR<0b0010100, 0b101, "gorcw">;
  def GREVIW : RVBInstImm5<0b0110100, 0b101, OPC_OP_IMM_32, "greviw">;
  def GORCIW : RVBInstImm5<0b0010100, 0b101, OPC_OP_IMM_32, "gorciw">;

  def SHFLW   : RVBInstR<0b0000100, 0b001, "shflw">;
  def UNSHFLW : RVBInstR<0b0000100, 0b101, "unshflw">;
}

// Polynomial Reduction Instructions

let Predicates = [HasStdExtZbr] in {
  def CRC32B : RVBInstFunct12<0b011000010000, 0b001, OPC_OP_IMM, "crc32.b">;
  def CRC32H : RVBInstFunct12<0b011000010001, 0b001, OPC_OP_IMM, "crc32.h">;
  def CRC32W : RVBInstFunct12<0b011000010010, 0b001, OPC_OP_IMM, "crc32.w">;

  def CRC32CB : RVBInstFunct12<0b011000011000, 0b001, OPC_OP_IMM, "crc32c.b">;
  def CRC32CH : RVBInstFunct12<0b011000011001, 0b001, OPC_OP_IMM, "crc32c.h">;
  def CRC32CW : RVBInstFunct12<0b011000011010, 0b001, OPC_OP_IMM, "crc32c.w">;
}

let Predicates = [HasStdExtZbr, IsRV64] in {
  def CRC32D  : RVBInstFunct12<0b011000010011, 0b001, OPC_OP_IMM, "crc32.d">;
  def CRC32CD : RVBInstFunct12<0b011000011011, 0b001, OPC_OP_IMM, "crc32c.d">;
}

// Single Bit Instructions

let Predicates = [HasStdExtZbs] in {
  def SBSET : ALU_rr<0b0010100, 0b001, "sbset">;
  def SBCLR : ALU_rr<0b0100100, 0b001, "sbclr">;
  def SBINV : ALU_rr<0b0110100, 0b001, "sbinv">;
  def SBEXT : ALU_rr<0b0100100, 0b101, "sbext">;

  def SBSETI : RVBInstImm7<0b00101, 0b001, OPC_OP_IMM, "sbseti">;
  def SBCLRI : RVBInstImm7<0b01001, 0b001, OPC_OP_IMM, "sbclri">;
  def SBINVI : RVBInstImm7<0b01101, 0b001, OPC_OP_IMM, "sbinvi">;
  def SBEXTI : RVBInstImm7<0b01001, 0b101, OPC_OP_IMM, "sbexti">;
}

let Predicates = [HasStdExtZbs, IsRV64] in {
  def SBSETW : RVBInstR<0b0010100, 0b001, "sbsetw">;
  def SBCLRW : RVBInstR<0b0100100, 0b001, "sbclrw">;
  def SBINVW : RVBInstR<0b0110100, 0b001, "sbinvw">;
  def SBEXTW : RVBInstR<0b0100100, 0b101, "sbextw">;

  def SBSETIW : RVBInstImm5<0b0010100, 0b001, OPC_OP_IMM_32, "sbsetiw">;
  def SBCLRIW : RVBInstImm5<0b0100100, 0b001, OPC_OP_IMM_32, "sbclriw">;
  def SBINVIW : RVBInstImm5<0b0110100, 0b001, OPC_OP_IMM_32, "sbinviw">;
}

// Ternary Instructions

let Predicates = [HasStdExtZbt] in {
  def CMIX : RVBInstR4Reg<0b11, 0b001, OPC_OP, "cmix", "$rd, $rs2, $rs1, $rs3">;
  def CMOV : RVBInstR4Reg<0b11, 0b101, OPC_OP, "cmov", "$rd, $rs2, $rs1, $rs3">;
  def FSL  : RVBInstR4Reg<0b10, 0b001, OPC_OP, "fsl", "$rd, $rs1, $rs3, $rs2">;
  def FSR  : RVBInstR4Reg<0b10, 0b101, OPC_OP, "fsr", "$rd, $rs1, $rs3, $rs2">;
  def FSRI : RVBInstR4Imm6<0b1, 0b101, OPC_OP_IMM, "fsri">;
}

let Predicates = [HasStdExtZbt, IsRV64] in {
  def FSLW  : RVBInstR4Reg<0b10, 0b001, OPC_OP_32, "fslw", "$rd, $rs1, $rs3, $rs2">;
  def FSRW  : RVBInstR4Reg<0b10, 0b101, OPC_OP_32, "fsrw", "$rd, $rs1, $rs3, $rs2">;
  def FSRIW : RVBInstR4Imm<0b10, 0b101, OPC_OP_IMM_32, "fsriw">;
}

//===----------------------------------------------------------------------===//
// Future compressed instructions
//===----------------------------------------------------------------------===//

class RVBInstC<bits<2> funct2, string opcodestr>
    : RVInst16<(outs GPR:$rs_wb), (ins GPR:$rs), opcodestr, "$rs", [],
               InstFormatCR> {
  bits<3> rs;
  let Constraints = "$rs = $rs_wb";

  let Inst{12-15} = 0b0110;
  let Inst{10-11} = funct2;
  let Inst{7-9} = rs;
  let Inst{0-6} = 0b0000001;
}

let Predicates = [HasStdExtB, HasStdExtC] in {
  def CNOT : RVBInstC<00, "c.not">;
}

let Predicates = [HasStdExtB, HasStdExtC, IsRV64] in {
  def CZESTW : RVBInstC<01, "c.zest.w">;
}
}  // hasSideEffects = 0, mayLoad = 0, mayStore = 0

//===----------------------------------------------------------------------===//
// Pseudo Instructions
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtZbbOrZbp, IsRV32] in {
  def : InstAlias<"rev $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b11111)>;
  def : InstAlias<"rev2 $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b11110)>;
  def : InstAlias<"rev4 $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b11100)>;
  def : InstAlias<"rev8 $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b11000)>;
  def : InstAlias<"rev16 $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b10000)>;

  def : InstAlias<"orc $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b11111)>;
  def : InstAlias<"orc2 $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b11110)>;
  def : InstAlias<"orc4 $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b11100)>;
  def : InstAlias<"orc8 $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b11000)>;
  def : InstAlias<"orc16 $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b10000)>;

  def : InstAlias<"zip $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b1111)>;
  def : InstAlias<"zip2 $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b1110)>;
  def : InstAlias<"zip4 $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b1100)>;
  def : InstAlias<"zip8 $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b1000)>;
  def : InstAlias<"unzip $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b1111)>;
  def : InstAlias<"unzip2 $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b1110)>;
  def : InstAlias<"unzip4 $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b1100)>;
  def : InstAlias<"unzip8 $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b1000)>;
}

let Predicates = [HasStdExtZbbOrZbp, IsRV64] in {
  def : InstAlias<"rev.w $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b011111)>;
  def : InstAlias<"rev2.w $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b011110)>;
  def : InstAlias<"rev4.w $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b011100)>;
  def : InstAlias<"rev8.w $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b011000)>;
  def : InstAlias<"rev16.w $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b010000)>;
  def : InstAlias<"rev $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b111111)>;
  def : InstAlias<"rev2 $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b111110)>;
  def : InstAlias<"rev4 $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b111100)>;
  def : InstAlias<"rev8 $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b111000)>;
  def : InstAlias<"rev16 $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b110000)>;
  def : InstAlias<"rev32 $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b100000)>;

  def : InstAlias<"orc.w $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b011111)>;
  def : InstAlias<"orc2.w $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b011110)>;
  def : InstAlias<"orc4.w $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b011100)>;
  def : InstAlias<"orc8.w $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b011000)>;
  def : InstAlias<"orc16.w $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b010000)>;
  def : InstAlias<"orc $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b111111)>;
  def : InstAlias<"orc2 $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b111110)>;
  def : InstAlias<"orc4 $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b111100)>;
  def : InstAlias<"orc8 $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b111000)>;
  def : InstAlias<"orc16 $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b110000)>;
  def : InstAlias<"orc32 $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b100000)>;

  def : InstAlias<"zip.w $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b01111)>;
  def : InstAlias<"zip2.w $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b01110)>;
  def : InstAlias<"zip4.w $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b01100)>;
  def : InstAlias<"zip8.w $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b01000)>;
  def : InstAlias<"unzip.w $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b01111)>;
  def : InstAlias<"unzip2.w $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b01110)>;
  def : InstAlias<"unzip4.w $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b01100)>;
  def : InstAlias<"unzip8.w $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b01000)>;
  def : InstAlias<"zip $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b11111)>;
  def : InstAlias<"zip2 $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b11110)>;
  def : InstAlias<"zip4 $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b11100)>;
  def : InstAlias<"zip8 $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b11000)>;
  def : InstAlias<"zip16 $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b10000)>;
  def : InstAlias<"unzip $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b11111)>;
  def : InstAlias<"unzip2 $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b11110)>;
  def : InstAlias<"unzip4 $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b11100)>;
  def : InstAlias<"unzip8 $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b11000)>;
  def : InstAlias<"unzip16 $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b10000)>;
}

let Predicates = [HasStdExtZbbOrZbp] in {
  def : InstAlias<"rev.h $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b01111)>;
  def : InstAlias<"rev.b $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b00111)>;
  def : InstAlias<"rev.n $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b00011)>;
  def : InstAlias<"rev.p $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b00001)>;
  def : InstAlias<"rev2.h $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b01110)>;
  def : InstAlias<"rev2.b $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b00110)>;
  def : InstAlias<"rev2.n $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b00010)>;
  def : InstAlias<"rev4.h $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b01100)>;
  def : InstAlias<"rev4.b $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b00100)>;
  def : InstAlias<"rev8.h $rd, $rs", (GREVI GPR:$rd, GPR:$rs, 0b01000)>;

  def : InstAlias<"orc.h $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b01111)>;
  def : InstAlias<"orc.b $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b00111)>;
  def : InstAlias<"orc.n $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b00011)>;
  def : InstAlias<"orc.p $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b00001)>;
  def : InstAlias<"orc2.h $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b01110)>;
  def : InstAlias<"orc2.b $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b00110)>;
  def : InstAlias<"orc2.n $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b00010)>;
  def : InstAlias<"orc4.h $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b01100)>;
  def : InstAlias<"orc4.b $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b00100)>;
  def : InstAlias<"orc8.h $rd, $rs", (GORCI GPR:$rd, GPR:$rs, 0b01000)>;

  def : InstAlias<"zip.h $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b0111)>;
  def : InstAlias<"zip.b $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b0011)>;
  def : InstAlias<"zip.n $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b0001)>;
  def : InstAlias<"zip2.h $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b0110)>;
  def : InstAlias<"zip2.b $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b0010)>;
  def : InstAlias<"zip4.h $rd, $rs", (SHFLI GPR:$rd, GPR:$rs, 0b0100)>;
  def : InstAlias<"unzip.h $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b0111)>;
  def : InstAlias<"unzip.b $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b0011)>;
  def : InstAlias<"unzip.n $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b0001)>;
  def : InstAlias<"unzip2.h $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b0110)>;
  def : InstAlias<"unzip2.b $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b0010)>;
  def : InstAlias<"unzip4.h $rd, $rs", (UNSHFLI GPR:$rd, GPR:$rs, 0b0100)>;
}
