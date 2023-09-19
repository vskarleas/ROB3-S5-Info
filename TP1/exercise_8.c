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

    int state = -2;
    /*The defined states are:
    -| 1: multple de 3 et finis sur 3
    -| 2: multple de 7 et finis sur 7
    -| 3: 1& 2 verfiies
    -| 0: Just a number  */

    for (int i = 1; i<=100; i++)
    {
        /*
        if (verification_ends_to(i, 7))
        {
            printf(" %dSEVEN ", i);
        }
        else
        {
            printf(" %d ", i);
        }
        */
       
        //Logic section
        if ((mutliple_verification(i, 3)) || verification_ends_to(i, 3)) //if this is true then it's a multiple of three and ends to 3
        {
            state = 1; 
            if ((mutliple_verification(i, 7)) || verification_ends_to(i, 7)) //if this is true then both conditions are met
            {
                state = 3;
            }
        }
        else if ((mutliple_verification(i, 7)) || verification_ends_to(i, 7)) //if this is true then it's a multiple of seven and ends to 7
        {
            state = 2;
        }
        else 
        {
            state = 0;
        }
        


        //Affichage section
        if (state == 3)
        {
            printf("FizzBuzz ");
        }
        else if (state == 1)
        {
            printf("Fizz ");
        }
        else if (state == 2)
        {
            printf("Buzz ");
        }
        else
        {
            printf("%d ", i);
        }
        state = -2;
    }

    

    return 0;
}