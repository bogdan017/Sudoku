#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Grid.h"
#include "Grid_6x6.h"
#include "Grid_9x9.h"

class Player {
private:
    static int idPlayer;
    int id_PlayerCur;
    std::string nume;
    std::vector<std::shared_ptr<Grid>> g;

public:
    //constructor
    Player();
    Player(const std::string &nume, const std::vector<std::shared_ptr<Grid>> &g);

    Player &operator=(Player other);
    friend void swap(Player &st1, Player &st2);
    //operator<<
    friend std::ostream& operator<<(std::ostream &os, const Player &p);
    friend std::istream &operator>>(std::istream &is, Player &player);
    std::istream &citire(std::istream &is);
    std::ostream &afisare(std::ostream &os) const;
    const std::vector<std::shared_ptr<Grid>> &getGame() const;
    //destructor
    ~Player();
};


#endif //MAIN_CPP_PLAYER_H
