#ifndef MAIN_CPP_SUDOKU_6X6_H
#define MAIN_CPP_SUDOKU_6X6_H
#include "Grid.h"
#include <memory>
#include "exceptions.h"

class Grid_6x6 : public Grid {
public:
    Grid_6x6();
    void initializeGrid();
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
