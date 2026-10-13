#pragma once
#include <cstddef>

namespace MemoryInjector {
// Triggers an immediate malloc failure
void enable_oom_fault();

// Disables the simulator (malloc goes back to normal behavior)
void disable_fault();

// Advanced: Makes malloc succeed N times and fail on the next allocation
void fail_on_allocation_number(int n);
} // namespace MemoryInjector
