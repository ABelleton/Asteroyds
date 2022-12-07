#pragma once

// Mother class for every token on the grid
class Token {
	// x coordinate of the token
	int x;
	// y coordinate of the token
	int y;
	// orientation of the token
	int orientation;

	// Constructor setting parameters at 0
	Token() { x = 0; y = 0; orientation = 0; }
	// Constructor setting parameters to custom values
	Token(int x, int y, int orientation) { this.x = x; this.y = y; this.orientation = orientation; }

	// method to move the token
	virtual void moveToken(int direction, grid g);
};