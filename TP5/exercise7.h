#ifndef EXERCISE7_H
#define EXERCISE7_H

// Structure to represent an entity in the ecosystem
typedef struct {
    int x;           // x-coordinate
    int y;           // y-coordinate
    int direction;   // 0 for proie, non-zero for prédateur
    int energy;      // Energy level
} Entity;

// Structure to represent the ecosystem
typedef struct {
    int size;        // Total number of entities in the ecosystem
    Entity *entities; // Array of entities
} Ecosystem;

/* Starting up the ecosystem */
void initialize_ecosystem(Ecosystem *ecosystem, int size);

/* Printing the ecosystem on the terminal */
void print_ecosystem(Ecosystem *ecosystem, int rows, int collumns);

/* Changing entities position according to their orientation - Only one step at the time */
void move_entities(Ecosystem *ecosystem, float change_dir_prob);

/* Proies reproduction and placement on the ecosystem */
void reproduce_entities(Ecosystem *ecosystem, float p_reproduce);

/* Scans the whoel ecosystem and updates the energy according to the values of d_predateur and d_proie */
void update_energy(Ecosystem *ecosystem, int d_proie, int d_predateur);

/* Updating the entity from proie to predateur */
/* predateurs are those entities with an enery equal to 0 or lower than that */
void predator_eat_proie(Ecosystem *ecosystem, float eat_prob);

/* Creating predateurs */
void reproduce_predators(Ecosystem *ecosystem, float p_reproduce);

/* Changing the direction of an entity */
void change_direction(Entity *entity, float change_dir_prob);

/* Validating the input and if true then prints the message on the terminal and received data */
/* Multidimensional function that is treating both percentages and integrers */
int validate_input(int min, int max, const char *message, bool is_percentage);

#endif
