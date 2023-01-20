//
// Created by Vlad Bogdan on 20.01.2023.
//

#include "Meniu.h"

void Meniu::arataOptiuni() {
    std::cout << "1. Afisare sudoku\n";
    std::cout << "2. Adaugarea sudoku\n";
    std::cout << "0. Iesire\n";
}

Meniu *Meniu::getMeniu() {
    if(meniu == nullptr) {
        meniu = new Meniu;
    }
    return meniu;
}

void Meniu::afisareSudoku() {
    if(sudoku.empty()) {
        std::cout << "Player-ul nu are atribuit niciun sudoku\n";
    }
    for (auto &game : sudoku) {
        std::cout << *game;
    }
}

void Meniu::adaugareSudoku() {
    std::shared_ptr<Sudoku> tmpSudoku = std::make_shared<Sudoku>();
    tmpSudoku->citire(std::cin);
    sudoku.push_back(tmpSudoku);
}

Meniu *Meniu::meniu;
