#include <iostream>
#include "game/Game.h"

void input(string name, int *field) {
    std::cout << name;
    std::cin >> *field;
    std::cout << endl;
}

int main() {
    int cottagerSpeed, cottagerHitRadius, maleAmount, femaleAmount, rows, cols;
    input("Input cottager speed:", &cottagerSpeed);
    input("Input cottager hit radius:", &cottagerHitRadius);
    input("Input mole male count:", &maleAmount);
    input("Input mole female count:", &femaleAmount);
    input("Input field max rows:", &rows);
    input("Input field max cols:", &cols);
    Game *game = new Game(cottagerSpeed, cottagerHitRadius, maleAmount, femaleAmount, rows, cols);
    game->startPlay();
    delete(game);
}

