find_package(Catch2 3 REQUIRED)
find_path(CATCH_INCLUDE_DIR NAMES catch.hpp PATH_SUFFIXES catch2)

file(GLOB_RECURSE SOURCES "unit/lib/*.cpp")
add_executable(unit-tests_combined ${SOURCES})

# Test framework dependencies.
target_link_libraries(unit-tests_combined PRIVATE Catch2::Catch2WithMain)

# Functionality to test.
target_link_libraries(unit-tests_combined PRIVATE exercises)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

catch_discover_tests(unit-tests_combined WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" DISCOVERY_MODE "PRE_TEST")
