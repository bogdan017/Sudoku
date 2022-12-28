#include "Player.h"

Player::Player(int number_, const std::string &nume_) : number{number_}, nume{nume_} {
    std::cout << "Constructor initializare jucator\n";
}

Player::Player(const Player &other) : number{other.number}, nume{other.nume} {
    std::cout << "Constructor de copiere student\n";
}

int Player::GetNumber() const {
    return number;
}

std::string Player::GetNume() const {
    return nume;
}

Player &Player::operator=(const Player &other) {
    number = other.number;
    nume = other.nume;
    std::cout << "Op= copiere Player\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Player &p) {
    os << "Player" << p.number << " " << p.nume << "\n";
    return os;
}

Player::~Player() {
    std::cout << "Destructor player\n";
}
