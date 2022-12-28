//
// Created by Vlad Bogdan on 29.12.2022.
//

#ifndef MAIN_CPP_SUDOKU_6X6_H
#define MAIN_CPP_SUDOKU_6X6_H
#include "Grid.h"

class Sudoku_6x6 : public Grid {
public:
    // explicit Sudoku_9x9(const std::array<std::array<int, 9>, 9> &grid) : Grid(grid) {}
    void initializeGrid_() override;
    void afisare(std::ostream &os) override;
    std::shared_ptr<Grid> clone() const override;
private:
    int NumInRow_(int r_, int num_) const override;
    int NumInCol_(int c_, int num_) const override;
    int NumInSquare_(int ls_, int cs_, int num_) const override;
    int findEmpty_(int &r, int &c) const override;
    int ok_(int r_, int c_, int num_) const override;
    int solve_() override;
};


#endif //MAIN_CPP_SUDOKU_6X6_H