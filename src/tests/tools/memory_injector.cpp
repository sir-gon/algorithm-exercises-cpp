// cppcheck-suppress unusedFunction

#include "memory_injector.hpp"
#include <cstdlib>

// Hidden state variables local to this translation unit
static bool force_immediate_error = false;
static int allocation_counter = 0;
static int target_fault_allocation = -1;

namespace MemoryInjector {
// cppcheck-suppress unusedFunction
void enable_oom_fault() {
  force_immediate_error = true;
  target_fault_allocation = -1;
}

// cppcheck-suppress unusedFunction
void disable_fault() {
  force_immediate_error = false;
  allocation_counter = 0;
  target_fault_allocation = -1;
}

// cppcheck-suppress unusedFunction
void fail_on_allocation_number(int n) {
  force_immediate_error = false;
  allocation_counter = 0;
  target_fault_allocation = n;
}
} // namespace MemoryInjector

// ── Platform-specific interception ──────────────────────────────────────────

#if defined(__APPLE__)
// macOS: use dyld interposition. No extra linker flags are required.
// The DYLD_INTERPOSE macro creates an entry in the __DATA,__interpose section
// that dyld uses to redirect calls to `malloc` at load time.

#include <malloc/malloc.h>

static void *my_malloc(size_t size) {
  // Case 1: Forced immediate out-of-memory error
  if (force_immediate_error) {
    return nullptr;
  }

  // Case 2: Error on the Nth allocation attempt
  if (target_fault_allocation != -1) {
    allocation_counter++;
    if (allocation_counter == target_fault_allocation) {
      return nullptr;
    }
  }

  // Fall through to the real malloc (resolved via the interpose table)
  return malloc(size);
}

#define DYLD_INTERPOSE(_replacement, _replacee)                                \
  __attribute__((used)) static struct {                                        \
    const void *replacement;                                                   \
    const void *replacee;                                                      \
  } _interpose_##_replacee __attribute__((section("__DATA,__interpose"))) = {  \
      (const void *)(_replacement), (const void *)(_replacee)}

DYLD_INTERPOSE(my_malloc, malloc);

#else
// Linux / GNU ld: use the --wrap=malloc linker flag.
// The linker renames every call to `malloc` → `__wrap_malloc` and makes the
// original symbol available as `__real_malloc`.

extern "C" void *__real_malloc(size_t);

extern "C" void *__wrap_malloc(size_t size) {
  // Case 1: Forced immediate out-of-memory error
  if (force_immediate_error) {
    return nullptr;
  }

  // Case 2: Error on the Nth allocation attempt
  if (target_fault_allocation != -1) {
    allocation_counter++; // NOLINT(cppcoreguidelines-avoid-magic-numbers)
    if (allocation_counter == target_fault_allocation) {
      return nullptr;
    }
  }

  // If it shouldn't fail, call the real system malloc
  return __real_malloc(size);
}
#endif
