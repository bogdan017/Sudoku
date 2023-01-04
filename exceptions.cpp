#include "exceptions.h"

eroare_joc::eroare_joc(int no) :
        eroare_aplicatie("Numarul jocului trebuie sa fie un numar pozitiv, dar este " + std::to_string(no)) {}

eroare_sudoku::eroare_sudoku(int r, int c, int val) :
        eroare_aplicatie("Linia " + std::to_string(r) + " sau coloana " + std::to_string(c) + " sau valoarea " + std::to_string(val) + " este invalida") {}
