#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "resistor.h"

int buildBoard()
{
    int rows, cols;
    int t = 1;
    while (t)
    {
        printf("Enter a number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);
        getc(stdin);

        if (rows <= 0 || rows > 30 || cols <= 0 || cols > 10)
        {
            printf("\n");
            printf("Enter a correct value\n");
        }
        else
        {
            t = 0;
        }
    }

    addBoard(rows, cols); // allokerar minne med hjälp av malloc

    return 0;
}

int showBoard()
{
    struct Board *board;

    board = retriveBoard(); // När vi anropar retriveboard så returnerar den adressen till structen som vi har skapat brädan på/i.

    printf("\n");
    printf("  ");
    for (int i = 0; i < board->cols; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int x = 0; x < board->rows; x++)
    {
        printf("%d ", x);
        for (int y = 0; y < board->cols; y++) // loop för både rad och col.
        {
            printf("%c ", board->board[x][y]); // Sätter alla värden på brädan till 0.
        }
        printf("\n");
    }

    return 0;
}
int createResistor()
{
    int pointA, pointB, y;
    printf("Enter column of first point of the resistor: ");
    scanf("%d", &pointA);
    printf("Enter second column point of the resistor: ");
    scanf("%d", &pointB);
    printf("Select row: ");
    scanf("%d", &y);
    if (pointA >= pointB)
    {
        printf("Wrong input!");
    }
    else
    {

        addResistor(pointA, pointB, y);
    }

    return 0;
}

int removeResistor()
{
    int column, row;

    printf("Enter column of leftleg of the resistor: ");
    scanf("%d", &column);
    printf("Enter which row: ");
    scanf("%d", &row);
    deleteResistor(column, row);
    return 0;
}

int userMenu()
{
    int choice;
    printf("\n");
    printf("1. Add resistor to bredboard\n");
    printf("2. Remove resistor from bredboard\n");
    printf("3. Quit program\n");
    printf("\n");
    printf("Make a choice:");
    scanf("%d", &choice);
    getc(stdin);

    switch (choice)
    {
    case 1:
        createResistor();
        break;
    case 2:
        removeResistor();
        break;
    case 3:
        printf("You've given up!\n");
        exit(EXIT_SUCCESS);
    default:
        printf("Wrong input, try again!\n");
        break;
    }

    return 0;
}

int main()
{
    buildBoard();

    while (1)
    {
        showBoard();
        userMenu();
    }

    return 0;
}