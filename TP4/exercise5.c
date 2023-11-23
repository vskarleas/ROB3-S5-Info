#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to set up matrix elements entered by the user
void matrix_initialisation(int matrix[][10], int row, int column) {

   printf("\nEnter elements: \n");

   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("Enter (%d,%d) : ", i + 1, j + 1); //+1 here to print the real value for a human
         scanf("%d", &matrix[i][j]);
      }
   }
}

// function to multiply two matrices
//called in a sequence if an donly if the verification of rows and collumns is completed
void multiply_matrices(int first[][10], int second[][10], int result[][10], int r1, int c1, int r2, int c2) {

   // Initializing result matrix
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         result[i][j] = 0;
      }
   }

   // Multiplying first and second matrices and storing it in result
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}


void affiche(int result[][10], int row, int column) {

   printf("\nOutput Matrix:\n");
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("%d  ", result[i][j]);
         if (j == column - 1)
            printf("\n");
      }
   }
}

int main() {
   // initialize the matrices to be treated and the matrix to be created with a maximum size 10x10
   //However the program is written in a way that allows teh user to choose the desired size of the matrix
   int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2;
   printf("Enter rows and column for the first matrix: ");
   scanf("%d %d", &r1, &c1);

   printf("Enter rows and column for the second matrix: ");
   scanf("%d %d", &r2, &c2);

   if (c1 > 10 || c2 > 10 || r1 > 10 || r2 > 10)
   {
      printf("Currently we accept a maximm of 10 rows and 10 columns\n\n");
      return -1;
   } 

   // Taking input until
   // 1st matrix columns is not equal to 2nd matrix row - TREATING THIS ERROR CASE HERE
   while (c1 != r2) {
      printf("Error! Enter rows and columns again.\n");
      printf("1st matrix number of collumns needs to be equal to 2nd matrix's rows\n\n");

      printf("Enter rows and columns for the first matrix: ");
      scanf("%d%d", &r1, &c1);
      printf("Enter rows and columns for the second matrix: ");
      scanf("%d%d", &r2, &c2);
   }

   printf("Matrix No 1\n");
   matrix_initialisation(first, r1, c1);

   printf("\nMatrix No 2\n");
   matrix_initialisation(second, r2, c2);

   // multiplying
   multiply_matrices(first, second, result, r1, c1, r2, c2);

   // afficher_liste the result
   affiche(result, r1, c2);

   return 0;
}