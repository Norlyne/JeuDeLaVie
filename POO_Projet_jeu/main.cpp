#include <ctime>
#include <iostream>
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

    pattern pattern;
    sf::Vector2i pixelPos;

    string mode = "1";

    jeu2.demarer(g, grille1, mode);

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

                if (event.key.code == Keyboard::Num1)
                    pattern.set_numero(1);

                if (event.key.code == Keyboard::Num2)
                    pattern.set_numero(2);

                if (event.key.code == Keyboard::Num3)
                    pattern.set_numero(3);

                if (event.key.code == Keyboard::Num4)
                    pattern.set_numero(4);

                if (event.key.code == Keyboard::Num5)
                    pattern.set_numero(5);

                if (event.key.code == Keyboard::Num6)
                    pattern.set_numero(6);


                if (event.key.code == Keyboard::A) {
                    pattern.random(grille1, g, window);
                }

                if (event.key.code == Keyboard::R) {
                    pattern.reset(grille1, g, window);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    cout << "appuis" << endl;
                    pixelPos = sf::Mouse::getPosition(window);
                    cout << pixelPos.x << "   " << pixelPos.y << endl;
                    pattern.poser_pattern(pixelPos.x, pixelPos.y, g, grille1, window);
                    cout << g.get_grille(pixelPos.x / 10, pixelPos.y / 10)->is_alive() << endl;
                    cout << grille1.get_grille(pixelPos.x / 10, pixelPos.y / 10)->is_alive() << endl;
                    
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