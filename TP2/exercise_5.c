#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "programmes.h"

#define N 10
#define P 10

int main(int argc, char **argv)
{
    int number, r, index_number;
    int T[N]; //an array of N numbers, so we create N positions in the array

    srand(time(NULL)); //seconds from the very first january of the current year

    number = random_number(P);

    T[0] = number; //starts from zero the numeration on c
    r = random_number(3);

    for (int i = 1; i < N; i++)
    {
        index_number = T[i-1] + r;
        T[i] = index_number;
    }
    //Tableau deja trie est sauvegardé sur T

    //logic below
    for (int i = 0; i < N; i++)
    {
        if (i != N-2)
        {
            if (T[i] == T[i+1])
            {
                T[i] = T[i+1];
            }
        }
    }

    printf("We take the croissant array (without doublons):\n");
    //TRY TO MAKE IT A FUNCTION!!!
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ",T[i] );
    }
    printf("]\n");
    return 0; 
}