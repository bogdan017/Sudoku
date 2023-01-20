//
// Created by Vlad Bogdan on 29.12.2022.
//

#ifndef MAIN_CPP_SUDOKU_H
#define MAIN_CPP_SUDOKU_H
#include "Grid.h"
#include "Player.h"
#include <memory>


class Sudoku {
    static int id;
    const int id_game;
    std::vector<std::shared_ptr<Player>> players;
public:
    //constructor
    explicit Sudoku();
    /*int GetId() const {
        return id_game;
    }*/
    explicit Sudoku(std::vector<std::shared_ptr<Player>> &players) : id_game(id++), players(players) {}
    //void adaugaJucator(Player &p);
    //operator<<
    friend std::ostream& operator<<(std::ostream &os, const Sudoku &s);
    friend std::istream& operator>>(std::istream &is, Sudoku &s);
    std::ostream &afisare(std::ostream &os) const;
    std::istream &citire(std::istream &is);

};



#endif //MAIN_CPP_SUDOKU_H
