//
// Created by Vlad Bogdan on 29.12.2022.
//

#ifndef MAIN_CPP_GRID_9X9_H
#define MAIN_CPP_GRID_9X9_H
#include "Grid.h"
#include <memory>
#include "exceptions.h"

class Grid_9x9 : public Grid {
public:
    void initializeGrid_();
    std::shared_ptr<Grid> clone() const override;
private:
    int NumInRow_(int r_, int num_) const override;
    int NumInCol_(int c_, int num_) const override;
    int NumInSquare_(int ls_, int cs_, int num_) const override;
    int findEmpty_(int &r, int &c) const override;
    int ok_(int r_, int c_, int num_) const override;
    int solve_() override;
    const int lines = 9, cols = 9;
};


#endif //MAIN_CPP_GRID_9X9_H
