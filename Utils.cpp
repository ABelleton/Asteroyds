#include "Utils.h"

// Get 3 random values between 0 and 5, one for each dice
void getDiceValues(){
	srand(time(0));
	SpaceObject::diceValues = { rand() % 6, rand() % 6 , rand() % 6 };
}