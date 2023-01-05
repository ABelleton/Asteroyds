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

}