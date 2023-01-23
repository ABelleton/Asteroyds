#pragma once

/*! \file Door.h
* \brief Contains the Door class
*/

#pragma once
#include "SpaceObject.h"

/*! \class Door
* \brief Class for the behavior of doors \n
* Parent class : SpaceObject
*/
class Door : public SpaceObject {

public:

	/*! \brief Constructor \n
	* Constructor for a Door \n
	* The door ID is given in consecutive ascending order 
	* \param none
	*/
	Door() : SpaceObject() {
		idDoor = nbDoors;
		nbDoors++;
		isDoor = true;
	}

	/*! \brief Constructor \n
	* Constructor for a Door \n
	* The door ID is given in consecutive ascending order
	* \param x, y : position of the SpaceObject
	*/
	Door(int x, int y) : SpaceObject(x, y) {
		idDoor = nbDoors;
		nbDoors++;
		isDoor = true;
	}

	/*! \brief Constructor \n
	* Constructor for a Door \n
	* The door ID is given in consecutive ascending order
	* \param red, white, blue : color of the constructed SpaceObject
	*/
	Door(bool red, bool white, bool blue) : SpaceObject(red, white, blue) {
		idDoor = nbDoors;
		nbDoors++;
		isDoor = true;
	}

	/*! \brief Constructor \n
	* Constructor for a Door \n
	* The door ID is given in consecutive ascending order
    * \param x, y : position of the SpaceObject
    * \param red, white, blue : color of the constructed SpaceObject
	*/
		Door(int x, int y, bool red, bool white, bool blue) : SpaceObject(x, y, red, white, blue) {
		idDoor = nbDoors;
		nbDoors++;
		isDoor = true;
	}

	/*! \brief ID Getter \n
	* Returns the ID of the door
	* \param none
	*/
	int getIdDoor() { return idDoor; }

private:
	static int nbDoors; // Initialized to 0 and used to have successive id for the doors
	int idDoor;
};

Door::nbDoors = 0;