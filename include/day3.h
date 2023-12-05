#ifndef AOC_INCLUDE_UTILS_DAY3_H_
#define AOC_INCLUDE_UTILS_DAY3_H_

#include <utils/advent_solver.h>

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

#endif // AOC_INCLUDE_UTILS_DAY3_H_