#include <exercises/hackerrank/warmup/mini_max_sum.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/mini_max_sum.md]]
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace hackerrank::warmup {
std::string miniMaxSumCalculate(const std::vector<int> &arr) {
  if (arr.size() < 2) {
    // GCOVR_EXCL_START
    throw std::invalid_argument("List too short. Pass at least 2 elements.");
    // GCOVR_EXCL_STOP
  }

  long long tsum = 0;
  long long tmin = arr[0];
  long long tmax = arr[1];

  for (const int &value : arr) {
    auto cvalue = (long long)value;
    tsum += cvalue;
    tmin = std::min(tmin, cvalue);
    tmax = std::max(tmax, cvalue);
  }

  std::stringstream result;

  result << tsum - tmax << " " << tsum - tmin; // GCOVR_EXCL_BR_WITHOUT_HIT: 3/6

  return result.str(); // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2
}

void miniMaxSum(const std::vector<int> &arr) {
  const auto result = miniMaxSumCalculate(arr);
  // GCOVR_EXCL_START
  std::cout << result << std::endl;
  // GCOVR_EXCL_STOP
}

} // namespace hackerrank::warmup
