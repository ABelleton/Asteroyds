#include "Utils.h"

void getDiceValues(){
	srand(time(0));
	SpaceObject::diceValues = { rand() % 6, rand() % 6 , rand() % 6 };
}