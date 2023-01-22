//
// Created by Vlad Bogdan on 20.01.2023.
//

#ifndef GRID_6X6_CPP_MENIU_H
#define GRID_6X6_CPP_MENIU_H

#include <iostream>
#include <vector>
#include <array>
#include "Grid_6x6.h"
#include "Player.h"
#include "Grid_9x9.h"
#include "Grid.h"
#include "Sudoku.h"

class Meniu {
private:
    static Meniu *meniu;
    int optiune;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Sudoku>> sudoku;
    void arataOptiuni();
public:
    explicit Meniu(int optiune);
    static Meniu *getMeniu();
    void afisareSudoku();
    void adaugareSudoku();
    void leaderboard();
    void showMenu();
};



#endif //GRID_6X6_CPP_MENIU_H
