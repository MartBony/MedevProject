#include "Player.h"

vector<int> toIntCoord(string coord) {
	vector<int> IntCoord;
	int x = static_cast<int>(coord.at(0)) - 65; //Le code ASCII du A est 65, celui de B est 66, etc.
	int y = coord.at(1);
	IntCoord.push_back(x);
	IntCoord.push_back(y);
}

//bool isOccupied(int x, int y, Grid G){
	//Cell cell = *(G.cells).at(x).at(y);



void Player::initShips() {

	cout << "Place your ships by entering the coordinates occupied by each one : " << endl;
	vector<vector<int>> fleet{ {1,5},{1,4},{1,3},{2,2},{2,1} }; //vect<vect< number of ships of that length, length of a ship >>

	for (vector<int> shipType : fleet) {
		size_t NbOfShips = shipType.at(0);
		size_t shipLength = shipType.at(1);
		string shipName{};
		switch (shipLength) {
		case 5:
			shipName = "battleship";
			break;
		case 4:
			shipName = "cruiser";
			break;
		case 3:
			shipName = "destroyer";
			break;
		case 2:
			shipName = "submarine";
			break;
		case 1:
			shipName = "fishing boat";
			break;
		}

		for (size_t shipIndex = 0; shipIndex < NbOfShips; shipIndex++) {
			vector<Cell*> position{};

			for (size_t cellIndex = 0; cellIndex < shipLength; cellIndex++) {

				//Afficher la grille avec les cellules déjà occupées pour que le joueur ne choisisse pas une cellule déjà occupée

				cout << "Enter coordinates for the " << shipName << " number " << shipIndex << " (" << shipLength - cellIndex << " cell(s) remaining) : ";
				string coord{};
				cin >> coord;
				vector<int> IntCoord = toIntCoord(coord);
				int x = IntCoord.at(0);
				int y = IntCoord.at(1);
				/*if (!isOccupied(x, y)) {
					Cell newCell = Cell(x, y);
					position.push_back(&newCell);
				}
				*/
			}
		}
	}