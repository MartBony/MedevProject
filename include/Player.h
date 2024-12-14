#include "Ship.h"
#include "Grid.h"
#include <vector>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Grid.h"

using namespace std;


/**
 * @class Player
 * @brief CLasse représentant un joueur dans le jeu.
 * 
 * Cette classe permet d'initier un joueur et ses grilles, puis de jouer à travers le terminal. 
 * Elle ne peut pas exister seule et nécessite un autre joueur omme adversaire.
 */
class Player {
	friend class Grid;

private:
	string name;
	
	/**
	 * @brief Grille du joueur avec ses propres bateaux.
	 */
	Grid shipGrid;

	/**
	 * @brief Grid of the previous attacks from that player. Contains the information from the opponent's ships in a hidden way.
	 */
	Grid attackGrid;
	/**
	 * @brief List of ships from that player.
	 */
	vector<Ship*> shipList;
	Player* opponent;

public:
	/**
	 * @brief Asks the user to initialise his own grid with a range of boat types.
	 */

	void setOpponent(Player* opponent);

	void initShips();
	vector<int> toIntCoord(string coord);

	/**
	 * @brief Auxilary function that tests if a position is adjacent and aligned to the previous cells (for ship placement)
	 * @param x X coordinate of the cell the player wants to input
	 * @param y Y coordinate of the cell the player wants to input
	 * @return True or False
	 */
	bool isAdjacentAndAligned(const int& x, const int& y, const vector<Cell*> shipCells) const;

	Player(const string& name);
	
	string getName() const;
	/**
	 * @brief Returns whether the user lost, ie whether all of his boats sank.
	 * @return Boolan representing whether the user lost.
	 */
	bool hasLost();

	/**
	 * @brief Plays the game, starting on this player's side, and then recursively finishing the game by switching to the opponent,
	 * until the game ends.
	 * @param row Row of the previous attack, only used to inform the user of the opponent's move.
	 * @param col Col of the previous attack in a similar fashion to row parameter.
	 * @return Pointer to the winning player.
	 */
	Player* playTurn(const char& row = '_', const char& col = '_');
};