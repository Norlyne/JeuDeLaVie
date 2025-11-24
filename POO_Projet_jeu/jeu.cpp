#include "Jeu.h"
using namespace std;

// method 
void Jeu::initializeGrid() {
	string filename;
	cout << "Entrez le nom du fichier a ouvrir : (exemple: ficher.txt)" << endl;
	cin >> filename;
	ifstream filenam;
	filenam.open(filename, ios::in);  // on ouvre le fichier en lecture
	if (filenam) { // si l'ouverture a réussi
		char caractere;
		while (filenam.get(caractere)) // on lit le fichier tant qu'on ne dépasse pas la fin
		{
			int entier1, entier2;
			filenam >> entier1 >> entier2;
			grille = new Grille(entier1, entier2);


			filenam.close();
		}
	}
	else {
		cerr << "Erreur : fichier introuvable !" << endl;
	}
};

void Jeu::reglebase() {
	// copie temporaire
	vector<vector<cell*>> grid = grille->get_grid();
	vector<vector<cell*>> next = grid;
	for (int x = 0; x < grille->get_widht(); ++x) {
		for (int y = 0; y < grille->get_height(); ++y) {
			int n = countvoisin(x, y);
			if (grid[x][y]->get_state() == 1) {
				// cellule vivante
				if (n < 2 || n > 3) {
					next[x][y]->set_state(0);// meurt
				}
				else {
					next[x][y]->set_state(1); // survit
				}
			}
			else {
				// cellule morte
				if (n == 3) next[x][y]->set_state(1); // naissance
				else next[x][y]->set_state(0);
			}
		}
	}
	grid.swap(next); // met à jour la grille courante
}
