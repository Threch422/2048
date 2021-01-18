// header file for board in 2048
class board2048 {
private:
    int board[4][4];
    int move;
    int score;

public:
    // Constructor
    board2048() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = 0;
            }
        }
        move = 0;
        score = 0;
    };
    // Destructor
    ~board2048() {};

    // getter
    int get_data(int x, int y) {
        return board[x][y];
    }
    int get_move() {
        return move;
    }
    int get_score() {
        return score;
    }

    // setter
    void set_score() {
        int max = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] > max) {
                    max = board[i][j];
                }
            }
        }
        score = max;
    }
    // Function needed
    void print_board();
    void generate_num();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    bool check();
    void reset();
    void start();

};