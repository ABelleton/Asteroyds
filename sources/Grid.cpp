#include "Grid.h"

Grid::Grid() {
	//on crée les 16 rangées
	
	for (int i = 0; i < 16; i++) {
		grid.push_back(vector<Token*>);
		for (int k = 0; k < 13; k++) {
			grid[i].push_back(nullptr);
		}
	}
	int rand = rand() % 6;
	for (int i = 0; i < 2; i++) {
		if (i == rand) {
			ships.push_back(new player(i, 9-i, 6-i, i));
		}
		else () {
			ships.push_back(new IA(i, 9-i, 6-i, i));
		}
	}

	for (int i = 2; i < 4; i++) {
		if (i == rand) {
			ships.push_back(new player(i, 7, 3 + i, i));
		}
		else () {
			ships.push_back(new IA(i, 7, 3 + i, i));
		}
	}

	for (int i = 4; i < 6; i++) {
		if (i == rand) {
			ships.push_back(new player(i, 4 + i, 7, i));
		}
		else () {
			ships.push_back(new IA(i, 4 + i, 7, i));
		}
	}
}

void initGrid() {
	//Creation of Walls
	Wall1 = new Wall(0,3);
	Wall2 = new Wall(15, 10);
	Wall3 = new Wall(3, 9);
	Wall4 = new Wall(12, 3);
	Wall5 = new Wall(4, 0);
	Wall6 = new Wall(5, 0);
	Wall7 = new Wall(10, 12);
	Wall8 = new Wall(11, 12);

	grid[0][3] = Wall1;
	grid[15][10] = Wall2;
	grid[3][9] = Wall3;
	grid[12][3] = Wall4;
	grid[4][0] = Wall5;
	grid[5][0] = Wall6;
	grid[10][12] = Wall7;
	grid[11][12] = Wall8;

	for (int i = 0; i < 7; i++) {
		grid[i][i + 7] = new Wall(i, i + 7);
	}

	for (int i = 9; i < 16; i++) {
		grid[i][i] = new Wall(i, i);
	}
	//Creation of bases
	grid[7][5] = base(7, 5);
	grid[7][5] = base(7, 6);
	grid[7][5] = base(8, 5);
	grid[7][5] = base(8, 7);
	grid[7][5] = base(9, 6);
	grid[7][5] = base(9, 7);
	//Creation of Asteroyds
	//Red asteroyds
	grid[3][3] = new asteroyd(3, 3, true, false, false);
	grid[5][8] = new asteroyd(5, 8, true, false, false);
	grid[10][4] = new asteroyd(10, 4, true, false, false);
	grid[12][9] = new asteroyd(12, 9, true, false, false);
	//White asteroyds
	grid[2][3] = new asteroyd(2, 3, false, true, false);
	grid[7][1] = new asteroyd(7, 1, false, true, false);
	grid[8][11] = new asteroyd(8, 11, false, true, false);
	grid[11][10] = new asteroyd(11, 10, false, true, false);
	//Blue asteroyds
	grid[4][5] = new asteroyd(4, 5, false, false, true);
	grid[6][9] = new asteroyd(6, 9, false, false, true);
	grid[10][7] = new asteroyd(10, 7, false, false, true);
	grid[8][3] = new asteroyd(8, 3, false, false, true);
	//White/Blue asteroyds
	grid[4][2] = new asteroyds(4, 2, false, true, true);
	grid[5][5] = new asteroyds(5, 5, false, true, true);
	grid[10][2] = new asteroyds(10, 2, false, true, true);
	grid[13][8] = new asteroyds(13, 8, false, true, true);
	//Red/White asteroyds
	grid[2][5] = new asteroyds(2, 5, true, true, false);
	grid[3][7] = new asteroyds(3, 7, true, true, false);
	grid[12][5] = new asteroyds(12, 5, true, true, false);
	grid[14][10] = new asteroyds(14, 10, true, true, false);
	//Grey asteroyds
	grid[1][6] = new asteroyds(1, 6, false, false, false);
	grid[1][6] = new asteroyds(5, 1, false, false, false);
	grid[1][6] = new asteroyds(7, 9, false, false, false);
	grid[1][6] = new asteroyds(9, 10, false, false, false);
	grid[1][6] = new asteroyds(10, 13, false, false, false);
	grid[1][6] = new asteroyds(14, 6, false, false, false);
	//Creation of doors
	grid[1][2] = new door(1, 2, false, true, false);
	grid[13][11] = new door(13, 11, false, true, false);
	grid[6][11] = new door(6, 11, true, false, false);
	grid[9][1] = new door(9, 1, true, false, false);

}

void updateGrid() {
	
	//Move RED
	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 13; k++) {
			if (grid[i][k] != nullptr) {
				if (getAstType()[0] == true) {
					Grid[i][k]->moveToken((SpaceObject::DiceValues[0] - grid[i][k]->getOrientation() - 2) % 6),grid);
					Grid[i][k]->moveToken((SpaceObject::DiceValues[0] - grid[i][k]->getOrientation() - 2) % 6),grid);
				}
			}
		}
	}
	//Move WHITE
	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 13; k++) {
			if (getAstType()[1] == true) {
				Grid[i][k]->moveToken((SpaceObject::DiceValues[1] - grid[i][k]->getOrientation() - 2) % 6), grid);
			}
		}
	}
	//Move BLUE
	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 13; k++) {
			if (getAstType()[0] == true) {
				Grid[i][k]->moveToken((SpaceObject::DiceValues[2] - grid[i][k]->getOrientation() - 2) % 6), grid);
			}
		}
	}

}