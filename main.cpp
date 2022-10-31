#include <iostream>
#include <string>

class Sudoku {
public:
    //constructor
    Sudoku() {
        std::cout << "Constructor initializare joc\n";
    }
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Sudoku & s) {
        os << "sudoku";
        return os;
    };
};

class Player {
private:
    int number;
    std::string nume;
public:
    //constructor
    Player(int number_, const std::string& nume_) : number{number_}, nume{nume_} {
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
    friend std::ostream& operator<<(std::ostream & os, const Player& p) {
        os << "Player" << p.number << " " << p.nume << "\n";
        return os;
    };

};

class Grid {
    int **grid, row, col;
public:
    //constructor
    Grid (const int r, const int c) : row{r}, col{c} {
        grid = new int*[row];
        for (int i = 0; i < row; ++i) {
            grid[i] = new int[col];
            for (int j = 0; j < col; ++j) {
                grid[i][j] = 0;
            }
        }
        std::cout << "Constructor de initializare grid\n";
    }
    //constructor de copiere
    Grid (const Grid& other) : row{other.row}, col{other.col} {

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                grid[i][j] = other.grid[i][j];
            }
        }
    }
    void citire() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                std::cin >> grid[i][j];
            }
        }
    }
    void scrie() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    //operator=
    Grid& operator=(const Grid& other) {
    row = other.row;
    col = other.col;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            grid[i][j] = other.grid[i][j];
        }
    }
    std::cout << "operator= copiere\n";
    return *this;
    }
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Grid& g) {
        os << "Grid" << g.row << " " << g.col << "\n";
        for (int i = 0; i < g.row; ++i) {
            for (int j = 0; j < g.col; ++j) {
                os << g.grid[i][j];
            }
        }
        return os;
    };
    //destructor
    ~Grid() {
        delete [] grid;
        std::cout << "Destructor grid";
    }
};

int main() {
    Sudoku s;
    Player p(1, "Andrei");
    p.scrie();
    Grid g(9, 9);
    g.citire();
    std::cout << "\n";
    g.scrie();
    return 0;
}