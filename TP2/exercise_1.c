#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "programmes.h"

#define N 10
#define P 100

int main(int argc, char **argv)
{
    int number;
    int array[N]; //an array of numbers
    srand(time(NULL));

    for (int i = 0; i <N; i++)
    {
        number = random_number(P);
        array[i] = number;
    }

    printf("The constructed array is\n");

    //TRY TO MAKE IT A FUNCTION!!!
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ",array[i] );
    }
    printf("]\n");

    return 0;
}