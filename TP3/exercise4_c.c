#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LONG 100

void affiche_mirroir(char *filename)
{
    int length = strlen(filename);
    if (length != 0)
    {
        printf("%c", filename[length - 1]);
        filename[length - 1] = '\0';
        affiche_mirroir(filename);
    }
    else
    {
        return;
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
            printf("Type 1 for the world on the terminal or 2 for system's world : ");
            repeat = true;
        }
    }
    if (choice == 2)
    {
        char string[LONG] = "bonjour";
        printf("The default word is : bonjour\n");
        printf("The mirror message is: ");
        affiche_mirroir(string);
        printf("\n");
    }
    if (choice == 1)
    {
        char chaine[LONG];
        printf("Write a word : ");
        scanf("%s", chaine);
        printf("The default word is : %s\n", chaine);
        printf("The mirror message is: ");
        affiche_mirroir(chaine);
        printf("\n");
        
    }

    return 0;
}