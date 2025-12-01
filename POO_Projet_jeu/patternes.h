#pragma once
#include "grille.h"


class pattern
{
private:
	int numero;
	int x;
	int y;
	int x2;
	int y2;


public:
	//contructor
	pattern();
	pattern(int x, int y, int numero);


	//getters
	int get_x();
	int get_y();
	int get_x2();
	int get_y2();
	int get_numero();

	//setters
	void set_x(int x);
	void set_y(int y);
	void set_x2(int x2);
	void set_y2(int y2);
	void set_numero(int numero);


	//methodes

	void poser_point(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);
	void poser_stable1(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);
	void poser_stable2(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);
	void poser_glider(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);
	void poser_oscillateur1(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);
	void poser_oscillateur2(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);
	void poser_canon_glider(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);
	void poser_obstacle(int x, int y, grille& grid, grille& grid2, sf::RenderWindow& window);

	void poser_pattern(int x, int y, grille &grid, grille &grid2, RenderWindow &window);
	
	void random(grille& grid, grille& grid2, sf::RenderWindow& window);
	void random_obs(grille& grid, grille& grid2, sf::RenderWindow& window);
	void reset(grille& grid, grille& grid2, sf::RenderWindow& window);

};


