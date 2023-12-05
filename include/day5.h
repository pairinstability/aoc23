#ifndef AOC_INCLUDE_UTILS_DAY5_H_
#define AOC_INCLUDE_UTILS_DAY5_H_

#include <utils/advent_solver.h>

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

#endif // AOC_INCLUDE_UTILS_DAY5_H_