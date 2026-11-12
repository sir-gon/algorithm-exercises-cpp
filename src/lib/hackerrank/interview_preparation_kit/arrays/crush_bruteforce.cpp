#include <exercises/hackerrank/interview_preparation_kit/arrays/crush.hpp>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/arrays/crush.md]]
 */

static inline long exercise_max_long(long a, long b) { return a > b ? a : b; }

namespace hackerrank::interview_preparation_kit::arrays {

// cppcheck-suppress passedByValue
long arrayManipulation(int n, vector<vector<int>> queries) {
  // why adding 2?
  //   first slot to adjust 1-based index and
  //   last slot for storing accum_sum result
  vector result((size_t)(n + 1), 0L);
  long maximum = 0;

  for (int i = 0; i <= n; i++) {
    result[i] = 0;
  }

  for (const auto &query : queries) {
    int a = query[0];
    int b = query[1];
    int k = query[2];

    for (int l = a; l <= b; l++) {
      result[l] += k;
    }
  }

  for (int i = 1; i < n + 1; i++) {
    long value = result[i];
    maximum = exercise_max_long(maximum, value);
  }

  return maximum;
}
} // namespace hackerrank::interview_preparation_kit::arrays
