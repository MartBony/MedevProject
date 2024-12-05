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

public:

	void initShips();
private:
	string name;
	Grid shipGrid;
	Grid attackGrid;
	vector<Ship*> shipList;
	Player* opponent;

public:
	void initShips();
	bool hasLost();
	Player* playTurn(const char& row = '_', const char& col = '_');
};