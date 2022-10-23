#ifndef POO_PROJECT_PLAYER_H
#define POO_PROJECT_PLAYER_H


class Player {
private:
    int number;
public:
    //constructor
    Player();
    //destructor
    ~Player();
    friend ostream & operator <<(ostream &, const Player &);

};


#endif //POO_PROJECT_PLAYER_H
