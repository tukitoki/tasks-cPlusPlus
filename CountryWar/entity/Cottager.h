//
// Created by iamki on 12.03.2023.
//

#ifndef SECOND_COTTAGER_H
#define SECOND_COTTAGER_H

#include "Character.h"
#include "../utils/Vector2D.h"
#include "Mole.h"
#include "../Field.h"

class Field;

class Mole;

class Cottager : public Character {
public:

    Cottager(int speed, int hitRadius, Vector2D &position);

    ~Cottager() = default;

    int getSpeed();

    int getHitRadius();

    Vector2D getPosition();

    void setField(Field *field);

    void hit(Mole *mole);

    void move() override;

private:
    Mole *findClosestMole();

    bool canKillMole(Vector2D molePosition);

private:
    int speed;
    int hitRadius;
    Vector2D position;
    Field *field;
};


#endif //SECOND_COTTAGER_H
