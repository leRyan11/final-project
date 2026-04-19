cmake_minimum_required(VERSION 3.10)
project(BartSnake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Main executable
add_executable(bart_snake src/main.cpp)

# Test setup (not required to work yet)
# add_executable(tests tests/test_main.cpp)
# add_test(NAME BartSnakeTests COMMAND tests)
