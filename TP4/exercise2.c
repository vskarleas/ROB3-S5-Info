#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NB_NUMBERS 17

int main(int argc, char **argv)
{
    int * tab = malloc(sizeof(int)*NB_NUMBERS);

    if (tab == NULL) {
        printf("ERROR: malloc failed!\n");
        exit(1);
    }

    //just filling the table in order to say that the program is doing soemthing to the created table before FREEing it
    for (int i = 0; i < NB_NUMBERS; i++)
    {
        tab[i] = i+1;
    }

    //printing the table
    for (int i = 0; i < NB_NUMBERS; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    //free up the allocated memory
    free(tab);
    return 0;
    
}