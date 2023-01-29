#include "exceptions.h"

eroare_jucator::eroare_jucator(int no) :
        eroare_aplicatie("Numarul jucatorului trebuie sa fie mai mic sau egal cu numarul total de jucatori, dar este " + std::to_string(no)) {}

eroare_sudoku::eroare_sudoku(int r, int c, int val) :
        eroare_aplicatie("Linia " + std::to_string(r) + " sau coloana " + std::to_string(c) + " sau valoarea " + std::to_string(val) + " este invalida") {}
