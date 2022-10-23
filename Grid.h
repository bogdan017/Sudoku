#ifndef POO_PROJECT_GRID_H
#define POO_PROJECT_GRID_H


class Grid {
private:
    int linii, coloane;
public:
    friend ostream & operator <<(ostream &, const Grid &);
};


#endif //POO_PROJECT_GRID_H
