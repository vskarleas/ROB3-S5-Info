#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/* Generates random Numbers from 1 to P given a sargument*/
int random_number(int P)
{
    int num;
    num = (rand() % P) + 1;
    return num;
}

/*It shows on the terminal a vertical array composed of numbers*/
void affiche_array(int * array, int N)
{
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ",array[i]);
    }
    printf("]\n");
}

/*Generates random numbers min and max given as arguments*/
int random_number_with_minimum(int min, int max)
{
    int step = 10;
    int our_random;

    for (int i = 0; i < step; i++)
    {
        our_random = (rand() % (max - min + 1)) + min;
    }

    return our_random;
}

//EXPLICIT USE ON EXERCISE 10 ~
/* +1 to a specific index of a specific array notes_[21], which is the counter of every note on the array notes, given on the argument*/
void updating_index(int index,int notes_[21])
{
    notes_[index] = notes_[index] + 1;
}
//EXPLICIT USE ON EXERCISE 10 ^

/* return false if the number x is between 1 and 49, else it returns true*/
bool not_between_1_and_49(int x)
{
    if (x >= 1 && x<= 49)
    {
        return false;
    }
    else
    {
        return true;
    }
}
