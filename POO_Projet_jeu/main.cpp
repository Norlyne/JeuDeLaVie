#include <ctime>
#include <iostream>
#include "cellule.h"
#include "grille.h"

int main()
{
    std::srand(std::time(0));

    grille current_grid;
    grille next_grid;

    current_grid.fichier_init();

    for (int dx = 0; dx < current_grid.get_width(); dx++) {
        for (int dy = 0; dy < current_grid.get_height(); dy++) {
            cellule* c = current_grid.get_grille(dx, dy);
            if (c && c->is_alive()) std::cout << "1";
            else std::cout << "0";
        }
        std::cout << "\n";  // <- correction ici
    }
}
