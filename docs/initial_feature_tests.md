Initial Feature Test Cases
Feature: Basic Game Objects and Status Display
Test 1: Normal Operation

What it tests: Creating a Bart train, Clipper card, and station map with normal values

Expected result: Each object stores and returns the values passed into its constructor

Result: Pass

Test 2: Edge Case

What it tests: Creating the default game objects without custom input

Expected result: Each object has safe default values and can be displayed without crashing

Result: Pass

Test 3: Boundary Conditions

What it tests: Moving the snake from the edge of the map beyond the wall

Expected result: The wall collision check detects that the snake is out of bounds

Result: Pass

Test 4: Game Status

What it tests: Starting the game and checking the initial running state and score

Expected result: The game starts running and the score begins at 0

Result: Pass

CTest Output

Run this before submitting and paste your output here:

cmake -S . -B build
cmake --build build
ctest --test-dir build --verbose
