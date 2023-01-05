// Class for the behavior of asteroyds

#pragma once
#include "SpaceObject.h"

class Asteroyd : public SpaceObject {

public:
	Asteroyd() : SpaceObject() {};
	Asteroyd(int x, int y) : SpaceObject(x, y) {};
	Asteroyd(bool red, bool white, bool blue) : SpaceObject(red, white, blue) {};
	Asteroyd(int x, int y, bool red, bool white, bool blue) : SpaceObject(x, y, red, white, blue) {};
};