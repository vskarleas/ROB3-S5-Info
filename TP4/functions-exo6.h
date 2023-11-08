#ifndef _FUNCTION_6_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void affiche_mat(int NB_ROWS, int NB_COLS, int **tab);

void removeColumn(int **matrix, int col, int N);

void removeRow(int **matrix, int row, int N);

void strcp2D(int **final, int **source, int N);

int **prive(int **original, int x, int y, int N);

int random_number(int min, int max);

void initialize(int **matrix, int N, int min, int max);

int det(int **matrice, int n);

#endif