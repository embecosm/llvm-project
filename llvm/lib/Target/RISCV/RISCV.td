//===-- RISCV.td - Describe the RISCV Target Machine -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// RISC-V subtarget features and instruction predicates.
//===----------------------------------------------------------------------===//

def FeatureStdExtM
    : SubtargetFeature<"m", "HasStdExtM", "true",
                       "'M' (Integer Multiplication and Division)">;
def HasStdExtM : Predicate<"Subtarget->hasStdExtM()">,
                           AssemblerPredicate<"FeatureStdExtM">;

def FeatureStdExtA
    : SubtargetFeature<"a", "HasStdExtA", "true",
                       "'A' (Atomic Instructions)">;
def HasStdExtA : Predicate<"Subtarget->hasStdExtA()">,
                           AssemblerPredicate<"FeatureStdExtA">;

def FeatureStdExtF
    : SubtargetFeature<"f", "HasStdExtF", "true",
                       "'F' (Single-Precision Floating-Point)">;
def HasStdExtF : Predicate<"Subtarget->hasStdExtF()">,
                           AssemblerPredicate<"FeatureStdExtF">;

def FeatureStdExtD
    : SubtargetFeature<"d", "HasStdExtD", "true",
                       "'D' (Double-Precision Floating-Point)",
                       [FeatureStdExtF]>;
def HasStdExtD : Predicate<"Subtarget->hasStdExtD()">,
                           AssemblerPredicate<"FeatureStdExtD">;

def FeatureStdExtC
    : SubtargetFeature<"c", "HasStdExtC", "true",
                       "'C' (Compressed Instructions)">;
def HasStdExtC : Predicate<"Subtarget->hasStdExtC()">,
                           AssemblerPredicate<"FeatureStdExtC">;

def FeatureExtZbb
    : SubtargetFeature<"bb", "HasStdExtZbb", "true",
                       "'Zbb' (Base Bit Manipulation Instructions)">;
def HasStdExtZbb : Predicate<"Subtarget->hasStdExtZbb()">,
                           AssemblerPredicate<"FeatureExtZbb">;

def FeatureExtZbc
    : SubtargetFeature<"bc", "HasStdExtZbc", "true",
                       "'Zbc' (Carry-Less Bit Manipulation Instructions)">;
def HasStdExtZbc : Predicate<"Subtarget->hasStdExtZbc()">,
                           AssemblerPredicate<"FeatureExtZbc">;

def FeatureExtZbe
    : SubtargetFeature<"be", "HasStdExtZbe", "true",
                       "'Zbe' (Extract-Deposit Bit Manipulation Instructions)">;
def HasStdExtZbe : Predicate<"Subtarget->hasStdExtZbe()">,
                           AssemblerPredicate<"FeatureExtZbe">;

def FeatureExtZbf
    : SubtargetFeature<"bf", "HasStdExtZbf", "true",
                       "'Zbf' (Bit-Field Bit Manipulation Instructions)">;
def HasStdExtZbf : Predicate<"Subtarget->hasStdExtZbf()">,
                           AssemblerPredicate<"FeatureExtZbf">;

def FeatureExtZbm
    : SubtargetFeature<"bm", "HasStdExtZbm", "true",
                       "'Zbm' (Matrix Bit Manipulation Instructions)">;
def HasStdExtZbm : Predicate<"Subtarget->hasStdExtZbm()">,
                           AssemblerPredicate<"FeatureExtZbm">;

def FeatureExtZbp
    : SubtargetFeature<"bp", "HasStdExtZbp", "true",
                       "'Zbp' (Permutation Bit Manipulation Instructions)">;
def HasStdExtZbp : Predicate<"Subtarget->hasStdExtZbp()">,
                           AssemblerPredicate<"FeatureExtZbp">;

def FeatureExtZbr
    : SubtargetFeature<"br", "HasStdExtZbr", "true",
                       "'Zbr' (Polynomial Reduction Bit Manipulation Instructions)">;
def HasStdExtZbr : Predicate<"Subtarget->hasStdExtZbr()">,
                           AssemblerPredicate<"FeatureExtZbr">;

def FeatureExtZbs
    : SubtargetFeature<"bs", "HasStdExtZbs", "true",
                       "'Zbs' (Single-Bit Bit Manipulation Instructions)">;
def HasStdExtZbs : Predicate<"Subtarget->hasStdExtZbs()">,
                           AssemblerPredicate<"FeatureExtZbs">;

