#include "ClipperCard.h"

ClipperCard::ClipperCard() : x(2), y(2) {
}

ClipperCard::ClipperCard(int startX, int startY) : x(startX), y(startY) {
}

int ClipperCard::getX() const {
    return x;
}

int ClipperCard::getY() const {
    return y;
}

void ClipperCard::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}
