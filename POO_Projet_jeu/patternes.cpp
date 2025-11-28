#include "patternes.h"
#include "grille.h"


//constructor
pattern::pattern() {
	this->x = 0;
	this->y = 0;
	this->numero = 1;
}

pattern::pattern(int x, int y, int numero) {
	this->x = x;
	this->y = y;
	this->numero = 1;
}


//getters
int pattern::get_x() { return x; }
int pattern::get_y() { return y; }
int pattern::get_numero() { return numero; }


//setters
void pattern::set_x(int x) { this->x = x; }
void pattern::set_y(int y) { this->y = y; }
void pattern::set_numero(int numero) { this->numero = numero; }


void pattern::poser_point(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	cout << numero << "   " << x2 << "   " << y2 << endl;

	grid2.set_grille(x2, y2, 1);
}


void pattern::poser_carre(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	cout << numero << "   " << x2 << "   " << y2 << endl;

	grid2.set_grille(x2, y2, 1);
	grid2.set_grille(x2, y2+1, 1);
	grid2.set_grille(x2+1, y2, 1);
	grid2.set_grille(x2+1, y2+1, 1);
}

void pattern::poser_glider(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	cout << "glider" << numero << "   " << x2 << "   " << y2 << endl;

	grid2.set_grille(x2, y2 + 1, 1);
	grid2.set_grille(x2 + 1, y2, 1);
	grid2.set_grille(x2, y2 - 1, 1);
	grid2.set_grille(x2 - 1, y2 - 1, 1);
	grid2.set_grille(x2 + 1, y2 - 1, 1);
}

void pattern::poser_pattern(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	if (this->numero == 1) { poser_point(x, y, grid, grid2, window); }
	if (this->numero == 2) { poser_carre(x, y, grid, grid2, window); }
	if (this->numero == 3) { poser_glider(x, y, grid, grid2, window); }
}

void pattern::ramdom(string mode, grille& grid, grille& grid2, sf::RenderWindow& window) {
	if (mode == "1") {
		grid.random_init();
		grid2.random_init();
	}
	else if (mode == "2") {
		grid.random_init();
		grid2.random_init();
	}
	else if (mode == "3") {
		grid.random_init();
		grid2.random_init();
	}
	else if (mode == "4") {
		grid.random_init();
		grid2.random_init();
	}
	else if (mode == "5") {
		grid.random_init();
		grid2.random_init();
	}
	else if (mode == "6") {
		grid.random_init();
		grid2.random_init();
	}
}









