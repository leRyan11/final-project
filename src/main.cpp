#include <iostream>
#include "BartSnakeGame.h"

using namespace std;

int main() {
    BartSnakeGame game;
    game.startGame();

    cout << "Bart Snake" << endl;
    cout << "Use w/a/s/d to move, r to render, q to quit." << endl;

    char input;
    while (game.isRunning() && cin >> input) {
        if (input == 'r') {
            game.render();
        } else {
            game.processInput(input);
            game.update();
            game.render();
        }
    }

    return 0;
}