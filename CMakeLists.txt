cmake_minimum_required(VERSION 3.0.0)
project("Test")

include_directories(".")

add_executable(Test
    "Main.cpp"
)

set_property(TARGET Test PROPERTY CXX_STANDARD 11)

if(MSVC)
  target_compile_options(Test PRIVATE /W4 /WX)
else()
  target_compile_options(Test PRIVATE -Wall -Wextra -Wpedantic)
endif()