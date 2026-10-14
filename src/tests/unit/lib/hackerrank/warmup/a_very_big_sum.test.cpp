#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/warmup/a_very_big_sum.hpp>
#include <iostream>
#include <vector>

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("aVeryBigSum JSON Test Cases",
          "[hackerrank] [jsontestcase] [warmup]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "a_very_big_sum.testcases.json";

  INFO("aVeryBigSum JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    long long result = hackerrank::warmup::aVeryBigSum(testcase["input"]);
    CHECK(result == testcase["expected"]);
  }
}
