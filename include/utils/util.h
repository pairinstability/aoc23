#ifndef AOC_INCLUDE_UTILS_UTIL_H_
#define AOC_INCLUDE_UTILS_UTIL_H_

#include <cstdlib>
#include <cstring>
#include <expected>
#include <fstream>
#include <iostream>
#include <string>
#include <utils/errors.h>
#include <vector>

#define GTEST_COUT std::cerr << "[          ] [ INFO ] "
#define PATH "/home/user/aoc/"

namespace Util {
// read text input from a file, line by line, return the vector with lines wrapped
// in an expected
std::expected<std::vector<std::string>, Error::file_error> ReadInputFromFile(const std::string& filename);

// print debugging information only if the DEBUG environemnt variable is
// set
template<typename... Args>
inline void print(const Args&... args)
{
    if (getenv("DEBUG") && strcmp(getenv("DEBUG"), "1") == 0) {
        auto debugPrintImpl = [](const auto&... values) {
            (std::cout << ... << values) << std::endl;
        };

        debugPrintImpl(args...);
    }
}
}

#endif // AOC_INCLUDE_UTILS_UTIL_H_