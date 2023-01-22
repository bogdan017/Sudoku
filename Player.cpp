#include "Player.h"

#include <utility>
#include "Grid.h"


int Player::idPlayer = 1;

Player::Player() : id_PlayerCur(idPlayer++) {}

Player::Player(const std::string &nume, const std::vector<std::shared_ptr<Grid>> &g) : id_PlayerCur(idPlayer++), nume(nume), g(g) {
    std::cout << "Constructor initializare jucator\n";
}

Player &Player::operator=(Player other) {
    swap(*this, other);
    return *this;
}

void swap(Player &st1, Player &st2) {
    std::swap(st1.g, st2.g);
    std::swap(st1.nume, st2.nume);
}

Player::~Player() {
    std::cout << "Destructor player\n";
}

std::istream &operator>>(std::istream &is, Player &player) {
    player.citire(is);
    return is;
}

std::istream &Player::citire(std::istream &is) {
    std::cout << "Nume jucator:";
    is >> nume;
    std::cout << "Numarul de jocuri:";
    int nrGames;
    is >> nrGames;
    for (int i = 0; i < nrGames; ++i) {
        int opt, citireValida = 0;
        std::shared_ptr<Grid> tmpGrid;
        while(!citireValida) {
            std::cout << "Alegeti optiunea: 1.Grid_6x6, 2.Grid_9x9: ";
            std::cin >> opt;
            citireValida = 1;
            if(opt == 1) {
                tmpGrid = std::make_shared<Grid_6x6>();
            } else if(opt == 2) {
                tmpGrid = std::make_shared<Grid_9x9>();
            }
            tmpGrid->citire(std::cin);
            g.push_back(tmpGrid);
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Player &p) {
    p.afisare(os);
    return os;
}

std::ostream &Player::afisare(std::ostream &os) const {
    os << "Player no." << id_PlayerCur << "\n" << "Nume player: " <<  nume << "\n";
    os << "Jocuri player: ";
    os << "\n";
    for (const auto &Grid: g) {
        os << "\nJocul initial:\n";
        os << *Grid;
        (*Grid).solve();
        os << "\nJocul dupa rezolvare:\n";
        os << *Grid;
        os << "\n";
    }
    os << "\n";
    return os;
}

const std::vector<std::shared_ptr<Grid>> &Player::getGame() const {
    return g;
}

