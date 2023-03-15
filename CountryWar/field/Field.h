//
// Created by iamki on 13.03.2023.
//

#ifndef SECOND_FIELD_H
#define SECOND_FIELD_H

#include <vector>
#include "../entity/Cottager.h"
#include "../entity/Mole.h"

using namespace std;

class Cottager;
class Mole;

class Field {
public:

    Field(Cottager *cottager, vector<Mole *> &moles, int row, int column);

    ~Field();
public:
    vector<Mole *> getMoles();

    Cottager getCottager();

    int getRow();

    int getColumn();

    bool **getField();

    int getCropsCountAroundMole(Mole *mole);

    Vector2D *getCorpAroundMole(Mole *mole);

    void setMoles(vector<Mole *> moles);

    void cottagerMove();

    void molesMove();

    bool isLandWithoutCrop();

    bool isRightCoord(int x, int y);

private:
    Cottager *cottager;
    vector<Mole *> moles;
    int row;
    int column;
    bool **field;
};



#endif //SECOND_FIELD_H
