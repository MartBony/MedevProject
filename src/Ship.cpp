#include "Ship.h"

Ship::Ship(const vector<Cell*>& position, const string& type) {
    this->setPosition(position);
    this->setType(type);
}

vector<Cell*> Ship::getPosition() const { 
    return this->position; 
};

void Ship::setPosition(const vector<Cell*>& position) {
    this->position = position; 
};

string Ship::getType() const { return this->type; };
void Ship::setType(const string& type) { this->type = type; };