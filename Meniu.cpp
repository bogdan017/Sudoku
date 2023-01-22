//
// Created by Vlad Bogdan on 20.01.2023.
//

#include "Meniu.h"
#include "Grid_6x6.h"
#include "Player.h"
#include "Grid_9x9.h"
#include "Grid.h"
#include "Sudoku.h"

void Meniu::arataOptiuni() {
    std::cout << "1. Afisare sudoku\n";
    std::cout << "2. Adaugarea sudoku\n";
    std::cout << "3. Leaderboard\n";
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
    std::shared_ptr<Player> tmpSudoku = std::make_shared<Player>();
    tmpSudoku->citire(std::cin);
    players.push_back(tmpSudoku);
}


void Meniu::leaderboard() {
    // afisareSudoku();
    std::cout << "Introduceti numarul player-ului pentru care doriti afisarea leaderboard-ului:";
    int option;
    std::cin >> option;
    int frqGrid[2] = {0,0};

    for (const auto &player:players[option]->getGame()) {
        if (dynamic_pointer_cast<Grid_6x6>(player)) {
            frqGrid[0]++;
        } else if (dynamic_pointer_cast<Grid_9x9>(player)) {
            frqGrid[1]++;
        }
    }
    int nrGrid = players[option]->getGame().size();
    std::cout << "Playerul " << option << ", a jucat "<< nrGrid << " jocuri,";
    std::cout << " dintre care " << frqGrid[0] << " sunt/este sudoku 6x6";
    std::cout << " iar " << frqGrid[1] << " sunt/este sudoku 9x9\n";
}


void Meniu::showMenu()  {
    std::cout << "Introduceti o optiune din meniul de mai jos:\n";
    arataOptiuni();

    std::cout << "Optiune:";
    std::cin >> optiune;
    while (optiune) {
        if(optiune == 1) {
            afisareSudoku();
        } else if (optiune == 2) {
            adaugareSudoku();
        } else if (optiune == 3) {
            leaderboard();
        } else {
            std::cout << "Optiunea introdusa este invalida";
        }
        arataOptiuni();
        std::cout << "Optiune:";
        std::cin >> optiune;
    }
}


Meniu *Meniu::meniu;
