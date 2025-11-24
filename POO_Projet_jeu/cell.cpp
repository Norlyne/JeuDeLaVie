#include "cell.h"

//COnstructors
cell::cell() {
	this->x = 0;
	this->y = 0;
	this->state = false;
}

cell::cell(int x, int y, bool state) {
	this->x = x;
	this->y = y;
	this->state = state;
}

dead_cell::dead_cell() {
	this->x = 0;
	this->y = 0;
	this->state = false;
}

live_cell::live_cell() {
	this->x = 0;
	this->y = 0;
	this->state = false;
}

//getters
int cell::getx() { return this->x; }
int cell::gety() { return this->y; }
bool cell::get_state() { return this->state;  }

//setters
void cell::setx(int x) { this->x = x; }
void cell::sety(int y) { this->y = y; }
void cell::set_state(bool state) { this->state = state; }
