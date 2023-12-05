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
target_link_libraries(aocday1 day1 GTest::GTest)
add_test(aocday1 aocday1)

# day 2
add_executable(aocday2 day2.cpp)
target_include_directories(aocday2 PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(aocday2 day2 GTest::GTest)
add_test(aocday2 aocday2)

# day 3
add_executable(aocday3 day3.cpp)
target_include_directories(aocday3 PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(aocday3 day3 GTest::GTest)
add_test(aocday3 aocday3)

# day 4
add_executable(aocday4 day4.cpp)
target_include_directories(aocday4 PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(aocday4 day4 GTest::GTest)
add_test(aocday4 aocday4)

# day 5
add_executable(aocday5 day5.cpp)
target_include_directories(aocday5 PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(aocday5 day5 GTest::GTest)
add_test(aocday5 aocday5)