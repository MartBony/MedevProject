// MedevProject.cpp : définit le point d'entrée de l'application.
//
#include <iostream>
#include "Grid.h"
using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	Player* player1 = new Player(opponent=player2);
	Player* player2 = new Player(opponent=player1);

	player1->initShips();
	player2->initShips();

	Player* winner = player1.playTurn();



	delete player1;
	delete player2;
	return 0;
}
