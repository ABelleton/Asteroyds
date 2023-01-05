// Class for the behavior of walls
// The walls do not exist in the original game, but we use them to simulate the borders of the board

#pragma once
#include "SpaceObject.h"

class Wall : public SpaceObject {

public:
	Wall() : SpaceObject(false, false, false) {}; // Wall do not move and so have no color
	Wall(int x, int y) : SpaceObject(x, y, false, false, false) {};
};