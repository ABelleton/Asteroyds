#include "Ship.h"

//Constructeurs
Ship(int orient, int x_coord, int y_coord, , int id) { 
	orientation = orient;
	x = x_coord;
	y = y_coord;
	idShip = id;
	hitPoints = 6;
	reachedDoors = [false, false, false, false];
}

//Fonctions
void moveToken(int direction, grid g) {

}