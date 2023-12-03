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
# each solution
# day 1
add_executable(aocday1 day1.cpp)
target_include_directories(aocday1 PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(
    aocday1
    day1
    GTest::GTest
)

add_test(aocday1 aocday1)

# day 2
add_executable(aocday2 day2.cpp)
target_include_directories(aocday2 PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(
    aocday2
    day2
    GTest::GTest
)

add_test(aocday2 aocday2)