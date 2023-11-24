#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define OPERATION_COMPLETED -10
#define MIN 0

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


/* renvoie la valeur du polynome pour un x particulier */
double polynome_value(Liste *L, double x)
{
    Maillon *el;
    el = L->first;
    double res = 0;

    while (el != NULL)
    {
        res = res + pow(x, el->n) * el->c;
        el = el->suiv;
    }

    return res;
}

 /* Concantenatng two polynomes expressed in a form of liste chaine */
Liste somme_polynomes(Liste *poly1, Liste *poly2)
{
    Liste res = creer_liste_Point_vide();
    Maillon *el1 = poly1->first;
    Maillon *el2 = poly2->first;

    while (el1 != NULL || el2 != NULL)
    {
        //initilaizations
        double coef1 = (el1 != NULL) ? el1->c : 0.0;
        double coef2 = (el2 != NULL) ? el2->c : 0.0;
        int id1 = (el1 != NULL) ? el1->n : MIN;
        int id2 = (el2 != NULL) ? el2->n : MIN;

        if (id1 > id2)
        {
            ajouter_element_liste_Point(&res, coef1, id1);
            el1 = el1->suiv;
        }
        else if (id1 < id2)
        {
            ajouter_element_liste_Point(&res, coef2, id2);
            el2 = el2->suiv;
        }
        else
        {
            ajouter_element_liste_Point(&res, coef1 + coef2, id1);
            el1 = el1->suiv;
            el2 = el2->suiv;
        }
    }

    return res;
}


/* Multiplying a polynome with a real number - actualy means mupltipying its coefficients with that number */
void multiplier_polynome_reel(Liste* L, double number)
{
    Maillon* el = L->first;

    while (el != NULL)
    {
        el->c = el->c * number;
        el = el->suiv;
    }
}

/* Multiplyong monome with a polynome */
void multiplier_polynome_monome(Liste* L, Maillon * m)
{
    Maillon* el = L->first;

    while (el != NULL)
    {
        el->c = el->c * m->c;
        el->n = el->n * m->n;
        el = el->suiv;
    }
}




int main(int argc, char **argv)
{
    /*
    Liste mylist1 = initialize_list();

    // afficher_liste the elements in the list
    printf("\n================================\n");
    printf("\n============ Test 1 ============\n");
    printf("\n================================\n");
    printf("Printing before first element's removal\n");
    afficher_liste(&mylist1);

    delete_first_element(&mylist1);
    printf("After first element's removal\n");
    afficher_liste(&mylist1);



    printf("\n================================");
    printf("\n============ Test 2 ============");
    printf("\n================================\n");
    int x;
    printf("Give the number x to find th epolynome value that you created previously: ");
    scanf("%d", &x);
    printf("\n");
    int value = polynome_value(&mylist1, x);
    printf("The value is = %d\n", value);

    printf("\n================================");
    printf("\n============ Test 3 ============");
    printf("\n================================\n");
    printf("Creating a second list that we will need for tha test:\n");
    Liste mylist2 = initialize_list();
    printf("\nHere is ListNo1\n");
    afficher_liste(&mylist1);

    printf("\nHere is ListNo2\n");
    afficher_liste(&mylist2);

    Liste res = somme_polynomes(&mylist1, &mylist2);
    printf("\nHere is the somme of the two lists:\n"); //concantenation
    afficher_liste(&res);

    printf("\n================================");
    printf("\n============ Test 4 ============");
    printf("\n================================\n");
    printf("Multiplying the polynome with a real number:\n");
    double real_number;
    afficher_liste(&res); //using the created polynome from previous test (No 3)

    printf("Give the real number that you wish: ");
    scanf("%lf", &real_number);
    printf("\n");
    multiplier_polynome_reel(&res, real_number);
    afficher_liste(&res);
    */

    printf("\n================================");
    printf("\n============ Test 5 ============");
    printf("\n================================\n");
    printf("\nHere is ListNo1 before multiplication\n");
    Liste mylist3 = initialize_list();
    afficher_liste(&mylist3);

    printf("\nCreating the monome:\n");
    Maillon *monome;
    monome =(Maillon *)malloc(sizeof(Maillon));

    if (monome == NULL)
    {
        fprintf(stderr, "Memory allocation failed for monome.\n");
        exit(1);
    }

    int n;
    double f;

        printf("Float value = ");
        scanf("%lf", &f);
        printf("\n");
        printf("n value = ");
        scanf("%d", &n);
        printf("\n");
        monome->c = f;
        monome->n = n;

        printf("The result of the multplication between the created monome and the function is:\n");
        multiplier_polynome_monome(&mylist3, monome);
        afficher_liste(&mylist3);



    return 0;
}
