#pragma once 
#include "Ship.h"
#include <string> 

using namespace std;

class Cell {
private : 
	int x; 
	int y; 
	Ship* occupant;
	bool hit;
	string state; //notHit or missedHit or touchedHit

public : 
	//constructor 
	Cell(int x, int y) : x(x), y(y), occupant(nullptr), hit(false), state("notHit") {};

	//getters and setters 
	int getX() const { return this->x; }
	int getY() const { return this->y; }
	Ship* getOccupant() const { return this->occupant; }
	bool getHit() const { return this->hit; }
	string getState() const { return this->state; }
	void setX(const int& x) { this->x = x; }
	void setY(const int& y) { this->y = y; }
	void setOccupant(Ship* occupant) { this->occupant = occupant;}
	void setHit(const bool& hit) { this->hit = hit; }
	void setState(const string& state) { this->state = state; }
};