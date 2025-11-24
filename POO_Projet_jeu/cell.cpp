#include "cell.h"
#include "Grille.h"

//COnstructors
cell::cell() {
	this->state = false;
}

cell::cell(bool state) {
	this->state = state;
}

dead_cell::dead_cell(sf::RenderWindow& window, int x, int y) {
	this->state = false;
	dessiner(window, x, y);
}

live_cell::live_cell(sf::RenderWindow& window, int x, int y) {
	this->state = true;
	dessiner(window, x, y);
}

//getters
bool cell::get_state() { return this->state; }
 
//setters
void cell::set_state(bool state) { this->state = state; }

