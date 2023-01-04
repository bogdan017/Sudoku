#include "Player.h"
#include "Grid.h"

Player::Player(int number_, const std::string &nume_, std::vector<std::shared_ptr<Grid>> g) : number{number_}, nume{nume_}, g{std::move(g)} {
    std::cout << "Constructor initializare jucator\n";
}

Player::Player(const Player &other) : number{other.number}, nume{other.nume} {
    for (const auto &Grid: other.g)
        g.emplace_back(Grid->clone());
    std::cout << "Constructor de copiere jucator\n";
}

/*int Player::GetNumber() const {
    return number;
}

std::string Player::GetNume() const {
    return nume;
}
*/
Player &Player::operator=(const Player &other) {
    number = other.number;
    nume = other.nume;
    std::cout << "Op= copiere Player\n";
    return *this;
}

Player &Player::operator=(Player other) {
    swap(*this, other);
    return *this;
}

void swap(Player &st1, Player &st2) {
    std::swap(st1.g, st2.g);
    std::swap(st1.nume, st2.nume);
    std::swap(st1.number, st2.number);
}

std::ostream &operator<<(std::ostream &os, const Player &p) {
    os << "Player no." << p.number << "\n" << "Nume player: " <<  p.nume << "\n";
    os << "Jocuri player: " << "\n";
    for (const auto &Grid: p.g){
        os << *Grid;
        os << "\n";
    }
    os << "\n";
    os << "Jocuri rezolvate player: " << "\n";
    for (const auto &Grid: p.g) {
        (*Grid).solve();
        os << *Grid;
        os << "\n";
    }
    os << "\n";
    return os;
}

Player::~Player() {
    std::cout << "Destructor player\n";
}

void Player::adauga_grid(const Grid &gr) {
    g.push_back(gr.clone());
}


