#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/* Generates random Numbers from 1 to P given a sargument*/
int random_number(int P)
{
    int num;
    num = (rand() % P) + 1;
    return num;
}

/*It shows on the terminal a vertical array composed of numbers*/
//IT DOESN"T WORK, NEEDS TO BE FIXED
void affiche_array(int ** array, int N)
{
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ",*(array[i]) );
    }
    printf("]\n");
}

