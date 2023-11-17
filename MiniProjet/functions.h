#ifndef _FUNCTIONS_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct une_case {
  int x; /* position de la case en x*/
  int y; /* position de la case en y*/
} Case;

// type: Structure
typedef struct navire
{
    int sens; /* 0 haut 1 droite 2 bas 3 gauche */
    Case premiere_case;
    int taille;
} Navire;

int nb_random(int min, int max);

void printing_the_grille(int **table, int taille_plateau);

void initialize_plate(int taille_plateau, int **table);

bool valdation_navire(int **table_navire, int x, int y, int sens, int taille, int taille_plateau);

Navire *creer_navire(int taille, int taille_plateau, int **table_navire);

void initialisation_plateau(int **table_navire, int taille_plateau, Navire **liste_of_navires);

void copier_grille_de_reference_vers_la_grille_de_jeu(int **table_navire, int **table_jeu, int taille_tableau);

void proposition_joueur(int **plateau, int **prop, int *NbTouche, int *NbJoue, int *NbToucheNav, int taille_plateau);

#endif