# 第 3 章 模块化（Modularity）子项目构建配置
#
# 本子项目包含模块化相关的示例代码，包括：
# - 分离编译（头文件方式与模块方式）
# - 命名空间的使用
# - 函数参数与返回值
add_executable(3_modularity
               src/main.cpp
               include/modularity.hpp
               include/Vector.hpp
               src/Vector.cpp
               src/3_2_separate_compilation.cpp
               src/3_3_namespaces.cpp
               src/3_4_function_arguments_and_return_values.cpp
)

# C++ Modules：把提供 module 的文件放进 CXX_MODULES 的 FILE_SET
target_sources(3_modularity
               PRIVATE
               FILE_SET cxx_modules TYPE CXX_MODULES
               FILES
               module/module_vector.cpp
)

target_include_directories(3_modularity PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(3_modularity PRIVATE -Wall -Wextra -Wpedantic)
