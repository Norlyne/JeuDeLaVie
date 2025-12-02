//commentaire
#pragma once
#include "cellule.h"
#include "grille.h"
#include <direct.h>
#include <filesystem>

#pragma region Jeu

class jeu {
private:
protected:
    const int attente[6] = { 2000, 1000, 500, 200, 100, 50 };
    static int indexe;
    static string mode_depart;
    static grille current_grid;
    static grille next_grid;
    public:
        
        //Constructeurs
        jeu();
        jeu(grille current_grid, grille next_grid, int ind);

        //getters
        int get_attente();
        int get_indexe();
        grille& get_current_grid();
        grille& get_next_grid();
        int get_mode_depart();

        //setters
        void set_indexe(bool variation);
        void set_current_grid(grille current_grid);
        void set_next_grid(grille next_grid);
        void set_mode_depart(string mode_depart);


        void demarer(string& nom_Dossier) {
            string rep;
            cout << "Avez-vous un fichier ? (o/n) " << endl;
            cin >> rep;
            if (rep == "o") {
                string fic;
                cout << "Quel est sont nom ? (.txt)" << endl;
                cin >> fic; 
                nom_Dossier = fic.substr(0, fic.length() - 4) + "_out";
                int retour = _mkdir(nom_Dossier.c_str());
                this->current_grid.fichier_init(fic);
                this->next_grid.fichier_init(fic);
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
                    cin >> this->mode_depart;
                    if (mode_depart != "1" && mode_depart != "2" && mode_depart != "3" && mode_depart != "4" && mode_depart != "5" && mode_depart != "6" && mode_depart != "7" && mode_depart != "8") { cout << "Erreur : mauvaise reponse" << endl; }
                    if (obs == "o") {
                        this->current_grid.random_init_obs();
                        this->next_grid.random_init_obs();
                    }
                    else if (obs == "n") {
                        this->current_grid.random_init();
                        this->next_grid.random_init();
                    }
                    else {
                        cout << "Erreur : mauvaise reponse" << endl;
                    }
                }
                else if (pattern_depart == "1") {//////////////////////////////////////////////////////////////////////////////////////////
                    this->current_grid.fichier_init("Gliders.txt");
                    this->next_grid.fichier_init("Gliders.txt");
                }
                else if (pattern_depart == "2") {
                    this->current_grid.fichier_init("vide.txt");
                    this->next_grid.fichier_init("vide.txt");
                }
                else if (pattern_depart == "3") {
                    this->mode_depart = "4";
                    this->current_grid.fichier_init("lab.txt");
                    this->next_grid.fichier_init("lab.txt");
                }
                else if (pattern_depart == "4") {
                    this->mode_depart = "5";
                    this->current_grid.fichier_init("expetchaos.txt");
                    this->next_grid.fichier_init("expetchaos.txt");
                }
                else if (pattern_depart == "5") {
                    this->mode_depart = "6";
                    this->current_grid.fichier_init("Motrep.txt");
                    this->next_grid.fichier_init("Motrep.txt");
                }
                else {
                    cout << "Erreur : mauvaise reponse" << endl;
                }
            }
            else {
                cout << "Erreur : mauvaise reponse" << endl;
            }
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

	    virtual void regle_base() = 0;
	    //void dessin_rectangle(RenderWindow& window);
};

#pragma endregion

#pragma region Mode

#pragma region ModeNormal

class ModeNormal : public jeu {
public:
    ModeNormal();
    ModeNormal(grille current_grid, grille next_grid, int ind);

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n < 2 || n > 3) {
                        this->next_grid.set_grille(x, y, 0);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 1);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region ModeLifeIsShort

class ModeLifeIsShort : public jeu {
public:
    ModeLifeIsShort();
    ModeLifeIsShort(grille current_grid, grille next_grid, int ind);

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    this->next_grid.set_grille(x, y, 0);
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 2) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region ModeDayAndLight

class ModeDayAndLight : public jeu {
public:
    ModeDayAndLight();
    ModeDayAndLight(grille current_grid, grille next_grid, int ind);

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n == 3 || n == 4 || n == 6 || n == 7 || n == 8) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3 || n == 6 || n == 7 || n == 8) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region labyrinthiques

class labyrinthiques : public jeu {
public:
    labyrinthiques();
    labyrinthiques(grille current_grid, grille next_grid, int ind);

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n == 2 || n == 3 || n == 4 || n == 5) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region ExplosionsAndChaos

class ExplosionsAndChaos : public jeu {
public:
    ExplosionsAndChaos();
    ExplosionsAndChaos(grille current_grid, grille next_grid, int ind);

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    this->next_grid.set_grille(x, y, 0);
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 2) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region MotifsRepliquants

class MotifsRepliquants : public jeu {
public:
    MotifsRepliquants();
    MotifsRepliquants(grille current_grid, grille next_grid, int ind);

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n == 1 || n == 3 || n == 5 || n == 7) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 1 || n == 3 || n == 5 || n == 7) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region HighLife

class HighLife : public jeu {
public:
    HighLife();
    HighLife(grille current_grid, grille next_grid, int ind);

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n == 2 || n == 3) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3 || n == 6) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region Corail

class Corail : public jeu {
public:
    Corail();
    Corail(grille current_grid, grille next_grid, int ind);

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n >= 4 || n <= 8) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma endregion