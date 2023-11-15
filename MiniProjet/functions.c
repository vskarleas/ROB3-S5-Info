#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

#define NORTH 0
#define SOUTH 2
#define WEST 1
#define EAST 3

#define VIDE 0
#define NAVIRE 1

#define DEJA_CHOISI 2 // case ete joue
#define AUCUN_NAVIRE -1
#define NAVIRE_TROUVE 3

#define COULE 10 // Felicitations

/* Initializes the clock for random numbers generation */
void init_nb_aleatoire()
{
	srandom(time(NULL));
}

/*Generates random numbers min and max given as arguments*/
int nb_random(int min, int max)
{
	int step = 10;
	int our_random;

	for (int i = 0; i < step; i++)
	{
		our_random = (rand() % (max - min + 1)) + min;
	}

	return our_random;
}

/* It prints the plate */
void printing_the_grille(int **table, int taille_plateau)
{
	// Printing columns
	printf("   ");
	for (int k = 0; k < taille_plateau; k++)
	{
		printf("%d ", k + 1);
	}

	// Printing lines
	printf("\n\n");
	for (int i = 0; i < taille_plateau; i++)
	{
		printf("%d  ", i + 1);
		for (int j = 0; j < taille_plateau; j++)
		{
			switch (table[i][j])
			{
			case VIDE:
				printf(". ");
				break;

			case NAVIRE_TROUVE:
				printf("x ");
				break;

			case AUCUN_NAVIRE:
				printf("o ");
				break;

			case COULE:
				printf("\033[1;36mx\033[1;0m ");
				break;
			}
		}
		printf("\n");
	}
}

/* Just put a 0 on every cell */
void initialize_plate(int taille_plateau, int **table)
{
	for (int i = 0; i < taille_plateau; i++)
	{
		for (int j = 0; j < taille_plateau; j++)
		{
			table[i][j] = VIDE;
		}
	}
}

bool valdation_navire(int **table_navire, int x, int y, int sens, int taille, int taille_plateau)
{
	switch (sens)
	{
	case NORTH:
		for (int j = y; j < y + taille -1; j--)
		{
			if (j < 0)
			{
				return false;
				break;
			}
			if (table_navire[x][j] == 1)
			{
				return false;
				break;
			}
		}
		return true;
		break;

	case SOUTH:
		for (int j = y; j < y + taille -1; j++)
		{
			if (j > taille_plateau)
			{
				return false;
				break;
			}
			if (table_navire[x][j] == 1)
			{
				return false;
				break;
			}
		}
		return true;
		break;

	case EAST:
		for (int i = x; i < x + taille -1; i++)
		{
			if (i > taille_plateau)
			{
				return false;
				break;
			}
			if (table_navire[i][y] == 1)
			{
				return false;
				break;
			}
		}
		return true;
		break;

	case WEST:
		for (int i = x; i < x + taille -1; i--)
		{
			if (i < 0)
			{
				return false;
				break;
			}
			if (table_navire[i][y] == 1)
			{
				return false;
				break;
			}
		}
		return true;
		break;

	default:
		return false;
		break;
	}
}

Navire *creer_navire(int taille, int taille_plateau, int **table_navire)
{
	Navire *nav = NULL;
	int randing = nb_random(0, 3);
	int x = nb_random(0, taille_plateau - 1);
	int y = nb_random(0, taille_plateau - 1);
	bool verification = true;

	while (verification)
	{
		if (valdation_navire(table_navire, x, y, randing, taille, taille_plateau))
		{
			verification = false;
		}
		else
		{
			x = nb_random(0, taille_plateau - 1);
			y = nb_random(0, taille_plateau - 1);
		}
	}

	switch (randing)
	{
	case NORTH: // NORTH
		nav->sens = NORTH;
		nav->taille = taille;
		nav->premiere_case.x = x;
		nav->premiere_case.y = y;
		return nav;
		break;

	case WEST: // WEST
		nav->sens = WEST;
		nav->taille = taille;
		nav->premiere_case.x = x;
		nav->premiere_case.y = y;
		return nav;
		break;

	case SOUTH: // SOUTH
		nav->sens = SOUTH;
		nav->taille = taille;
		nav->premiere_case.x = x;
		nav->premiere_case.y = y;
		return nav;
		break;

	case EAST: // EAST
		nav->sens = EAST;
		nav->taille = taille;
		nav->premiere_case.x = x;
		nav->premiere_case.y = y;
		return nav;
		break;

	default:
		return nav;
		break;
	}
}

void initialisation_plateau(int **table_navire, int taille_plateau, Navire **liste_of_navires) {
    int randing;
    for (int i = 0; i < 6; i++) {
        randing = (taille_plateau < 6) ? nb_random(2, taille_plateau) : nb_random(2, 6);
        Navire *nav = creer_navire(randing, taille_plateau, table_navire);

        // Enregistrement du navire dans le tableau
        liste_of_navires[i] = nav;

        int x = nav->premiere_case.x;
        int y = nav->premiere_case.y;

        switch (nav->sens) {
            case NORTH:
                for (int j = y; j > y - nav->taille; j--) {
                    table_navire[x][j] = 1;
                }
                break;
            case SOUTH:
                for (int j = y; j < y + nav->taille; j++) {
                    table_navire[x][j] = 1;
                }
                break;
            case EAST:
                for (int j = x; j < x + nav->taille; j++) {
                    table_navire[j][y] = 1;
                }
                break;
            case WEST:
                for (int j = x; j > x - nav->taille; j--) {
                    table_navire[j][y] = 1;
                }
                break;
        }
    }
}

void copier_grille_de_reference_vers_la_grille_de_jeu(int **table_navire, int **table_jeu, int taille_tableau)
{
	for (int i = 0; i < taille_tableau; i++)
	{
		for (int j = 0; j < taille_tableau; j++)
		{
			if (table_navire[i][j] == 1)
			{
				table_jeu[i][j] = 1;
			}
		}
	}
}

void proposition_joueur(int **plateau, int **prop, int *NbTouche, int *NbJoue, int *NbToucheNav, int taille_plateau) 
{
    int x, y;

    printf("Entrez les coordonnées (x, y) pour tirer: ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Entrée invalide. Veuillez entrer des nombres.\n");
        while (getchar() != '\n'); // Nettoyer le buffer d'entrée
        return;
    }

    x--; y--; // Ajustement pour l'indexation

    if (x < 0 || x >= taille_plateau || y < 0 || y >= taille_plateau) {
        printf("Coordonnées hors du plateau. Veuillez réessayer.\n");
        return;
    }

    (*NbJoue)++;

    if (prop[x][y] != 0) {
        printf("Deja joué.\n");
    } else if (plateau[x][y] > 0) {
        printf("Touché!\n");
        prop[x][y] = 1;
        (*NbTouche)++;
        int idNavire = plateau[x][y];
        NbToucheNav[idNavire - 1]++; // Supposant que chaque navire a un chiffre unique (1, 2, 3, ...)
    } else {
        printf("À l'eau.\n");
        prop[x][y] = 0;
    }
}