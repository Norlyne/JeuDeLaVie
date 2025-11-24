#include "Jeu.h"
using namespace std;

// method 
void Jeu::initializeGrid() {
	string filename;
	cout << "Entrez le nom du fichier a ouvrir : (exemple: ficher.txt)" << endl;
	cin >> filename;
	ifstream filename;
	filename.open(filename, ios::in);  // on ouvre le fichier en lecture
	if (filename) { // si l'ouverture a réussi
		char caractere;
		while (filename.get(caractere)) // on lit le fichier tant qu'on ne dépasse pas la fin
		{
			filename.close();
		}
	}
	else {
		cerr << "Erreur : fichier introuvable !" << endl;
	}
	////////////////////////////////////////////////////////////////////////
	for (int x = 0; x < grille->get_widht(); ++x) {
		for (int y = 0; y < grille->get_height(); ++y) {
			if (grid[x][y] == 0) {// remplace par le numéro de fichier
				//= new live_cell()
			}
		}
	}
};