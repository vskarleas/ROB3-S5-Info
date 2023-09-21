#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "programmes.h"

int main(int argc, char **argv)
{
    int length, number, l, j, temp;
    printf("Give how many numbers you want to be part of the array ? ");
    scanf("%d", &length);
    printf("\n\n");

    //creation du tableau
    int * array = malloc(sizeof(int)*length);

    ///creation of the table that we want
    for (int i = 0; i < length; i++)
    {
        printf("Give no %d: ", i+1);
        scanf("%d", &number);
        array[i] = number;
    }

    printf("====================\n");
    printf("Give index of the number that you want to be exchanged: ");
    scanf("%d", &l);
    printf("\n");
    printf("Now give the index of the number of which it will be exchanged the previous one: ");
    scanf("%d", &j);
    printf("\n");

    temp = array[l-1]; //because the user does not give the real index but the one it sees on the screen
    array[l-1] = array[j-1];
    array[j-1] = temp;

    printf("Here is the final array:\n");
    affiche_array(array, length);
    
    free(array);

    return 0;
}