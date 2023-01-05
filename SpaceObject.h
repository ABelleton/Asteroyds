#pragma once

#include "Token.h"
#include "Grid.h"

class SpaceObject:Token{
    private:
    bool[3] astType;
    static int[3] diceValues;

    public:
    moveToken(int direction, Grid g);
}