# all of the solutions to each day of aoc are in the src dir
project(aoc_solutions)

add_library(errors INTERFACE "${PROJECT_SOURCE_DIR}/../include/utils/errors.h")

# utils
add_library(utils "${PROJECT_SOURCE_DIR}/../include/utils/util.h" "${PROJECT_SOURCE_DIR}/../src/util.cpp")
target_include_directories(utils PUBLIC ${PROJECT_SOURCE_DIR}/../include)

# advent_solver is the base class for solutions
add_library(advent_solver INTERFACE "${PROJECT_SOURCE_DIR}/../include/utils/advent_solver.h")


#####################################################################
# each solution
# day 1
add_library(day1 "${PROJECT_SOURCE_DIR}/../include/day1.h" "${PROJECT_SOURCE_DIR}/../src/day1.cpp")
target_include_directories(day1 PUBLIC ${PROJECT_SOURCE_DIR}/../include)

# day 2
add_library(day2 "${PROJECT_SOURCE_DIR}/../include/day2.h" "${PROJECT_SOURCE_DIR}/../src/day2.cpp")
target_include_directories(day2 PUBLIC ${PROJECT_SOURCE_DIR}/../include)





#####################################################################

target_link_libraries(
    day1
    utils
)

target_link_libraries(
    day2
    utils
)