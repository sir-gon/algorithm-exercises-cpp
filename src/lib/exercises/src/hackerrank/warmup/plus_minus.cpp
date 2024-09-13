#include <exercises/hackerrank/warmup/plus_minus.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/plus_minus.md]]
 */

#include <iostream>
#include <string>
#include <vector>

#define BUFFER_MAX_SIZE 100

std::string format_result(double number) {
  char buffer[BUFFER_MAX_SIZE];

  snprintf(buffer, BUFFER_MAX_SIZE, "%0.6lf", number);
  std::string formatted = buffer;

  return formatted;
}

namespace hackerrank::warmup {
std::vector<std::string> plusMinusCalculate(const std::vector<int> &arr) {
  unsigned long positives = 0;
  int negatives = 0;
  int zeros = 0;

  for (const int &value : arr) {
    if (value > 0) {
      positives += 1;
    }
    if (value < 0) {
      negatives += 1;
    }
    if (value == 0) {
      zeros += 1;
    }
  }

  std::vector<double> results = {
      static_cast<double>(positives) / static_cast<double>(arr.size()),
      static_cast<double>(negatives) / static_cast<double>(arr.size()),
      static_cast<double>(zeros) / static_cast<double>(arr.size())};

  std::vector<std::string> answer = {};

  for (double tmp : results) {
    std::string formatted = format_result(tmp);
    answer.emplace_back(formatted);
  }

  return answer;
}

void plusMinus(const std::vector<int> &arr) {
  std::vector<std::string> output = plusMinusCalculate(arr);

  for (const std::string &line : output) {
    std::cout << line << std::endl;
  }
}
} // namespace hackerrank::warmup
