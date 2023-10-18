#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char * removeSpaces(char *string)
{
    // non_space_count to keep the frequency of non space characters
    int non_space_count = 0;
    int length = strlen(string);
 
    //Traverse a string and if it is non space character then, place it at index non_space_count
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            string[non_space_count] = string[i];
            non_space_count++;//non_space_count incremented
        }    
    }
    
    //Finally placing final character at the string end
    string[non_space_count] = '\0';

    //Printing on screen the number of spaces
    printf("We found %d spaces on the string\n", length - non_space_count);

    //returning the string updated!!
    return string;
}


//MAIN PROGRAM
int main(int argc, char *argv[])
{
    printf("============== BEFORE TREATMENT =============== \n");
    char string[180];
    printf("Input a string to remove the spaces: ");
    fgets(string, sizeof(string), stdin);
    printf("============== AFTER TREATMENT ================ \n");

    printf("%s\n",removeSpaces(string));
    
    return 0;
}