#include <iostream>
#include <array>

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
        std::cout << "Constructor de copiere student\n";
    }
    int GetNumber() const {
        return number;
    }
    std::string GetNume() const {
        return nume;
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
        int r = 0, c = 0, val = 0;
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
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Grid& g) {
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                os << g.grid[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    };
};

class Sudoku {
    int id_game;
    Player player1;
    Grid grid1;
public:
    //constructor
    explicit Sudoku(int id_game_, const Player& player1_, const Grid& grid1_) : id_game{id_game_}, player1{player1_}, grid1{grid1_} {
        std::cout << "Constructor initializare joc\n";
    }
    /*int GetId() const {
        return id_game;
    }*/
    //operator<<
    friend std::ostream& operator<<(std::ostream & os, const Sudoku& s) {
        os << "sudoku game no." << s.id_game << "\n" << "Numarul jucatorului: " << s.player1.GetNumber() << "\n" << "Numele jucatorului: " << s.player1.GetNume() << "\n" << s.grid1;
        return os;
    };
};

int main() {
    Player p(1,"Andrei"), p1(2, "Stefan");
    std::cout << p << '\n' << p1 << '\n';
    std::cout << p << '\n';
    std::cout << p1 << '\n';
    Grid g;
    std::cout << "\n" << g << "\n";
    g.initializeGrid();
    std::cout << g << "\n";
    std::cout << "Rezolvare sudoku: \n";
    if (g.solve()) {
        std::cout << g << "\n";
    } else {
        std::cout << "Sudoku nu poate fi rezolvat\n";
    }
    Sudoku s(1,p,g);
    std::cout << s << "\n";
    return 0;
}