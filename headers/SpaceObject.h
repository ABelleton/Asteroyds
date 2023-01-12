#pragma once

#include "Token.h"
#include "Grid.h"

class SpaceObject:Token{
    private:
    bool[3] astType;
    static int[3] diceValues;
    bool isDoor;

    public:
        SpaceObject();
        SpaceObject(int x, int y);
        SpaceObject(bool rouge, bool blanc, bool bleu);
        SpaceObject(int x, int y, bool rouge, bool blanc, bool bleu);

    moveToken(int direction, Grid g);
    bool getIsDoor() { return isdoor; }
}

SpaceObject::diceValues = { 0,0,0 };