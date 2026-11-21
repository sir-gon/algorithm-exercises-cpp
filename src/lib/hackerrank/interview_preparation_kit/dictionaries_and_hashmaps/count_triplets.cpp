#include <algorithm>
#include <exercises/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/count_triplets.hpp>
#include <iostream>
#include <unordered_map>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/count-triplets.md]]
 */

namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps {

long countTriplets(vector<long> arr, long r) {
  long counter = 0;

  for (auto i = arr.begin(); i != arr.end() - 2; ++i) {
    for (auto j = i + 1; j != arr.end() - 1; ++j) {
      counter += std::count_if(j + 1, arr.end(), [i, j, r](const auto &k) {
        return *i * r == *j && *j * r == k;
      });
    }
  }

  return counter;
}

} // namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps
