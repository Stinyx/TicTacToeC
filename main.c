#include <stdio.h>
#define COLUMNS 5
#define ROWS 5

void printBoard(int board[COLUMNS][ROWS]){
    int middle = 1;
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

void userInput(int board[COLUMNS][ROWS], int currentPlayer){
    int userInput;

    if(currentPlayer == 0){
        while(1){
            printf("\nplayer 1 give location whore:");
            scanf("%d", &userInput);

            if(userInput <= 0 || userInput < COLUMNS*ROWS){
                userInput--;
                if(board[userInput/COLUMNS][userInput%COLUMNS] == 0){
                    board[userInput/COLUMNS][userInput%COLUMNS] = 1;
                    return;
                }else(printf("\ninvalid position"));
            }
        };
        
    }else if(currentPlayer == 1){
        while(1){
                printf("\nplayer 2 give location whore:");
                scanf("%d", &userInput);

                if(userInput <= 0 || userInput < COLUMNS*ROWS){
                    userInput--;
                    if(board[userInput/COLUMNS][userInput%COLUMNS] == 0){
                        board[userInput/COLUMNS][userInput%COLUMNS] = 2;
                        return;
                    }else(printf("\ninvalid position"));
                    
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
    while(1){
        printBoard(board);
        userInput(board, currentPlayer);
        currentPlayer = !currentPlayer;
    }
    
}




