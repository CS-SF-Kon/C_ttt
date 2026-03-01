#include <stdio.h>
#include "game.h"

void initBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '_';
        }
    }
}

void printBoard(const char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int makeMove(char board[BOARD_SIZE][BOARD_SIZE], int position, char currentPlayer)
{
    if (board[(position - 1) / 3][(position - 1) % 3] == '_')
    {
        board[(position - 1) / 3][(position - 1) % 3] = currentPlayer;
        return 0;
    }
    return 1;
}

int checkWin(const char board[BOARD_SIZE][BOARD_SIZE])
{
    char test[3];
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            test[j] = board[i][j];
        }
        if (test[0] == test[1] && test[0] == test[2])
        {
            if (test[0] == 'X') return 1;
            if (test[0] == 'O') return 2;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            test[j] = board[j][i];
        }
        if (test[0] == test[1] && test[0] == test[2])
        {
            if (test[0] == 'X') return 1;
            if (test[0] == 'O') return 2;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        test[i] = board[i][i];
        if (test[0] == test[1] && test[0] == test[2])
        {
            if (test[0] == 'X') return 1;
            if (test[0] == 'O') return 2;
        }
    }

    test[0] = board[0][2];
    test[1] = board[1][1];
    test[2] = board[2][0];
    if (test[0] == test[1] && test[0] == test[2])
        {
            if (test[0] == 'X') return 1;
            if (test[0] == 'O') return 2;
        }

    return 0;
}

int isBoardFull(const char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ') return 0;
        }
    }

    return 1;
}