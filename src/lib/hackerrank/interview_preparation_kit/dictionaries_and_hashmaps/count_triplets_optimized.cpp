#include <exercises/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/count_triplets.hpp>
#include <iostream>
#include <unordered_map>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/count-triplets.md]]
 */

namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps {

long countTripletsOptimized(vector<long> arr, long r) {
  std::unordered_map<long, long> potential_twos;
  std::unordered_map<long, long> potential_threes;
  long counter = 0;

  for (long i : arr) {
    if (potential_threes.find(i) != potential_threes.end()) {
      counter += potential_threes[i];
    }

    if (potential_twos.find(i) != potential_twos.end()) {
      potential_threes[i * r] += potential_twos[i];
    }

    potential_twos[i * r]++;
  }

  return counter;
}

} // namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps
