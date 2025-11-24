#include "Jeu.h"
using namespace std;

// method 
void Jeu::initializeGrid() {
	string name;
	cout << "Entrez le nom du fichier a ouvrir : (exemple: ficher.txt)" << endl;
	cin >> name;
	ifstream filenam;
	filenam.open(name, ios::in);  // on ouvre le fichier en lecture
	if (filenam) { // si l'ouverture a réussi
		char caractere;
		while (filenam.get(caractere)) // on lit le fichier tant qu'on ne dépasse pas la fin
		{
			int entier1, entier2;
			string ligne;
			filenam >> entier1 >> entier2;
			grille = new Grille(entier1, entier2);
			getline(filenam, ligne);
			for (int i = 0; i < entier1; i++) {
				for (int y = 0; y < entier2; y++) {
					if (filenam >> caractere) {
						///
					}
				}
			}


			filenam.close();
		}
	}
	else {
		cerr << "Erreur : fichier introuvable !" << endl;
	}
};

int Jeu::countvoisin(int x, int y) {
	int count = 0;
	vector<vector<cell*>> grid = grille->get_grid();
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx == 0 && dy == 0) continue;
			int nx = x + dx;
			int ny = y + dy;
			// gestion des bords: ignore les voisins hors grille
			if (nx >= 0 && nx < grille->get_widht() && ny >= 0 && ny < grille->get_height()) {
				if (grid[nx][ny]->get_state() == 1) {
					count++;
				}
			}
		}
	}
	return count;
};

void Jeu::initializerandom() {
	std::srand(std::time(0));
	vector<vector<cell*>> grid = grille->get_grid();
	for (int x = 0; x < grille->get_widht(); ++x) {
		for (int y = 0; y < grille->get_height(); ++y) {
			grid[x][y]->set_state(std::rand() % 2);  // Randomly initialize cells as alive or dead
		}
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
					next[x][y] = new dead_cell();// meurt
				}
				else {
					next[x][y] = new live_cell(); // survit
				}
			}
			else {
				// cellule morte
				if (n == 3) next[x][y] = new live_cell(); // naissance
				else next[x][y] = new dead_cell();
			}
		}
	}
	grid.swap(next); // met à jour la grille courante
};
