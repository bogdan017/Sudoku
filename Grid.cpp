#include "Grid.h"
#include "exceptions.h"

std::ostream &operator<<(std::ostream &os, const Grid &g) {
    g.afisare(os);
    return os;
}

Grid::Grid() {
    Grid::lines = 9;
    Grid::cols = 9;
}

std::ostream & Grid::afisare(std::ostream &os) const {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < cols; ++j) {
            os << grid[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Grid &g) {
    g.citire(is);
    return is;
}

std::istream &Grid::citire(std::istream &is) {
    int r, c, val;
    char ch = 'y';
    std::cout << "Initializare joc Sudoku:\n";
    while (ch == 'y') {
        std::cout << "Introduceti linia, coloana si valoarea corespunzatoare celulei alese: \n";
        is >> r;
        is >> c;
        is >> val;
        if (r < 0 || r > lines) {
            throw (eroare_sudoku(r, c, val));
        } else if (c < 0 || c > lines) {
            throw (eroare_sudoku(r, c, val));
        } else if (val < 1 || val > lines) {
            throw (eroare_sudoku(r, c, val));
        } else {
            grid[r][c] = val;
        }
        std::cout << "Mai poti introduce o valoare sau apasa n pentru a te opri: \n";
        is >> ch;
    }
    return is;
}

