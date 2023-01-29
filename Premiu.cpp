//
// Created by Vlad Bogdan on 29.12.2022.
//

#include <vector>
#include <memory>
#include "Premiu.h"
#include "Player.h"
#include "Grid.h"
#include "Grid_9x9.h"


Premiu::Premiu(const std::string &tip) : tip(tip) {}


std::istream &operator>>(std::istream &is, Premiu &s) {
    s.citire(is);
    return is;
}

std::istream &Premiu::citire(std::istream &is) {
    std::cout << "Tip premiu:";
    is >> tip;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Premiu &s) {
    s.afisare(os);
    return os;
}

std::ostream &Premiu::afisare(std::ostream &os) const {
    os << "Tip premiu: " << tip << "\n";
    return os;
}

Premiu::Premiu() {}



