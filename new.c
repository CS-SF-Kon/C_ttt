#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void ScreenClear()
{
    system("clear");
}

void printMenu()
{
    printf("1 - new game\n");
    printf("0 - exit\n");
}

int main(void)
{
    start:
    
    printMenu();
    int menuPoint;

    scanf("%i", &menuPoint);
    
    if (menuPoint == 0)
    {
        printf("selected quit\n");
        return 0;
    }
    if (menuPoint == 1) printf("selected new game\n");

    char board[BOARD_SIZE][BOARD_SIZE];

    initBoard(board);

    ScreenClear();

    printBoard(board);

    char currentPlayer = PLAYER_X;

    int gameState = 0;

    while (gameState == 0)
    {
        printf("Player %c turn\n", currentPlayer);
        int position;

        again:

        scanf("%i", &position);

        if (makeMove(board, position, currentPlayer))
        {
            printf("This position is not empty!\n");
            goto again;
        }

        if (currentPlayer == PLAYER_X)
        {
            currentPlayer = PLAYER_O;
        }
        else currentPlayer = PLAYER_X;

        ScreenClear();

        printBoard(board);
        
        gameState = checkWin(board);
    }
    
    if (currentPlayer == PLAYER_X)
    {
        currentPlayer = PLAYER_O;
    }
    else currentPlayer = PLAYER_X;

    printf("Player %c wins!\n", currentPlayer);

    goto start;

    return 0;
}