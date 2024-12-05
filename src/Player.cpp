#include "Player.h"

using namespace std;

Player* Player::playTurn(const char& row = '_', const char& col = '_') {
	//Asking confirmation from the player to start his turn
	cout << "It's " << this->name << "'s turn. Press Enter to start your turn." << endl;
	cin;

	//Display the player's grid and the opponent's last attack
	cout << "This is your grid." << endl;
	if (row != '_') {
		cout << "Your opponent attacked " << row << col << " on his last turn" << endl;
	}
	this->shipGrid.display();

	//Display the player's attack grid
	cout << "This is the grid of your previous attacks:" << endl;
	this->attackGrid.display();

	// Ask the player for a cell to attack
	map<char, int> rowMap = { {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}};
	char attackRow = '_';
	int attackCol = -1;
	while (!rowMap.count(attackRow)) {
		cout << "Enter a row to attack (Letter between A and J)" << endl;
		cin >> attackRow; 
	}
	while (attackCol < 1 || attackCol > 10) {
		cout << "Enter a column to attack (Integer between 1 and 10)" << endl;
		cin >> attackCol;
	}
	attackCol--;

	//Update the grids
	this->attackGrid.attack(rowMap[attackRow], attackCol);
	this->opponent->shipGrid.attack(rowMap[attackRow], attackCol);

	if (!opponent->hasLost()) {
		//Start other player's turn
		return this->opponent->playTurn(attackRow, (char)attackCol);
	}
	else {
		//Return the winner of the game
		return this;
	}
}

bool Player::hasLost() {
	for (auto& ship : shipList) {
		if (ship->getAlive()) {
			return false; 
		}
	}
	return true; 
}