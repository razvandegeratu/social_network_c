#ifndef FRIENDS_H
#define FRIENDS_H

#define MAX_COMMAND_LEN 100
#define MAX_PEOPLE 550

typedef struct matrix_graph_t {
    int **matrix; /* Matricea de adiacenta a grafului */
    int nodes;    /* Numarul de noduri din graf. */
} matrix_graph_t;

void handle_input_friends(char *input, matrix_graph_t *graph);

#endif // FRIENDS_H