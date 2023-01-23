#pragma once

#include "Ship.h"

#include<iostream>
#include<vector>

class IA : public Ship {

	int xDirection;
	int yDirection;

#pragma region Methods
	vector<int> chooseMoves();
	void findClosestDoor(vector<vector<Token*>> grid);
	IA() : Ship() { findClosestDoor(); }
	void actuDoorPosition();
#pragma endregion
};