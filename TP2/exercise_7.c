#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "programmes.h"

#define N 20
#define P 2

int main(int argc, char **argv)
{
    srand(time(NULL));

    int number, r;
    int T[N]; //an array of N numbers, so we create N positions in the array
    number = random_number_with_minimum(1, 10);
    T[0] = number; //starts from zero the numeration on c

    for (int i = 1; i < N; i++)
    {
        r = random_number_with_minimum(0, P);
        T[i] =  T[i-1] + r;
    }

    printf("We have the array:\n");
    printf("NOTE: The array may iclude doublons.\n");
    affiche_array(T, N);

    int fisher;
    int temp;
    //logic of Fisher algorithm
    for (int i = 0; i < N; i++)
    {
        if (i+1 == N)
        {
            fisher = random_number_with_minimum(i, N-1);
            temp = T[i];
            T[i] = T[fisher];
            T[fisher] = temp;
        }
        else
        {
            fisher = random_number_with_minimum(i+1, N-1);
            temp = T[i];
            T[i] = T[fisher];
            T[fisher] = temp;
        }
        
    }

    printf("We take the array treated based on Fisher algorythm:\n");
    affiche_array(T, N);

    return 0;
}