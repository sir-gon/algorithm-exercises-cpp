#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/warmup/plus_minus.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("plusMinus JSON Test Cases", "[hackerrank] [jsontestcase] [warmup]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "plus_minus.testcases.json";

  INFO("plusMinus JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    hackerrank::warmup::plusMinus(testcase["input"]);
    std::vector<std::string> result =
        hackerrank::warmup::plusMinusCalculate(testcase["input"]);
    CHECK(result == testcase["expected"]);
  }
}
