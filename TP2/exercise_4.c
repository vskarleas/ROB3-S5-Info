#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "programmes.h"

#define N 10
#define P 2

int main(int argc, char **argv)
{
    srand(time(NULL));

    int number, r;
    int T[N]; //an array of N numbers, so we create N positions in the array
    number = random_number_with_minimum(1, 10);
    T[0] = number; //starts from zero the numeration on c
    r = random_number_with_minimum(0, P);

    for (int i = 1; i < N; i++)
    {
        T[i] =  T[i-1] + r;
    }

    printf("We take the croissant array:\n");
    affiche_array(T, N);

    return 0;
}