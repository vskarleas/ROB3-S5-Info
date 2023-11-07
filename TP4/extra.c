#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int nbDeChiffre(int number)
{
    int counter = 0;
    int temp_number = number;
    while (temp_number != 0)
    {
        counter++;

        temp_number /= 10;
    }

    return counter;
}