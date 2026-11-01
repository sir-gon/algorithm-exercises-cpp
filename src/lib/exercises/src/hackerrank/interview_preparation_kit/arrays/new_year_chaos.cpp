#include <stdbool.h>
#include <stdio.h> // snprintf
#include <stdlib.h>

#include <exercises/hackerrank/interview_preparation_kit/arrays/new_year_chaos.hpp>
#include <iostream>
#include <string>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/arrays/new_year_chaos.md]]
 */

constexpr int NEW_YEAR_CHAOS_TOLERANCE = 2;
constexpr const char *MESSAGE = "Too chaotic";

static inline long exercise_max_long(long a, long b) { return a > b ? a : b; }

static inline long exercise_min_long(long a, long b) { return a < b ? a : b; }

namespace hackerrank::interview_preparation_kit::arrays {

// cppcheck-suppress passedByValue
static int minimumBribesCompute(vector<int> q, bool *ok) {
  int bribes = 0;

  for (size_t i = 0; i < q.size(); i++) {
    long position = i + 1;
    long value = q[i];

    if (value - position > NEW_YEAR_CHAOS_TOLERANCE) {
      *ok = false;
      return bribes;
    }

    for (auto k = (size_t)exercise_min_long(
             exercise_max_long(value - NEW_YEAR_CHAOS_TOLERANCE, 0), (long)i);
         k < i; ++k) {
      if (q[k] > value) {
        bribes += 1;
      }
    }
  }

  *ok = true;
  return bribes;
}

// cppcheck-suppress passedByValue
std::string minimumBribesText(vector<int> q) {
  bool ok = false;
  int bribes = minimumBribesCompute(q, &ok);

  if (ok) {
    return std::to_string(bribes);
  }

  return MESSAGE;
}

// cppcheck-suppress passedByValue
void minimumBribes(vector<int> q) { std::cout << minimumBribesText(q) << "\n"; }

} // namespace hackerrank::interview_preparation_kit::arrays
