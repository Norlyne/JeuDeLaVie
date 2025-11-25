#include "grille.h"
#include <cstdlib>  // pour std::rand
#include <fstream>
using namespace std;


//Constructors
grille::grille() {
    this->width = 100;
    this->height = 100;
    grid.resize(width, std::vector<cellule*>(height, nullptr)); // initialise les pointeurs à nullptr

    for (int dx = 0; dx < this->width; dx++) {
        for (int dy = 0; dy < this->height; dy++) {
            grid[dx][dy] = new cellule_morte(); // parenthèses obligatoires
        }
    }
}

grille::grille(int width, int height) {
    this->width = width;
    this->height = height;
    grid.resize(width, std::vector<cellule*>(height, nullptr));

    for (int dx = 0; dx < this->width; dx++) {
        for (int dy = 0; dy < this->height; dy++) {
            grid[dx][dy] = new cellule_morte();
        }
    }
}

grille::grille(grille& g) {
    this->width= g.width;
    this->height = g.height;
    for (int dx = 0; dx < width; dx++) {
        for (int dy = 0; dy < height; dy++) {
            grid[dx][dy] = g.get_grille(dx, dy);
        }
    }
}
// Destructeur
grille::~grille() {
    for (int dx = 0; dx < width; dx++) {
        for (int dy = 0; dy < height; dy++) {
            delete grid[dx][dy];
            grid[dx][dy] = nullptr;
        }
    }
}

//getters
int grille::get_width() { return this->width; }
int grille::get_height() { return this->height; }
cellule* grille::get_grille(int x, int y) { return this->grid[x][y]; }

//Setters
void grille::set_width(int width) { this->width = width; }
void grille::set_height(int height) { this->height = height; }
void grille::set_grille(int x, int y, bool state) {
    if (grid[x][y]) delete grid[x][y]; // supprime l'ancienne cellule
    if (state) {
        grid[x][y] = new cellule_vivante();
    }
    else {
        grid[x][y] = new cellule_morte();
    }
}

//Methodes
void grille::random_init() {
    for (int dx = 0; dx < this->width; dx++) {
        for (int dy = 0; dy < this->height; dy++) {
            if (std::rand() % 2 == 0) {
                if (grid[dx][dy]) delete grid[dx][dy];  // a revoir
                grid[dx][dy] = new cellule_vivante();
            }
            else {
                if (grid[dx][dy]) delete grid[dx][dy];
                grid[dx][dy] = new cellule_morte();
            }
        }
    }
}


void grille::fichier_init() {
    ifstream fichier("depart.txt", ios::in);

    if (fichier)
    {
        string chaine1, chaine2;
        int state;
        fichier >> this->width >> this->height;
        grid.resize(width, std::vector<cellule*>(height, nullptr));

        for (int dx = 0; dx < this->width; dx++) {
            for (int dy = 0; dy < this->height; dy++) {
                fichier >> state;
                if (state == 0) {
                    delete grid[dx][dy];
                    grid[dx][dy] = new cellule_morte();
                }
                else {
                    delete grid[dx][dy];
                    grid[dx][dy] = new cellule_vivante();
                }
            }
        }
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}


int grille::compt_voisin(int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            // gestion des bords: ignore les voisins hors grille
            if (nx >= 0 && nx < this->width && ny >= 0 && ny < this->height) {
                if (grid[nx][ny]->is_alive()) {
                    count++;
                }
            }
        }
    }
    return count;
};