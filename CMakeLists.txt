cmake_minimum_required(VERSION 3.21)

project(algorithm-exercises-cpp CXX C ASM)

# Option to control whether compiler should save intermediate temps (assembly files)
option(GENERATE_ASM "Generate assembly outputs (*.s) during the build" OFF)

# Allow overriding from environment variable GENERATE_ASM (1/ON to enable)
if(DEFINED ENV{GENERATE_ASM})
  if("$ENV{GENERATE_ASM}" STREQUAL "1" OR "$ENV{GENERATE_ASM}" STREQUAL "ON")
    set(GENERATE_ASM ON CACHE BOOL "Generate assembly outputs" FORCE)
  endif()
endif()

# Must be set before including CTest so that these arguments are applied when
# running `$ ninja test` or `$ make test`.
set(CMAKE_CTEST_ARGUMENTS "--extra-verbose" "--output-junit" "junit.xml")
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")

# This must be in the top-level CMakeLists.txt to enable CMake/CTest support.
include(CTest)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -fsanitize=address causes SIGILL on macOS (Clang 17 + macOS 26 Intel) due to
# ASan runtime incompatibility. Coverage instrumentation still works without it.
if(APPLE)
  if(GENERATE_ASM)
    SET(SAVE_TEMPS_FLAG "-save-temps")
  else()
    SET(SAVE_TEMPS_FLAG "")
  endif()
  SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -g -O0 ${SAVE_TEMPS_FLAG}")
  SET(GCC_COVERAGE_LINK_FLAGS "--coverage")
else()
  if(GENERATE_ASM)
    SET(SAVE_TEMPS_FLAG "-save-temps")
  else()
    SET(SAVE_TEMPS_FLAG "")
  endif()
  SET(GCC_COVERAGE_COMPILE_FLAGS "-fsanitize=address -fprofile-arcs -ftest-coverage -g -O0 ${SAVE_TEMPS_FLAG}")
  SET(GCC_COVERAGE_LINK_FLAGS "--coverage")
endif()

if (CMAKE_GENERATOR MATCHES "Unix Makefiles")

  SET(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
  SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

  SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

endif ()

add_subdirectory(src/lib/exercises)

if(BUILD_TESTING)
  add_subdirectory(src/tests)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
