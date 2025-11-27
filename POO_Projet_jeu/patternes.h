#pragma once
class pattern
{
private:
	int numero;
	int x;
	int y;


public:
	//contructor
	pattern();
	pattern(int x, int y, int numero);


	//getters
	int get_x();
	int get_y();
	int get_numero();

	//setters
	void set_x(int x);
	void set_y(int y);
	void set_numero(int numero);


	//methodes
	void selection_pattern();
	void coordonnees_souris();
	void poser_pattern();
	void poser_point();
};


