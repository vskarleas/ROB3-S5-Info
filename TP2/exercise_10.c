#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "programmes.h"

#define STUDENTS_NUMBER 1000

int main(int argc, char **argv)
{
    srand(time(NULL)); //initilaisation so that the function random_number_with_minimum(min, max) can work properly

    //table creation
    int * notes = malloc(sizeof(int)*STUDENTS_NUMBER);
    int notes_[21];

    //tables initialisation
    for (int i=0; i<STUDENTS_NUMBER; i++)
    {
        notes[i] = random_number_with_minimum(0,20);
    }

    //initialising the mirror array
    for (int i=0; i<21; i++)
    {
        notes_[i] = 0; //this table is used to create the final histogram
    }

    //scanning the notes table and updating notes_ accordingly
    for (int i=0; i<STUDENTS_NUMBER; i++)
    {
        switch(notes[i])
        {
            case 0:
                updating_index(0, notes_);
                break;

            case 1:
                updating_index(1, notes_);
                break;
            case 2:
                updating_index(2, notes_);
                break;
            case 3:
                updating_index(3, notes_);
                break;
            case 4:
                updating_index(4, notes_);
                break;
            case 5:
                updating_index(5, notes_);
                break;
            case 6:
                updating_index(6, notes_);
                break;
            case 7:
                updating_index(7, notes_);
                break;
            case 8:
                updating_index(8, notes_);
                break;
            case 9:
                updating_index(9, notes_);
                break;
            case 10:
                updating_index(10, notes_);
                break;
            case 11:
                updating_index(11, notes_);
                break;
            case 12:
                updating_index(12, notes_);
                break;
            case 13:
                updating_index(13, notes_);
                break;
            case 14:
                updating_index(14, notes_);
                break;
            case 15:
                updating_index(15, notes_);
                break;
            case 16:
                updating_index(16, notes_);
                break;
            case 17:
                updating_index(17, notes_);
                break;
            case 18:
                updating_index(18, notes_);
                break;
            case 19:
                updating_index(19, notes_);
                break;
            case 20:
                updating_index(20, notes_);
                break;
        }
    }

    //final screen printing
    for (int i = 0; i < 10; i++)
    {
        printf("%d  | ", i);
        for (int j = 0; j<notes_[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 10; i < 21; i++) //we do this because we want to achieve a correct printing on the screen
    {
        printf("%d | ", i);
        for (int j = 0; j<notes_[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    free(notes);

    return 0;
}