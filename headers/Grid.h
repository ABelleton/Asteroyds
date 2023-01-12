#pragma once
#include <vector>
#include <iostream>
#include "Token.h"
#include <random>


class Grid
{
private : 
    vector<vector<Token*>> grid;
    vector<Ship*> ships;
public : 
    //Constructors
    Grid();
    //Methods
    void initGrid();
    void updateGrid();

}