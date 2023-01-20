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
#include "Meniu.h"

int main() {
    try {
       /* Grid_9x9 g;
        g.initializeGrid_();
        Grid_6x6 h;
        h.initializeGrid();
        Player p1{"Andrei", {}};
       // Player p2{"George",{}};
        p1.adauga_grid(g);
        //std::cout << g;
        p1.adauga_grid(h);
        //std::cout << h;
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
        //std::cout << s1;*/
       Meniu *meniu = Meniu::getMeniu();
       meniu->arataMeniu();
    } catch(eroare_sudoku &err) {
        std::cout<<err.what()<<std::endl;
    } catch(eroare_joc &err) {
        std::cout<<err.what()<<std::endl;
    }
    return 0;
}

