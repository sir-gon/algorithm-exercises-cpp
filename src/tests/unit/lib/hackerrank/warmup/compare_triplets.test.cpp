#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/warmup/compare_triplets.hpp>
#include <iostream>
#include <vector>

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("compareTriplets JSON Test Cases",
          "[hackerrank] [jsontestcase] [warmup]") {
  std::filesystem::path cwd = std::filesystem::current_path();
  std::string path =
      cwd.string() +
      "/unit/lib/hackerrank/warmup/compare_triplets.testcases.json";

  INFO("compareTriplets JSON test cases FILE: " << path);

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    std::vector<int> result =
        hackerrank::warmup::compareTriplets(testcase["a"], testcase["b"]);
    CHECK(result == testcase["expected"]);
  }
}

TEST_CASE("compareTriplets EDGE CASE empty input", "[hackerrank] [warmup]") {
  std::vector<int> a;
  std::vector<int> b;

  std::vector<int> result = hackerrank::warmup::compareTriplets(a, b);

  CHECK(result == std::vector<int>{0, 0});
}
