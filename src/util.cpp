#include <util.h>

namespace Util {
std::expected<std::vector<std::string>, Error::generic_error> ReadInputFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open()) {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    } else {
        return std::unexpected { Error::generic_error::bad_file };
    }
}

std::string ErrorToString(Error::generic_error error)
{
    switch (error) {
    case Error::no_solution:
        return "no solution exists";
    case Error::file_doesnt_exist:
        return "file does not exist";
    case Error::bad_file:
        return "badly formatted file";
    default:
        return "unknown error";
    }
}

}