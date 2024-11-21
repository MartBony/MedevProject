#pragma once 
#include "ship/ship.h" 

using namespace std;

class Cell {
private : 
	int x; 
	int y; 
	Ship* occupant;
	bool hit;
	char state; //N for notHit or M for missedHit or T for touchedHit

public : 
	//constructor 
	Cell(int x, int y) : x(x), y(y), occupant(nullptr), hit(false), state('N') {};

	//getters and setters 
	int getX() const { return this->x; }
	int getY() const { return this->y; }
	Ship* getOccupant() const { return this->occupant; }
	bool getHit() const { return this->hit; }
	char getState() const { return this->state; }
	void setX(const int& x) { this->x = x; }
	void setY(const int& y) { this->y = y; }
	void setOccupant(Ship* occupant) { this->occupant = occupant;}
	void setHit(const bool& hit) { this->hit = hit; }
	void setState(const char& state) { this->state = state; }
};