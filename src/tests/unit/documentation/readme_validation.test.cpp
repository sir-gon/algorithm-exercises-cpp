#include <catch2/catch_test_macros.hpp>
#include <filesystem>
#include <fstream>
#include <string>
#include <regex>

namespace {
    std::string readFileContent(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filepath);
        }
        
        std::string content;
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        return content;
    }
}

TEST_CASE("README.md contains expected Apple clang version", "[documentation] [readme]") {
    std::string readmePath = "README.md";
    
    // Check if file exists
    REQUIRE(std::filesystem::exists(readmePath));
    
    std::string content = readFileContent(readmePath);
    
    // Test that the updated Apple clang version is present
    REQUIRE(content.find("Apple clang version 17.0.0 (clang-1700.0.13.5)") != std::string::npos);
    
    // Test that the old version is NOT present
    REQUIRE(content.find("Apple clang version 15.0.0 (clang-1500.3.9.4)") == std::string::npos);
}

TEST_CASE("README.md contains expected target architecture", "[documentation] [readme]") {
    std::string readmePath = "README.md";
    
    // Check if file exists
    REQUIRE(std::filesystem::exists(readmePath));
    
    std::string content = readFileContent(readmePath);
    
    // Test that the updated target architecture is present
    REQUIRE(content.find("Target: x86_64-apple-darwin24.6.0") != std::string::npos);
    
    // Test that the old target architecture is NOT present
    REQUIRE(content.find("Target: x86_64-apple-darwin23.6.0") == std::string::npos);
}

TEST_CASE("README.md contains expected Cppcheck version", "[documentation] [readme]") {
    std::string readmePath = "README.md";
    
    // Check if file exists
    REQUIRE(std::filesystem::exists(readmePath));
    
    std::string content = readFileContent(readmePath);
    
    // Test that the updated Cppcheck version is present
    REQUIRE(content.find("Cppcheck 2.18.0") != std::string::npos);
    
    // Test that the old version is NOT present
    REQUIRE(content.find("Cppcheck 2.15.0") == std::string::npos);
}

TEST_CASE("README.md version information format validation", "[documentation] [readme]") {
    std::string readmePath = "README.md";
    
    // Check if file exists
    REQUIRE(std::filesystem::exists(readmePath));
    
    std::string content = readFileContent(readmePath);
    
    // Validate Apple clang version format using regex
    std::regex clang_pattern(R"(Apple clang version \d+\.\d+\.\d+ \(clang-\d+\.\d+\.\d+\.\d+\))");
    REQUIRE(std::regex_search(content, clang_pattern));
    
    // Validate Cppcheck version format using regex
    std::regex cppcheck_pattern(R"(Cppcheck \d+\.\d+\.\d+)");
    REQUIRE(std::regex_search(content, cppcheck_pattern));
}