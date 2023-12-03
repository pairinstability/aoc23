#include <day1.h>
#include <gtest/gtest.h>
#include <iostream>
#include <utils/util.h>

TEST(RunSolutions, RunDay1)
{
    Day1 day1;
    auto sample_sol_a = day1.SolvePart1(PATH "input/day1a_sample.txt");

    EXPECT_TRUE(sample_sol_a.has_value());
    EXPECT_EQ(sample_sol_a.value(), 142.0);

    auto puzzle_sol_a = day1.SolvePart1(PATH "input/day1_puzzle.txt");
    EXPECT_TRUE(puzzle_sol_a.has_value());
    GTEST_COUT << "day 1a: " << puzzle_sol_a.value() << std::endl;

    auto sample_sol_b = day1.SolvePart2(PATH "input/day1b_sample.txt");

    EXPECT_TRUE(sample_sol_b.has_value());
    EXPECT_EQ(sample_sol_b.value(), 281.0);

    auto puzzle_sol_b = day1.SolvePart2(PATH "input/day1_puzzle.txt");
    EXPECT_TRUE(puzzle_sol_b.has_value());
    GTEST_COUT << "day 1b: " << puzzle_sol_b.value() << std::endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}