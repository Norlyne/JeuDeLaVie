//commentaire
#include <ctime>
#include <iostream>
#include <fstream>
#include <fontsub.h>
#include "cellule.h"
#include "grille.h"
#include "jeu.h"
#include "patternes.h"

int jeu::indexe = 0;
string jeu::mode_depart = "1";
grille jeu::current_grid = grille();
grille jeu::next_grid = grille();

int main()
{
    srand(time(0));

    jeu* jeu;
    jeu = new ModeNormal();

    pattern* pat;
    pat = new point;
    
    sf::Vector2i pixelPos;

    string nom_Dossier = "";
    string nomFichier = "";

    jeu->demarer(nom_Dossier);

    cout << jeu->get_mode_depart() << endl;
    if (jeu->get_mode_depart() == 1) { delete jeu; jeu = new ModeNormal; }
    else if (jeu->get_mode_depart() == 2) { delete jeu; jeu = new ModeLifeIsShort; }
    else if (jeu->get_mode_depart() == 3) { delete jeu; jeu = new ModeDayAndLight; }
    else if (jeu->get_mode_depart() == 4) { delete jeu; jeu = new labyrinthiques; }
    else if (jeu->get_mode_depart() == 5) { delete jeu; jeu = new ExplosionsAndChaos; }
    else if (jeu->get_mode_depart() == 6) { delete jeu; jeu = new MotifsRepliquants; }
    else if (jeu->get_mode_depart() == 7) { delete jeu; jeu = new HighLife; }
    else if (jeu->get_mode_depart() == 8) { delete jeu; jeu = new Corail; }
    else { return 1; }



    
    
  

    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              CONSOLE                                              //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //for (int i = 0; i < 5; i++) {

    //    nomFichier = nom_Dossier + "/iteration" + to_string(i) + ".txt";
    //    std::ofstream fichier(nomFichier, ios::out);

    //    for (int dx = 0; dx < jeu->get_current_grid().get_width(); dx++) {
    //        for (int dy = 0; dy < jeu->get_current_grid().get_height(); dy++) {
    //            cellule* d = jeu->get_current_grid().get_grille(dx, dy);//////////////////
    //            if (d && d->is_alive() == 2) {
    //                cout << "O";
    //                fichier << 2 << " ";
    //            }
    //            if (d && d->is_alive() == 1) {
    //                cout << "#";
    //                fichier << 1 << " ";
    //            }
    //            else {
    //                cout << ".";
    //                fichier << 0 << " ";
    //            }
    //        }
    //        cout << "\n";
    //        fichier << endl;
    //    }
    //    jeu->regle_base();
    //    cout << "---------------------------------------------------------------------------------------" << endl;
    //    fichier.close();
    //    sleep(milliseconds(1000));

    //    
    //}
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              WINDOWS                                              //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    

    RenderWindow window(VideoMode(jeu->get_current_grid().get_width() * jeu->get_current_grid().get_grille(0, 0)->get_cellsize(), jeu->get_current_grid().get_height() * jeu->get_current_grid().get_grille(0, 0)->get_cellsize()), "Jeu de la vie");
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
                    pat = new point(0, 0, jeu->get_current_grid().get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num2) {
                    delete pat;
                    pat = new stable1(0, 0, jeu->get_current_grid().get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num3) {
                    delete pat;
                    pat = new stable2(0, 0, jeu->get_current_grid().get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num4) {
                    delete pat;
                    pat = new glider(0, 0, jeu->get_current_grid().get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num5) {
                    delete pat;
                    pat = new oscilateur1(0, 0, jeu->get_current_grid().get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num6) {
                    delete pat;
                    pat = new oscilateur2(0, 0, jeu->get_current_grid().get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num7) {
                    delete pat;
                    pat = new canon_glider(0, 0, jeu->get_current_grid().get_grille(0, 0));
                }

                if (event.key.code == Keyboard::Num0) {
                    delete pat;
                    pat = new obstacle(0, 0, jeu->get_current_grid().get_grille(0, 0));
                }

                if (event.key.code == Keyboard::A) {
                    pat->random(jeu->get_current_grid(), jeu->get_next_grid(), window);
                }

                if (event.key.code == Keyboard::O) {
                    pat->random_obs(jeu->get_current_grid(), jeu->get_next_grid(), window);
                }

                if (event.key.code == Keyboard::R) {
                    pat->reset(jeu->get_current_grid(), jeu->get_next_grid(), window);
                }

                if (event.key.code == Keyboard::N) {
                    delete jeu;
                    jeu = new ModeNormal(jeu->get_current_grid(), jeu->get_next_grid(), jeu->get_indexe());
                }

                if (event.key.code == Keyboard::S) {
                    delete jeu;
                    jeu = new ModeLifeIsShort(jeu->get_current_grid(), jeu->get_next_grid(), jeu->get_indexe());
                }

                if (event.key.code == Keyboard::D) {
                    delete jeu;
                    jeu = new ModeDayAndLight(jeu->get_current_grid(), jeu->get_next_grid(), jeu->get_indexe());
                }

                if (event.key.code == Keyboard::L) {
                    delete jeu;
                    jeu = new labyrinthiques(jeu->get_current_grid(), jeu->get_next_grid(), jeu->get_indexe());
                }

                if (event.key.code == Keyboard::E) {
                    delete jeu;
                    jeu = new ExplosionsAndChaos(jeu->get_current_grid(), jeu->get_next_grid(), jeu->get_indexe());
                }

                if (event.key.code == Keyboard::M) {
                    delete jeu;
                    jeu = new MotifsRepliquants(jeu->get_current_grid(), jeu->get_next_grid(), jeu->get_indexe());
                }

                if (event.key.code == Keyboard::H) {
                    delete jeu;
                    jeu = new HighLife(jeu->get_current_grid(), jeu->get_next_grid(), jeu->get_indexe());
                }

                if (event.key.code == Keyboard::C) {
                    delete jeu;
                    jeu = new Corail(jeu->get_current_grid(), jeu->get_next_grid(), jeu->get_indexe());
                }

                if (event.key.code == sf::Keyboard::Left) {
                    jeu->set_indexe(false);
                }

                if (event.key.code == sf::Keyboard::Right) {
                    jeu->set_indexe(true);
                }
            }

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    pixelPos = sf::Mouse::getPosition(window);
                    pat->set_x2(pixelPos.x / jeu->get_current_grid().get_grille(0,0)->get_cellsize());
                    pat->set_y2(pixelPos.y / jeu->get_current_grid().get_grille(0, 0)->get_cellsize());
                    pat->poser(pixelPos.x, pixelPos.y, jeu->get_current_grid(), jeu->get_next_grid(), window);
                    jeu->get_current_grid().get_grille(0, 0)->dessin_rectangle(window, jeu->get_current_grid());
                }
            }

        }

        if (!etat) {
            jeu->regle_base();
            jeu->get_current_grid().get_grille(0, 0)->dessin_rectangle(window, jeu->get_current_grid());
            sleep(milliseconds(jeu->get_attente()));
        }
    }
    return 0;
}












