#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool palindrome(char *string)
{
    //creattion of mirror image
    int length = strlen(string);

    char mirror[length];
    int idex = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        mirror[idex] = string[i];
        idex++;
    }
    mirror[idex] = '\0';

    //comparing the two strings
    for (int i = 0; i < length; i++)
    {
        if (mirror[i] != string[i])
        {
            return false;
        }
    }

    return true;
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
        }
    }
    if (choice == 2)
    {
        char string[256] = "rever";
        printf("The default word No 1 is : %s\n", string);
        bool res = palindrome(string);
        if (res)
        {
            printf("=> It's a palindrome\n");
        }
        else
        {
            printf("=> It's NOT a palindrome\n");
        }
        
        char string2[256] = "radar";
        printf("The default word No 2 is : %s\n", string2);
        res = palindrome(string2);
        if (res)
        {
            printf("=> It's a palindrome\n");
        }
        else
        {
            printf("=> It's NOT a palindrome\n");
        }
    }
    if (choice == 1)
    {
        printf("Give a world : ");
        char string[256];
        scanf("%s", string);
        bool res = palindrome(string);
        printf("The default word is : %s\n", string);
        if (res)
        {
            printf("=> It's a palindrome\n");
        }
        else
        {
            printf("=> It's NOT a palindrome\n");
        }
    }

    return 0;
}