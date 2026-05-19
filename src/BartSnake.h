#include "BartSnake.h"

BartSnake::BartSnake() {
    body.push_back(std::make_pair(0, 0));
    directionX = 1;
    directionY = 0;
}

BartSnake::BartSnake(int startX, int startY) {
    body.push_back(std::make_pair(startX, startY));
    directionX = 1;
    directionY = 0;
}

void BartSnake::move() {
    std::pair<int, int> head = body[0];
    std::pair<int, int> newHead = std::make_pair(head.first + directionX, head.second + directionY);

    body.insert(body.begin(), newHead);
    body.pop_back();
}

void BartSnake::changeDirection(int dx, int dy) {
    directionX = dx;
    directionY = dy;
}

void BartSnake::grow() {
    body.push_back(body[body.size() - 1]);
}

bool BartSnake::hitWall(int width, int height) const {
    std::pair<int, int> head = getHeadPosition();
    return head.first < 0 || head.first >= width || head.second < 0 || head.second >= height;
}

bool BartSnake::hitSelf() const {
    std::pair<int, int> head = getHeadPosition();

    for (int i = 1; i < static_cast<int>(body.size()); i++) {
        if (body[i] == head) {
            return true;
        }
    }

    return false;
}

bool BartSnake::occupiesPosition(int x, int y) const {
    for (int i = 0; i < static_cast<int>(body.size()); i++) {
        if (body[i].first == x && body[i].second == y) {
            return true;
        }
    }

    return false;
}

void BartSnake::setHeadPositionForTest(int x, int y) {
    body.clear();
    body.push_back(std::make_pair(x, y));
}

std::pair<int, int> BartSnake::getHeadPosition() const {
    return body[0];
}

int BartSnake::getLength() const {
    return static_cast<int>(body.size());
}
