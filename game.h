#ifndef GAME_H
#define GAME_H
#endif
#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_CELL '_'
#define MAX_POSITION (BOARD_SIZE * BOARD_SIZE)

enum game_state
{
    CONTINUES,
    DRAW,
    X_WIN,
    O_WIN
};

void initBoard(char board[BOARD_SIZE][BOARD_SIZE]);

void printBoard(const char board[BOARD_SIZE][BOARD_SIZE]);

int makeMove(char board[BOARD_SIZE][BOARD_SIZE], int position, char currentPlayer);

enum game_state checkWin(const char board[BOARD_SIZE][BOARD_SIZE]);