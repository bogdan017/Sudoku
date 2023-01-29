//
// Created by Vlad Bogdan on 20.01.2023.
//

#include "Meniu.h"
#include "Grid_6x6.h"
#include "Player.h"
#include "Grid_9x9.h"
#include "Grid.h"
#include "Premiu.h"

void Meniu::arataOptiuni() {
    std::cout << "1. Afisare player\n";
    std::cout << "2. Adaugare player\n";
    std::cout << "3. Leaderboard\n";
    std::cout << "0. Iesire\n";
}

Meniu *Meniu::getMeniu() {
    if(meniu == nullptr) {
        meniu = new Meniu;
    }
    return meniu;
}

void Meniu::afisarePlayer() {
    if(players.empty()) {
        std::cout << "Player-ul nu are atribuit niciun game atribuit\n";
    }
    for (const auto &grid : players) {
        std::cout << *grid;
    }
}

void Meniu::adaugarePlayer() {
    std::shared_ptr<Player> tmpPlayer = std::make_shared<Player>();
    tmpPlayer->citire(std::cin);
    players.push_back(tmpPlayer);
}

void Meniu::leaderboard() {
    std::cout << "Introduceti numarul player-ului pentru care doriti afisarea leaderboard-ului(primul player are numarul 0, al doilea player are numarul 1, etc.):";
    int option;
    try {
        std::cin >> option;
        if(option >= 2) {
            throw eroare_jucator(option);
        }
    } catch(eroare_jucator &err) {
        std::cout<<err.what()<<std::endl;
    }
    int frqGrid[3] = {0,0};

    for (const auto &player:players[option]->getGame()) {
        if (dynamic_pointer_cast<Grid_6x6>(player)) {
            frqGrid[0]++;
        } else if (dynamic_pointer_cast<Grid_9x9>(player)) {
            frqGrid[1]++;
        }
    }
    int nrGrid = players[option]->getGame().size();
    std::cout << "Playerul " << players[option]->getNume() << ", a jucat "<< nrGrid << " jocuri,";
    std::cout << " dintre care " << frqGrid[0] << " sunt/este sudoku 6x6";
    std::cout << " iar " << frqGrid[1] << " sunt/este sudoku 9x9\n";

    if(nrGrid >= 2) {
        std::cout << "Daca playerul are cel putin doua jocuri rezolvate acesta va primi un premiu:\n";
        std::shared_ptr<Premiu> tmpPrize = std::make_shared<Premiu>();
        tmpPrize->citire(std::cin);
        std::cout << "Acesta a castigat un premiu, care este sub forma: " << tmpPrize->getType() << "\n";
    }
}


void Meniu::showMenu()  {
    std::cout << "Introduceti o optiune din meniul de mai jos:\n";
    arataOptiuni();
    int optiune;
    std::cout << "Optiune:";
    std::cin >> optiune;
    while (optiune) {
        if(optiune == 1) {
            afisarePlayer();
        } else if (optiune == 2) {
            adaugarePlayer();
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
