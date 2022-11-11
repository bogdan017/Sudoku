#include <iostream>
#include <array>

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
    //constructor de copiere
    Player(const Player& other) : number{other.number}, nume{other.nume} {
        std::cout << "Constructor de copiere student";
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
    //operator=
    Player& operator=(const Player& other) {
        number = other.number;
        nume = other.nume;
        std::cout << "Op= copiere Player\n";
        return *this;
    }
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Player& p) {
        os << "Player" << p.number << " " << p.nume << "\n";
        return os;
    };
    //destructor
    ~Player() {
        std::cout << "Destructor player\n";
    }
};

class Grid {
    std::array<std::array<int, 9>, 9> grid{};
public:
    Grid() {
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                grid[i][j] = 0;
            }
        }
        std::cout << "Constructor de initializare grid\n";
    }
    void initializeGrid() {
        int r, c, val;
        std::cout << "Introduceti linia, coloana si valoarea corespunzatoare celulei alese initial: \n";
        std::cin >> r >> c >> val;
        if ((r < 0 || r > 8) && (c < 0 || c > 8) && (val < 0 || val > 8)) {
            std::cout << "Valoarea introdusa se afla in afara gridului si nu este valida\n";
            return;
        } else {
            grid[r][c] = val;
            char ch = 'y';
            while (ch == 'y') {
                std::cout << "Introduceti linia, coloana si valoarea corespunzatoare celulei alese: \n";
                std::cin >> r;
                std::cin >> c;
                std::cin >> val;
                grid[r][c] = val;
                std::cout << "Mai poti introduce o valoare sau apasa n pentru a te opri: \n";
                std::cin >> ch;
            }
        }
    }
    int NumInRow(int r, int num) {
        for (int i = 0; i < 9; ++i) {
            if (num != 0 && grid[r][i] == num) {
                return 1;
            }
        }
        return 0;
    }
    int NumInCol(int c, int num) {
        for (int i = 0; i < 9; ++i) {
            if (num != 0 && grid[i][c] == num) {
                return 1;
            }
        }
        return 0;
    }
    int NumInSquare(int ls, int cs, int num) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i + ls][j + cs] == num) {
                    return 1;
                }
            }
        }
        return 0;
    }
    int findEmpty(int &r, int &c) {
        for (r = 0; r < 9; ++r) {
            for (c = 0; c < 9; ++c) {
                if (grid[r][c] == 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    int ok(int r, int c, int num) {
        if (!NumInRow(r, num)) {
            if (!NumInCol(c, num)) {
                int line_sq = r - r % 3;
                int col_sq = c - c % 3;
                if (!NumInSquare(line_sq, col_sq, num)) {
                    return 1;
                }
            }
        }
        return 0;
    }
    int solve() {
        int r, c;
        if (findEmpty(r, c)) {
            for (int num = 1; num <= 9; ++num) {
                if (ok(r, c, num)) {
                    grid[r][c] = num;
                    if (solve()) {
                        return 1;
                    }
                    grid[r][c] = 0;
                }
            }
            return 0;
        } else {
            return 1;
        }
    }

    void scrie() {
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Grid& g) {
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                os << g.grid[i][j];
            }
        }
        return os;
    };
};

int main() {
    Sudoku s(1);
    s.scrie();
    Player p(1,"Andrei"), p1(2, "Stefan");
    p.scrie();
    p1.scrie();
    p = p1;
    p.scrie();
    p1.scrie();
    Grid g;
    std::cout << "\n";
    g.scrie();
    g.initializeGrid();
    g.scrie();
    std::cout << "Rezolvare sudoku: \n";
    if (g.solve()) {
        g.scrie();
    } else {
        std::cout << "Sudoku nu poate fi rezolvat\n";
    }
    return 0;
}