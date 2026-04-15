# Modern C++ 学习项目构建配置
#
# 本项目通过实际代码示例来学习和掌握现代 C++（C++11 及更高版本）的核心特性。
#
# 构建方式：
# 1. 创建构建目录：mkdir build && cd build
# 2. 配置项目：cmake ..
# 3. 编译并运行：make && ./bin/<子项目名称>
cmake_minimum_required(VERSION 3.31)
project(modern_cpp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_subdirectory(1_basics)
add_subdirectory(2_user_defined_types)
add_subdirectory(3_modularity)
add_subdirectory(4_error_handling)
add_subdirectory(5_classes)
