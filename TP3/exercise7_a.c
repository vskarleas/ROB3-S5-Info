#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void remove_parenthesis(char *string)
{
    char no_parenthesis[100];
    int id = 0;
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        if (string[i] == '(' || string[i] == ')')
        {
            no_parenthesis[id] = string[i];
            id++;
        }
        
    }
    strcpy(string, no_parenthesis);
}

int main(int argc, char **argv)
{
    char string[100] = "( a + 2 * (3 /5))";
    remove_parenthesis(string);
    printf("%s\n", string);
}
