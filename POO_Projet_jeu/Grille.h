#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
// #include "cell.h"

class Grille {
private:
	int cellSize = 9;
    int gridWidth = 100;
	int gridHeight = 100;
public:
	// constructor
	Grille() {
		cellSize = 10;
		gridWidth = 100;
		gridHeight = 100;
	}

	Grille(int w, int h) {
		cellSize = 10;
		gridWidth = w;
		gridHeight = h;
	}

	Grille(int s, int w, int h) {
		cellSize = s;
		gridWidth = w;
		gridHeight = h;
	}

	Grille(Grille& g) {
		cellSize = g.cellSize;
		gridWidth = g.gridWidth;
		gridHeight = g.gridHeight;
	}

	// getter
	int get_size();
	int get_height();
	int get_widht();

	//setter
	void set_size(int s);
	void set_height(int h);
	void set_width(int w);

	// method
	void initializeGrid();
};

