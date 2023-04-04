#include <stdio.h>
#include <stdlib.h>
#include "resistor.h"
#include "board.h"

int addResistor(int beginningX, int endingX, int axisy)
{

    struct Board *board;
    board = retriveBoard();

    if (axisy > board->rows || axisy < 0) // kolla rader innan jag kollar efter 0:or. Kan inte kolla efter 0:or på rad som inte existerar.
    {
        printf("Error, try again!\n");
        return -1;
    }
    for (int i = beginningX; i <= endingX; i++)
    {
        if (board->board[axisy][i] != '0')
        {
            printf("Error, try again!\n");
            return -1;
        }
    }

    board->board[axisy][beginningX] = 'R';
    board->board[axisy][endingX] = 'x';

    beginningX++; // Om jag inte skulle ha denna skulle den loopa över första X

    for (; beginningX < endingX; beginningX++)
    {
        board->board[axisy][beginningX] = '-';
    }

    printf("You've added a reistor");
    return 0;
}

int deleteResistor(int leftleg, int row)
{
    struct Board *board;
    board = retriveBoard();
    int currentColumn = leftleg;
    if (board->board[row][leftleg] == 'R')
    {
        while (board->board[row][currentColumn] != 'x')
        {
            board->board[row][currentColumn] = '0';
            currentColumn++;
        }
        board->board[row][currentColumn] = '0';
        printf("You have deleted a resistor!\n");
    }
    else
    {
        printf("Wrong, select from first point of your resistor!");
    }

    return 0;
}
