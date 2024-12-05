#include "Ship.h"
#include "Grid.h"
#include <vector>
#include <iostream>

using namespace std;

class Player {
	friend class Grid;
	Grid shipGrid;
	Grid attackGrid;
	vector<Ship*> shipList;

public:

	void initShips();
};