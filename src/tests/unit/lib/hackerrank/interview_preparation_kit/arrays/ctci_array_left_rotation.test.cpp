// 3rd party libs
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>

// local libs
#include <exercises/hackerrank/interview_preparation_kit/arrays/ctci_array_left_rotation.hpp>

// std libs
#include <filesystem>
#include <fstream>
#include <vector>

using json = nlohmann::json;

TEST_CASE("rotLeft JSON Test Cases", "[jsontestcase] [hackerrank] [arrays]") {
  SECTION("rotLeft: Normal workflow") {
    std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                                 "ctci_array_left_rotation.testcases.json";

    INFO("rotLeft JSON test cases FILE: " << path.string());

    std::ifstream f(path);
    json data = json::parse(f);

    for (const auto &testcase : data) {
      const vector<int> result =
          hackerrank::interview_preparation_kit::arrays::rotLeft(
              testcase["input"], testcase["d_rotations"]);
      CHECK(result == testcase["expected"]);
    }
  }
}
