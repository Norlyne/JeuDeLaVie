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
    grille1.random_init();
    g.random_init();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              CONSOLE                                              //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    /*for (int i = 0; i < 5; i++) {
        for (int dx = 0; dx < g.get_width(); dx++) {
            for (int dy = 0; dy < g.get_height(); dy++) {
                cellule* d = g.get_grille(dx, dy);
                if (d && d->is_alive()) cout << "#";
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
            jeu4.regle_base(grille1, g);
            jeu4.dessin_rectangle(window, g);
            sleep(milliseconds(50));
        }
    }
    return 0;
};
