//
// Created by iamki on 13.03.2023.
//

#ifndef SECOND_GAME_H
#define SECOND_GAME_H

#include "../field/Field.h"
#include "../entity/Cottager.h"

class GUI;

class Game {
public:
    enum GameState {
        Playing,
        Cottager_win,
        Mole_win
    };

public:
    Game(int cottagerSpeed, int cottagerHitRadius, int maleMoleAmount,
         int femaleMoleAmount, int rowFieldSize, int columnFieldSize);

    ~Game();

public:
    void setGameState(Game::GameState gameState);

    Game::GameState getGameState();

    Field getField();

    void startPlay();

private:
    void checkGameState();

private:
    Field *field;
    GameState gameState;
};


#endif //SECOND_GAME_H
