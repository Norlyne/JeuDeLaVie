//commentaire
#include "jeu.h"

string jeu::demarer(grille& grille1, grille& g, string& mode, string& nom_Dossier) {
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

void jeu::touche() {
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
                cell.setFillColor(sf::Color(255, 0, 0));
                window.draw(cell);
            }
        }
    }
    window.display();
}