cmake_minimum_required(VERSION 3.21)

project(algoritm-exercises-cpp CXX C ASM)

# Must be set before including CTest so that these arguments are applied when
# running `$ ninja test` or `$ make test`.
set(CMAKE_CTEST_ARGUMENTS "--extra-verbose" "--output-junit" "junit.xml")
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")

# This must be in the top-level CMakeLists.txt to enable CMake/CTest support.
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

SET(GCC_COVERAGE_COMPILE_FLAGS "-fsanitize=address -fprofile-arcs -ftest-coverage -g -O0")
SET(GCC_COVERAGE_LINK_FLAGS "--coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_subdirectory(src/lib/exercises)

if(BUILD_TESTING)
  add_subdirectory(src/tests)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
