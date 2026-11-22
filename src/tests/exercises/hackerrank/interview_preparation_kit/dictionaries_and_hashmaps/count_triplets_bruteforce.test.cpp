// 3rd party libs
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>

// local libs
#include <exercises/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/count_triplets_1_bruteforce.hpp>

// std libs
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <vector>

using json = nlohmann::json;

TEST_CASE("countTriplets (Brute Force) JSON Test Cases",
          "[hackerrank] [jsontestcase] [dictionaries_and_hashmaps]") {
  SECTION("countTriplets: Normal workflow") {
    std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                                 "count_triplets_1.testcases.json";

    INFO("countTriplets JSON test cases FILE: " << path.string());

    for (auto testcase : json::parse(std::ifstream(path))) {
      INFO("countTriplets JSON test case: " << testcase["title"]);

      long expected = testcase["expected"].get<long>();
      std::vector<long> input_array =
          testcase["input"].get<std::vector<long>>();
      long r = testcase["r"].get<long>();
      long result = hackerrank::interview_preparation_kit::
          dictionaries_and_hashmaps::countTripletsBruteForce(input_array, r);

      CHECK(result == expected);
    }
  }

  SECTION("countTriplets JSON Big cases:") {
    std::filesystem::path path = std::filesystem::path(__FILE__).parent_path() /
                                 "count_triplets_1.big.testcases.json";

    INFO("countTriplets JSON test cases FILE: " << path.string());

    for (auto testcase : json::parse(std::ifstream(path))) {
      INFO("countTriplets JSON test case: " << testcase["title"]);

      long expected = testcase["expected"].get<long>();
      std::vector<long> input_array =
          testcase["input"].get<std::vector<long>>();
      long r = testcase["r"].get<long>();
      long result = hackerrank::interview_preparation_kit::
          dictionaries_and_hashmaps::countTripletsBruteForce(input_array, r);

      CHECK(result == expected);
    }
  }
}
