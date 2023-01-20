//
// Created by Vlad Bogdan on 20.01.2023.
//

#ifndef GRID_6X6_CPP_MENIU_H
#define GRID_6X6_CPP_MENIU_H

#include <iostream>
#include <vector>
#include <array>
#include "Sudoku.h"

class Meniu {
private:
    Meniu() {}
    static Meniu *meniu;
    std::vector<std::shared_ptr<Sudoku>> sudoku;
    unsigned int optiune;
    void arataOptiuni();
public:
    static Meniu *getMeniu();
    void afisareSudoku();
    void adaugareSudoku();
    void arataMeniu() {
        std::cout << "Introduceti o optiune din meniul de mai jos:\n";
        arataOptiuni();

        std::cout << "Optiune:";
        std::cin >> optiune;
        while (optiune) {
            if(optiune == 1) {
                afisareSudoku();
            } else if (optiune == 2) {
                adaugareSudoku();
            } else {
                std::cout << "Optiunea introdusa este invalida";
            }
            arataOptiuni();
            std::cout << "Optiune:";
            std::cin >> optiune;
        }
    }
};



#endif //GRID_6X6_CPP_MENIU_H
