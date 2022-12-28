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
    Player p(1,"Andrei"), p1(2, "Stefan");
    //std::cout << p << '\n' << p1 << '\n';
    //std::cout << p << '\n';
    std::cout << p1 << '\n';
    //Grid *g = new Sudoku_9x9();
    Sudoku_9x9 g;
    g.initializeGrid_();
    std::cout << "Sudoku initial:" << "\n" << g << "\n\n\n\n";
    std::cout << "Rezolvare sudoku: \n";
    if (g.solve()) {
        std::cout<< g <<"\n\n\n\n";
    } else {
        std::cout << "Sudoku nu poate fi rezolvat\n";
    }
    //Sudoku s(1, p, std::shared_ptr<Grid>());
    //std::cout << s << "\n";
    return 0;
}

