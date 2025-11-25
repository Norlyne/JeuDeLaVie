#include "jeu.h"

void jeu::regle_base(grille current_grid, grille new_grid) {
    int nb_voisin;
    for (int dx = 0; dx < current_grid.get_width(); dx++) {
        for (int dy = 0; dy < current_grid.get_height(); dy++) {
            nb_voisin = compt_voisin();
            cellule* current = grille1.get_grille(dx, dy)
         
                if (grid[dx][dy]) delete grid[dx][dy];  // a revoir
                grid[dx][dy] = new cellule_vivante();
         
        
                if (grid[dx][dy]) delete grid[dx][dy];
                grid[dx][dy] = new cellule_morte();
           
        }
    }
}



grille jeu::regle_base(grille& grid) {

    grille next(grid.get_width(), grid.get_height());

    for (int x = 0; x < grid.get_width(); ++x) {
        for (int y = 0; y < grid.get_height(); ++y) {

            int n = grid.compt_voisin(x, y);
            bool alive = grid.get_grille(x, y)->is_alive();

            if (alive) {
                next.set_grille(x, y, (n == 2 || n == 3));
            }
            else {
                next.set_grille(x, y, (n == 3));
            }
        }
    }

    return next;
}