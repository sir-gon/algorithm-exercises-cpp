#include <exercises/hackerrank/warmup/diagonal_difference.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/diagonal_difference.md]]
 */

#include <cstddef>
#include <cstdlib>
#include <numeric>
#include <vector>

namespace hackerrank::warmup {
int diagonalDifference(const std::vector<std::vector<int>> &arr) {
  int diag1 = 0;
  int diag2 = 0;
  size_t last = arr.size() - 1L;

  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      if (i == j) {
        diag1 += arr[i][j];
        diag2 += arr[last - i][j];
      }
    }
  }
  return abs(diag1 - diag2);
}
} // namespace hackerrank::warmup
