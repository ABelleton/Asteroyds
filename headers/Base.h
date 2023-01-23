#pragma once

/*! \file Base.h
* \brief Contains the Base class
*/

/// Base do not move and so have no color.
///

#include "SpaceObject.h"

/*! \class Base
* \brief Class for the behavior of bases \n
* Parent class : SpaceObject
*/
class Base : public SpaceObject {

public:

	/*! \brief Constructor \n
	* Constructor for a Base
	* \param none
	*/
	Base() : SpaceObject(false, false, false) {};

	/*! \brief Constructor \n
	* Constructor for a Base
	* \param x, y : position of the SpaceObject
	*/
	Base(int x, int y) : SpaceObject(x, y, false, false, false) {};
};