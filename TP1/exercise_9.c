#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

/* This only works for rational numbers.*/
/* CHECK THE PROGRAM exercise_9_v2 WHHICH INCLUDES THE CORRECT ANSWER TO THE EXERCISE 9*/
int main (int argc, char **argv){
    
    double Nn,Nd,i, E;
    i = 1;
    

    //Initialize the number of which we are searching the egyptian fractions
    printf("Numerator ");
    scanf("%lf",&Nn);
    printf("Denominator ");
    scanf("%lf",&Nd);
    printf("We have %0.0lf / %0.0lf =\n", Nn, Nd);

    while (i < 10)
    {
        E = trunc(Nd/Nn)+1; //denominator of the new fraction
        //emove digits after decimal point and return the modified decimal number

        printf("1 / %0.0lf\n\n", E);

        Nn = Nn * E - Nd; //New fraction 
        Nd = Nd * E;

        if (Nn == 1)
        {
            i = 100; //stop the boucle, we found the final fracion
            printf("1 / %0.0lf\n\n", Nd);
        }
        i++;
    }


    return 0;
}