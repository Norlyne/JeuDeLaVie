//commentaire
#pragma once
#include "grille.h"

class pattern {
protected:
    int x;
    int y;
    int x2;
    int y2;

public:
    //contructor
    pattern();
    pattern(int x, int y, cellule* cell);

    //getters
    int get_x();
    int get_y();
    int get_x2();
    int get_y2();

    //setters
    void set_x(int x);
    void set_y(int y);
    void set_x2(int x2);
    void set_y2(int y2);

    //methodes
    virtual void poser(int x, int y, grille& current_grid) = 0;
    void random(grille& current_grid);
    void random_obs(grille& current_grid);
    void reset(grille& current_grid);
};


class point : public pattern {
public:
    point();
    point(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2, y2, 1);
    }
};


class stable1 : public pattern {
public:
    stable1();
    stable1(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2, y2, 1);
        current_grid.set_grille(x2, y2 + 1, 1);
        current_grid.set_grille(x2 + 1, y2, 1);
        current_grid.set_grille(x2 + 1, y2 + 1, 1);
    }
};

class stable2 : public pattern {
public:
    stable2();
    stable2(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2, y2 + 1, 1);
        current_grid.set_grille(x2 + 1, y2 + 1, 1);
        current_grid.set_grille(x2, y2 - 1, 1);
        current_grid.set_grille(x2 + 1, y2 - 1, 1);
        current_grid.set_grille(x2 - 1, y2, 1);
        current_grid.set_grille(x2 + 2, y2, 1);
    }
};

class glider : public pattern {
public:
    glider();
    glider(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2, y2 + 1, 1);
        current_grid.set_grille(x2 + 1, y2, 1);
        current_grid.set_grille(x2, y2 - 1, 1);
        current_grid.set_grille(x2 - 1, y2 - 1, 1);
        current_grid.set_grille(x2 + 1, y2 - 1, 1);
    }
};

class oscilateur1 : public pattern {
public:
    oscilateur1();
    oscilateur1(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2, y2, 1);
        current_grid.set_grille(x2 + 1, y2, 1);
        current_grid.set_grille(x2 - 1, y2, 1);
    }
};

class oscilateur2 : public pattern {
public:
    oscilateur2();
    oscilateur2(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2, y2, 1);
        current_grid.set_grille(x2, y2 + 1, 1);
        current_grid.set_grille(x2 + 1, y2, 1);
        current_grid.set_grille(x2 + 1, y2 + 1, 1);
        current_grid.set_grille(x2 - 1, y2, 1);
        current_grid.set_grille(x2 + 2, y2 + 1, 1);
    }
};

class canon_glider : public pattern {
public:
    canon_glider();
    canon_glider(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2 + 1, y2 + 5, 1);
        current_grid.set_grille(x2 + 1, y2 + 6, 1);
        current_grid.set_grille(x2 + 2, y2 + 5, 1);
        current_grid.set_grille(x2 + 2, y2 + 6, 1);
        current_grid.set_grille(x2 + 11, y2 + 5, 1);
        current_grid.set_grille(x2 + 11, y2 + 6, 1);
        current_grid.set_grille(x2 + 11, y2 + 7, 1);
        current_grid.set_grille(x2 + 12, y2 + 4, 1);
        current_grid.set_grille(x2 + 12, y2 + 8, 1);
        current_grid.set_grille(x2 + 13, y2 + 3, 1);
        current_grid.set_grille(x2 + 13, y2 + 9, 1);
        current_grid.set_grille(x2 + 14, y2 + 3, 1);
        current_grid.set_grille(x2 + 14, y2 + 9, 1);
        current_grid.set_grille(x2 + 15, y2 + 6, 1);
        current_grid.set_grille(x2 + 16, y2 + 4, 1);
        current_grid.set_grille(x2 + 16, y2 + 8, 1);
        current_grid.set_grille(x2 + 17, y2 + 5, 1);
        current_grid.set_grille(x2 + 17, y2 + 6, 1);
        current_grid.set_grille(x2 + 17, y2 + 7, 1);
        current_grid.set_grille(x2 + 18, y2 + 6, 1);
        current_grid.set_grille(x2 + 21, y2 + 3, 1);
        current_grid.set_grille(x2 + 21, y2 + 4, 1);
        current_grid.set_grille(x2 + 21, y2 + 5, 1);
        current_grid.set_grille(x2 + 22, y2 + 3, 1);
        current_grid.set_grille(x2 + 22, y2 + 4, 1);
        current_grid.set_grille(x2 + 22, y2 + 5, 1);
        current_grid.set_grille(x2 + 23, y2 + 2, 1);
        current_grid.set_grille(x2 + 23, y2 + 6, 1);
        current_grid.set_grille(x2 + 25, y2 + 1, 1);
        current_grid.set_grille(x2 + 25, y2 + 2, 1);
        current_grid.set_grille(x2 + 25, y2 + 6, 1);
        current_grid.set_grille(x2 + 25, y2 + 7, 1);
        current_grid.set_grille(x2 + 35, y2 + 3, 1);
        current_grid.set_grille(x2 + 35, y2 + 4, 1);
        current_grid.set_grille(x2 + 36, y2 + 3, 1);
        current_grid.set_grille(x2 + 36, y2 + 4, 1);
    }
};

class obstacle : public pattern {
public:
    obstacle();
    obstacle(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2, y2, 2);
    }
};
