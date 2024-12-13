#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(const string& name) : name(name), shipGrid(new Grid(false)), attackGrid(new Grid(true)) {}

void Player::setOpponent(Player* opponent) {
	this->opponent = opponent;
}

vector<int> Player::toIntCoord(string coord) {
	vector<int> IntCoord;
	int x = static_cast<int>(coord.at(0)) - 65; //Le code ASCII du A est 65, celui de B est 66, etc.
	int y = coord.size() == 2 ? (int)(coord.at(1)) - 49 : 9; // If the user typed 10, the string will be of size 3 > 2
	IntCoord.push_back(x);
	IntCoord.push_back(y);
	return IntCoord;
}

bool inBounds(const int& testInt){
	return testInt >= 0 && testInt <= 9;
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

				this->shipGrid.display();

				string coord;
				int x = -1;
				int y = -1;
				while(true){
					coord = "";
					while(true){
						cout << "Enter coordinates for the " << shipName << " number " << shipIndex << " (" << shipLength - cellIndex << " cell(s) remaining) : ";
						cin >> coord;
						if(coord.size() >= 2) break;
						cout << "The input is too short" << endl;
					}
					vector<int> IntCoord = toIntCoord(coord);
					x = IntCoord.at(0);
					y = IntCoord.at(1);

					if(inBounds(x) && inBounds(y)) break;
					cout << "The input is uncorrectly formatted" << endl;
				}


				if (this->shipGrid.cells[x][y]->getOccupant() == nullptr) {
					position.push_back(shipGrid.cells[x][y]);
				}
			}

			Ship* newShip = new Ship(position, shipName);
			this->shipList.push_back(newShip);
			cout << "Ship added" << endl;
			//Add ship to shipGrid
			for (vector<Cell*> vect : this->shipGrid.getCells()) {
				for (Cell* gridCell : vect) {
					for (Cell* ptrC : position) {
						if (ptrC->getX() == gridCell->getX() && ptrC->getY() == gridCell->getY()) {
							gridCell->setOccupant(newShip);
							cout << "occupant changed" << endl;
						}
					}
				}
			}
			//Add ship to attackGrid
			for (vector<Cell*> vect : this->attackGrid.getCells()) {
				for (Cell* gridCell : vect) {
					for (Cell* ptrC : position) {
						if (ptrC->getX() == gridCell->getX() && ptrC->getY() == gridCell->getY()) {
							gridCell->setOccupant(newShip);
						}
					}
				}
			}
		}
	}
}

Player* Player::playTurn(const char& row, const char& col) {
	//Asking confirmation from the player to start his turn
	cout << "It's " << this->name << "'s turn. Press Enter to start your turn." << endl;
	cin;

	//Display the player's grid and the opponent's last attack
	cout << "This is your grid." << endl;
	if (row != '_') {
		cout << "Your opponent attacked " << row << (int)col << " on his last turn" << endl;
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
