#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/warmup/mini_max_sum.hpp>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("miniMaxSum JSON Test Cases",
          "[hackerrank] [jsontestcase] [warmup]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "mini_max_sum.testcases.json";

  INFO("miniMaxSum JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    std::string result =
        hackerrank::warmup::miniMaxSumCalculate(testcase["input"]);
    hackerrank::warmup::miniMaxSum(testcase["input"]);

    CHECK(result == testcase["expected"]);
  }
}

TEST_CASE("miniMaxSum Edge Cases", "[hackerrank] [warmup]") {
  std::vector<int> empty;
  CHECK_THROWS_AS(hackerrank::warmup::miniMaxSumCalculate(empty),
                  std::invalid_argument);
  CHECK_THROWS_AS(hackerrank::warmup::miniMaxSum(empty), std::invalid_argument);
  CHECK_THROWS_AS(hackerrank::warmup::miniMaxSumCalculate({}),
                  std::invalid_argument);
  CHECK_THROWS_AS(hackerrank::warmup::miniMaxSum({}), std::invalid_argument);
  CHECK_THROWS_AS(hackerrank::warmup::miniMaxSumCalculate({1}),
                  std::invalid_argument);
  CHECK_THROWS_AS(hackerrank::warmup::miniMaxSum({1}), std::invalid_argument);
}
