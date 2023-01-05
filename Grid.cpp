#include "Grid.h"

Grid::Grid() {
	for (int i = 0; i < 7; i++) {
		grid.push_back(vector<Token*>);
		for (int k = 0; k < 7+i; k++) {
			grid[i].push_back(nullptr);
		}
	}
	
	for (int i = 7; i < 9; i++) {
		grid.push_back(vector<Token*>);
		for (int k = 0; k < 13; k++) {
			grid[i].push_back(nullptr);
		}
	}

	for (int i = 9; i < 16; i++) {
		grid.push_back(vector<Token*>);
		for (int k = 0; k < 13+9-i; k++) {
			grid[i].push_back(nullptr);
		}
	}

}

void initGrid() {
	Wall1 = new Wall(0,3);
	Wall2 = new Wall(15, 3);
	Wall3 = new Wall(3, 9);
	Wall4 = new Wall(12, 0);
	Wall5 = new Wall(4, 0);
	Wall6 = new Wall(5, 0);
	Wall7 = new Wall(10, 12);
	Wall8 = new Wall(11, 12);

	grid[0][3] = Wall1;
	grid[15][3] = Wall2;
	grid[3][9] = Wall3;
	grid[12][0] = Wall4;
	grid[4][0] = Wall5;
	grid[5][0] = Wall6;
	grid[10][12] = Wall7;
	grid[11][12] = Wall8;

}