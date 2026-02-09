add_executable(smart_pointer
               src/main.cpp
               src/raii.cpp
               include/shared_ptr.hpp
)

target_include_directories(smart_pointer PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(smart_pointer PRIVATE -Wall -Wextra -Wpedantic)