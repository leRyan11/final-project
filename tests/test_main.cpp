#include <cassert>
#include <iostream>
#include <string>
#include "../src/BartSnakeGame.h"

void test_collect_card_normal() {
    std::cout << "Collect card (normal)... ";
    BartSnakeGame game;
    game.startGame();

    game.setSnakeHeadPositionForTest(2, 2);
    game.setCardPosition(2, 2);

    bool collected = game.collectCardIfReached();

    assert(collected);
    assert(game.getScore() == 10);
    assert(game.getSnakeLength() == 2);
    assert(!(game.getCardX() == 2 && game.getCardY() == 2));
    std::cout << "PASSED\n";
}

int main() {
    test_collect_card_normal();
    return 0;
}
