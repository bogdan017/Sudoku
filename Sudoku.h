//
// Created by Vlad Bogdan on 29.12.2022.
//

#ifndef MAIN_CPP_SUDOKU_H
#define MAIN_CPP_SUDOKU_H
#include "Grid.h"
#include "Player.h"
#include <memory>


class Sudoku {
    int id_game;
    std::vector<Player> players;
public:
    //constructor
    Sudoku(int id_game_);
    /*int GetId() const {
        return id_game;
    }*/
    void adaugaJucator(const Player &p);
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Sudoku &s);
};



#endif //MAIN_CPP_SUDOKU_H
