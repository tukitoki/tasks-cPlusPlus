//
// Created by iamki on 13.03.2023.
//

#include "Field.h"

Field::Field(Cottager *cottager, vector<Mole *> &moles, int row, int column) {
    this->cottager = cottager;
    this->moles = moles;
    this->row = row;
    this->column = column;
    this->field = new bool *[row];
    for (int i = 0; i < row; i++) {
        this->field[i] = new bool[column];
        for (int j = 0; j < column; j++) {
            this->field[i][j] = true;
        }
    }
}

Field::~Field() {
    delete(this->cottager);
    for (Mole *mole : this->moles) {
        delete(mole);
    }
}

vector<Mole *> Field::getMoles() {
    return this->moles;
}

Cottager Field::getCottager() {
    return *this->cottager;
}

int Field::getRow() {
    return this->row;
}

int Field::getColumn() {
    return this->column;
}

bool **Field::getField() {
    return this->field;
}

void Field::setMoles(vector<Mole *> moles) {
    this->moles = moles;
}

void Field::cottagerMove() {
    this->cottager->move();
}

void Field::molesMove() {
    for (int i = 0; i < this->getMoles().size(); i++) {
        this->getMoles()[i]->move();
    }
    Mole::reproduction(*this);
}

bool Field::isLandWithoutCrop() {
    for (int row = 0; row < this->row; row++) {
        for (int column = 0; column < this->column; column++) {
            if (this->field[row][column]) {
                return false;
            }
        }
    }
    return true;
}

bool Field::isRightCoord(int x, int y) {
    if (x < 0) {
        return false;
    }
    if (y < 0) {
        return false;
    }
    if (x >= this->row) {
        return false;
    }
    if (y >= this->column) {
        return false;
    }
    return true;
}

int Field::getCropsCountAroundMole(Mole *mole) {
    int x = mole->getPosition().getX();
    int y = mole->getPosition().getY();
    int corps = 0;
    bool **garden = this->field;
    for (int row = x - 1; row <= x + 1; row++) {
        for (int col = y - 1; col <= y + 1; col++) {
            if (!isRightCoord(row, col)) {
                continue;
            }
            if (garden[row][col]) {
                corps++;
            }
        }
    }
    return corps;
}

Vector2D *Field::getCorpAroundMole(Mole *mole) {
    int x = mole->getPosition().getX();
    int y = mole->getPosition().getY();
    bool **garden = this->field;
    for (int row = x - 1; row <= x + 1; row++) {
        for (int col = y - 1; col <= y + 1; col++) {
            if (!isRightCoord(row, col)) {
                continue;
            }
            if (garden[row][col]) {
                return new Vector2D(row, col);
            }
        }
    }
    return nullptr;
}