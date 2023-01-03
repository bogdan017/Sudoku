#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Grid.h"

class Player {
private:
    int number;
    std::string nume;
    std::vector<std::shared_ptr<Grid>> g;
public:
    //constructor
    Player(int number_, const std::string& nume_, std::vector<std::shared_ptr<Grid>> g);
    void adauga_grid(const Grid &gr);
    //constructor de copiere
    Player(const Player& other);
    int GetNumber() const;
    std::string GetNume() const;
    //operator=
    Player& operator=(const Player& other);
    Player &operator=(Player other);
    friend void swap(Player &st1, Player &st2);
    //operator<<
    friend std::ostream& operator<<(std::ostream &os, const Player& p);
    //destructor
    ~Player();
};


#endif //MAIN_CPP_PLAYER_H
