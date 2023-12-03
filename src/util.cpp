#include <utils/util.h>

namespace Util {
std::expected<std::vector<std::string>, Error::file_error> ReadInputFromFile(const std::string& filename)
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
        return std::unexpected { Error::file_error::bad_file };
    }
}
}