#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 10

// QUESTION 1
int** creation_matrice(int nb_lignes, int nb_col)
{
    int** mat;
    mat = (int **)malloc(nb_lignes * sizeof(int *));
    for (int i = 0; i < nb_lignes; i++)
    {
        mat[i] = (int *)malloc(nb_col * sizeof(int));
    }

    return mat;
}

int** remplissage_matrice(int** m, int nb_lignes, int nb_col)
{
    for (int i = 0; i < nb_lignes; i++)
    {
        for (int j = 0; j < nb_col; j++)
        {
            m[i][j] = rand()% MAX; // valeurs entre 0 et 9
        }
    }
    return m;
}

void affichage_matrice(int** m, int nb_lignes, int nb_col)
{
    for (int i = 0; i < nb_lignes; i++)
    {
        for (int j = 0; j < nb_col; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int** supprimer_ligne_colonne(int** m, int nb_lignes, int nb_col, int i, int j)
{
    int** res;
    res = creation_matrice((nb_lignes - 1), nb_col);

    int x = 0;
    for (int k = 0; k < (nb_lignes - 1); k++)
    {
        if (x != i)
        {
            res[k] = m[x];
            x++;
        }
        else
        {
            res[k] = m[x+1];
            x += 2;
        }
    }
    int** resultat;
    resultat = creation_matrice((nb_lignes - 1), (nb_col - 1));  //Creation de la matrice (n-1)x(n-1)
    
    for (int p = 0; p < (nb_lignes - 1); p++)
    {
        int x = 0;
        for (int k = 0; k < (nb_col - 1); k++)
        {
            if (x != j)
            {
                resultat[p][k] = res[p][x];
                x++;
            }
            else
            {
                resultat[p][k] = res[p][x+1];
                x += 2;
            }
        }
    }
    
    return resultat;
}

// QUESTION 2
int calcul_det(int** m, int nb_lignes, int nb_col)
{
    if (nb_lignes == 1)
    {
        return m[0][0];
    }
    else if (nb_lignes == 2)
    {
        return (m[0][0]*m[1][1] - m[0][1]*m[1][0]);
    }
    else
    {
        int res = 0;
        int positive_or_negative = 1;
        for (int j = 0; j < nb_lignes; j++)
        {
            int k = m[0][j];
            int **priv = supprimer_ligne_colonne(m, nb_lignes, nb_col, j+1, 1);
            res = res + positive_or_negative * k * calcul_det(priv, nb_lignes-1, nb_col-1);
            positive_or_negative = -positive_or_negative;

        }

        return res;
    }
}

int main()
{
    // QUESTION 1
    srand(time(NULL));

    int n;
    printf("Donnez la dimension n de la matrice : ");
    scanf("%d", &n);

    // Creation de la matrice et remplissage avec des valeurs randoms (avec un MAX de 10)
    int** m;
    m = creation_matrice(n, n);
    m = remplissage_matrice(m, n, n);
    affichage_matrice(m, n, n);

    int i, j;
    printf("Donnez le nombre de la ligne a enlever (nombre compris entre 0 et %d) : ", (n-1));
    scanf("%d", &i);
    while (i >= n)
    {
        printf("Donnez le nombre de la ligne a enlever (nombre compris entre 0 et %d) : ", (n-1));
        scanf("%d", &i);
    }

    printf("Donnez le nombre de la colonne a enlever (nombre compris entre 0 et %d) : ", (n-1));
    scanf("%d", &j);
    while (j >= n)
    {
        printf("Donnez le nombre de la colonne a enlever (nombre compris entre 0 et %d) : ", (n-1));
        scanf("%d", &j);
    }
    
    int** resultat;  // Matrice privée de sa i-ème ligne
    resultat = supprimer_ligne_colonne(m, n, n, i, j);
    printf("Matrice sans la %d-eme ligne et la %d-eme colonne =\n", i, j);
    affichage_matrice(resultat, (n-1), (n-1));
    printf("\n");

    // QUESTION 2
    int det;
    det = calcul_det(m, n, n);
    printf("\n\n det=%d\n\n", det);

    free(m);
    free(resultat);

}