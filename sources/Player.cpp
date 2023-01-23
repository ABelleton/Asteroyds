#include "Player.h"

using namespace std;

// interacts with the player to get the moves he will make
vector<int> Player::chooseMoves() {
	// list of the moves that will be returned
	vector<int> movesList;
	// key pressed (to detect action wanted)
	char key;
	// validation of selected action
	bool validAction;
	// number of moves already registered
	for (int nbMovesRegistered = 0; nbMovesRegistered < 7; nbMovesRegistered++) {
		validAction = false;
		cout << nbMovesRegistered << "ème déplacement. Que faire ?" << endl <<
			"-> 1: déplacement vers l'avant à gauche" << endl <<
			"-> 2: déplacement vers l'avant" << endl <<
			"-> 3: déplacement vers l'avant à droite" << endl <<
			"-> 4: demi-tour" << endl <<
			"-> 5: attendre" << endl;
		// Check if the key entered is a valid one, else asks for one
		while (!validAction) {
			cout << "action choisie: ";
			cin >> key;
			cout << endl;
			validAction = true;
			switch (key) {
				case 1:
					movesList.push_back(FORWARD_LEFT);
					break;
				case 2:
					movesList.push_back(FORWARD);
					break;
				case 3:
					movesList.push_back(FORWARD_RIGHT);
					break;
				case 4:
					movesList.push_back(U_TURN);
					break;
				case 5:
					movesList.push_back(WAIT);
					break;
				default:
					cout << "Action invalide !" << endl;
					validAction = false;
			}
		}
		cout << endl << endl;
	}
	return movesList;
}