#include <day6.h>
#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <utils/util.h>

TEST(RunSolutions, RunDay6)
{
    Day6 day6;
    auto sample_sol_a = day6.SolvePart1(USE_PATH("input/day6a_sample.txt"));

    EXPECT_TRUE(sample_sol_a.has_value()) << PRINT_ERROR(sample_sol_a.error());
    EXPECT_EQ(sample_sol_a.value(), 288.0);

    auto puzzle_sol_a = day6.SolvePart1(USE_PATH("input/day6_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_a.has_value());
    GTEST_COUT << "day 6a: " << std::fixed << std::setprecision(0) << puzzle_sol_a.value() << std::endl;

    auto sample_sol_b = day6.SolvePart2(USE_PATH("input/day6a_sample.txt"));

    EXPECT_TRUE(sample_sol_b.has_value()) << PRINT_ERROR(sample_sol_b.error());
    EXPECT_EQ(sample_sol_b.value(), 71503.0);

    auto puzzle_sol_b = day6.SolvePart2(USE_PATH("input/day6_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_b.has_value());
    GTEST_COUT << "day 6b: " << std::fixed << std::setprecision(0) << puzzle_sol_b.value() << std::endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}