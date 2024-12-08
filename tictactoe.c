#include <stdio.h>
#include <stdbool.h>

char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void printBoard() {
    printf("\n     |     |    \n");
    printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);
    printf("     |     |    \n");
    printf("-----------------\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);
    printf("     |     |    \n");
    printf("-----------------\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);
    printf("     |     |    \n\n");
}

char checkWinner() {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Horizontal
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Vertical
        {0, 4, 8}, {2, 4, 6}              // Diagonal
    };

    for (int i = 0; i < 8; i++) {
        if (board[winPatterns[i][0]] == board[winPatterns[i][1]] &&
            board[winPatterns[i][1]] == board[winPatterns[i][2]]) {
            return board[winPatterns[i][0]];
        }
    }
    return ' '; // No winner yet
}

bool isDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}

void resetBoard() {
    for (int i = 0; i < 9; i++) {
        board[i] = '1' + i;
    }
}

int main() {
    while (true) {
        int choice;
        printf("Welcome to TIC TAC TOE\n");
        printf("Choose an option:\n1. PLAY\n2. EXIT\n-> ");
        scanf("%d", &choice);

        if (choice == 1) {
            resetBoard();
            printf("\n-----------------TIC TAC TOE GAME----------------\n");
            printf("\n----------------BY AYUSHMAN GHOSH----------------\n");

            int currentPlayer = 1; // 1 for Player 1 (X), 2 for Player 2 (O)
            char marker;
            while (true) {
                printBoard();
                marker = (currentPlayer == 1) ? 'X' : 'O';

                int position;
                printf("Enter the position Player %d (%c): ", currentPlayer, marker);
                scanf("%d", &position);

                if (position < 1 || position > 9 || board[position - 1] == 'X' || board[position - 1] == 'O') {
                    printf("Invalid move! Try again.\n");
                    continue;
                }

                board[position - 1] = marker;

                char winner = checkWinner();
                if (winner == 'X' || winner == 'O') {
                    printBoard();
                    printf("************* PLAYER %d (%c) WINS! *************\n", currentPlayer, marker);
                    break;
                }

                if (isDraw()) {
                    printBoard();
                    printf("************* IT'S A DRAW! *************\n");
                    break;
                }

                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        } else if (choice == 2) {
            printf("Exiting the game. Goodbye!\n");
            break;
        } else {
            printf("Invalid selection! Please try again.\n");
        }
    }

    return 0;
}
