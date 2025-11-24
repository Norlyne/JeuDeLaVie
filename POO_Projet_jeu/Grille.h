#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "cell.h"

class Grille {
private:
    int gridWidth = 100;
	int gridHeight = 100;
public:
	// constructor
	Grille() {
		gridWidth = 100;
		gridHeight = 100;
		std::vector<std::vector <cell*>> grid(gridWidth, std::vector<cell*>(gridHeight));

	}

	Grille(int w, int h) {
		gridWidth = w;
		gridHeight = h;
		std::vector<std::vector <cell*>> grid(gridWidth, std::vector<cell*>(gridHeight));

	}

	Grille(Grille& g) {
		gridWidth = g.gridWidth;
		gridHeight = g.gridHeight;
		std::vector<std::vector <cell*>> grid(gridWidth, std::vector<cell*>(gridHeight));

	}

	// getter
	int get_height();
	int get_widht();

	//setter
	void set_height(int h);
	void set_width(int w);

};
