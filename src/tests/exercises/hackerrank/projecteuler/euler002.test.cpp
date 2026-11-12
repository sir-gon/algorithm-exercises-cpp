#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/projecteuler/euler002.hpp>
#include <iostream>
#include <vector>

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("euler002 JSON Test Cases",
          "[hackerrank] [jsontestcase] [projecteuler]") {
  std::filesystem::path path =
      std::filesystem::path(__FILE__).parent_path() / "euler002.testcases.json";

  INFO("euler002 JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    int result = hackerrank::projecteuler::euler002(testcase["n"]);
    CHECK(result == testcase["expected"]);
  }
}
