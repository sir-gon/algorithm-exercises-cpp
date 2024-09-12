#include <exercises/hackerrank/warmup/a_very_big_sum.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/birthday_cake_candles.md]]
 */

#include <vector>

namespace hackerrank::warmup {
    int birthdayCakeCandles(const std::vector<int>& candles) {
        int counter = 0;
        int maximum = candles[0];

        for (const int& element : candles) {
            if (element == maximum) {
                counter += 1;
            }
            if (element > maximum) {
                maximum = element;
                counter = 1;
            }
        }

        return counter;
    }
}
