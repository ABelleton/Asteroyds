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
void Ship::moveToken(int direction, grid g) {

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