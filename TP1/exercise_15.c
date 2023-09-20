#include "programmes.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define NB_RANG 5
#define NB_PLACES 5 //number of seats for every rang
#define MAX_GROUPE 12 //Number of groupes

int main(int argc, char **argv)
{
    int available = NB_RANG * NB_PLACES; //calculating available seats
    printf("There are %d seats available\n", available); 
    printf("================================================================\n\n\n");


    int current_seat = 0;
    int current_row = 1;
    int x;

    srand(time(0));

  while (current_row < NB_RANG) //number of rows
    {
        x = random_number_v2(MAX_GROUPE);
        printf("There are %d persons\n", x);
        for (int j = 1; j <= x; j++) //counts the x
        {
            current_seat ++;
            if (current_seat == NB_PLACES)
            {
                printf("We place %d on row %d\n", current_seat, current_row);
                current_row ++;
                current_seat = 0;
            }
        }
        if (current_seat > NB_PLACES)
        {
            printf("We place %d on row %d\n", current_seat-NB_PLACES, current_row);
        }
        else
        {
            printf("We place %d on row %d\n", -(NB_PLACES - current_seat - NB_PLACES), current_row); //find the correct value for the current number of seats based on the existing occupied ones
        }
        
        //mis a jour des 
        if (available-x >= 0)
        {
            printf("Remain %d seats available\n\n",available-x);
            available = available - x;
        }
        else
        {
            printf("We can't place the group of %d since there aren't so many available seats.\n",x);
            break;
        }

        current_seat = 0;
    }

    return 0;
}