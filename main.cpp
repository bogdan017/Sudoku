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
    try {
        Grid_9x9 g;
        g.initializeGrid_();
        Grid_6x6 h;
        h.initializeGrid();
        Player p1{1, "Andrei", {}};
        p1.adauga_grid(g);
        p1.adauga_grid(h);
        g.solve();
        h.solve();
       // std::cout << p1;
        Sudoku s{1};
        s.adaugaJucator(p1);
        std::cout << s;
    } catch(eroare_sudoku &err) {
        std::cout<<err.what()<<std::endl;
    } catch(eroare_joc &err) {
        std::cout<<err.what()<<std::endl;
    }
    return 0;
}

