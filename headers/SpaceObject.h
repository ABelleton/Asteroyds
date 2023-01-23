#pragma once

/*! \file SpaceObject.h
* \brief Contains the SpaceObject class
*/

#include "Token.h"
#include "Grid.h"
#include "Ship.h"

/*! \class SpaceObject
* \brief Parent class of all Tokens except ships \n
* Parent class : Token \n
* Inherited class : Base, Door, Wall and Asteroyd
*/
class SpaceObject:Token{
    private:
        bool[3] astType;
        int idSpaceObject;
        static int idEnum;
        bool isDoor;

    public:
        static int[3] diceValues;

        /*! \brief Constructor \n
        * Constructor for a SpaceObject
        * \param none
        */
        SpaceObject();

        /*! \brief Constructor \n
        * Constructor for a SpaceObject
        * \param x, y : position of the SpaceObject
        */
        SpaceObject(int x, int y);

        /*! \brief Constructor \n
        * Constructor for a SpaceObject
        * \param red, white, blue : color of the constructed SpaceObject
        */
        SpaceObject(bool red, bool white, bool blue);

        /*! \brief Constructor \n
        * Constructor for a SpaceObject
        * \param x, y : position of the SpaceObject
        * \param red, white, blue : color of the constructed SpaceObject
        */
        SpaceObject(int x, int y, bool red, bool white, bool blue);

        /*! \brief ID Getter \n
        * Returns the ID of the SpaceObject
        * \param none
        */
        int getID() { return idSpaceObject; }

        /*! \brief IsDoor Getter \n
        * Returns true if the SpaceObject is a door
        * \param none
        */
        bool getIsDoor() { return isDoor; }

        /*! \brief AstType Getter \n
        * Returns the type of the SpaceObject
        * \param none
        */
        bool[3] getAstType() {return astType; }

        /*! \brief Function to move the SpaceObject with regards to its surroundings \n
        * Moves the SpaceObject if the space before it is free. \n
        * If the SpaceObject is blue, The SpaceObject before it can also be moved.\n
        * This function is inherited from the Token class.
        * \param direction : Direction the SpaceObject is supposed to move in
        * \param grid : Vector containing the positions and orientations of all Tokens
        * \param ships : Vector containing the positions and orientations of all ships
        */
        void moveToken(int direction, vector<vector<Token*>> grid, vector<Ship*> ships);
}

SpaceObject::diceValues = { 0,0,0 };
SpaceObject::idEnum = 0;