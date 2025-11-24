#pragma once
#include <SFML/Graphics.hpp>
class cell
{
protected:
	bool state; // peut etre pas besoin puisqu'on ne crée qu'un seul objet
	int cellSize;

public:
	//Constructor
	cell();
	cell(bool state);

	//getters
	bool get_state();
	int get_cellSize();

	//setters
	void set_state(bool state);
	void set_cellSize(int cellSize);

	//methodes
	virtual void dessiner(sf::RenderWindow& window, int x, int y) = 0;
};



class dead_cell : public cell {
public:
	//Constructor
	dead_cell();
	dead_cell(sf::RenderWindow& window, int x, int y);
	

	//methodes
	void dessiner(sf::RenderWindow& window, int x, int y) override {
		sf::RectangleShape cell(sf::Vector2f(this->cellSize - 1.0f, this->cellSize - 1.0f));
		cell.setPosition(x * this->cellSize, y * this->cellSize);
		cell.setFillColor(sf::Color(0, 0, 0));
		window.draw(cell);
	}
};


class live_cell : public cell {
public:
	//Constructor
	live_cell();
	live_cell(sf::RenderWindow& window, int x, int y);

	//methodes
	void dessiner(sf::RenderWindow& window, int x, int y) override {
		sf::RectangleShape cell(sf::Vector2f(this->cellSize - 1.0f, this->cellSize - 1.0f));
		cell.setPosition(x * this->cellSize, y * this->cellSize);
		cell.setFillColor(sf::Color(255, 255, 255));
		window.draw(cell);
	}
};





