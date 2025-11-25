#include "jeu.h"

void jeu::regle_base(grille &grid, grille &next) {
    for (int x = 0; x < grid.get_width(); ++x) {
        for (int y = 0; y < grid.get_height(); ++y) {
            int n = grid.compt_voisin(x, y);
            if (grid.get_grille(x, y)->is_alive()) {
                // cellule vivante
                if (n < 2 || n > 3) {
                    next.set_grille( x, y, false); // meurt
                }
                else {
                    next.set_grille(x, y, true); // survit
                }
            }
            else {
                // cellule morte
                if (n == 3) {
                    next.set_grille(x, y, true); // naissance
                }
                else {
                    next.set_grille(x, y, false);
                }
            }
        }
    }
    //grid.swap(next); // met à jour la grille courante
}

void jeu::dessin_rectangle(sf::RenderWindow& window, grille grid) {
    int x, y;

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(10 - 1.0f, 10 - 1.0f));
    for (x = 0; x < grid.get_width(); ++x) {
        for (y = 0; y < grid.get_height(); ++y) {
            if (grid.get_grille(x,y)->is_alive()) {
                cell.setPosition(x * 10, y * 10);
                window.draw(cell);
            }
        }
    }
    window.display();
};