#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/warmup/staircase.hpp>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

TEST_CASE("staircase", "[warmup]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "staircase.testcases.json";

  INFO("staircase JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    std::vector<std::string> result =
        hackerrank::warmup::staircaseCalculate(testcase["input"]);
    CHECK(result == testcase["expected"]);

    hackerrank::warmup::staircase(testcase["input"]);
  }
}
