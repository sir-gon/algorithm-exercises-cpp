#include <stdlib.h>

#include <exercises/hackerrank/interview_preparation_kit/arrays/ctci_array_left_rotation.hpp>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/arrays/ctci_array_left_rotation.md]]
 */

namespace hackerrank::interview_preparation_kit::arrays {

// cppcheck-suppress passedByValue
vector<int> rotLeft(vector<int> a, int d) {
  size_t a_count = a.size();
  std::vector result(a_count, 0);

  int rotations = d % a.size();

  for (int i = 0; i < a_count; ++i) {
    size_t new_position = (i + a_count - rotations) % a_count;
    result[new_position] = a[i];
  }

  return result;
}

} // namespace hackerrank::interview_preparation_kit::arrays
