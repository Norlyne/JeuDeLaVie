//commentaire
#include "jeu.h"

//Constructeurs
jeu::jeu() {
    this->indexe = 1;
    this->mode_depart = "1";
}

jeu::jeu(grille current_grid, grille next_grid, int ind) {
    this->indexe = ind;
    this->mode_depart = "1";
    this->current_grid = current_grid;
    this->next_grid = next_grid;
}

ModeNormal::ModeNormal() {}
ModeLifeIsShort::ModeLifeIsShort() {}
ModeDayAndLight::ModeDayAndLight() {}
labyrinthiques::labyrinthiques() {}
ExplosionsAndChaos::ExplosionsAndChaos() {}
MotifsRepliquants::MotifsRepliquants() {}
HighLife::HighLife() {}
Corail::Corail() {}

ModeNormal::ModeNormal( int ind) { this->indexe = ind; }
ModeLifeIsShort::ModeLifeIsShort( int ind) { this->indexe = ind; }
ModeDayAndLight::ModeDayAndLight( int ind) { this->indexe = ind; }
labyrinthiques::labyrinthiques( int ind) { this->indexe = ind; }
ExplosionsAndChaos::ExplosionsAndChaos( int ind) { this->indexe = ind; }
MotifsRepliquants::MotifsRepliquants( int ind) { this->indexe = ind; }
HighLife::HighLife( int ind) { this->indexe = ind; }
Corail::Corail( int ind) { this->indexe = ind; }

//getters
int jeu::get_attente() { return this->attente[this->indexe]; }
int jeu::get_indexe() { return this->indexe; }
grille& jeu::get_current_grid() { return this->current_grid; }
grille& jeu::get_next_grid() { return this->next_grid; }
int jeu::get_mode_depart() { return std::stoi(this->mode_depart); }


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

void jeu::set_current_grid(grille current_grid) { this->current_grid = current_grid; }
void jeu::set_next_grid(grille next_grid) { this->next_grid = next_grid; }
void jeu::set_mode_depart(string mode_depart) { this->mode_depart = mode_depart; }

//methodes
//void jeu::dessin_rectangle(RenderWindow& window) {
//    int x, y;
//
//    window.clear();
//    RectangleShape cell(Vector2f(this->current_grid.get_grille(0, 0)->get_cellsize() - 1.0f, this->current_grid.get_grille(0, 0)->get_cellsize() - 1.0f));
//    for (x = 0; x < current_grid.get_width(); ++x) {
//        for (y = 0; y < current_grid.get_height(); ++y) {
//            if (current_grid.get_grille(x, y)->is_alive() == 1) {
//                cell.setPosition((float)x * current_grid.get_grille(0, 0)->get_cellsize(), (float)y * current_grid.get_grille(0, 0)->get_cellsize());
//                int R = x * (255 / current_grid.get_width());
//                int Vx = 127 - (x * (127 / current_grid.get_width()));
//                int Vy = 127 - (y * (127 / current_grid.get_width()));
//                int B = y * (255 / current_grid.get_width());
//                cell.setFillColor(Color(R, Vx + Vy, B));
//                window.draw(cell);
//            }
//            else if (current_grid.get_grille(x, y)->is_alive() == 2) {
//                cell.setPosition((float)x * current_grid.get_grille(0, 0)->get_cellsize(), (float)y * current_grid.get_grille(0, 0)->get_cellsize());
//                cell.setFillColor(sf::Color(128, 128, 128));
//                window.draw(cell);
//            }
//        }
//    }
//    window.display();
//}

