#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "function-exo1.h"

int main(int argc, char **argv)
{
    int a, b, i;
    printf("a = ");
    scanf("%d", &a);
    printf("\n");

    printf("b = ");
    scanf("%d", &b);
    printf("\n");

    printf("i = ");
    scanf("%d", &i);
    printf("\n");

    printf("Result retruned from the incremente function is %d\n",incremente(&a, &b, i)); // passing address of variables to function
    printf("--------------------------------\n");
    printf(("After the traitement with pointers a and b are:\n"));
    printf("a = %d, b = %d\n\n", a, b);

    return 0;
}