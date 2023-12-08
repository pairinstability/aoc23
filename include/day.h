#ifndef AOC_DAY_H_
#define AOC_DAY_H_

#include <advent_solver.h>

// sample_part1 and sample_part2 are the sample solutions for testing
// sample_input and puzzle_input are paths to the text inputs.
// opt_sample_input is if the day uses a different sample for part2. rare.
template<typename DayType>
void RunDayTest(double sample_part1, double sample_part2, const char* sample_input, const char* puzzle_input, const char* opt_sample_input = nullptr);

class Day1 : public AdventSolver {
public:
    std::expected<double, Error::generic_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::generic_error> SolvePart2(const std::string& input) override;
};

class Day2 : public AdventSolver {
public:
    std::expected<double, Error::generic_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::generic_error> SolvePart2(const std::string& input) override;
};

class Day3 : public AdventSolver {
public:
    std::expected<double, Error::generic_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::generic_error> SolvePart2(const std::string& input) override;

    struct Number {
        int num, row, start, end;
    };
    struct Symbol {
        char type;
        int row, col;
    };

    bool is_adjacent(Number& num, Symbol& sym);
    void parse_input(std::vector<std::string>& input, std::vector<Number>& numbers, std::vector<Symbol>& symbols);
};

class Day4 : public AdventSolver {
public:
    std::expected<double, Error::generic_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::generic_error> SolvePart2(const std::string& input) override;

    struct Card {
        int wins = 0;
        int copies = 1;
    };
};

class Day5 : public AdventSolver {
public:
    std::expected<double, Error::generic_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::generic_error> SolvePart2(const std::string& input) override;

    // an individual range
    struct Range {
        uint64_t dest, source, range;
    };

    // a seed pair value
    struct SeedPair {
        uint64_t start, range;
    };

    // a mapping, from a to b. contains n number of ranges
    using Mapping = std::vector<Range>;
    // all of the mappings
    using Mappings = std::vector<Mapping>;
};

class Day6 : public AdventSolver {
public:
    std::expected<double, Error::generic_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::generic_error> SolvePart2(const std::string& input) override;
    int64_t Solve(int64_t time, int64_t dist);
};

class Day7 : public AdventSolver {
public:
    std::expected<double, Error::generic_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::generic_error> SolvePart2(const std::string& input) override;
};

#endif // AOC_DAY_H_