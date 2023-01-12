// Class for the behavior of doors

#pragma once
#include "SpaceObject.h"

class Door : public SpaceObject {

public:
	Door() : SpaceObject() {
		idDoor = nbDoors;
		nbDoors++;
		isDoor = true;
	}
	Door(int x, int y) : SpaceObject(x, y) {
		idDoor = nbDoors;
		nbDoors++;
		isDoor = true;
	}
	Door(bool red, bool white, bool blue) : SpaceObject(red, white, blue) {
		idDoor = nbDoors;
		nbDoors++;
		isDoor = true;
	}
	Door(int x, int y, bool red, bool white, bool blue) : SpaceObject(x, y, red, white, blue) {
		idDoor = nbDoors;
		nbDoors++;
		isDoor = true;
	}

	int getIdDoor() { return idDoor; }

private:
	static int nbDoors; // Initialized to 0 and used to have successive id for the doors
	int idDoor;
};

Door::nbDoors = 0;