#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/projecteuler/euler003.hpp>
#include <iostream>
#include <vector>

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("euler003 JSON Test Cases",
          "[hackerrank] [jsontestcase] [projecteuler]") {
  std::filesystem::path cwd = std::filesystem::current_path();
  std::string path =
      cwd.string() +
      "/unit/lib/hackerrank/projecteuler/euler003.testcases.json";

  INFO("euler003 JSON test cases FILE: " << path);

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    long result = hackerrank::projecteuler::euler003(testcase["n"]);
    CHECK(result == testcase["expected"]);
  }
}

TEST_CASE("euler003 Edge Cases", "[hackerrank] [projecteuler]") {
  CHECK_THROWS_AS(hackerrank::projecteuler::euler003(0), std::invalid_argument);
  CHECK_THROWS_AS(hackerrank::projecteuler::euler003(1), std::invalid_argument);
}
