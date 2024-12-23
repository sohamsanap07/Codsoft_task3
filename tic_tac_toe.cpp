#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, col;
bool draw = false;

void displayBoard() {
    cout << "\n\nPlayer 1 [X] - Player 2 [O]\n\n";
    cout << "     |     |     \n";
    for (int i = 0; i < 3; i++) {
        cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  \n";
        if (i < 2) {
            cout << "_____|_____|_____\n     |     |     \n";
        }
    }
    cout << "\n\n";
}

bool updateBoard(int choice) {
    switch (choice) {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default:
            cout << "Invalid choice. Please select a number between 1 and 9.\n";
            return false;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = turn;
        return true;
    } else {
        cout << "Cell already occupied! Try a different move.\n";
        return false;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchTurn() {
    turn = (turn == 'X') ? 'O' : 'X';
}

void displayInstructions() {
    cout << "\nWelcome to Tic-Tac-Toe!\n";
    cout << "Two players take turns marking a cell in a 3x3 grid.\n";
    cout << "Player 1 is 'X', and Player 2 is 'O'. The goal is to form a straight line (row, column, or diagonal).\n";
    cout << "Choose a cell number from 1 to 9 as shown below:\n\n";
    cout << "     |     |     \n";
    cout << "  1  |  2  |  3  \n";
    cout << "_____|_____|_____\n";
    cout << "  4  |  5  |  6  \n";
    cout << "_____|_____|_____\n";
    cout << "  7  |  8  |  9  \n";
    cout << "     |     |     \n\n";
}

int main() {
    int choice;
    displayInstructions();

    while (true) {
        displayBoard();
        cout << "Player " << (turn == 'X' ? 1 : 2) << " [" << turn << "] turn: Enter your choice: ";
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        if (!updateBoard(choice)) {
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << "Congratulations! Player " << (turn == 'X' ? 1 : 2) << " wins!\n";
            break;
        }

        if (checkDraw()) {
            draw = true;
            displayBoard();
            cout << "It's a draw! Well played both players!\n";
            break;
        }

        switchTurn();
    }

    cout << "\nThank you for playing Tic-Tac-Toe!\n";
    return 0;
}
