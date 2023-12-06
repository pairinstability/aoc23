#include <day2.h>
#include <gtest/gtest.h>
#include <iostream>
#include <utils/util.h>

TEST(RunSolutions, RunDay2)
{
    Day2 day2;
    auto sample_sol_a = day2.SolvePart1(USE_PATH("input/day2a_sample.txt"));

    EXPECT_TRUE(sample_sol_a.has_value()) << PRINT_ERROR(sample_sol_a.error());
    EXPECT_EQ(sample_sol_a.value(), 8.0);

    auto puzzle_sol_a = day2.SolvePart1(USE_PATH("input/day2_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_a.has_value());
    GTEST_COUT << "day 2a: " << puzzle_sol_a.value() << std::endl;

    auto sample_sol_b = day2.SolvePart2(USE_PATH("input/day2a_sample.txt"));

    EXPECT_TRUE(sample_sol_b.has_value()) << PRINT_ERROR(sample_sol_b.error());
    EXPECT_EQ(sample_sol_b.value(), 2286.0);

    auto puzzle_sol_b = day2.SolvePart2(USE_PATH("input/day2_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_b.has_value());
    GTEST_COUT << "day 2b: " << puzzle_sol_b.value() << std::endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}