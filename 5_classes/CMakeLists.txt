# 第 5 章 类（Classes）子项目构建配置
#
# 本子项目包含类相关的示例代码，包括：
# - 引言（Introduction）
# - 具体类型（Concrete Types）
# - 抽象类型（Abstract Types）
# - 虚函数（Virtual Functions）
# - 类层次结构（Class Hierarchies）

add_executable(5_classes
               src/main.cpp
               src/5_1_introduction.cpp
               src/5_2_concrete_types.cpp
               src/5_3_abstract_types.cpp
               src/5_4_virtual_functions.cpp
               src/5_5_class_hierarchies.cpp
)

# C++ Modules：把提供 module 的文件放进 CXX_MODULES 的 FILE_SET
target_sources(5_classes
               PRIVATE
               FILE_SET cxx_modules TYPE CXX_MODULES
               FILES
               module/classes.cpp
)

target_compile_options(5_classes PRIVATE -Wall -Wextra -Wpedantic)
