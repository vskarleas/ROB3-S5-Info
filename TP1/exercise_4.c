#include "programmes.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//The intialization of n is done by the user
int main(int argc, char **argv)
{
    if (argc != 1)
    {
        printf("No arguments are required for this program to run\n");
        exit(-2);
    }
    int n; //Il s'agit d'un entier alors int c'est le type de la variable
    printf("Give a number : ");
    scanf("%d", &n);
    affichage_n(n);
}