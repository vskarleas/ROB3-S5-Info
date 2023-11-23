#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ECOSYSTEM_SIZE 10
#define ENERGY_DECAY_PROIE 1
#define ENERGY_DECAY_PREDATEUR 2
#define REPRODUCE_PROIE_PROB 0.2
#define REPRODUCE_PREDATEUR_PROB 0.1
#define EAT_PROIE_PROB 0.3
#define CHANGE_DIRECTION_PROB 0.1

typedef struct {
    int x;
    int y;
    int energy;
    int direction;
} Entity;

typedef struct {
    Entity *entities;
    int size;
} Ecosystem;

void initialize_ecosystem(Ecosystem *ecosystem, int size);
void print_ecosystem(Ecosystem *ecosystem, int rows, int columns);
void move_entities(Ecosystem *ecosystem);
void reproduce_entities(Ecosystem *ecosystem, float reproduce_prob);
void update_energy(Ecosystem *ecosystem, int energy_decay_proie, int energy_decay_predateur);
void predator_eat_proie(Ecosystem *ecosystem, float eat_prob);
void reproduce_predators(Ecosystem *ecosystem, float reproduce_prob);
void change_direction(Entity *entity, float change_dir_prob);

int main() {
    srand(time(NULL));

    Ecosystem ecosystem;
    initialize_ecosystem(&ecosystem, ECOSYSTEM_SIZE);

    int rows = 10;
    int columns = 20;

    for (int i = 0; i < 5; ++i) {
        printf("Étape temporelle %d:\n", i + 1);
        print_ecosystem(&ecosystem, rows, columns);
        move_entities(&ecosystem);
        reproduce_entities(&ecosystem, REPRODUCE_PROIE_PROB);
        update_energy(&ecosystem, ENERGY_DECAY_PROIE, ENERGY_DECAY_PREDATEUR);
        predator_eat_proie(&ecosystem, EAT_PROIE_PROB);
        reproduce_predators(&ecosystem, REPRODUCE_PREDATEUR_PROB);

        usleep(500000); // Sleep for 0.5 seconds
    }

    free(ecosystem.entities);

    return 0;
}

void initialize_ecosystem(Ecosystem *ecosystem, int size) {
    ecosystem->size = size;
    ecosystem->entities = (Entity *)malloc(size * sizeof(Entity));

    for (int i = 0; i < size; ++i) {
        ecosystem->entities[i].x = rand() % size;
        ecosystem->entities[i].y = rand() % size;
        ecosystem->entities[i].energy = 10; // Énergie initiale
        ecosystem->entities[i].direction = rand() % 4; // 0: haut, 1: droite, 2: bas, 3: gauche
    }
}

