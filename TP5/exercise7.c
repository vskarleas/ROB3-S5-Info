#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "exercise7.h"

#define ECOSYSTEM_SIZE 10
#define SIZE_X 10
#define SIZE_Y 10

/* Ecosystem's main loop happens on the main program */
int main(int argc, char **argv)
{
    srand(time(NULL));

    Ecosystem ecosystem;
    initialize_ecosystem(&ecosystem, ECOSYSTEM_SIZE);

    int num_time_steps;
    int d_proie;
    int d_predateur;
    double p_reproduce_proie;
    double p_reproduce_predateur; // d_reproduce
    double eat_prob;
    double change_dir_prob;

    // Ask the user if they want to use default configuration
    printf("Voulez-vous utiliser la configuration par défaut ? (1: Oui, 0: Non): ");
    int use_default;
    if (scanf("%d", &use_default) != 1)
    {
        printf("Entrée invalide. Utilisation de la configuration par défaut.\n");
        use_default = 1;
    }

    if (use_default)
    {
        // Default configuration
        num_time_steps = 8;
        d_proie = 3;
        d_predateur = 1;
        p_reproduce_proie = 0.47;
        p_reproduce_predateur = 0.2;
        eat_prob = 0.28;
        change_dir_prob = 0.2;
    }
    else
    {
        // User input for simulation parameters with validation
        num_time_steps = validate_input(1, 1000, "Entrez le nombre d'étapes temporelles (entre 1 et 1000): ", false);
        d_proie = validate_input(1, 10, "Entrez la décroissance d'énergie pour proie (entre 1 et 10): ", false);
        d_predateur = validate_input(1, 10, "Entrez la décroissance d'énergie pour prédateur (entre 1 et 10): ", false);
        p_reproduce_proie = validate_input(0, 100, "Entrez la probabilité de reproduction pour proie (en pourcentage): ", true) / 100.0;
        p_reproduce_predateur = validate_input(0, 100, "Entrez la probabilité de reproduction pour prédateur (en pourcentage): ", true) / 100.0;
        eat_prob = validate_input(0, 100, "Entrez la probabilité de manger (en pourcentage): ", true) / 100.0;
        change_dir_prob = validate_input(0, 100, "Entrez la probabilité de changement de direction (en pourcentage): ", true) / 100.0;
    }

    // Simulation loop
    for (int step = 0; step < num_time_steps; ++step)
    {
        printf("T = %d:\n", step + 1);
        print_ecosystem(&ecosystem, SIZE_X, SIZE_Y);
        move_entities(&ecosystem, change_dir_prob);
        reproduce_entities(&ecosystem, p_reproduce_proie);
        update_energy(&ecosystem, d_proie, d_predateur);
        predator_eat_proie(&ecosystem, eat_prob);
        reproduce_predators(&ecosystem, p_reproduce_predateur);

        usleep(500000); // Sleep for 0.5 seconds
    }

    printf("Etat final de l'ecosystem :\n");
    print_ecosystem(&ecosystem, SIZE_X, SIZE_Y);

    // afficher_liste summary
    int proie_count = 0;
    int predateur_count = 0;

    for (int i = 0; i < ecosystem.size; ++i)
    {
        if (ecosystem.entities[i].energy > 0)
        {
            if (ecosystem.entities[i].direction == 0)
            {
                proie_count++;
            }
            else
            {
                predateur_count++;
            }
        }
    }

    printf("\n\033[1;35mResults of the simulation\033[1;0m\n");
    printf("--------------------------------\n\n");
    printf("Nombre total de proies restantes: %d\n", proie_count);
    printf("Nombre total de prédateurs restants: %d\n", predateur_count);
    printf("Pourcentage de proies par rapport à la population initiale: %.2f%%\n", ((double)proie_count / ECOSYSTEM_SIZE) * 100);
    printf("Pourcentage de prédateurs par rapport à la population initiale: %.2f%%\n", ((double)predateur_count / ECOSYSTEM_SIZE) * 100);

    printf("================================================\n");
    printf("The positions of entities in the ecosystem are afficher_listeed on the terminal. Proies are represented in green with their energy levels, and predateurs are represented in red. Empty spaces are represented by dots.\n");

    free(ecosystem.entities);

    return 0;
}

