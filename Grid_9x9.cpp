#include "Grid_9x9.h"

//std::shared_ptr<Grid> Grid_9x9::clone() { return std::make_shared<Grid_9x9>(); }


Grid_9x9::Grid_9x9() {
    this->lines = 9;
    this->cols = 9;
    for(int i = 0; i < lines; i++){
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = 0;
        }
    }
}

int Grid_9x9::NumInRow_(int r_, int num_) const {
    for (int i = 0; i < lines; ++i) {
        if (num_ != 0 && grid[r_][i] == num_) {
            return 1;
        }
    }
    return 0;
}

int Grid_9x9::NumInCol_(int c_, int num_) const {
    for (int i = 0; i < cols; ++i) {
        if (num_ != 0 && grid[i][c_] == num_) {
            return 1;
        }
    }
    return 0;
}

int Grid_9x9::NumInSquare_(int ls_, int cs_, int num_) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + ls_][j + cs_] == num_) {
                return 1;
            }
        }
    }
    return 0;
}

int Grid_9x9::findEmpty_(int &r, int &c) const {
    for (r = 0; r < lines; ++r) {
        for (c = 0; c < cols; ++c) {
            if (grid[r][c] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int Grid_9x9::ok_(int r_, int c_, int num_) const {
    if (!NumInRow_(r_, num_)) {
        if (!NumInCol_(c_, num_)) {
            int line_sq = r_ - r_ % 3;
            int col_sq = c_ - c_ % 3;
            if (!NumInSquare_(line_sq, col_sq, num_)) {
                return 1;
            }
        }
    }
    return 0;
}

int Grid_9x9::solve_() {
    int r, c;
    if (findEmpty_(r, c)) {
        for (int num = 1; num <= 9; ++num) {
            if (ok_(r, c, num)) {
                grid[r][c] = num;
                if (solve_()) {
                    return 1;
                }
                grid[r][c] = 0;
            }
        }
        return 0;
    } else {
        return 1;
    }
}

std::ostream &Grid_9x9::afisare(std::ostream &os) const {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < cols; ++j) {
            os << grid[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

std::istream &Grid_9x9::citire(std::istream &is) {
    std::cout << "Initializare Sudoku 9x9:\n";
    try {
        Grid::citire(is);
    } catch(eroare_sudoku &err) {
        std::cout<<err.what()<<std::endl;
    }
    return is;
}






