#include <stdlib.h>

#include <exercises/hackerrank/interview_preparation_kit/arrays/minimum_swaps_2.hpp>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/arrays/minimum_swaps_2.md]]
 */

namespace hackerrank::interview_preparation_kit::arrays {

// cppcheck-suppress passedByValue
int minimumSwaps(vector<int> arr) {
  vector<int> indexed_group(arr.begin(), arr.end());

  for (int i = 0; i < indexed_group.size(); i++) {
    indexed_group[i] = arr[i] - 1;
  }

  int swaps = 0;
  int index = 0;

  while (index < arr.size()) {
    if (indexed_group[index] == index) {
      index += 1;
    } else {
      int temp = indexed_group[index];
      indexed_group[index] = indexed_group[temp];
      indexed_group[temp] = temp;
      swaps += 1;
    }
  }

  return swaps;
}

} // namespace hackerrank::interview_preparation_kit::arrays
