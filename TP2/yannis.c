#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5  // j'ai augmenté la taille de la grille
#define BOATS 6 // j'ai augmenté le nombre de bateaux

#define WATER 0
#define MISS -1
#define HIT -2
#define BOAT 1

void afficher_listeGrid(int grid[SIZE][SIZE]) {
    printf("\n   ");
    for (int col = 0; col < SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n   ");
    for (int col = 0; col < SIZE; col++) {
        printf("--");
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == WATER || grid[i][j] == BOAT) {
                printf("~ ");
            } else if (grid[i][j] == MISS) {
                printf("x ");
            } else if (grid[i][j] == HIT) {
                printf("o ");
            }
        }
        printf("|\n");
    }

    printf("   ");
    for (int col = 0; col < SIZE; col++) {
        printf("--");
    }
    printf("\n");
}

int main() {
    int grid[SIZE][SIZE]; 
    int x, y, score = 12, hits = 0; 

    srand(time(NULL));

    // Initialisation de la grille avec de l'eau
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = WATER;
        }
    }

    for (int b = 0; b < BOATS; b++) {
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (grid[x][y] == BOAT);
        grid[x][y] = BOAT;
    }

    printf("=== Bataille Navale Améliorée ===\n");
    while (score > 0 && hits < BOATS) {
        afficher_listeGrid(grid);
        printf("\nPoints restants: %d\n", score);
        printf("Coordonnées du tir (x y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || grid[x][y] == MISS || grid[x][y] == HIT) {
            printf("Tir invalide ou déjà tenté.\n");
            continue;
        }

        if (grid[x][y] == BOAT) {
            printf("Touché !\n");
            grid[x][y] = HIT;
            hits++;
        } else {
            printf("Manqué.\n");
            grid[x][y] = MISS;
            score--;
        }
    }

    afficher_listeGrid(grid);
    if (hits == BOATS) {
        printf("Félicitations! Tous les bateaux ont été coulés!\n");
    } else {
        printf("Essayez à nouveau! Votre score est : %d\n", score);
    }

    return 0;
}