// implementation of day4 solution

#include <cmath>
#include <day4.h>
#include <iostream>
#include <numeric>
#include <set>
#include <sstream>
#include <utils/util.h>

std::expected<double, Error::generic_error> Day4::SolvePart1(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    int sum = 0;

    for (const auto& line : data.value()) {
        std::set<int> winning;
        std::set<int> numbers;

        int temp_sum = 0;
        int count;
        std::string c;
        size_t pipe = line.find('|');
        size_t colon = line.find(':');
        std::istringstream iss { line.substr(colon + 1, pipe - colon - 1) };

        while (iss >> count)
            winning.insert(count);

        iss = std::istringstream(line.substr(pipe + 1));
        while (iss >> count) {
            if (winning.find(count) != winning.end()) {
                temp_sum++;
            }
        }

        if (temp_sum > 0)
            sum += std::pow(2, temp_sum - 1);
    }

    if (sum == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return sum;
    }
};

std::expected<double, Error::generic_error> Day4::SolvePart2(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    int sum = 0;
    std::vector<Card> cards;

    for (const auto& line : data.value()) {
        std::set<int> winning;
        std::set<int> numbers;
        Card c;
        int count;
        size_t pipe = line.find('|');
        size_t colon = line.find(':');

        std::istringstream iss { line.substr(colon + 1, pipe - colon - 1) };

        while (iss >> count)
            winning.insert(count);

        iss = std::istringstream(line.substr(pipe + 1));
        while (iss >> count) {
            if (winning.find(count) != winning.end()) {
                c.wins++;
            }
        }
        cards.push_back(c);
    }

    for (auto i = 0; i < cards.size(); i++)
        for (auto j = 1; j <= cards[i].wins; j++)
            cards[i + j].copies += cards[i].copies;

    sum = std::accumulate(cards.begin(), cards.end(), 0, [](int a, const Card& c) {
        return a + c.copies;
    });

    if (sum == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return sum;
    }
};