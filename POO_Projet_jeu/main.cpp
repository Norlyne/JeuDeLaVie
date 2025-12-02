//commentaire
#include <ctime>
#include <iostream>
#include <fstream>
#include <fontsub.h>
#include "cellule.h"
#include "grille.h"
#include "jeu.h"
#include "patternes.h"
#include "source.h"

int jeu::indexe = 0;
string jeu::mode_depart = "1";
grille jeu::current_grid = grille();
grille jeu::next_grid = grille();

int main()
{
    string demarage;
    cout << "Quel mode de demarrage ?" << endl;
    cout << "1." << "Console" << endl;
    cout << "2." << "Test unitaire" << endl;
    cout << "3." << "Window" << endl;
    cin >> demarage;
    if (demarage == "1") {
        console();
    }
    else if (demarage == "2") {
        test();
    }
    else if (demarage == "3") {
        window();
    }
    else {
        cout << "Ce mode de demarrage n'existe pas" << endl;
    }

    return 0;
}












