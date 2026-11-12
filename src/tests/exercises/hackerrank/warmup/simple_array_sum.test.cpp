#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/warmup/simple_array_sum.hpp>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

TEST_CASE("simpleArraySum JSON Test Cases",
          "[hackerrank] [jsontestcase] [warmup]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "simple_array_sum.testcases.json";

  INFO("simpleArraySum JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    int result = hackerrank::warmup::simpleArraySum(testcase["input"]);
    CHECK(result == testcase["expected"]);
  }
}
