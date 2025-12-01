#include <ctime>
#include <iostream>
#include <fontsub.h>
#include "cellule.h"
#include "grille.h"
#include "jeu.h"
#include "patternes.h"
int main()
{
    srand(time(0));

    ModeNormal jeu2;
    ModeLifeIsShort jeu3;
    ModeDayAndLight jeu4;
    labyrinthiques jeu5;
    ExplosionsAndChaos jeu6;
    MotifsRepliquants jeu7;
    HighLife jeu8;
    Corail jeu9;

    grille g;
    grille grille1;

    pattern* pat;
    pat = new point;
    
    sf::Vector2i pixelPos;

    string mode = "1";

    string nom_Dossier = "";
    string nomFichier = "";

    jeu2.demarer(g, grille1, mode, nom_Dossier);
  

    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              CONSOLE                                              //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    
    /*for (int i = 0; i < 5; i++) {

        nomFichier = nom_Dossier + "/iteration" + to_string(i) + ".txt";
        std::ofstream fichier(nomFichier, ios::out);

        for (int dx = 0; dx < g.get_width(); dx++) {
            for (int dy = 0; dy < g.get_height(); dy++) {
                cellule* d = g.get_grille(dx, dy);
                if (d && d->is_alive() == 1) {
                    cout << "#";
                    fichier << 1 << " ";
                }
                else {
                    cout << ".";
                    fichier << 0 << " ";
                }
            }
            cout << "\n";
            fichier << endl;
        }
        jeu2.regle_base(grille1, g);
        cout << "---------------------------------------------------------------------------------------" << endl;
        fichier.close();
        sleep(milliseconds(1000));

        
    }*/
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              WINDOWS                                              //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    // Chargement de la police à partir d'un fichier
    /*Font MyFont;
    string s = "Hello";
    String Text( s, MyFont, 50);*/

    // Ou, si vous souhaitez le faire après la construction :
    /*sf::String Text;
    Text.SetText("Hello");
    Text.SetFont(MyFont);
    Text.SetSize(50);*/

    RenderWindow window(VideoMode(grille1.get_width() * grille1.get_grille(0,0)->get_cellsize(), grille1.get_height() * grille1.get_grille(0, 0)->get_cellsize()), "Jeu de la vie");
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

                if (event.key.code == Keyboard::Num1) {
                    delete pat;
                    pat = new point(0, 0, g.get_grille(0,0));
                }

                if (event.key.code == Keyboard::Num2) {
                    delete pat;
                    pat = new stable1(0, 0, g.get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num3) {
                    delete pat;
                    pat = new stable2(0, 0, g.get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num4) {
                    delete pat;
                    pat = new glider(0, 0, g.get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num5) {
                    delete pat;
                    pat = new oscilateur1(0, 0, g.get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num6) {
                    delete pat;
                    pat = new oscilateur2(0, 0, g.get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num7) {
                    delete pat;
                    pat = new canon_glider(0, 0, g.get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num0) {
                    delete pat;
                    pat = new obstacle(0, 0, g.get_grille(0, 0));
                }


                if (event.key.code == Keyboard::A) {
                    pat->random(grille1, g, window);
                }

                if (event.key.code == Keyboard::O) {
                    pat->random_obs(grille1, g, window);
                }

                if (event.key.code == Keyboard::R) {
                    pat->reset(grille1, g, window);
                }

                if (event.key.code == Keyboard::N) {
                    mode = "1";
                }

                if (event.key.code == Keyboard::S) {
                    mode = "2";
                }

                if (event.key.code == Keyboard::D) {
                    mode = "3";
                }

                if (event.key.code == Keyboard::L) {
                    mode = "4";
                }

                if (event.key.code == Keyboard::E) {
                    mode = "5";
                }

                if (event.key.code == Keyboard::M) {
                    mode = "6";
                }

                if (event.key.code == Keyboard::H) {
                    mode = "7";
                }

                if (event.key.code == Keyboard::C) {
                    mode = "8";
                }
            }

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    pixelPos = sf::Mouse::getPosition(window);
                    pat->set_x2(pixelPos.x / grille1.get_grille(0, 0)->get_cellsize());
                    pat->set_y2(pixelPos.y / grille1.get_grille(0, 0)->get_cellsize());
                    pat->poser(pixelPos.x, pixelPos.y, g, grille1, window);
                    g.get_grille(0, 0)->dessin_instantané(mode, window, grille1, jeu2, jeu3, jeu4, jeu5, jeu6, jeu7, jeu8, jeu9);                    
                }
            }
        }
        if (!etat) {
            if (mode == "1") {
                jeu2.regle_base(grille1, g);
                jeu2.dessin_rectangle(window, g);
                sleep(milliseconds(100));
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
            else if (mode == "4") {
                jeu5.regle_base(grille1, g);
                jeu5.dessin_rectangle(window, g);
                sleep(milliseconds(50));
            }
            else if (mode == "5") {
                jeu6.regle_base(grille1, g);
                jeu6.dessin_rectangle(window, g);
                sleep(milliseconds(50));
            }
            else if (mode == "6") {
                jeu7.regle_base(grille1, g);
                jeu7.dessin_rectangle(window, g);
                sleep(milliseconds(50));
            }
            else if (mode == "7") {
                jeu8.regle_base(grille1, g);
                jeu8.dessin_rectangle(window, g);
                sleep(milliseconds(50));
            }
            else if (mode == "8") {
                jeu9.regle_base(grille1, g);
                jeu9.dessin_rectangle(window, g);
                sleep(milliseconds(50));
            }
        }
    }
    return 0;
};