add_executable(2_user_defined_types
               src/main.cpp
               include/user_defined_types.hpp
               src/2_2_structs.cpp
               src/2_3_classes.cpp
               src/2_4_enums.cpp
               src/2_5_unions.cpp
)

target_include_directories(2_user_defined_types PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(2_user_defined_types PRIVATE -Wall -Wextra -Wpedantic)
