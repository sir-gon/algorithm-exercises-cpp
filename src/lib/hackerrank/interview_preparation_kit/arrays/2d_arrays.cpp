
#include <exercises/hackerrank/interview_preparation_kit/arrays/2d_arrays.hpp>

#include <vector>
using std::vector;

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/arrays/2d_arrays.md]]
 */

namespace hackerrank::interview_preparation_kit::arrays {

int hourglassSum(const vector<vector<int>> &arr) {
  int max_sum = -63; // Minimum possible hourglass sum (-9 * 7)
  for (int i = 0; i <= arr.size() - 3; i++) {
    for (int j = 0; j <= arr[0].size() - 3; j++) {
      int current_sum =
          // top
          arr[i][j] + arr[i][j + 1] + arr[i][j + 2] +
          // middle
          arr[i + 1][j + 1] +
          // bottom
          arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
      if (current_sum > max_sum) {
        max_sum = current_sum;
      }
    }
  }
  return max_sum;
}

} // namespace hackerrank::interview_preparation_kit::arrays
