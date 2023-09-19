#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Demande à l’utilisateur d’initialiser deux entiers. Puis le pro-gramme stocke 
la somme de ces deux entiers dans une autre variable et enfin affiche le résultat*/
int main(int argc, char **argv)
{
    if (argc != 1)
    {
        printf("No arguments are required for this program to run\n");
        exit(-2);
    } 
    
    float a,b, res;
    printf("Give the 1st number : ");
    scanf("%f",&a);

    printf("Give the 2nd number : ");
    scanf("%f",&b);

    res = a + b;
    printf("The result is : %0.2f\n", res); //Precision with two digits after the comma
    

    return 0;

}