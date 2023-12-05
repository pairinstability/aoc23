#ifndef AOC_INCLUDE_UTILS_DAY4_H_
#define AOC_INCLUDE_UTILS_DAY4_H_

#include <utils/advent_solver.h>

class Day4 : public AdventSolver {
public:
    std::expected<double, Error::generic_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::generic_error> SolvePart2(const std::string& input) override;

    struct Card {
        int wins = 0;
        int copies = 1;
    };
};

#endif // AOC_INCLUDE_UTILS_DAY4_H_