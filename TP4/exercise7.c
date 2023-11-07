#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

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

// signature of the function chercher_chemin_rec used before declaration
void afficher_lab(int *tab, int N);

void initialize(int *maze, int N)
{
	int x;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			x = random_number(0, 1);
			maze[i * N + j] = x;
		}
	}

	// setting case (1,1) to 0 so that the labyrinth solving algorithm can be executed at least one time
	maze[0] = 0;

	printf("\n\nHere is the labyrinth visualized\n");
	afficher_lab(maze, N);
	printf("\n==================\n\n");

	return;
}

void initialize2(int *maze, int N)
{
	int x;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("Number in position (%d,%d): ", i + 1, j + 1);
			scanf("%d", &x);
			maze[i * N + j] = x;
		}
	}

	printf("\n\nHere is the labyrinth visualized\n");
	afficher_lab(maze, N);
	printf("\n==================\n\n");

	return;
}

// signature of the function chercher_chemin_rec used before declaration
bool chercher_chemin_rec(int *maze, int x, int y, int N);

/* Printing the labyrinth */
void afficher_lab(int *tab, int N)
{
	printf("+ ");
	for (int i = 0; i < N; i++)
	{
		printf("- ");
	}
	printf("+\n\n");

	for (int i = 0; i < N; i++)
	{
		printf("| ");
		for (int j = 0; j < N; j++)
		{
			if (tab[i * N + j] == 0)
			{
				printf("  ");
			}
			if (tab[i * N + j] == 1)
			{
				printf("* ");
			}
			if (tab[i * N + j] == 2)
			{
				printf("\033[1;32m+\033[1;0m "); // printing the solution in green
			}
			if (tab[i * N + j] == 3)
			{
				printf("  ");
			}
		}
		printf("|\n\n");
	}

	printf("+ ");
	for (int i = 0; i < N; i++)
	{
		printf("- ");
	}
	printf("+\n");
}

/* Check if (x, y) is valid index for N*N labyrinth */
bool is_safe(int *maze, int x, int y, int N)
{
	// if (x, y outside maze) return false
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x * N + y] == 0) // 0 is a free case
		return true;

	return false;
}

bool chercher_chemin(int *maze, int N)
{
	if (chercher_chemin_rec(maze, 0, 0, N) == false)
	{
		printf("A solution doesn't exist");
		return false;
	}

	printf("Here is a solution:\n");
	// every treatment is done recursively
	afficher_lab(maze, N);
	return true;
}

/* Solving the labyrinth */
// PASS CASE FOR 2 and 3 OPTIONS ON THE PROGRAM BELOW
bool chercher_chemin_rec(int *maze, int x, int y, int N)
{
	// if (x, y is goal) return true
	if (x == N - 1 && y == N - 1)
	{
		maze[x * N + y] = 2; // we arrived to the last case of the labyrinth and we set it to 2 as it's a case unoccupied
		return true;
	}

	// Check if maze[x][y] is valid
	if (is_safe(maze, x, y, N) == true)
	{
		// mark x, y as part of solution path temporarily
		maze[x * N + y] = 2;

		/* Move to the right */
		if (chercher_chemin_rec(maze, x + 1, y, N) == true)
		{
			return true;
		}

		/* Moving down */
		if (chercher_chemin_rec(maze, x, y + 1, N) == true)
		{
			return true;
		}

		/* moving up */
		if ((chercher_chemin_rec(maze, x - 1, y, N) == true) && x - 1 >= 0)
		{
			return true;
		}

		/* moving left */
		if ((chercher_chemin_rec(maze, x, y - 1, N) == true) && y - 1 >= 0)
		{
			return true;
		}

		/* If none of the above movements work then BACKTRACK:
			unmark x, y as part of solution path */
		maze[x * N + y] = 3; // setting it as a case unoccupied that doesn't verify the solution
		return false;
	}

	return false;
}

// driver program to test above functions
int main(int argc, char **argv)
{
	int N;
	int choice = 0;
	bool repeat = true;

	do
	{
		printf("Give the size of the labyrinth that you wish: ");
		scanf("%d", &N);
	} while (N <= 0);

	printf("Choose the functionality of the labyrinth program below.\n - Type 1 you want to create a maze on yourself\n - Type 2 to generate a maze automaticly\n - Type 3 to take the default one\n\n");
	printf("You choose: ");
	scanf("%d", &choice);
	printf("\n");

	while (repeat)
	{
		if (choice == 1 || choice == 2 || choice == 3)
		{
			repeat = false;
			continue;
		}

		printf("\n\033[1;33mTRY AGAIN!\033[1;0m Type 1 for manual, 2 for random or 3 for default\n");
		printf("You choose: ");
		scanf("%d", &choice);
		printf("\n");
	}

	// initializing the labyrinth
	if (choice == 2)
	{
		srand(time(0)); // needed for randomness

		// creating the labyrinth
		int *maze = malloc((N * N) * sizeof(int));
		initialize(maze, N);

		// solving the labyrinth
		chercher_chemin(maze, N);
		return 2;
	}
	else if (choice == 1)
	{
		// creating the labyrinth
		int *maze = malloc((N * N) * sizeof(int));
		initialize2(maze, N);

		// solving the labyrinth
		chercher_chemin(maze, N);
		return 1;
	}
	else if (choice == 3)
	{
		// creating the labyrinth
		int by_default[64] = {
			0, 0, 1, 0, 0, 0, 1, 1,
			1, 0, 0, 1, 1, 0, 1, 0,
			1, 0, 1, 1, 1, 0, 0, 0,
			1, 0, 0, 1, 0, 0, 1, 1,
			0, 1, 0, 0, 0, 1, 0, 1,
			0, 0, 0, 1, 0, 1, 0, 1,
			1, 1, 1, 1, 0, 0, 0, 0,
			1, 0, 1, 1, 0, 0, 0, 0};

		int *maze = malloc((8 * 8) * sizeof(int));

		// filling out with the default values to the pointed matrix
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				maze[i * 8 + j] = by_default[i * 8 + j];
			}
		}

		printf("\n\nHere is the labyrinth visualized\n");
		afficher_lab(maze, 8);
		printf("\n==================\n\n");

		// solving the labyrinth
		chercher_chemin(maze, 8);
		return 3;
	}
	else
	{
		printf("\033[1;31mSorry I don't understand. You should try again!\033[1;0m\n\n");
		return -1;
	}
}
