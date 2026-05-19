cmake_minimum_required(VERSION 3.10)
project(BartSnake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

add_library(bart_snake_core
    src/BartSnake.cpp
    src/ClipperCard.cpp
    src/GameMap.cpp
    src/BartSnakeGame.cpp
)

# Main executable
add_executable(bart_snake src/main.cpp)
target_link_libraries(bart_snake bart_snake_core)

add_executable(tests tests/test_main.cpp)
target_link_libraries(tests bart_snake_core)

add_test(NAME CollectCardNormal COMMAND tests normal)
add_test(NAME CollectCardNoMatch COMMAND tests no_match)
add_test(NAME CollectCardBoundary COMMAND tests boundary)
add_test(NAME CreateGameObjects COMMAND tests objects)
add_test(NAME DefaultObjectValues COMMAND tests defaults)
add_test(NAME SnakeBoundaryCheck COMMAND tests snake-boundary)
add_test(NAME GameStatusStartsRunning COMMAND tests game-status)