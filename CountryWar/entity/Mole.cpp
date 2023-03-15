//
// Created by iamki on 12.03.2023.
//

#include "Mole.h"
#include "../utils/Generator.h"

Mole::Mole(Gender gender, Vector2D &position, bool isUnderground) {
    this->gender = gender;
    this->position = position;
    this->isUnderground = isUnderground;
    this->corpsToDestroy = 0;
}

void Mole::setField(Field *field) {
    this->field = field;
}

Gender Mole::getGender() {
    return this->gender;
}

bool Mole::getIsUnderground() {
    return this->isUnderground;
}

Vector2D Mole::getPosition() {
    return this->position;
}

void Mole::move() {
    if (this->corpsToDestroy != 0) {
        return destroyCorp();
    }
    int x = Generator::getNumberBetween(0, this->field->getRow() - 1);
    int y = Generator::getNumberBetween(0, this->field->getColumn() - 1);
    this->position = *new Vector2D(x, y);
    this->isUnderground = Generator::getNumberBetween(1, 2) % 2 == 0;
    if (this->isUnderground) {
        return;
    }
    int corps = this->field->getCropsCountAroundMole(this);
    this->corpsToDestroy = Generator::getNumberBetween(0, corps);
    if (this->corpsToDestroy == 0) {
        this->isUnderground = true;
    }
}

void Mole::reproduction(Field &field) {
    vector<Mole *> moles = field.getMoles();
    vector<Mole *> newMoles;
    auto iter = moles.begin();
    while (iter != moles.end()) {
        auto iter1 = iter + 1;
        Mole *initMole = *iter;
        newMoles.push_back(initMole);
        if (!initMole->isUnderground) {
            iter++;
            continue;
        }
        int x = initMole->getPosition().getX();
        int y = initMole->getPosition().getY();
        while (iter1 != moles.end()) {
            Mole *secMole = *iter1;
            if (!secMole->isUnderground) {
                iter1++;
                continue;
            }
            if (secMole->getPosition().getX() == x && secMole->getPosition().getY() == y
                && secMole->getGender() != initMole->getGender()) {
                Gender gender;
                if (Generator::getNumberBetween(0, 1) % 2 == 0) {
                    gender = Male;
                } else {
                    gender = Female;
                }
                Mole *mole = new Mole(gender, *new Vector2D(0, 0), true);
                mole->setField(&field);
                newMoles.push_back(mole);
            }
            iter1++;
        }
        iter++;
    }
    if (newMoles.size() != moles.size()) {
        field.setMoles(newMoles);
    }
}

void Mole::destroyCorp() {
    Vector2D *vector2D = this->field->getCorpAroundMole(this);
    if (vector2D == nullptr) {
        this->corpsToDestroy = 0;
        this->isUnderground = true;
        return;
    }
    this->field->getField()[vector2D->getX()][vector2D->getY()] = false;
    this->corpsToDestroy -= 1;
    if (this->corpsToDestroy == 0) {
        this->isUnderground = true;
    }
}