#include <exercises/hackerrank/warmup/staircase.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace hackerrank::warmup {
std::vector<std::string> staircaseCalculate(int n) {
  std::vector<std::string> answer;

  for (int i = 0; i < n; i++) {
    std::string line = ""; // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2

    for (int j = 0; j < n; j++) {
      if (j < n - i - 1) {
        line += " "; // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2
      } else {
        line += "#"; // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2
      }
    }
    answer.emplace_back(line); // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2
  }

  return answer;
} // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2

void staircase(int n) {
  std::vector<std::string> output = staircaseCalculate(n);

  for (const std::string &line : output) {
    std::cout << line << std::endl; // GCOVR_EXCL_BR_WITHOUT_HIT: 2/4
  }
}
} // namespace hackerrank::warmup
