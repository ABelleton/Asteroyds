#pragma once

/*! \file Token.h
* \brief Contains the Token class
*/

// includes
#include<cstdlib>

/*! \class Token
* \brief Abstract class describing all tokens on the grid \n
* Inherited class : SpaceObject and Ship
*/
class Token {

/*! Position: xand y describe the position of the token \n
* Orientation : orientation describes the orientation of the token */
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

	// Constructor setting position to custom and orientation to random
	Token(int x, int y) {}

	// Constructor setting coordinates to custom values and orientation to random value
	Token(int x, int y) { this.x = x, this.y = y, orientation = rand() % 6; }

	// Constructor setting parameters to custom values
	Token(int x, int y, int orientation) { this.x = x; this.y = y; this.orientation = orientation; }
#pragma endregion

#pragma region Getters
	int getX() { return x; }
	int getY() { return y; }
	int getOrientation() { return orientation; }
#pragma endregion

#pragma region Setters
	void setX(int x) { this.x = x; }
	void setY(int y) { this.y = y; }
	void setOrientation(int orientation) { this.orientation = orientation; }
#pragma endregion

#pragma region Methods
	// method to move the token
	virtual void moveToken(int direction, grid g) = 0;
#pragma endregion
};