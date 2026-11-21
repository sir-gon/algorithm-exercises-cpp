#include <exercises/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/ctci_ransom_note.hpp>
#include <iostream>
#include <unordered_map>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/two-strings.md]]
 */

namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps {

const std::string __TWO_STRINGS_YES__ = "YES";
const std::string __TWO_STRINGS_NO__ = "NO";

string twoStrings(string s1, string s2) {
  std::unordered_map<char, int> char_map;

  for (char c : s1) {
    char_map[c]++;
  }

  for (char c : s2) {
    if (char_map.find(c) != char_map.end()) {
      return __TWO_STRINGS_YES__;
    }
  }

  return __TWO_STRINGS_NO__;
}

} // namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps
