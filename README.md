Bart-Snake
Bart Snake Game Description: It's the Google Snake game; however, instead of a sanke its a bart train, and instead of apples it's Clipper cards.

Features:

Move the Bart snake using keyboard controls

Collect Clipper cards to increase score and snake length

Play through different BART station-themed maps

Detect collisions with walls and the snake itself

Trigger checkpoint or boss encounters during gameplay

Save and load the high score from a text file

Building
cmake -S . -B build
cmake --build build
Current Status
Implemented Features:

Feature 1: Basic game objects and status display. The program can create a Bart train, a Clipper card, and a BART station map, then show the current game status in the terminal.
Stubbed (compile but not fully finished gameplay yet):

Feature 2: Full keyboard movement loop
Feature 3: Collecting Clipper cards during full gameplay
Feature 4: Multiple BART station maps
Feature 5: Game over flow for collisions
Feature 6: Saving and loading high scores
Known Issues:

The game is still terminal-based for this first feature.
The demo only processes one move before ending.
High scores are tracked in memory only.
