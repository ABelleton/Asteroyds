#pragma once
#include <vector>
#include <iostream>


class Grid
{
private : 
    vector<vector<Token*>> grid;
public : 
    Grid Grid();
    void updateGrid();

}