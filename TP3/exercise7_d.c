#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Removing a caracter in a specific position sent on argument */
void remove_char(char *string, int id)
{
    int k;
    for (k = id; k < strlen(string) - 1; k++)
    {
        string[k] = string[k + 1];
    }

    string[k] = '\0';
}

/* Updating the string so that it includes only well parenthesized expressions */
void updating_string(char *string)
{
    int counter = 0;
    int length = strlen(string);

    // Reading from left to right
    for (int i = 0; string[i] != 0; i++)
    {
        if (string[i] == '(')
        {
            counter++;
        }
        if (string[i] == ')')
        {
            counter--;
        }
        if (counter < 0)
        {
            remove_char(string, i);
            counter = 0; // restarting the logic machine
            i--;
        }
    }
    counter = 0;

    // Reading from right to left
    for(int i = length - 1; i >= 0; i--){
         if(string[i] == ')')
        {
            counter++;
        }
        if(string[i] == '(')
        {
            counter--;
        }
        if(counter<0)
        {
            remove_char(string,i);
            counter=0;
        }

    }
}

/* Capable of treating any given string. Not only a string that contains only parenthesis*/
int longest_parenethsis(char *string)
{
    updating_string(string); // Taking the updated form of the string
    int len = strlen(string);
    int index = 0;

    int res = 0;
    int *temp = malloc(sizeof(int) * len); // Using a STACK to hold the string's '(', ')' occurrences

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '(')
        {
            temp[++index] = 1; // we first access index and then we do index = index + 1;
        }

        // logic from exercise7_c
        if (string[i] == ')')
        {
            if (temp[index] == 1)
            {
                index--;

                res = res + 2;
            }
        }
    }

    return res;
}

int main(int argc, char **argv)
{
    char string[180];
    printf("Input a string: ");
    fgets(string, sizeof(string), stdin); // works better than scanf in order to take the whole phrase as an argument or saved into a variable

    printf("Longest well-parenthesized expression result: %d for... %s", longest_parenethsis(string), string);
    printf("NOTE: If after for... is empty then there is no longer a well-parenthesized expression");
}