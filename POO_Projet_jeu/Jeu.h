//commentaire
#pragma once
#include "cellule.h"
#include "grille.h"
#include <direct.h>
#include <filesystem>

#pragma region Jeu

class jeu {
private:
public:
    string demarer(grille& grille1, grille& g, string& mode, string& nom_Dossier);

    void touche();

    virtual void regle_base(grille& grid, grille& next) = 0;
    void dessin_rectangle(RenderWindow& window, grille grid);
};

#pragma endregion

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
                else if (grid.get_grille(x, y)->is_alive() == 0) {
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
};

#pragma endregion

#pragma region labyrinthiques

class labyrinthiques : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin_thorique(x, y);
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    // cellule vivante
                    if (n == 2 || n == 3 || n == 4 || n == 5) {
                        next.set_grille(x, y, 1); // survit
                    }
                    else {
                        next.set_grille(x, y, 0); // meurt
                    }
                }
                else if (grid.get_grille(x, y)->is_alive() == 0) {
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
};

#pragma endregion

#pragma region ExplosionsAndChaos

class ExplosionsAndChaos : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin_thorique(x, y);
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    // cellule vivante
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
};

#pragma endregion

#pragma region MotifsRepliquants

// B1357/S1357
class MotifsRepliquants : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin_thorique(x, y);
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    // cellule vivante
                    if (n == 1 || n == 3 || n == 5 || n == 7) {
                        next.set_grille(x, y, 1); // survit
                    }
                    else {
                        next.set_grille(x, y, 0); // meurt
                    }
                }
                else if (grid.get_grille(x, y)->is_alive() == 0) {
                    // cellule morte
                    if (n == 1 || n == 3 || n == 5 || n == 7) {
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
};
#pragma endregion

#pragma region HighLife

class HighLife : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin_thorique(x, y);
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    // cellule vivante
                    if (n == 2 || n == 3) {
                        next.set_grille(x, y, 1); // survit
                    }
                    else {
                        next.set_grille(x, y, 0); // meurt
                    }
                }
                else if (grid.get_grille(x, y)->is_alive() == 0) {
                    // cellule morte
                    if (n == 3 || n == 6) {
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
};

#pragma endregion

#pragma region Corail

class Corail : public jeu {
public:
    void regle_base(grille& grid, grille& next) override {
        for (int x = 0; x < grid.get_width(); ++x) {
            for (int y = 0; y < grid.get_height(); ++y) {
                int n = grid.compt_voisin_thorique(x, y);
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    // cellule vivante
                    if (n >= 4 || n <= 8) {
                        next.set_grille(x, y, 1); // survit
                    }
                    else {
                        next.set_grille(x, y, 0); // meurt
                    }
                }
                else if (grid.get_grille(x, y)->is_alive() == 0) {
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
};
#pragma endregion

#pragma endregion