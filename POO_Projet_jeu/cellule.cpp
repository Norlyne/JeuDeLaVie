//commentaire
#include "cellule.h"
#include "jeu.h"
#include "string"

//Constructors
cellule::cellule() { this->cellsize = 10; }
cellule::cellule(int cellsize) { this->cellsize = cellsize; }

cellule_morte::cellule_morte() { this->cellsize = 10; }
cellule_morte::cellule_morte(int cellsize) { this->cellsize = cellsize; }

cellule_vivante::cellule_vivante() { this->cellsize = 10; }
cellule_vivante::cellule_vivante(int cellsize) { this->cellsize = cellsize; }

cellule_obstacle::cellule_obstacle() { this->cellsize = 10; }
cellule_obstacle::cellule_obstacle(int cellsize) { this->cellsize = cellsize; }

cellule_morte::~cellule_morte() {}
cellule_vivante::~cellule_vivante() {}
cellule_obstacle::~cellule_obstacle() {}


//getters
int cellule::get_cellsize() { return this->cellsize; }



//setters
void cellule::set_cellsize(int cellsize) { this->cellsize = cellsize; }

//methodes

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
void cellule::dessin_instantané(string mode, RenderWindow& window, grille grid, ModeNormal ModeNormal, ModeLifeIsShort ModeLifeIsShort, ModeDayAndLight ModeDayAndLight, labyrinthiques labyrinthiques, ExplosionsAndChaos ExplosionsAndChaos, MotifsRepliquants MotifsRepliquants, HighLife HighLife, Corail Corail) {
	if (mode == "1") { ModeNormal.dessin_rectangle(window, grid); }
	if (mode == "2") { ModeLifeIsShort.dessin_rectangle(window, grid); }
	if (mode == "3") { ModeDayAndLight.dessin_rectangle(window, grid); }
	if (mode == "4") { labyrinthiques.dessin_rectangle(window, grid); }
	if (mode == "5") { ExplosionsAndChaos.dessin_rectangle(window, grid); }
	if (mode == "6") { MotifsRepliquants.dessin_rectangle(window, grid); }
	if (mode == "7") { HighLife.dessin_rectangle(window, grid); }
	if (mode == "8") { Corail.dessin_rectangle(window, grid); }
}
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////