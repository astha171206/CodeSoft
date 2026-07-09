#include <iostream>
#include <vector>

using namespace std; 


void resetBoard(vector<vector<char>>& board) {
    char start = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = start++;
        }
    }
}


void displayBoard(const vector<vector<char>>& board) {
    cout << "\n-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}


bool updateBoard(vector<vector<char>>& board, int choice, char player) {
   
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

   
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return true;
    }
    return false; 
}


bool checkForWin(const vector<vector<char>>& board) {
  
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
  
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool checkForDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    vector<vector<char>> board(3, vector<char>(3));
    char playAgain;

    do {
        resetBoard(board);
        char currentPlayer = 'X'; 
        bool gameWon = false;
        bool gameDraw = false;

        cout << "\nTIC-TAC-TOE GAME \n";

        while (!gameWon && !gameDraw) {
            displayBoard(board);
            
           
            int choice;
            cout << "Player " << currentPlayer << ", enter a slot number (1-9): ";
            cin >> choice;

            
            if (choice < 1 || choice > 9) {
                cout << "Invalid slot! Please enter a number between 1 and 9.\n";
                continue;
            }

            
            if (!updateBoard(board, choice, currentPlayer)) {
                cout << "Slot already taken! Try another one.\n";
                continue;
            }

            
            gameWon = checkForWin(board);
            if (gameWon) {
                displayBoard(board);
                cout << "\n Player " << currentPlayer << " WINS! \n";
                break;
            }

         
            gameDraw = checkForDraw(board);
            if (gameDraw) {
                displayBoard(board);
                cout << "\n It's a DRAW! \n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        
        cout << "\nDo you want to play another game? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing! Goodbye.\n";
    return 0;
}