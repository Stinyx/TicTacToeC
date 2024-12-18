#include <stdio.h>
#define COLUMNS 15
#define ROWS 15
#define WIN 5

void printBoard(int board[COLUMNS][ROWS]){
    int middle = 1;
    int number = 1;

    printf("    ");
    for(int k = 0; k < ROWS; k++){
            printf("|%3d", k+1); }
            printf("|\n");

    for(int i = 0; i < COLUMNS; i++){
        if(middle == 1){
            for(int m = 0; m < ROWS*4+5; m++){
                printf("-");
            }
            printf("\n");
            middle = 0;
        }
        printf("|%3d", number);
        number++;
        for(int j = 0; j < ROWS; j++){
            
            printf("|");

            switch(board[i][j]){
                case 0:
                    printf("   ");
                    break;
                case 1:
                    printf(" X ");
                    break;
                case 2:
                    printf(" O ");
                    break;
                default:
                    printf("bruh");
            }

            middle = 1;
            
        }
        printf("|");
        printf("\n");
    }
    for(int m = 0; m < ROWS*4+5; m++){
        printf("-");
    }
    middle = 0;
}

int checkWinner(int board[COLUMNS][ROWS]) {
    // Check rows for a win
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j <= ROWS - WIN; j++) {
            int player = board[i][j];
            if (player != 0) {
                int win = 1;
                for (int k = 1; k < WIN; k++) {
                    if (board[i][j + k] != player) {
                        win = 0;
                        break;
                    }
                }
                if (win) {
                    return player;  // Player 1 or 2 wins
                }
            }
        }
    }

    // Check columns for a win
    for (int j = 0; j < ROWS; j++) {
        for (int i = 0; i <= COLUMNS - WIN; i++) {
            int player = board[i][j];
            if (player != 0) {
                int win = 1;
                for (int k = 1; k < WIN; k++) {
                    if (board[i + k][j] != player) {
                        win = 0;
                        break;
                    }
                }
                if (win) {
                    return player;  // Player 1 or 2 wins
                }
            }
        }
    }

    // Check diagonals for a win (top-left to bottom-right)
    for (int i = 0; i <= COLUMNS - WIN; i++) {
        for (int j = 0; j <= ROWS - WIN; j++) {
            int player = board[i][j];
            if (player != 0) {
                int win = 1;
                for (int k = 1; k < WIN; k++) {
                    if (board[i + k][j + k] != player) {
                        win = 0;
                        break;
                    }
                }
                if (win) {
                    return player;  // Player 1 or 2 wins
                }
            }
        }
    }

    // Check diagonals for a win (top-right to bottom-left)
    for (int i = 0; i <= COLUMNS - WIN; i++) {
        for (int j = WIN - 1; j < ROWS; j++) {
            int player = board[i][j];
            if (player != 0) {
                int win = 1;
                for (int k = 1; k < WIN; k++) {
                    if (board[i + k][j - k] != player) {
                        win = 0;
                        break;
                    }
                }
                if (win) {
                    return player;  // Player 1 or 2 wins
                }
            }
        }
    }

    return 0;  // No winner
}

void userInput(int board[COLUMNS][ROWS], int currentPlayer) {
    int userInput, userInput2;
    int charcount;

    // Input for Player 1 (X)
    if (currentPlayer == 0) {
        while (1) {
            printf("\n(X)Player 1 X-Coordinate location (1-%d): ", ROWS);
            scanf("%d", &userInput);

            // Clear the input buffer to avoid leftover characters
            while (getchar() != '\n'); 

            if (userInput > 0 && userInput <= ROWS) {
                userInput--; // Convert to 0-based index
                while (1) {
                    printf("\n(X)Player 1 Y-Coordinate location (1-%d): ", COLUMNS);
                    scanf("%d", &userInput2);

                    // Clear the input buffer to avoid leftover characters
                    while (getchar() != '\n'); 

                    if (userInput2 > 0 && userInput2 <= COLUMNS) {
                        userInput2--; // Convert to 0-based index
                        if (board[userInput2][userInput] == 0) {
                            board[userInput2][userInput] = 1; // Player 1 places X
                            return; // Valid move, return
                        } else {
                            printf("Position already taken, try again.\n");
                        }
                    } else {
                        printf("Invalid Y-coordinate, try again.\n");
                    }
                }
            } else {
                printf("Invalid X-coordinate, try again.\n");
            }
        }
    }

    // Input for Player 2 (O)
    else if (currentPlayer == 1) {
        while (1) {
            printf("\n(O)Player 2 X-Coordinate location (1-%d): ", ROWS);
            scanf("%d", &userInput);

            // Clear the input buffer to avoid leftover characters
            while (getchar() != '\n'); 

            if (userInput > 0 && userInput <= ROWS) {
                userInput--; // Convert to 0-based index
                while (1) {
                    printf("\n(O)Player 2 Y-Coordinate location (1-%d): ", COLUMNS);
                    scanf("%d", &userInput2);

                    // Clear the input buffer to avoid leftover characters
                    while (getchar() != '\n'); 

                    if (userInput2 > 0 && userInput2 <= COLUMNS) {
                        userInput2--; // Convert to 0-based index
                        if (board[userInput2][userInput] == 0) {
                            board[userInput2][userInput] = 2; // Player 2 places O
                            return; // Valid move, return
                        } else {
                            printf("Position already taken, try again.\n");
                        }
                    } else {
                        printf("Invalid Y-coordinate, try again.\n");
                    }
                }
            } else {
                printf("Invalid X-coordinate, try again.\n");
            }
        }
    }
}



int main(){
    int currentPlayer = 0;
    int board[COLUMNS][ROWS];
        for(int i = 0; i < COLUMNS; i++){
            for(int j = 0; j < ROWS; j++){
            board[i][j] = 0;
        }
    }

    int winner = 0;
//Loop until someone wins
    while(winner == 0){
        printBoard(board);
        userInput(board, currentPlayer);
        currentPlayer = !currentPlayer;
        winner = checkWinner(board);
        if(winner != 0){
            printBoard(board);
            printf("\nPlayer %d %s won the game!", winner, winner == 1 ? "(X)":"(O)" );
            return 0;
        }
    }
    
}



