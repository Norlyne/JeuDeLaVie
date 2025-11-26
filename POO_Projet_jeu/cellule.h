
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
	virtual bool is_alive() = 0;
	virtual void dessiner(sf::RenderWindow& window, int x, int y) = 0;
};



class cellule_morte : public cellule {
public:
	//Constructor
	cellule_morte();
	cellule_morte(int cellsize);
	~cellule_morte();


	//methodes
	bool is_alive() override { return false; }

	void dessiner(sf::RenderWindow& window, int x, int y) override {
		RectangleShape cell(Vector2f(this->cellsize - 1.0f, this->cellsize - 1.0f));
		cell.setPosition(x * this->cellsize, y * this->cellsize);
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
	bool is_alive() override { return true; }

	void dessiner(sf::RenderWindow& window, int x, int y) override {
		RectangleShape cell(Vector2f(this->cellsize - 1.0f, this->cellsize - 1.0f));
		cell.setPosition(x * this->cellsize, y * this->cellsize);
		cell.setFillColor(Color(255, 255, 255));
		window.draw(cell);
	}
};