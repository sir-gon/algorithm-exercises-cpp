#include <catch2/catch_test_macros.hpp>

#include <exercises/hackerrank/warmup/solve_me_first.hpp>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

TEST_CASE("solveMeFirst JSON Test Cases",
          "[hackerrank] [jsontestcase] [warmup]") {
  std::filesystem::path cwd = std::filesystem::current_path();
  std::string path =
      cwd.string() +
      "/unit/lib/hackerrank/warmup/solve_me_first.testcases.json";

  INFO("solveMeFirst JSON test cases FILE: " << path);

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    int result = hackerrank::warmup::solveMeFirst(testcase["a"], testcase["b"]);
    CHECK(result == testcase["expected"]);
  }
}
