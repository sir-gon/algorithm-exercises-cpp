#pragma once

#include <string>
#include <vector>

#include "tools/memory_allocator.hpp"

using std::string;
using std::vector;

const std::string __RANSOM_NOTE_YES__ = "Yes";
const std::string __RANSOM_NOTE_NO__ = "No";

namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps {

using tools::getMemoryAllocator;
using tools::MemoryAllocator;
using tools::resetMemoryAllocator;
using tools::setMemoryAllocator;

void checkMagazine(vector<string> magazine, vector<string> note);
const std::string checkMagazineText(const vector<string> &magazine,
                                    const vector<string> &note);

} // namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps
