// implementation of day3 solution

#include <day3.h>
#include <iostream>
#include <regex>
#include <sstream>
#include <utils/util.h>

bool Day3::is_adjacent(Number& num, Symbol& sym)
{
    return
        (num.row == sym.row - 1 && sym.col >= num.start - 1 && sym.col <= num.end + 1) ||
        (num.row == sym.row + 1 && sym.col >= num.start - 1 && sym.col <= num.end + 1) ||
        (num.row == sym.row && num.end == sym.col - 1) ||
        (num.row == sym.row && num.start == sym.col + 1);
}

void Day3::parse_input(std::vector<std::string>& input, std::vector<Number>& numbers, std::vector<Symbol>& symbols)
{
    int row = 0;

    // store the numbers and symbols so we can check adjacency later
    // parse the numbers
    auto parse_numbers = [&numbers, &row](const std::string& line) {
        std::regex number_re("\\d+");

        for (auto i = std::sregex_iterator(line.begin(), line.end(), number_re);
             i != std::sregex_iterator(); i++) {
            numbers.push_back(Number {
                std::stoi(i->str()),
                row,
                static_cast<int>(i->position()),
                static_cast<int>(i->position() + i->length() - 1) });
        }
    };

    auto parse_symbols = [&symbols, &row](const std::string& line) {
        std::regex symbol_re("([^\\d\\.])");

        // parse the symbols
        for (auto i = std::sregex_iterator(line.begin(), line.end(), symbol_re);
             i != std::sregex_iterator(); i++) {
            symbols.push_back(Symbol {
                i->str()[0],
                row,
                static_cast<int>(i->position()) });
        }
    };

    for (const auto& line : input) {
        row++;
        parse_numbers(line);
        parse_symbols(line);
    }
}

std::expected<double, Error::generic_error> Day3::SolvePart1(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    std::vector<Number> numbers;
    std::vector<Symbol> symbols;

    parse_input(data.value(), numbers, symbols);
    int sum = 0;

    // check adjacency
    for (auto& num : numbers) {
        for (auto& sym : symbols) {
            if (is_adjacent(num, sym)) {
                sum += num.num;
                break;
            }
        }
    }

    if (sum == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return sum;
    }
};

std::expected<double, Error::generic_error> Day3::SolvePart2(const std::string& input)
{
    auto data = Util::ReadInputFromFile(input);
    if (not data.has_value()) {
        return std::unexpected { data.error() };
    }

    std::vector<Number> numbers;
    std::vector<Symbol> symbols;

    parse_input(data.value(), numbers, symbols);
    int sum = 0;

    // we only care about * now and if there are 2 part numbers adjacent to it
    for (auto& sym : symbols) {
        if (sym.type == '*') {
            std::vector<Number> gear_adjacent;
            for (auto& num : numbers) {
                if (is_adjacent(num, sym)) {
                    gear_adjacent.push_back(num);
                }
            }

            if (gear_adjacent.size() == 2) {
                sum += gear_adjacent[0].num * gear_adjacent[1].num;
            }
        }
    }

    if (sum == 0) {
        return std::unexpected { Error::generic_error::no_solution };
    } else {
        return sum;
    }
};