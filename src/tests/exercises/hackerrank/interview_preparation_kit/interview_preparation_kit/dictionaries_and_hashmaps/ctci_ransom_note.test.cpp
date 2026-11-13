// 3rd party libs
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>

// local libs
#include <exercises/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/ctci_ransom_note.hpp>

// std libs
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <vector>

#include "tools/memory_allocator.hpp"

using json = nlohmann::json;

TEST_CASE("checkMagazine JSON Test Cases",
          "[hackerrank] [jsontestcase] [dictionaries_and_hashmaps]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "ctci-ransom-note.testcases.json";

  INFO("checkMagazine JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    INFO("checkMagazine JSON test case: " << testcase["title"]);

    std::string expected = testcase["expected"].get<std::string>();
    std::vector<std::string> magazine =
        testcase["magazine"].get<std::vector<std::string>>();
    std::vector<std::string> note =
        testcase["note"].get<std::vector<std::string>>();

    std::string result = hackerrank::interview_preparation_kit::
        dictionaries_and_hashmaps::checkMagazineText(magazine, note);

    // print result to get high coverage
    hackerrank::interview_preparation_kit::dictionaries_and_hashmaps::
        checkMagazine(magazine, note);

    CHECK(result == expected);
  }
}

TEST_CASE("checkMagazine unhappy path cases",
          "[hackerrank] [dictionaries_and_hashmaps] [unhappy]") {
  SECTION("arrayManipulation: magazine has empty word") {
    std::vector<std::string> magazine = {"hello", "world", ""};
    std::vector<std::string> note = {"hello", "world"};

    std::string result = hackerrank::interview_preparation_kit::
        dictionaries_and_hashmaps::checkMagazineText(magazine, note);

    CHECK(result == __RANSOM_NOTE_YES__);
  }

  SECTION(
      "arrayManipulation: note contains a word not present in the magazine") {
    std::vector<std::string> magazine = {"hello", "world"};
    std::vector<std::string> note = {"hello", "missing"};

    std::string result = hackerrank::interview_preparation_kit::
        dictionaries_and_hashmaps::checkMagazineText(magazine, note);

    CHECK(result == __RANSOM_NOTE_NO__);
  }

  SECTION("arrayManipulation: note has many repeated words") {
    std::vector<std::string> magazine = {"hello", "world"};
    std::vector<std::string> note = {"hello", "world", "world", "world"};

    std::string result = hackerrank::interview_preparation_kit::
        dictionaries_and_hashmaps::checkMagazineText(magazine, note);

    CHECK(result == __RANSOM_NOTE_NO__);
  }

  SECTION("arrayManipulation: allocator failure path") {
    using namespace hackerrank::interview_preparation_kit::
        dictionaries_and_hashmaps;

    std::vector<std::string> magazine = {"hello", "world"};
    std::vector<std::string> note = {"out", "of", "world"};

    const auto previous_allocator = tools::getMemoryAllocator();
    tools::setMemoryAllocator([](size_t) -> void * { return nullptr; });

    std::string result = hackerrank::interview_preparation_kit::
        dictionaries_and_hashmaps::checkMagazineText(magazine, note);

    if (previous_allocator != nullptr) {
      tools::setMemoryAllocator(previous_allocator);
    } else {
      tools::resetMemoryAllocator();
    }

    CHECK(result == __RANSOM_NOTE_NO__);
  }

  SECTION("arrayManipulation: non-ascii leading byte is safe") {
    std::vector<std::string> magazine = {"ñandú", "mundo"};
    std::vector<std::string> note = {"ñandú"};

    std::string result = hackerrank::interview_preparation_kit::
        dictionaries_and_hashmaps::checkMagazineText(magazine, note);

    CHECK(result == __RANSOM_NOTE_YES__);
  }
}