def FeatureExtZbt
    : SubtargetFeature<"bt", "HasStdExtZbt", "true",
                       "'Zbt' (Ternary Bit Manipulation Instructions)">;
def HasStdExtZbt : Predicate<"Subtarget->hasStdExtZbt()">,
                           AssemblerPredicate<"FeatureExtZbt">;

// For instructions that belong to both the basic and the permutation subextensions.
// They should be added if any of the two subextension has been specified.
def HasStdExtZbbOrZbp
    : Predicate<"Subtarget->hasStdExtZbb() || Subtarget->hasStdExtZbp()">;

def FeatureStdExtB
    : SubtargetFeature<"b", "HasStdExtB", "true",
                       "'B' (Bit Manipulation Instructions)",
                                [FeatureExtZbb,
                                 FeatureExtZbc,
                                 FeatureExtZbe,
                                 FeatureExtZbf,
                                 FeatureExtZbm,
                                 FeatureExtZbp,
                                 FeatureExtZbr,
                                 FeatureExtZbs,
                                 FeatureExtZbt]>;
def HasStdExtB : Predicate<"Subtarget->hasStdExtB()">,
                           AssemblerPredicate<"FeatureStdExtB">;

def FeatureRVCHints
    : SubtargetFeature<"rvc-hints", "EnableRVCHintInstrs", "true",
                       "Enable RVC Hint Instructions.">;
def HasRVCHints : Predicate<"Subtarget->enableRVCHintInstrs()">,
                            AssemblerPredicate<"FeatureRVCHints">;

def Feature64Bit
    : SubtargetFeature<"64bit", "HasRV64", "true", "Implements RV64">;
def IsRV64 : Predicate<"Subtarget->is64Bit()">,
                       AssemblerPredicate<"Feature64Bit">;
def IsRV32 : Predicate<"!Subtarget->is64Bit()">,
                       AssemblerPredicate<"!Feature64Bit">;

def RV64           : HwMode<"+64bit">;
def RV32           : HwMode<"-64bit">;

def FeatureRV32E
    : SubtargetFeature<"e", "IsRV32E", "true",
                       "Implements RV32E (provides 16 rather than 32 GPRs)">;
def IsRV32E : Predicate<"Subtarget->isRV32E()">,
                        AssemblerPredicate<"FeatureRV32E">;

def FeatureRelax
    : SubtargetFeature<"relax", "EnableLinkerRelax", "true",
                       "Enable Linker relaxation.">;

foreach i = {1-31} in
    def FeatureReserveX#i :
        SubtargetFeature<"reserve-x"#i, "UserReservedRegister[RISCV::X"#i#"]",
                         "true", "Reserve X"#i>;

def FeatureSaveRestore : SubtargetFeature<"save-restore", "EnableSaveRestore",
                                          "true", "Enable save/restore.">;

//===----------------------------------------------------------------------===//
// Named operands for CSR instructions.
//===----------------------------------------------------------------------===//

include "RISCVSystemOperands.td"

//===----------------------------------------------------------------------===//
// Registers, calling conventions, instruction descriptions.
//===----------------------------------------------------------------------===//

include "RISCVRegisterInfo.td"
include "RISCVCallingConv.td"
include "RISCVInstrInfo.td"
include "RISCVRegisterBanks.td"

//===----------------------------------------------------------------------===//
// RISC-V processors supported.
//===----------------------------------------------------------------------===//

def : ProcessorModel<"generic-rv32", NoSchedModel, [FeatureRVCHints]>;

def : ProcessorModel<"generic-rv64", NoSchedModel, [Feature64Bit,
                     FeatureRVCHints]>;

//===----------------------------------------------------------------------===//
// Define the RISC-V target.
//===----------------------------------------------------------------------===//

def RISCVInstrInfo : InstrInfo {
  let guessInstructionProperties = 0;
}

def RISCVAsmParser : AsmParser {
  let ShouldEmitMatchRegisterAltName = 1;
  let AllowDuplicateRegisterNames = 1;
}

def RISCVAsmWriter : AsmWriter {
  int PassSubtarget = 1;
}

def RISCV : Target {
  let InstructionSet = RISCVInstrInfo;
  let AssemblyParsers = [RISCVAsmParser];
  let AssemblyWriters = [RISCVAsmWriter];
  let AllowRegisterRenaming = 1;
}
