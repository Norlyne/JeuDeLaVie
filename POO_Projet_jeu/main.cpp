#include <ctime>
#include <iostream>
#include "cellule.h"
#include "grille.h"

int main()
{
    std::srand(std::time(0));

    grille grille1;
    grille1.fichier_init();

    for (int dx = 0; dx < grille1.get_width(); dx++) {
        for (int dy = 0; dy < grille1.get_height(); dy++) {
            cellule* c = grille1.get_grille(dx, dy);
            if (c && c->is_alive()) std::cout << "1";
            else std::cout << "0";
        }
        std::cout << "\n";  // <- correction ici
    }
}
