#include "Grille.h"

// getter

int Grille::get_size() {
	return cellSize;
}

int Grille::get_height() {
	return gridHeight;
}

int Grille::get_widht() {
	return gridWidth;
}

// setter
void Grille::set_size(int s) {
	cellSize = s;
}

void Grille::set_height(int h) {
	gridHeight = h;
}

void Grille::set_width(int w) {
	gridWidth = w;
}

// method 
void Grille::initializeGrid() {
	std::vector<std::vector <cell>> grid(gridWidth, std::vector<cell>(gridHeight));

	std::srand(std::time(0));
	for (int x = 0; x < gridWidth; ++x) {
		for (int y = 0; y < gridHeight; ++y) {
			grid[x][y] = std::rand() % 2;  // Randomly initialize cells as alive or dead
		}
	}
};
