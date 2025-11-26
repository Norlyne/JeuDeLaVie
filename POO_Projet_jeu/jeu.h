#pragma once
#include "cellule.h"
#include "grille.h"


class jeu
{
private:
public:
	void regle_base(grille& grid, grille& next);
	void dessin_rectangle(sf::RenderWindow& window, grille grid);
};

