#pragma once
class cell
{
protected:
	int x;
	int y;


public:
	//Constructor
	cell();

	//getters
	int getx();
	int gety();

	//setters
	void setx();
	void sety();

	//methodes
	virtual void set_color() = 0;
};



class dead_cell : cell {
private:
	bool state;


public:
	//Constructor
	dead_cell();

	//getter
	bool get_state();

	//setters
	void set_state(bool state);

	//methodes
	void set_color() override {

	}
};


class live_cell : cell {
private:
	bool state;


public:
	//Constructor
	live_cell();

	//getters
	bool get_state();

	//setters
	void set_state(bool state);

	//methodes
	void color() override {

	}
};





