// MedevProject.cpp : définit le point d'entrée de l'application.
//
#include <iostream>

#include "Player.h"
using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	Player* player1 = new Player("Theo");
	Player* player2 = new Player("Yvan");
	player1->setOpponent(player2);
	player2->setOpponent(player1);

	player1->initShips();
	player2->initShips();

	Player* winner = player1->playTurn();

	//cout << "Player " << winner->name << " has won!" << endl;

	delete player1;
	delete player2;
	return 0;
}
