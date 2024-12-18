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
    throw std::invalid_argument("List too short. Pass at least 2 elements.");
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
  result << tsum - tmax << " " << tsum - tmin;

  return result.str();
}

void miniMaxSum(const std::vector<int> &arr) {
  std::cout << miniMaxSumCalculate(arr) << std::endl;
}

} // namespace hackerrank::warmup
