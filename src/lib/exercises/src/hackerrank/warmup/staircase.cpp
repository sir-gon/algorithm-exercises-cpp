#include <exercises/hackerrank/warmup/staircase.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace hackerrank::warmup {
std::vector<std::string> staircaseCalculate(int n) {
  std::vector<std::string> answer;

  for (int i = 0; i < n; i++) {
    std::string line = "";

    for (int j = 0; j < n; j++) {
      if (j < n - i - 1) {
        line += " ";
      } else {
        line += "#";
      }
    }
    answer.emplace_back(line);
  }

  return answer;
}

void staircase(int n) {
  std::vector<std::string> output = staircaseCalculate(n);

  for (const std::string &line : output) {
    std::cout << line << std::endl;
  }
}
} // namespace hackerrank::warmup
