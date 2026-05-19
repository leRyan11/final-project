#include "BartSnake.h"

#include <cstddef>

BartSnake::BartSnake() : directionX(1), directionY(0), growing(false) {
    body.push_back(std::make_pair(5, 5));
}

BartSnake::BartSnake(int startX, int startY) : directionX(1), directionY(0), growing(false) {
    body.push_back(std::make_pair(startX, startY));
}

void BartSnake::move() {
    std::pair<int, int> head = getHeadPosition();
    body.insert(body.begin(), std::make_pair(head.first + directionX, head.second + directionY));

    if (growing) {
        growing = false;
    } else {
        body.pop_back();
    }
}

void BartSnake::changeDirection(int dx, int dy) {
    if (dx == 0 && dy == 0) {
        return;
    }

    if (body.size() > 1 && dx == -directionX && dy == -directionY) {
        return;
    }

    directionX = dx;
    directionY = dy;
}

void BartSnake::grow() {
    growing = true;
}

bool BartSnake::hitWall(int width, int height) const {
    std::pair<int, int> head = getHeadPosition();
    return head.first < 0 || head.second < 0 || head.first >= width || head.second >= height;
}

bool BartSnake::hitSelf() const {
    if (body.empty()) {
        return false;
    }

    std::pair<int, int> head = body.front();
    for (std::size_t i = 1; i < body.size(); ++i) {
        if (body[i] == head) {
            return true;
        }
    }

    return false;
}

bool BartSnake::occupiesPosition(int x, int y) const {
    for (std::size_t i = 0; i < body.size(); ++i) {
        if (body[i].first == x && body[i].second == y) {
            return true;
        }
    }

    return false;
}

std::pair<int, int> BartSnake::getHeadPosition() const {
    if (body.empty()) {
        return std::make_pair(0, 0);
    }

    return body.front();
}

int BartSnake::getLength() const {
    return static_cast<int>(body.size());
}
