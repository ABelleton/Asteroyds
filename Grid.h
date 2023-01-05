#pragma once
#include <vector>
#include <iostream>
#include "Token.h"


class Grid
{
private : 
    vector<vector<Token*>> grid;
public : 
    Grid();
    void initGrid();
    void updateGrid();

}