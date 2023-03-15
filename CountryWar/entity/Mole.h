//
// Created by iamki on 12.03.2023.
//

#ifndef SECOND_MOLE_H
#define SECOND_MOLE_H


#include "Character.h"
#include "../utils/Vector2D.h"
#include "../Field.h"

class Field;

enum Gender {
    Male,
    Female
};

class Mole : public Character {
public:

    Mole(Gender gender, Vector2D &position, bool isUnderground);

    ~Mole() = default;

public:

    void setField(Field *field);

    Gender getGender();

    Vector2D getPosition();

    bool getIsUnderground();

    static void reproduction(Field &field);

    void move() override;

private:
    void destroyCorp();

private:
    Gender gender;
    Vector2D position;
    bool isUnderground;
    Field *field;
    int corpsToDestroy;
};


#endif //SECOND_MOLE_H
