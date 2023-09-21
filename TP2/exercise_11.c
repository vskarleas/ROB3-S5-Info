#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "programmes.h"
#include "types_loto.h"

int main(int argc, char **argv)
{
    srand(time(NULL)); // required for the random number generator

    // creating the loto card
    bool card_not_ready = true;
    bool repeat_generator = true;
    int number;
    int loto[6]; // loto card created
    int user[6]; // user card created
    int action;  // 0 means that a number wasn't generated before, while 1 means that the number that was generated is already used

    // starting lotot card generation
    number = random_number_with_minimum(1, 49);

    // paralleled list with not specified length that is used to maintain uniqueness on the aleartory numbers given from the machine
    Liste_Point loto_numbers;
    loto_numbers = creer_liste_Point_vide();

    loto[0] = number;
    ajouter_element_liste_Point(&loto_numbers, number);

    int index = 1; // the indexing system for the rest numbers used on the loto card automatic generator below

    while (card_not_ready)
    {
        while (repeat_generator)
        {
            action = 0;
            number = random_number_with_minimum(1, 49);
            Tableau_Point T = sequence_points_liste_vers_tableau(loto_numbers); // loto_numbers liste to a table

            // verifying the uniqueness
            for (int i = 0; i < T.taille; i++)
            {
                if (T.tab[i] == number)
                {
                    action = 1; // action 1 means that this number already found before
                }
            }

            if (action != 1)
            {
                repeat_generator = false;
            }
        }
        // when exited from the previous loop, it means that we found a unique number

        ajouter_element_liste_Point(&loto_numbers, number);
        loto[index] = number; // adding the number on card
        index++;              // moving on to next element

        // closing loto generator
        if (index == 6)
        {
            card_not_ready = false;
        }

        // re-configurations for the loops
        repeat_generator = true;
    }

    // creating the user card
    card_not_ready = true;
    repeat_generator = true;
    index = 0;

    Liste_Point user_numbers; // used to verify the uniqueness of numbers given from the user
    user_numbers = creer_liste_Point_vide();
    ajouter_element_liste_Point(&user_numbers, 0); // it needs at least one element so that the rest of the program can work

    while (card_not_ready)
    {
        while (repeat_generator)
        {
            action = 0;
            printf("Give a number: ");
            scanf("%d", &number);
           

            // verifying if the number given from the user is between 1 and 49 is essential!!!
            while (not_between_1_and_49(number))
            {
                printf("The number needs to be between 1 and 49. Try again!\n");
                printf("Give a number: ");
                scanf("%d", &number);
                
            }

            Tableau_Point T = sequence_points_liste_vers_tableau(user_numbers); // loto_numbers liste to a table

            // verifying the uniqueness
            for (int i = 0; i < T.taille; i++)
            {
                if (T.tab[i] == number)
                {
                    action = 1; // action 1 means that this number already found before
                }
            }

            if (action != 1)
            {
                repeat_generator = false;
            }
        }

        ajouter_element_liste_Point(&user_numbers, number);
        user[index] = number; // adding the number on card
        index++;              // moving on to next element

        // closing loto generator
        if (index == 6)
        {
            card_not_ready = false;
        }

        // re-configurations for the loops
        repeat_generator = true;
        printf("\n");
    }

    // final verification
    action = 0; // action here is used to determine the jackpot or not 0 means jackpot and 1 means that user lost
    for (int i = 0; i < 6; i++)
    {
        if (user[i] != loto[i])
        {
            action = 1;
        }
    }

    printf("\n===================================\n");
    if (action == 0)
    {
        printf("JACKPOT - YOU WON\n\n");
        printf("Here is the loto card:\n ");
        affiche_array(loto, 6);
        printf("\n");
        printf("Your loto card:\n ");
        affiche_array(user, 6);
        printf("\n");
    }
    else
    {
        printf("YOU LOST\n\n");
        printf("Unique loto card:\n ");
        affiche_array(loto, 6);
        printf("\n");
        printf("Your loto card:\n ");
        affiche_array(user, 6);
        printf("\n");
    }

    return 0;
}