#pragma once

#include <iostream>

using namespace std;

class Ship : public Token {
	int idShip;
	int hitPoints;
	bool[4] reachedDoors;
public:
	//Constructors
	Ship(int id, int hp);
	//Bjr
};