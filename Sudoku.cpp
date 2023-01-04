//
// Created by Vlad Bogdan on 29.12.2022.
//

#include <vector>
#include <memory>
#include "Sudoku.h"
#include "Player.h"
#include "Grid.h"
#include "Sudoku_9x9.h"


Sudoku::Sudoku(int id_game_): id_game(std::move(id_game_)) {
    std::cout << "Constructor initializare joc\n";
}

std::ostream &operator<<(std::ostream &os, const Sudoku &s) {
    os << "sudoku game no." << s.id_game;
    for (const auto &Player: s.players)
        os << Player;
    return os;
}

