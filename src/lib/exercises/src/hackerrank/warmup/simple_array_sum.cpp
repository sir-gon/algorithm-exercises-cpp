#include <exercises/hackerrank/warmup/simple_array_sum.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/simple_array_sum.md]]
 */

#include <numeric>
#include <vector>

namespace hackerrank::warmup {

    int simpleArraySum(const std::vector<int>& ar) {
        const int INIT_VALUE = 0;
        return std::accumulate(ar.begin(), ar.end(), INIT_VALUE);
    }

}
