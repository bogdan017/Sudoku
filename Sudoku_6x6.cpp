//
// Created by Vlad Bogdan on 29.12.2022.
//

#include "Sudoku_6x6.h"

std::shared_ptr<Grid> Sudoku_6x6::clone() const { return std::make_shared<Sudoku_6x6>(*this); }


void Sudoku_6x6::initializeGrid() {
    this->lines = 6;
    this->cols = 6;
    int r, c, val;
    char ch = 'y';
    std::cout << "Initializare sudoku 6x6\n";
    while (ch == 'y') {
        std::cout << "Introduceti linia, coloana si valoarea corespunzatoare celulei alese: \n";
        std::cin >> r;
        std::cin >> c;
        std::cin >> val;
        if ((r < 0 || r > 5) && (c < 0 || c > 5) && (val < 0 || val > 5)) {
            std::cout << "Matricea este invalida\n";
            break;
        } else {
            grid[r][c] = val;
        }
        std::cout << "Mai poti introduce o valoare sau apasa n pentru a te opri: \n";
        std::cin >> ch;
    }
}

void Sudoku_6x6::afisare(std::ostream &os) {
    for (size_t i = 0; i < 6; ++i) {
        for (size_t j = 0; j < 6; ++j) {
            os << grid[i][j] << " ";
        }
        os << "\n";
    }
}

int Sudoku_6x6::NumInRow_(int r_, int num_) const {
    for (int i = 0; i < 6; ++i) {
        if (num_ != 0 && grid[r_][i] == num_) {
            return 1;
        }
    }
    return 0;
}

int Sudoku_6x6::NumInCol_(int c_, int num_) const {
    for (int i = 0; i < 6; ++i) {
        if (num_ != 0 && grid[i][c_] == num_) {
            return 1;
        }
    }
    return 0;
}

int Sudoku_6x6::NumInSquare_(int ls_, int cs_, int num_) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + ls_][j + cs_] == num_) {
                return 1;
            }
        }
    }
    return 0;
}

int Sudoku_6x6::findEmpty_(int &r, int &c) const {
    for (r = 0; r < 6; ++r) {
        for (c = 0; c < 6; ++c) {
            if (grid[r][c] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int Sudoku_6x6::ok_(int r_, int c_, int num_) const {
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

int Sudoku_6x6::solve_() {
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

