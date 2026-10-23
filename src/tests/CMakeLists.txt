find_package(Catch2 3 REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_path(CATCH_INCLUDE_DIR NAMES catch.hpp PATH_SUFFIXES catch2)

# Create a static library for general test utilities.
file(GLOB_RECURSE TOOLS_SOURCES "tools/*.cpp")
add_library(test_tools STATIC ${TOOLS_SOURCES})

file(GLOB_RECURSE SOURCES "unit/lib/*.cpp")
add_executable(unit-tests_combined ${SOURCES})

set_property(TARGET unit-tests_combined PROPERTY CXX_STANDARD 17)

# Test framework dependencies.
target_link_libraries(unit-tests_combined PRIVATE Catch2::Catch2WithMain)
target_link_libraries(unit-tests_combined PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(unit-tests_combined PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(test_tools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Functionality to test.
target_link_libraries(unit-tests_combined PRIVATE exercises)

target_link_libraries(unit-tests_combined PRIVATE test_tools)
target_link_libraries(test_tools PUBLIC nlohmann_json::nlohmann_json)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

catch_discover_tests(unit-tests_combined WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" DISCOVERY_MODE "PRE_TEST")
