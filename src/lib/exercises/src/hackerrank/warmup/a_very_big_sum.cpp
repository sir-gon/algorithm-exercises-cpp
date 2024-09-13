#include <exercises/hackerrank/warmup/a_very_big_sum.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/a_very_big_sum.md]]
 */

#include <numeric>
#include <vector>

namespace hackerrank::warmup {

long aVeryBigSum(const std::vector<long> &ar) {
  const long INIT_VALUE = 0L;
  return std::accumulate(ar.begin(), ar.end(), INIT_VALUE);
}

} // namespace hackerrank::warmup
