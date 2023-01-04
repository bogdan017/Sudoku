//
// Created by Vlad Bogdan on 29.12.2022.
//

#include "Sudoku_9x9.h"

std::shared_ptr<Grid> Sudoku_9x9::clone() const { return std::make_shared<Sudoku_9x9>(*this); }

void Sudoku_9x9::initializeGrid_() {
    lines = 9;
    cols = 9;
    for(int i = 0; i < this->lines; i++){
        for (int j = 0; j < this->cols; ++j) {
            grid[i][j] = 0;
        }
    }
    int r, c, val;
    char ch = 'y';
    std::cout << "Initializare Sudoku 9x9:\n";
    while (ch == 'y') {
        std::cout << "Introduceti linia, coloana si valoarea corespunzatoare celulei alese: \n";
        std::cin >> r;
        std::cin >> c;
        std::cin >> val;
        if ((r < 0 || r > 8) && (c < 0 || c > 8) && (val < 1 || val > 9)) {
            std::cout << "Matricea este invalida\n";
            break;
        } else {
            grid[r][c] = val;
        }
        std::cout << "Mai poti introduce o valoare sau apasa n pentru a te opri: \n";
        std::cin >> ch;
    }
}


int Sudoku_9x9::NumInRow_(int r_, int num_) const {
    for (int i = 0; i < 9; ++i) {
        if (num_ != 0 && grid[r_][i] == num_) {
            return 1;
        }
    }
    return 0;
}

int Sudoku_9x9::NumInCol_(int c_, int num_) const {
    for (int i = 0; i < 9; ++i) {
        if (num_ != 0 && grid[i][c_] == num_) {
            return 1;
        }
    }
    return 0;
}

int Sudoku_9x9::NumInSquare_(int ls_, int cs_, int num_) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + ls_][j + cs_] == num_) {
                return 1;
            }
        }
    }
    return 0;
}

int Sudoku_9x9::findEmpty_(int &r, int &c) const {
    for (r = 0; r < 9; ++r) {
        for (c = 0; c < 9; ++c) {
            if (grid[r][c] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int Sudoku_9x9::ok_(int r_, int c_, int num_) const {
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

int Sudoku_9x9::solve_() {
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




