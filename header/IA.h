#pragma once

#include "Ship.h"

#include<iostream>
#include<vector>

class IA : public Ship {

#pragma region Methods
	vector<int> chooseMoves();
#pragma endregion
};