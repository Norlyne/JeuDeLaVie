#include <ctime>
#include <iostream>
#include "cellule.h"
#include "grille.h"
#include "jeu.h"

int main()
{
    std::srand(std::time(0));

    jeu jeu;
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
                if (d && d->is_alive()) std::cout << "#";
                else std::cout << ".";
            }
            std::cout << "\n";
        }
        jeu.regle_base(grille1, g);
        std::cout << "---------------------------------------------------------------------------------------" << std::endl;
        
    }*/
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              WINDOWS                                              //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode(grille1.get_width() * 10, grille1.get_height() * 10), "Jeu de la vie");
    window.clear(sf::Color(214, 214, 214));
    bool etat = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space){
                    etat = !etat;
                }
            }
        }
        if (!etat) {
            jeu.regle_base(grille1, g);
            jeu.dessin_rectangle(window, g);
            sf::sleep(sf::milliseconds(50));
        }
    }
    return 0;
};
