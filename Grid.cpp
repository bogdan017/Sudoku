#include "Grid.h"


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
    return is;
}

