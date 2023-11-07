#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "function-exo2.h"


int main(int argc, char **argv)
{
    int NB_ROWS, NB_COLS;

    printf("Give us the number of rows for the matrix.\n");
    printf("Rows = ");
    scanf("%d", &NB_ROWS);
    printf("\n");

    printf("Give us the number of collumns for the matrix.\n");
    printf("Cols = ");
    scanf("%d", &NB_COLS);
    printf("\n");

    //tabel creation
    int *tab = malloc((NB_ROWS * NB_COLS) * sizeof(int));

    int x;
    //Asking numbers from user to be added on the creaed matrix
    for (int i = 0; i < NB_ROWS; i++) {
        for (int j = 0; j < NB_COLS; j++)
        {
            printf("Number for position (%d, %d) ? ", i+1, j+1);
            scanf("%d", &x);

            tab[i * NB_COLS + j] = x;;
        }
    }
    printf("\n\n");

    printf("Printign the created matrix:\n");
    /* Accessing the array values as if it was a 2D array to print it on the terminal*/
    for (int i = 0; i < NB_ROWS; i++) {
        for (int j = 0; j < NB_COLS; j++)
        {
            printf("%d ", tab[i * NB_COLS + j]);
        }
        printf("\n");
    }
    printf("\n");

    /*Printing teh row and the collumn chosen fro the user using the affichemat(m,l,c) function*/
    //TO BE COMPLETED at the file function-exo2.c

    // free up the allocated memory
    free(tab);
    return 0;
}