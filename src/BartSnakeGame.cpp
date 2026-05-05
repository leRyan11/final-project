#include "BartSnakeGame.h"

#include <iostream>

BartSnakeGame::BartSnakeGame()
    : snake(5, 5), card(8, 5), currentMap("MacArthur", 20, 12), score(0), highScore(0), running(false) {
}

void BartSnakeGame::startGame() {
    snake = BartSnake(5, 5);
    card = ClipperCard(8, 5);
    currentMap = GameMap("MacArthur", 20, 12);
    score = 0;
    running = true;
}

void BartSnakeGame::update() {
    if (!running) {
        return;
    }

    snake.move();
    std::pair<int, int> head = snake.getHeadPosition();

    if (head.first == card.getX() && head.second == card.getY()) {
        score += 10;
        snake.grow();
        card.setPosition((card.getX() + 3) % currentMap.getWidth(), (card.getY() + 2) % currentMap.getHeight());
    }

    if (snake.hitWall(currentMap.getWidth(), currentMap.getHeight()) || snake.hitSelf()) {
        running = false;
        if (score > highScore) {
            highScore = score;
        }
    }
}

void BartSnakeGame::render() const {
    std::cout << "Station: " << currentMap.getStationName() << "\n";
    std::cout << "Score: " << score << "\n";
    std::cout << "High Score: " << highScore << "\n";
    std::cout << "Train Length: " << snake.getLength() << "\n";
    std::cout << "Clipper Card: (" << card.getX() << ", " << card.getY() << ")\n";
}

void BartSnakeGame::processInput(char input) {
    if (input == 'w' || input == 'W') {
        snake.changeDirection(0, -1);
    } else if (input == 's' || input == 'S') {
        snake.changeDirection(0, 1);
    } else if (input == 'a' || input == 'A') {
        snake.changeDirection(-1, 0);
    } else if (input == 'd' || input == 'D') {
        snake.changeDirection(1, 0);
    } else if (input == 'q' || input == 'Q') {
        running = false;
    }
}

int BartSnakeGame::getScore() const {
    return score;
}

bool BartSnakeGame::isRunning() const {
    return running;
}
