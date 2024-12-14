#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(const string& name) : name(name), shipGrid(new Grid(false)), attackGrid(new Grid(true)) {}

void Player::setOpponent(Player* opponent) {
	this->opponent = opponent;
}

vector<int> Player::toIntCoord(string coord) {
	vector<int> IntCoord;
	int x = static_cast<int>(coord.at(0)) - 65; //The ASCII code of 'A' is 65, 'B' is 66, etc.
	int y = coord.size() == 2 ? (int)(coord.at(1)) - 49 : 9; // If the user typed 10, the string will be of size 3 > 2 
	IntCoord.push_back(x);
	IntCoord.push_back(y);
	return IntCoord;
}

bool inBounds(const int& testInt){
	return testInt >= 0 && testInt <= 9;
}

void Player::initShips() {

	vector<vector<int>> fleet{ {1,5},{1,4},{1,3},{2,2},{2,1} }; //vect<vect < number of ships of that length, length of a ship > >

	for (vector<int> shipType : fleet) {
		size_t NbOfShips = shipType.at(0);
		size_t shipLength = shipType.at(1);
		string shipName{};
		switch (shipLength) { //attribution of the name of the ship depending on their length
		case 5:
			shipName = "battleship (5 cells)";
			break;
		case 4:
			shipName = "cruiser (4 cells)";
			break;
		case 3:
			shipName = "destroyer (3 cells)";
			break;
		case 2:
			shipName = "submarine (2 cells)";
			break;
		case 1:
			shipName = "fishing boat (1 cell)";
			break;
		}

		for (size_t shipIndex = 0; shipIndex < NbOfShips; shipIndex++) { //we iterate on the number of ships of a given type
			vector<Cell*> position{};

			this->shipGrid.display(); //we display the shipGrid

			string coord;
			int x = -1;
			int y = -1;
			bool cellOccupied = false;
			do {
				cout << "Enter starting coordinates for the  " << shipName << " number " << shipIndex << " (letter btwn A and J + number btwn 1 and 10) : ";
				cin >> coord;
				vector<int> IntCoord = toIntCoord(coord);
				x = IntCoord.at(0);
				y = IntCoord.at(1);
				cellOccupied = (this->shipGrid.cells.at(x).at(y)->getOccupant() != nullptr);
				if (cellOccupied)
					cout << "\nCell already occupied, please try again" << endl;
			} while (cellOccupied);
			cout << "x :" << x << endl;;
			cout << "y :" << y << endl;
			position.push_back(shipGrid.cells[x][y]);


			vector<char> possibleOrientations{ 'D','U','R','L' }; //D=Down, U=Up, R=Right, L=Left
			if (shipLength > 1) { //if the ship occupies more than the starting cell
				if (shipLength - 1 <= x) { //we verify that there is space for the cells to be put to the left
					for (size_t i = 1; i <= shipLength - 1; i++) {
						if (this->shipGrid.cells.at(x - i).at(y)->getOccupant() != nullptr)
							possibleOrientations.erase(possibleOrientations.begin()+3);
					}
				}
				else {
					possibleOrientations.erase(possibleOrientations.begin() + 3);
				}

				if (shipLength - 1 <= 9 - x) { //we verify that there is space for the cells to be put to the right
					for (size_t i = 1; i <= shipLength - 1; i++) {
						if (this->shipGrid.cells.at(x + i).at(y)->getOccupant() != nullptr)
							possibleOrientations.erase(possibleOrientations.begin() + 2);
					}
				}
				else {
					possibleOrientations.erase(possibleOrientations.begin() + 2);
				}

				if (shipLength - 1 <= y) { //we verify that there is space for the cells to be put up
					for (size_t i = 1; i <= shipLength - 1; i++) {
						if (this->shipGrid.cells.at(x).at(y - i)->getOccupant() != nullptr)
							possibleOrientations.erase(possibleOrientations.begin() + 1);
					}
				}
				else {
					possibleOrientations.erase(possibleOrientations.begin() + 1);
				}

				if (shipLength - 1 <= 9 - y) { //we verify that there is space for the cells to be put down
					for (size_t i = 1; i <= shipLength - 1; i++) {
						if (this->shipGrid.cells.at(x).at(y + i)->getOccupant() != nullptr)
							possibleOrientations.erase(possibleOrientations.begin());
					}
				}
				else {
					possibleOrientations.erase(possibleOrientations.begin());
				}

			}
			bool wrongOrientation = false;
			do {
				cout << "Here are the possible orientations for your ship : " << endl;
				for (char letter : possibleOrientations) {
					cout << letter << " ";
				}
				cout << "\nUp (U), Down (D), Left (L), Right (R)" << endl;
				cout << "Select an orientation (1 letter) : ";
				char orientation;
				cin >> orientation;

				switch (orientation) {
				case 'u':
				case'U':
					for (size_t i = 0; i < shipLength - 1; i++) {
						position.push_back(shipGrid.cells[x][y - i]);
					}
					break;
				case 'd':
				case'D':
					for (size_t i = 0; i < shipLength - 1; i++) {
						position.push_back(shipGrid.cells[x][y + i]);
					}
					break;
				case 'r':
				case'R':
					for (size_t i = 0; i < shipLength - 1; i++) {
						position.push_back(shipGrid.cells[x + i][y]);
					}
					break;
				case 'l':
				case'L':
					for (size_t i = 0; i < shipLength - 1; i++) {
						position.push_back(shipGrid.cells[x - i][y]);
					}
					break;
				default:
					cout << "Wrong orientation, please try again" << endl;
					wrongOrientation = true;
				}

			} while (wrongOrientation);

			Ship newShip(position, shipName);
			for (Cell* ptrC : position) {
				ptrC->setOccupant(&newShip);
			}
			this->shipList.push_back(&newShip);
		}
	}
}

/*
			if 
			for (size_t cellIndex = 0; cellIndex < shipLength; cellIndex++) { //we iterate on the number of cells in a ship of that type

				this->shipGrid.display() //we display the shipGrid

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

			Ship newShip(position, shipName);
			for (Cell* ptrC : position) {
				ptrC->setOccupant(&newShip);
			}
			this->shipList.push_back(&newShip);
		}
	}
}

*/

Player* Player::playTurn(const char& row, const char& col) {
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
