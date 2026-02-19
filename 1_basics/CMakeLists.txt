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