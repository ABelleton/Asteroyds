#pragma once

/*! \file Wall.h
* \brief Contains the Wall class
*/

/// The walls do not exist in the original game, but we use them to simulate the borders of the board \n
/// Walls do not move and so have no color.

#include "SpaceObject.h"

/*! \class Wall
* \brief Class for the behavior of walls \n
* Parent class : SpaceObject
*/
class Wall : public SpaceObject {

public:

	/*! \brief Constructor \n
	* Constructor for a Wall
	* \param none
	*/
	Wall() : SpaceObject(false, false, false) {}; 

	/*! \brief Constructor \n
	* Constructor for a Wall
	* \param x, y : position of the SpaceObject
	*/
	Wall(int x, int y) : SpaceObject(x, y, false, false, false) {};
};