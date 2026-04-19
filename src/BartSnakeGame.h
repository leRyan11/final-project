#ifndef BART_SNAKE_GAME_H
#define BART_SNAKE_GAME_H

#include <string>
#include "BartSnake.h"
#include "ClipperCard.h"
#include "GameMap.h"

class BartSnakeGame {
private:
    BartSnake snake;
    ClipperCard card;
    GameMap currentMap;

    int score;
    int highScore;
    bool running;

public:
    BartSnakeGame();

    void startGame();
    void update();
    void render() const;
    void processInput(char input);

    int getScore() const;
    bool isRunning() const;
};

#endif
