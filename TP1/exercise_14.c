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

        printf("Give the number n pour calcular le n-ieme valeur de la suite : ");
        scanf("%d", &n);
        if (n>=0)
        {
            repeat = false;
            printf("U(n) = %d\n", suite_exercise_14(n));
        }
        else 
        {
            printf("=====================\n");
            printf("We need one positive number or the zero. Try again!\n");
        }
    }
    
 
    return 0;
}