#include "Grid_6x6.h"

//std::shared_ptr<Grid> Grid_6x6::clone() { return std::make_shared<Grid_6x6>(); }

Grid_6x6::Grid_6x6() {
    this->lines = 6;
    this->cols = 6;
    for(int i = 0; i < lines; i++){
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = 0;
        }
    }
}



int Grid_6x6::NumInRow_(int r_, int num_) const {
    for (int i = 0; i < lines; ++i) {
        if (num_ != 0 && grid[r_][i] == num_) {
            return 1;
        }
    }
    return 0;
}

int Grid_6x6::NumInCol_(int c_, int num_) const {
    for (int i = 0; i < cols; ++i) {
        if (num_ != 0 && grid[i][c_] == num_) {
            return 1;
        }
    }
    return 0;
}

int Grid_6x6::NumInSquare_(int ls_, int cs_, int num_) const {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + ls_][j + cs_] == num_) {
                return 1;
            }
        }
    }
    return 0;
}

int Grid_6x6::findEmpty_(int &r, int &c) const {
    for (r = 0; r < lines; ++r) {
        for (c = 0; c < cols; ++c) {
            if (grid[r][c] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int Grid_6x6::ok_(int r_, int c_, int num_) const {
    if (!NumInRow_(r_, num_)) {
        if (!NumInCol_(c_, num_)) {
            int line_sq = 2 * (r_ / 2);
            int col_sq = 3 * (c_ / 3);
            if (!NumInSquare_(line_sq, col_sq, num_)) {
                return 1;
            }
        }
    }
    return 0;
}

int Grid_6x6::solve_() {
    int r, c;
    if (findEmpty_(r, c)) {
        for (int num = 1; num <= 6; ++num) {
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

std::istream &Grid_6x6::citire(std::istream &is) {
    try {
        int r, c, val;
        char ch = 'y';
        std::cout << "Initializare sudoku 6x6\n";
        while (ch == 'y') {
            std::cout << "Introduceti linia, coloana si valoarea corespunzatoare celulei alese: \n";
            is >> r;
            is >> c;
            is >> val;
            if (r < 0 || r > 5) {
                throw (eroare_sudoku(r, c, val));
            } else if (c < 0 || c > 5) {
                throw (eroare_sudoku(r, c, val));
            } else if (val < 1 || val > 6) {
                throw (eroare_sudoku(r, c, val));
            } else {
                grid[r][c] = val;
            }
            std::cout << "Mai poti introduce o valoare sau apasa n pentru a te opri: \n";
            is >> ch;
        }
    } catch(eroare_sudoku &err) {
        std::cout<<err.what()<<std::endl;
    }
    return is;
}

std::ostream &Grid_6x6::afisare(std::ostream &os) const {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < cols; ++j) {
            os << grid[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

