// 3rd party libs
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>

// local libs
#include <exercises/hackerrank/interview_preparation_kit/arrays/minimum_swaps_2.hpp>

// std libs
#include <filesystem>
#include <fstream>
#include <vector>

using json = nlohmann::json;

TEST_CASE("minimumSwaps JSON Test Cases",
          "[hackerrank] [jsontestcase] [arrays]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "minimum_swaps_2.testcases.json";

  INFO("minimumSwaps JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    INFO("minimumSwaps JSON test case: " << testcase["title"]);

    int result = hackerrank::interview_preparation_kit::arrays::minimumSwaps(
        testcase["input"].get<std::vector<int>>());

    CHECK(result == testcase["expected"].get<int>());
  }
}
