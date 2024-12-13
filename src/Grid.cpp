#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(const bool& hidden) : hidden(hidden) {
	for (int x = 0; x <= 9; x++) {
		vector<Cell*> row = {};
		for (int y = 0; y <= 9; y++) {
			Cell* cell = new Cell(x, y);
			row.push_back(cell);
		}
		this->cells.push_back(row);
	}
}

vector<vector<Cell*>> Grid::getCells() const {
	return this->cells;
}

void Grid::display() const {
	cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
	vector<char> letters = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	for (int i = 0; i < cells.size(); i++) {
		cout << letters[i];
		cout << "| ";
		vector<Cell*> row = this->cells[i];
		for (auto& cell : row) {
			if (this->hidden) {
				switch (cell->getState()) {
				case 'N':
					cout << "~ ";
					break;
				case 'M':
					cout << "O ";
					break;
				case 'T':
					cout << "T ";
					break;
				case 'X':
					cout << "X ";
					break;
				default:
					cout << " ? ";
					break;
				}
			}
			else {
				if (cell->getOccupant() == nullptr) { //Case sans bateau
					if (cell->getState() == 'M') { //Attaquee mais ratee
						cout << "O ";
					}
					else { //Pas attaquee
						cout << "~ ";
					}
				}
				else { //Case avec bateau
					switch (cell->getState()) {
					case 'T': //Attaquee et touchee
						cout << "T ";
						break;
					case 'X' :
						cout << "X ";
						break;
					default : //Pas attaquee
						cout << "B ";
						break;
					}
				}
			}
		}
		cout << "|" << endl;
	}
}

void Grid::attack(const int x, const int y) {
	//This method retrieves the attacked cell and changes its state
	//If a ship is hit, it calls the isAlive() method of the hit ship
	Cell* targetCell = this->cells[x][y];
	if(targetCell->getOccupant()){
		targetCell->setState(targetCell->touchedHitState);
		(targetCell->getOccupant())->isAlive();
	} else {
		targetCell->setState(targetCell->missedHitState);
	}

}