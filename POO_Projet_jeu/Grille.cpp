#include "Grille.h"

// getter

int Grille::get_height() {
	return gridHeight;
}

int Grille::get_widht() {
	return gridWidth;
}

// setter

void Grille::set_height(int h) {
	gridHeight = h;
}

void Grille::set_width(int w) {
	gridWidth = w;
}