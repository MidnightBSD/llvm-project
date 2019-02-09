//===--- MidnightBSD.h - MidnightBSD ToolChain Implementations ----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MIDNIGHTBSD_H
#define LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MIDNIGHTBSD_H

#include "Gnu.h"
#include "clang/Driver/Driver.h"
#include "clang/Driver/ToolChain.h"

namespace clang {
	namespace driver {
		namespace tools {

/// midnightbsd -- Directly call GNU Binutils assembler and linker
			namespace midnightbsd {
				class LLVM_LIBRARY_VISIBILITY Assembler : public GnuTool {
				public:
				Assembler(const ToolChain &TC)
						: GnuTool("midnightbsd::Assembler", "assembler", TC) {}

				bool hasIntegratedCPP() const override { return false; }

			void ConstructJob(Compilation &C, const JobAction &JA,
			                  const InputInfo &Output, const InputInfoList &Inputs,
			                  const llvm::opt::ArgList &TCArgs,
			                  const char *LinkingOutput) const override;
		};

		class LLVM_LIBRARY_VISIBILITY Linker : public GnuTool {
		public:
		Linker(const ToolChain &TC) : GnuTool("midnightbsd::Linker", "linker", TC) {}

		bool hasIntegratedCPP() const override { return false; }
	bool isLinkJob() const override { return true; }

void ConstructJob(Compilation &C, const JobAction &JA,
                  const InputInfo &Output, const InputInfoList &Inputs,
                  const llvm::opt::ArgList &TCArgs,
                  const char *LinkingOutput) const override;
};
} // end namespace midnightbsd
} // end namespace tools

namespace toolchains {

	class LLVM_LIBRARY_VISIBILITY MidnightBSD : public Generic_ELF {
	public:
	MidnightBSD(const Driver &D, const llvm::Triple &Triple,
	        const llvm::opt::ArgList &Args);
	bool HasNativeLLVMSupport() const override;

	bool IsMathErrnoDefault() const override { return false; }
bool IsObjCNonFragileABIDefault() const override { return true; }

CXXStdlibType GetDefaultCXXStdlibType() const override;
void addLibStdCxxIncludePaths(
		const llvm::opt::ArgList &DriverArgs,
		llvm::opt::ArgStringList &CC1Args) const override;
void AddCXXStdlibLibArgs(const llvm::opt::ArgList &Args,
                         llvm::opt::ArgStringList &CmdArgs) const override;

llvm::ExceptionHandling GetExceptionModel(
		const llvm::opt::ArgList &Args) const override;
bool isPIEDefault() const override;
SanitizerMask getSupportedSanitizers() const override;
unsigned GetDefaultDwarfVersion() const override { return 2; }
// Until dtrace (via CTF) and LLDB can deal with distributed debug info,
// MidnightBSD defaults to standalone/full debug info.
bool GetDefaultStandaloneDebug() const override { return true; }

protected:
Tool *buildAssembler() const override;
Tool *buildLinker() const override;
};

} // end namespace toolchains
} // end namespace driver
} // end namespace clang

#endif // LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MIDNIGHTBSD_H
