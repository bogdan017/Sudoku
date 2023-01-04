//
// Created by Vlad Bogdan on 29.12.2022.
//

#include "Grid.h"

int Grid::solve() { return solve_(); }

std::ostream &operator<<(std::ostream &os, const Grid &g) {
    for (int i = 0; i < g.lines; ++i) {
        for (int j = 0; j < g.cols; ++j) {
            os << g.grid[i][j] << " ";
        }
        os << "\n";
    }
    //g.afisare(os);
    return os;
}

Grid::Grid() {
    this->lines = 0;
    this->cols = 0;
}

Grid::Grid(const int lines, const int cols) {
    this->lines = lines;
    this->cols = cols;

}
