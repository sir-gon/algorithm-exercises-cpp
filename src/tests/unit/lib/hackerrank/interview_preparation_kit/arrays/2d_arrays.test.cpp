// 3rd party libs
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>

// local libs
#include <exercises/hackerrank/interview_preparation_kit/arrays/2d_arrays.hpp>

// std libs
#include <filesystem>
#include <fstream>
#include <vector>

using json = nlohmann::json;

TEST_CASE("hourglassSum JSON Test Cases",
          "[hackerrank] [jsontestcase] [arrays]") {
  std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                               "2d_arrays.testcases.json";

  INFO("hourglassSum JSON test cases FILE: " << path.string());

  std::ifstream f(path);
  json data = json::parse(f);

  for (auto testcase : data) {
    std::vector<std::vector<int>> matrix = testcase["input"];
    std::vector<int *> rows;
    rows.reserve(matrix.size());

    for (const auto &row : matrix) {
      rows.push_back(const_cast<int *>(row.data()));
    }

    long long result =
        hackerrank::interview_preparation_kit::arrays::hourglassSum(matrix);

    CHECK(result == testcase["expected"]);
  }
}
