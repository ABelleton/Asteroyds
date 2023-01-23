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

/*! Position: x and y describe the position of the token \n
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

	/*! \brief Constructor \n
	* Constructor for a SpaceObject \n
	* Arbitrarily sets coordinates and orientation at 0
	* \param none
	*/
	Token() { x = 0; y = 0; orientation = 0; }

	/*! \brief Constructor \n
	* Constructor for a SpaceObject \n
	* Sets position to custom and orientation to random
	* \param none
	*/
	Token(int x, int y) {}

	/*! \brief Constructor \n
	* Constructor for a SpaceObject \n
	* Sets coordinates to custom values and orientation to random value
	* \param none
	*/
	Token(int x, int y) { this.x = x, this.y = y, orientation = rand() % 6; }

	/*! \brief Constructor \n
	* Constructor for a SpaceObject \n
	* Sets coordinates  and orientation to custom values
	* \param none
	*/
	Token(int x, int y, int orientation) { this.x = x; this.y = y; this.orientation = orientation; }
#pragma endregion

#pragma region Getters

	/*! \brief X Getter \n
	* Returns the X-axis coordinate of the token
	* \param none
	*/
	int getX() { return x; }

	/*! \brief Y Getter \n
	* Returns the Y-axis coordinate of the token
	* \param none
	*/
	int getY() { return y; }

	/*! \brief Orientation Getter \n
	* Returns the orientation of the token
	* \param none
	*/
	int getOrientation() { return orientation; }
#pragma endregion

#pragma region Setters

	/*! \brief X Setter \n
	* Modifies the X-axis coordinate of the token according to the input
	* \param x : desired X-axis coordinate of the token
	*/
	void setX(int x) { this.x = x; }

	/*! \brief Y Setter \n
	* Modifies the Y-axis coordinate of the token according to the input
	* \param x : desired Y-axis coordinate of the token
	*/
	void setY(int y) { this.y = y; }

	/*! \brief Orientation Setter \n
	* Modifies the orientation of the token according to the input
	* \param x : desired orientation of the token
	*/
	void setOrientation(int orientation) { this.orientation = orientation; }
#pragma endregion

#pragma region Methods
	/*! \brief Function to move the Token with regards to its surroundings \n
	* This is a virtual function.
	* \param direction : Direction the SpaceObject is supposed to move in
	* \param grid : Vector containing the positions and orientations of all Tokens
	*/
	virtual void moveToken(int direction, grid g) = 0;
#pragma endregion
};