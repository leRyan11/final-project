#ifndef CLIPPER_CARD_H
#define CLIPPER_CARD_H

class ClipperCard {
private:
    int x;
    int y;

public:
    ClipperCard();
    ClipperCard(int startX, int startY);

    int getX() const;
    int getY() const;

    void setPosition(int newX, int newY);
};

#endif
