#pragma once 

using namespace std;

class Ship;

class Cell {
private : 
	int x; 
	int y; 
	Ship* occupant;
	char state; //N for notHit or M for missedHit or T for touchedHit

public : 
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