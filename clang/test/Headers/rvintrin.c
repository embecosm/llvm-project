// RUN: %clang -fsyntax-only               -ffreestanding --target=riscv32 -std=c89 -xc %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -std=c99 -xc %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -std=c11 -xc %s

// RUN: %clang -fsyntax-only               -ffreestanding --target=riscv64 -std=c89 -xc %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -std=c99 -xc %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -std=c11 -xc %s

// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -std=c++98 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -std=c++11 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -std=c++14 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -std=c++17 -xc++ %s

// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -std=c++98 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -std=c++11 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -std=c++14 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -std=c++17 -xc++ %s

// RUN: %clang -fsyntax-only               -ffreestanding --target=riscv32 -Xclang -target-feature -Xclang +b -std=c89 -xc %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -Xclang -target-feature -Xclang +b -std=c99 -xc %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -Xclang -target-feature -Xclang +b -std=c11 -xc %s

// RUN: %clang -fsyntax-only               -ffreestanding --target=riscv64 -Xclang -target-feature -Xclang +b -std=c89 -xc %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -Xclang -target-feature -Xclang +b -std=c99 -xc %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -Xclang -target-feature -Xclang +b -std=c11 -xc %s

// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -Xclang -target-feature -Xclang +b -std=c++98 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -Xclang -target-feature -Xclang +b -std=c++11 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -Xclang -target-feature -Xclang +b -std=c++14 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv32 -Xclang -target-feature -Xclang +b -std=c++17 -xc++ %s

// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -Xclang -target-feature -Xclang +b -std=c++98 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -Xclang -target-feature -Xclang +b -std=c++11 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -Xclang -target-feature -Xclang +b -std=c++14 -xc++ %s
// RUN: %clang -fsyntax-only -Wall -Werror -ffreestanding --target=riscv64 -Xclang -target-feature -Xclang +b -std=c++17 -xc++ %s

#include <rvintrin.h>
