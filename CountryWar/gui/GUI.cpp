//
// Created by iamki on 14.03.2023.
//

#include <iostream>
#include "GUI.h"

void GUI::printField(Field *field, Game::GameState gameState) {
    printGameState(gameState);
    Vector2D cottagerPos = field->getCottager().getPosition();
    for (int i = 0; i < field->getRow(); i++) {
        for (int j = 0; j < field->getColumn(); j++) {
            if (cottagerPos.getX() == i && cottagerPos.getY() == j) {
                std::cout << "K" << " ";
            } else if (isMolePos(i, j, field->getMoles())) {
                std::cout << "M" << " ";
            } else if (field->getField()[i][j]) {
                std::cout << "1" << " ";
            } else {
                std::cout << "0" << " ";
            }
        }
        std::cout << endl;
    }
    std::cout << "-------------------------------" << endl;
}

bool GUI::isMolePos(int x, int y, vector<Mole *> mole) {
    for (int i = 0; i < mole.size(); i++) {
        if (mole[i]->getPosition().getX() == x && mole[i]->getPosition().getY() == y && !mole[i]->getIsUnderground()) {
            return true;
        }
    }
    return false;
}

void GUI::printGameState(Game::GameState gameState) {
    switch (gameState) {
        case Game::Playing:
            cout << "Playing";
            break;
        case Game::Mole_win:
            cout << "Mole win!";
            break;
        case Game::Cottager_win:
            cout << "Cottager win!";
            break;
    }
    cout << endl;
}

