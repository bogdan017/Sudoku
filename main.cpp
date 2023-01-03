#include <iostream>
#include <array>
#include <utility>
#include <algorithm>
#include <vector>
#include <memory>
#include <string>
#include "Player.h"
#include "Grid.h"
#include "Sudoku_9x9.h"
#include "Sudoku_6x6.h"
#include "Sudoku.h"

int main() {

    /*Sudoku_9x9 g;
    g.initializeGrid_();
    std::cout << "Sudoku initial:" << "\n" << g << "\n\n\n\n";
    std::cout << "Rezolvare sudoku: \n";
    if (g.solve()) {
        std::cout<< g <<"\n\n\n\n";
    } else {
        std::cout << "Sudoku nu poate fi rezolvat\n";
    }
    Sudoku_6x6 h;
    h.initializeGrid_();
    std::cout << "Sudoku initial:" << "\n" << h << "\n\n\n\n";
    std::cout << "Rezolvare sudoku: \n";
    if (h.solve()) {
        std::cout<< h <<"\n\n\n\n";
    } else {
        std::cout << "Sudoku nu poate fi rezolvat\n";
    }*/
    //Sudoku_9x9 g;
    //g.initializeGrid_();
    Sudoku_6x6 h;
    h.initializeGrid();
    Player p1{1, "Andrei",{}};
    //g.solve();
    h.solve();
    //p1.adauga_grid(g);
    p1.adauga_grid(h);
    std::cout << p1;
    return 0;
}

