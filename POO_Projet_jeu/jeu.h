#pragma once
#include "cellule.h"
#include "grille.h"

#pragma region Jeu

class jeu {
    private:
    public:
        string demarer(grille& grille1, grille& g, string& mode) {
            string rep;
            cout << "Avez-vous un fichier ? (o/n) " << endl;
            cin >> rep;
            if (rep == "o") {
                string fic;
                cout << "Quel est sont nom ? (.txt)" << endl;
                cin >> fic;
                grille1.fichier_init(fic);
                g.fichier_init(fic);
            }
            else if (rep == "n") {
                string ale;
                cout << "Voici une liste de blinkers disponible : " << endl;
                cout << "1." << "Glidres" << endl;
                cout << "2." << "vide" << endl;
                cout << "3." << "lab ( teste du mode labirinthe ) " << endl;
                cout << "4." << "expetchaos ( teste du mode exp et chaos ) " << endl;
                cout << "5." << "Motrep ( teste du mode Motifs repetion ) " << endl;
                cout << "Soutaitez-vous un grille alleatoire ou une grilles avec des blikers ? (a/1)" << endl;
                cin >> ale;
                if (ale == "a") {
                    string obs;
                    cout << "Soutaitez-vous des obstacles dans la grille ? (o/n) " << endl;
                    cin >> obs;
                    if (obs == "o") {
                        cout << "Voici une liste de mode disponible : " << endl;
                        cout << "1." << "normal" << endl;
                        cout << "2." << "Life is short ( attention pour les epileptiques)" << endl;
                        cout << "3." << "Day and light" << endl;
                        cout << "4." << "Labyrinthiques" << endl;
                        cout << "5." << "Explosions And Chaos" << endl;
                        cout << "6." << "Motifs Repliquants" << endl;
                        cout << "7." << "HighLife" << endl;
                        cout << "8." << "Corail" << endl;
                        cout << "Quel mode de jeu souhaitez-vous ?" << endl;
                        cin >> mode;
                        grille1.random_init_obs();
                        g.random_init_obs();
                        if (mode != "1" && mode != "2" && mode != "3" && mode != "4" && mode != "5" && mode != "6" && mode != "7" && mode != "8") { cout << "Erreur : mauvaise reponse" << endl; }
                    }
                    else if (obs == "n") {
                        cout << "Voici une liste de mode disponible : " << endl;
                        cout << "1." << "normal" << endl;
                        cout << "2." << "Life is short ( attention pour les epileptiques)" << endl;
                        cout << "3." << "Day and light" << endl;
                        cout << "4." << "Labyrinthiques" << endl;
                        cout << "5." << "Explosions And Chaos" << endl;
                        cout << "6." << "Motifs Repliquants" << endl;
                        cout << "7." << "HighLife" << endl;
                        cout << "8." << "Corail" << endl;
                        cout << "Quel mode de jeu souhaitez-vous ?" << endl;
                        cin >> mode;
                        grille1.random_init();
                        g.random_init();
                        if (mode != "1" && mode != "2" && mode != "3" && mode != "4" && mode != "5" && mode != "6" && mode != "7" && mode != "8") { cout << "Erreur : mauvaise reponse" << endl; }
                    }
                    else {
                        cout << "Erreur : mauvaise reponse" << endl;
                    }
                }
                else if (ale == "1") {
                    grille1.fichier_init("Gliders.txt");
                    g.fichier_init("Gliders.txt");
                }
                else if (ale == "2") {
                    grille1.fichier_init("vide.txt");
                    g.fichier_init("vide.txt");
                }
                else if (ale == "3") {
                    mode = "4";
                    grille1.fichier_init("lab.txt");
                    g.fichier_init("lab.txt");
                }
                else if (ale == "4") {
                    mode = "5";
                    grille1.fichier_init("expetchaos.txt");
                    g.fichier_init("expetchaos.txt");
                }
                else if (ale == "5") {
                    mode = "6";
                    grille1.fichier_init("Motrep.txt");
                    g.fichier_init("Motrep.txt");
                }
                else {
                    cout << "Erreur : mauvaise reponse" << endl;
                }
            }
            else {
                cout << "Erreur : mauvaise reponse" << endl;
            }
            return mode;
        };

	    virtual void regle_base(grille& grid, grille &next) = 0;
	    virtual void dessin_rectangle(RenderWindow& window, grille grid) = 0;
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
                    cell.setPosition((float)x * 10, (float)y * 10);
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
                    cell.setPosition((float)x * 10, (float)y * 10);
                    cell.setFillColor(Color(rand() % 1 + x, rand() % 255, rand() % 1 + x));
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
                    cell.setPosition((float)x * 10, (float)y * 10);
                    cell.setFillColor(Color(rand() % 1 + x, rand() % 255, rand() % 1 + x));
                    window.draw(cell);
                }
                else if (grid.get_grille(x, y)->is_alive() == 2) {
                    cell.setPosition((float)x * 10, (float)y * 10);
                    cell.setFillColor(sf::Color(137, 81, 41));
                    window.draw(cell);
                }
                else  {
                    cell.setPosition((float)x * 10, (float)y * 10);
                    cell.setFillColor(sf::Color(0, 0, 0));
                    window.draw(cell);
                }
                

            }
        }
        window.display();
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

    void dessin_rectangle(RenderWindow& window, grille grid) override {
        int x, y;

        window.clear();
        RectangleShape cell(Vector2f(10 - 1.0f, 10 - 1.0f));
        for (x = 0; x < grid.get_width(); ++x) {
            for (y = 0; y < grid.get_height(); ++y) {
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    cell.setPosition((float)x * 10, (float)y * 10);
                    cell.setFillColor(Color(rand() % 1 + x, 255, rand() % 1 + x));
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

    void dessin_rectangle(RenderWindow& window, grille grid) override {
        int x, y;

        window.clear();
        RectangleShape cell(Vector2f(10 - 1.0f, 10 - 1.0f));
        for (x = 0; x < grid.get_width(); ++x) {
            for (y = 0; y < grid.get_height(); ++y) {
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    cell.setPosition((float)x * 10, (float)y * 10);
                    cell.setFillColor(Color(rand() % 1 + x, rand() % 255, rand() % 1 + x));
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

    void dessin_rectangle(RenderWindow& window, grille grid) override {
        int x, y;

        window.clear();
        RectangleShape cell(Vector2f(10 - 1.0f, 10 - 1.0f));
        for (x = 0; x < grid.get_width(); ++x) {
            for (y = 0; y < grid.get_height(); ++y) {
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    cell.setPosition((float)x * 10, (float)y * 10);
                    cell.setFillColor(Color(rand() % 1 + x, rand() % 255, rand() % 1 + x));
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
                    if (n == 3 || n== 6) {
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
                    cell.setPosition((float)x * 10, (float)y * 10);
                    cell.setFillColor(Color(rand() % 1 + x, rand() % 255, rand() % 1 + x));
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

    void dessin_rectangle(RenderWindow& window, grille grid) override {
        int x, y;

        window.clear();
        RectangleShape cell(Vector2f(10 - 1.0f, 10 - 1.0f));
        for (x = 0; x < grid.get_width(); ++x) {
            for (y = 0; y < grid.get_height(); ++y) {
                if (grid.get_grille(x, y)->is_alive() == 1) {
                    cell.setPosition((float)x * 10, (float)y * 10);
                    cell.setFillColor(Color(rand() % 1 + x, rand() % 255, rand() % 1 + x));
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
};
#pragma endregion

#pragma endregion