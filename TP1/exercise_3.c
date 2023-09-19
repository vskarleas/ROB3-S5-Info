#include "programmes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//The intialization of n is done while caling the function ex3 below
int main(int argc, char **argv)
{
    if (argc != 1)
    {
        printf("No arguments are required for this program to run\n");
        exit(-2);
    }
    affichage_n(2);
}