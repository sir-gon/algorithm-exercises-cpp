// 3rd party libs
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>

// local libs
#include <exercises/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/two_strings.hpp>

// std libs
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <vector>

using json = nlohmann::json;

TEST_CASE("twoStrings JSON Test Cases",
          "[hackerrank] [jsontestcase] [dictionaries_and_hashmaps]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "two_strings.testcases.json";

  INFO("twoStrings JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    INFO("twoStrings JSON test case: " << testcase["title"]);

    std::string expected = testcase["expected"].get<std::string>();
    std::string s1 = testcase["s1"].get<std::string>();
    std::string s2 = testcase["s2"].get<std::string>();

    // print result to get high coverage
    std::string result = hackerrank::interview_preparation_kit::
        dictionaries_and_hashmaps::twoStrings(s1, s2);

    CHECK(result == expected);
  }
}
