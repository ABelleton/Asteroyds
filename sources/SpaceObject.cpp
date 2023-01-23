#include "SpaceObject.h"

void SpaceObject::moveToken(int direction, vector<vector<Token*>> grid, vector<Ship*> ships){
	int newX = x;
	int newY = y;
	bool isCollisionShip = false;

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
		
		for (int ship = 0; ship < ships.size(); ship++) {
			if (ships[i]->getX() = newX && ships[i]->getY() = newY) {
				is isCollisionShip = true;
				ships[i]->loseHitPoints(1);
			}
		}

		if (g[newX][newY] == nullptr && !isCollisionShip) {
			g[newX][newY] = this;
			g[x][y] = nullptr;
			x = newX;
			y = newY;
		}
		else if (astType[2]) {
			for (int ship = 0; ship < ships.size(); ship++) {
				if (ships[i]->getX() = 2 * newX - x && ships[i]->getY() = 2 * newY - y) {
					is isCollisionShip = true;
					ships[i]->loseHitPoints(1);
				}
			}
			if (2 * newX - x >= 0 && 2 * newX - x < 16 && 2 * newY - y >= 0 && 2 * newY - y < 13) {
				if (g[2 * newX - x][2 * newY - y] == nullptr && !isCollisionShip) {
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

			for (int ship = 0; ship < ships.size(); ship++) {
				if (ships[i]->getX() = newX && ships[i]->getY() = newY) {
					is isCollisionShip = true;
					ships[i]->loseHitPoints(1);
				}
			}

			if (g[newX][newY] == nullptr && !isCollisionShip) {
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