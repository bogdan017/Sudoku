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
#include "Premiu.h"
#include "Meniu.h"

int main() {
    Meniu *meniu = Meniu::getMeniu();
    meniu->showMenu();
    return 0;
}

