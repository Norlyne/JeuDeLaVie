#include "jeu.h"

void jeu::dessin_rectangle(RenderWindow& window, grille grid) {
    int x, y;

    window.clear();
    RectangleShape cell(Vector2f(10 - 1.0f, 10 - 1.0f));
    for (x = 0; x < grid.get_width(); ++x) {
        for (y = 0; y < grid.get_height(); ++y) {
            if (grid.get_grille(x, y)->is_alive() == 1) {
                cell.setPosition((float)x * 10, (float)y * 10);
                int R = x * (255 / grid.get_width());
                int Vx = 127 - (x * (127 / grid.get_width()));
                int Vy = 127 - (y * (127 / grid.get_width()));
                int B = y * (255 / grid.get_width());
                cell.setFillColor(Color(R, Vx + Vy, B));
                window.draw(cell);
            }
            else if (grid.get_grille(x, y)->is_alive() == 2) {
                cell.setPosition((float)x * 10, (float)y * 10);
                cell.setFillColor(sf::Color(128, 128, 128));
                window.draw(cell);
            }
        }
    }
    window.display();
}
/*
void ::regle_base(grille &grid, grille &next) {
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
    /// swap
    for (int dx = 0; dx < next.get_width(); dx++) {
        for (int dy = 0; dy < next.get_height(); dy++) {
            if (next.get_grille(dx, dy)->is_alive()) {
                grid.set_grille(dx, dy, true);
            }
            else {
                grid.set_grille(dx, dy, false);
            }
        }
    }
}

void jeu::dessin_rectangle(sf::RenderWindow& window, grille grid) {
    int x, y;

    window.clear();
    RectangleShape cell(Vector2f(10 - 1.0f, 10 - 1.0f));
    for (x = 0; x < grid.get_width(); ++x) {
        for (y = 0; y < grid.get_height(); ++y) {
            if (grid.get_grille(x,y)->is_alive()) {
                cell.setPosition(x * 10, y * 10);
                window.draw(cell);
            }
        }
    }
    window.display();
};*/