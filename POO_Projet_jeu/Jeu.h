
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Grille.h"
#include "cell.h"

class Jeu {
private:
	Grille* grille;
public:
	// constructeur
	Jeu(){
		grille = new Grille();
	}

	Jeu(Grille& g) {
		grille = &g;
	}

	// method
	void initializeGrid();
	int countvoisin(int x, int y);
	void reglebase();


};
