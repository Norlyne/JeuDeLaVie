//commentaire
#include "jeu.h"

        //Constructeurs
jeu::jeu() {
    this->indexe = 1;
}

//getters
int jeu::get_attente() { return this->attente[this->indexe]; }
int jeu::get_indexe() { return this->indexe; }

//setters
void jeu::set_indexe(bool variation) {
    if (variation) {
        if (this->indexe == (sizeof(attente) / sizeof(attente[0]))) {}
        else { this->indexe++; }

    }
    else {
        if (this->indexe == 0) {}
        else { this->indexe--; }
    }
}

//methodes
void jeu::dessin_rectangle(RenderWindow& window, grille grid) {
    int x, y;

    window.clear();
    RectangleShape cell(Vector2f(grid.get_grille(0, 0)->get_cellsize() - 1.0f, grid.get_grille(0, 0)->get_cellsize() - 1.0f));
    for (x = 0; x < grid.get_width(); ++x) {
        for (y = 0; y < grid.get_height(); ++y) {
            if (grid.get_grille(x, y)->is_alive() == 1) {
                cell.setPosition((float)x * grid.get_grille(0, 0)->get_cellsize(), (float)y * grid.get_grille(0, 0)->get_cellsize());
                int R = x * (255 / grid.get_width());
                int Vx = 127 - (x * (127 / grid.get_width()));
                int Vy = 127 - (y * (127 / grid.get_width()));
                int B = y * (255 / grid.get_width());
                cell.setFillColor(Color(R, Vx + Vy, B));
                window.draw(cell);
            }
            else if (grid.get_grille(x, y)->is_alive() == 2) {
                cell.setPosition((float)x * grid.get_grille(0, 0)->get_cellsize(), (float)y * grid.get_grille(0, 0)->get_cellsize());
                cell.setFillColor(sf::Color(128, 128, 128));
                window.draw(cell);
            }
        }
    }
    window.display();
}
