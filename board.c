#include <stdio.h>
#include <stdlib.h>
#include "board.h"

struct Board board;

int addBoard(int rows, int cols)
{
    board.rows = rows;
    board.cols = cols;

    board.board = malloc(sizeof(char *) * rows);

    for (int i = 0; i < rows; i++)
    {
        board.board[i] = malloc(cols * sizeof(char));
    }

    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            board.board[x][y] = '0';
        }
    }
    // Free malloc?
    /*for (int i = 0; i < rows; i++)
    {
        free(board.board[i]);
    }
    free(board.board);*/
    return 0;
}

struct Board *retriveBoard()
{
    return &board;
}
