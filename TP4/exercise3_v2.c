#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NB_ROWS 15
#define NB_COLS 17

int main(int argc, char **argv)
{
    int **tab;
    tab = malloc(NB_ROWS * sizeof(int **));

     if (tab == NULL) {
        printf("ERROR: malloc allocation failed!\n");
        exit(1);
    }

    //table on table IDEA
    for (int i = 0; i < NB_ROWS; i++)
    {
        tab[i] = malloc(NB_COLS * sizeof(int));
    }


    // just filling the table in order to say that the program is doing soemthing to the created table before FREEing it
    int k =1;
    for (int i = 0; i < NB_ROWS; i++)
    {
        for(int j = 0; j < NB_COLS; j++)
        {
            tab[i][j] = k;
            k ++;
        }
    }



    for (int i = 0; i < NB_ROWS; i++) {
        for (int j = 0; j < NB_COLS; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // free up the allocated memory
    free(tab);
    return 0;
}