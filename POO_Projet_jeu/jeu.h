#pragma once
#include "cellule.h"
#include "grille.h"


class jeu {
    private:
    public:
	    virtual void regle_base(grille& grid, grille &next) = 0;
	    virtual void dessin_rectangle(RenderWindow& window, grille grid) = 0;
};

#pragma region Mode

     #pragma region ModeNormal

class ModeNormal : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin_thorique(x, y);
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    // cellule vivante
                    if (n < 2 || n > 3) {
                        next.set_grille(x, y, 0); // meurt
                    }
                    else {
                        next.set_grille(x, y, 1); // survit
                    }
                }
                else if (grid.get_grille(x, y)->is_alive() == 0){
                    // cellule morte
                    if (n == 3) {
                        next.set_grille(x, y, 1); // naissance
                    }
                    else {
                        next.set_grille(x, y, 0);
                    }
                }
                else {
                    next.set_grille(x, y, 2);
                }
            }
        }
        /// swap 
        for (int dx = 0; dx < next.get_width(); dx++) {
            for (int dy = 0; dy < next.get_height(); dy++) {
                if (next.get_grille(dx, dy)->is_alive() == 1) {
                    grid.set_grille(dx, dy, 1);
                }
                else if (next.get_grille(dx, dy)->is_alive() == 0) {
                    grid.set_grille(dx, dy, 0);
                }
                else {
                    grid.set_grille(dx, dy, 2);
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
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    cell.setPosition(x * 10, y * 10);
                    cell.setFillColor(Color(rand() % 1+x, rand()%255, rand() % 1 + x));
                    window.draw(cell);
                }
                else if (grid.get_grille(x, y)->is_alive() == 2) {
                    cell.setPosition(x * 10, y * 10);
                    cell.setFillColor(sf::Color(128, 128, 128));
                    window.draw(cell);
                }
            }
        }
        window.display();
    }
};

#pragma endregion

     #pragma region ModeLifeIsShort

class ModeLifeIsShort : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin_thorique(x, y);
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    next.set_grille(x, y, 0); // meurt
                }
                else if (grid.get_grille(x, y)->is_alive() == 0) {
                    // cellule morte
                    if (n == 2) {
                        next.set_grille(x, y, 1); // naissance
                    }
                    else {
                        next.set_grille(x, y, 0);
                    }
                }
                else {
                    next.set_grille(x, y, 2);
                }
            }
        }
        /// swap 
        for (int dx = 0; dx < next.get_width(); dx++) {
            for (int dy = 0; dy < next.get_height(); dy++) {
                if (next.get_grille(dx, dy)->is_alive() == 1) {
                    grid.set_grille(dx, dy, 1);
                }
                else if (next.get_grille(dx, dy)->is_alive() == 0) {
                    grid.set_grille(dx, dy, 0);
                }
                else {
                    grid.set_grille(dx, dy, 2);
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
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    cell.setPosition(x * 10, y * 10);
                    cell.setFillColor(Color(rand() % 1 + x, rand() % 255, rand() % 1 + x));
                    window.draw(cell);
                }
                else if (grid.get_grille(x, y)->is_alive() == 2) {
                    cell.setPosition(x * 10, y * 10);
                    cell.setFillColor(sf::Color(128, 128, 128));
                    window.draw(cell);
                }

            }
        }
        window.display();
    }
};
	
#pragma endregion

     #pragma region ModeDayAndLight

class ModeDayAndLight : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin_thorique(x, y);
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    //une cellule vivante survit à l'étape suivante si elle est entourée de 3, 4, 6, 7 ou 8 cellules vivantes.
                    if (n == 3 || n == 4 || n == 6 || n == 7 || n == 8) {
                        next.set_grille(x, y, 1); // survit
                    }
                    else {
                        next.set_grille(x, y, 0); // meurt
                    }
                }
                else if (grid.get_grille(x, y)->is_alive() == 0) {
                    //une cellule morte naît à l'étape suivante si elle est entourée de 3, 6, 7 ou 8 voisines,
                    if (n == 3 || n == 6 || n == 7 || n == 8) {
                        next.set_grille(x, y, 1); // naissance
                    }
                    else {
                        next.set_grille(x, y, 0);
                    }
                }
                else {
                    next.set_grille(x, y, 2);
                }
            }
        }
        /// swap 
        for (int dx = 0; dx < next.get_width(); dx++) {
            for (int dy = 0; dy < next.get_height(); dy++) {
                if (next.get_grille(dx, dy)->is_alive() == 1) {
                    grid.set_grille(dx, dy, 1);
                }
                else if (next.get_grille(dx, dy)->is_alive() == 0) {
                    grid.set_grille(dx, dy, 0);
                }
                else {
                    grid.set_grille(dx, dy, 2);
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
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    cell.setPosition(x * 10, y * 10);
                    cell.setFillColor(Color(rand() % 1 + x, rand() % 255, rand() % 1 + x));
                    window.draw(cell);
                }
                else if (grid.get_grille(x, y)->is_alive() == 2) {
                    cell.setPosition(x * 10, y * 10);
                    cell.setFillColor(sf::Color(137, 81, 41));
                    window.draw(cell);
                }
                else  {
                    cell.setPosition(x * 10, y * 10);
                    cell.setFillColor(sf::Color(0, 0, 0));
                    window.draw(cell);
                }
                

            }
        }
        window.display();
    }
};

#pragma endregion

#pragma endregion