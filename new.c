#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void screenClear()
{
    system("clear");
}

void printMenu()
{
    printf("1 - new game\n");
    printf("0 - exit\n");
}

int getValidInt(const char* prompt, int minValue, int maxValue) {
    char buffer[100];
    int value;
    int valid = 0;
    
    while (!valid) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        
        char* endptr;
        value = strtol(buffer, &endptr, 10);
        
        if (endptr == buffer)
        {
            printf("Enter a number!\n");
        }
        else if (*endptr != '\n' && *endptr != '\0')
        {
            printf("Enter a number, not letter!\n");
        }
        else if (value < minValue || value > maxValue)
        {
            printf("The number must be between %d and %d!\n", minValue, maxValue);
        }
        else
        {
            valid = 1;
        }
    }
    
    return value;
}

int main(void)
{    
    int appRun = 1;

    while (appRun)
    {
        printMenu();

        int menuPoint = getValidInt("", 0, 1);

        if (menuPoint == 0)
        {
            printf("selected quit\n");
            appRun = 0;
            continue;
        }

        if (menuPoint == 1)
        {
            printf("selected new game\n");
            char board[BOARD_SIZE][BOARD_SIZE];
            initBoard(board);
            screenClear();
            printBoard(board);
            char currentPlayer = PLAYER_X;
            int gameState = CONTINUES;

            while (gameState == CONTINUES)
            {
                int validMove = 0;
                int position;

                while (!validMove)
                {
                    char movePrompt[128];
                    sprintf(movePrompt, "Player %c turn.\nEnter 1-%d: ", currentPlayer, MAX_POSITION);
                    position = getValidInt(movePrompt, 1, MAX_POSITION);
                    
                    if (makeMove(board, position, currentPlayer) == 0)
                    {
                        validMove = 1;
                    }
                    else printf("This position is not empty or position is more than %d!\n", MAX_POSITION); 
                }

                if (currentPlayer == PLAYER_X)
                {
                    currentPlayer = PLAYER_O;
                }
                else currentPlayer = PLAYER_X;
                screenClear();
                printBoard(board);
                gameState = checkWin(board);
            }
            
            if (gameState == X_WIN)
            {
                printf("Player X WINS!\n");
            } else if (gameState == O_WIN)
            {
                printf("Player O WINS!\n");
            } else if (gameState == DRAW)
            {
                printf("It's a draw!\n");
            }
        }
    }

    return 0;
}