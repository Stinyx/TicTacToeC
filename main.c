#include <stdio.h>
#define COLUMNS 5
#define ROWS 5
#define WIN 2

void printBoard(int board[COLUMNS][ROWS]){
    int middle = 1;

    for(int k = 0; k < ROWS; k++){
            printf("| %d ", k+1); }
            printf("|\n");

    for(int i = 0; i < COLUMNS; i++){
        if(middle == 1){
            for(int m = 0; m < ROWS*4; m++){
                printf("-");
            }
            printf("\n");
            middle = 0;
        }
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
    for(int m = 0; m < ROWS*4; m++){
        printf("-");
    }
    middle = 0;
}

int checkWinner(int board[COLUMNS][ROWS]) {
    // Check rows for a win
    for (int i = 0; i < COLUMNS; i++) {
        int player = board[i][0];
        if (player != 0) {
            int win = 1;
            for (int j = 1; j < WIN; j++) {
                if (board[i][j] != player) {
                    win = 0;
                    break;
                }
            }
            if (win) {
                return player;  // Player 1 or 2 wins
            }
        }
    }

    // Check columns for a win
    for (int j = 0; j < ROWS; j++) {
        int player = board[0][j];
        if (player != 0) {
            int win = 1;
            for (int i = 1; i < WIN; i++) {
                if (board[i][j] != player) {
                    win = 0;
                    break;
                }
            }
            if (win) {
                return player;  // Player 1 or 2 wins
            }
        }
    }

    // Check diagonals for a win (top-left to bottom-right)
    int player = board[0][0];
    if (player != 0) {
        int win = 1;
        for (int i = 1; i < WIN; i++) {
            if (board[i][i] != player) {
                win = 0;
                break;
            }
        }
        if (win) {
            return player;  // Player 1 or 2 wins
        }
    }

    // Check diagonals for a win (top-right to bottom-left)
    player = board[0][ROWS-1];
    if (player != 0) {
        int win = 1;
        for (int i = 1; i < WIN; i++) {
            if (board[i][ROWS-i-1] != player) {
                win = 0;
                break;
            }
        }
        if (win) {
            return player;  // Player 1 or 2 wins
        }
    }

    return 0;  // No winner
}

void userInput(int board[COLUMNS][ROWS], int currentPlayer){
    int userInput;
    int userInput2;

    if(currentPlayer == 0){
        while(1){
            printf("\n(X)Player 1 X-Coordinate location:");
            scanf("%d", &userInput);
            

            if(userInput <= 0 || userInput <= ROWS){
                userInput--;
                printf("(X)Player 1 Y-Coordinate location:");
                scanf("%d", &userInput2);
                if(userInput2 <= 0 || userInput2 <= COLUMNS){
                    userInput2--;
                    if(board[userInput2][userInput] == 0){
                        board[userInput2++][userInput++] = 1;
                    return;
                }else(printf("\ninvalid position"));
                }
                
            }else(printf("\ninvalid position"));
        };
        
    }else if(currentPlayer == 1){
        while(1){
            printf("\n(O)Player 2 X-Coordinate location:");
            scanf("%d", &userInput);
            

            if(userInput <= 0 || userInput <= ROWS){
                userInput--;
                printf("(O)Player 2 Y-Coordinate location:");
                scanf("%d", &userInput2);
                if(userInput2 <= 0 || userInput2 <= COLUMNS){
                    userInput2--;
                    if(board[userInput2][userInput] == 0){
                        board[userInput2++][userInput++] = 2;
                    return;
                }else(printf("\ninvalid position"));
                }
                
            }else(printf("\ninvalid position"));
        };
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
    while(1){
        printBoard(board);
        userInput(board, currentPlayer);
        currentPlayer = !currentPlayer;
        int winner = checkWinner(board);
        if(winner != 0){
            printBoard(board);
            printf("\nPlayer %d %s won the game!", winner, winner == 1 ? "(X)":"(O)" );
            return 0;
        }
    }
    
}




