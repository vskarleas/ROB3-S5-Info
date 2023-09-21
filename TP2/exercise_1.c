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

    //Initialize of srand for random_number_with_minimum generator
    srand(time(NULL));

    for (int i = 0; i <N; i++)
    {
        number = random_number_with_minimum(1, P); //random number between 1 and P
        array[i] = number;
    }

    printf("The constructed array is\n");
    affiche_array(array, N);

    return 0;
}