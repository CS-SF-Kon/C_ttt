#include <stdio.h>
#include "game.h"

void initBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY_CELL;
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
    if ((position > MAX_POSITION) || (board[(position - 1) / 3][(position - 1) % 3] != EMPTY_CELL)) return 1;
    else
    {
        board[(position - 1) / 3][(position - 1) % 3] = currentPlayer;
        return 0;
    }
}

int rowCheck(char row[3])
{
    if (row[0] == row[1] && row[0] == row[2] && row[0] != EMPTY_CELL)
    {
        return 1;
    }

    return 0;
}

enum game_state returner(char cell)
{
    if (cell == PLAYER_X) return X_WIN; else return O_WIN;
}

enum game_state checkWin(const char board[BOARD_SIZE][BOARD_SIZE])
{
    char testH[3];
    char testV[3];
    char testDiag[3];
    char testDiag2[3];
    int hasEmpty = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            testH[j] = board[i][j];
            testV[j] = board[j][i];
            if (board[i][j] == EMPTY_CELL)
            {
                hasEmpty = 1;
                break;
            }
        }

        if (rowCheck(testH))
        {
            return returner(testH[0]);
        }
        
        if (rowCheck(testV))
        {
            return returner(testV[0]);
        }

        testDiag[i] = board[i][i];
        testDiag2[i] = board[i][2-i];
        if (hasEmpty) break;
    }

    if (rowCheck(testDiag))
    {
        return returner(testDiag[0]);
    }

    if (rowCheck(testDiag2))
    {
        return returner(testDiag2[0]);
    }

    if (!hasEmpty) return DRAW;
    return CONTINUES;
}