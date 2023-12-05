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

# day 3
add_library(day3 "${PROJECT_SOURCE_DIR}/../include/day3.h" "${PROJECT_SOURCE_DIR}/../src/day3.cpp")
target_include_directories(day3 PUBLIC ${PROJECT_SOURCE_DIR}/../include)

# day 4
add_library(day4 "${PROJECT_SOURCE_DIR}/../include/day4.h" "${PROJECT_SOURCE_DIR}/../src/day4.cpp")
target_include_directories(day4 PUBLIC ${PROJECT_SOURCE_DIR}/../include)

# day 5
add_library(day5 "${PROJECT_SOURCE_DIR}/../include/day5.h" "${PROJECT_SOURCE_DIR}/../src/day5.cpp")
target_include_directories(day5 PUBLIC ${PROJECT_SOURCE_DIR}/../include)


#####################################################################

target_link_libraries(day1 utils)
target_link_libraries(day2 utils)
target_link_libraries(day3 utils)
target_link_libraries(day4 utils)
target_link_libraries(day5 utils)