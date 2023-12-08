// implementation of day1 solution

#include <day.h>
#include <iostream>
#include <numeric>
#include <string>
#include <util.h>

std::expected<double, Error::generic_error> Day1::SolvePart1(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    std::vector<int> calibration_values;

    for (const auto& line : data.value()) {
        std::vector<int> digits;
        for (auto c : line) {
            if (c >= '0' && c <= '9') {
                // maps from decimal representation to 0-indexed (or, what
                // the num actually is)
                digits.push_back(c - '0');
            }
        }
        // we only want first (in tens place) and last (in ones place)
        calibration_values.push_back(digits[0] * 10 + digits.back());
    }

    // get the sum
    const auto sum = std::accumulate(std::begin(calibration_values), std::end(calibration_values), 0);
    return sum;
};

std::expected<double, Error::generic_error> Day1::SolvePart2(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    std::vector<std::string> string_numbers { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    std::vector<int> calibration_values;

    // both 0-9 and one-nine count
    for (auto line : data.value()) {
        std::vector<int> digits;
        for (int i = 0; i < line.length(); i++) {
            const auto c = line[i];
            if (c >= '0' && c <= '9') {
                // maps from decimal representation to 0-indexed (or, what
                // the num actually is)
                digits.push_back(c - '0');
            }

            for (int j = 0; j < string_numbers.size(); j++) {
                const auto& n = string_numbers[j];
                // check if the number in string format can actually fit
                if (line.size() >= i + n.size()) {
                    if (line.substr(i, n.size()) == n) {
                        digits.push_back(j + 1);
                    }
                }
            }
        }

        // we only want first (in tens place) and last (in ones place)
        calibration_values.push_back(digits[0] * 10 + digits.back());
    }

    // get the sum
    const auto sum = std::accumulate(std::begin(calibration_values), std::end(calibration_values), 0);
    return sum;
};