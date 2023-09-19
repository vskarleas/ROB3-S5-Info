#include <stdio.h>
#include <stdlib.h>

#include "programmes.h"

int main (int argc, char **argv){
    
    int Nn,Nd;
    

    //Initialize the number of which we are searching the egyptian fractions
    printf("Numerator ");
    scanf("%d",&Nn);
    printf("Denominator ");
    scanf("%d",&Nd);
    printf("We have %d / %d =\n", Nn, Nd);

    egyptian_fraction(Nn, Nd); //Responsible for showing on the terminal the fractions


    return 0;
}