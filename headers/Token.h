#pragma once

// includes
#include<cstdlib>

// Mother class for every token on the grid
class Token {
#pragma region Parameters
	// x coordinate of the token
	int x;
	// y coordinate of the token
	int y;
	// orientation of the token
	int orientation;
#pragma endregion

#pragma region Constructors
	// Constructor setting parameters at 0
	Token() { x = 0; y = 0; orientation = 0; }
	
	// Constructor setting coordinates to custom values and orientation to random value
	Token(int x, int y) { this.x = x, this.y = y, orientation = rand() % 6; }

	// Constructor setting parameters to custom values
	Token(int x, int y, int orientation) { this.x = x; this.y = y; this.orientation = orientation; }
#pragma endregion

#pragma region methods
	// method to move the token
	virtual void moveToken(int direction, grid g) = 0;
#pragma endregion
};