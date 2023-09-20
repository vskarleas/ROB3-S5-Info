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
    int number, n;
    int array[N]; //an array of N numbers, so we create N positions in the array
    srand(time(NULL));

    for (int i = 0; i <N; i++)
    {
        number = random_number(P);
        array[i] = number;
    }


    printf("Give a number :");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        if (array[i] == n)
        {
            printf("%d exists on the generated array on position (index) %d\n", n, i);
            return 0;
        }
    }
    printf("We did not found n on the generated array which was\n");

    //TRY TO MAKE IT A FUNCTION!!!
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ",array[i] );
    }
    printf("]\n");
    return 0;
}