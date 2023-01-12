#include "SpaceObject.h"

void SpaceObject::moveToken(int direction, Grid g){
    
}

SpaceObject::SpaceObject() : Token() {
    astType = { false, false, false };
    isDoor = false;
}

SpaceObject::SpaceObject(int x, int y) : Token(x, y) {
    astType = { false, false, false };
    isDoor = false;
}

SpaceObject::SpaceObject(bool rouge, bool blanc, bool bleu) : Token() {
    astType = { rouge, blanc, bleu };
    isDoor = false;
}

SpaceObject::SpaceObject(int x, int y, bool rouge, bool blanc, bool bleu) : Token(x, y) {
        astType = { rouge, blanc, bleu };
        isDoor = false;
}