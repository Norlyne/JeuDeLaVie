#pragma once
#include "cellule.h"
#include "grille.h"


class jeu {
private:
public:
	virtual void regle_base(grille& grid, grille &next) = 0;
	virtual void dessin_rectangle(RenderWindow& window, grille grid) = 0;
};


class ModeNormal : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin(x, y);
                if (grid.get_grille(x, y)->is_alive()) {
                    // cellule vivante
                    if (n < 2 || n > 3) {
                        next.set_grille(x, y, false); // meurt
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

    void dessin_rectangle(RenderWindow& window, grille grid) override {
        int x, y;

        window.clear();
        RectangleShape cell(Vector2f(10 - 1.0f, 10 - 1.0f));
        for (x = 0; x < grid.get_width(); ++x) {
            for (y = 0; y < grid.get_height(); ++y) {
                if (grid.get_grille(x, y)->is_alive()) {
                    cell.setPosition(x * 10, y * 10);
                    window.draw(cell);
                }
            }
        }
        window.display();
    }
};

class ModeLifeIsShort : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin(x, y);
                if (grid.get_grille(x, y)->is_alive()) {
                    next.set_grille(x, y, false); // meurt
                }
                else {
                    // cellule morte
                    if (n == 2) {
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

    void dessin_rectangle(RenderWindow& window, grille grid) override {
        int x, y;

        window.clear();
        RectangleShape cell(Vector2f(10 - 1.0f, 10 - 1.0f));
        for (x = 0; x < grid.get_width(); ++x) {
            for (y = 0; y < grid.get_height(); ++y) {
                if (grid.get_grille(x, y)->is_alive()) {
                    cell.setPosition(x * 10, y * 10);
                    cell.setFillColor(sf::Color(100, 250, 50));
                    window.draw(cell);
                }
            }
        }
        window.display();
    }
};
	

class ModeDayAndLight : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin(x, y);
                if (grid.get_grille(x, y)->is_alive()) {
                    //une cellule vivante survit à l'étape suivante si elle est entourée de 3, 4, 6, 7 ou 8 cellules vivantes.
                    if (n == 3 || n == 4 || n == 6 || n == 7 || n == 8) {
                        next.set_grille(x, y, true); // survit
                    }
                    else {
                        next.set_grille(x, y, false); // meurt
                    }
                }
                else {
                    //une cellule morte naît à l'étape suivante si elle est entourée de 3, 6, 7 ou 8 voisines,
                    if (n == 3 || n == 6 || n == 7 || n == 8) {
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

    void dessin_rectangle(RenderWindow& window, grille grid) override {
        int x, y;

        window.clear();
        RectangleShape cell(Vector2f(10 - 1.0f, 10 - 1.0f));
        for (x = 0; x < grid.get_width(); ++x) {
            for (y = 0; y < grid.get_height(); ++y) {
                if (grid.get_grille(x, y)->is_alive()) {
                    cell.setPosition(x * 10, y * 10);
                    cell.setFillColor(sf::Color(250, 250, 50));
                    window.draw(cell);
                }
            }
        }
        window.display();
    }
};