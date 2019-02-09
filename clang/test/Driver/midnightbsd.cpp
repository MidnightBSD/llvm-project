// RUN: %clangxx %s -### -o %t.o -target amd64-unknown-midnightbsd1.1 -stdlib=platform 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-TEN %s
// RUN: %clangxx %s -### -o %t.o -target amd64-unknown-midnightbsd0.8.5 -stdlib=platform 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-NINE %s
// CHECK-TEN: "-lc++" "-lm"
// CHECK-NINE: "-lstdc++" "-lm"

// RUN: %clangxx %s -### -pg -o %t.o -target amd64-unknown-midnightbsd1.1 -stdlib=platform 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-PG-TEN %s
// RUN: %clangxx %s -### -pg -o %t.o -target amd64-unknown-midnightbsd0.8.5 -stdlib=platform 2>&1 \
// RUN:   | FileCheck --check-prefix=CHECK-PG-NINE %s
// CHECK-PG-TEN: "-lc++_p" "-lm_p"
// CHECK-PG-NINE: "-lstdc++_p" "-lm_p"