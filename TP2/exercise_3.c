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
    int array[N]; //an array of N numbers, so we create N positions in the array

    srand(time(NULL));
    for (int i = 0; i <N; i++)
    {
        number = random_number(P); //gives random numbers between 1 and P
        array[i] = number;
    }

    printf("BEFORE the doublons treatment:\n");
    //TRY TO MAKE IT A FUNCTION!!!
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ",array[i] );
    }
    printf("]\n");


    //logic below
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; array[j] != '\0'; j++)
        {
            if (array[j] == array[i])
            {
                /*
                for (int k = j; array[k] != '\0';)
                {
                    array[k] = array[k + 1];
                }

                */
               array[j] = 0; //replaces the duplicate with zero
            }

        }
    }

    printf("AFTER the doublons treatment:\n");
    //TRY TO MAKE IT A FUNCTION!!!
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ",array[i] );
    }
    printf("]\n");
    return 0;
}