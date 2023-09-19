#include "programmes.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>


/* Programme pour la premier question de l'exercise 13*/

int main(int argc, char **argv)
{
    bool premier;
    int luck;
    luck = random_number(1, 99); //A random number between 1 and 99
    printf("The number %d chose from the program is ", luck);
    premier = premier_number_or_not(luck);
    if (premier)
    {
            printf("premier\n");
    }
    else
    {
        printf("NOT premier\n");
    }

    return 0;
}