#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/warmup/time_conversion.hpp>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

TEST_CASE("time_conversion JSON Test Cases",
          "[hackerrank] [jsontestcase] [warmup]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "time_conversion.testcases.json";

  INFO("time_conversion JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    std::string result = hackerrank::warmup::timeConversion(testcase["input"]);
    CHECK(result == testcase["expected"]);

    hackerrank::warmup::timeConversion(testcase["input"]);
  }
}

TEST_CASE("time_conversion helper functions edge cases",
          "[hackerrank] [helper] [warmup]") {
  CHECK(hackerrank::warmup::firstN("", 10) == "");
  CHECK(hackerrank::warmup::lastN("", 10) == "");

  CHECK(hackerrank::warmup::firstN("", 0) == "");
  CHECK(hackerrank::warmup::lastN("", 0) == "");
}
