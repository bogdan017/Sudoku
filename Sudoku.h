#ifndef POO_PROJECT_SUDOKU_H
#define POO_PROJECT_SUDOKU_H


class Sudoku {
private:
    int grid[9][9];
public:
    //constructor
    Sudoku();
    //destructor
    ~Sudoku();
    Sudoku& operator=(const Sudoku &);
    friend ostream & operator <<(ostream &, const Sudoku &);
};


#endif //POO_PROJECT_SUDOKU_H
