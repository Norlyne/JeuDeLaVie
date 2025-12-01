//commentaire
#pragma once
#include "cellule.h"
#include "grille.h"
#include <direct.h>
#include <filesystem>

#pragma region Jeu

class jeu {
protected:
    const int attente[6] = { 2000, 1000, 500, 200, 100, 50 };
    static int indexe;
    public:
        //Constructeurs
        jeu();

        //getters
        int get_attente();
        int get_indexe();

        //setters
        void set_indexe(bool variation);

        string demarer(grille& grille1, grille& g, string& mode_depart, string& nom_Dossier) {
            string rep;
            cout << "Avez-vous un fichier ? (o/n) " << endl;
            cin >> rep;
            if (rep == "o") {
                string fic;
                cout << "Quel est sont nom ? (.txt)" << endl;
                cin >> fic; 
                nom_Dossier = fic.substr(0, fic.length() - 4) + "_out";
                int retour = _mkdir(nom_Dossier.c_str());
                grille1.fichier_init(fic);
                g.fichier_init(fic);
            }
            else if (rep == "n") {
                nom_Dossier = "None";
                int retour = _mkdir(nom_Dossier.c_str());
                string pattern_depart;
                cout << "Voici une liste de blinkers disponible : " << endl;
                cout << "1." << "Glidres" << endl;
                cout << "2." << "vide" << endl;
                cout << "3." << "lab ( teste du mode labirinthe ) " << endl;
                cout << "4." << "expetchaos ( teste du mode exp et chaos ) " << endl;
                cout << "5." << "Motrep ( teste du mode Motifs repetion ) " << endl;
                cout << "Soutaitez-vous un grille alleatoire ou une grilles avec des blikers ? (a/1)" << endl;
                cin >> pattern_depart;
                if (pattern_depart == "a") {
                    string obs;
                    cout << "Soutaitez-vous des obstacles dans la grille ? (o/n) " << endl;
                    cin >> obs;
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
                    cin >> mode_depart;
                    if (mode_depart != "1" && mode_depart != "2" && mode_depart != "3" && mode_depart != "4" && mode_depart != "5" && mode_depart != "6" && mode_depart != "7" && mode_depart != "8") { cout << "Erreur : mauvaise reponse" << endl; }
                    if (obs == "o") {
                        grille1.random_init_obs();
                        g.random_init_obs();
                    }
                    else if (obs == "n") {
                        grille1.random_init();
                        g.random_init();
                    }
                    else {
                        cout << "Erreur : mauvaise reponse" << endl;
                    }
                }
                else if (pattern_depart == "1") {
                    grille1.fichier_init("Gliders.txt");
                    g.fichier_init("Gliders.txt");
                }
                else if (pattern_depart == "2") {
                    grille1.fichier_init("vide.txt");
                    g.fichier_init("vide.txt");
                }
                else if (pattern_depart == "3") {
                    mode_depart = "4";
                    grille1.fichier_init("lab.txt");
                    g.fichier_init("lab.txt");
                }
                else if (pattern_depart == "4") {
                    mode_depart = "5";
                    grille1.fichier_init("expetchaos.txt");
                    g.fichier_init("expetchaos.txt");
                }
                else if (pattern_depart == "5") {
                    mode_depart = "6";
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
            return mode_depart;
        };

        void touche() {
            cout << "-----------------------------------------------" << endl;
            cout << "                Options & Mode                    " << endl;
            cout << "-----------------------------------------------" << endl;
            cout << " Espace : Pause" << endl;
            cout << " A : Grille aleatoire" << endl;
            cout << " R : Reset" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << " N : Mode Normal" << endl;
            cout << " S : Mode Life is short" << endl;
            cout << " D : Mode Day and light" << endl;
            cout << " L : Mode Labyrinthiques" << endl;
            cout << " E : Mode Explosions and chaos" << endl;
            cout << " M : Mode Motifs repliquants" << endl;
            cout << " H : Mode High life" << endl;
            cout << " C : Mode Corail" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "               Poser des Patternes             " << endl;
            cout << "-----------------------------------------------" << endl;
            cout << " 1+Click gauche : une cellule " << endl;
            cout << " 2+Click gauche : un carre " << endl;
            cout << " 3+Click gauche : un glider " << endl;
            cout << " 4+Click gauche : un ocsillateur 1" << endl;
            cout << " 5+Click gauche : un ocsillateur 2" << endl;
        }

	    virtual void regle_base(grille& grid, grille &next) = 0;
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