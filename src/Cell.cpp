#include "Cell.h"
Cell::Cell(int x, int y) : x(x), y(y), occupant(nullptr), state('N') {};

//getters and setters 
int Cell::getX() const { return this->x; }
int Cell::getY() const { return this->y; }
Ship* Cell::getOccupant() const { return this->occupant; }
char Cell::getState() const { return this->state; }
void Cell::setX(const int& x) { this->x = x; }
void Cell::setY(const int& y) { this->y = y; }
void Cell::setOccupant(Ship* occupant) { this->occupant = occupant; }
void Cell::setState(const char& state) { this->state = state; }