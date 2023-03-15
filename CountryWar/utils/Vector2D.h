//
// Created by iamki on 12.03.2023.
//

#ifndef SECOND_VECTOR2D_H
#define SECOND_VECTOR2D_H


class Vector2D {
public:
    Vector2D();
    Vector2D(int x, int y);

public:
    int getX();
    int getY();

    void setX(int x);
    void setY(int y);

    double getDistanceToVector(Vector2D vector2D);
private:
    int x;
    int y;
};


#endif //SECOND_VECTOR2D_H
