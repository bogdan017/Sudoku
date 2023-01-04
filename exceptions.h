#ifndef MAIN_CPP_EXCEPTIONS_H
#define MAIN_CPP_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class eroare_aplicatie : public std::runtime_error { using std::runtime_error::runtime_error; };

class eroare_sudoku: public eroare_aplicatie {
public:
    explicit eroare_sudoku(int r, int c, int val);
};

class eroare_joc: public eroare_aplicatie{
public:
    explicit eroare_joc(int no);
};



#endif //MAIN_CPP_EXCEPTIONS_H
