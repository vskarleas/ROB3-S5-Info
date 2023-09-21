#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "programmes.h"

#define TAILLE 4
#define BOATS 5

bool position_available_or_not (int table[TAILLE][TAILLE], int x, int y)
{
    if (table[x][y] == 0)
    {
        return true; //we can place ships
    }
    else
    {
        return false; //we can't place ships
    }

}

void printing_the_grille(int table[TAILLE][TAILLE])
{
    printf("   ");
    for (int k = 0; k< TAILLE; k++)
    {
        printf("%d ", k+1);
    }
    printf("\n\n");
    for (int i = 0; i < TAILLE; i++)
    {
        printf("%d  ", i+1);
        for (int j = 0; j < TAILLE; j++)
        {
            if (table[i][j] == 0 || table[i][j] == 1) //nothing on this position
            {
                printf("  ");
            }
            if (table[i][j] == 2) //case  ayant  subit  un  tir  vaudront  2 
            {
                printf("x ");
            }
            if (table[i][j] == 3)//case ayant subit un tir sur un bateau
            {
                printf("o ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL)); //needed for the random generator

    int grille[TAILLE][TAILLE]; //creation de la grille TAILLExTAILLE
    int points = 11; //11 points attributed to the user
    bool repeat = true; //be used when positioning ships in the begining and to repeat the game procedure
    int ships_positioned_counter = 0; //how many ships have been positioned in the begining
    int i, j; //coordinates used for ships position
    int round = 1; //used to show the number of the round
    bool coordinates = true; //used to ask the use new coordinates for a vessel if the previous ones are not inside the specified limits mentioned on the instructions

    //initiliasation de la grille (zeros everywhere)
    for (int x=0; x<TAILLE; x++)
    {
        for (int y=0; y<TAILLE; y++)
        {
            grille[x][y] = 0;
        }
    }

    //positioning ships in the beginning
    while (repeat)
    {
        i = random_number_with_minimum(0, TAILLE-1);
        j = random_number_with_minimum(0, TAILLE-1);
        if (position_available_or_not(grille, i,j))
        {
            grille[i][j] = 1; //positioning a ship
            ships_positioned_counter ++;
        }

        if (ships_positioned_counter == BOATS)
        {
            repeat = false;
        }
    }

    i = 0;
    j = 0;

    repeat = true; //re-initialisation of the repeater for the game loop

    //game loop
    printf("SCORE\n");
    printf("Your initial score is %d\n\n", points);
    printf("RULES\n");
    printf("We are playing in a field of %dx%d. On every round you will be asked to provide the coordinates x & y for a vessel. The goal is to find the hiden vessels coordinates. If you do not find it, you will lose one point from the total of %d\n\n", TAILLE, TAILLE, points);
    printf("The coordinates x & y can take any value between 1 and %d\n", TAILLE);
    printf("================================================================\n");
    while(repeat)
    {
        printf("------------------------------------------------\n");
        printf("Round No %d\n\n", round);
        while (coordinates)
        {
            printf("Postion x: ");
            scanf("%d", &i);
            printf("\n");
            printf("Postion y: ");
            scanf("%d", &j);
            printf("\n");

            if (!(i < 1 || i > TAILLE + 1 || j < 1 || j > TAILLE + 1)) //coordinates verification out of limit
            {
                
                coordinates = false;
            }
            else
            {
                printf("The coordinates x & y can take any value between 1 and %d. TRY AGAIN!\n", TAILLE);
            }
        }

        coordinates = true;
        
        if (position_available_or_not(grille, i, j))
        {
            //means that no ship found -> marking with 'x'
            grille[i-1][j-1] = 2; //we need -1 because user gives visual coordinates
            points --; //updating the score
        }
        else 
        {
            //means that the user found a ship -> markig with 'o'
            grille[i-1][j-1] = 3; //we need -1 because user gives visual coordinates
            ships_positioned_counter --;
        }

        printing_the_grille(grille);

        //loop's logic
        if (points == 0)
        {
            repeat = false;
            printf("=================================\n");
            printf("=========== Game over ===========\n");
            printf("=================================\n");
            printf("           YOU LOSE              \n");

            return 1; //returns 1 if the user lost all of his points - it also works as the while(repeat) stopper
        }
        if (ships_positioned_counter == 0 )
        {
            printf("=================================\n");
            printf("========= Game finished =========\n");
            printf("=================================\n");
            printf("            YOU WIN              \n");

            return 0; //returns 0 if the user foudn all the ships - it also works as the while(repeat) stopper
        }

        round ++; //updating round number
    }
}