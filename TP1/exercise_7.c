#include "programmes.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ENOUGH 256

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        printf("No arguments are required for this program to run\n");
        exit(-2);
    }

    int a;

    bool repeat = true;
    while (repeat)
    {
        printf("=====================\n");
        printf("\n");

        printf("Give a striclty postive number : ");
        scanf("%d", &a);

        if (a > 0)
        {
            char str[ENOUGH];
            printf("This number reversed method V1 is: %d\n",inverser_entier(a));
            printf("This number reversed method V2 is: %d\n",inverser_entier_v2(a));
            printf("This number reversed method V3 is: %s\n",inverser_entier_v3(a, str)); //Importan tto pass the string that it needs localy, otherwise there will be an error with addesses!
            repeat = false;
        }
        else
        {
            printf("=====================\n");
            printf("We need one strictly positive number. Try again!\n");
        }
    }

    return 0;
}