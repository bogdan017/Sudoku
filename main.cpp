#include <iostream>
#include <array>
#include <utility>
#include <algorithm>
#include <vector>
#include <memory>
#include <string>
#include "Player.h"
#include "Grid.h"
#include "Grid_9x9.h"
#include "Grid_6x6.h"
#include "Sudoku.h"


void tipSudoku(Grid* Sudoku_) {
    auto *co = dynamic_cast<Grid_9x9 *>(Sudoku_);
    if (co != nullptr) {
        std::cout << "Sudoku de tip 9x9:";
        std::cout << "\n";
    } else {
        auto *co2 = dynamic_cast<Grid_6x6 *>(Sudoku_);
        std::cout << "\n";
        if (co2 != nullptr) {
            std::cout << "Sudoku de tip 6x6:";
        }
        std::cout << "\n";
    }
}

int main() {
    try {
        Grid_9x9 g;
        g.initializeGrid_();
        Grid_6x6 h;
        h.initializeGrid();
        Player p1{"Andrei", {}};
       // Player p2{"George",{}};
        tipSudoku(&g);
        p1.adauga_grid(g);
        std::cout << g;
        tipSudoku(&h);
        p1.adauga_grid(h);
        std::cout << h;
        //p2.adauga_grid(g);
        //std::cout << g;
        g.solve();
        h.solve();
        //std::cout << p1;
        Sudoku s;
        s.adaugaJucator(p1);
        //s1.adaugaJucator(p2);
        std::cout << s;
        std::cout << "\n";
        //std::cout << s1;
    } catch(eroare_sudoku &err) {
        std::cout<<err.what()<<std::endl;
    } catch(eroare_joc &err) {
        std::cout<<err.what()<<std::endl;
    }
    return 0;
}

