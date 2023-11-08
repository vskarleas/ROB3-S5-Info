#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void affiche_mat(int NB_ROWS, int NB_COLS, int **tab)
{
    for (int i = 0; i < NB_ROWS; i++)
    {
        for (int j = 0; j < NB_COLS; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void removeColumn(int **matrix, int col, int N)
{
    N--;
    int orig_col = col;
    for (int i = 0; i < N; i++)
    {
        while (col < N)
        {
            // move number to the left
            matrix[i][col] = matrix[i][col + 1];
            col++;
        }
        col = orig_col;
        matrix[i] = realloc(matrix[i], sizeof(double) * N);
    }
}

void removeRow(int **matrix, int row, int N)
{
    N--;
    free(matrix[row]); // removing the specific row (ligne)
    while (row < N)
    {
        // move data up
        matrix[row] = matrix[row + 1];
        row++;
    }
}

/* Required in order to return a new instance of the matrix that is modified instead of odifying the original one */
void strcp2D(int **final, int **source, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            final[i][j] = source[i][j];
        }
    }

    return;
}

int **prive(int **original, int col, int row, int N)
{
    int** arr;
    arr = malloc(N * sizeof (int **));
    if (arr == NULL)
    {
        printf("Error with malloc - memory allocation failed");
        exit(1);
    }
    for (int i = 0; i < N; i++)
    {
        arr[i] = malloc(N * sizeof(int));
    }

    strcp2D(arr, original, N);

    removeRow(arr, row - 1, N);
    removeColumn(arr, col - 1, N);

    return arr;
}

int random_number(int min, int max)
{
    int step = 10;
    int our_random;

    for (int i = 0; i < step; i++)
    {
        our_random = (rand() % (max - min + 1)) + min;
    }

    return our_random;
}

void initialize(int **matrix, int N, int min, int max)
{
    int x;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            x = random_number(min, max);
            matrix[i][j] = x;
        }
    }

    printf("\n\nHere is the initial matrix %dx%d\n", N, N);
    affiche_mat(N, N, matrix);
    printf("\n==================\n\n");

    return;
}

int det(int **matrix, int N)
{
    if (N == 1)
    {
        return matrix[0][0];
    }
    else if (N == 2)
    {
        return (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]);
    }
    else
    {
        int res = 0;
        int positive_or_negative = 1;
        for (int j = 0; j < N; j++)
        {
            int **priv = prive(matrix, j+1, 1, N);
            res = res + positive_or_negative * matrix[0][j] * det(priv, N-1);
            positive_or_negative = -positive_or_negative;

        }

        return res;
    }
}