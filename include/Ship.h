#pragma once

#include <vector>
#include <string>

#include "Cell.h"

using namespace std;

class Cell;

/**
 * @class Ship
 * @brief Class representing a ship.
 */
class Ship{
    /**
     * @brief The ship's position is the list (vector) of cells it occupies.
     */
    vector<Cell*> position;
    string type;
    /**
     * @brief Internal variable meant to decrease the number of operations of the isAlive function.
     * Prefer sing the isAlive function to get the alive state of the ship which will recalculate the state.
     */
    bool alive = true;
    public:
        
        Ship(const vector<Cell*>& position, const string& type);
        

        // Getters and setters
        vector<Cell*> getPosition() const;
        void setPosition(const vector<Cell*> &position);

        string getType() const;
        void setType(const string &type);

        /**
         * @brief Returns whether the ship still floats, ie whether it occupies at least one unattacked cell.
         * @return State of the ship.
         */
        bool isAlive();

};