#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <bitset>
#include "Grille.h"
#include "cell.h"

class Jeu{
private:
	Grille *grille;
public:
	// constructeur
	Jeu() {
		grille = new Grille();
	}
	// method
	void initializeGrid();
	int countvoisin(int x, int y);
	void reglebase();


};

