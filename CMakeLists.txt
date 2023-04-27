cmake_minimum_required(VERSION 3.0.0)
project("Test")

include_directories(".")

add_executable(Test
    "Test/Main.cpp"
)

set_property(TARGET Test PROPERTY CXX_STANDARD 11)

if(MSVC)
  target_compile_options(Test PRIVATE /W4 /WX)
else()
  target_compile_options(Test PRIVATE -Wall -Wextra -Wpedantic)
endif()

project("TestCustomMalloc")

include_directories(".")

add_executable(TestCustomMalloc
    "Test/CustomMalloc.cpp"
)

set_property(TARGET TestCustomMalloc PROPERTY CXX_STANDARD 11)

if(MSVC)
  target_compile_options(TestCustomMalloc PRIVATE /W4 /WX)
else()
  target_compile_options(TestCustomMalloc PRIVATE -Wall -Wextra -Wpedantic)
endif()