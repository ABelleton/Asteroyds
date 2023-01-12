#pragma once

#include "Token.h"
#include "Grid.h"

class SpaceObject:Token{
    private:
        bool[3] astType;
        int idSpaceObject;
        static int idEnum;
        bool isDoor;

    public:
        static int[3] diceValues;

        SpaceObject();
        SpaceObject(int x, int y);
        SpaceObject(bool rouge, bool blanc, bool bleu);
        SpaceObject(int x, int y, bool rouge, bool blanc, bool bleu);

        //get
        int getID() { return idSpaceObject; }
        bool getIsDoor() { return isDoor; }
        bool[3] getAstType() {return astType; }

        // méthodes
        void moveToken(int direction, vector<vector<Token*>> grid);
}

SpaceObject::diceValues = { 0,0,0 };
SpaceObject::idEnum = 0;