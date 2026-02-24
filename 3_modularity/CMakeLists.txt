add_executable(3_modularity
               src/main.cpp
               include/modularity.hpp
               include/Vector.hpp
               src/Vector.cpp
               src/3_2_separate_compilation.cpp
               src/3_3_namespaces.cpp
               src/3_4_error_handling.cpp
)

target_include_directories(3_modularity PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(3_modularity PRIVATE -Wall -Wextra -Wpedantic)
