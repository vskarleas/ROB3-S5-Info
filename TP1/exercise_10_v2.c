#include <stdio.h>
#include <stdbool.h>

#include "programmes.h"
 
 /* Une autre maniere de realiser l'exercise 10 (nombre n-ieme de la suite de Fibonacci)*/
int main(int argc, char **argv)
{
    int n;

    bool repeat = true;
    while (repeat)
    {
        printf("=====================\n");
        printf("\n");

        printf("Give a postive number : ");
        scanf("%d", &n);
        if (n>=0)
        {
            repeat = false;
            printf("F(n) = %d\n", fibonacci(n));
        }
        else 
        {
            printf("=====================\n");
            printf("We need one positive number. Try again!\n");
        }
    }
    
 
    return 0;
}