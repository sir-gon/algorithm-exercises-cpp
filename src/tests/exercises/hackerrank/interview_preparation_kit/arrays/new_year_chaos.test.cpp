// 3rd party libs
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>

// local libs
#include "tools/json_to_string.hpp"
#include <exercises/hackerrank/interview_preparation_kit/arrays/new_year_chaos.hpp>

// std libs
#include <filesystem>
#include <fstream>
#include <vector>

using json = nlohmann::json;

TEST_CASE("minimumBribes JSON Test Cases",
          "[hackerrank] [jsontestcase] [arrays]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "new_year_chaos.testcases.json";

  INFO("minimumBribes JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    INFO("minimumBribes JSON test case: " << testcase["title"]);

    std::string result =
        hackerrank::interview_preparation_kit::arrays::minimumBribesText(
            testcase["input"]);
    std::string expected = json_to_string(testcase["expected"]);
    hackerrank::interview_preparation_kit::arrays::minimumBribes(
        testcase["input"]); // call print function

    CHECK(result == expected);
  }
}
