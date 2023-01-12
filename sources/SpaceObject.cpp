#include "SpaceObject.h"

void SpaceObject::moveToken(int direction, vector<vector<Token*>> grid){
	int newX = x;
	int newY = y;

	switch (direction) {
	case 0:
		newX++;
		break;
	case 1:
		newY--;
		break;
	case 2:
		newX--;
		newY--;
		break;
	case 3:
		newX--;
		break;
	case 4:
		newY++;
		break;
	case 5:
		newX++;
		newY++;
		break;
	default:
		cout << "Erreur : valeur de direction non comprise entre 0 et 5" << endl;
		break;
	}

	if (newX >= 0 && newX < 16 && newY >= 0 && newY < 13) {

		if (g[newX][newY] == nullptr) {
			g[newX][newY] = this;
			g[x][y] = nullptr;
			x = newX;
			y = newY;
		}
		else if (astType[2]) {
			if (2 * newX - x >= 0 && 2 * newX - x < 16 && 2 * newY - y >= 0 && 2 * newY - y < 13) {
				if (g[2 * newX - x][2 * newY - y] == nullptr) {
					g[newX][newY]->x = 2 * newX - x;
					g[newX][newY]->y = 2 * newY - y;
					g[2newX - x][2 * newY - y] = g[newX][newY];
					g[newX][newY] = this;
					g[x][y] = nullptr;
					x = newX;
					y = newY;
				}
			}
		}
	}

	if (astType[0]) {
		switch (direction) {
		case 0:
			newX++;
			break;
		case 1:
			newY--;
			break;
		case 2:
			newX--;
			newY--;
			break;
		case 3:
			newX--;
			break;
		case 4:
			newY++;
			break;
		case 5:
			newX++;
			newY++;
			break;
		default:
			cout << "Erreur : valeur de direction non comprise entre 0 et 5" << endl;
			break;
		}

		if (newX >= 0 && newX < 16 && newY >= 0 && newY < 13) {

			if (g[newX][newY] == nullptr) {
				g[newX][newY] = this;
				g[x][y] = nullptr;
				x = newX;
				y = newY;
			}
		}
	}
}

SpaceObject::SpaceObject() : Token() {
    astType = { false, false, false };
    isDoor = false;
}

SpaceObject::SpaceObject(int x, int y) : Token(x, y) {
    astType = { false, false, false };
    isDoor = false;
}

SpaceObject::SpaceObject(bool rouge, bool blanc, bool bleu) : Token() {
    astType = { rouge, blanc, bleu };
    isDoor = false;
}

SpaceObject::SpaceObject(int x, int y, bool rouge, bool blanc, bool bleu) : Token(x, y) {
        astType = { rouge, blanc, bleu };
        isDoor = false;
}