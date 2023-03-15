//
// Created by iamki on 12.03.2023.
//

#include <math.h>
#include "Vector2D.h"

Vector2D::Vector2D() {}

Vector2D::Vector2D(int x, int y) {
    this->y = y;
    this->x = x;
}

int Vector2D::getX() {
    return this->x;
}

int Vector2D::getY() {
    return this->y;
}

void Vector2D::setX(int x) {
    this->x = x;
}

void Vector2D::setY(int y) {
    this->y = y;
}

double Vector2D::getDistanceToVector(Vector2D vector2D) {
    return sqrt(pow(this->x - vector2D.getX(), 2)
                + pow(this->y - vector2D.getY(), 2));
}