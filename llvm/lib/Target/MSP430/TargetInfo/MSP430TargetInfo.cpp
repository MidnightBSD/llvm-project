//===-- MSP430TargetInfo.cpp - MSP430 Target Implementation ---------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "MSP430.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheMSP430Target() {
  static Target TheMSP430Target;
  return TheMSP430Target;
}

extern "C" void LLVMInitializeMSP430TargetInfo() {
  RegisterTarget<Triple::msp430> X(getTheMSP430Target(), "msp430",
                                   "MSP430 [experimental]", "MSP430");
}
