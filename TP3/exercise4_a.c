#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LONG 100

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
        int length = strlen(chaine);

        char mirror[length];
        int idex = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            mirror[idex] = chaine[i];
            idex++;
        }
        mirror[idex] = '\0';

        printf("The mirror message is: ");
        printf("%s\n", mirror);
    }

    if (choice == 2)
    {
        char chaine[LONG] = "bonjour je ";
        int length = strlen(chaine);

        char mirror[length];
        int idex = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            mirror[idex] = chaine[i];
            idex++;
        }
        mirror[idex] = '\0';

        printf("The default word is : bonjour\n");
        printf("The mirror message is: ");
        printf("%s\n", mirror);
    }

    return 0;
}