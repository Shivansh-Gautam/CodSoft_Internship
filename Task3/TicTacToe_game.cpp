#include <iostream>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0; // No winner yet
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // There's still an empty space
            }
        }
    }
    return true;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
        currentPlayer = 2;
    } else {
        currentMarker = 'X';
        currentPlayer = 1;
    }
}

void game() {
    currentPlayer = 1;
    currentMarker = 'X';
    int playerWon;

    drawBoard();
    
    while (true) {
        int slot;
        std::cout << "Player " << currentPlayer << "'s turn. Enter your slot (1-9): ";
        std::cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        drawBoard();
        
        playerWon = winner();

        if (playerWon == 1) {
            std::cout << "Player 1 (X) wins!" << std::endl;
            break;
        } else if (playerWon == 2) {
            std::cout << "Player 2 (O) wins!" << std::endl;
            break;
        }

        if (isDraw()) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        swapPlayerAndMarker();
    }
}

int main() {
    char playAgain;

    do {
        // Reset board
       for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        board[i][j] = static_cast<char>('1' + (i * 3 + j));  // Explicit cast to avoid warning
    }
}


        game();

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
