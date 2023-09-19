#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "programmes.h"
#define ENOUGH 256


int main(int argc, char **argv)
{
    printf("The goal of the game is to find the number that I have guessed. I will give you indication sif you are close or not to the number that I have guessed.\n\n");
    int luck, number, temp, counter;
    temp = -10; //Extra help variable
    counter = 0; //
    
    char name[ENOUGH];
    luck = random_number(1, 100); //A random number between 1 and 100
    printf("The number is %d\n\n\n", luck);

    printf("To begin with, what's your name ? ");
    scanf("%s", name);

    bool repeat = true;
    while (repeat)
    {
        counter ++;
        printf("(Round No%d) What's the number ? ", counter);
        scanf("%d", &number);
        printf("================================================================\n");
        printf("\n");

        //Logic of the game
        if (number == luck)
        {
            repeat = false; 
            printf("****************************************************************\n");
            printf("You found the number!\n\n");
            printf("You did in total %d rounds\n", counter);
            printf("================================================================\n\n");
        }
        else
        {
            if (temp == -10)
            {
                if (number < luck+10 && number > luck - 10)
                {
                    temp = number;
                    printf("You are close %s\n\n", name);
                }
                else if (number > luck+23 || number < luck - 23)
                {
                    printf("You are too far away %s\n\n", name);
                    temp = -10;
                }
                else
                {
                    printf("You can still do it %s. Somewhat close\n\n", name);
                    temp = -10;
                }
            }
            else 
            {
                if ((luck - number < 7 && luck - number > 0) || (number - luck < 7 && number - luck > 0))
                {
                    printf("You are very very close to the guessed number. Remmber! Your previous number was %d\n\n", temp); //before the one that the user just typed
                    temp = number;
                }
                else
                {
                    if (number < luck+10 && number > luck - 10)
                    {
                        temp = number;
                        printf("You are close %s\n\n", name);
                    }
                    else if (number > luck+50 || number < luck - 50)
                    {
                        printf("You are too far away %s\n\n", name);
                        temp = -10;
                    }
                    else
                    {
                        printf("You can still do it %s. Keep searching\n\n", name);
                        temp = -10;
                    }
                }
            }
            
            
        }
    }

    return 0;
}