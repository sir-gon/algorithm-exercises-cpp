// 3rd party libs
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>

#include <exercises/hackerrank/interview_preparation_kit/arrays/crush.hpp>

// std libs
#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <vector>

using json = nlohmann::json;

TEST_CASE("arrayManipulation JSON Test Cases",
          "[jsontestcase] [hackerrank] [arrays]") {
  SECTION("arrayManipulation: Normal workflow") {
    std::filesystem::path path =
        std::filesystem::path(__FILE__).parent_path() / "crush.testcases.json";

    INFO("arrayManipulation JSON test cases FILE: " << path.string());

    std::ifstream f(path);
    json data = json::parse(f);

    for (const auto &testcase : data) {
      const int result =
          hackerrank::interview_preparation_kit::arrays::arrayManipulation(
              testcase["n"], testcase["queries"]);

      CHECK(result == testcase["expected"]);
    }
  }
}
