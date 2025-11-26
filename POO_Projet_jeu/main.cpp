#include <ctime>
#include <iostream>
#include "cellule.h"
#include "grille.h"
#include "jeu.h"

int main()
{
    srand(time(0));

    ModeNormal jeu2;
    ModeLifeIsShort jeu3;
    ModeDayAndLight jeu4;

    grille g;
    grille grille1;
    string rep;

    string mode = "1";

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
        cout << "Soutaitez-vous un grille alleatoire ou une grilles avec des blikers ? (a/1)" << endl;
        cout << "Voici une liste de blinkers disponible : " << endl;
        cout << "1." << "Glidres" << endl;
        cin >> ale;
        if (ale == "a") {
            string obs;
            cout << "Soutaitez-vous des obstacles dans la grille ? (o/n) " << endl;
            cin >> obs;
            if (obs == "o") {
                cout << "Quel mode de jeu souhaitez-vous ?" << endl;
                cout << "Voici une liste de mode disponible : " << endl;
                cout << "1." << "normal" << endl;
                cout << "2." << "Life is short ( attention pour les epileptiques)" << endl;
                cout << "3." << "Day and light" << endl;
                cin >> mode;
                grille1.random_init_obs();
                g.random_init_obs();
                if (mode != "1" || mode != "2" || mode != "3") { cout << "Erreur : mauvaise reponse" << endl; }
            }
            else if (obs == "n") {
                cout << "Quel mode de jeu souhaitez-vous ?" << endl;
                cout << "Voici une liste de mode disponible : " << endl;
                cout << "1." << "normal" << endl;
                cout << "2." << "Life is short ( attention pour les epileptiques)" << endl;
                cout << "3." << "Day and light" << endl;
                cin >> mode;
                grille1.random_init();
                g.random_init();
                if (mode != "1" || mode != "2" || mode != "3") { cout << "Erreur : mauvaise reponse" << endl; }
            }
            else {
                cout << "Erreur : mauvaise reponse" << endl;
            }
        }
        else if (ale == "1") {
            grille1.fichier_init("Gliders.txt");
            g.fichier_init("Gliders.txt");
        }
        else {
            cout << "Erreur : mauvaise reponse" << endl;
        }
    }
    else {
        cout << "Erreur : mauvaise reponse" << endl;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              CONSOLE                                              //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    /*for (int i = 0; i < 5; i++) {
        for (int dx = 0; dx < g.get_width(); dx++) {
            for (int dy = 0; dy < g.get_height(); dy++) {
                cellule* d = g.get_grille(dx, dy);
                if (d && d->is_alive() == 1) cout << "#";
                else cout << ".";
            }
            cout << "\n";
        }
        jeu.regle_base(grille1, g);
        cout << "---------------------------------------------------------------------------------------" << endl;
        
    }*/
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              WINDOWS                                              //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////


    RenderWindow window(VideoMode(grille1.get_width() * 10, grille1.get_height() * 10), "Jeu de la vie");
    window.clear(Color(214, 214, 214));
    bool etat = false;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Space)
                    etat = !etat;
            }
        }
        if (!etat) {
            if (mode == "1") {
                jeu2.regle_base(grille1, g);
                jeu2.dessin_rectangle(window, g);
                sleep(milliseconds(50));
            }
            else if (mode == "2") {
                jeu3.regle_base(grille1, g);
                jeu3.dessin_rectangle(window, g);
                sleep(milliseconds(50));
            }
            else if (mode == "3") {
                jeu4.regle_base(grille1, g);
                jeu4.dessin_rectangle(window, g);
                sleep(milliseconds(50));
            }
        }
    }
    return 0;
};