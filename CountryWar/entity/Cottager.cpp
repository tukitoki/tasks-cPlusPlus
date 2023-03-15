//
// Created by iamki on 12.03.2023.
//

#include "Cottager.h"
#include <climits>

Cottager::Cottager(int speed, int hitRadius, Vector2D &position) {
    this->speed = speed;
    this->hitRadius = hitRadius;
    this->position = position;
}

int Cottager::getSpeed() {
    return this->speed;
}

int Cottager::getHitRadius() {
    return this->hitRadius;
}

Vector2D Cottager::getPosition() {
    return this->position;
}

void Cottager::setField(Field *field) {
    this->field = field;
}

void Cottager::hit(Mole *mole) {
    vector<Mole *> moles = this->field->getMoles();
    vector<Mole *>::iterator iter = moles.begin();
    while (iter != moles.end()) {
        if (*iter == mole) {
            moles.erase(iter);
            delete (mole);
            this->field->setMoles(moles);
            return;
        }
        iter++;
    }
}

void Cottager::move() {
    Mole *mole = findClosestMole();
    if (mole == nullptr) {
        return;
    }
    if (canKillMole(mole->getPosition())) {
        hit(mole);
        return;
    }
    int currMovementSpeed = this->speed;
    int moleX = mole->getPosition().getX();
    int moleY = mole->getPosition().getY();
    int cottagerX = this->getPosition().getX();
    int cottagerY = this->getPosition().getY();
    if (moleX > cottagerX) {
        while (cottagerX != moleX && currMovementSpeed > 0) {
            cottagerX += 1;
            currMovementSpeed--;
        }
    }
    if (moleX < cottagerX) {
        while (cottagerX != moleX && currMovementSpeed > 0) {
            cottagerX -= 1;
            currMovementSpeed--;
        }
    }
    if (moleY > cottagerY) {
        while (cottagerY != moleY && currMovementSpeed > 0) {
            cottagerY += 1;
            currMovementSpeed--;
        }
    }
    if (moleY < cottagerY) {
        while (cottagerY != moleY && currMovementSpeed > 0) {
            cottagerY -= 1;
            currMovementSpeed--;
        }
    }
    this->position.setX(cottagerX);
    this->position.setY(cottagerY);
    if (canKillMole(mole->getPosition())) {
        hit(mole);
    }
}

bool Cottager::canKillMole(Vector2D molePosition) {
    Vector2D pos = this->position;
    if (pos.getX() == molePosition.getX()) {
        if (pos.getY() + this->hitRadius >= molePosition.getY()) {
            return true;
        }
    }
    if (pos.getY() == molePosition.getY()) {
        if (pos.getX() + this->hitRadius >= molePosition.getX()) {
            return true;
        }
    }
    return false;
}

Mole *Cottager::findClosestMole() {
    Mole *closestMole = nullptr;
    double closestDistance = INT_MAX;
    vector<Mole *> moles = this->field->getMoles();
    for (int i = 0; i < moles.size(); i++) {
        if (moles[i]->getIsUnderground()) {
            continue;
        }
        double distance = this->position.getDistanceToVector(moles[i]->getPosition());
        if (closestDistance > distance) {
            closestMole = moles[i];
            closestDistance = distance;
        }
    }
    return closestMole;
}
