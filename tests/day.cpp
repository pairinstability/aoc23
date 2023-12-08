#include <day.h>
#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <util.h>

template<typename DayType>
void RunDayTest(double sample_part1, double sample_part2, const char* sample_input, const char* puzzle_input, const char* opt_sample_input)
{
    DayType day;

    auto sample_sol_a = day.SolvePart1(USE_PATH(sample_input));
    EXPECT_TRUE(sample_sol_a.has_value()) << PRINT_ERROR(sample_sol_a.error());
    EXPECT_EQ(sample_sol_a.value(), sample_part1);

    auto puzzle_sol_a = day.SolvePart1(USE_PATH(puzzle_input));
    EXPECT_TRUE(puzzle_sol_a.has_value());
    GTEST_COUT << "Part a: " << puzzle_sol_a.value() << std::endl;

    if (opt_sample_input) {
        auto sample_sol_b = day.SolvePart2(USE_PATH(opt_sample_input));
        EXPECT_TRUE(sample_sol_b.has_value()) << PRINT_ERROR(sample_sol_b.error());
        EXPECT_EQ(sample_sol_b.value(), sample_part2);
    } else {
        auto sample_sol_b = day.SolvePart2(USE_PATH(sample_input));
        EXPECT_TRUE(sample_sol_b.has_value()) << PRINT_ERROR(sample_sol_b.error());
        EXPECT_EQ(sample_sol_b.value(), sample_part2);
    }

    auto puzzle_sol_b = day.SolvePart2(USE_PATH(puzzle_input));
    EXPECT_TRUE(puzzle_sol_b.has_value());
    GTEST_COUT << "Part b: " << std::fixed << std::setprecision(0) << puzzle_sol_b.value() << std::endl;
}

TEST(RunSolutions, RunDay1)
{
    RunDayTest<Day1>(142.0, 281.0, "input/day1a_sample.txt", "input/day1_puzzle.txt", "input/day1b_sample.txt");
}

TEST(RunSolutions, RunDay2)
{
    RunDayTest<Day2>(8.0, 2286.0, "input/day2a_sample.txt", "input/day2_puzzle.txt");
}

TEST(RunSolutions, RunDay3)
{
    RunDayTest<Day3>(4361.0, 467835.0, "input/day3a_sample.txt", "input/day3_puzzle.txt");
}

TEST(RunSolutions, RunDay4)
{
    RunDayTest<Day4>(13.0, 30.0, "input/day4a_sample.txt", "input/day4_puzzle.txt");
}

TEST(RunSolutions, RunDay5)
{
    RunDayTest<Day5>(35.0, 46.0, "input/day5a_sample.txt", "input/day5_puzzle.txt");
}

TEST(RunSolutions, RunDay6)
{
    RunDayTest<Day6>(288.0, 71503.0, "input/day6a_sample.txt", "input/day6_puzzle.txt");
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}