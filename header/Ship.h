#pragma once

#include <iostream>
#include "Token.h"

using namespace std;

//Mother class of ship tokens
class Ship : public Token {
	//id of the ship
	int idShip;
	//HP of the ship, representing its remaining life
	int hitPoints;
	//Boolean array representing which doors where validated by id : when everything is true, the ship wins
	bool[4] reachedDoors;
public:
	//Constructors
	Ship(int orient, int x_coord, int y_coord, , int id);

	//Virtual members
	virtual vector<int> chooseMoves()=0;

	//Members
	void moveToken(int direction, grid g);
};