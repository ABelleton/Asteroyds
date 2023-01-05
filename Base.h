// Classe décrivant le comportement des bases

#pragma once
#include "SpaceObject.h"

class Base : public SpaceObject {

public:

	Base() : SpaceObject(){ astType = [false, false, false]; }
};