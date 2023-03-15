//
// Created by iamki on 14.03.2023.
//

#ifndef SECOND_GUI_H
#define SECOND_GUI_H


#include "../field/Field.h"
#include "../game/Game.h"

class GUI {
public:
    GUI() = default;

    ~GUI() = default;

public:
    static void printField(Field *field, Game::GameState gameState);

private:
    static bool isMolePos(int x, int y, vector<Mole *> mole);

    static void printGameState(Game::GameState gameState);
};


#endif //SECOND_GUI_H
