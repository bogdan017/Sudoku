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
       Meniu *meniu = Meniu::getMeniu();
       meniu->showMenu();
    }  catch(eroare_joc &err) {
        std::cout<<err.what()<<std::endl;
    }
    return 0;
}

