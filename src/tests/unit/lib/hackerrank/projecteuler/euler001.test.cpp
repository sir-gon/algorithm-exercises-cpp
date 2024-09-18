#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/projecteuler/euler001.hpp>
#include <iostream>
#include <vector>

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("euler001 JSON Test Cases",
          "[hackerrank] [jsontestcase] [projecteuler]") {
  std::filesystem::path cwd = std::filesystem::current_path();
  std::string path =
      cwd.string() +
      "/unit/lib/hackerrank/projecteuler/euler001.testcases.json";

  INFO("euler001 JSON test cases FILE: " << path);

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    int result = hackerrank::projecteuler::euler001(
        testcase["a"], testcase["b"], testcase["n"]);
    CHECK(result == testcase["expected"]);
  }
}
