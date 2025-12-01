#include "patternes.h"
#include "grille.h"


//constructor
pattern::pattern() {
	this->x = 0;
	this->y = 0;
	this->x2 = 0;
	this->y2 = 0;
	this->numero = 1;
}

pattern::pattern(int x, int y, int numero) {
	this->x = x;
	this->y = y;
	this->x2 = this->x / 10;
	this->y2 = this->x / 10;
	this->numero = 1;
}


//getters
int pattern::get_x() { return x; }
int pattern::get_y() { return y; }
int pattern::get_x2() { return x2; }
int pattern::get_y2() { return y2; }
int pattern::get_numero() { return numero; }


//setters
void pattern::set_x(int x) { this->x = x; }
void pattern::set_y(int y) { this->y = y; }
void pattern::set_x2(int x2) { this->x2 = x2; }
void pattern::set_y2(int y2) { this->y2 = y2; }
void pattern::set_numero(int numero) { this->numero = numero; }


void pattern::poser_point(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	grid2.set_grille(x2, y2, 1);
}


void pattern::poser_stable1(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	grid2.set_grille(x2, y2, 1);
	grid2.set_grille(x2, y2+1, 1);
	grid2.set_grille(x2+1, y2, 1);
	grid2.set_grille(x2+1, y2+1, 1);
}

void pattern::poser_stable2(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	grid2.set_grille(x2, y2 + 1, 1);
	grid2.set_grille(x2 + 1, y2 + 1, 1);
	grid2.set_grille(x2, y2 - 1, 1);
	grid2.set_grille(x2 + 1, y2 - 1, 1);
	grid2.set_grille(x2 - 1, y2, 1);
	grid2.set_grille(x2 + 2, y2, 1);
}

void pattern::poser_glider(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	grid2.set_grille(x2, y2 + 1, 1);
	grid2.set_grille(x2 + 1, y2, 1);
	grid2.set_grille(x2, y2 - 1, 1);
	grid2.set_grille(x2 - 1, y2 - 1, 1);
	grid2.set_grille(x2 + 1, y2 - 1, 1);
}

void pattern::poser_oscillateur1(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	grid2.set_grille(x2, y2, 1);
	grid2.set_grille(x2 + 1, y2, 1);
	grid2.set_grille(x2 - 1, y2, 1);
}

void pattern::poser_oscillateur2(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	grid2.set_grille(x2, y2, 1);
	grid2.set_grille(x2, y2 + 1, 1);
	grid2.set_grille(x2 + 1, y2, 1);
	grid2.set_grille(x2 + 1, y2 + 1, 1);
	grid2.set_grille(x2 - 1, y2, 1);
	grid2.set_grille(x2 + 2, y2 + 1, 1);
}

void pattern::poser_canon_glider(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;

	// ---- Gosper Glider Gun ----

	// Bloc de gauche
	grid2.set_grille(x2 + 1, y2 + 5, 1);
	grid2.set_grille(x2 + 1, y2 + 6, 1);
	grid2.set_grille(x2 + 2, y2 + 5, 1);
	grid2.set_grille(x2 + 2, y2 + 6, 1);

	// Canon central gauche
	grid2.set_grille(x2 + 11, y2 + 5, 1);
	grid2.set_grille(x2 + 11, y2 + 6, 1);
	grid2.set_grille(x2 + 11, y2 + 7, 1);

	grid2.set_grille(x2 + 12, y2 + 4, 1);
	grid2.set_grille(x2 + 12, y2 + 8, 1);

	grid2.set_grille(x2 + 13, y2 + 3, 1);
	grid2.set_grille(x2 + 13, y2 + 9, 1);

	grid2.set_grille(x2 + 14, y2 + 3, 1);
	grid2.set_grille(x2 + 14, y2 + 9, 1);

	grid2.set_grille(x2 + 15, y2 + 6, 1);

	grid2.set_grille(x2 + 16, y2 + 4, 1);
	grid2.set_grille(x2 + 16, y2 + 8, 1);

	grid2.set_grille(x2 + 17, y2 + 5, 1);
	grid2.set_grille(x2 + 17, y2 + 6, 1);
	grid2.set_grille(x2 + 17, y2 + 7, 1);

	grid2.set_grille(x2 + 18, y2 + 6, 1);

	// Partie droite (3×2 blocs)
	grid2.set_grille(x2 + 21, y2 + 3, 1);
	grid2.set_grille(x2 + 21, y2 + 4, 1);
	grid2.set_grille(x2 + 21, y2 + 5, 1);

	grid2.set_grille(x2 + 22, y2 + 3, 1);
	grid2.set_grille(x2 + 22, y2 + 4, 1);
	grid2.set_grille(x2 + 22, y2 + 5, 1);

	grid2.set_grille(x2 + 23, y2 + 2, 1);
	grid2.set_grille(x2 + 23, y2 + 6, 1);

	grid2.set_grille(x2 + 25, y2 + 1, 1);
	grid2.set_grille(x2 + 25, y2 + 2, 1);
	grid2.set_grille(x2 + 25, y2 + 6, 1);
	grid2.set_grille(x2 + 25, y2 + 7, 1);

	// Petit bloc le plus à droite
	grid2.set_grille(x2 + 35, y2 + 3, 1);
	grid2.set_grille(x2 + 35, y2 + 4, 1);
	grid2.set_grille(x2 + 36, y2 + 3, 1);
	grid2.set_grille(x2 + 36, y2 + 4, 1);
}

void pattern::poser_obstacle(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	int x2 = x / 10;
	int y2 = y / 10;
	grid2.set_grille(x2, y2, 2);
}

void pattern::poser_pattern(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window) {
	if (this->numero == 1) { poser_point(x, y, grid, grid2, window); }
	if (this->numero == 2) { poser_stable1(x, y, grid, grid2, window); }
	if (this->numero == 3) { poser_stable2(x, y, grid, grid2, window); }
	if (this->numero == 4) { poser_glider(x, y, grid, grid2, window); }
	if (this->numero == 5) { poser_oscillateur1(x, y, grid, grid2, window); }
	if (this->numero == 6) { poser_oscillateur2(x, y, grid, grid2, window); }
	if (this->numero == 7) { poser_canon_glider(x, y, grid, grid2, window); }
	if (this->numero == 0) { poser_obstacle(x, y, grid, grid2, window); }

}

void pattern::random(grille& grid, grille& grid2, sf::RenderWindow& window) {
		grid.random_init();
		grid2.random_init();
}

void pattern::random_obs(grille& grid, grille& grid2, sf::RenderWindow& window) {
	grid.random_init_obs();
	grid2.random_init_obs();
}

void pattern::reset(grille& grid, grille& grid2, sf::RenderWindow& window) {
	grid.fichier_init("vide.txt");
	grid2.fichier_init("vide.txt");
}












