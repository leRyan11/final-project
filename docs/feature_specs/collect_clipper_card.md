# Collect Clipper Card - Spec

## Problem statement
A player can collect a Clipper card when the Bart snake reaches the card's position. Collecting the card increases the score and snake length during gameplay.

## Types involved
- `BartSnakeGame` checks whether the snake/bart thing head and card are on the same square, updates the score, grows the snake, and moves the card.
- `BartSnake` provides the head position, grows, moves, and reports occupied squares.
- `ClipperCard` stores the card's in-memory position.
- `GameMap` provides the map width and height used when choosing the next card position.

## Public interface
- `bool BartSnakeGame::collectCardIfReached();`
  Returns true if the snake head is on the Clipper card and the card was collected.
- `void BartSnakeGame::setCardPosition(int x, int y);`
  Sets the card position for tests and simple manual setup.
- `void BartSnakeGame::setSnakeHeadPositionForTest(int x, int y);`
  Sets the snake head position for tests.
- `int BartSnakeGame::getSnakeLength() const;`
  Returns the current snake length.
- `int BartSnakeGame::getCardX() const;`
  Returns the card's x position.
- `int BartSnakeGame::getCardY() const;`
  Returns the card's y position.

## Inputs and outputs
- Input: the player moves with `w`, `a`, `s`, or `d`.
- Output: score increases by 10 when a card is collected, the snake length increases, and the card moves to the first open square on the map.

## Edge cases
- The snake head is not on the card, so nothing changes.
- The card is on the right edge of the map and the collection still succeeds.
- The replacement card position must not be inside the snake.
- The map has no open square left, so the score still increases and the card remains where it is.

## Three tests (English version)
- Normal: put the snake head on the card, collect it, and confirm the score increases by 10.
- Edge: put the snake and card on different squares and confirm score, length, and card position do not change.
- Boundary: move the snake onto a card at the right edge of the map and confirm the game is still running, the score increases, and the card wraps to the first open square.

## Design decisions
The feature is implemented in `BartSnakeGame` because it needs to coordinate `BartSnake`, `ClipperCard`, and `GameMap`. I chose deterministic card placement with plain nested loops instead of random placement so the behavior is easy to test and explain.
