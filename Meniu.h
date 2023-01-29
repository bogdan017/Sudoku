//
// Created by Vlad Bogdan on 20.01.2023.
//

#ifndef GRID_6X6_CPP_MENIU_H
#define GRID_6X6_CPP_MENIU_H

#include <iostream>
#include <vector>
#include <array>
#include "Grid_6x6.h"
#include "Player.h"
#include "Grid_9x9.h"
#include "Grid.h"
#include "Premiu.h"

class Meniu {
private:
    Meniu() {}
    static Meniu *meniu;
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Premiu> prize;
    void arataOptiuni();
public:
    static Meniu *getMeniu();
    void afisarePlayer();
    void adaugarePlayer();
    void leaderboard();
    void showMenu();
};



#endif //GRID_6X6_CPP_MENIU_H
