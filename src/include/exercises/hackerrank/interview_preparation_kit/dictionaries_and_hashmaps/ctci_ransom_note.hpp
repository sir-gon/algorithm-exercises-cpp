#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

const std::string __RANSOM_NOTE_YES__ = "Yes";
const std::string __RANSOM_NOTE_NO__ = "No";

namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps {

void checkMagazine(vector<string> magazine, vector<string> note);
std::string checkMagazineText(const vector<string> &magazine,
                              const vector<string> &note);

} // namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps
