#include <day4.h>
#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <utils/util.h>

TEST(RunSolutions, RunDay4)
{
    Day4 day4;
    auto sample_sol_a = day4.SolvePart1(USE_PATH("input/day4a_sample.txt"));

    EXPECT_TRUE(sample_sol_a.has_value());
    EXPECT_EQ(sample_sol_a.value(), 13.0);

    auto puzzle_sol_a = day4.SolvePart1(USE_PATH("input/day4_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_a.has_value());
    GTEST_COUT << "day 4a: " << puzzle_sol_a.value() << std::endl;

    auto sample_sol_b = day4.SolvePart2(USE_PATH("input/day4a_sample.txt"));

    EXPECT_TRUE(sample_sol_b.has_value());
    EXPECT_EQ(sample_sol_b.value(), 30.0);

    auto puzzle_sol_b = day4.SolvePart2(USE_PATH("input/day4_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_b.has_value());
    GTEST_COUT << "day 4b: " << std::fixed << std::setprecision(0) << puzzle_sol_b.value() << std::endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}