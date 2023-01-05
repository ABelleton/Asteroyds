// Classe décrivant le comportement des portes

#pragma once
#include "SpaceObject.h"

class Door : public SpaceObject {

public:
	Door() : SpaceObject(){
		idDoor = nbDoors;
		nbDoors++;
	}

private:
	static int nbDoors;
	int idDoor;
};

Door::nbDoors = 0;