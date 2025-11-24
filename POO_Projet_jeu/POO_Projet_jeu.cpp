#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

const int cellSize = 9;
const int gridWidth = 100;
const int gridHeight = 100;

std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));

void initializeGrid() {
    std::srand(std::time(0));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
};

void renderGrid(sf::RenderWindow& window) {
    int x, y;

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if (grid[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

// Ajoute ceci (par ex. avant main)
int countNeighbors(int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            // gestion des bords: ignore les voisins hors grille
            if (nx >= 0 && nx < gridWidth && ny >= 0 && ny < gridHeight) {
                count += grid[nx][ny];
            }
        }
    }
    return count;
}

void updateGrid() {
    // copie temporaire
    std::vector<std::vector<int>> next = grid;
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            int n = countNeighbors(x, y);
            if (grid[x][y] == 1) {
                // cellule vivante
                if (n < 2 || n > 3) next[x][y] = 0; // meurt
                else next[x][y] = 1; // survit
            }
            else {
                // cellule morte
                if (n == 3) next[x][y] = 1; // naissance
                else next[x][y] = 0;
            }
        }
    }
    grid.swap(next); // met à jour la grille courante
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main() {
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Jeu de la vie");

    initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        updateGrid();
        renderGrid(window);

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
};*/