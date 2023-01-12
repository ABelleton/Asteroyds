#pragma once

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
	void moveToken(int action, grid g);
	void reachDoor(int idDoor);
	void loseHitPoints(int lostHP);
	bool checkCollision(grid g);

	//Setters
	void setIdShip(int id) { idShip = id; }
	void setHitPoints(int hp) { hitPoints = hp; }
	void setReachedDoor(bool[4] doors) { reachedDoors = doors; }

	//Getters
	int getIdShip() { return idShip; }
	int getHitPoints() { return hitPoints; }
	bool[4] getReachedDoors{ return reachDoor; }
	
};