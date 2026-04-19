#ifndef BART_SNAKE_H
#define BART_SNAKE_H

#include <vector>
#include <utility>

class BartSnake {
private:
    std::vector<std::pair<int, int>> body;
    int directionX;
    int directionY;
    bool growing;

public:
    BartSnake();
    BartSnake(int startX, int startY);

    void move();
    void changeDirection(int dx, int dy);
    void grow();

    bool hitWall(int width, int height) const;
    bool hitSelf() const;
    bool occupiesPosition(int x, int y) const;

    std::pair<int, int> getHeadPosition() const;
    int getLength() const;
};

#endif
