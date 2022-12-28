#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include <iostream>
#include <string>

class Player {
private:
    int number;
    std::string nume;
public:
    //constructor
    Player(int number_, const std::string& nume_);
    //constructor de copiere
    Player(const Player& other);
    int GetNumber() const;
    std::string GetNume() const;
    //operator=
    Player& operator=(const Player& other);
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Player& p);
    //destructor
    ~Player();
};


#endif //MAIN_CPP_PLAYER_H
