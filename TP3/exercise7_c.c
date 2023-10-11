#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Capable of treating any given string. Not only a string that contains only parenthesis*/
bool well_parenethsis(char *string)
{
    int len = strlen(string);
    int index = 0;
    int counter = 0;
    int *temp = malloc(sizeof(int) * len); // WORKS AS AN ACCESSIBLE STACK

    for (int i = 0; i < len; i++)
    {
        if (string[i] == '(')
        {
            temp[++index] = 1; // we first access index and then we do index = index + 1;

            // Indicator to see if there is a closing parenthesis for every opening parenthesis
            counter++;
        }

        if (string[i] == ')')
        {
            // Accessing this section means that we have found a closing parenthesis
            if (temp[index] == 1)
            {
                // if found the closing parenthesis, then counter is decremented
                counter--;

                // pointer on the temp array goes back to the previous position
                index--;
            }

            // meaning that there are too many closing parenethesis in comparison with the opening parenthesis of the string
            else
            {
                return false; // returns 0
            }
        }
    }

    // meaning that there are still open parenthesis that were not closed
    if (counter > 0)
    {
        return false; // returns 0
    }

    // succesfully passed all the tests!!!
    return true; // returns 1
}

int main(int argc, char **argv)
{
    char string[180];
    printf("Input a string: ");
    fgets(string, sizeof(string), stdin);

    printf("Result: %d [1 for valid parenthesis & 0 for not valid parenthesis]", well_parenethsis(string));
}