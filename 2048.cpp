#include "2048.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Print the game board
void board2048::print_board() {
    cout << "Move: " << get_move() << "\t" << "Score: " << get_score() << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Generate random number and put in the empty grid
void board2048::generate_num() {
    // Set seed
    srand(time(NULL));

    // Vector for storing empty grid index
    vector<int> empty;
    empty.clear();
    int count = 0;
    int chosen_index;
    int random_num;
    // Empty grid checking
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                empty.push_back(count);
            }
            count++;
        }
    }
    chosen_index = rand() % empty.size();
    if (rand() % 2) {

        random_num = 4;
    }
    else {
        random_num = 2;
    }
    board[empty[chosen_index] / 4][empty[chosen_index] % 4] = random_num;
}

// Moving the grid upward
void board2048::move_up() {
    for (int col = 0; col < 4; col++) {
        // Trim Space
        for (int i = 0; i < 3; i++) {
            if (board[i][col] == 0) {
                int x = i;
                for (int j = i + 1; j < 4; j++) {
                    if (board[j][col] != 0) {
                        board[x][col] = board[j][col];
                        board[j][col] = 0;
                        x++;
                    }
                }
                break;
            }
        }

        // Merge
        for (int i = 0; i < 3; i++) {
            if (board[i][col] != 0) {
                if (board[i][col] == board[i + 1][col]) {
                    board[i][col] *= 2;
                    board[i + 1][col] = 0;
                    i++;
                }
            }
        }

        // Trim Space Again
        for (int i = 0; i < 3; i++) {
            if (board[i][col] == 0) {
                int x = i;
                for (int j = i + 1; j < 4; j++) {
                    if (board[j][col] != 0) {
                        board[x][col] = board[j][col];
                        board[j][col] = 0;
                        x++;
                    }
                }
                break;
            }
        }
    }
}

void board2048::move_down() {
    for (int col = 0; col < 4; col++) {
        // Trim Space
        for (int i = 3; i > 0; i--) {
            if (board[i][col] == 0) {
                int x = i;
                for (int j = i - 1; j >= 0; j--) {
                    if (board[j][col] != 0) {
                        board[x][col] = board[j][col];
                        board[j][col] = 0;
                        x--;
                    }
                }
                break;
            }
        }

        // Merge
        for (int i = 3; i > 0; i--) {
            if (board[i][col] != 0) {
                if (board[i][col] == board[i - 1][col]) {
                    board[i][col] *= 2;
                    board[i - 1][col] = 0;
                    i--;
                }
            }
        }

        // Trim Space Again
        for (int i = 3; i > 0; i--) {
            if (board[i][col] == 0) {
                int x = i;
                for (int j = i - 1; j >= 0; j--) {
                    if (board[j][col] != 0) {
                        board[x][col] = board[j][col];
                        board[j][col] = 0;
                        x--;
                    }
                }
                break;
            }
        }
    }    
}

void board2048::move_left() {
    for (int row = 0; row < 4; row++) {
        // Trim Space
        for (int i = 0; i < 3; i++) {
            if (board[row][i] == 0) {
                int x = i;
                for (int j = i + 1; j < 4; j++) {
                    if (board[row][j] != 0) {
                        board[row][x] = board[row][j];
                        board[row][j] = 0;
                        x++;
                    }
                }
                break;
            }
        }

        // Merge
        for (int i = 0; i < 3; i++) {
            if (board[row][i] != 0) {
                if (board[row][i] == board[row][i + 1]) {
                    board[row][i] *= 2;
                    board[row][i + 1] = 0;
                    i++;
                }
            }
        }

        // Trim Space Again
        for (int i = 0; i < 3; i++) {
            if (board[row][i] == 0) {
                int x = i;
                for (int j = i + 1; j < 4; j++) {
                    if (board[row][j] != 0) {
                        board[row][x] = board[row][j];
                        board[row][j] = 0;
                        x++;
                    }
                }
                break;
            }
        }
    }
}

void board2048::move_right() {
    for (int row = 0; row < 4; row++) {
        // Trim Space
        for (int i = 3; i > 0; i--) {
            if (board[row][i] == 0) {
                int x = i;
                for (int j = i - 1; j >= 0; j--) {
                    if (board[row][j] != 0) {
                        board[row][x] = board[row][j];
                        board[row][j] = 0;
                        x--;
                    }
                }
                break;
            }
        }

        // Merge
        for (int i = 3; i > 0; i--) {
            if (board[row][i] != 0) {
                if (board[row][i] == board[row][i - 1]) {
                    board[row][i] *= 2;
                    board[row][i - 1] = 0;
                    i--;
                }
            }
        }

        // Trim Space Again
        for (int i = 3; i > 0; i--) {
            if (board[row][i] == 0) {
                int x = i;
                for (int j = i - 1; j >= 0; j--) {
                    if (board[row][j] != 0) {
                        board[row][x] = board[row][j];
                        board[row][j] = 0;
                        x--;
                    }
                }
                break;
            }
        }
    }    
}

bool board2048::check() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

void board2048::reset() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
    generate_num();
    generate_num();
    move = 0;
    set_score();
}

void board2048::start() {
    char choice;
    reset();
    while(1) {
        print_board();
        cin >> choice;
        switch(choice) {
            case 'w': case 'W':
                move_up();
                break;
            case 's': case 'S':
                move_down();
                break;
            case 'a': case 'A':
                move_left();
                break;
            case 'd': case 'D':
                move_right();
                break;
            case 'q': case 'Q':
                return;
        }
        set_score();
        set_move();
        if (!check()) {
            cout << "You lost!" << endl;
            cout << "Retry? (r)" << endl;
            cin >> choice;
            if (choice == 'R' || choice == 'r') {
                reset();
            }
            else
                return;
        }
        else if (get_score() == 2048) {
            cout << "You Win!" << endl;
            return;
        }
        else
            generate_num();
    }   
}