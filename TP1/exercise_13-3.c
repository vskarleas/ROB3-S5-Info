#include "programmes.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>


/* Modifiez le programme (exercise 13-2) pour qu’il demande à l’utilisateur 
de saisir une valeur entière m. Le programme affiche ensuite tous les 
entiers de 2 à m en les séparant par des tabulations (’\t’) et en passant 
à la ligne après chaque nombre premier. */

int main(int argc, char **argv)
{
    bool premier, repeat;
    int m;
    repeat = true;
    while (repeat)
    {
        printf("Give a number m (postive):\n");
        scanf("%d", &m);

        if (m>=2)
        {
            repeat = false;
        }

    }
    
    for (int i = 2; i <= m; i++) //de 2 à m
    {
        premier = premier_number_or_not(i);
        if (premier)
        {
            printf("%d\n", i);
        }
        else 
        {
            printf("%d\t", i);
        }
    }
    printf("\n");

    return 0;
}