/* Starting up the ecosystem */
void initialize_ecosystem(Ecosystem *ecosystem, int size)
{
    ecosystem->size = size;
    ecosystem->entities = (Entity *)malloc(size * sizeof(Entity));

    for (int i = 0; i < size; ++i)
    {
        ecosystem->entities[i].x = rand() % size;
        ecosystem->entities[i].y = rand() % size;
        ecosystem->entities[i].energy = 10;
        ecosystem->entities[i].direction = rand() % 4; // 0: NORTH, 1: EAST, 2: SOUTH, 3: WEST
    }
}

/* Printing the ecosystem on the terminal */
void print_ecosystem(Ecosystem *ecosystem, int rows, int collumns)
{
    printf("     ");
    for (int x = 0; x < SIZE_Y; ++x)
    {
        printf(" %d  ", x);
    }
    printf("\n");

    for (int y = 0; y < SIZE_X; ++y)
    {
        printf("%d    ", y);
        for (int x = 0; x < SIZE_Y; ++x)
        {
            int entity_found = 0;
            for (int i = 0; i < ecosystem->size; ++i)
            {
                if (ecosystem->entities[i].x == x && ecosystem->entities[i].y == y)
                {
                    if (ecosystem->entities[i].energy > 0)
                    {
                        printf("\033[1;32mP%d\033[1;0m  ", ecosystem->entities[i].energy); // it won energy
                    }
                    else
                    {
                        printf("\033[1;31mP%d\033[1;0m  ", ecosystem->entities[i].energy); // it lost energy
                    }
                    entity_found = 1;
                    break;
                }
            }
            if (!entity_found)
            {
                printf("\033[1;37m .  \033[1;0m");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* Changing entities position according to their orientation - Only one step at the time */
void move_entities(Ecosystem *ecosystem, float change_dir_prob)
{
    for (int i = 0; i < ecosystem->size; ++i)
    {
        if ((float)rand() / RAND_MAX < change_dir_prob)
        {
            change_direction(&ecosystem->entities[i], change_dir_prob);
        }

        switch (ecosystem->entities[i].direction)
        {
        case 0: // NORTH
            ecosystem->entities[i].y = (ecosystem->entities[i].y - 1 + ECOSYSTEM_SIZE) % ECOSYSTEM_SIZE;
            break;
        case 1: // EAST
            ecosystem->entities[i].x = (ecosystem->entities[i].x + 1) % ECOSYSTEM_SIZE;
            break;
        case 2: // SOUTH
            ecosystem->entities[i].y = (ecosystem->entities[i].y + 1) % ECOSYSTEM_SIZE;
            break;
        case 3: // WEST
            ecosystem->entities[i].x = (ecosystem->entities[i].x - 1 + ECOSYSTEM_SIZE) % ECOSYSTEM_SIZE;
            break;
        default:
            break;
        }
    }
}

/* Proies reproduction and placement on the ecosystem */
void reproduce_entities(Ecosystem *ecosystem, float p_reproduce)
{
    int original_size = ecosystem->size;

    for (int i = 0; i < original_size; ++i)
    {
        if ((float)rand() / RAND_MAX < p_reproduce)
        {
            Entity new_entity = ecosystem->entities[i];
            new_entity.direction = rand() % 4;

            ecosystem->entities = (Entity *)realloc(ecosystem->entities, (++ecosystem->size) * sizeof(Entity));
            ecosystem->entities[ecosystem->size - 1] = new_entity;
        }
    }
}

/* Scans the whoel ecosystem and updates the energy according to the values of d_predateur and d_proie */
void update_energy(Ecosystem *ecosystem, int d_proie, int d_predateur)
{
    for (int i = 0; i < ecosystem->size; ++i)
    {
        if (ecosystem->entities[i].energy > 0)
        {
            if (ecosystem->entities[i].energy <= d_proie && ecosystem->entities[i].energy > 0)
            {
                ecosystem->entities[i].energy = 0; // declaring a predateur
            }
            else
            {
                ecosystem->entities[i].energy -= (ecosystem->entities[i].energy > d_proie) ? d_proie : d_predateur;
            }
        }
    }
}

/* Updating the entity from proie to predateur */
/* predateurs are those entities with an enery equal to 0 or lower than that */
void predator_eat_proie(Ecosystem *ecosystem, float eat_prob)
{
    for (int i = 0; i < ecosystem->size; ++i)
    {
        if (ecosystem->entities[i].energy > 0)
        {
            for (int j = 0; j < ecosystem->size; ++j)
            {
                if (i != j && ecosystem->entities[j].energy > 0 &&
                    ecosystem->entities[i].x == ecosystem->entities[j].x &&
                    ecosystem->entities[i].y == ecosystem->entities[j].y &&
                    (float)rand() / RAND_MAX < eat_prob)
                {
                    ecosystem->entities[i].energy += ecosystem->entities[j].energy;
                    ecosystem->entities[j].energy = 0;
                }
            }
        }
    }
}

/* Creating predateurs */
void reproduce_predators(Ecosystem *ecosystem, float p_reproduce)
{
    int original_size = ecosystem->size;

    for (int i = 0; i < original_size; ++i)
    {
        if (ecosystem->entities[i].energy > 0 && (float)rand() / RAND_MAX < p_reproduce)
        {
            Entity new_predator = ecosystem->entities[i];
            new_predator.direction = rand() % 4;

            ecosystem->entities = (Entity *)realloc(ecosystem->entities, (++ecosystem->size) * sizeof(Entity));
            ecosystem->entities[ecosystem->size - 1] = new_predator;
        }
    }
}

/* Changing the direction of an entity */
void change_direction(Entity *entity, float change_dir_prob)
{
    entity->direction = rand() % 4;
}

/* Validating the input and if true then prints the message on the terminal and received data */
/* Multidimensional function that is treating both percentages and integrers */
int validate_input(int min, int max, const char *message, bool is_percentage)
{
    char input_str[20];
    int value;
    bool repeater = true;

    do
    {
        printf("\n=======================\n");
        printf("\033[1;33m%s\033[1;0m", message);
        printf("\n=======================\n");

        if (scanf("%s", input_str) != 1)
        {
            while (getchar() != '\n')
                ; // Clear input buffer
            printf("\n\033[1;32mEntrée invalide. Veuillez réessayer.\033[1;0m\n");
            continue;
        }

        // Check if the input ends with '%' !!!
        char *percent_sign = strchr(input_str, '%');

        if (is_percentage && percent_sign != NULL)
        {
            // If '%' is found, remove it and convert to integer
            *percent_sign = '\0';
            value = atoi(input_str); // char to integer
        }
        else if (!is_percentage && (percent_sign != NULL || atoi(input_str) < 0 || atoi(input_str) > 100))
        {
            // If '%' is found or the value is not in the valid range for non-percentage input
            printf("\n\033[1;31mLa valeur doit être entre %d et %d. Veuillez réessayer.\033[1;0m\n", min, max);
            continue;
        }
        else
        {
            // If '%' is not found, or the input is not a percentage, convert to integer
            value = atoi(input_str); // char to integer
        }


        //verifying limits
        if (value < min || value > max)
        {
            printf("\n\033[1;31mLa valeur doit être entre %d et %d. Veuillez réessayer.\033[1;0m\n", min, max);
        }
        else
        {
            repeater = false;
        }
    } while (repeater);

    return value;
}
