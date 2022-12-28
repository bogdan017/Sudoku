//
// Created by Vlad Bogdan on 29.12.2022.
//

#include <vector>
#include "Sudoku.h"
#include "Player.h"
#include "Grid.h"

Sudoku::Sudoku(std::vector<std::shared_ptr<Grid>> g, Player player1) : player1(player1), g(std::move(g)) {}

Sudoku::Sudoku(const Sudoku &other, Player player1) : player1(player1) {
    for (const auto &Grid: other.g)
        g.emplace_back(Grid->clone());
}

Sudoku &Sudoku::operator=(Sudoku other) {
    swap(*this, other);
    return *this;
}

void swap(Sudoku &st1, Sudoku &st2) {
    std::swap(st1.g, st2.g);
    std::swap(st1.player1, st2.player1);
    std::swap(st1.id_game, st2.id_game);
}

std::ostream &operator<<(std::ostream &os, const Sudoku &s) {
    os << "sudoku game no." << s.id_game << "\n" << "Numarul jucatorului: " << s.player1.GetNumber() << "\n" << "Numele jucatorului: " << s.player1.GetNume() << "\n";
    for (const auto &Grid: s.g)
        os << *Grid;
    return os;
}

Sudoku::Sudoku(int id_game_, const Player &player1_, std::vector<std::shared_ptr<Grid>> g)
        : id_game{id_game_}, player1{player1_}, g(g) {
    std::cout << "Constructor initializare joc\n";
}
