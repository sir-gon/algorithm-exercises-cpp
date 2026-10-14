#include <exercises/hackerrank/warmup/plus_minus.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/plus_minus.md]]
 */

#include <iostream>
#include <string>
#include <vector>

const int BUFFER_MAX_SIZE = 10;

std::string format_result(double number) {
  std::string str;
  str.reserve(BUFFER_MAX_SIZE); // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2
  char *buffer = str.data();

  snprintf(buffer, BUFFER_MAX_SIZE, "%0.6lf", number);
  return buffer; // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2
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

  std::vector results = {
      static_cast<double>(positives) / static_cast<double>(arr.size()),
      static_cast<double>(negatives) / static_cast<double>(arr.size()),
      static_cast<double>(zeros) / static_cast<double>(arr.size())};

  std::vector<std::string> answer = {};

  for (double tmp : results) {
    std::string formatted =
        format_result(tmp);         // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2
    answer.emplace_back(formatted); // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2
  }

  return answer;
} // GCOVR_EXCL_BR_WITHOUT_HIT: 1/2

void plusMinus(const std::vector<int> &arr) {
  std::vector<std::string> output = plusMinusCalculate(arr);

  for (const std::string &line : output) {
    std::cout << line << std::endl; // GCOVR_EXCL_BR_WITHOUT_HIT: 2/4
  }
}
} // namespace hackerrank::warmup
