#include "Grid.h"

using namespace std;
Grid::Grid() {
	for (int x = 0; x <= 9; x++) {
		vector<Cell*> row = {};
		for (int y = 0; y <= 9; y++) {
			Cell* cell = new Cell(x, y);
			row.push_back(cell);
		}
		this->cells.push_back(row);
	}
}

void Grid::display() const{
	for (auto& row : this->cells) {
		cout << "|";
		for (auto& cell : row) {
			if (this->hidden) {
				switch (cell->getState()) {
				case 'N':
					cout << '~';
					break;
				case 'M':
					cout << 'O';
					break;
				case 'T':
					cout << 'X';
					break;
				default:
					cout << '?';
					break;
				}
			}
			else {
				if (cell->getOccupant() == nullptr) { //Case sans bateau
					if (cell->getState() == 'M') { //Attaquée mais ratée
						cout << 'O';
					}
					else { //Pas attaquée
						cout << '~';
					}
				}
				else { //Case avec bateau
					if (cell->getState() == 'T') { //Attaquée et touchée
						cout << 'X';
					}
					else { //Pas attaquée
						cout << 'B';
					}
				}
			}
		}
		cout << "|" << endl;
	}
}

void Grid::attack(const int x, const int y) {

}