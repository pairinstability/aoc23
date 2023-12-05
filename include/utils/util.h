#ifndef AOC_INCLUDE_UTILS_UTIL_H_
#define AOC_INCLUDE_UTILS_UTIL_H_

#include <cstdlib>
#include <cstring>
#include <expected>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utils/errors.h>
#include <vector>

#define GTEST_COUT std::cerr << "[ INFO     ] "

// assume the test is being run from build/tests, which is not a great assumption but
// its better than hardcoding the path
#define USE_PATH(path) (std::filesystem::current_path() / "../.." / path).string()

// for easily printing the error out
#define PRINT_ERROR(result) ("Error: " + Util::ErrorToString(result))

namespace Util {
// read text input from a file, line by line, return the vector with lines wrapped
// in an expected
std::expected<std::vector<std::string>, Error::generic_error> ReadInputFromFile(const std::string& filename);

// convert a error to useful text
std::string ErrorToString(Error::generic_error error);

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