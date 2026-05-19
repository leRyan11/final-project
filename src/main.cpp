#include <iostream>
#include "BartSnakeGame.h"

using namespace std;

int main() {
    BartSnakeGame game;
    game.startGame();

    cout << "Bart Snake initial feature demo\n";
    cout << "Use W/A/S/D to move once, or Q to quit.\n\n";
    game.render();

    char input;
    cout << "\nChoice: ";
    cin >> input;

    game.processInput(input);
    if (game.isRunning()) {
        game.update();
    }

    cout << "\nAfter update:\n";
    game.render();

    return 0;
}
