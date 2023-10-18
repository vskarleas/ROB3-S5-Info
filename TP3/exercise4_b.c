#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LONG 100

void mirror_char(char *string)
{
    int length = strlen(string);
    char c;
    int id = length - 1;

    for (int i = 0; i < length / 2; i++)
    {
        c = string[i];
        string[i] = string[id];
        string[id] = c;

        // Updating id for inversed reading
        id = id - 1;
    }
}

int main(int argc, char **argv)
{
    bool repeat = true;
    int choice = 0;
    printf("1 for giving the world on the terminal or 2 for system's world : ");

    while (repeat)
    {
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1 || choice == 2)
        {
            repeat = false;
        }
        else
        {
            printf("Type 1 for the word on the terminal or 2 for system's world : ");
        }
    }
    if (choice == 1)
    {
        char chaine[LONG];
        printf("Write a word : ");
        scanf("%s", chaine);
        
        mirror_char(chaine);

        printf("The mirror message is: ");
        printf("%s\n", chaine);
    }

    if (choice == 2)
    {
        char chaine[LONG] = "Hello World";
        
        mirror_char(chaine);

        printf("The default phrase is : Hello World\n");
        printf("The mirror message is: ");
        printf("%s\n", chaine);
    }

    return 0;
}
