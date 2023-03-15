//
// Created by iamki on 15.03.2023.
//

#include "Generator.h"

Generator::Generator() {
}

int Generator::getNumberBetween(int first, int second) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distX(first, second);
    return distX(gen);
}