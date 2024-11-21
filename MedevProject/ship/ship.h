#pragma once
#include <vector>
#include "../Cell.h"
#include <string>

using namespace std;

class Ship{
    vector<Cell*> position;
    string type;
    public:

        Ship(const vector<Cell*> &position, const string &type){
            this->setPosition(position);
            this->setType(type);
        }

        // Getters and setters
        vector<Cell*> getPosition() const {return this->position;};
        void setPosition(const vector<Cell*> &position) {this->position = position;};

        string getType() const {return this->type;};
        void setType(const string &type){this->type = type;};

};