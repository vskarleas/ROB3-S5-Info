#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "extra.h"

#define NB_ROWS 15
#define NB_COLS 17

int main(int argc, char **argv)
{
    int *tab = malloc((NB_ROWS * NB_COLS) * sizeof(int));

    // It's like having a huge horizontale table
    // just filling the table in order to say that the program is doing soemthing to the created table before FREEing it
    for (int i = 0; i < NB_ROWS * NB_COLS; i++)
    {
        tab[i] = i + 1;
    }
 

    /* Accessing the array values as if it was a 2D array */
    for (int i = 0; i < NB_ROWS; i++) {
        for (int j = 0; j < NB_COLS; j++)
        {
            printf("%d ", tab[i * NB_COLS + j]);
        }
        printf("\n");
    }
    printf("\n");

    // free up the allocated memory
    free(tab);
    return 0;
}