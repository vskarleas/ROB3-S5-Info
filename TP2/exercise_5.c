#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "programmes.h"

#define N 20
#define P 10

int main(int argc, char **argv)
{
    int number, r;

    int T[N]; //an array of N numbers, so we create N positions in the array
    srand(time(NULL)); //seconds from the very first january of the current year

    number = random_number_with_minimum(0 , P);
    T[0] = number; //starts from zero the numeration on c


    for (int i = 1; i < N; i++)
    {
        r = random_number_with_minimum(0, P); //based on the alogrithm of the exercise 4
        T[i] =  T[i-1] + r;
    }
    printf("BEFORE TREATMENT:\n");
    affiche_array(T, N);

    //logic below with one only boucle for
    int i;
    for (i = 0; i < N-1; i++)
    {
        if (T[i] == T[i+1])
        {
            T[i+1] = 0;
        }
    }
    
    if (T[i+1] == T[N-1])
    {
        T[N-1] = 0;
    }

    printf("AFTER TREATMENT\n");
    printf("We take the croissant array (without doublons):\n");
    affiche_array(T, N);

    return 0; 
}