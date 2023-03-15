//
// Created by iamki on 13.03.2023.
//

#include <iostream>
#include "Game.h"
#include "../gui/GUI.h"
#include <chrono>
#include <thread>



Game::Game(int cottagerSpeed, int cottagerHitRadius, int maleMoleAmount,
           int femaleMoleAmount, int rowFieldSize, int columnFieldSize) {
    Vector2D *cottagerPos = new Vector2D(0, 0);
    Cottager *cottager = new Cottager(cottagerSpeed, cottagerHitRadius,
                                      *cottagerPos);
    vector<Mole *> moles;
    for (int i = 0; i < maleMoleAmount; i++) {
        moles.push_back(new Mole(Male, *new Vector2D(0, 0), true));
    }
    for (int i = 0; i < femaleMoleAmount; i++) {
        moles.push_back(new Mole(Female, *new Vector2D(0, 0), true));
    }
    this->field = new Field(cottager, moles, rowFieldSize, columnFieldSize);
    cottager->setField(this->field);
    for (int i = 0; i < moles.size(); i++) {
        moles[i]->setField(this->field);
    }
}

Game::~Game() {
    delete(this->field);
}

Field Game::getField() {
    return *this->field;
}

Game::GameState Game::getGameState() {
    return this->gameState;
}

void Game::setGameState(Game::GameState gameState) {
    this->gameState = gameState;
}

void Game::startPlay() {
    this->gameState = Playing;
    GUI::printField(this->field, this->gameState);
    while (gameState == Playing) {
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        this->field->cottagerMove();
        this->field->molesMove();
        this->checkGameState();
        GUI::printField(this->field, this->gameState);
    }
}

void Game::checkGameState() {
    if (this->field->getMoles().empty()) {
        this->gameState = Cottager_win;
    }
    if (this->field->isLandWithoutCrop()) {
        this->gameState = Mole_win;
    }
}