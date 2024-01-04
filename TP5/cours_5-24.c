#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    char nom[20];
    printf("\n Entrez votre nom : ");
    //scanf("%s", &nom);
    scanf("%s", nom);
    //scanf("%s ", nom);
    printf("\n Bonjour %s!\n", nom);
    return (0);
}