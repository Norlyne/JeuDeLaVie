#include "cell.h"

//COnstructors
cell::cell() {
	this->state = false;
}

cell::cell(bool state) {
	this->state = state;
}

dead_cell::dead_cell(sf::RenderWindow& window, int x, int y, int cellSize) {
	this->state = false;
	this->cellSize = cellSize;
	dessiner(window, x, y);
}

live_cell::live_cell(sf::RenderWindow& window, int x, int y, int cellSize) {
	this->state = true;
	this->cellSize = cellSize;
	dessiner(window, x, y);
}

//getters
bool cell::get_state() { return this->state; }
int cell::get_cellSize() { return this->cellSize; }
 
//setters
void cell::set_state(bool state) { this->state = state; }
void cell::set_cellSize(int cellSize) { this->cellSize = cellSize; }

