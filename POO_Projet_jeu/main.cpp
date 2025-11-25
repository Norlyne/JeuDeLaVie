#include <ctime>
#include <iostream>
#include "cellule.h"
#include "grille.h"
#include "jeu.h"

int main()
{
    std::srand(std::time(0));

    grille grille1;
    grille1.fichier_init();
    //sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Jeu de la vie");

    //for (int dx = 0; dx < grille1.get_width(); dx++) {
    //    for (int dy = 0; dy < grille1.get_height(); dy++) {
    //        cellule* c = grille1.get_grille(dx, dy);
    //        if (c && c->is_alive()) std::cout << "1";
    //        else std::cout << "0";
    //    }
    //    std::cout << "\n";  
    //}

    jeu jeu;
    grille g = jeu.regle_base(grille1);

    std::cout << "Nouvelle largeur : " << g.get_width() << std::endl;
    std::cout << "Cellule (1,1) : " << g.get_grille(1, 1)->is_alive() << std::endl;

    for (int dx = 0; dx < g.get_width(); dx++) {
        for (int dy = 0; dy < g.get_height(); dy++) {
            cellule* c = g.get_grille(dx, dy);
            if (c && c->is_alive()) std::cout << "1";
            else std::cout << "0";
        }
        std::cout << "\n";
    }
    return 0;
};
