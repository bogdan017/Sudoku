//
// Created by Vlad Bogdan on 29.12.2022.
//

#include <vector>
#include <memory>
#include "Sudoku.h"
#include "Player.h"
#include "Grid.h"
#include "Grid_9x9.h"


Sudoku::Sudoku() : id_game(id++) {
    if (id_game < 0) {
        throw(eroare_joc(id_game));
    }
    std::cout << "Constructor initializare joc\n";
}


int Sudoku::id = 1;


std::istream &operator>>(std::istream &is, Sudoku &s) {
    s.citire(is);
    return is;
}

std::istream &Sudoku::citire(std::istream &is) {

    std::shared_ptr<Player> tmpPlayer = std::make_shared<Player>();
    tmpPlayer->citire(is);
    players.push_back(tmpPlayer);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sudoku &s) {
    s.afisare(os);
    return os;
}

std::ostream &Sudoku::afisare(std::ostream &os) const {
    os << "Sudoku game no." << id_game;
    os << "\n";
    for (const auto &Player: players) {
        os << *Player;
        os << "\n";
    }
    return os;
}

Sudoku::Sudoku(const std::vector<std::shared_ptr<Player>> &players) : id_game(id++), players(players) {}

