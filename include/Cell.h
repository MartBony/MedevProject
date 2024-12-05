#pragma once 
#include "Ship.h"

using namespace std;

class Ship;

/**
 * @class Cell
 * @brief Class representing a cell from the grid.
 * 
 * A cell contains a subpart of a ship and has a state depending on the player's action.
 */
class Cell {
private : 
	int x; 
	int y; 
	Ship* occupant;
	/**
	 * @brief State of the cell
	 * 
	 * N for notHit or M for missedHit or T for touchedHit X for deadShip.
	 */
	char state = 'N';
	


public : 
	// Choices for state
	const char notHitState = 'N';
	const char missedHitState = 'M';
	const char touchedHitState = 'T';
	const char deadShipState = 'X';

	//constructor 
	Cell(int x, int y);

	//getters and setters 
	int getX() const;
	int getY() const;
	Ship* getOccupant() const;
	char getState() const;
	void setX(const int& x);
	void setY(const int& y);
	void setOccupant(Ship* occupant);
	void setState(const char& state);
};