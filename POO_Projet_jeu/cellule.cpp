#include "cellule.h"

//Constructors
cellule::cellule() { this->cellsize = 10; }
cellule::cellule(int cellsize) { this->cellsize = cellsize; }

cellule_morte::cellule_morte() { this->cellsize = 10; }
cellule_morte::cellule_morte(int cellsize) { this->cellsize = cellsize; }

cellule_vivante::cellule_vivante() { this->cellsize = 10; }
cellule_vivante::cellule_vivante(int cellsize) { this->cellsize = cellsize; }

cellule_morte::~cellule_morte() {}
cellule_vivante::~cellule_vivante() {}


//getters
int cellule::get_cellsize() { return this->cellsize; }



//setters
void cellule::set_cellsize(int cellsize) { this->cellsize = cellsize; }