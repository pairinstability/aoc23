// implementation of day2 solution

#include <day.h>
#include <iostream>
#include <sstream>
#include <util.h>

std::expected<double, Error::generic_error> Day2::SolvePart1(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    int sum = 0;

    for (const auto& line : data.value()) {
        int id, count;
        std::string c;
        bool possible = true;
        std::istringstream iss { line };
        iss >> c;
        iss >> id;
        iss.ignore(1);

        while (iss >> count) {
            iss >> c;
            if (('r' == c[0] && count > 12) || ('g' == c[0] && count > 13) || ('b' == c[0] && count > 14)) {
                possible = false;
                break;
            }
        }

        if (possible) {
            sum += id;
        }
    }

    if (sum == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return sum;
    }
};

std::expected<double, Error::generic_error> Day2::SolvePart2(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    int sum = 0;

    // basically same but we want the maximum number for each color
    // in each line, instead of constraining by a threshold
    for (const auto& line : data.value()) {
        int id, count;
        int r = 0;
        int g = 0;
        int b = 0;
        std::string c;
        std::istringstream iss { line };
        iss >> c;
        iss >> id;
        iss.ignore(1);

        while (iss >> count) {
            iss >> c;
            if ('r' == c[0]) {
                r = std::max(r, count);
            } else if ('g' == c[0]) {
                g = std::max(g, count);
            } else if ('b' == c[0]) {
                b = std::max(b, count);
            }
        }

        sum += r * g * b;
    }

    if (sum == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return sum;
    }
};