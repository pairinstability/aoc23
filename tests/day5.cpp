#include <day5.h>
#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <utils/util.h>

TEST(RunSolutions, RunDay5)
{
    Day5 day5;
    auto sample_sol_a = day5.SolvePart1(USE_PATH("input/day5a_sample.txt"));

    EXPECT_TRUE(sample_sol_a.has_value()) << PRINT_ERROR(sample_sol_a.error());
    EXPECT_EQ(sample_sol_a.value(), 35.0);

    auto puzzle_sol_a = day5.SolvePart1(USE_PATH("input/day5_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_a.has_value());
    GTEST_COUT << "day 5a: " << std::fixed << std::setprecision(0) << puzzle_sol_a.value() << std::endl;

    auto sample_sol_b = day5.SolvePart2(USE_PATH("input/day5a_sample.txt"));

    EXPECT_TRUE(sample_sol_b.has_value()) << PRINT_ERROR(sample_sol_b.error());
    EXPECT_EQ(sample_sol_b.value(), 46.0);

    auto puzzle_sol_b = day5.SolvePart2(USE_PATH("input/day5_puzzle.txt"));
    EXPECT_TRUE(puzzle_sol_b.has_value());
    GTEST_COUT << "day 5b: " << std::fixed << std::setprecision(0) << puzzle_sol_b.value() << std::endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}