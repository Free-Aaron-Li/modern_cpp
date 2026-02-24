cmake_minimum_required(VERSION 4.1)
project(modern_cpp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_subdirectory(1_basics)
add_subdirectory(2_user_defined_types)
add_subdirectory(3_modularity)
