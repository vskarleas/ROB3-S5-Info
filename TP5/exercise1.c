#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    double c;
    int n;
} Maillon;

/* A small program to see if it works */
int main(int argc, char **argv)
{
    Maillon *new = (Maillon *) malloc(sizeof(Maillon));
    new->c = 5.32;
    new->n = 1;

    printf("Maillon includes: c = %f, n = %d\n", new->c, new->n);
}