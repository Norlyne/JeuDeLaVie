#pragma once
class cell
{
protected:
	int x;
	int y;
	bool state;

public:
	//Constructor
	cell();
	cell(int x, int y, bool state);

	//getters
	int getx();
	int gety();
	bool get_state();

	//setters
	void setx(int x);
	void sety(int y);
	void set_state(bool state);

	//methodes
	virtual void set_color() = 0;
};



class dead_cell : cell {
private:



public:
	//Constructor
	dead_cell();

	//methodes
	void set_color() override {

	}
};


class live_cell : cell {
private:


public:
	//Constructor
	live_cell();

	//methodes
	void set_color() override {

	}
};



