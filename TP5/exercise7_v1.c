#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 10
#define MAX_Y 10
#define MAX_ENERGY 100
#define REPRODUCE_PROB 0.1
#define MOVE_ENERGY_COST 1
#define EAT_ENERGY_GAIN 50
#define CHDIR_PROB 0.2
#define REPRODUCE_ENERGY_COST 30
#define MAX_TIMESTEPS 100
#define EAT_PROB 0.6

typedef struct
{
    int x;
    int y;
    int energy;
    int direction;
} Entity;

typedef struct
{
    Entity *prey;
    Entity *predator;
} EcosystemCell;

void initializeEntity(Entity *entity, int x, int y)
{
    entity->x = x;
    entity->y = y;
    entity->energy = rand() % MAX_ENERGY + 1;
    entity->direction = rand() % 4; // 0: up, 1: down, 2: left, 3: right
}

void initializeCell(EcosystemCell *cell)
{
    cell->prey = NULL;
    cell->predator = NULL;
}

void moveEntity(Entity *entity)
{
    if (rand() / (double)RAND_MAX < CHDIR_PROB)
    {
        entity->direction = rand() % 4;
    }

    switch (entity->direction)
    {
    case 0:
        if (entity->y > 0)
        {
            entity->y--;
        }
        break;
    case 1:
        if (entity->y < MAX_Y - 1)
        {
            entity->y++;
        }
        break;
    case 2:
        if (entity->x > 0)
        {
            entity->x--;
        }
        break;
    case 3:
        if (entity->x < MAX_X - 1)
        {
            entity->x++;
        }
        break;
    default:
        break;
    }

    entity->energy -= MOVE_ENERGY_COST;
}

void reproduce(Entity *parent, Entity *child)
{
    child->x = parent->x;
    child->y = parent->y;
    child->energy = parent->energy / 2;
    child->direction = rand() % 4;
    parent->energy /= 2;
}

void evolveEcosystem(EcosystemCell ecosystem[MAX_X][MAX_Y])
{
    // Évolution des proies
    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            if (ecosystem[i][j].prey != NULL)
            {
                Entity *prey = ecosystem[i][j].prey;

                // Déplacement des proies
                moveEntity(prey);

                // Décrémentation de l'énergie des proies
                prey->energy -= MOVE_ENERGY_COST;

                // Reproduction des proies avec une probabilité reproduce
                if (rand() / (double)RAND_MAX < REPRODUCE_PROB && prey->energy > REPRODUCE_ENERGY_COST)
                {
                    Entity child;
                    reproduce(prey, &child);

                    // Ajouter l'enfant à une case voisine (si disponible)
                    int newX = i + (rand() % 3) - 1;
                    int newY = j + (rand() % 3) - 1;

                    if (newX >= 0 && newX < MAX_X && newY >= 0 && newY < MAX_Y &&
                        ecosystem[newX][newY].prey == NULL)
                    {
                        ecosystem[newX][newY].prey = (Entity *)malloc(sizeof(Entity));
                        *ecosystem[newX][newY].prey = child;
                    }
                }
            }
        }
    }

    // Évolution des prédateurs
    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            if (ecosystem[i][j].predator != NULL)
            {
                Entity *predator = ecosystem[i][j].predator;

                // Déplacement des prédateurs
                moveEntity(predator);

                // Décrémentation de l'énergie des prédateurs
                predator->energy -= MOVE_ENERGY_COST;

                // Reproduction des prédateurs avec une probabilité reproduce
                if (rand() / (double)RAND_MAX < REPRODUCE_PROB && predator->energy > REPRODUCE_ENERGY_COST)
                {
                    Entity child;
                    reproduce(predator, &child);

                    // Ajouter l'enfant à une case voisine (si disponible)
                    int newX = i + (rand() % 3) - 1;
                    int newY = j + (rand() % 3) - 1;

                    if (newX >= 0 && newX < MAX_X && newY >= 0 && newY < MAX_Y &&
                        ecosystem[newX][newY].predator == NULL)
                    {
                        ecosystem[newX][newY].predator = (Entity *)malloc(sizeof(Entity));
                        *ecosystem[newX][newY].predator = child;
                    }
                }

                // Vérification des proies à manger
                if (ecosystem[i][j].prey != NULL && rand() / (double)RAND_MAX < EAT_PROB)
                {
                    // Le prédateur mange la proie
                    predator->energy += EAT_ENERGY_GAIN;
                    free(ecosystem[i][j].prey);
                    ecosystem[i][j].prey = NULL;
                }
            }
        }
    }
}

void displayEcosystem(EcosystemCell ecosystem[MAX_X][MAX_Y])
{
    printf("Ecosystem at current iteration:\n");

    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            if (ecosystem[i][j].predator != NULL)
            {
                printf("P "); // Predator
            }
            else if (ecosystem[i][j].prey != NULL)
            {
                printf("p "); // Prey
            }
            else
            {
                printf(". "); // Empty cell
            }
        }
        printf("\n");
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    EcosystemCell ecosystem[MAX_X][MAX_Y];

    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            initializeCell(&ecosystem[i][j]);
        }
    }

    // Exemple d'initialisation d'une proie
    Entity prey;
    initializeEntity(&prey, 5, 5);
    ecosystem[5][5].prey = &prey;

    // Boucle principale de simulation
    for (int timestep = 0; timestep < MAX_TIMESTEPS; timestep++)
    {
        evolveEcosystem(ecosystem);
        displayEcosystem(ecosystem);
    }

    return 0;
}
