#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "functions-exo6.h"

// rows represent y and columns repesent x

int main(int argc, char **argv)
{
    srand(time(0)); // needed for randomness
    int N, col, row, min, max;
    bool repeat = true;

    printf("\033[1;34mTEST No 1\033[1;0m\n");
    printf("\033[1;34m========== REMOVE ===========\033[1;0m\n\n");
    while (repeat)
    {
        printf("Give the size of the matrix that you wish to be created: ");
        scanf("%d", &N);

        if (N >= 0) // coordinates verification out of limit
        {

            repeat = false;
        }
        else
        {
            printf("We need a positive number. \033[1;31mTry Again!\033[1;0m\n");
        }
    }

    int *arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = (int *)malloc(N * sizeof(int));
    }

    // arr can also be initialised like this
    /*
    int** arr;
    arr = malloc(N * sizeof (int **));

    //treating error case here
    if (arr == NULL)
    {
        printf("Error with malloc - memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        arr[i] = malloc(N * sizeof(int));
    }
    */

    printf("\n");
    printf("Provide the minimum number to be present on the matrix: ");
    scanf("%d", &min);
    printf("\n");
    printf("Provide the maximum number to be present on the matrix: ");
    scanf("%d", &max);

    initialize(arr, N, min, max);

    repeat = true;

    while (repeat)
    {
        printf("\033[1;32mThe following questions can accept values between 1 and %d\033[1;0m\n", N);
        printf("Give the column and the line in format * * that you want to be deleted: ");
        scanf("%d%d", &col, &row); // y line and x column

        if ((col >= 1 && col <= N) && (row >= 1 && row <= N)) // coordinates verification out of limit
        {

            repeat = false;
        }
        else
        {
            printf("\033[1;31mPay attention!\033[1;0m\n");
        }
    }
    int **final = prive(arr, col, row, N);
    printf("\n\033[1;33m Here is the final matrix: \033[1;0m\n");
    affiche_mat(N - 1, N - 1, final);

    printf("\033[1;34m\nTEST No 2\033[1;0m\n");
    printf("\033[1;34m============ DET ============\033[1;0m\n\n");
    printf("The determinant of the following matrix is: %d\n\n", det(arr, N));
    affiche_mat(N, N, arr);
    printf("\033[1;35m\nYou can verify the result at https://matrix.reshish.com/detCalculation.php\n\n\033[1;0m");

    return 0;
}