project(testaoc)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

#####################################################################
add_executable(aoc day.cpp)
target_include_directories(aoc PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(aoc day1 day2 day3 day4 day5 day6 GTest::GTest)
add_test(aoc aoc)