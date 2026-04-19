# 第 4 章 错误处理（Error Handling）子项目构建配置
#
# 本子项目包含错误处理相关的示例代码，包括：
# - 异常处理（Exceptions）
# - 约束条件（Constraints/Invariants）
# - 错误处理的其他替代方式（Alternatives）
# - 断言（Assertions）

add_executable(4_error_handling
               src/main.cpp
               src/4_2_exceptions.cpp
               src/4_3_invariants.cpp
               src/4_4_alternatives.cpp
               src/4_5_assertions.cpp
               src/4_2_invariants.cpp
)

# C++ Modules：把提供 module 的文件放进 CXX_MODULES 的 FILE_SET
target_sources(4_error_handling
               PRIVATE
               FILE_SET cxx_modules TYPE CXX_MODULES
               FILES
               module/error_handling.cpp
)

target_compile_options(4_error_handling PRIVATE -Wall -Wextra -Wpedantic)
