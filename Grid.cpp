//
// Created by Vlad Bogdan on 29.12.2022.
//

#include "Grid.h"

int Grid::NumInRow(int r, int num) const { return NumInRow_(r, num); }

int Grid::NumInCol(int c, int num) const { return NumInCol_(c, num); }

int Grid::NumInSquare(int ls, int cs, int num) const { return NumInSquare_(ls, cs, num); }

int Grid::findEmpty(int &r, int &c) const { return findEmpty_(r, c); }

int Grid::ok(int r, int c, int num) const { return ok_(r, c, num); }

int Grid::solve() { return solve_(); }

std::ostream &operator<<(std::ostream &os, const Grid &g) {
    for (size_t i = 0; i < g.lines; ++i) {
        for (size_t j = 0; j < g.cols; ++j) {
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
