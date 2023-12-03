#ifndef AOC_INCLUDE_UTILS_ERRORS_H_
#define AOC_INCLUDE_UTILS_ERRORS_H_

namespace Error {

// advent solver errors
enum solver_error {
    // if Solve does not produce any solution
    no_solution,
    // if Solve times out due to large recursion
    intractable
};

// file parsing errors
enum file_error {
    // file path doesn't exist
    file_doesnt_exist,
    // file is badly formatted
    bad_file
};

};

#endif // AOC_INCLUDE_UTILS_ERRORS_H