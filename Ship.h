#pragma once

#include <iostream>

using namespace std;

class Ship : public Token {
	int idShip;
	int hitPoints;
	bool[4] reachedDoors;
public:
	//Constructeurs
	Ship(int orient, int x_coord, int y_coord, , int id);

	//Fonctions virtuelles
	virtual vector<int> chooseMoves();

	//Fonctions
	void moveToken(int direction, grid g);
};