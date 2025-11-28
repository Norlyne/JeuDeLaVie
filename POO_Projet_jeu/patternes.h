#pragma once
#include "grille.h"


class pattern
{
private:
	int numero;
	int x;
	int y;


public:
	//contructor
	pattern();
	pattern(int x, int y, int numero);


	//getters
	int get_x();
	int get_y();
	int get_numero();

	//setters
	void set_x(int x);
	void set_y(int y);
	void set_numero(int numero);


	//methodes
	void selection_pattern(int numero);

	void poser_point(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);
	void poser_carre(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);
	void poser_glider(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);


	void poser_pattern(int x, int y, grille &grid, grille &grid2, RenderWindow &window);
	
	void random(grille& grid, grille& grid2, sf::RenderWindow& window);
	void reset(grille& grid, grille& grid2, sf::RenderWindow& window);
};


