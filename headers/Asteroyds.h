#pragma once

/*! \file Asteroyds.h
* \brief Contains the Asteroyd class
*/

#include "SpaceObject.h"

/*! \class Asteroyds
* \brief Class for the behavior of asteroyds \n
* Parent class : SpaceObject
*/
class Asteroyd : public SpaceObject {

public:
	/*! \brief Constructor \n
	* Constructor for an Asteroyd
	* \param none
	*/
	Asteroyd() : SpaceObject() {};

	/*! \brief Constructor \n
	* Constructor for an Asteroyd
	* \param x, y : position of the SpaceObject
	*/
	Asteroyd(int x, int y) : SpaceObject(x, y) {};

	/*! \brief Constructor \n
	* Constructor for an Asteroyd
	* \param red, white, blue : color of the constructed SpaceObject
	*/
	Asteroyd(bool red, bool white, bool blue) : SpaceObject(red, white, blue) {};

	/*! \brief Constructor \n
	* Constructor for an Asteroyd
    * \param x, y : position of the SpaceObject
    * \param red, white, blue : color of the constructed SpaceObject
	*/
	Asteroyd(int x, int y, bool red, bool white, bool blue) : SpaceObject(x, y, red, white, blue) {};
};