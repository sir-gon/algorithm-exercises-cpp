#include <stdbool.h>
#include <stdio.h> // snprintf
#include <stdlib.h>

#include <exercises/hackerrank/interview_preparation_kit/arrays/new_year_chaos.hpp>
#include <iostream>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/arrays/new_year_chaos.md]]
 */

#define MAX_SIZE 12
const char *MESSAGE = "Too chaotic\0";
const int NEW_YEAR_CHAOS_TOLERANCE = 2;

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

    for (size_t k = (size_t)exercise_min_long(
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
    static char result[MAX_SIZE];
    snprintf(result, MAX_SIZE, "%d", bribes);
    return result;
  } else {
    return MESSAGE;
  }
}

// cppcheck-suppress passedByValue
void minimumBribes(vector<int> q) { std::cout << minimumBribesText(q) << "\n"; }

} // namespace hackerrank::interview_preparation_kit::arrays
