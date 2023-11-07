#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initialization(int NB_ROWS, int NB_COLS, int *tab)
{
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
    
}

void affiche_mat(int NB_ROWS, int NB_COLS, int *tab)
{
    /* Accessing the array values as if it was a 2D array to print it on the terminal*/
    for (int i = 0; i < NB_ROWS; i++) {
        for (int j = 0; j < NB_COLS; j++)
        {
            printf("%d ", tab[i * NB_COLS + j]);
        }
        printf("\n");
    }
}