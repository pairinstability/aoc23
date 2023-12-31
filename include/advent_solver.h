#ifndef AOC_ADVENT_SOLVER_H_
#define AOC_ADVENT_SOLVER_H_

#include <expected>
#include <string>
#include <util.h>
#include <vector>

// AOC daily solver interface
class AdventSolver {
public:
    // Takes a filename as an argument and returns the solution for that given data
    // wrapped in a std::expected
    // also problems have a part 1 and a part 2 that are somewhat independent
    virtual std::expected<double, Error::generic_error> SolvePart1(const std::string& input) = 0;
    virtual std::expected<double, Error::generic_error> SolvePart2(const std::string& input) = 0;
    virtual ~AdventSolver() = default;
};

#endif // AOC_ADVENT_SOLVER_H_