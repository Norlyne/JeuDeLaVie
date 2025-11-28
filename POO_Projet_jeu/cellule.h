
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace sf;

class cellule
{
protected:
	int cellsize;

public:
	//Constructor
	cellule();
	cellule(int cellsize);
	virtual ~cellule() = default;

	//getters
	int get_cellsize();

	//setters
	void set_cellsize(int cellsize);

	//methodes
	virtual int is_alive() = 0;
	virtual void dessiner(sf::RenderWindow& window, int x, int y) = 0;
};



class cellule_morte : public cellule {
public:
	//Constructor
	cellule_morte();
	cellule_morte(int cellsize);
	~cellule_morte();


	//methodes
	int is_alive() override { return 0; }

	void dessiner(sf::RenderWindow& window, int x, int y) override {
		RectangleShape cell(Vector2f(this->cellsize - 1.0f, this->cellsize - 1.0f));
		cell.setPosition(x * float(this->cellsize), y * float(this->cellsize));
		cell.setFillColor(Color(0, 0, 0));
		window.draw(cell);
	}
};


class cellule_vivante : public cellule {
public:
	//Constructor
	cellule_vivante();
	cellule_vivante(int cellsize);
	~cellule_vivante();

	//methodes
	int is_alive() override { return 1; }

	void dessiner(sf::RenderWindow& window, int x, int y) override {
		RectangleShape cell(Vector2f(this->cellsize - 1.0f, this->cellsize - 1.0f));
		cell.setPosition(x * this->cellsize, y * this->cellsize);
		cell.setFillColor(Color(255, 255, 255));
		window.draw(cell);
	}
};

class cellule_obstacle : public cellule {
public:
	//Constructor
	cellule_obstacle();
	cellule_obstacle(int cellsize);
	~cellule_obstacle();


	//methodes
	int is_alive() override { return 2; }

	void dessiner(sf::RenderWindow& window, int x, int y) override {
		RectangleShape cell(Vector2f(this->cellsize - 1.0f, this->cellsize - 1.0f));
		cell.setPosition(x * this->cellsize, y * this->cellsize);
		cell.setFillColor(sf::Color(128, 128, 128));
		window.draw(cell);
	}
};