void print_ecosystem(Ecosystem *ecosystem, int rows, int columns) {

    /*
    
    Lors de l'impression de l'écosystème à l'aide de la fonction print_ecosystem, 
    le programme vérifie le niveau d'énergie de chaque entité. Si le niveau 
    d'énergie est supérieur à 0, il est considéré comme un proie et sa représentation 
    sur la grille est colorée en vert. Si le niveau d'énergie est de 0, il est considéré comme 
    un prédateur et sa représentation sur la grille est colorée en rouge.

    */

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < columns; ++x) {
            int entity_found = 0;
            for (int i = 0; i < ecosystem->size; ++i) {
                if (ecosystem->entities[i].x == x && ecosystem->entities[i].y == y) {
                    if (ecosystem->entities[i].energy > 0) {
                        // Green color for proies
                        printf("\033[1;32mP%d\033[1;0m", ecosystem->entities[i].energy);
                    } else {
                        // Red color for prédateurs
                        printf("\033[1;31mP%d\033[1;0m", ecosystem->entities[i].energy);
                    }
                    entity_found = 1;
                    break;
                }
            }
            if (!entity_found) {
                // White color for the background
                printf("\033[1;37m. \033[1;0m");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void move_entities(Ecosystem *ecosystem) {
    for (int i = 0; i < ecosystem->size; ++i) {
        if ((float)rand() / RAND_MAX < CHANGE_DIRECTION_PROB) {
            change_direction(&ecosystem->entities[i], CHANGE_DIRECTION_PROB);
        }

        switch (ecosystem->entities[i].direction) {
            case 0: // Haut
                ecosystem->entities[i].y = (ecosystem->entities[i].y - 1 + ECOSYSTEM_SIZE) % ECOSYSTEM_SIZE;
                break;
            case 1: // Droite
                ecosystem->entities[i].x = (ecosystem->entities[i].x + 1) % ECOSYSTEM_SIZE;
                break;
            case 2: // Bas
                ecosystem->entities[i].y = (ecosystem->entities[i].y + 1) % ECOSYSTEM_SIZE;
                break;
            case 3: // Gauche
                ecosystem->entities[i].x = (ecosystem->entities[i].x - 1 + ECOSYSTEM_SIZE) % ECOSYSTEM_SIZE;
                break;
            default:
                break;
        }
    }
}

void reproduce_entities(Ecosystem *ecosystem, float reproduce_prob) {
    int original_size = ecosystem->size;

    for (int i = 0; i < original_size; ++i) {
        if ((float)rand() / RAND_MAX < reproduce_prob) {
            // Créer une nouvelle entité avec les mêmes propriétés
            Entity new_entity = ecosystem->entities[i];
            // Changer aléatoirement la direction de la nouvelle entité
            new_entity.direction = rand() % 4;

            // Ajouter la nouvelle entité à l'écosystème
            ecosystem->entities = (Entity *)realloc(ecosystem->entities, (++ecosystem->size) * sizeof(Entity));
            ecosystem->entities[ecosystem->size - 1] = new_entity;
        }
    }
}

void update_energy(Ecosystem *ecosystem, int energy_decay_proie, int energy_decay_predateur) {
    for (int i = 0; i < ecosystem->size; ++i) {
        if (ecosystem->entities[i].energy > 0) {
            if (ecosystem->entities[i].energy <= energy_decay_proie && ecosystem->entities[i].energy > 0) {
                ecosystem->entities[i].energy = 0; // La proie meurt de faim
            } else {
                ecosystem->entities[i].energy -= (ecosystem->entities[i].energy > energy_decay_proie) ? energy_decay_proie : energy_decay_predateur;
            }
        }
    }
}

void predator_eat_proie(Ecosystem *ecosystem, float eat_prob) {
    for (int i = 0; i < ecosystem->size; ++i) {
        if (ecosystem->entities[i].energy > 0) {
            for (int j = 0; j < ecosystem->size; ++j) {
                if (i != j && ecosystem->entities[j].energy > 0 &&
                    ecosystem->entities[i].x == ecosystem->entities[j].x &&
                    ecosystem->entities[i].y == ecosystem->entities[j].y &&
                    (float)rand() / RAND_MAX < eat_prob) {
                    // Le prédateur mange la proie
                    ecosystem->entities[i].energy += ecosystem->entities[j].energy;
                    ecosystem->entities[j].energy = 0; // La proie meurt
                }
            }
        }
    }
}

void reproduce_predators(Ecosystem *ecosystem, float reproduce_prob) {
    int original_size = ecosystem->size;

    for (int i = 0; i < original_size; ++i) {
        if (ecosystem->entities[i].energy > 0 && (float)rand() / RAND_MAX < reproduce_prob) {
            // Créer un nouveau prédateur avec les mêmes propriétés
            Entity new_predator = ecosystem->entities[i];
            // Changer aléatoirement la direction du nouveau prédateur
            new_predator.direction = rand() % 4;

            // Ajouter le nouveau prédateur à l'écosystème
            ecosystem->entities = (Entity *)realloc(ecosystem->entities, (++ecosystem->size) * sizeof(Entity));
            ecosystem->entities[ecosystem->size - 1] = new_predator;
        }
    }
}

void change_direction(Entity *entity, float change_dir_prob) {
    if ((float)rand() / RAND_MAX < change_dir_prob) {
        entity->direction = rand() % 4;
    }
}
