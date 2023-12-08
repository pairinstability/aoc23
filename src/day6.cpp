// implementation of day6 solution

#include <algorithm>
#include <array>
#include <cmath>
#include <day.h>
#include <iostream>
#include <sstream>
#include <util.h>


// find a solution whereby t * (T - t) > D, with unknown t
// we want the number of these solutions.
int64_t Day6::Solve(int64_t time, int64_t dist) {
    auto t1 = (time - std::sqrt(time * time - 4 * dist)) / 2;
    auto t2 = (time + std::sqrt(time * time - 4 * dist)) / 2;

    auto const x = std::round(t1) == t1 ? t1 + 1 : std::floor(t1);

    return (t2 - x);
}

std::expected<double, Error::generic_error> Day6::SolvePart1(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    int sum = 1;
    // race durations
    std::vector<int64_t> times;
    // record distances
    std::vector<int64_t> dists;
    int num;

    // first line (time)
    std::istringstream iss { data.value()[0] };

    iss.ignore(5);
    while (iss >> num) {
        times.push_back(num);
    }

    // second line (distance)
    iss.str(data.value()[1]);
    iss.clear();
    iss.ignore(9);

    while (iss >> num) {
        dists.push_back(num);
    }

    for (int i = 0; i < times.size(); i++) {
        int64_t val = Solve(times[i], dists[i]);
        sum *= val;
    }

    if (sum == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return sum;
    }
};

std::expected<double, Error::generic_error> Day6::SolvePart2(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    int64_t sum;

    // race durations
    std::string time_s;
    // record distances
    std::string dist_s;
    int num;

    // first line (time)
    std::istringstream iss { data.value()[0] };

    iss.ignore(5);
    while (iss >> num) {
        time_s += std::to_string(num);
    }

    // second line (distance)
    iss.str(data.value()[1]);
    iss.clear();
    iss.ignore(9);

    while (iss >> num) {
        dist_s += std::to_string(num);
    }

    auto time = std::stoll(time_s);
    auto dist = std::stoll(dist_s);

    sum = Solve(time, dist);

    if (sum == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return sum;
    }
};