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
    if (id_game_ < 0) {
        throw(eroare_joc(id_game_));
    }
    std::cout << "Constructor initializare joc\n";
}

std::ostream &operator<<(std::ostream &os, const Sudoku &s) {
    os << "sudoku game no." << s.id_game;
    os << "\n";
    for (const auto &Player: s.players) {
        os << Player;
        os << "\n";
    }
    return os;
}

void Sudoku::adaugaJucator(const Player &p) {
    players.push_back(p);
}

