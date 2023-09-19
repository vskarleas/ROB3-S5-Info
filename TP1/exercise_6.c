#include "programmes.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        printf("No arguments are required for this program to run\n");
        exit(-2);
    }
    
    int a, b;

    bool repeat = true;
    while (repeat)
    {
        printf("=====================\n");
        printf("\n");

        printf("Give the 1st number : ");
        scanf("%d", &a);

        printf("Give the 2nd number : ");
        scanf("%d", &b);

        if (a > 0 && b > 0)
        {
            printf("The GCD of %d and %d is: %d\n", a, b, calculer_pgcd(a, b));
            repeat = false;
        }
        else
        {
            printf("=====================\n");
            printf("We need two strictly positive numbers\n");
        }
    }

    return 0;
}