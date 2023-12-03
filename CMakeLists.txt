cmake_minimum_required(VERSION 3.22)
project(adventofcode LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)