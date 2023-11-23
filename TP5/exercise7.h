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

// Function to initialize the ecosystem with entities at random positions
void initialize_ecosystem(Ecosystem *ecosystem, int size);

// Function to print the current state of the ecosystem in a grid format
void print_ecosystem(Ecosystem *ecosystem, int rows, int columns);

// Function to move entities in the ecosystem with a probability of changing direction
void move_entities(Ecosystem *ecosystem, double change_dir_prob);

// Function to reproduce proies in the ecosystem with a given probability
void reproduce_entities(Ecosystem *ecosystem, double p_reproduce_proie);

// Function to update the energy levels of entities in the ecosystem
void update_energy(Ecosystem *ecosystem, int d_proie, int d_predateur);

// Function to simulate prédateurs eating proies with a given probability
void predator_eat_proie(Ecosystem *ecosystem, double eat_prob);

// Function to reproduce prédateurs in the ecosystem with a given probability
void reproduce_predators(Ecosystem *ecosystem, double p_reproduce_predateur);

#endif
