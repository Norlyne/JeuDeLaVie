#include "Jeu.h"
#include "Grille.h"
#include "cell.h"

int  main() {
	Grille g;
	Jeu jdv(g);
	jdv.initializeGrid();
	jdv.reglebase();
	return 0;
}