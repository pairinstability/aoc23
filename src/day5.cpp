// implementation of day5 solution

#include <algorithm>
#include <array>
#include <cstdint>
#include <day5.h>
#include <iostream>
#include <sstream>
#include <utils/util.h>

std::expected<double, Error::generic_error> Day5::SolvePart1(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    std::istringstream iss { data.value()[0] };
    iss.ignore(6);
    uint64_t s;
    std::vector<uint64_t> seeds;
    while (iss >> s)
        seeds.push_back(s);

    Mappings mappings;
    Mapping mapping;
    data.value().push_back("");
    for (size_t i = 3; i < data.value().size(); ++i) {
        if (data.value()[i].empty()) {
            mappings.push_back(mapping);
            mapping.clear();
            i++;
            continue;
        }

        std::istringstream iss { data.value()[i] };
        uint64_t dest, source, range;
        iss >> dest >> source >> range;
        // add a range to the a-to-b mapping
        mapping.push_back(Range {
            dest,
            source,
            range });
    }

    // for each of the a-to-b mappings
    for (const auto& mapping : mappings) {
        for (auto& seed : seeds) {
            for (const auto& range : mapping) {
                if (seed >= range.source && seed < range.source + range.range) {
                    seed += range.dest - range.source;
                    break;
                }
            }
        }
    }

    const auto min = *std::min_element(seeds.begin(), seeds.end());

    if (min == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return min;
    }
};

std::expected<double, Error::generic_error> Day5::SolvePart2(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    uint64_t min = UINT64_MAX;

    std::istringstream iss { data.value()[0] };
    iss.ignore(6);
    // start, range of the seed pair
    uint64_t s1, s2;
    std::vector<SeedPair> seeds;
    while (iss >> s1 >> s2)
        seeds.push_back(SeedPair {
            s1,
            s2 });

    Mappings mappings;
    Mapping mapping;
    data.value().push_back("");
    for (size_t i = 3; i < data.value().size(); ++i) {
        if (data.value()[i].empty()) {
            mappings.push_back(mapping);
            mapping.clear();
            i++;
            continue;
        }

        std::istringstream iss { data.value()[i] };
        uint64_t dest, source, range;
        iss >> dest >> source >> range;
        // add a range to the a-to-b mapping
        mapping.push_back(Range {
            dest,
            source,
            range });
    }

    for (const auto& pair : seeds) {
        for (uint64_t i = 0; i < pair.range; ++i) {
            std::vector<uint64_t> skip;
            uint64_t seed = pair.start + i;

            for (uint64_t j = 0; j < mappings.size(); ++j) {
                for (const auto& range : mappings[j]) {
                    if (seed >= range.source && seed < range.source + range.range) {
                        skip.push_back(range.source + range.range - seed - 1);
                        seed += range.dest - range.source;
                        break;
                    }
                }
            }
            if (not skip.empty()) {
                i += *std::min_element(skip.begin(), skip.end());
            }
            min = std::min(min, seed);
        }
    }

    if (min == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return min;
    }
};