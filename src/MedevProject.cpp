// MedevProject.cpp : définit le point d'entrée de l'application.
//
#include <iostream>
#include "Grid.h"
using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	Grid* grid = new Grid(true);
	grid->display();
	return 0;
}
