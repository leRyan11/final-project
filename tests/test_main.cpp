#include <cassert>
#include <iostream>
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

void test_collect_card_no_match() {
    std::cout << "Collect card (no match)... ";
    BartSnakeGame game;
    game.startGame();

    game.setSnakeHeadPositionForTest(0, 0);
    game.setCardPosition(3, 3);

    bool collected = game.collectCardIfReached();

    assert(!collected);
    assert(game.getScore() == 0);
    assert(game.getSnakeLength() == 1);
    assert(game.getCardX() == 3);
    assert(game.getCardY() == 3);
    std::cout << "PASSED\n";
}

void test_collect_card_after_update_boundary() {
    std::cout << "Collect card after update (boundary)... ";
    BartSnakeGame game;
    game.startGame();

    game.setSnakeHeadPositionForTest(8, 0);
    game.setCardPosition(9, 0);
    game.processInput('d');
    game.update();

    assert(game.isRunning());
    assert(game.getScore() == 10);
    assert(game.getSnakeLength() == 2);
    assert(game.getCardX() == 0);
    assert(game.getCardY() == 0);
    std::cout << "PASSED\n";
}

int main() {
    test_collect_card_normal();
    test_collect_card_no_match();
    test_collect_card_after_update_boundary();
    return 0;
}
