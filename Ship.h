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
	
	//Constructeurs
	Ship(int id, int hp) { idShip = id; hitPoints = hp; }

	//Fonctions virtuelles
	virtual

	//Bjr
};