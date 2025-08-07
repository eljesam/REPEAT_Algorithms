cmake_minimum_required(VERSION 3.31)
project(REPEAT_Algorithms)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
add_executable(
        runTests
        "Tests/tests.cpp"
)
target_link_libraries(runTests gtest_main)
include(GoogleTest)
gtest_discover_tests(runTests)
add_executable(REPEAT_Algorithms src/main.cpp
        "Header Files/MySet.h"
)



