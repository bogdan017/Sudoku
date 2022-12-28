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
    Player player1;
    std::vector<std::shared_ptr<Grid>> g;
public:
    //constructor
    explicit Sudoku(int id_game_, const Player &player1_, std::vector<std::shared_ptr<Grid>> g);
    /*int GetId() const {
        return id_game;
    }*/
    Sudoku(std::vector<std::shared_ptr<Grid>> g, Player player1);
    Sudoku(const Sudoku &other, Player player1);
    Sudoku &operator=(Sudoku other);
    friend void swap(Sudoku &st1, Sudoku &st2);
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Sudoku &s);
};



#endif //MAIN_CPP_SUDOKU_H
