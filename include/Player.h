#include "Ship.h"
#include "Grid.h"
#include <vector>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Grid.h"

using namespace std;

class Player {
	friend class Grid;
	Grid shipGrid;
	Grid attackGrid;
	vector<Ship*> shipList;

private:
	string name;
	Grid shipGrid;
	Grid attackGrid;
	vector<Ship*> shipList;
	Player* opponent;

public:
	void initShips();
	vector<int> toIntCoord(string coord);
	bool hasLost();
	Player* playTurn(const char& row = '_', const char& col = '_');
};