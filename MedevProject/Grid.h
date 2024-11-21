#pragma once 
#include <iostream>
#include "Cell.h"
#include <string>
#include <vector>

using namespace std;

class Grid {
private:
	vector<vector<Cell*>> cells;
	bool hidden;

public:
	Grid();

	void display() const;
	void attack(const int x, const int y);
};