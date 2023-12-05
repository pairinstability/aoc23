#ifndef AOC_INCLUDE_UTILS_ERRORS_H_
#define AOC_INCLUDE_UTILS_ERRORS_H_

namespace Error {

// generic errors
enum generic_error {
    // if Solve does not produce any solution
    no_solution,
    // file path doesn't exist
    file_doesnt_exist,
    // file is badly formatted
    bad_file
};

};

#endif // AOC_INCLUDE_UTILS_ERRORS_H