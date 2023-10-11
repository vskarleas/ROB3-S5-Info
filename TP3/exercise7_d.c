#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Capable of treating any given string. Not only a string that contains only parenthesis*/
int longest_parenethsis(char *string)
{
    int len = strlen(string);
    int index = 0;

    int res = 0;
    int *temp = malloc(sizeof(int) * len); // WORKS AS AN ACCESSIBLE STACK

    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (string[i] == '(')
        {
            temp[++index] = 1; // we first access index and then we do index = index + 1;
            count++;
        }

        // logic from exercise7_c
        if (string[i] == ')')
        {
            if (temp[index] == 1)
            {
                count--;
                index--;

                res = res + 2;
            }
        }
    }

    if ((count > 0))
    {
        return res;
    }
    else
    {
        return res;
    }
}

int main(int argc, char **argv)
{
    char string[180];
    printf("Input a string: ");
    fgets(string, sizeof(string), stdin); // works better than scanf in order to take the whole phrase as an argument or saved into a variable

    printf("Result: %d [the longest well-parenthesized expression]", longest_parenethsis(string));
}