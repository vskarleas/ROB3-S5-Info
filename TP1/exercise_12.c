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

    int a, result;

    bool repeat = true;
    while (repeat)
    {
        printf("=====================\n");
        printf("\n");

        printf("Give a number : ");
        scanf("%d", &a);

        if (a >= 0)
        {
            repeat = false;

            char str[ENOUGH];
            result = number_of_specified_number(a, str);
        }
        else
        {
            printf("=====================\n");
            printf("We need one positive number or equal to 0. Try again!\n");
        }
    }

    printf("For the number %d, %d ones were detected", a, result);

    return 0;
}