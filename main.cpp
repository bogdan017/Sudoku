#include <iostream>
#include <string>

class Sudoku {
    int id_game;
public:
    //constructor
    explicit Sudoku(int id_game_) : id_game{id_game_} {
        std::cout << "Constructor initializare joc\n";
    }
    void scrie() const {
        std::cout << "Id joc: " << id_game << "\n";
    }
    /*int GetId() const {
        return id_game;
    }*/
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Sudoku& s) {
        os << "sudoku " << s.id_game << "\n";
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
    /*int GetNumber() {
        return number;
    }
    std::string GetNume() {
        return nume;
    }
    void SetNume(const std::string& nume1) {
        nume = nume1;
    }*/
    void scrie() {
        std::cout << "Numarul jucatorului: " << number << "\n" << "Numele jucatorului: " << nume << "\n";
        std::cout << "\n";
    }
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Player& p) {
        os << "Player" << p.number << " " << p.nume << "\n";
        return os;
    };

};

class Grid {
    int **grid{}, row, col;
public:
    //constructor
    Grid (int r, int c) : row{r}, col{c} {
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
        grid = new int*[other.row];
        for (int i = 0; i < other.row; ++i) {
            grid[i] = new int[other.col];
            (*grid[i]) = *(other.grid[i]);
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
        if (this == &other) {
            return *this;
        }
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
        for (int i = 0; i < row; ++i) {
            delete[] grid[i];
        }
        delete[] grid;
        std::cout << "Destructor grid";
    }
};

int main() {
    Sudoku s(1);
    s.scrie();
    Player p(1,"Andrei");
    p.scrie();
    Grid g(2, 2);
    g.citire();
    std::cout << "\n";
    g.scrie();
    return 0;
}