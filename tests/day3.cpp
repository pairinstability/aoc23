#include <day3.h>
#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <utils/util.h>

TEST(RunSolutions, RunDay3)
{
    Day3 day3;
    auto sample_sol_a = day3.SolvePart1(USE_PATH("input/day3a_sample.txt"));

    EXPECT_TRUE(sample_sol_a.has_value());
    EXPECT_EQ(sample_sol_a.value(), 4361.0);

    auto puzzle_sol_a = day3.SolvePart1(USE_PATH("input/day3_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_a.has_value());
    GTEST_COUT << "day 3a: " << puzzle_sol_a.value() << std::endl;

    auto sample_sol_b = day3.SolvePart2(USE_PATH("input/day3a_sample.txt"));

    EXPECT_TRUE(sample_sol_b.has_value());
    EXPECT_EQ(sample_sol_b.value(), 467835.0);

    auto puzzle_sol_b = day3.SolvePart2(USE_PATH("input/day3_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_b.has_value());
    GTEST_COUT << "day 3b: " << std::fixed << std::setprecision(0) << puzzle_sol_b.value() << std::endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}