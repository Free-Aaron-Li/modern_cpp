# 第 1 章 基础（Basics）子项目构建配置
#
# 本子项目包含 C++ 基础相关的示例代码，包括：
# - 程序基本结构
# - 函数与重载
# - 类型、变量与算术
# - 常量（const、constexpr、consteval）
# - 指针、数组与引用
# - 条件判断与循环
add_executable(1_basics
               src/main.cpp
               include/basics.hpp
               src/1_2_program.cpp
               src/1_3_functions.cpp
               src/1_4_types.cpp
               src/1_6_constants.cpp
               src/1_7_pointers.cpp
               src/1_8_tests.cpp
)

target_include_directories(1_basics PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(1_basics PRIVATE -Wall -Wextra -Wpedantic)