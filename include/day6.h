#ifndef AOC_INCLUDE_UTILS_DAY6_H_
#define AOC_INCLUDE_UTILS_DAY6_H_

#include <utils/advent_solver.h>

class Day6 : public AdventSolver {
public:
    std::expected<double, Error::generic_error> SolvePart1(const std::string& input) override;
    std::expected<double, Error::generic_error> SolvePart2(const std::string& input) override;
    int64_t Solve(int64_t time, int64_t dist);
};

#endif // AOC_INCLUDE_UTILS_DAY6_H_