#include <exercises/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/ctci_ransom_note.hpp>
#include <iostream>
#include <unordered_map>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/ctci-ransom-note.md]]
 */

namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps {

static bool checkMagazineCompute(const vector<string> &magazine,
                                 const vector<string> &note) {
  std::unordered_map<string, int> word_counts;

  for (const auto &word : magazine) {
    ++word_counts[word];
  }

  for (const auto &word : note) {
    auto it = word_counts.find(word);
    if (it == word_counts.end() || it->second == 0) {
      return false;
    }
    --it->second;
  }

  return true;
}

string checkMagazineText(const vector<string> &magazine,
                         const vector<string> &note) {
  if (!checkMagazineCompute(magazine, note)) {
    return __RANSOM_NOTE_NO__;
  } else {
    return __RANSOM_NOTE_YES__;
  }
}

void checkMagazine(vector<string> magazine, vector<string> note) {
  std::cout << checkMagazineText(magazine, note) << std::endl;
}

} // namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps
