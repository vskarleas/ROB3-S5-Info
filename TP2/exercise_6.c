#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "programmes.h"

int main(int argc, char **argv)
{
    int length, number;
    printf("Give how many numbers you want to be part of the array.\n");
    scanf("%d", &length);

    int * array = malloc(sizeof(int)*length);

    ///creation of the table that we want
    for (int i = 0; i < length; i++)
    {
        printf("Give no%d", i);
        scanf("%d", &number);
        array[i] = number;
    }

    free(array);

    
    /*
    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf(" %d ",argv[1][i] );
    }
    printf("]\n");
    */
}