#include "programmes.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 200000

/* Programme modifie (original exercise_13-1.c) pour qu’il affiche
 la liste de tous les nombres premiers infé- rieurs ou égaux à MAX.
  La valeur de MAX sera définie en utilisant la directive #define*/

int main(int argc, char **argv)
{
    bool premier;
    printf("List of primier number:\n");
    for (int i = MAX; i > 0; i--) //zero not included in the analysis
    {
        premier = premier_number_or_not(i);
        if (premier)
        {
            printf("%d, ", i);
        }
    }
    printf("0\n"); //zero is always a premier number 

    return 0;
}