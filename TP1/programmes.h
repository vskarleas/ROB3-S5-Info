/****************************************************************************** 
  Interface des differents sous-programmes pour les differents execriseses
******************************************************************************/

#ifndef _PROGRAMMES_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/*on définit une variable de type entier qu'on affiche
*/
void affichage_n(int n);


/*Calcule le pgcd de deux nombres. On prend on condition que les
 arguments sont strictements positives (verification fait 
 avant l'appel de la fonction)*/
int calculer_pgcd(int a, int b);


/* Calcle le plus petit commun multiple où  deux entiers non nuls a et b est le plus petit entier strictement positif qui soit multiple de ces deux nombres*/
int calculer_pcmm(int a, int b);


/*Inverse un entier passe en argument*/
int inverser_entier(int number);


/*Un eautre manier à faire l'inversion du nombre qui passe par une transformation au chaine de caracter*/
int inverser_entier_v2(int number);


/*Un eautre manier à faire l'inversion du nombre sans perdre le zero selon la methode de chaine des caracters*/
char* inverser_entier_v3(int number, char * str);


/* Verifie si un nombre passé en argumeng est un multiple d'un autre nombre passé en argument*/
bool mutliple_verification(int number, int multiple_of);


/*Verifies if a specific number given as an argument ends to specific number given as an argument as well*/
bool verification_ends_to(int number, int ends_to);


/* Pour trouver le nième nombre de Fibonacci */
int fibonacci(int n);


/*Gives a rundom number between two values specified as arguments*/
int random_number(int min, int max);


/* Trouve le nombre de chiffres 1 contenu dans un entier */
int number_of_specified_number(int number, char *string);


/* alcule le terme de rangnde la suite de l'exercise 14 du TP1*/
int suite_exercise_14(int n);

/* Cacule de fractions egyptiens */
void egyptian_fraction(int n, int d);

/*Responds if a number is premier or not with a bool */
bool premier_number_or_not (int number);

#endif /* _PROGRAMMES_H_ */