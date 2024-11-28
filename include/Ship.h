#pragma once

#include <vector>
#include <string>

using namespace std;

class Cell;

class Ship{
    vector<Cell*> position;
    string type;
    public:
        
        Ship(const vector<Cell*>& position, const string& type);
        

        // Getters and setters
        vector<Cell*> getPosition() const;
        void setPosition(const vector<Cell*> &position);

        string getType() const;
        void setType(const string &type);

};