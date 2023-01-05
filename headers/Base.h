// Class for the behavior of bases

#pragma once
#include "SpaceObject.h"

class Base : public SpaceObject {

public:
	Base() : SpaceObject(false, false, false) {}; // Bases do not move and so have no color
	Base(int x, int y) : SpaceObject(x, y, false, false, false) {};
};