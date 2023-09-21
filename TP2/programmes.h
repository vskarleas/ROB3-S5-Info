/****************************************************************************** 
  Interface des differents sous-programmes pour les differents execriseses
******************************************************************************/

#ifndef _PROGRAMMES_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Generates random Numbers from 1 to P given a sargument*/
int random_number(int P);

/*It shows on the terminal a vertical array composed of numbers*/
void affiche_array(int * array, int N);

/*Generates random numbers min and max given as arguments*/
int random_number_with_minimum(int min, int max);


//EXPLICIT USE ON EXERCISE 10 ~
/* +1 to a specific index of a specific array notes_[21], which is the counter of every note on the array notes, given on the argument*/
void updating_index(int index,int notes_[21]);
//EXPLICIT USE ON EXERCISE 10 ^

/* return true if the number x is between 1 and 49, else it returns false*/
bool not_between_1_and_49(int x);


#endif /* _PROGRAMMES_H_ */