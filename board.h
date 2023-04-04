#ifndef BOARD_H // För att man inte ska kunna definera två gånger
#define BOARD_H

struct Board
{
    int rows, cols;
    char **board;
};

int addBoard(int rows, int cols);
struct Board *retriveBoard(); // I H filen deklarerar man funktioner, structar och andra typer för att sedan använda den efter att man skapat funktionen.

#endif /* ifndef BOARD_H */