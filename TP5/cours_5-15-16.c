#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    char c;
    char cd;
    /*
    printf("\nInsert space_A: ");
    scanf ("%c" , &cd);

    printf("Pour entre _A on obtiens: %c \n", cd);
    */
    printf("\nInsert A: ");
    scanf ("%c" , &c);
    printf("\nInsert space_A: ");
    scanf (" %c" , &cd);

    printf("Pour entre A on obtiens: %c \n", c);
    printf("Pour entre _A on obtiens: %c \n", cd);
    

    return (0);
}