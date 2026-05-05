cmake_minimum_required(VERSION 3.10)
project(BartSnake)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
enable_testing()
add_library(bart_snake_lib
    src/BartSnake.cpp
    src/BartSnakeGame.cpp
    src/ClipperCard.cpp
    src/GameMap.cpp
)
add_executable(bart_snake src/main.cpp)
target_link_libraries(bart_snake bart_snake_lib)
add_executable(tests tests/test_main.cpp)
target_link_libraries(tests bart_snake_lib)
add_test(NAME CreateGameObjects COMMAND tests objects)
add_test(NAME DefaultObjectValues COMMAND tests defaults)
add_test(NAME SnakeBoundaryCheck COMMAND tests boundary)
add_test(NAME GameStatusStartsRunning COMMAND tests game-status)
