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


bool Ship::isAlive(){
    //Tests if a ship is alive after beeing hit, changes the state of all its cells if it's not alive anymore. 
    if(this->alive){
        for(Cell* cell : this->position){
            if(cell->getState() == cell->notHitState) return true;
        }
        this->alive = false;
        for (Cell* cell : this->position) {
            cell->setState('X');
        }
        return false;
    } else return false;
}