#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "programmes.h"

#define N 10

int main(int argc, char **argv)
{
    int * table = malloc(sizeof(int)*N);
    int count=0;

    srand(time(NULL));//initialisation of the random number generator

    for (int i=0; i<N-1; i++)
    {
        table[i] = random_number_with_minimum(0, 1);
    }

    for (int i=0; i<N-1; i++)
    {
        if (table[i] == 1)
        {
            count ++;
        }
    }

    table[N-1] = count % 2;

    printf("Here is the result of the exercise: \n");
    affiche_array(table, N);

    return 0;
}