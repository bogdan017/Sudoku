//
// Created by Vlad Bogdan on 29.12.2022.
//

#ifndef MAIN_CPP_SUDOKU_H
#define MAIN_CPP_SUDOKU_H
#include "Grid.h"
#include "Player.h"
#include <memory>


class Premiu {
    std::string tip;

public:

    //constructor
    explicit Premiu();
    explicit Premiu(const std::string &tip);
    //operator<<
    friend std::ostream &operator<<(std::ostream &os, const Premiu &s);
    //operator>>
    friend std::istream &operator>>(std::istream &is, Premiu &s);
    std::ostream &afisare(std::ostream &os) const;
    std::istream &citire(std::istream &is);

    const std::string &getType() const {
        return tip;
    };


};



#endif //MAIN_CPP_SUDOKU_H
