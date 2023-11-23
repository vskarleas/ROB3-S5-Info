#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define ECOSYSTEM_SIZE 10

typedef struct Entity {
    int x;
    int y;
    int energy; // for energy lower than 0 we have a predateur
    int direction;
    struct Entity* next;
} Entity;

typedef struct {
    Entity* head;
    int size;
} Ecosystem;

void initialize_ecosystem(Ecosystem* ecosystem, int size);
void print_ecosystem(Ecosystem* ecosystem, int rows, int columns);
void move_entities(Ecosystem* ecosystem, float change_dir_prob);
void reproduce_entities(Ecosystem* ecosystem, float p_reproduce);
void update_energy(Ecosystem* ecosystem, int d_proie, int d_predateur);
void predator_eat_proie(Ecosystem* ecosystem, float eat_prob);
void reproduce_predators(Ecosystem* ecosystem, float p_reproduce);
void change_direction(Entity* entity, float change_dir_prob);

int validate_input(int min, int max, const char* message, bool is_percentage);

int main(int argc, char** argv) {
    srand(time(NULL));

    Ecosystem ecosystem;
    initialize_ecosystem(&ecosystem, ECOSYSTEM_SIZE);

    int rows = 10;
    int columns = 10;

    int num_time_steps;
    int d_proie;
    int d_predateur;
    double p_reproduce_proie;
    double p_reproduce_predateur; //d_reproduce
    double eat_prob;
    double change_dir_prob;

    // Ask the user if they want to use default configuration
    printf("Voulez-vous utiliser la configuration par défaut ? (1: Oui, 0: Non): ");
    int use_default;
    if (scanf("%d", &use_default) != 1) {
        printf("Entrée invalide. Utilisation de la configuration par défaut.\n");
        use_default = 1;
    }

    if (use_default) {
        // Default configuration
        num_time_steps = 9;
        d_proie = 3;
        d_predateur = 1;
        p_reproduce_proie = 0.47;
        p_reproduce_predateur = 0.2;
        eat_prob = 0.28;
        change_dir_prob = 0.2;
    } else {
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
    for (int step = 0; step < num_time_steps; ++step) {
        printf("Étape temporelle %d:\n", step + 1);
        print_ecosystem(&ecosystem, rows, columns);
        move_entities(&ecosystem, change_dir_prob);
        reproduce_entities(&ecosystem, p_reproduce_proie);
        update_energy(&ecosystem, d_proie, d_predateur);
        predator_eat_proie(&ecosystem, eat_prob);
        reproduce_predators(&ecosystem, p_reproduce_predateur);

        usleep(500000); // Sleep for 0.5 seconds
    }

    printf("Etat final de l'ecosystem :\n");
    print_ecosystem(&ecosystem, rows, columns);

    // afficher_liste summary
    int proie_count = 0;
    int predateur_count = 0;

    Entity* current = ecosystem.head;
    while (current != NULL) {
        if (current->energy > 0) {
            if (current->direction == 0) {
                proie_count++;
            } else {
                predateur_count++;
            }
        }
        current = current->next;
    }

    printf("\n\033[1;35mRésumé de la simulation\033[1;0m\n");
    printf("--------------------------------\n\n");
    printf("Nombre total de proies restantes: %d\n", proie_count);
    printf("Nombre total de prédateurs restants: %d\n", predateur_count);
    printf("Pourcentage de proies par rapport à la population initiale: %.2f%%\n", ((double)proie_count / ECOSYSTEM_SIZE) * 100);
    printf("Pourcentage de prédateurs par rapport à la population initiale: %.2f%%\n", ((double)predateur_count / ECOSYSTEM_SIZE) * 100);

    // Additional conclusions or observations can be added here

    // Free the linked list
    current = ecosystem.head;
    while (current != NULL) {
        Entity* next_entity = current->next;
        free(current);
        current = next_entity;
    }

    return 0;
}

// Other functions remain unchanged

/* Starting up the ecosystem */
void initialize_ecosystem(Ecosystem* ecosystem, int size) {
    ecosystem->head = NULL;
    ecosystem->size = 0;

    for (int i = 0; i < size; ++i) {
        Entity* new_entity = (Entity*)malloc(sizeof(Entity));
        new_entity->x = rand() % size;
        new_entity->y = rand() % size;
        new_entity->energy = 10;
        new_entity->direction = rand() % 4;
        new_entity->next = ecosystem->head;
        ecosystem->head = new_entity;
        ecosystem->size++;
    }
}

/* Printing the ecosystem on the terminal */
/* Printing the ecosystem on the terminal */
void print_ecosystem(Ecosystem* ecosystem, int rows, int columns) {
    printf("     ");
    for (int x = 0; x < columns; ++x) {
        printf(" %d  ", x);
    }
    printf("\n");

    for (int y = 0; y < rows; ++y) {
        printf("%d    ", y);
        for (int x = 0; x < columns; ++x) {
            Entity* current = ecosystem->head;
            int entity_found = 0;

            while (current != NULL) {
                if (current->energy > 0 && current->x == x && current->y == y) {
                    if (current->energy > 0) {
                        printf("\033[1;32mP%d\033[1;0m  ", current->energy); // it won energy
                    } else {
                        printf("\033[1;31mP%d\033[1;0m  ", current->energy); // it lost energy
                    }
                    entity_found = 1;
                    break;
                }
                current = current->next;
            }

            if (!entity_found) {
                printf("\033[1;37m .  \033[1;0m");
            }
        }
        printf("\n");
    }
    printf("\n");
}


/* Changing entities position according to their orientation - Only one step at the time */
void move_entities(Ecosystem* ecosystem, float change_dir_prob) {
    Entity* current = ecosystem->head;

    while (current != NULL) {
        if ((float)rand() / RAND_MAX < change_dir_prob) {
            change_direction(current, change_dir_prob);
        }

        switch (current->direction) {
            case 0: // NORTH
                current->y = (current->y - 1 + ECOSYSTEM_SIZE) % ECOSYSTEM_SIZE;
                break;
            case 1: // EAST
                current->x = (current->x + 1) % ECOSYSTEM_SIZE;
                break;
            case 2: // SOUTH
                current->y = (current->y + 1) % ECOSYSTEM_SIZE;
                break;
            case 3: // WEST
                current->x = (current->x - 1 + ECOSYSTEM_SIZE) % ECOSYSTEM_SIZE;
                break;
            default:
                break;
        }

        current = current->next;
    }
}


/* Proies reproduction and placement on the ecosystem */
void reproduce_entities(Ecosystem* ecosystem, float p_reproduce) {
    Entity* current = ecosystem->head;

    while (current != NULL) {
        if ((float)rand() / RAND_MAX < p_reproduce) {
            Entity* new_entity = (Entity*)malloc(sizeof(Entity));
            new_entity->x = current->x;
            new_entity->y = current->y;
            new_entity->energy = current->energy;  // You may adjust this based on your reproduction logic
            new_entity->direction = rand() % 4;
            new_entity->next = ecosystem->head;
            ecosystem->head = new_entity;
            ecosystem->size++;
        }

        current = current->next;
    }
}


/* Scans the whole ecosystem and updates the energy according to the values of d_predateur and d_proie */
/* Scans the whole ecosystem and updates the energy according to the values of d_predateur and d_proie */
void update_energy(Ecosystem* ecosystem, int d_proie, int d_predateur) {
    Entity* current = ecosystem->head;

    while (current != NULL) {
        if (current->energy > 0) {
            if (current->energy <= d_proie) {
                current->energy = 0; // declaring a predateur
            } else {
                current->energy -= (current->energy > d_proie) ? d_proie : d_predateur;
            }
        }

        current = current->next;
    }
}


/* Updating the entity from proie to predateur */
/* predateurs are those entities with an energy equal to 0 or lower than that */
void predator_eat_proie(Ecosystem* ecosystem, float eat_prob) {
    Entity* predator = ecosystem->head;

    while (predator != NULL) {
        if (predator->energy > 0) {
            Entity* proie = ecosystem->head;

            while (proie != NULL) {
                if (proie != predator && proie->energy > 0 &&
                    predator->x == proie->x &&
                    predator->y == proie->y &&
                    (float)rand() / RAND_MAX < eat_prob) {
                    predator->energy += proie->energy;
                    proie->energy = 0;
                }

                proie = proie->next; //we move from the current cellule to the next cellule of the liste chaine 
            }
        }

        predator = predator->next;
    }
}


/* Creating predateurs while using p_reproduce */
void reproduce_predators(Ecosystem* ecosystem, float p_reproduce) {
    Entity* current = ecosystem->head;

    while (current != NULL) {
        if (current->energy > 0 && (float)rand() / RAND_MAX < p_reproduce) {
            Entity* new_predator = (Entity*)malloc(sizeof(Entity));
            new_predator->x = current->x;
            new_predator->y = current->y;
            new_predator->energy = current->energy;  // You may adjust this based on your reproduction logic
            new_predator->direction = rand() % 4;
            new_predator->next = ecosystem->head;
            ecosystem->head = new_predator;
            ecosystem->size++;
        }

        current = current->next;
    }
}


/* Changing the direction of an entity */
void change_direction(Entity* entity, float change_dir_prob) {
    entity->direction = rand() % 4;
}

int validate_input(int min, int max, const char* message, bool is_percentage) {
    char input_str[20];
    int value;
    
    do {
        printf("\n=======================\n");
        printf("\033[1;33m%s\033[1;0m", message);
        printf("\n=======================\n");

        if (scanf("%s", input_str) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            printf("\n\033[1;32mEntrée invalide. Veuillez réessayer.\033[1;0m\n");
            continue;
        }

        // Check if the input ends with '%'
        char *percent_sign = strchr(input_str, '%');
        
        if (is_percentage && percent_sign != NULL) {
            // If '%' is found, remove it and convert to integer
            *percent_sign = '\0';
            value = atoi(input_str);
        } else if (!is_percentage && (percent_sign != NULL || atoi(input_str) < 0 || atoi(input_str) > 100)) {
            // If '%' is found or the value is not in the valid range for non-percentage input
            printf("\n\033[1;31mLa valeur doit être entre %d et %d. Veuillez réessayer.\033[1;0m\n", min, max);
            continue;
        } else {
            // If '%' is not found, or the input is not a percentage, convert to integer
            value = atoi(input_str);
        }

        if (value < min || value > max) {
            printf("\n\033[1;31mLa valeur doit être entre %d et %d. Veuillez réessayer.\033[1;0m\n", min, max);
        } else {
            break;
        }
    } while (1);

    return value;
}
