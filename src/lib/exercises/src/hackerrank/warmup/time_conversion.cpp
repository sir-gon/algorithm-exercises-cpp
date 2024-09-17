#include <exercises/hackerrank/warmup/time_conversion.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/time_conversion.md]]
 */

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace hackerrank::warmup {

std::string firstN(const std::string_view &input, unsigned long n) {
  unsigned long inputSize = input.size();
  return static_cast<std::string>((n > 0 && inputSize > n) ? input.substr(0, n)
                                                           : "");
}

std::string lastN(const std::string_view &input, unsigned long n) {
  unsigned long inputSize = input.size();
  return static_cast<std::string>(
      (n > 0 && inputSize > n) ? input.substr(inputSize - n) : "");
}

std::string timeConversion(const std::string &s) {
  char TIME_SEPARATOR = ':';
  std::string meridian = lastN(s, 2);

  auto time_str = std::stringstream(firstN(s, s.size() - 2));
  std::string segment;
  std::vector<std::string> time;

  while (std::getline(time_str, segment, TIME_SEPARATOR)) {
    time.push_back(segment);
  }

  std::stringstream hour_str;
  hour_str << time[0];

  int hour;
  hour_str >> hour;

  if (hour >= 12) {
    hour = 0;
  }

  if (meridian.compare("PM") == 0) {
    hour += 12;
  }

  hour_str.str("");
  hour_str.clear();
  hour_str << std::setfill('0') << std::setw(2) << hour;
  time[0] = hour_str.str();

  std::string conversion;
  unsigned long tsize = time.size();
  for (int i = 0; i < tsize; i++) {
    conversion += time[i];
    if (i < tsize - 1) {
      conversion += ":";
    }
  }

  return conversion;
}

} // namespace hackerrank::warmup
