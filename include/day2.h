#ifndef AOC_INCLUDE_UTILS_DAY2_H_
#define AOC_INCLUDE_UTILS_DAY2_H_

#include <utils/advent_solver.h>

class Day2 : public AdventSolver {
public:
    std::expected<double, Error::solver_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::solver_error> SolvePart2(const std::string& input) override;
};

#endif // AOC_INCLUDE_UTILS_DAY2_H_