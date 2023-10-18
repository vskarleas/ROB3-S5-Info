#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sous_chaine(char *s1, char *s2)
{
    int i, j, k;

    //Initialisations
    i = 0;
    j = 0;
    k = 0;
    
    //using a two dimenions array to treat the s1
    char twoD[40][60];

    //converting s1 to two dimensional array
    //IDEA: Move to a new line for every new word detected based on spaes ' '
    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == ' ')
        {
            twoD[k][j] = '\0';
            k++;
            j = 0;
        }
        else
        {
            twoD[k][j] = s1[i];
            j++;
        }
    }

    //maring the end of teh array
    twoD[k][j] = '\0';

    //reinitatize j for treatment
    j = 0;
    for (i = 0; i < k + 1; i++)
    {
        if (strcmp(twoD[i], s2) == 0) //cheking if the word (s2) on every line of the 2D array (s1)
        {
            twoD[i][j] = '\0'; //if it's the case then we remove this world from the array
        }
    }

    j = 0;
    for (i = 0; i < k + 1; i++)
    {

        if (twoD[i][j] == '\0')
            continue;
        else
            //printing the rest 2D array which represnets s1 which now maintains everything excpet from the phrase given as s2 on the argument
            printf("%s ", twoD[i]);
    }

    printf("\n");

    return;
}

int main(int argc, char **argv)
{
    printf("Before: \n");
    char s1[200] = "Hello world! This is  full of opportunities. Welcome to the world !";
    printf("%s \n\n", s1);

    printf("The phrase to be removed: \n");

    char s2[100] = "world";
    printf("%s \n\n", s2);
    printf("After: \n");

    sous_chaine(s1, s2); //printing is done in the function
    return 0;
}