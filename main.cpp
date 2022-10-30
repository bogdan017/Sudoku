#include <iostream>
#include <string>

class Sudoku {
public:
    //constructor
    Sudoku() {
        std::cout << "Constructor initializare joc\n";
    }
    //operator<<
    friend std::ostream& operator<<(std::ostream &, const Sudoku &);
};

class Player {
private:
    int number;
    std::string nume;
public:
    //constructor
    Player(int number1, const std::string nume1) {
        number = number1;
        nume = nume1;
        std::cout << "Constructor initializare jucator\n";
    }
    int GetNumber() {
        return number;
    }
    std::string GetNume() {
        return nume;
    }
    void SetNume(const std::string& nume1) {
        nume = nume1;
    }
    void scrie() {
        std::cout << number << " " << nume;
        std::cout << "\n";
    }
    //operator<<
    friend std::ostream& operator<<(std::ostream &, const Player &);

};

class Grid {
    int **grid, row, col;
public:
    //constructor
    Grid (const int r = 9, const int c = 9) {
        row = r;
        col = c;
        grid = new int*[row];
        for (int i = 1; i <= r; ++i) {
            grid[i] = new int[9];
            for (int j = 1; j <= c; ++j) {
                grid[i][j] = 0;
            }
        }
        std::cout << "Constructor de initializare grid\n";
    }
    //constructor de copiere
    Grid (Grid& g) {

        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                grid[i][j] = g.grid[i][j];
            }
        }
    }
    void citire() {
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                std::cin >> grid[i][j];
            }
        }
    }
    void scrie() {
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    //operator=
    Grid& operator=(const Grid& grid1);
    //operator<<
    friend std::ostream& operator<<(std::ostream &, const Grid &);
    //destructor
    ~Grid() {
        delete [] grid;
        std::cout << "Destructor grid";
    }
};

Grid& Grid::operator=(const Grid & grid1) {
    if (this == &grid1) {
        return *this;
    }
    grid = new int*[row];
    for (int i = 1; i <= row; ++i) {
        grid[i] = new int[9];
    }
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            grid[i][j] = grid1.grid[i][j];
        }
    }
    return *this;
}

int main() {
    Sudoku s;
    Player p(1, "Andrei");
    p.scrie();
    Grid g;
    g.citire();
    std::cout << "\n";
    g.scrie();
    return 0;
}
