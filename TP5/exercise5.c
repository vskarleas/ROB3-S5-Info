#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define OPERATION_COMPLETED -10

/*---- le type maillon ----*/
typedef struct Maillon_
{
	double c;
    int n;
	struct Maillon_* suiv; /* pointeur sur l'�l�ment suivant */
} Maillon;
/*---- le type liste des maillons ----*/
typedef struct Liste_
{
	unsigned int taille;        /* nombre d'�l�ments dans la liste */
	Maillon *first; /* pointeur sur le premier �l�ment de la liste */
	Maillon *last;  /* pointeur sur le dernier �l�ment de la liste */
	                       /* first = last = NULL et taille = 0 <=> liste vide */
} Liste;


/* cr�er une cellule de liste avec l'�l�ment v 
   renvoie le pointeur sur la liste cr��e
   la fonction s'arrete si la cr�ation n'a pas pu se faire */
Maillon *creer_element_liste_Point(double flottant, int id)
{
	Maillon *el;
	el = (Maillon *)malloc(sizeof(Maillon));
	if (el==NULL)
	{
		fprintf(stderr, "creer_element_liste_Point : allocation impossible\n");
		exit(-1);
	}
	el->c = flottant;
    el->n = id;
	el->suiv = NULL;
	return el;
}


/* cr�er une liste des maillons vide */
Liste creer_liste_Point_vide()
{
	Liste L = {0, NULL, NULL};
	return L;
}


/* Printing the liste chaine */
void afficher_liste (Liste *L)
{
    Maillon *el = L->first;
    while (el != NULL)
    {
      printf ("c = %f and n = %d\n", el->c, el->n);
      el = el->suiv;
    }
}

/* Deleting the first element of the last as asked on exercise 3 */
void delete_first_element (Liste *L)
{
    Maillon *el = L->first;
    L->first = el->suiv;
    L->taille --;
    return;
}

/* If a maillon equals to an existing one in the liste we perform the action (c1 + c2, n) */
bool treat_egaux(Liste *L, double flottant, int id)
{
    Maillon *el = L->first;
    while (el != NULL)
    {
        if(el->c == flottant)
        {
            el->c = el->c + flottant;
            return true;
        }
      el = el->suiv;
    }

    return false;
}


/* ajouter l'�l�ment e en fin de la liste L, renvoie la liste L modifi�e */
void ajouter_element_liste_Point(Liste* L, double flottant, int id)
{
    // Create a new Maillon
    Maillon* newMaillon;
    newMaillon = creer_element_liste_Point(flottant, id);

    bool egality_treatmen = treat_egaux(L, flottant, id);
    if (egality_treatmen == true)
    {
        return;
    }


    //verifying if it's allocated or not
    if (newMaillon == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Adding as the first element if there isn't any other element
    if (L->taille == 0)
    {
        L->first = L->last = newMaillon;
        L->taille = 1;
        return;
    }

    // Check if the new element should be the new first element
    if (id >= L->first->n)
    {
        newMaillon->suiv = L->first;
        L->first = newMaillon;
        L->taille++;
        return;
    }

    // Traverse the list to find the correct position to insert the new element
    Maillon* current = L->first;
    Maillon* previous = NULL;


    //scanning the while liste to find the best position
    while (current != NULL && id < current->n)
    {
        previous = current;
        current = current->suiv;
    }

    // Insert the new element at the correct position
    previous->suiv = newMaillon;
    newMaillon->suiv = current;

    // Update the last pointer if necessary
    if (current == NULL)
    {
        L->last = newMaillon;
    }

    L->taille++;
}

Liste initialize_list()
{
    Liste myList = creer_liste_Point_vide();
    bool repeater = true;

    double flottant;
    int id;
    int count = 1;

    while(repeater)
    {
        printf("Element No %d\n", count);
        printf("Float value = ");
        scanf("%lf", &flottant);
        printf("\n");
        printf("n value = ");
        scanf("%d", &id);
        printf("\n");

        if (id<0)
        {
            repeater = false;
            return myList;
        }


        ajouter_element_liste_Point(&myList, flottant, id);
        printf("=================\n\n");
        count ++;
    }
    
    exit(OPERATION_COMPLETED);
	
}

int main(int argc, char **argv)
{
    Liste mylist = initialize_list();

    // afficher_liste the elements in the list
    printf("Printing before first element's removal\n");
    afficher_liste(&mylist);

    delete_first_element(&mylist);
    printf("After first element's removal\n");
    afficher_liste(&mylist);

    return 0;
}
