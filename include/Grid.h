#pragma once 
#include "Cell.h"
#include <string>
#include <vector>

using namespace std;

/**
 * @class Grid
 * @brief Class representing a grid that contains ships, placed on cells.
 */
class Grid {
private:
	vector<vector<Cell*>> cells;
	/**
	 * @brief Represents whether the user can see the ships on the grid when displaying it.
	 * 
	 * Useful to create a grid of previous attacks on the opponent and the hits and misses, without disclosing the ships of teh opponent.
	 */
	bool hidden;

public:
	Grid(const bool& hidden);

	void display() const;
	/**
	 * @brief Allows you to flip the state of a Cell at gicen coordinates to a hit ot miss.
	 * @param x Row of the targeted cell
	 * @param y Column of teh targeted cell 
	 */
	void attack(const int x, const int y);
};