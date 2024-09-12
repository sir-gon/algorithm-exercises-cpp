#include <exercises/hackerrank/warmup/compare_triplets.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/compare_triplets.md]]
 */

#include <vector>

namespace hackerrank::warmup {

    std::vector<int> compareTriplets(const std::vector<int>& a, const std::vector<int>& b) {
        std::vector<int> awards = {0, 0};

        int i = 0;
        for (const int& value : a) {
            if (value > b[i]) {
                awards[0] = awards[0] + 1;
            }
            if (value < b[i]) {
                awards[1] = awards[1] + 1;
            }

            i += 1;
        }
        return awards;
    }

}
