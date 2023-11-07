#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions-exo4.h"

int main(int argc, char **argv)
{
    int NB_ROWS, NB_COLS;

    bool repeat = true;

    while (repeat)
    {
        printf("Give us the number of rows and the number of collumns for the matrix: ");
        scanf("%d%d", &NB_ROWS, &NB_COLS);
        printf("\n");

        if (NB_COLS < 1 || NB_ROWS < 1)
        {
            printf("\n================================\n");
            printf("We need a table at least 1 column and 1 row\n");
            printf("TRY AGAIN\n\n");
        }
        else
        {
            repeat = false;
        }
    }

    // table creation
    int *tab = malloc((NB_ROWS * NB_COLS) * sizeof(int));

    // table initailization
    initialization(NB_ROWS, NB_COLS, tab);

    printf("\n\nPrintign the created matrix:\n");
    affiche_mat(NB_ROWS, NB_COLS, tab);
    printf("\n");

    // free up the allocated memory
    free(tab);
    return 0;
}