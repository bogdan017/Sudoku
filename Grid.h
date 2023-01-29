//
// Created by Vlad Bogdan on 29.12.2022.
//

#ifndef MAIN_CPP_GRID_H
#define MAIN_CPP_GRID_H
#include <iostream>
#include <array>
#include <memory>

class Grid {

public:
    virtual ~Grid() = default;
   // virtual std::shared_ptr<Grid> clone() = 0;
    Grid();
    int NumInRow(int r, int num) const { return NumInRow_(r, num); };
    int NumInCol(int c, int num) const { return NumInCol_(c, num); };
    int NumInSquare(int ls, int cs, int num) const { return NumInSquare_(ls, cs, num); };
    int findEmpty(int &r, int &c) const { return findEmpty_(r, c); };
    int ok(int r, int c, int num) const { return ok_(r, c, num); };
    int solve() {return solve_();};
    friend std::ostream &operator<<(std::ostream &os, const Grid& g);
    friend std::istream &operator>>(std::istream &is, Grid &g);
    virtual std::istream &citire(std::istream &is);
    virtual std::ostream &afisare(std::ostream &os) const;

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
};


#endif //MAIN_CPP_GRID_H
