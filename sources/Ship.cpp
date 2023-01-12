#include "Ship.h"

//Constructors
Ship::Ship(int orient, int x_coord, int y_coord, , int id) { 
	orientation = orient;
	x = x_coord;
	y = y_coord;
	idShip = id;
	hitPoints = 6;
	reachedDoors = [false, false, false, false];
}

//Members
void Ship::moveToken(int action, grid g) {
	// register actual coordinates and orientation
	int oldX = x;
	int oldY = y;
	int oldOrientation = orientation;

	// Actions without movement
	if (action == WAIT) {
		return;
	}
	orientation += action;
	if (action = U_TURN) {
		return;
	}

	// Moving ship 
	switch (orientation) {
	case 0: // to the right
		x += 1;
		break;
	case 1: // to the bottom right
		y -= 1;
		break;
	case 2: // to the bottom left
		y -= 1;
		x -= 1;
		break;
	case 3: // to the left
		x -= 1;
		break;
	case 4: // to the top left
		y += 1;
		break;
	case 5: // to the top right
		y += 1;
		x += 1;
		break;
	}

	// If there is a collision, removes HP and get back to previous position
	if (checkCollision(grid g)) {
		x = oldX;
		y = oldY;
	}
}

void Ship::reachDoor(int idDoor) {
	reachedDoor[idDoor] = true;
}

void Ship::loseHitPoints(int lostHP) {
	if (hitPoints >= lostHP) {
		hitPoints -= lostHP;
	} else {
		hitPoints = 0;
	}
}

void Ship::checkCollision(grid g) {
	return (!((grid[x, y] == nullptr) || (grid[x, y]->getIsDoor() == true)));
	
}