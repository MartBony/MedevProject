#include "Player.h"
#include <iostream>
using namespace std;


vector<int> Player::toIntCoord(string coord) {
	vector<int> IntCoord;
	int x = static_cast<int>(coord.at(0)) - 65; //Le code ASCII du A est 65, celui de B est 66, etc.
	int y = coord.at(1)-1;
	IntCoord.push_back(x);
	IntCoord.push_back(y);
}

void Player::initShips() {

	cout << "Place your ships by entering the coordinates occupied by each one : " << endl;
	vector<vector<int>> fleet{ {1,5},{1,4},{1,3},{2,2},{2,1} }; //vect<vect < number of ships of that length, length of a ship > >

	for (vector<int> shipType : fleet) {
		size_t NbOfShips = shipType.at(0);
		size_t shipLength = shipType.at(1);
		string shipName{};
		switch (shipLength) { //attribution
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

				this->shipGrid.display()

					cout << "Enter coordinates for the " << shipName << " number " << shipIndex << " (" << shipLength - cellIndex << " cell(s) remaining) : ";
				string coord{};
				cin >> coord;
				vector<int> IntCoord = toIntCoord(coord);
				int x = IntCoord.at(0);
				int y = IntCoord.at(1);


				if (this->shipGrid.at(x).at(y).getOccupant() == nullptr) {
					position.push_back(shipGrid.at(x).at(y));
				}
			}

			Ship newShip(position, shipName);
			for (Cell* ptrC : position) {
				ptrC->setOccupant(newShip);
			}
			this->shipList.push_back(&newShip);
		}
	}
}

Player* Player::playTurn(const char& row = '_', const char& col = '_') {
	//Asking confirmation from the player to start his turn
	cout << "It's " << this->name << "'s turn. Press Enter to start your turn." << endl;
	cin;

	//Display the player's grid and the opponent's last attack
	cout << "This is your grid." << endl;
	if (row != '_') {
		cout << "Your opponent attacked " << row << col << " on his last turn" << endl;
	}
	this->shipGrid.display();

	//Display the player's attack grid
	cout << "This is the grid of your previous attacks:" << endl;
	this->attackGrid.display();

	// Ask the player for a cell to attack
	map<char, int> rowMap = { {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}};
	char attackRow = '_';
	int attackCol = -1;
	while (!rowMap.count(attackRow)) {
		cout << "Enter a row to attack (Letter between A and J)" << endl;
		cin >> attackRow; 
	}
	while (attackCol < 1 || attackCol > 10) {
		cout << "Enter a column to attack (Integer between 1 and 10)" << endl;
		cin >> attackCol;
	}
	attackCol--;

	//Update the grids
	this->attackGrid.attack(rowMap[attackRow], attackCol);
	this->opponent->shipGrid.attack(rowMap[attackRow], attackCol);

	if (!opponent->hasLost()) {
		//Start other player's turn
		return this->opponent->playTurn(attackRow, (char)attackCol);
	}
	else {
		//Return the winner of the game
		return this;
	}
}

bool Player::hasLost() {
	for (auto& ship : shipList) {
		if (ship->isAlive()) {
			return false; 
		}
	}
	return true; 
}
