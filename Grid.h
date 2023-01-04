//
// Created by Vlad Bogdan on 29.12.2022.
//

#ifndef MAIN_CPP_GRID_H
#define MAIN_CPP_GRID_H
#include <iostream>
#include <array>
#include <memory>

class Grid {
/*public:
    Grid() {
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                grid[i][j] = 0;
            }
        }
        std::cout << "Constructor de initializare grid\n";
    }
    void initializeGrid() {
        char ch = 'y';
        while (ch == 'y') {
            std::cout << "Introduceti linia, coloana si valoarea corespunzatoare celulei alese: \n";
            int r, c, val;
            std::cin >> r;
            std::cin >> c;
            std::cin >> val;
            if ((r < 0 || r > 8) && (c < 0 || c > 8) && (val < 0 || val > 8)) {
                std::cout << "Matricea este invalida\n";
                break;
            } else {
                grid[r][c] = val;
            }
            std::cout << "Mai poti introduce o valoare sau apasa n pentru a te opri: \n";
            std::cin >> ch;
        }
    }
    int NumInRow(int r, int num) {
        for (int i = 0; i < 9; ++i) {
            if (num != 0 && grid[r][i] == num) {
                return 1;
            }
        }
        return 0;
    }
    int NumInCol(int c, int num) {
        for (int i = 0; i < 9; ++i) {
            if (num != 0 && grid[i][c] == num) {
                return 1;
            }
        }
        return 0;
    }
    int NumInSquare(int ls, int cs, int num) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i + ls][j + cs] == num) {
                    return 1;
                }
            }
        }
        return 0;
    }
    int findEmpty(int &r, int &c) {
        for (r = 0; r < 9; ++r) {
            for (c = 0; c < 9; ++c) {
                if (grid[r][c] == 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    int ok(int r, int c, int num) {
        if (!NumInRow(r, num)) {
            if (!NumInCol(c, num)) {
                int line_sq = r - r % 3;
                int col_sq = c - c % 3;
                if (!NumInSquare(line_sq, col_sq, num)) {
                    return 1;
                }
            }
        }
        for (int i = 0 ; i < 9; ++i) {
            if (grid[i][i] == num) {
                return 1;
            }
        }
        int line = 0;
        for (int i = 8; i >= 0; --i) {
            if (grid[line][i] == num) {
                ++line;
                return 1;
            }
        }
        return 0;
    }
    int solve() {
        int r, c;
        if (findEmpty(r, c)) {
            for (int num = 1; num <= 9; ++num) {
                if (ok(r, c, num)) {
                    grid[r][c] = num;
                    if (solve()) {
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
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Grid& g) {
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                os << g.grid[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    };*/
public:
    virtual ~Grid() = default;
    virtual std::shared_ptr<Grid> clone() const = 0;
    Grid();
    Grid(const int lines, const int cols);
    //void initializeGrid() {}
    [[maybe_unused]] int NumInRow(int r, int num) const;

    [[maybe_unused]] int NumInCol(int c, int num) const;

    [[maybe_unused]] int NumInSquare(int ls, int cs, int num) const;

    [[maybe_unused]] int findEmpty(int &r, int &c) const;

    [[maybe_unused]] int ok(int r, int c, int num) const;
    int solve();

    friend std::ostream& operator<<(std::ostream & os, const Grid& g);

protected:
    Grid(const Grid &other) = default;
    Grid &operator=(const Grid &other) = default;
    std::array<std::array<int, 9>, 9> grid;
    int lines, cols;

private:
    virtual int NumInRow_(int r_, int num_) const = 0;
    virtual int NumInCol_(int c_, int num_) const = 0;
    virtual int NumInSquare_(int ls_, int cs_, int num_) const = 0;
    virtual int findEmpty_(int &r_, int &c) const = 0;
    virtual int ok_(int r_, int c_, int num_) const = 0;
    virtual int solve_() = 0;
    virtual void afisare(std::ostream &) = 0;
};


#endif //MAIN_CPP_GRID_H
